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
#include "QuadTree.h"

using namespace std;

namespace simplicity
{
	QuadTree::QuadTree(unsigned int subdivideThreshold, const Square& bounds, Plane plane) :
		absoluteTransform(),
		bounds(bounds),
		children(),
		connections(),
		entities(),
		parent(nullptr),
		plane(plane),
		subdivideThreshold(subdivideThreshold),
		transform()
	{
		absoluteTransform.setIdentity();
		transform.setIdentity();
	}

	void QuadTree::addEntityFromChild()
	{
		for (unsigned int index = 0; index < children.size(); index++)
		{
			if (!children[index]->getEntities().empty())
			{
				Entity* entity = children[index]->getEntities().front();
				children[index]->remove(*entity);
				entities.push_back(entity);
				return;
			}
		}
	}

	void QuadTree::connectTo(SceneGraph& graph)
	{
		connections.push_back(&graph);
	}

	void QuadTree::disconnectFrom(SceneGraph& graph)
	{
		if (find(connections.begin(), connections.end(), &graph) != connections.end())
		{
			connections.erase(std::remove(connections.begin(), connections.end(), &graph));
		}
	}

	Matrix44 QuadTree::getAbsoluteTransform() const
	{
		return absoluteTransform;
	}

	const Shape& QuadTree::getBounds() const
	{
		return bounds;
	}

	vector<SceneGraph*> QuadTree::getChildren() const
	{
		vector<SceneGraph*> rawChildren;
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

	vector<Entity*> QuadTree::getEntitiesWithinBounds(const Shape& bounds, const Vector3& position) const
	{
		// Create a vector here and reserve some space to avoid lots of copying from one vector to another and to
		// reduce the amount of allocations.
		vector<Entity*> entitiesWithinBounds;
		entitiesWithinBounds.reserve(128);

		getEntitiesWithinBounds(bounds, position, entitiesWithinBounds);

		return entitiesWithinBounds;
	}

	void QuadTree::getEntitiesWithinBounds(const Shape& bounds, const Vector3& position,
			vector<Entity*>& entitiesWithinBounds) const
	{
		// First check that this node intersects the bounds.
		if (!Intersection::intersect(this->bounds, bounds, projectOntoPlane(position - getPosition3(absoluteTransform))))
		{
			return;
		}

		for (Entity* entity : entities)
		{
			if (isWithinBounds(*entity, bounds, position))
			{
				entitiesWithinBounds.push_back(entity);
			}
		}

		// Do this for all the children as well (recursive).
		for (unsigned int index = 0; index < children.size(); index++)
		{
			children[index]->getEntitiesWithinBounds(bounds, position, entitiesWithinBounds);
		}
	}

	SceneGraph* QuadTree::getParent()
	{
		return parent;
	}

	const SceneGraph* QuadTree::getParent() const
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
		bool boundsExist = false;

		for (Component* component : entity.getComponents())
		{
			if (component->getBounds() == nullptr)
			{
				continue;
			}

			boundsExist = true;

			Vector3 graphPosition = getPosition3(absoluteTransform);
			Vector3 boundsPosition = getPosition3(entity.getTransform() * component->getTransform());

			// Check that the entity intersects the bounds.
			Vector3 relativePosition = boundsPosition - graphPosition;
			if (!Intersection::contains(bounds, *component->getBounds(), projectOntoPlane(relativePosition)))
			{
				continue;
			}

			if (entities.size() == subdivideThreshold && children.empty())
			{
				subdivide();
			}

			// Attempt to insert the entity into one of the children (recursive).
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

		if (!boundsExist)
		{
			// If the entity has no bounds we insert it here.
			entities.push_back(&entity);
			return true;
		}

		return false;
	}

	bool QuadTree::insert(Entity& entity, const Entity& /*parent*/)
	{
		return insert(entity);
	}

	bool QuadTree::isWithinBounds(const Entity& entity, const Shape& bounds, const Vector3& position) const
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

	Vector3 QuadTree::projectOntoPlane(const Vector3& position) const
	{
		if (plane == Plane::XY)
		{
			return Vector3(position.X(), position.Y(), 0.0f);
		}

		if (plane == Plane::XZ)
		{
			return Vector3(position.X(), position.Z(), 0.0f);
		}

		return Vector3(position.Y(), position.Z(), 0.0f);
	}

	bool QuadTree::remove(const Entity& entity)
	{
		if (find(entities.begin(), entities.end(), &entity) == entities.end())
		{
			// The entity is not in this node, try the children (recursive).
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

		// Bring an entity up from the children to replace the removed one.
		if (entities.size() < subdivideThreshold)
		{
			addEntityFromChild();
		}

		// If this is still true that means that we don't have any entities in the children so lets get rid of them.
		if (entities.size() < subdivideThreshold)
		{
			children.clear();
		}

		return true;
	}

	void QuadTree::setParent(SceneGraph* parent)
	{
		this->parent = parent;

		if (parent == nullptr)
		{
			absoluteTransform = transform;
		}
		else
		{
			absoluteTransform = transform * parent->getAbsoluteTransform();
		}
	}

	void QuadTree::setTransform(const Matrix44& transform)
	{
		this->transform = transform;
	}

	void QuadTree::subdivide()
	{
		children.reserve(4);

		float childHalfDimension = bounds.getHalfEdgeLength() / 2.0f;
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		if (plane == Plane::XY)
		{
			x = childHalfDimension;
			y = childHalfDimension;
		}
		else if (plane == Plane::XZ)
		{
			x = childHalfDimension;
			z = childHalfDimension;
		}
		else
		{
			y = childHalfDimension;
			z = childHalfDimension;
		}

		unique_ptr<QuadTree> child0(new QuadTree(subdivideThreshold, Square(childHalfDimension), plane));
		setPosition(child0->getTransform(), Vector3(x, y, z));
		child0->setParent(this);
		children.push_back(move(child0));

		unique_ptr<QuadTree> child1(new QuadTree(subdivideThreshold, Square(childHalfDimension), plane));
		setPosition(child1->getTransform(), Vector3(x, -y, -z));
		child1->setParent(this);
		children.push_back(move(child1));

		unique_ptr<QuadTree> child2(new QuadTree(subdivideThreshold, Square(childHalfDimension), plane));
		setPosition(child2->getTransform(), Vector3(-x, y, z));
		child2->setParent(this);
		children.push_back(move(child2));

		unique_ptr<QuadTree> child3(new QuadTree(subdivideThreshold, Square(childHalfDimension), plane));
		setPosition(child3->getTransform(), Vector3(-x, -y, -z));
		child3->setParent(this);
		children.push_back(move(child3));
	}

	void QuadTree::update(Entity& entity)
	{
		remove(entity);
		insert(entity);
	}
}
