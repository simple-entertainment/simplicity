/*
 * Copyright © 2014 Simple Entertainment Limited
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
#include "../model/Model.h"
#include "OcTree.h"

using namespace std;

namespace simplicity
{
	OcTree::OcTree(unsigned int subdivideThreshold, const Cube& bounds) :
		bounds(bounds),
		children(),
		connections(),
		entities(),
		parent(nullptr),
		subdivideThreshold(subdivideThreshold),
		transform()
	{
		transform.setIdentity();
	}

	void OcTree::addEntityFromChild()
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

	void OcTree::connectTo(SceneGraph& graph)
	{
		connections.push_back(&graph);
	}

	void OcTree::disconnectFrom(SceneGraph& graph)
	{
		if (find(connections.begin(), connections.end(), &graph) != connections.end())
		{
			connections.erase(std::remove(connections.begin(), connections.end(), &graph));
		}
	}

	Matrix44 OcTree::getAbsoluteTransform() const
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

	const Shape& OcTree::getBounds() const
	{
		return bounds;
	}

	vector<SceneGraph*> OcTree::getChildren() const
	{
		vector<SceneGraph*> rawChildren;
		for (unsigned int index = 0; index < children.size(); index++)
		{
			rawChildren.push_back(children[index].get());
		}

		return rawChildren;
	}

	vector<Entity*>& OcTree::getEntities()
	{
		return entities;
	}

	const vector<Entity*>& OcTree::getEntities() const
	{
		return entities;
	}

	vector<Entity*> OcTree::getEntitiesWithinBounds(const Shape& bounds, const Vector3& position) const
	{
		// Create a vector here and reserve some space to avoid lots of copying from one vector to another and to
		// reduce the amount of allocations.
		vector<Entity*> entitiesWithinBounds;
		entitiesWithinBounds.reserve(128);

		getEntitiesWithinBounds(bounds, position, entitiesWithinBounds);

		return entitiesWithinBounds;
	}

	void OcTree::getEntitiesWithinBounds(const Shape& bounds, const Vector3& position,
			vector<Entity*>& entitiesWithinBounds) const
	{
		// First check that this node intersects the bounds.
		if (!Intersection::intersect(this->bounds, bounds, position - getPosition3(getAbsoluteTransform())))
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

	SceneGraph* OcTree::getParent()
	{
		return parent;
	}

	const SceneGraph* OcTree::getParent() const
	{
		return parent;
	}

	Matrix44& OcTree::getTransform()
	{
		return transform;
	}

	const Matrix44& OcTree::getTransform() const
	{
		return transform;
	}

	bool OcTree::insert(Entity& entity)
	{
		bool boundsExist = false;

		for (Component* component : entity.getComponents())
		{
			if (component->getBounds() == nullptr)
			{
				continue;
			}

			boundsExist = true;

			Vector3 graphPosition = getPosition3(getAbsoluteTransform());
			Vector3 boundsPosition = getPosition3(entity.getTransform() * component->getTransform());

			// Check that the entity intersects the bounds.
			Vector3 relativePosition = boundsPosition - graphPosition;
			if (!Intersection::contains(bounds, *component->getBounds(), relativePosition))
			{
				return false;
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

	bool OcTree::insert(Entity& entity, const Entity& /*parent*/)
	{
		return insert(entity);
	}

	bool OcTree::isWithinBounds(const Entity& entity, const Shape& bounds, const Vector3& position) const
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

	bool OcTree::remove(const Entity& entity)
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

	void OcTree::setParent(SceneGraph* parent)
	{
		this->parent = parent;
	}

	void OcTree::setTransform(const Matrix44& transform)
	{
		this->transform = transform;
	}

	void OcTree::subdivide()
	{
		children.reserve(8);

		float childHalfDimension = bounds.getHalfEdgeLength() / 2.0f;

		unique_ptr<OcTree> child0(new OcTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child0->getTransform(), Vector3(-childHalfDimension, childHalfDimension, childHalfDimension));
		child0->setParent(this);
		children.push_back(move(child0));

		unique_ptr<OcTree> child1(new OcTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child1->getTransform(), Vector3(childHalfDimension, childHalfDimension, childHalfDimension));
		child1->setParent(this);
		children.push_back(move(child1));

		unique_ptr<OcTree> child2(new OcTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child2->getTransform(), Vector3(-childHalfDimension, -childHalfDimension, childHalfDimension));
		child2->setParent(this);
		children.push_back(move(child2));

		unique_ptr<OcTree> child3(new OcTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child3->getTransform(), Vector3(childHalfDimension, -childHalfDimension, childHalfDimension));
		child3->setParent(this);
		children.push_back(move(child3));

		unique_ptr<OcTree> child4(new OcTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child4->getTransform(), Vector3(-childHalfDimension, childHalfDimension, -childHalfDimension));
		child4->setParent(this);
		children.push_back(move(child4));

		unique_ptr<OcTree> child5(new OcTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child5->getTransform(), Vector3(childHalfDimension, childHalfDimension, -childHalfDimension));
		child5->setParent(this);
		children.push_back(move(child5));

		unique_ptr<OcTree> child6(new OcTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child6->getTransform(), Vector3(-childHalfDimension, -childHalfDimension, -childHalfDimension));
		child6->setParent(this);
		children.push_back(move(child6));

		unique_ptr<OcTree> child7(new OcTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child7->getTransform(), Vector3(childHalfDimension, -childHalfDimension, -childHalfDimension));
		child7->setParent(this);
		children.push_back(move(child7));
	}

	void OcTree::update(Entity& entity)
	{
		remove(entity);
		insert(entity);
	}
}
