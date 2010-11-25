/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleTraversal.h"

namespace simplicity
{
    SimpleTraversal::SimpleTraversal(Node* const root) :
        fBacktracksToNextNode(0), fNextNode(0), fRoot(root)
    {
        reset();
    }

    SimpleTraversal::~SimpleTraversal()
    {
    }

    Node*
    SimpleTraversal::findNextNode()
    {
        fBacktracksToNextNode = 0;

        // If the only node in the traversal is the root, end the traversal.
        if (fNextNode == fRoot && !fNextNode->hasChildren())
        {
            fBacktracksToNextNode++;

            return (NULL);
        }

        // If the current node has children, move to it's first child.
        if (fNextNode->hasChildren())
        {
            return (fNextNode->getChildren()->at(0));
        }

        // If the current node has no children, backtrack to the next sibling.
        vector<Node*>* siblings = fNextNode->getParent()->getChildren();

        // While the current node has no more siblings, move to it's parent.
        while (fNextNode == siblings->back())
        {
            fBacktracksToNextNode++;

            fNextNode = fNextNode->getParent();

            // If the next node is the root, end the traversal.
            if (fNextNode == fRoot)
            {
                fBacktracksToNextNode++;

                return (NULL);
            }

            siblings = fNextNode->getParent()->getChildren();
        }

        // If the next node has more siblings, move to it's next sibling.
        fBacktracksToNextNode++;

        return (fNextNode + 1);
    }

    int
    SimpleTraversal::getBacktracksToNextNode()
    {
        return (fBacktracksToNextNode);
    }

    Node*
    SimpleTraversal::getNextNode()
    {
        // If the traversal has ended.
        if (!fNextNode)
        {
            return (NULL);
        }

        Node* currentNode = fNextNode;
        fNextNode = findNextNode();

        return (currentNode);
    }

    bool
    SimpleTraversal::hasMoreNodes()
    {
        return (fNextNode);
    }

    void
    SimpleTraversal::reset()
    {
        fBacktracksToNextNode = 0;
        fNextNode = fRoot;
    }
}
