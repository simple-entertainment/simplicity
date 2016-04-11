/*
 * Copyright © 2012 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <algorithm>

#include "../common/AddressEquals.h"
#include "../math/Intersection.h"
#include "../math/MathFunctions.h"
#include "../model/Model.h"
#include "SimpleSceneGraph.h"

using namespace std;

namespace simplicity
{
	SimpleSceneGraph::SimpleSceneGraph() :
		bounds(0.0f),
		children(),
		connections(),
		entities(),
		parent(nullptr),
		transform()
	{
		transform.setIdentity();
	}

	Matrix44 SimpleSceneGraph::calculateRelativeTransform(const Matrix44& absoluteTransform) const
	{
		if (parent == nullptr)
		{
			return absoluteTransform;
		}

		/*
		 * Find the transform for this graph (Gr) relative to the absolute parent transform (Pa) that matches the
		 * absolute transform (Ga) i.e. such that: Ga = Pa * Gr or Gr = Ga * Pa-1
		 */
		Matrix44 inverseParentAbsoluteTransform = parent->getAbsoluteTransform();
		inverseParentAbsoluteTransform.invert();

		return absoluteTransform * inverseParentAbsoluteTransform;
	}

	void SimpleSceneGraph::connectTo(SceneGraph& graph)
	{
		connections.push_back(&graph);
	}

	void SimpleSceneGraph::disconnectFrom(SceneGraph& graph)
	{
		if (find(connections.begin(), connections.end(), &graph) != connections.end())
		{
			connections.erase(std::remove(connections.begin(), connections.end(), &graph));
		}
	}

	Matrix44 SimpleSceneGraph::getAbsoluteTransform() const
	{
		Matrix44 absoluteMatrix;
		absoluteMatrix.setIdentity();
		const SceneGraph* currentGraph = this;
		while (currentGraph != nullptr)
		{
			absoluteMatrix *= currentGraph->getTransform();
			currentGraph = currentGraph->getParent();
		}

		return absoluteMatrix;
	}

	const Shape& SimpleSceneGraph::getBounds() const
	{
		return bounds;
	}

	vector<SceneGraph*> SimpleSceneGraph::getChildren() const
	{
		vector<SceneGraph*> rawChildren;
		for (unsigned int index = 0; index < children.size(); index++)
		{
			rawChildren.push_back(children[index].get());
		}

		return rawChildren;
	}

	vector<Entity*>& SimpleSceneGraph::getEntities()
	{
		return entities;
	}

	const vector<Entity*>& SimpleSceneGraph::getEntities() const
	{
		return entities;
	}

	vector<Entity*> SimpleSceneGraph::getEntitiesWithinBounds(const Shape& bounds, const Vector3& position) const
	{
		vector<Entity*> entitiesWithinBounds;

		for (Entity* entity : entities)
		{
			if (isWithinBounds(*entity, bounds, position))
			{
				entitiesWithinBounds.push_back(entity);
			}
		}

		for (unsigned int index = 0; index < children.size(); index++)
		{
			vector<Entity*> childResult = children[index]->getEntitiesWithinBounds(bounds, position);
			entitiesWithinBounds.insert(entitiesWithinBounds.end(), childResult.begin(), childResult.end());
		}

		return entitiesWithinBounds;
	}

	SceneGraph* SimpleSceneGraph::getParent()
	{
		return parent;
	}

	const SceneGraph* SimpleSceneGraph::getParent() const
	{
		return parent;
	}

	Matrix44& SimpleSceneGraph::getTransform()
	{
		return transform;
	}

	const Matrix44& SimpleSceneGraph::getTransform() const
	{
		return transform;
	}

	bool SimpleSceneGraph::insert(Entity& entity)
	{
		unique_ptr<SimpleSceneGraph> newChild(new SimpleSceneGraph);
		bool result = newChild->insertDirect(entity);

		newChild->setParent(this);
		children.push_back(move(newChild));

		return result;
	}

	bool SimpleSceneGraph::insert(Entity& entity, const Entity& parent)
	{
		for (Entity* myEntity : entities)
		{
			if (myEntity == &parent)
			{
				return insert(entity);
			}
		}

		for (unsigned int index = 0; index < children.size(); index++)
		{
			if (children[index]->insert(entity, parent))
			{
				return true;
			}
		}

		return false;
	}

	bool SimpleSceneGraph::insertDirect(Entity& entity)
	{
		entities.push_back(&entity);
		return true;
	}

	bool SimpleSceneGraph::isWithinBounds(const Entity& entity, const Shape& bounds, const Vector3& position) const
	{
		bool boundsExist = false;

		for (Component* component : entity.getComponents())
		{
			if (component->getBounds() == nullptr)
			{
				continue;
			}

			boundsExist = true;

			Vector3 componentPosition = getPosition3(entity.getTransform() * component->getTransform());
			if (Intersection::intersect(*component->getBounds(), bounds, position - componentPosition))
			{
				return true;
			}
		}

		// If the entity has no bounds we take the safe option and assume that it intersects.
		return !boundsExist;
	}

	bool SimpleSceneGraph::remove(const Entity& entity)
	{
		if (find(entities.begin(), entities.end(), &entity) == entities.end())
		{
			for (unsigned int index = 0; index < children.size(); index++)
			{
				if (children[index]->remove(entity))
				{
					removeChild(*children[index]);
					return true;
				}
			}

			return false;
		}

		entities.erase(std::remove(entities.begin(), entities.end(), &entity));
		return true;
	}

	unique_ptr<SimpleSceneGraph> SimpleSceneGraph::removeChild(SimpleSceneGraph& child)
	{
		unique_ptr<SimpleSceneGraph> uniqueChild;

		vector<unique_ptr<SimpleSceneGraph>>::iterator result =
				find_if(children.begin(), children.end(), AddressEquals<SimpleSceneGraph>(child));

		if (result != children.end())
		{
			uniqueChild.swap(*result);
			children.erase(result);
		}

		return uniqueChild;
	}

	void SimpleSceneGraph::setParent(SceneGraph* parent)
	{
		this->parent = parent;
	}

	void SimpleSceneGraph::setTransform(const Matrix44& transform)
	{
		this->transform = transform;
	}

	void SimpleSceneGraph::update(Entity& entity)
	{
		bool entityFound = false;
		for (Entity* myEntity : entities)
		{
			if (myEntity == &entity)
			{
				entityFound = true;
				break;
			}
		}

		if (entityFound)
		{
			transform = calculateRelativeTransform(entity.getTransform());

			// Update the entities to match the updated graph.
			for (Entity* myEntity : entities)
			{
				myEntity->setTransform(entity.getTransform());
			}

			for (unsigned int index = 0; index < children.size(); index++)
			{
				children[index]->updateSuccessor(entity);
			}
		}
		else
		{
			for (unsigned int index = 0; index < children.size(); index++)
			{
				children[index]->update(entity);
			}
		}
	}

	void SimpleSceneGraph::updateSuccessor(Entity& entity)
	{
		// Update the entities to match the updated graph.
		Matrix44 absoluteTransform = getAbsoluteTransform();
		for (Entity* myEntity : entities)
		{
			myEntity->setTransform(absoluteTransform);
		}

		for (unsigned int index = 0; index < children.size(); index++)
		{
			children[index]->updateSuccessor(entity);
		}
	}
}
