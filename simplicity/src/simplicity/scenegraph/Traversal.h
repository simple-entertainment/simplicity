/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TRAVERSAL_H_
#define TRAVERSAL_H_

#include "Node.h"

namespace simplicity
{
  /**
   * <p>
   * Traverses a tree type graph of {@link simplicity::Node Node}s. The order in which the <code>Node</code>s are traversed is specific
   * to each implementation.
   * </p>
   *
   * @author Gary Buyn
   */
  class Traversal
  {
    public:
      /**
       * <p>
       * Disposes of an instance of <code>Traversal</code> (included to allow polymorphic deletion).
       * </p>
       */
      virtual
      ~Traversal()
      {
      }

      /**
       * <p>
       * Retrieves the next {@link com.se.simplicity.scenegraph.Node Node} in this traversal.
       * </p>
       *
       * @return The next <code>Node</code> in this traversal or <code>null</code> if there are no more <code>Node</code>s to be returned.
       */
      virtual Node *
      getNextNode() = 0;

      /**
       * <p>
       * Determines if there are more {@link com.se.simplicity.scenegraph.Node Node}s to be retrieved by this traversal.
       * </p>
       *
       * @return True if a <code>Node</code> will be retrieved by the next call to <code>getNextNode()</code>, false otherwise.
       */
      virtual bool
      hasMoreNodes() const = 0;

      /**
       * <p>
       * Resets this traversal so that the next {@link com.se.simplicity.scenegraph.Node Node} retrieved is the root <code>Node</code> of the graph.
       * </p>
       */
      virtual void
      reset() = 0;
  };
}

#endif /* TRAVERSAL_H_ */
