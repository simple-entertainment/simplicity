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
		transformation()
	{
		transformation.setIdentity();
	}

	void SimpleGraph::addChild(unique_ptr<Graph> child)
	{
		child->setParent(this);
		children.push_back(move(child));
	}

	void SimpleGraph::connectTo(Graph& graph)
	{
		connections.push_back(&graph);
	}

	void SimpleGraph::disconnectFrom(Graph& graph)
	{
		if (find(connections.begin(), connections.end(), &graph) == connections.end())
		{
			connections.erase(std::remove(connections.begin(), connections.end(), &graph));
		}
	}

	Matrix44 SimpleGraph::getAbsoluteTransformation() const
	{
		Matrix44 absoluteMatrix;
		absoluteMatrix.setIdentity();
		const Graph* currentGraph = this;
		while (currentGraph != NULL)
		{
			absoluteMatrix *= currentGraph->getTransformation();
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
			Model* entityBounds = entity->getComponent<Model>(Categories::BOUNDS);
			if (entityBounds == NULL)
			{
				continue;
			}

			Vector3 modelBoundsPosition = MathFunctions::getTranslation3(entity->getTransformation() *
					entityBounds->getTransformation());
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

	Matrix44& SimpleGraph::getTransformation()
	{
		return transformation;
	}

	const Matrix44& SimpleGraph::getTransformation() const
	{
		return transformation;
	}

	bool SimpleGraph::insert(Entity& entity)
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
					return true;
				}
			}

			return false;
		}

		entities.erase(std::remove(entities.begin(), entities.end(), &entity));
		return true;
	}

	unique_ptr<Graph> SimpleGraph::removeChild(Graph& child)
	{
		unique_ptr<Graph> uniqueChild;

		vector<unique_ptr<Graph>>::iterator result =
				find_if(children.begin(), children.end(), AddressEquals<Graph>(child));

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

	void SimpleGraph::setTransformation(const Matrix44& transformation)
	{
		this->transformation = transformation;
	}

	void SimpleGraph::update(Entity& entity)
	{
		remove(entity);
		insert(entity);
	}
}
