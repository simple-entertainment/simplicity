/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLENODE_H_
#define SIMPLENODE_H_

#include "Node.h"

namespace simplicity
{
  /**
   * <p>
   * A component of a {@link simplicity::SceneGraph SceneGraph}.
   * </p>
   *
   * @author Gary Buyn
   */
  class SimpleNode : public virtual Node
  {
    public:
      /**
       * <p>
       * Creates an instance of <code>SimpleNode</code>.
       * </p>
       */
      SimpleNode();

      /**
       * <p>
       * Disposes of an instance of <code>SimpleNode</code>.
       * </p>
       */
      virtual
      ~SimpleNode();

      void
      addChild(Node * const child);

      TransformationMatrix<float> *
      getAbsoluteTransformation()const;

      BoundingVolume *
      getBounds() const;

      vector<Node *>
      getChildren() const;

      int
      getID() const;

      Node *
      getParent() const;

      TransformationMatrix<float> *
      getTransformation() const;

      bool
      hasChildren() const;

      bool
      isAncestor(Node const * const ancestor) const;

      bool
      isCollidable() const;

      bool
      isModifiable() const;

      bool
      isSuccessor(Node const * const successor) const;

      bool
      isVisible() const;

      void
      removeChild(Node * const child);

      void
      setBounds(BoundingVolume * const bounds);

      void
      setCollidable(bool const collidable);

      void
      setID(int const id);

      void
      setModifiable(bool const modifiable);

      void
      setParent(Node * const parent);

      void
      setTransformation(TransformationMatrix<float> * const transformation);

      void
      setVisible(bool const visible);

    private:
      /**
       * <p>
       * A volume containing all the {@link com.se.simplicity.model.Model Model}s within the subgraph of which this <code>SimpleNode</code>
       * is the root.
       * </p>
       */
      BoundingVolume * fBounds;

      /**
       * <p>
       * The <code>SimpleNode</code>s directly below this <code>SimpleNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
       * </p>
       */
      vector<Node *> fChildren;

      /**
       * <p>
       * The collision mode. Determines if this <code>SimpleNode</code> can collide with other <code>SimpleNode</code>s in the
       * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} (determines if it should be included in collision detection).
       * </p>
       */
      bool fCollidable;

      /**
       * <p>
       * This <code>SimpleNode</code>'s unique identifier. This unique identifier is managed by the {@link com.se.simplicity.scenegraph.SceneGraph
       * SceneGraph}.
       * </p>
       */
      int fId;

      /**
       * <p>
       * The modification mode. Determines if this <code>SimpleNode</code> can be modified.
       * </p>
       */
      bool fModifiable;

      /**
       * <p>
       * The <code>SimpleNode</code> directly above this <code>SimpleNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} .
       * </p>
       */
      Node * fParent;

      /**
       * <p>
       * This <code>SimpleNode</code>'s relative position and orientation.
       * </p>
       */
      TransformationMatrix<float> * fTransformation;

      /**
       * <p>
       * The visibility mode. Determines if this <code>SimpleNode</code> is visible (determines if it should be rendered).
       * </p>
       */
      bool fVisible;
  };
}

#endif /* SIMPLENODE_H_ */
