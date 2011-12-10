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
#include "../math/SimpleTransformationMatrix44.h"
#include "SimpleNode.h"
#include "PreorderNodeIterator.h"

using namespace boost;
using namespace std;

namespace simplicity
{
	SimpleNode::SimpleNode() :
		children(vector<shared_ptr<Node> >()), collidable(true), id(0), modifiable(true), transformation(
			new SimpleTransformationMatrix44<float>), visible(true)
	{
	}

	SimpleNode::~SimpleNode()
	{
	}

	void SimpleNode::addChild(shared_ptr<Node> child)
	{
		children.push_back(child);
		child->setParent(getThisShared());
	}

	const TransformationMatrix<float>& SimpleNode::getAbsoluteTransformation() const
	{
		absoluteTransformation.reset(new SimpleTransformationMatrix44<float>);
		Node* thisNode = (Node*) this;
		shared_ptr<Node> currentNode(thisNode->getThisShared());

		while (currentNode.get())
		{
			absoluteTransformation->multiplyLeft(currentNode->getTransformation());

			currentNode = currentNode->getParent();
		}

		return (*absoluteTransformation);
	}

	// const BoundingVolume& SimpleNode::getBounds() const TODO
	// {
	// 	return (bounds);
	// }

	const vector<shared_ptr<Node> >& SimpleNode::getChildren() const
	{
		return (children);
	}

	int SimpleNode::getId() const
	{
		return (id);
	}

	shared_ptr<Node> SimpleNode::getParent() const
	{
		return (parent);
	}

	TransformationMatrix<float>& SimpleNode::getTransformation() const
	{
		return (*transformation);
	}

	bool SimpleNode::hasChildren() const
	{
		if (!children.empty())
		{
			return (true);
		}

		return (false);
	}

	bool SimpleNode::isAncestor(const Node& ancestor) const
	{
		shared_ptr<Node> currentParent(parent);

		while (currentParent)
		{
			if (currentParent.get() == &ancestor)
			{
				return (true);
			}

			currentParent = currentParent->getParent();
		}

		return (false);
	}

	bool SimpleNode::isCollidable() const
	{
		return (collidable);
	}

	bool SimpleNode::isModifiable() const
	{
		return (modifiable);
	}

	bool SimpleNode::isSuccessor(const Node& successor) const
	{
		PreorderNodeIterator iterator(*this);

		while (iterator.hasMoreNodes())
		{
			if (iterator.getNextNode().get() == &successor && &successor != this)
			{
				return (true);
			}
		}

		return (false);
	}

	bool SimpleNode::isVisible() const
	{
		return (visible);
	}

	void SimpleNode::removeChild(Node& child)
	{
		vector<shared_ptr<Node> >::iterator iterator = children.begin();
		for (unsigned int index = 0; index < children.size(); index++)
		{
			if (children.at(index).get() == &child)
			{
				children.erase(iterator);
				child.setParent(shared_ptr<Node>());
				break;
			}

			iterator++;
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

	void SimpleNode::setParent(shared_ptr<Node> parent)
	{
		this->parent = parent;
	}

	void SimpleNode::setTransformation(shared_ptr<TransformationMatrix<float> > transformation)
	{
		this->transformation = transformation;
	}

	void SimpleNode::setVisible(const bool visible)
	{
		this->visible = visible;
	}
}
