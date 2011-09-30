/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <algorithm>

#include "SimpleTraversal.h"

using namespace boost;
using namespace std;

namespace simplicity
{
  SimpleTraversal::SimpleTraversal(const Node& root) :
    fBacktracksToNextNode(0), fRoot(root)
  {
    reset();
  }

  SimpleTraversal::~SimpleTraversal()
  {
  }

  shared_ptr<Node>
  SimpleTraversal::findNextNode()
  {
    fBacktracksToNextNode = 0;

    // If the only node in the traversal is the root, end the traversal.
    if (fNextNode.get() == &fRoot && !fNextNode->hasChildren())
    {
      fBacktracksToNextNode++;

      return (shared_ptr<Node> ());
    }

    // If the current node has children, move to it's first child.
    if (fNextNode->hasChildren())
    {
      return (fNextNode->getChildren().at(0));
    }

    // If the current node has no children, backtrack to the next sibling.
    vector<shared_ptr<Node> > siblings = fNextNode->getParent()->getChildren();

    // While the current node has no more siblings, move to it's parent.
    fBacktracksToNextNode++;
    while (fNextNode == siblings.back())
    {
      fBacktracksToNextNode++;
      fNextNode = fNextNode->getParent();

      // If the next node is the root, end the traversal.
      if (fNextNode.get() == &fRoot)
      {
        return (shared_ptr<Node> ());
      }

      siblings = fNextNode->getParent()->getChildren();
    }

    // If the next node has more siblings, move to it's next sibling.
    vector<shared_ptr<Node> >::iterator iterator = find(siblings.begin(), siblings.end(), fNextNode);
    iterator++;

    return (*iterator);
  }

  int
  SimpleTraversal::getBacktracksToNextNode() const
  {
    return (fBacktracksToNextNode);
  }

  shared_ptr<Node>
  SimpleTraversal::getNextNode()
  {
    // If the traversal has ended.
    if (!fNextNode.get())
    {
      return (shared_ptr<Node> ());
    }

    shared_ptr<Node> currentNode(fNextNode);
    fNextNode = findNextNode();

    return (currentNode);
  }

  bool
  SimpleTraversal::hasMoreNodes() const
  {
    return (fNextNode);
  }

  void
  SimpleTraversal::reset()
  {
    fBacktracksToNextNode = 0;
    Node* rootNode = (Node*) &fRoot;
    fNextNode = rootNode->getThisShared();
  }
}
