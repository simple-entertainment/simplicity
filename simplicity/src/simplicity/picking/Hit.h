/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HIT_H_
#define HIT_H_

#include "../model/Model.h"
#include "../scenegraph/Node.h"

namespace simplicity
{
  /**
   * <p>
   * A hit made as a result of a pick.
   * </p>
   *
   * @author Gary Buyn
   */
  class Hit
  {
    public:
      /**
       * <p>
       * Creates an instance of <code>Hit</code>.
       * </p>
       */
      Hit();

      /**
       * <p>
       * Disposes of an instance of <code>Hit</code>.
       * </p>
       */
      virtual
      ~Hit();

      /**
       * <p>
       * Retrieves the maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
       * {@link com.se.simplicity.rendering.Camera Camera}.
       * </p>
       *
       * @return The maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
       * {@link com.se.simplicity.rendering.Camera Camera}.
       */
      int
      getMaximumDistance() const;

      /**
       * <p>
       * Retrieves the minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
       * {@link com.se.simplicity.rendering.Camera Camera}.
       * </p>
       *
       * @return The minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
       * {@link com.se.simplicity.rendering.Camera Camera}.
       */
      int
      getMinimumDistance() const;

      /**
       * <p>
       * Retrieves the {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
       * </p>
       *
       * @return The {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
       */
      Node *
      getNode() const;

      /**
       * <p>
       * Retrieves the primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive stored in
       * this value is undefined.
       * </p>
       *
       * @return The primitive that intersected the pick.
       */
      Model *
      getPrimitive() const;

      /**
       * <p>
       * Sets the maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
       * {@link com.se.simplicity.rendering.Camera Camera}.
       * </p>
       *
       * @param maximumDistance The maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
       * {@link com.se.simplicity.rendering.Camera Camera}.
       */
      void
      setMaximumDistance(int const maximumDistance);

      /**
       * <p>
       * Sets the minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
       * {@link com.se.simplicity.rendering.Camera Camera}.
       * </p>
       *
       * @param minimumDistance The minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
       * {@link com.se.simplicity.rendering.Camera Camera}.
       */
      void
      setMinimumDistance(int const minimumDistance);

      /**
       * <p>
       * Sets the {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
       * </p>
       *
       * @param node The {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
       */
      void
      setNode(Node * const node);

      /**
       * <p>
       * Sets the primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive stored in this
       * value is undefined.
       * </p>
       *
       * @param primitive The primitive that intersected the pick.
       */
      void
      setPrimitive(Model * const primitive);

    private:
      /**
       * <p>
       * The maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the {@link com.se.simplicity.rendering.Camera
       * Camera}.
       * </p>
       */
      int fMaximumDistance;

      /**
       * <p>
       * The minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the {@link com.se.simplicity.rendering.Camera
       * Camera}.
       * </p>
       */
      int fMinimumDistance;

      /**
       * <p>
       * The {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
       * </p>
       */
      Node * fNode;

      /**
       * <p>
       * The primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive stored in this
       * value is undefined.
       * </p>
       */
      Model * fPrimitive;
  };
}

#endif /* HIT_H_ */
