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
#include "SimpleTree.h"

using namespace std;

namespace simplicity
{
	SimpleTree::SimpleTree() :
		boundary(),
		children(),
		connections(),
		entities(),
		parent(NULL),
		transformation()
	{
		transformation.setIdentity();
	}

	void SimpleTree::addChild(unique_ptr<Graph> child)
	{
		child->setParent(this);
		children.push_back(move(child));
	}

	void SimpleTree::connectTo(Graph& graph)
	{
		connections.push_back(&graph);
	}

	void SimpleTree::disconnectFrom(Graph& graph)
	{
		if (find(connections.begin(), connections.end(), &graph) == connections.end())
		{
			connections.erase(std::remove(connections.begin(), connections.end(), &graph));
		}
	}

	Matrix44 SimpleTree::getAbsoluteTransformation() const
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

	const AABB2& SimpleTree::getBoundary() const
	{
		return boundary;
	}

	vector<Graph*> SimpleTree::getChildren() const
	{
		vector<Graph*> rawChildren;
		for (unsigned int index = 0; index < children.size(); index++)
		{
			rawChildren.push_back(children[index].get());
		}

		return rawChildren;
	}

	vector<Entity*>& SimpleTree::getEntities()
	{
		return entities;
	}

	const vector<Entity*>& SimpleTree::getEntities() const
	{
		return entities;
	}

	Graph* SimpleTree::getParent()
	{
		return parent;
	}

	const Graph* SimpleTree::getParent() const
	{
		return parent;
	}

	Matrix44& SimpleTree::getTransformation()
	{
		return transformation;
	}

	const Matrix44& SimpleTree::getTransformation() const
	{
		return transformation;
	}

	bool SimpleTree::insert(Entity& entity)
	{
		entities.push_back(&entity);
		return true;
	}

	vector<Entity*> SimpleTree::queryRange(const AABB2& range) const
	{
		vector<Entity*> queryResult;

		if (!Intersection::intersect(boundary, range))
		{
			return queryResult;
		}

		for (unsigned int entityIndex = 0; entityIndex < entities.size(); entityIndex++)
		{
			vector<Model*> models = entities[entityIndex]->getComponents<Model>();
			for (unsigned int index = 0; index < models.size(); index++)
			{
				Circle* circle = dynamic_cast<Circle*>(models[index]);
				if (circle != NULL)
				{
					Vector3 circlePosition3 = MathFunctions::getTranslation3(entities[entityIndex]->getTransformation() *
									circle->getTransformation());
					Vector2 circlePosition2(circlePosition3.X(), circlePosition3.Y());
					if (Intersection::intersect(range, *circle, circlePosition2))
					{
						queryResult.push_back(entities[entityIndex]);
					}
				}
			}
		}

		for (unsigned int index = 0; index < children.size(); index++)
		{
			vector<Entity*> childResult = children[index]->queryRange(range);
			queryResult.insert(queryResult.end(), childResult.begin(), childResult.end());
		}

		return queryResult;
	}

	bool SimpleTree::remove(const Entity& entity)
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

	unique_ptr<Graph> SimpleTree::removeChild(Graph& child)
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

	void SimpleTree::setParent(Graph* parent)
	{
		this->parent = parent;
	}

	void SimpleTree::setTransformation(const Matrix44& transformation)
	{
		this->transformation = transformation;
	}

	void SimpleTree::update(Entity& entity)
	{
		remove(entity);
		insert(entity);
	}
}
