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

#include "../../common/AddressEquals.h"
#include "NoPathException.h"
#include "SimplePathFinder.h"

using namespace std;

namespace simplicity
{
	SimplePathFinder::SimplePathFinder(const Node& start, const Node& finish) :
		distance(0), finish(finish), start(start)
	{
		markAsTraversed(start);
		openNodes.push_back(start);
	}

	SimplePathFinder::~SimplePathFinder()
	{
	}

	vector<reference_wrapper<const Node> > SimplePathFinder::findShortestPath()
	{
		do
		{
			if (stepForward())
			{
				return generatePath();
			}
		}
		while (!openNodes.empty());

		throw NoPathException();
	}

	vector<reference_wrapper<const Node> > SimplePathFinder::generatePath()
	{
		vector<reference_wrapper<const Node> > path;
		path.push_back(finish);
		const Node* currentNode = &finish;
		const Node* nextNode = &finish;

		while (currentNode != &start)
		{
			for (shared_ptr<const Node> adjacentNode : currentNode->getChildren())
			{
				if (isTraversed(*adjacentNode)
					&& nodeDistances.find(adjacentNode.get())->second < nodeDistances.find(nextNode)->second)
				{
					nextNode = adjacentNode.get();
				}
			}

			path.insert(path.begin(), *nextNode);
			currentNode = nextNode;
		}

		return path;
	}

	vector<reference_wrapper<const Node> > SimplePathFinder::getOpenNodes()
	{
		return openNodes;
	}

	bool SimplePathFinder::isTraversed(const Node& node)
	{
		return find_if(traversedNodes.begin(), traversedNodes.end(), AddressEquals<Node>(node)) != traversedNodes.end();
	}

	void SimplePathFinder::markAsTraversed(const Node& node)
	{
		traversedNodes.push_back(node);
		nodeDistances.insert(pair<const Node*, int>(&node, distance));
	}

	bool SimplePathFinder::stepForward()
	{
		vector<reference_wrapper<const Node> > newOpenNodes;
		distance++;

		for (reference_wrapper<const Node> openNode : openNodes)
		{
			for (shared_ptr<const Node> adjacentNode : openNode.get().getChildren())
			{
				if (adjacentNode.get() == &finish)
				{
					markAsTraversed(*adjacentNode);
					return true;
				}

				if (!isTraversed(*adjacentNode))
				{
					markAsTraversed(*adjacentNode);
					newOpenNodes.push_back(*adjacentNode);
				}
			}
		}

		openNodes = newOpenNodes;

		return false;
	}
}
