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
#include <algorithm>
#include <stack>

#include "../common/AddressEquals.h"
#include "../math/MathFactory.h"
#include "NonTreeNodeException.h"
#include "PreorderConstNodeIterator.h"
#include "SimpleTreeNode.h"

using namespace std;

namespace simplicity
{
	SimpleTreeNode::SimpleTreeNode() :
		parent(NULL)
	{
	}

	SimpleTreeNode::SimpleTreeNode(const SimpleTreeNode& original) :
		parent(NULL)
	{
		operator=(original);
	}

	void SimpleTreeNode::addChild(TreeNode& child)
	{
		children.push_back(child);
	}

	void SimpleTreeNode::connectTo(Node& otherNode)
	{
		TreeNode* otherTreeNode = dynamic_cast<TreeNode*>(&otherNode);
		if (otherTreeNode == NULL)
		{
			throw NonTreeNodeException();
		}

		addChild(*otherTreeNode);
	}

	std::shared_ptr<Node> SimpleTreeNode::copy() const
	{
		std::shared_ptr<Node> copy(new SimpleTreeNode(*this));
		return copy;
	}

	void SimpleTreeNode::disconnectFrom(Node& otherNode)
	{
		TreeNode* otherTreeNode = dynamic_cast<TreeNode*>(&otherNode);
		if (otherTreeNode == NULL)
		{
			return;
		}

		removeChild(*otherTreeNode);
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

	vector<reference_wrapper<TreeNode> > SimpleTreeNode::getChildren() const
	{
		return children;
	}

	vector<reference_wrapper<Node> > SimpleTreeNode::getConnectedNodes() const
	{
		return vector<reference_wrapper<Node> >(children.begin(), children.end());
	}

	TreeNode* SimpleTreeNode::getParent() const
	{
		return parent;
	}

	bool SimpleTreeNode::hasChildren() const
	{
		return !children.empty();
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

	SimpleTreeNode& SimpleTreeNode::operator=(const SimpleTreeNode& original)
	{
		BaseNode::operator=(original);
		children.clear();
		parent = NULL;

		return *this;
	}

	void SimpleTreeNode::removeChild(TreeNode& child)
	{
		children.erase(remove_if(children.begin(), children.end(), AddressEquals<TreeNode>(child)));
	}

	void SimpleTreeNode::setParent(TreeNode* parent)
	{
		this->parent = parent;
	}
}
