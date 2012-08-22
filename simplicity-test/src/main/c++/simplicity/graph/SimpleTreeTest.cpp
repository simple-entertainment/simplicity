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
#include <simplicity/graph/SimpleTreeNode.h>

#include "../graph/MockTreeNode.h"
#include "SimpleTreeTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTree#add(shared_ptr<NodeType>) add(shared_ptr<NodeType>)}.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, add)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockTreeNode> root(new NiceMock<MockTreeNode>);
		shared_ptr<MockTreeNode> mockNode(new NiceMock<MockTreeNode>);
		TreeNode* nodePtr = mockNode.get();

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockNode, setId(1));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		SimpleTree<TreeNode> objectUnderTest(root);

		// Perform test.
		// //////////////////////////////////////////////////
		TreeNode& nodeRef = objectUnderTest.add(move(mockNode));

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(nodePtr, &nodeRef);
		ASSERT_EQ(2u, objectUnderTest.getAll().size());
		ASSERT_EQ(nodePtr, objectUnderTest.getAll().at(1).get());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTree#connect(NodeType&, NodeType&) connect(NodeType&, NodeType&)}.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, connect)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockTreeNode> root(new NiceMock<MockTreeNode>);
		shared_ptr<MockTreeNode> mockNode(new NiceMock<MockTreeNode>);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode, getParent()).WillByDefault(ReturnNull());

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*mockNode, connectTo(Ref(*root)));
		EXPECT_CALL(*root, addChild(Ref(*mockNode)));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		SimpleTree<TreeNode> objectUnderTest(root);
		TreeNode& nodeRef = objectUnderTest.add(move(mockNode));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.connect(objectUnderTest.getRoot(), nodeRef);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTree#connect(NodeType&, NodeType&) connect(NodeType&, NodeType&)}
	 * with the special case that the child is already connected to a different parent.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, connectToDifferentParent)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockTreeNode> root(new NiceMock<MockTreeNode>);
		NiceMock<MockTreeNode> mockNode1;
		shared_ptr<MockTreeNode> mockNode2(new NiceMock<MockTreeNode>);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode2, getParent()).WillByDefault(Return(root.get()));

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*root, removeChild(Ref(*mockNode2)));
		EXPECT_CALL(*mockNode2, disconnectFrom(Ref(*root)));
		EXPECT_CALL(mockNode1, addChild(Ref(*mockNode2)));
		EXPECT_CALL(*mockNode2, connectTo(Ref(mockNode1)));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		SimpleTree<TreeNode> objectUnderTest(root);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.connect(mockNode1, *mockNode2);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTree#SimpleTree() SimpleTree()}.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, constructor)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockTreeNode> root(new NiceMock<MockTreeNode>);
		TreeNode* rootPtr = root.get();

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(*root, setId(0));

		// Perform test.
		// //////////////////////////////////////////////////
		SimpleTree<TreeNode> objectUnderTest(root);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(rootPtr, &objectUnderTest.getRoot());
		ASSERT_EQ(1u, objectUnderTest.getAll().size());
		ASSERT_EQ(rootPtr, objectUnderTest.getAll().at(0).get());
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleTree#disconnect(NodeType&, NodeType&) disconnect(NodeType&, NodeType&)}.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, disconnect)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockTreeNode> root(new NiceMock<MockTreeNode>);
		shared_ptr<MockTreeNode> mockNode(new NiceMock<MockTreeNode>);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode, getParent()).WillByDefault(ReturnNull());

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		SimpleTree<TreeNode> objectUnderTest(root);
		TreeNode& nodeRef = objectUnderTest.add(move(mockNode));
		objectUnderTest.connect(objectUnderTest.getRoot(), nodeRef);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		EXPECT_CALL(static_cast<MockTreeNode&>(objectUnderTest.getRoot()), removeChild(Ref(nodeRef)));
		EXPECT_CALL(static_cast<MockTreeNode&>(nodeRef), disconnectFrom(Ref(objectUnderTest.getRoot())));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.disconnect(objectUnderTest.getRoot(), nodeRef);
	}

	/**
	 * <p>
	 * Unit test the methods {@link simplicity::SimpleTree#exists(NodeType&) exists(NodeType&)} and
	 * {@link simplicity::SimpleTree#exists(int) exists(int)}.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, exists)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<TreeNode> node1(new SimpleTreeNode);
		shared_ptr<TreeNode> node2(new SimpleTreeNode);

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		SimpleTree<TreeNode> objectUnderTest(node1);

		// Perform test - Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(objectUnderTest.exists(0));
		ASSERT_FALSE(objectUnderTest.exists(1));
		ASSERT_TRUE(objectUnderTest.exists(*node1));
		ASSERT_FALSE(objectUnderTest.exists(*node2));
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTree#get(int) get(int)}.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, get)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockTreeNode> root(new NiceMock<MockTreeNode>);
		TreeNode* rootPtr = root.get();

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*root, getId()).WillByDefault(Return(0));
		SimpleTree<TreeNode> objectUnderTest(root);

		// Perform test.
		// //////////////////////////////////////////////////
		TreeNode& rootRef = objectUnderTest.get(0);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(rootPtr, &rootRef);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTree#get(int) get(int)} with the special case that the node to be
	 * retrieved does not exist.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, getInvalidNode)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockTreeNode> root(new NiceMock<MockTreeNode>);

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*root, getId()).WillByDefault(Return(0));
		SimpleTree<TreeNode> objectUnderTest(root);

		// Perform test - Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_THROW(objectUnderTest.get(1), NodeDoesNotExistException);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTree#remove(NodeType&) remove(NodeType&)}.
	 * </p>
	 */
	TEST_F(SimpleTreeTest, remove)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<MockTreeNode> root(new NiceMock<MockTreeNode>);
		shared_ptr<MockTreeNode> mockNode(new NiceMock<MockTreeNode>);
		vector<reference_wrapper<TreeNode> > children;

		// Dictate expected behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode, getChildren()).WillByDefault(ReturnRef(children));
		ON_CALL(*mockNode, getParent()).WillByDefault(Return(root.get()));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		SimpleTree<TreeNode> objectUnderTest(root);
		TreeNode& nodeRef = objectUnderTest.add(move(mockNode));

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.remove(nodeRef);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(1u, objectUnderTest.getAll().size());
	}
}
