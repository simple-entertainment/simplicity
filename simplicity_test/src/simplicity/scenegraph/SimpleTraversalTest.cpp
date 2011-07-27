/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/scenegraph/SimpleNode.h>

#include "../mocks/NodeHierarchy.h"
#include "SimpleTraversalTest.h"

using namespace boost;

namespace simplicity
{
  /**
   * <p>
   * Unit test a full traversal of a simple tree of {@link simplicity::SimpleNode SimpleNode}s.
   * </p>
   */
  TEST_F(SimpleTraversalTest, traversalFull)
  {
    NodeHierarchy nodes;
    nodes.setStandardNodeHierarchy();

    SimpleTraversal fTestObject(*nodes.node1);
    shared_ptr<Node> nextNode;

    ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
    ASSERT_TRUE(fTestObject.hasMoreNodes());

    nextNode = fTestObject.getNextNode();

    ASSERT_EQ(nodes.node1, nextNode);
    ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
    ASSERT_TRUE(fTestObject.hasMoreNodes());

    nextNode = fTestObject.getNextNode();

    ASSERT_EQ(nodes.node2, nextNode);
    ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
    ASSERT_TRUE(fTestObject.hasMoreNodes());

    nextNode = fTestObject.getNextNode();

    ASSERT_EQ(nodes.node3, nextNode);
    ASSERT_EQ(2, fTestObject.getBacktracksToNextNode());
    ASSERT_TRUE(fTestObject.hasMoreNodes());

    nextNode = fTestObject.getNextNode();

    ASSERT_EQ(nodes.node4, nextNode);
    ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
    ASSERT_TRUE(fTestObject.hasMoreNodes());

    nextNode = fTestObject.getNextNode();

    ASSERT_EQ(nodes.node5, nextNode);
    ASSERT_EQ(1, fTestObject.getBacktracksToNextNode());
    ASSERT_TRUE(fTestObject.hasMoreNodes());

    nextNode = fTestObject.getNextNode();

    ASSERT_EQ(nodes.node6, nextNode);
    ASSERT_EQ(2, fTestObject.getBacktracksToNextNode());
    ASSERT_TRUE(fTestObject.hasMoreNodes());

    nextNode = fTestObject.getNextNode();

    ASSERT_EQ(nodes.node7, nextNode);
    ASSERT_EQ(2, fTestObject.getBacktracksToNextNode());
    ASSERT_FALSE(fTestObject.hasMoreNodes());

    ASSERT_FALSE(fTestObject.getNextNode());
  }

    /**
   * <p>
   * Unit test a reset part way through a traversal of a simple tree of {@link simplicity::SimpleNode SimpleNode}s.
   * </p>
   */
  TEST_F(SimpleTraversalTest, traversalReset)
    {
      NodeHierarchy nodes;
      nodes.setBasicNodeHierarchy();

      SimpleTraversal fTestObject(*nodes.node1);
      shared_ptr<Node> nextNode;

      ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
      ASSERT_TRUE(fTestObject.hasMoreNodes());

      nextNode = fTestObject.getNextNode();

      ASSERT_EQ(nodes.node1, nextNode);
      ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
      ASSERT_TRUE(fTestObject.hasMoreNodes());

      nextNode = fTestObject.getNextNode();

      ASSERT_EQ(nodes.node2, nextNode);
      ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
      ASSERT_TRUE(fTestObject.hasMoreNodes());

      fTestObject.reset();

      ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
      ASSERT_TRUE(fTestObject.hasMoreNodes());

      nextNode = fTestObject.getNextNode();

      ASSERT_EQ(nodes.node1, nextNode);
      ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
      ASSERT_TRUE(fTestObject.hasMoreNodes());

      nextNode = fTestObject.getNextNode();

      ASSERT_EQ(nodes.node2, nextNode);
      ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
      ASSERT_TRUE(fTestObject.hasMoreNodes());

      nextNode = fTestObject.getNextNode();

      ASSERT_EQ(nodes.node3, nextNode);
      ASSERT_EQ(3, fTestObject.getBacktracksToNextNode());
      ASSERT_FALSE(fTestObject.hasMoreNodes());

      ASSERT_FALSE(fTestObject.getNextNode());
    }

  /**
   * <p>
   * Unit test a traversal of a tree with only one {@link simplicity::SimpleNode SimpleNode}.
   * </p>
   */
  TEST_F(SimpleTraversalTest, traversalRootOnly)
    {
      shared_ptr<Node> node1(new SimpleNode);
      SimpleTraversal fTestObject(*node1);
      shared_ptr<Node> nextNode;

      ASSERT_EQ(0, fTestObject.getBacktracksToNextNode());
      ASSERT_TRUE(fTestObject.hasMoreNodes());

      nextNode = fTestObject.getNextNode();

      ASSERT_EQ(node1, nextNode);
      ASSERT_EQ(1, fTestObject.getBacktracksToNextNode());
      ASSERT_FALSE(fTestObject.hasMoreNodes());

      ASSERT_FALSE(fTestObject.getNextNode());
    }
}
