/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <algorithm>

#include "../../common/shared_equals_raw.h"
#include "NoPathException.h"
#include "SimplePathFinder.h"

using namespace boost;
using namespace std;

namespace simplicity
{
  SimplePathFinder::SimplePathFinder(const Node& start, const Node& finish) :
      distance(0), finish(finish), start(start)
  {
    markAsTraversed(start);
    boundaryNodes.push_back(start.getThisShared());
  }

  SimplePathFinder::~SimplePathFinder()
  {
  }

  vector<shared_ptr<const Node> >
  SimplePathFinder::findShortestPath()
  {
    do
    {
      if (stepForward())
      {
        return (generatePath());
      }
    }
    while (!boundaryNodes.empty());

    throw NoPathException();
  }

  vector<shared_ptr<const Node> >
  SimplePathFinder::generatePath()
  {
    vector<shared_ptr<const Node> > path;
    path.push_back(finish.getThisShared());
    shared_ptr<const Node> currentNode(finish.getThisShared());
    shared_ptr<const Node> nextNode(finish.getThisShared());

    while (currentNode.get() != &start)
    {
      for (unsigned int adjacentNodeIndex = 0; adjacentNodeIndex < currentNode->getChildren().size(); adjacentNodeIndex++)
      {
        shared_ptr<Node> adjacentNode(currentNode->getChildren().at(adjacentNodeIndex));
        if (isTraversed(*adjacentNode) && nodeDistances.find(adjacentNode)->second < nodeDistances.find(nextNode)->second)
        {
          nextNode = adjacentNode;
        }
      }

      path.insert(path.begin(), nextNode);
      currentNode = nextNode;
    }

    return (path);
  }

  vector<shared_ptr<const Node> >
  SimplePathFinder::getBoundaryNodes()
  {
    return (boundaryNodes);
  }

  bool
  SimplePathFinder::isTraversed(const Node& node)
  {
    shared_equals_raw<const Node> sharedEqualsRaw(&node);

    return (find_if(traversedNodes.begin(), traversedNodes.end(), sharedEqualsRaw) != traversedNodes.end());
  }

  void
  SimplePathFinder::markAsTraversed(const Node& node)
  {
    traversedNodes.push_back(node.getThisShared());
    nodeDistances.insert(pair<shared_ptr<const Node>, int>(node.getThisShared(), distance));
  }

  bool
  SimplePathFinder::stepForward()
  {
    vector<shared_ptr<const Node> > newBoundaryNodes;
    distance++;

    for (unsigned int boundaryNodeIndex = 0; boundaryNodeIndex < boundaryNodes.size(); boundaryNodeIndex++)
    {
      shared_ptr<const Node> boundaryNode(boundaryNodes.at(boundaryNodeIndex));
      for (unsigned int adjacentNodeIndex = 0; adjacentNodeIndex < boundaryNode->getChildren().size(); adjacentNodeIndex++)
      {
        shared_ptr<const Node> adjacentNode(boundaryNode->getChildren().at(adjacentNodeIndex));
        if (adjacentNode.get() == &finish)
        {
          markAsTraversed(*adjacentNode);
          return (true);
        }

        if (!isTraversed(*adjacentNode))
        {
          markAsTraversed(*adjacentNode);
          newBoundaryNodes.push_back(adjacentNode->getThisShared());
        }
      }
    }

    boundaryNodes = newBoundaryNodes;

    return (false);
  }
}
