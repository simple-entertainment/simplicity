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
#include <simplicity/scene/SimpleNode.h>

#include "../testdoubles/NodeHierarchy.h"
#include "BreadthFirstNodeIteratorTest.h"

using namespace boost;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test a full iteration of a simple acyclic graph of {@link simplicity::SimpleNode SimpleNode}s.
	 * </p>
	 */
	TEST_F(BreadthFirstNodeIteratorTest, iterationFull)
	{
		NodeHierarchy nodes;
		nodes.setStandardNodeHierarchy();

		BreadthFirstNodeIterator objectUnderTest(*nodes.node1);
		shared_ptr<Node> nextNode;

		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node1, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node2, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node4, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node7, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node3, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node5, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node6, nextNode);
		ASSERT_FALSE(objectUnderTest.hasMoreNodes());

		ASSERT_FALSE(objectUnderTest.getNextNode());
	}

	/**
	 * <p>
	 * Unit test a reset part way through an iteration of an acyclic graph of
	 * {@link simplicity::SimpleNode SimpleNode}s.
	 * </p>
	 */
	TEST_F(BreadthFirstNodeIteratorTest, iterationReset)
	{
		NodeHierarchy nodes;
		nodes.setBasicNodeHierarchy();

		BreadthFirstNodeIterator objectUnderTest(*nodes.node1);
		shared_ptr<Node> nextNode;

		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node1, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node2, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		objectUnderTest.reset();

		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node1, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node2, nextNode);
		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(nodes.node3, nextNode);
		ASSERT_FALSE(objectUnderTest.hasMoreNodes());

		ASSERT_FALSE(objectUnderTest.getNextNode());
	}

	/**
	 * <p>
	 * Unit test an iteration of an acyclic graph with only one {@link simplicity::SimpleNode SimpleNode}.
	 * </p>
	 */
	TEST_F(BreadthFirstNodeIteratorTest, iterationRootOnly)
	{
		shared_ptr<Node> node1(new SimpleNode);
		BreadthFirstNodeIterator objectUnderTest(*node1);
		shared_ptr<Node> nextNode;

		ASSERT_TRUE(objectUnderTest.hasMoreNodes());

		nextNode = objectUnderTest.getNextNode();

		ASSERT_EQ(node1, nextNode);
		ASSERT_FALSE(objectUnderTest.hasMoreNodes());

		ASSERT_FALSE(objectUnderTest.getNextNode());
	}
}
