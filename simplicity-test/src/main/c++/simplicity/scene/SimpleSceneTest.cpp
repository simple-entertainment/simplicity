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

#include "../testdoubles/NodeHierarchy.h"
#include "SimpleSceneTest.h"

using namespace boost;
using namespace std;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleScene#addNode(Node * const) addNode(Node * const)}.
	 * </p>
	 */
	TEST_F(SimpleSceneTest, addNode)
	{
		NodeHierarchy nodes;
		nodes.setStandardNodeHierarchy();

		objectUnderTest.addNode(nodes.node1);

		vector<shared_ptr<Node> > children(objectUnderTest.getRoot()->getChildren());
		vector<shared_ptr<Node> >::iterator iterator = find(children.begin(), children.end(), nodes.node1);
		ASSERT_TRUE(*iterator == nodes.node1);
		ASSERT_EQ(objectUnderTest.getRoot(), nodes.node1->getParent());

		ASSERT_EQ(1, nodes.node1->getId());
		ASSERT_EQ(objectUnderTest.getNode(1), nodes.node1);
		ASSERT_EQ(2, nodes.node2->getId());
		ASSERT_EQ(objectUnderTest.getNode(2), nodes.node2);
		ASSERT_EQ(3, nodes.node3->getId());
		ASSERT_EQ(objectUnderTest.getNode(3), nodes.node3);
		ASSERT_EQ(4, nodes.node4->getId());
		ASSERT_EQ(objectUnderTest.getNode(4), nodes.node4);
		ASSERT_EQ(5, nodes.node5->getId());
		ASSERT_EQ(objectUnderTest.getNode(5), nodes.node5);
		ASSERT_EQ(6, nodes.node6->getId());
		ASSERT_EQ(objectUnderTest.getNode(6), nodes.node6);
		ASSERT_EQ(7, nodes.node7->getId());
		ASSERT_EQ(objectUnderTest.getNode(7), nodes.node7);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleScene#removeNode() removeNode()}.
	 * </p>
	 */
	TEST_F(SimpleSceneTest, removeNode)
	{
		NodeHierarchy nodes;
		nodes.setStandardNodeHierarchy();

		objectUnderTest.addNode(nodes.node1);
		objectUnderTest.removeNode(*nodes.node4);

		vector<shared_ptr<Node> > children = objectUnderTest.getRoot()->getChildren();
		vector<shared_ptr<Node> >::iterator iterator = find(children.begin(), children.end(), nodes.node1);
		ASSERT_TRUE(*iterator == nodes.node1);
		ASSERT_EQ(objectUnderTest.getRoot(), nodes.node1->getParent());

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
	 * Unit test the method {@link simplicity::SimpleScene#resetIds() resetIds()}.
	 * </p>
	 */
	TEST_F(SimpleSceneTest, resetIds)
	{
		NodeHierarchy nodes;
		nodes.setStandardNodeHierarchy();

		objectUnderTest.addNode(nodes.node1);
		objectUnderTest.removeNode(*nodes.node4);

		objectUnderTest.resetIds();

		ASSERT_EQ(nodes.node1, objectUnderTest.getNode(1));
		ASSERT_EQ(nodes.node2, objectUnderTest.getNode(2));
		ASSERT_EQ(nodes.node3, objectUnderTest.getNode(3));
		ASSERT_EQ(nodes.node7, objectUnderTest.getNode(4));
	}
}
