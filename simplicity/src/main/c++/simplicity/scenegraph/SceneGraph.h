/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_

#include <vector>

#include "Node.h"

namespace simplicity
{
  /**
   * <p>
   * A tree type graph of {@link simplicity::Node Node}s that represents a scene in a virtual universe. The <code>SceneGraph</code>
   * manages all the components within it. Methods of the <code>SceneGraph</code> should be called instead of calling methods on its components
   * directly. This ensures that the management of those components is not undermined.
   * </p>
   *
   * @author Gary Buyn
   */
  class SceneGraph
  {
    public:
      /**
       * <p>
       * Disposes of an instance of <code>SceneGraph</code> (included to allow polymorphic deletion).
       * </p>
       */
      virtual
      ~SceneGraph()
      {
      }

      /**
       * <p>
       * Adds a subgraph to the <code>SceneGraph</code>. The subgraph must be a tree type graph. The <code>SceneGraph</code> will determine where to add
       * the subgraph depending on the internal structure it maintains.
       * </p>
       *
       * <p>
       * This method should be called instead of retrieving the root {@link simplicity::Node Node} of the <code>SceneGraph</code> and
       * manually adding a subgraph to maintain the integrity of the <code>SceneGraph</code>.
       * </p>
       *
       * @param subgraphRoot The root <code>Node</code> of the subgraph to add.
       */
      virtual void
      addSubgraph(boost::shared_ptr<Node> subgraphRoot) = 0;

      /**
       * <p>
       * Adds a subgraph to the <code>SceneGraph</code>. The subgraph must be a tree type graph.
       * </p>
       *
       * <p>
       * This method should be called instead of retrieving the root {@link simplicity::Node Node} of the <code>SceneGraph</code> and
       * manually adding a subgraph to maintain the integrity of the <code>SceneGraph</code>.
       * </p>
       *
       * @param subgraphRoot The root <code>Node</code> of the subgraph to add.
       * @param parent The <code>Node</code> within the <code>SceneGraph</code> to add the subgraph under.
       */
      virtual void
      addSubgraph(boost::shared_ptr<Node> subgraphRoot, Node& parent) = 0;

      /**
       * <p>
       * Retrieves the {@link simplicity.scenegraph.Node Node} with the given ID.
       * </p>
       *
       * @param id The ID of the <code>Node</code> to retrieve.
       *
       * @return The <code>Node</code> with the given ID.
       */
      virtual boost::shared_ptr<Node>
      getNode(const int id) const = 0;

      /**
       * Retrieves the root {@link simplicity::Node Node} of this <code>SceneGraph</code>.
       *
       * @return The root <code>Node</code> of this <code>SceneGraph</code>.
       */
      virtual boost::shared_ptr<Node>
      getRoot() const = 0;

      /**
       * <p>
       * Retrieves the root {@link simplicity::Node Node}s off all the subgraphs in this <code>SceneGraph</code>.
       * </p>
       *
       * @return The root <code>Node</code>s off all the subgraphs in this <code>SceneGraph</code>.
       */
      virtual std::vector<boost::shared_ptr<Node> >
      getSubgraphRoots() const = 0;

      /**
       * <p>
       * Removes a subgraph from the <code>SceneGraph</code>.
       * </p>
       *
       * <p>
       * This method should be called instead of retrieving the root {@link simplicity::Node Node} of the subgraph and manually
       * removing it from its parent to maintain the integrity of the <code>SceneGraph</code>.
       * </p>
       *
       * @param subgraphRoot The root <code>Node</code> of the subgraph to remove.
       */
      virtual void
      removeSubgraph(Node& subgraphRoot) = 0;

      /**
       * <p>
       * Resets the IDs of all the {@link simplicity::Node Node}s in this <code>SceneGraph</code>.
       * </p>
       */
      virtual void
      resetIDs() = 0;
  };
}

#endif /* SCENEGRAPH_H_ */
