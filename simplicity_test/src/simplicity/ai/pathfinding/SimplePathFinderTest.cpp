/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <algorithm>

#include "SimplePathFinderTest.h"

using namespace boost;
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
    vector<shared_ptr<const Node> > path = objectUnderTest.findShortestPath();

    // Verify test results.
    ASSERT_EQ(5, path.size());

    // Verify that all nodes in the path are connected correctly.
    for (unsigned int index = 0; index < path.size(); index++)
    {
      const vector<shared_ptr<Node> >& children = path.at(index)->getChildren();

      if (index > 0)
      {
        ASSERT_TRUE(find(children.begin(), children.end(), path.at(index - 1)) != children.end());
      }
      if (index < path.size() - 1)
      {
        ASSERT_TRUE(find(children.begin(), children.end(), path.at(index + 1)) != children.end());
      }
    }
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimplePathFinder#findShortestPath() findShortestPath()} with the special case that obstacles require the
   * path to go around them.
   * </p>
   */
  TEST_F(SimplePathFinderTest, findShortestPathObstacles)
  {
    // Initialise test environment.
    SimplePathFinder objectUnderTest(*pathNodes.at(2), *pathNodes.at(22));

    // Create 'obstacles' by removing path nodes.
    for (unsigned int nodeIndex = 10; nodeIndex < 14; nodeIndex++)
    {
      shared_ptr<Node> pathNode = pathNodes.at(nodeIndex);
      for (unsigned int childIndex = 0; childIndex < pathNode->getChildren().size(); childIndex++)
      {
        pathNode->getChildren().at(childIndex)->removeChild(*pathNode);
      }
    }

    // Perform test.
    vector<shared_ptr<const Node> > path = objectUnderTest.findShortestPath();

    // Verify test results.
    ASSERT_EQ(9, path.size());

    // Verify that all nodes in the path are connected correctly.
    for (unsigned int index = 0; index < path.size(); index++)
    {
      const vector<shared_ptr<Node> >& children = path.at(index)->getChildren();

      if (index > 0)
      {
        ASSERT_TRUE(find(children.begin(), children.end(), path.at(index - 1)) != children.end());
      }
      if (index < path.size() - 1)
      {
        ASSERT_TRUE(find(children.begin(), children.end(), path.at(index + 1)) != children.end());
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
   * Unit test the method {@link simplicity::SimplePathFinder#getBoundaryNodes() getBoundaryNodes()}.
   * </p>
   */
  TEST_F(SimplePathFinderTest, getBoundaryNodes)
  {
    // Initialise test environment.
    SimplePathFinder objectUnderTest(*pathNodes.at(2), *pathNodes.at(22));
    objectUnderTest.stepForward();

    // Perform test.
    vector<shared_ptr<const Node> > boundaryNodes = objectUnderTest.getBoundaryNodes();

    // Verify test results.
    ASSERT_EQ(3, boundaryNodes.size());
    ASSERT_TRUE(find(boundaryNodes.begin(), boundaryNodes.end(), pathNodes.at(1)) != boundaryNodes.end());
    ASSERT_TRUE(find(boundaryNodes.begin(), boundaryNodes.end(), pathNodes.at(3)) != boundaryNodes.end());
    ASSERT_TRUE(find(boundaryNodes.begin(), boundaryNodes.end(), pathNodes.at(7)) != boundaryNodes.end());
  }
}
