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
#include "../math/MathFunctions.h"
#include "../model/shape/Circle.h"
#include "QuadTree.h"

using namespace std;

namespace simplicity
{
	QuadTree::QuadTree(unsigned int subdivideThreshold, const Square& boundary, Plane plane) :
		boundary(boundary),
		children(),
		connections(),
		entities(),
		parent(NULL),
		plane(plane),
		subdivideThreshold(subdivideThreshold),
		transform()
	{
		transform.setIdentity();
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

	Matrix44 QuadTree::getAbsoluteTransform() const
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

	const Model& QuadTree::getBoundary() const
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

	vector<Entity*> QuadTree::getEntitiesWithinBounds(const Model& bounds, const Vector3& position) const
	{
		vector<Entity*> entitiesWithinBounds;

		if (!Intersection::intersect(boundary, bounds,
				projectOntoPlane(position - getPosition3(getAbsoluteTransform()))))
		{
			return entitiesWithinBounds;
		}

		for (Entity* entity : entities)
		{
			Model* entityBounds = entity->getComponent<Model>(Categories::BOUNDS);
			if (entityBounds == NULL)
			{
				entitiesWithinBounds.push_back(entity);
				continue;
			}

			Vector3 modelBoundsPosition = getPosition3(entity->getTransform() * entityBounds->getTransform());
			if (Intersection::intersect(*entityBounds, bounds, projectOntoPlane(position - modelBoundsPosition)))
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

	Graph* QuadTree::getParent()
	{
		return parent;
	}

	const Graph* QuadTree::getParent() const
	{
		return parent;
	}

	Matrix44& QuadTree::getTransform()
	{
		return transform;
	}

	const Matrix44& QuadTree::getTransform() const
	{
		return transform;
	}

	bool QuadTree::insert(Entity& entity)
	{
		Model* bounds = entity.getComponent<Model>(Categories::BOUNDS);
		if (bounds == NULL)
		{
			entities.push_back(&entity);
			return true;
		}

		Vector3 graphPosition = getPosition3(getAbsoluteTransform());
		Vector3 boundsPosition = getPosition3(entity.getTransform() * bounds->getTransform());

		Vector3 relativePosition = boundsPosition - graphPosition;
		if (!Intersection::contains(boundary, *bounds, projectOntoPlane(relativePosition)))
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

	bool QuadTree::insert(Entity& entity, const Entity& /*parent*/)
	{
		return insert(entity);
	}

	Vector3 QuadTree::projectOntoPlane(const Vector3& position) const
	{
		if (plane == Plane::XY)
		{
			return Vector3(position.X(), position.Y(), 0.0f);
		}

		return Vector3(position.X(), position.Z(), 0.0f);
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

	void QuadTree::setParent(Graph* parent)
	{
		this->parent = parent;
	}

	void QuadTree::setTransform(const Matrix44& transform)
	{
		this->transform = transform;
	}

	void QuadTree::subdivide()
	{
		children.reserve(4);

		float childHalfDimension = boundary.getHalfEdgeLength() / 2.0f;
		float y = 0.0f;
		float z = 0.0f;
		if (plane == Plane::XY)
		{
			y = childHalfDimension;
		}
		else
		{
			z = childHalfDimension;
		}

		unique_ptr<Graph> child0(new QuadTree(subdivideThreshold, Square(childHalfDimension), plane));
		setPosition(child0->getTransform(), Vector3(childHalfDimension, y, z));
		child0->setParent(this);
		children.push_back(move(child0));

		unique_ptr<Graph> child1(new QuadTree(subdivideThreshold, Square(childHalfDimension), plane));
		setPosition(child1->getTransform(), Vector3(childHalfDimension, -y, -z));
		child1->setParent(this);
		children.push_back(move(child1));

		unique_ptr<Graph> child2(new QuadTree(subdivideThreshold, Square(childHalfDimension), plane));
		setPosition(child2->getTransform(), Vector3(-childHalfDimension, y, z));
		child2->setParent(this);
		children.push_back(move(child2));

		unique_ptr<Graph> child3(new QuadTree(subdivideThreshold, Square(childHalfDimension), plane));
		setPosition(child3->getTransform(), Vector3(-childHalfDimension, -y, -z));
		child3->setParent(this);
		children.push_back(move(child3));
	}

	void QuadTree::update(Entity& entity)
	{
		remove(entity);
		insert(entity);
	}
}
