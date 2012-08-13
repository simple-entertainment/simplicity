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

#include <simplicity/common/AddressEquals.h>

#include "SimplePathFinderTest.h"

using namespace std;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimplePathFinder#findShortestPath() findShortestPath()}.
	 * </p>
	 */
	TEST_F(SimplePathFinderTest, findShortestPath)
	{
		// Initialise test environment.
		SimplePathFinder objectUnderTest(*pathNodes.at(2), *pathNodes.at(22));

		// Perform test.
		vector<reference_wrapper<const Node> > path = objectUnderTest.findShortestPath();

		// Verify test results.
		ASSERT_EQ(5u, path.size());

		// Verify that all nodes in the path are connected correctly.
		for (unsigned int index = 0; index < path.size(); index++)
		{
			const vector<shared_ptr<Node> >& children = path.at(index).get().getChildren();

			if (index > 0)
			{
				ASSERT_TRUE(
					find_if(children.begin(), children.end(), AddressEquals<Node>(path.at(index - 1).get())) != children.end());
			}
			if (index < path.size() - 1)
			{
				ASSERT_TRUE(
					find_if(children.begin(), children.end(), AddressEquals<Node>(path.at(index + 1).get())) != children.end());
			}
		}
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimplePathFinder#findShortestPath() findShortestPath()} with the special
	 * case that obstacles require the path to go around them.
	 * </p>
	 */
	TEST_F(SimplePathFinderTest, findShortestPathObstacles)
	{
		// Initialise test environment.
		SimplePathFinder objectUnderTest(*pathNodes.at(2), *pathNodes.at(22));

		// Create 'obstacles' by removing path nodes.
		for (unsigned int nodeIndex = 10; nodeIndex < 14; nodeIndex++)
		{
			Node& pathNode = *pathNodes.at(nodeIndex);
			for (shared_ptr<Node> child : pathNode.getChildren())
			{
				child->removeChild(pathNode);
			}
		}

		// Perform test.
		vector<reference_wrapper<const Node> > path = objectUnderTest.findShortestPath();

		// Verify test results.
		ASSERT_EQ(9u, path.size());

		// Verify that all nodes in the path are connected correctly.
		for (unsigned int index = 0; index < path.size(); index++)
		{
			const vector<shared_ptr<Node> >& children = path.at(index).get().getChildren();

			if (index > 0)
			{
				ASSERT_TRUE(
					find_if(children.begin(), children.end(), AddressEquals<Node>(path.at(index - 1).get())) != children.end());
			}
			if (index < path.size() - 1)
			{
				ASSERT_TRUE(
					find_if(children.begin(), children.end(), AddressEquals<Node>(path.at(index + 1).get())) != children.end());
			}
		}
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimplePathFinder#stepForward() stepForward()}.
	 * </p>
	 */
	TEST_F(SimplePathFinderTest, stepForward)
	{
		// Initialise test environment.
		SimplePathFinder objectUnderTest(*pathNodes.at(2), *pathNodes.at(22));

		// Perform test - Verify test results.
		ASSERT_FALSE(objectUnderTest.stepForward());
		ASSERT_FALSE(objectUnderTest.stepForward());
		ASSERT_FALSE(objectUnderTest.stepForward());
		ASSERT_TRUE(objectUnderTest.stepForward());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimplePathFinder#getOpenNodes() getOpenNodes()}.
	 * </p>
	 */
	TEST_F(SimplePathFinderTest, getOpenNodes)
	{
		// Initialise test environment.
		SimplePathFinder objectUnderTest(*pathNodes.at(2), *pathNodes.at(22));
		objectUnderTest.stepForward();

		// Perform test.
		vector<reference_wrapper<const Node> > openNodes = objectUnderTest.getOpenNodes();

		// Verify test results.
		ASSERT_EQ(3u, openNodes.size());
		ASSERT_TRUE(
			find_if(openNodes.begin(), openNodes.end(), AddressEquals<Node>(*pathNodes.at(1))) != openNodes.end());
		ASSERT_TRUE(
			find_if(openNodes.begin(), openNodes.end(), AddressEquals<Node>(*pathNodes.at(3))) != openNodes.end());
		ASSERT_TRUE(
			find_if(openNodes.begin(), openNodes.end(), AddressEquals<Node>(*pathNodes.at(7))) != openNodes.end());
	}
}
