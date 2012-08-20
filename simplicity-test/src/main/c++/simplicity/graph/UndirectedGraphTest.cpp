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
#include <iostream>

#include <simplicity/graph/SimpleNode.h>

#include "../graph/MockNode.h"
#include "UndirectedGraphTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::UndirectedGraph#add(shared_ptr<NodeType>) add(shared_ptr<NodeType>)}.
	 * </p>
	 */
	TEST_F(UndirectedGraphTest, add)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockNode> mockNode(new NiceMock<MockNode>);
		Node* nodePtr = mockNode.get();

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockNode, setId(0));

		// Perform test.
		// //////////////////////////////////////////////////
		Node& nodeRef = objectUnderTest.add(move(mockNode));

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(nodePtr, &nodeRef);
		ASSERT_EQ(1u, objectUnderTest.getAll().size());
		ASSERT_EQ(nodePtr, objectUnderTest.getAll().at(0).get());
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::UndirectedGraph#connect(NodeType&, NodeType&) connect(NodeType&, NodeType&)}.
	 * </p>
	 */
	TEST_F(UndirectedGraphTest, connect)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockNode> mockNode1(new NiceMock<MockNode>);
		shared_ptr<MockNode> mockNode2(new NiceMock<MockNode>);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockNode1, connectTo(Ref(*mockNode2)));
		EXPECT_CALL(*mockNode2, connectTo(Ref(*mockNode1)));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		Node& node1Ref = objectUnderTest.add(move(mockNode1));
		Node& node2Ref = objectUnderTest.add(move(mockNode2));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.connect(node1Ref, node2Ref);
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::UndirectedGraph#disconnect(NodeType&, NodeType&) disconnect(NodeType&, NodeType&)}.
	 * </p>
	 */
	TEST_F(UndirectedGraphTest, disconnect)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockNode> mockNode1(new NiceMock<MockNode>);
		shared_ptr<MockNode> mockNode2(new NiceMock<MockNode>);

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		Node& node1Ref = objectUnderTest.add(move(mockNode1));
		Node& node2Ref = objectUnderTest.add(move(mockNode2));
		objectUnderTest.connect(node1Ref, node2Ref);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(static_cast<MockNode&>(node1Ref), disconnectFrom(Ref(node2Ref)));
		EXPECT_CALL(static_cast<MockNode&>(node2Ref), disconnectFrom(Ref(node1Ref)));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.disconnect(node1Ref, node2Ref);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::UndirectedGraph#get(int) get(int)}.
	 * </p>
	 */
	TEST_F(UndirectedGraphTest, get)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockNode> mockNode(new NiceMock<MockNode>);
		Node* nodePtr = mockNode.get();

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode, getId()).WillByDefault(Return(0));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		objectUnderTest.add(move(mockNode));

		// Perform test.
		// //////////////////////////////////////////////////
		Node& nodeRef = objectUnderTest.get(0);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(nodePtr, &nodeRef);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::UndirectedGraph#get(int) get(int)} with the special case that the node to
	 * be retrieved does not exist.
	 * </p>
	 */
	TEST_F(UndirectedGraphTest, getInvalidNode)
	{
		// Perform test - Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_THROW(objectUnderTest.get(0), NodeDoesNotExistException);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::UndirectedGraph#remove(NodeType&) remove(NodeType&)}.
	 * </p>
	 */
	TEST_F(UndirectedGraphTest, remove)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockNode> mockNode1(new NiceMock<MockNode>);
		shared_ptr<MockNode> mockNode2(new NiceMock<MockNode>);
		vector<reference_wrapper<Node> > connectedNodes1;
		connectedNodes1.push_back(*mockNode2);
		vector<reference_wrapper<Node> > connectedNodes2;
		connectedNodes2.push_back(*mockNode1);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getConnectedNodes()).WillByDefault(Return(connectedNodes1));
		ON_CALL(*mockNode2, getConnectedNodes()).WillByDefault(Return(connectedNodes2));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		Node& node1Ref = objectUnderTest.add(move(mockNode1));
		Node& node2Ref = objectUnderTest.add(move(mockNode2));

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(static_cast<MockNode&>(node1Ref), disconnectFrom(Ref(node2Ref)));
		EXPECT_CALL(static_cast<MockNode&>(node2Ref), disconnectFrom(Ref(node1Ref)));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.remove(node1Ref);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(1u, objectUnderTest.getAll().size());
		ASSERT_EQ(&node2Ref, objectUnderTest.getAll().at(0).get());
	}
}
