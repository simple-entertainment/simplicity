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
#include "BreadthFirstConstNodeIterator.h"

using namespace std;

namespace simplicity
{
	BreadthFirstConstNodeIterator::BreadthFirstConstNodeIterator(const Node& root) :
		queuedNodes(), root(root), unvisitedNodes()
	{
		queuedNodes.push_back(root);
		unvisitedNodes.push(root);
	}

	BreadthFirstConstNodeIterator::~BreadthFirstConstNodeIterator()
	{
	}

	const Node& BreadthFirstConstNodeIterator::getNextNode()
	{
		if (unvisitedNodes.empty())
		{
			throw NoMoreNodesException();
		}

		const Node& nextNode = unvisitedNodes.front().get();
		vector<reference_wrapper<Node> > connectedNodes = nextNode.getConnectedNodes();
		for (reference_wrapper<Node> connectedNode : connectedNodes)
		{
			if (find_if(queuedNodes.begin(), queuedNodes.end(), AddressEquals<Node>(connectedNode.get()))
				== queuedNodes.end())
			{
				queuedNodes.push_back(connectedNode.get());
				unvisitedNodes.push(connectedNode.get());
			}
		}

		unvisitedNodes.pop();

		return nextNode;
	}

	bool BreadthFirstConstNodeIterator::hasMoreNodes() const
	{
		return !unvisitedNodes.empty();
	}
}
