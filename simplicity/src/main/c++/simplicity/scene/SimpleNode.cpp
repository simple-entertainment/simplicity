/*
 * Copyright © 2011 Simple Entertainment Limited
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
#include <stack>

#include "../math/SimpleTransformationMatrix44.h"
#include "SimpleNode.h"
#include "PreorderNodeIterator.h"

using namespace std;

namespace simplicity
{
	SimpleNode::SimpleNode() :
		children(), collidable(true), id(0), modifiable(true), parent(), transformation(
			new SimpleTransformationMatrix44<>()), visible(true)
	{
	}

	SimpleNode::~SimpleNode()
	{
	}

	void SimpleNode::addChild(std::shared_ptr<Node> child)
	{
		children.push_back(child);
		child->setParent(getThisShared());
	}

	unique_ptr<TransformationMatrix<> > SimpleNode::getAbsoluteTransformation() const
	{
		unique_ptr<SimpleTransformationMatrix44<> > absoluteTransformation(new SimpleTransformationMatrix44<>());
		stack<std::shared_ptr<Node> > ancestors;
		std::shared_ptr<Node> currentNode(((Node*) this)->getThisShared());

		while (currentNode.get() != NULL)
		{
			ancestors.push(currentNode);
			currentNode = currentNode->getParent();
		}

		while (!ancestors.empty())
		{
			*absoluteTransformation *= ancestors.top()->getTransformation();
			ancestors.pop();
		}

		return move(absoluteTransformation);
	}

	// const BoundingVolume& SimpleNode::getBounds() const TODO
	// {
	// 	return (bounds);
	// }

	const vector<std::shared_ptr<Node> >& SimpleNode::getChildren() const
	{
		return children;
	}

	int SimpleNode::getId() const
	{
		return id;
	}

	std::shared_ptr<Node> SimpleNode::getParent() const
	{
		return parent;
	}

	TransformationMatrix<>& SimpleNode::getTransformation() const
	{
		return *transformation;
	}

	bool SimpleNode::hasChildren() const
	{
		if (!children.empty())
		{
			return true;
		}

		return false;
	}

	bool SimpleNode::isAncestor(const Node& ancestor) const
	{
		std::shared_ptr<Node> currentParent(parent);

		while (currentParent.get())
		{
			if (currentParent.get() == &ancestor)
			{
				return true;
			}

			currentParent = currentParent->getParent();
		}

		return false;
	}

	bool SimpleNode::isCollidable() const
	{
		return collidable;
	}

	bool SimpleNode::isModifiable() const
	{
		return modifiable;
	}

	bool SimpleNode::isSuccessor(const Node& successor) const
	{
		PreorderNodeIterator iterator(*this);

		while (iterator.hasMoreNodes())
		{
			if (iterator.getNextNode().get() == &successor && &successor != this)
			{
				return true;
			}
		}

		return false;
	}

	bool SimpleNode::isVisible() const
	{
		return visible;
	}

	void SimpleNode::removeChild(Node& child)
	{
		for (vector<std::shared_ptr<Node> >::iterator iterator = children.begin(); iterator != children.end();
			iterator++)
			{
			if ((*iterator).get() == &child)
			{
				children.erase(iterator);
				child.setParent(std::shared_ptr<Node>());
				break;
			}
		}
	}

	void SimpleNode::setCollidable(const bool collidable)
	{
		this->collidable = collidable;
	}

	void SimpleNode::setId(const int id)
	{
		this->id = id;
	}

	void SimpleNode::setModifiable(const bool modifiable)
	{
		this->modifiable = modifiable;
	}

	void SimpleNode::setParent(std::shared_ptr<Node> parent)
	{
		this->parent = parent;
	}

	void SimpleNode::setTransformation(unique_ptr<TransformationMatrix<> > transformation)
	{
		this->transformation = move(transformation);
	}

	void SimpleNode::setVisible(const bool visible)
	{
		this->visible = visible;
	}
}
