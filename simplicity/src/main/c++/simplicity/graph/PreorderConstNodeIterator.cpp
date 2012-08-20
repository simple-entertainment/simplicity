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
#include "../graph/NoMoreNodesException.h"
#include "PreorderConstNodeIterator.h"

using namespace std;

namespace simplicity
{
	PreorderConstNodeIterator::PreorderConstNodeIterator(const TreeNode& root) :
		backtracksToNextNode(0), root(root)
	{
		backtracksToNextNode = 0;
		nextNode = &root;
	}

	PreorderConstNodeIterator::~PreorderConstNodeIterator()
	{
	}

	const TreeNode* PreorderConstNodeIterator::findNextNode()
	{
		backtracksToNextNode = 0;

		// If the only node in the traversal is the root, end the iteration.
		if (nextNode == &root && !nextNode->hasChildren())
		{
			backtracksToNextNode++;

			return NULL;
		}

		// If the current node has children, move to it's first child.
		if (nextNode->hasChildren())
		{
			return &nextNode->getChildren().at(0).get();
		}

		// If the current node has no children, backtrack to the next sibling.
		const vector<reference_wrapper<TreeNode> >* siblings = &nextNode->getParent()->getChildren();

		// While the current node has no more siblings, move to it's parent.
		backtracksToNextNode++;
		while (nextNode == &siblings->back().get())
		{
			backtracksToNextNode++;
			nextNode = nextNode->getParent();

			// If the next node is the root, end the iteration.
			if (nextNode == &root)
			{
				return NULL;
			}

			siblings = &nextNode->getParent()->getChildren();
		}

		// If the next node has more siblings, move to it's next sibling.
		vector<reference_wrapper<TreeNode> >::const_iterator iterator = find_if(siblings->begin(), siblings->end(),
			AddressEquals<TreeNode>(*nextNode));
		iterator++;

		return &iterator->get();
	}

	int PreorderConstNodeIterator::getBacktracksToNextNode() const
	{
		return backtracksToNextNode;
	}

	const Node& PreorderConstNodeIterator::getNextNode()
	{
		// If the iteration has ended.
		if (nextNode == NULL)
		{
			throw NoMoreNodesException();
		}

		const Node* currentNode = nextNode;
		nextNode = findNextNode();

		return *currentNode;
	}

	bool PreorderConstNodeIterator::hasMoreNodes() const
	{
		return nextNode != NULL;
	}
}
