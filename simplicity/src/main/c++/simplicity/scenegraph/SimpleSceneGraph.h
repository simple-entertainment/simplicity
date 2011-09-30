/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLESCENEGRAPH_H_
#define SIMPLESCENEGRAPH_H_

#include <map>

#include "SceneGraph.h"

namespace simplicity
{
  /**
   * <p>
   * This implementation uses only simple scene graph techniques and properties.
   * </p>
   *
   * @author Gary Buyn
   */
  class SimpleSceneGraph : public SceneGraph
  {
    public:
      SimpleSceneGraph();

      virtual
      ~SimpleSceneGraph();

      void
      addSubgraph(boost::shared_ptr<Node> subgraphRoot);

      void
      addSubgraph(boost::shared_ptr<Node> subgraphRoot, Node& parent);

      boost::shared_ptr<Node>
      getNode(const int id) const;

      boost::shared_ptr<Node>
      getRoot() const;

      std::vector<boost::shared_ptr<Node> >
      getSubgraphRoots() const;

      void
      removeSubgraph(Node& subgraphRoot);

      void
      resetIDs();

    private:
      /**
       * The unique identifier that was assigned to the last {@link com.se.simplicity.scenegraph.Node Node} added to the <code>SimpleSceneGraph</code>.
       */
      int fLastNodeID;

      /**
       * <p>
       * The {@link simplicity::Node Node}s within this <code>SimpleSceneGraph</code>.
       * </p>
       */
      std::map<int, boost::shared_ptr<Node> > fNodes;

      /**
       * <p>
       * The root {@link simplicity::Node Node} of this <code>SimpleSceneGraph</code>.
       * </p>
       */
      boost::shared_ptr<Node> fRoot;

      /**
       * <p>
       * Retrieves a unique identifier to assign to the next {@link com.se.simplicity.scenegraph.Node Node} added to the <code>SimpleSceneGraph</code>.
       * </p>
       *
       * @return A unique identifier to assign to the next <code>Node</code> added to the <code>SimpleSceneGraph</code>.
       */
      int
      getNextNodeID();
  };
}

#endif /* SIMPLESCENEGRAPH_H_ */
