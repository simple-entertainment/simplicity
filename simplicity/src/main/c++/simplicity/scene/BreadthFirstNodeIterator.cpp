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

#include "BreadthFirstNodeIterator.h"

using namespace boost;
using namespace std;

namespace simplicity
{
	BreadthFirstNodeIterator::BreadthFirstNodeIterator(const Node& root) :
		root(root)
	{
		reset();
	}

	BreadthFirstNodeIterator::~BreadthFirstNodeIterator()
	{
	}

	shared_ptr<Node> BreadthFirstNodeIterator::getNextNode()
	{
		if (unvisitedNodes.empty())
		{
			return shared_ptr<Node>();
		}

		shared_ptr<Node> nextNode(unvisitedNodes.front());
		for (unsigned int index; index < nextNode->getChildren().size(); index++)
		{
			if (find(queuedNodes.begin(), queuedNodes.end(), nextNode->getChildren().at(index)) == queuedNodes.end())
			{
				queuedNodes.push_back(nextNode->getChildren().at(index));
				unvisitedNodes.push(nextNode->getChildren().at(index));
			}
		}

		unvisitedNodes.pop();

		return nextNode;
	}

	bool BreadthFirstNodeIterator::hasMoreNodes() const
	{
		return !unvisitedNodes.empty();
	}

	void BreadthFirstNodeIterator::reset()
	{
		queuedNodes.clear();
		unvisitedNodes = queue<shared_ptr<Node> >();

		Node& root = (Node&) this->root;

		queuedNodes.push_back(root.getThisShared());
		unvisitedNodes.push(root.getThisShared());
	}
}
