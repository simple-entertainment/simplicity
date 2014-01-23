/*
 * Copyright © 2013 Simple Entertainment Limited
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

#include "../math/Intersection.h"
#include "../model/shape/Circle.h"
#include "QuadTree.h"

using namespace std;

namespace simplicity
{
	QuadTree::QuadTree(unsigned int subdivideThreshold, const AABB2& boundary) :
		boundary(boundary),
		children(),
		connections(),
		entities(),
		parent(NULL),
		subdivideThreshold(subdivideThreshold),
		transformation()
	{
		children.reserve(4);
		transformation.setIdentity();
	}

	void QuadTree::addChild(std::unique_ptr<Graph>)
	{
	}

	void QuadTree::addEntityFromChild()
	{
		for (unsigned int index = 0; index < children.size(); index++)
		{
			if (!children[index]->getEntities().empty())
			{
				Entity* entity = children[index]->getEntities()[0];
				children[index]->remove(*entity);
				entities.push_back(entity);
				return;
			}
		}
	}

	void QuadTree::connectTo(Graph& graph)
	{
		connections.push_back(&graph);
	}

	void QuadTree::disconnectFrom(Graph& graph)
	{
		if (find(connections.begin(), connections.end(), &graph) == connections.end())
		{
			connections.erase(std::remove(connections.begin(), connections.end(), &graph));
		}
	}

	Matrix44 QuadTree::getAbsoluteTransformation() const
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

	const AABB2& QuadTree::getBoundary() const
	{
		return boundary;
	}

	vector<Graph*> QuadTree::getChildren() const
	{
		vector<Graph*> rawChildren;
		for (unsigned int index = 0; index < children.size(); index++)
		{
			rawChildren.push_back(children[index].get());
		}

		return rawChildren;
	}

	vector<Entity*>& QuadTree::getEntities()
	{
		return entities;
	}

	const vector<Entity*>& QuadTree::getEntities() const
	{
		return entities;
	}

	Graph* QuadTree::getParent()
	{
		return parent;
	}

	const Graph* QuadTree::getParent() const
	{
		return parent;
	}

	Matrix44& QuadTree::getTransformation()
	{
		return transformation;
	}

	const Matrix44& QuadTree::getTransformation() const
	{
		return transformation;
	}

	bool QuadTree::insert(Entity& entity)
	{
		if (!withinBounds(entity))
		{
			return false;
		}

		// TODO Should be model count, not entity count?
		if (entities.size() == subdivideThreshold && children.empty())
		{
			subdivide();
		}

		for (unsigned int index = 0; index < children.size(); index++)
		{
			if (children[index]->insert(entity))
			{
				return true;
			}
		}

		entities.push_back(&entity);
		return true;
	}

	vector<Entity*> QuadTree::queryRange(const AABB2& range) const
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
					if (Intersection::intersect(range, *circle))
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

	bool QuadTree::remove(const Entity& entity)
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

		// TODO Should be model count, not entity count?
		if (entities.size() < subdivideThreshold)
		{
			addEntityFromChild();
		}

		if (entities.size() < subdivideThreshold)
		{
			children.clear();
		}

		return true;
	}

	unique_ptr<Graph> QuadTree::removeChild(Graph&)
	{
		return unique_ptr<Graph>();
	}

	void QuadTree::setParent(Graph* parent)
	{
		this->parent = parent;
	}

	void QuadTree::setTransformation(const Matrix44& transformation)
	{
		this->transformation = transformation;
	}

	void QuadTree::subdivide()
	{
		float childHalfDimension = boundary.halfDimension / 2.0f;

		AABB2 boundary0;
		boundary0.center = boundary.center;
		boundary0.halfDimension = childHalfDimension;
		boundary0.center.X() -= childHalfDimension;
		boundary0.center.Y() += childHalfDimension;
		unique_ptr<Graph> child0(new QuadTree(subdivideThreshold, boundary0));
		child0->setParent(this);
		children.push_back(move(child0));

		AABB2 boundary1;
		boundary1.center = boundary.center;
		boundary1.halfDimension = childHalfDimension;
		boundary1.center.X() += childHalfDimension;
		boundary1.center.Y() += childHalfDimension;
		unique_ptr<Graph> child1(new QuadTree(subdivideThreshold, boundary1));
		child1->setParent(this);
		children.push_back(move(child1));

		AABB2 boundary2;
		boundary2.center = boundary.center;
		boundary2.halfDimension = childHalfDimension;
		boundary2.center.X() -= childHalfDimension;
		boundary2.center.Y() -= childHalfDimension;
		unique_ptr<Graph> child2(new QuadTree(subdivideThreshold, boundary2));
		child2->setParent(this);
		children.push_back(move(child2));

		AABB2 boundary3;
		boundary3.center = boundary.center;
		boundary3.halfDimension = childHalfDimension;
		boundary3.center.X() += childHalfDimension;
		boundary3.center.Y() -= childHalfDimension;
		unique_ptr<Graph> child3(new QuadTree(subdivideThreshold, boundary3));
		child3->setParent(this);
		children.push_back(move(child3));
	}

	void QuadTree::update(Entity& entity)
	{
		remove(entity);
		insert(entity);
	}

	bool QuadTree::withinBounds(const Entity& entity) const
	{
		Circle* circle = entity.getComponent<Circle>();
		if (circle == NULL)
		{
			return false;
		}

		return Intersection::contains(boundary, *circle);
	}
}
