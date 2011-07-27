/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <algorithm>

#include "../mocks/NodeHierarchy.h"
#include "SimpleSceneGraphTest.h"

using namespace boost;
using namespace simplicity;
using namespace std;

namespace simplicity
{
  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleSceneGraph#addSubgraph(Node * const) addSubgraph(Node * const)}.
   * </p>
   */
  TEST_F(SimpleSceneGraphTest, addSubgraph)
  {
    NodeHierarchy nodes;
    nodes.setStandardNodeHierarchy();

    fTestObject.addSubgraph(nodes.node1);

    vector<shared_ptr<Node> > children(fTestObject.getRoot()->getChildren());
    vector<shared_ptr<Node> >::iterator iterator = find(children.begin(), children.end(), nodes.node1);
    ASSERT_TRUE(*iterator == nodes.node1);
    ASSERT_EQ(fTestObject.getRoot(), nodes.node1->getParent());

    ASSERT_EQ(1, nodes.node1->getID());
    ASSERT_EQ(fTestObject.getNode(1), nodes.node1);
    ASSERT_EQ(2, nodes.node2->getID());
    ASSERT_EQ(fTestObject.getNode(2), nodes.node2);
    ASSERT_EQ(3, nodes.node3->getID());
    ASSERT_EQ(fTestObject.getNode(3), nodes.node3);
    ASSERT_EQ(4, nodes.node4->getID());
    ASSERT_EQ(fTestObject.getNode(4), nodes.node4);
    ASSERT_EQ(5, nodes.node5->getID());
    ASSERT_EQ(fTestObject.getNode(5), nodes.node5);
    ASSERT_EQ(6, nodes.node6->getID());
    ASSERT_EQ(fTestObject.getNode(6), nodes.node6);
    ASSERT_EQ(7, nodes.node7->getID());
    ASSERT_EQ(fTestObject.getNode(7), nodes.node7);
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleSceneGraph.removeSubgraph removeSubgraph()}.
   * </p>
   */
  TEST_F(SimpleSceneGraphTest, removeSubgraph)
    {
      NodeHierarchy nodes;
      nodes.setStandardNodeHierarchy();

      fTestObject.addSubgraph(nodes.node1);
      fTestObject.removeSubgraph(*nodes.node4);

      vector<shared_ptr<Node> > children = fTestObject.getRoot()->getChildren();
      vector<shared_ptr<Node> >::iterator iterator = find(children.begin(), children.end(), nodes.node1);
      ASSERT_TRUE(*iterator == nodes.node1);
      ASSERT_EQ(fTestObject.getRoot(), nodes.node1->getParent());

      children = nodes.node1->getChildren();
      iterator = find(children.begin(), children.end(), nodes.node2);
      ASSERT_TRUE(*iterator == nodes.node2);
      ASSERT_EQ(nodes.node1, nodes.node2->getParent());

      children = nodes.node1->getChildren();
      iterator = find(children.begin(), children.end(), nodes.node4);
      ASSERT_FALSE(*iterator == nodes.node4);
      ASSERT_FALSE(nodes.node4->getParent());

      children = nodes.node1->getChildren();
      iterator = find(children.begin(), children.end(), nodes.node7);
      ASSERT_TRUE(*iterator == nodes.node7);
      ASSERT_EQ(nodes.node1, nodes.node7->getParent());
    }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleSceneGraph#resetIDs() resetIDs()}.
   * </p>
   */
  TEST_F(SimpleSceneGraphTest, resetIDs)
    {
      NodeHierarchy nodes;
      nodes.setStandardNodeHierarchy();

      fTestObject.addSubgraph(nodes.node1);
      fTestObject.removeSubgraph(*nodes.node4);

      fTestObject.resetIDs();

      ASSERT_EQ(nodes.node1, fTestObject.getNode(1));
      ASSERT_EQ(nodes.node2, fTestObject.getNode(2));
      ASSERT_EQ(nodes.node3, fTestObject.getNode(3));
      ASSERT_EQ(nodes.node7, fTestObject.getNode(4));
    }
}
