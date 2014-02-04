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
#include "../model/shape/Circle.h"
#include "OctTree.h"

using namespace std;

namespace simplicity
{
	OctTree::OctTree(unsigned int subdivideThreshold, const Cube& boundary) :
		boundary(boundary),
		children(),
		connections(),
		entities(),
		parent(NULL),
		subdivideThreshold(subdivideThreshold),
		transform()
	{
		transform.setIdentity();
	}

	void OctTree::addChild(std::unique_ptr<Graph>)
	{
	}

	void OctTree::addEntityFromChild()
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

	void OctTree::connectTo(Graph& graph)
	{
		connections.push_back(&graph);
	}

	void OctTree::disconnectFrom(Graph& graph)
	{
		if (find(connections.begin(), connections.end(), &graph) == connections.end())
		{
			connections.erase(std::remove(connections.begin(), connections.end(), &graph));
		}
	}

	Matrix44 OctTree::getAbsoluteTransform() const
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

	const Model& OctTree::getBoundary() const
	{
		return boundary;
	}

	vector<Graph*> OctTree::getChildren() const
	{
		vector<Graph*> rawChildren;
		for (unsigned int index = 0; index < children.size(); index++)
		{
			rawChildren.push_back(children[index].get());
		}

		return rawChildren;
	}

	vector<Entity*>& OctTree::getEntities()
	{
		return entities;
	}

	const vector<Entity*>& OctTree::getEntities() const
	{
		return entities;
	}

	vector<Entity*> OctTree::getEntitiesWithinBounds(const Model& bounds, const Vector3& position) const
	{
		vector<Entity*> entitiesWithinBounds;

		if (!Intersection::intersect(boundary, bounds, position - getPosition3(getAbsoluteTransform())))
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

	Graph* OctTree::getParent()
	{
		return parent;
	}

	const Graph* OctTree::getParent() const
	{
		return parent;
	}

	Matrix44& OctTree::getTransform()
	{
		return transform;
	}

	const Matrix44& OctTree::getTransform() const
	{
		return transform;
	}

	bool OctTree::insert(Entity& entity)
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
		if (!Intersection::contains(boundary, *bounds, relativePosition))
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

	bool OctTree::insert(Entity& entity, const Entity& /*parent*/)
	{
		return insert(entity);
	}

	bool OctTree::remove(const Entity& entity)
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

	unique_ptr<Graph> OctTree::removeChild(Graph&)
	{
		return unique_ptr<Graph>();
	}

	void OctTree::setParent(Graph* parent)
	{
		this->parent = parent;
	}

	void OctTree::setTransform(const Matrix44& transform)
	{
		this->transform = transform;
	}

	void OctTree::subdivide()
	{
		children.reserve(8);

		float childHalfDimension = boundary.getHalfEdgeLength() / 2.0f;

		unique_ptr<Graph> child0(new OctTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child0->getTransform(), Vector3(-childHalfDimension, childHalfDimension, childHalfDimension));
		child0->setParent(this);
		children.push_back(move(child0));

		unique_ptr<Graph> child1(new OctTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child1->getTransform(), Vector3(childHalfDimension, childHalfDimension, childHalfDimension));
		child1->setParent(this);
		children.push_back(move(child1));

		unique_ptr<Graph> child2(new OctTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child2->getTransform(), Vector3(-childHalfDimension, -childHalfDimension, childHalfDimension));
		child2->setParent(this);
		children.push_back(move(child2));

		unique_ptr<Graph> child3(new OctTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child3->getTransform(), Vector3(childHalfDimension, -childHalfDimension, childHalfDimension));
		child3->setParent(this);
		children.push_back(move(child3));

		unique_ptr<Graph> child4(new OctTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child4->getTransform(), Vector3(-childHalfDimension, childHalfDimension, -childHalfDimension));
		child4->setParent(this);
		children.push_back(move(child4));

		unique_ptr<Graph> child5(new OctTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child5->getTransform(), Vector3(childHalfDimension, childHalfDimension, -childHalfDimension));
		child5->setParent(this);
		children.push_back(move(child5));

		unique_ptr<Graph> child6(new OctTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child6->getTransform(), Vector3(-childHalfDimension, -childHalfDimension, -childHalfDimension));
		child6->setParent(this);
		children.push_back(move(child6));

		unique_ptr<Graph> child7(new OctTree(subdivideThreshold, Cube(childHalfDimension)));
		setPosition(child7->getTransform(), Vector3(childHalfDimension, -childHalfDimension, -childHalfDimension));
		child7->setParent(this);
		children.push_back(move(child7));
	}

	void OctTree::update(Entity& entity)
	{
		remove(entity);
		insert(entity);
	}
}
