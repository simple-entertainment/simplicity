/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCKSCENEGRAPH_H_
#define MOCKSCENEGRAPH_H_

#include <gmock/gmock.h>

#include <simplicity/scenegraph/SceneGraph.h>

namespace simplicity
{
  /**
   * <p>
   * A mock implementation of {@link simplicity::SceneGraph SceneGraph}.
   * </p>
   *
   * @author Gary Buyn
   */
  class MockSceneGraph : public SceneGraph
  {
    public:
      MOCK_METHOD1(addSubgraph, void(boost::shared_ptr<Node> subgraphRoot));
      MOCK_METHOD2(addSubgraph, void(boost::shared_ptr<Node> subgraphRoot, Node& parent));
      MOCK_CONST_METHOD1(getNode, boost::shared_ptr<Node>(const int id));
      MOCK_CONST_METHOD0(getRoot, boost::shared_ptr<Node>());
      MOCK_CONST_METHOD0(getSubgraphRoots, std::vector<boost::shared_ptr<Node> >());
      MOCK_METHOD1(removeSubgraph, void(Node& subgraphRoot));
      MOCK_METHOD0(resetIDs, void());
  };
}

#endif /* MOCKSCENEGRAPH_H_ */
