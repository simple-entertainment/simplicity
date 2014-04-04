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
#include "SimpleGraph.h"

using namespace std;

namespace simplicity
{
	SimpleGraph::SimpleGraph() :
		boundary(0.0f),
		children(),
		connections(),
		entities(),
		parent(NULL),
		transform()
	{
		transform.setIdentity();
	}

	void SimpleGraph::addChild(unique_ptr<SimpleGraph> child)
	{
		child->setParent(this);
		children.push_back(move(child));
	}

	Matrix44 SimpleGraph::calculateRelativeTransform(const Matrix44& absoluteTransform) const
	{
		if (parent == NULL)
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

	void SimpleGraph::connectTo(Graph& graph)
	{
		connections.push_back(&graph);
	}

	void SimpleGraph::disconnectFrom(Graph& graph)
	{
		if (find(connections.begin(), connections.end(), &graph) != connections.end())
		{
			connections.erase(std::remove(connections.begin(), connections.end(), &graph));
		}
	}

	Matrix44 SimpleGraph::getAbsoluteTransform() const
	{
		Matrix44 absoluteMatrix;
		absoluteMatrix.setIdentity();
		const Graph* currentGraph = this;
		while (currentGraph != NULL)
		{
			absoluteMatrix *= currentGraph->getTransform();
			currentGraph = currentGraph->getParent();
		}

		return absoluteMatrix;
	}

	const Model& SimpleGraph::getBoundary() const
	{
		return boundary;
	}

	vector<Graph*> SimpleGraph::getChildren() const
	{
		vector<Graph*> rawChildren;
		for (unsigned int index = 0; index < children.size(); index++)
		{
			rawChildren.push_back(children[index].get());
		}

		return rawChildren;
	}

	vector<Entity*>& SimpleGraph::getEntities()
	{
		return entities;
	}

	const vector<Entity*>& SimpleGraph::getEntities() const
	{
		return entities;
	}

	vector<Entity*> SimpleGraph::getEntitiesWithinBounds(const Model& bounds, const Vector3& position) const
	{
		vector<Entity*> entitiesWithinBounds;

		for (Entity* entity : entities)
		{
			Model* entityBounds = entity->getComponent<Model>(Category::BOUNDS);
			if (entityBounds == NULL)
			{
				continue;
			}

			Vector3 modelBoundsPosition = getPosition3(entity->getTransform() * entityBounds->getTransform());
			if (Intersection::intersect(*entityBounds, bounds, position - modelBoundsPosition))
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

	Graph* SimpleGraph::getParent()
	{
		return parent;
	}

	const Graph* SimpleGraph::getParent() const
	{
		return parent;
	}

	Matrix44& SimpleGraph::getTransform()
	{
		return transform;
	}

	const Matrix44& SimpleGraph::getTransform() const
	{
		return transform;
	}

	bool SimpleGraph::insert(Entity& entity)
	{
		unique_ptr<SimpleGraph> newChild(new SimpleGraph);
		bool result = newChild->insertDirect(entity);

		newChild->setParent(this);
		children.push_back(move(newChild));

		return result;
	}

	bool SimpleGraph::insert(Entity& entity, const Entity& parent)
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

	bool SimpleGraph::insertDirect(Entity& entity)
	{
		entities.push_back(&entity);
		return true;
	}

	bool SimpleGraph::remove(const Entity& entity)
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

	unique_ptr<SimpleGraph> SimpleGraph::removeChild(SimpleGraph& child)
	{
		unique_ptr<SimpleGraph> uniqueChild;

		vector<unique_ptr<SimpleGraph>>::iterator result =
				find_if(children.begin(), children.end(), AddressEquals<SimpleGraph>(child));

		if (result != children.end())
		{
			uniqueChild.swap(*result);
			children.erase(result);
		}

		return uniqueChild;
	}

	void SimpleGraph::setParent(Graph* parent)
	{
		this->parent = parent;
	}

	void SimpleGraph::setTransform(const Matrix44& transform)
	{
		this->transform = transform;
	}

	void SimpleGraph::update(Entity& entity)
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

	void SimpleGraph::updateSuccessor(Entity& entity)
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
