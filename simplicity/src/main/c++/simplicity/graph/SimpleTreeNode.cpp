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

#include "../math/MathFactory.h"
#include "SimpleTreeNode.h"
#include "PreorderConstNodeIterator.h"

using namespace std;

namespace simplicity
{
	SimpleTreeNode::SimpleTreeNode() :
		children(), component(NULL), parent(NULL), transformation(
			MathFactory::getInstance().createTransformationMatrix())
	{
	}

	SimpleTreeNode::~SimpleTreeNode()
	{
	}

	void SimpleTreeNode::addChild(TreeNode& child)
	{
		children.push_back(child);
	}

	void SimpleTreeNode::connectTo(Node& parent)
	{
		this->parent = dynamic_cast<TreeNode*>(&parent);
	}

	void SimpleTreeNode::disconnectFrom(Node& parent)
	{
		this->parent = NULL;
	}

	unique_ptr<TransformationMatrix<> > SimpleTreeNode::getAbsoluteTransformation() const
	{
		unique_ptr<TransformationMatrix<> > absoluteTransformation(
			MathFactory::getInstance().createTransformationMatrix());
		stack<const Node*> ancestors;
		const TreeNode* currentNode = this;

		while (currentNode != NULL)
		{
			ancestors.push(currentNode);
			currentNode = currentNode->getParent();
		}

		while (!ancestors.empty())
		{
			absoluteTransformation->multiply(ancestors.top()->getTransformation());
			ancestors.pop();
		}

		return move(absoluteTransformation);
	}

	const vector<reference_wrapper<TreeNode> >& SimpleTreeNode::getChildren() const
	{
		return children;
	}

	Component* SimpleTreeNode::getComponent() const
	{
		return component;
	}

	vector<reference_wrapper<Node> > SimpleTreeNode::getConnectedNodes() const
	{
		vector<reference_wrapper<Node> > connectedNodes;

		if (parent != NULL)
		{
			connectedNodes.push_back(*parent);
		}

		for (reference_wrapper<TreeNode> child : children)
		{
			connectedNodes.push_back(child.get());
		}

		return connectedNodes;
	}

	int SimpleTreeNode::getId() const
	{
		return id;
	}

	TreeNode* SimpleTreeNode::getParent() const
	{
		return parent;
	}

	TransformationMatrix<>& SimpleTreeNode::getTransformation() const
	{
		return *transformation;
	}

	bool SimpleTreeNode::hasChildren() const
	{
		if (!children.empty())
		{
			return true;
		}

		return false;
	}

	bool SimpleTreeNode::isAncestor(const TreeNode& ancestor) const
	{
		TreeNode* currentParent = parent;

		while (currentParent != NULL)
		{
			if (currentParent == &ancestor)
			{
				return true;
			}

			currentParent = currentParent->getParent();
		}

		return false;
	}

	bool SimpleTreeNode::isSuccessor(const TreeNode& successor) const
	{
		PreorderConstNodeIterator iterator(*this);

		while (iterator.hasMoreNodes())
		{
			if (&iterator.getNextNode() == &successor && &successor != this)
			{
				return true;
			}
		}

		return false;
	}

	void SimpleTreeNode::removeChild(TreeNode& child)
	{
		for (vector<reference_wrapper<TreeNode> >::iterator iterator = children.begin(); iterator != children.end();
			iterator++)
			{
			if (&(*iterator).get() == &child)
			{
				children.erase(iterator);
				child.disconnectFrom(*child.getParent());
				break;
			}
		}
	}

	void SimpleTreeNode::setComponent(Component* component)
	{
		this->component = component;
	}

	void SimpleTreeNode::setId(const int id)
	{
		this->id = id;
	}

	void SimpleTreeNode::setTransformation(unique_ptr<TransformationMatrix<> > transformation)
	{
		this->transformation = move(transformation);
	}
}
