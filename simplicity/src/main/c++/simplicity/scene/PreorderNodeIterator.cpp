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

#include "PreorderNodeIterator.h"

using namespace std;

namespace simplicity
{
	PreorderNodeIterator::PreorderNodeIterator(const Node& root) :
		backtracksToNextNode(0), root(root)
	{
		reset();
	}

	PreorderNodeIterator::~PreorderNodeIterator()
	{
	}

	shared_ptr<Node> PreorderNodeIterator::findNextNode()
	{
		backtracksToNextNode = 0;

		// If the only node in the traversal is the root, end the iteration.
		if (nextNode.get() == &root && !nextNode->hasChildren())
		{
			backtracksToNextNode++;

			return shared_ptr<Node>();
		}

		// If the current node has children, move to it's first child.
		if (nextNode->hasChildren())
		{
			return nextNode->getChildren().at(0);
		}

		// If the current node has no children, backtrack to the next sibling.
		vector<shared_ptr<Node> > siblings = nextNode->getParent()->getChildren();

		// While the current node has no more siblings, move to it's parent.
		backtracksToNextNode++;
		while (nextNode == siblings.back())
		{
			backtracksToNextNode++;
			nextNode = nextNode->getParent();

			// If the next node is the root, end the iteration.
			if (nextNode.get() == &root)
			{
				return shared_ptr<Node>();
			}

			siblings = nextNode->getParent()->getChildren();
		}

		// If the next node has more siblings, move to it's next sibling.
		vector<shared_ptr<Node> >::iterator iterator = find(siblings.begin(), siblings.end(), nextNode);
		iterator++;

		return *iterator;
	}

	int PreorderNodeIterator::getBacktracksToNextNode() const
	{
		return backtracksToNextNode;
	}

	shared_ptr<Node> PreorderNodeIterator::getNextNode()
	{
		// If the iteration has ended.
		if (!nextNode.get())
		{
			return shared_ptr<Node>();
		}

		shared_ptr<Node> currentNode(nextNode);
		nextNode = findNextNode();

		return currentNode;
	}

	bool PreorderNodeIterator::hasMoreNodes() const
	{
		return nextNode.get();
	}

	void PreorderNodeIterator::reset()
	{
		backtracksToNextNode = 0;
		Node* rootNode = (Node*) &root;
		nextNode = rootNode->getThisShared();
	}
}
