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
#include <simplicity/graph/SimpleNode.h>
#include <simplicity/graph/UndirectedGraph.h>

#include "GraphFunctionsTest.h"
#include "MockNode.h"

using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::GraphFunctions::copy(const GraphType&) copy(const GraphType&)}.
	 * </p>
	 */
	TEST_F(GraphFunctionsTest, copy)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		UndirectedGraph<Node> original;
		shared_ptr<Node> node1(new SimpleNode);
		shared_ptr<Node> node2(new SimpleNode);
		shared_ptr<Node> node3(new SimpleNode);

		// Initialise test environment.
		// //////////////////////////////////////////////////
		original.add(node1);
		original.add(node2);
		original.add(node3);
		original.connect(*node1, *node2);
		original.connect(*node1, *node3);

		// Perform test.
		// //////////////////////////////////////////////////
		UndirectedGraph<Node> result = GraphFunctions::copy<UndirectedGraph<Node>, Node, SimpleNode>(original);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(3u, result.getAll().size());
		ASSERT_EQ(2u, result.getAll().at(0)->getConnectedNodes().size());
		ASSERT_EQ(result.getAll().at(1).get(), &result.getAll().at(0)->getConnectedNodes().at(0).get());
		ASSERT_EQ(result.getAll().at(2).get(), &result.getAll().at(0)->getConnectedNodes().at(1).get());
		ASSERT_EQ(1u, result.getAll().at(1)->getConnectedNodes().size());
		ASSERT_EQ(result.getAll().at(0).get(), &result.getAll().at(1)->getConnectedNodes().at(0).get());
		ASSERT_EQ(1u, result.getAll().at(2)->getConnectedNodes().size());
		ASSERT_EQ(result.getAll().at(0).get(), &result.getAll().at(2)->getConnectedNodes().at(0).get());
	}
}
