/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef VERTEXGROUP_H_
#define VERTEXGROUP_H_

#include "../SEInvalidOperationException.h"
#include "Model.h"

namespace simplicity
{
  /**
   * <p>
   * A {@link simplicity::Model Model} described by a set of vertices.
   * </p>
   *
   * @author Gary Buyn
   */
  class VertexGroup : public Model
  {
    public:
      /**
       * <p>
       * Creates a subset <code>VertexGroup</code> that contains only the edge at the given index within this <code>VertexGroup</code>.
       * </p>
       *
       * @param index The index of the edge to create a subset <code>VertexGroup</code> for.
       *
       * @return A subset <code>VertexGroup</code> that contains only the edge at the given index within this <code>VertexGroup</code>.
       */
      virtual std::shared_ptr<VertexGroup>
      createEdgeSubsetVG(const int index) = 0;

      /**
       * <p>
       * Creates a subset <code>VertexGroup</code> that contains only the face at the given index within this <code>VertexGroup</code>.
       * </p>
       *
       * @param index The index of the face to create a subset <code>VertexGroup</code> for.
       *
       * @return A subset <code>VertexGroup</code> that contains only the face at the given index within this <code>VertexGroup</code>.
       */
      virtual std::shared_ptr<VertexGroup>
      createFaceSubsetVG(const int index) = 0;

      /**
       * <p>
       * Creates a subset <code>VertexGroup</code> that contains the given length of consecutive vertices starting at the given index within this
       * <code>VertexGroup</code>.
       * </p>
       *
       * @param index The index of the first vertex to include in the subset <code>VertexGroup</code>.
       * @param length The number of consecutive vertices to include in the subset <code>VertexGroup</code>.
       *
       * @return A subset <code>VertexGroup</code> that contains the given length of consecutive vertices starting at the given index within this
       * <code>VertexGroup</code>.
       */
      virtual std::shared_ptr<VertexGroup>
      createSubsetVG(const int index, const int length) = 0;

      /**
       * <p>
       * Creates a subset <code>VertexGroup</code> that contains only the vertex at the given index within this <code>VertexGroup</code>.
       * </p>
       *
       * @param index The index of the vertex to create a subset <code>VertexGroup</code> for.
       *
       * @return A subset <code>VertexGroup</code> that contains only the vertex at the given index within this <code>VertexGroup</code>.
       */
      virtual std::shared_ptr<VertexGroup>
      createVertexSubsetVG(const int index) = 0;

      /**
       * <p>
       * Retrieves the index of the vertex in the parent <code>VertexGroup</code> from which the data in this <code>VertexGroup</code> was copied.
       * </p>
       *
       * @return The index of the vertex in the parent <code>VertexGroup</code> from which the data in this <code>VertexGroup</code> was copied.
       */
      virtual int
      getIndexWithinParent() const = 0;

      /**
       * <p>
       * Retrieves the parent of this <code>VertexGroup</code>. The parent should be set to <code>null</code> unless this <code>VertexGroup</code> is a
       * subset.
       * </p>
       *
       * @return The parent of this <code>VertexGroup</code>.
       */
      virtual VertexGroup*
      getParent() const = 0;

      /**
       * <p>
       * Retrieves number of vertices.
       * </p>
       *
       * @return The number of vertices.
       */
      virtual int
      getVertexCount() const = 0;

      /**
       * <p>
       * Determines if this <code>VertexGroup</code> is a subgroup of a parent <code>VertexGroup</code>.
       * </p>
       *
       * @return True if this <code>VertexGroup</code> is a subgroup of a parent <code>VertexGroup</code>, false otherwise.
       */
      virtual bool
      isSubset() const = 0;

      /**
       * <p>
       * Copies the changes made to this <code>VertexGroup</code> to it's parent <code>VertexGroup</code>.
       * </p>
       *
       * @throws SEInvalidOperationException If this Vertex Group is not a subset.
       */
      virtual void
      mergeWithParent() const = 0;

      /**
       * <p>
       * Sets the index of the vertex in the parent <code>VertexGroup</code> from which the data in this <code>VertexGroup</code> was copied.
       * </p>
       *
       * @param indexWithinParent The index of the vertex in the parent <code>VertexGroup</code> from which the data in this <code>VertexGroup</code>
       * was copied.
       */
      virtual void
      setIndexWithinParent(const int indexWithinParent) = 0;
  };
}

#endif /* VERTEXGROUP_H_ */
