/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef VECTORVG_H_
#define VECTORVG_H_

#include <vector>

#include "../math/TranslationVector.h"
#include "VertexGroup.h"

namespace simplicity
{
  /**
   * <p>
   * A {@link simplicity::VertexGroup VertexGroup} that contains its vertices in vectors.
   * </p>
   *
   * <p>
   * Three separate vectors are used to store the information for the vertices. One for the coordinates, one for the colours and one for the surface
   * normals.
   * </p>
   *
   * <p>
   * Each vertex is stored as three consecutive values in each vector as follows:
   * </p>
   *
   * <pre>
   * coordinates = {x1, y1, z1, x2, y2, z2, x3, y3, z3,..}
   * colours = {r1, g1, b1, r2, g2, b2, r3, g3, b3,..}
   * surface normals = {x1, y1, z1, x2, y2, z2, x3, y3, z3,..}
   * </pre>
   *
   * <p>
   * For all the vectors the numbers show which vertex the value relates to. For coordinates, the letters x, y and z show which axis the value relates
   * to. For colours the letters r, g and b show which component of the RGB colour model the value relates to. For surface normals the letters x, y and
   * z show which axis the value relates to.
   * </p>
   *
   * @author Gary Buyn
   */
  class VectorVG : public VertexGroup
  {
    public:
      /**
       * <p>
       * Creates an instance of <code>VectorVG</code>.
       * </p>
       */
      VectorVG();

      /**
       * <p>
       * Disposes of an instance of <code>VectorVG</code>.
       * </p>
       */
      virtual
      ~VectorVG();

      std::shared_ptr<VertexGroup>
      createEdgeSubsetVG(const int index);

      std::shared_ptr<VertexGroup>
      createFaceSubsetVG(const int index);

      std::shared_ptr<VertexGroup>
      createSubsetVG(const int index, const int length);

      std::shared_ptr<VertexGroup>
      createVertexSubsetVG(const int index);

      const TranslationVector<>&
      getCenter() const;

      /**
       * <p>
       * Retrieves the colours of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * @return The colours of all the vertices in this <code>VectorVG</code>.
       */
      std::vector<float>&
      getColours();

      /**
       * <p>
       * Retrieves the colours of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * @return The colours of all the vertices in this <code>VectorVG</code>.
       */
      const std::vector<float>&
      getColours() const;

      int
      getIndexWithinParent() const;

      /**
       * <p>
       * Retrieves the surface normals of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * @return The surface normals of all the vertices in this <code>VectorVG</code>.
       */
      std::vector<float>&
      getNormals();

      /**
       * <p>
       * Retrieves the surface normals of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * @return The surface normals of all the vertices in this <code>VectorVG</code>.
       */
      const std::vector<float>&
      getNormals() const;

      VertexGroup*
      getParent() const;

      int
      getVertexCount() const;

      /**
       * <p>
       * Retrieves the coordinates of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * @return The coordinates of all the vertices in this <code>VectorVG</code>.
       */
      std::vector<float>&
      getVertices();

      /**
       * <p>
       * Retrieves the coordinates of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * @return The coordinates of all the vertices in this <code>VectorVG</code>.
       */
      const std::vector<float>&
      getVertices() const;

      bool
      isSubset() const;

      void
      mergeWithParent() const;

      /**
       * <p>
       * Sets the colours of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * <p>
       * This <code>VectorVG</code> will assume ownership of the given vector and the previously held vector will be deleted.
       * </p>
       *
       * @param colours The colours of all the vertices in this <code>VectorVG</code>.
       */
      void
      setColours(std::shared_ptr<std::vector<float> > colours);

      void
      setIndexWithinParent(const int indexWithinParent);

      /**
       * <p>
       * Sets the surface normals of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * <p>
       * This <code>VectorVG</code> will assume ownership of the given vector and the previously held vector will be deleted.
       * </p>
       *
       * @param normals The surface normals of all the vertices in this <code>VectorVG</code>.
       */
      void
      setNormals(std::shared_ptr<std::vector<float> > normals);

      /**
       * <p>
       * Sets the coordinates of all the vertices in this <code>VectorVG</code>.
       * </p>
       *
       * <p>
       * This <code>VectorVG</code> will assume ownership of the given vector and the previously held vector will be deleted.
       * </p>
       *
       * @param vertices The coordinates of all the vertices in this <code>VectorVG</code>.
       */
      void
      setVertices(std::shared_ptr<std::vector<float> > vertices);

    private:
      /**
       * <p>
       * Creates an instance of <code>VectorVG</code>. This constructor should only be used when creating subset <code>VectorVG</code> s.
       * </p>
       *
       * @param parent The parent of this <code>VectorVG</code>.
       */
      VectorVG(VectorVG& parent);

      /**
       * <p>
       * The colours of all the vertices in this <code>VectorVG</code>.
       * </p>
       */
      std::shared_ptr<std::vector<float> > fColours;

      /**
       * <p>
       * The index in the parent <code>VectorVG</code> from which the data in this <code>VectorVG</code> was copied.
       * </p>
       */
      int fIndexWithinParent;

      /**
       * <p>
       * The subset status. Determines if this <code>VectorVG</code> is a subgroup of a parent <code>VectorVG</code>. Subset <code>ArrayVG</code>s contain
       * a copy of a subset of the parent <code>VectorVG</code>s data.
       * </p>
       */
      bool fIsSubset;

      /**
       * <p>
       * The surface normals of all the vertices in this <code>VectorVG</code>.
       * </p>
       */
      std::shared_ptr<std::vector<float> > fNormals;

      /**
       * <p>
       * The parent of this <code>VectorVG</code>. The parent should be set to <code>null</code> unless this <code>VectorVG</code> is a subset.
       * </p>
       */
      VectorVG* const fParent;

      /**
       * <p>
       * The coordinates of all the vertices in this <code>VectorVG</code>.
       * </p>
       */
      std::shared_ptr<std::vector<float> > fVertices;
  };
}

#endif /* VECTORVG_H_ */
