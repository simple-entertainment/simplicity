/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleNode.h"
#include "SimpleSceneGraph.h"
#include "SimpleTraversal.h"

namespace simplicity
{
    SimpleSceneGraph::SimpleSceneGraph() :
        fLastNodeID(0), fNodes(new map<int, Node*> ()), fRoot(new SimpleNode())
    {
        fRoot->setID(getNextNodeID());
        fNodes->insert(pair<int, Node*>(fRoot->getID(), fRoot));
    }

    SimpleSceneGraph::~SimpleSceneGraph()
    {
        delete fNodes;
    }

    void
    SimpleSceneGraph::addSubgraph(Node* const subgraphRoot)
    {
        addSubgraph(subgraphRoot, fRoot);
    }

    void
    SimpleSceneGraph::addSubgraph(Node* const subgraphRoot, Node* const parent)
    {
        SimpleTraversal traversal(subgraphRoot);

        while (traversal.hasMoreNodes())
        {
            Node* node = traversal.getNextNode();

            node->setID(getNextNodeID());
            fNodes->insert(pair<int, Node*>(node->getID(), node));
        }

        parent->addChild(subgraphRoot);
    }

    int
    SimpleSceneGraph::getNextNodeID()
    {
        return (fLastNodeID++);
    }

    Node*
    SimpleSceneGraph::getNode(const int id)
    {
        return (fNodes->find(id)->second);
    }

    Node*
    SimpleSceneGraph::getRoot()
    {
        return (fRoot);
    }

    vector<Node*>*
    SimpleSceneGraph::getSubgraphRoots()
    {
        return fRoot->getChildren();
    }

    void
    SimpleSceneGraph::removeSubgraph(Node* const subgraphRoot)
    {
        SimpleTraversal traversal(subgraphRoot);

        while (traversal.hasMoreNodes())
        {
            fNodes->erase(traversal.getNextNode()->getID());
        }

        subgraphRoot->getParent()->removeChild(subgraphRoot);
    }

    void
    SimpleSceneGraph::resetIDs()
    {
        fLastNodeID = 0;
        fNodes->clear();

        SimpleTraversal traversal(fRoot);

        while (traversal.hasMoreNodes())
        {
            Node* node = traversal.getNextNode();

            node->setID(getNextNodeID());
            fNodes->insert(pair<int, Node*>(node->getID(), node));
        }
    }
}
