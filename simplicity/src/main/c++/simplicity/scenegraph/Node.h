/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef NODE_H_
#define NODE_H_

#include <vector>

#include <boost/enable_shared_from_this.hpp>

#include "../Component.h"
#include "../math/TransformationMatrix.h"
#include "../model/BoundingVolume.h"

namespace simplicity
{
  /**
   * <p>
   * A component of a {@link simplicity::SceneGraph SceneGraph}.
   * </p>
   *
   * @author Gary Buyn
   */
  class Node : public Component, public boost::enable_shared_from_this<Node>
  {
    public:
      /**
       * <p>
       * Adds a child to this <code>Node</code>.
       * </p>
       *
       * @param child The <code>Node</code> to add to this <code>Node</code>'s children.
       */
      virtual void
      addChild(boost::shared_ptr<Node> child) = 0;

      /**
       * <p>
       * Retrieves this <code>Node</code>'s absolute position and orientation.
       * </p>
       *
       * @return This <code>Node</code>'s absolute position and orientation.
       */
      virtual const TransformationMatrix<float>&
      getAbsoluteTransformation() const = 0;

      /**
       * <p>
       * Retrieves a volume containing all the {@link simplicity::Model Model}s within the subgraph of which this <code>Node</code> is the
       * root.
       * </p>
       *
       * @return A volume containing all the <code>Model</code>s within the subgraph of which this <code>Node</code> is the
       * root.
       */
//      virtual const BoundingVolume& TODO
//      getBounds() const = 0;

      /**
       * <p>
       * Retrieves the <code>Node</code>s directly below this <code>Node</code> in a {@link simplicity::SceneGraph SceneGraph}.
       * </p>
       *
       * @return The <code>Node</code>s directly below this <code>Node</code> in a <code>SceneGraph</code>.
       */
      virtual const std::vector<boost::shared_ptr<Node> >&
      getChildren() const = 0;

      /**
       * <p>
       * Retrieves this <code>Node</code>'s unique identifier.
       * </p>
       *
       * @return This <code>Node</code>'s unique identifier.
       */
      virtual int
      getID() const = 0;

      /**
       * <p>
       * Retrieves the <code>Node</code> directly above this <code>Node</code> in a {@link simplicity::SceneGraph SceneGraph}.
       * </p>
       *
       * @return The <code>Node</code> directly above this <code>Node</code> in a <code>SceneGraph</code>.
       */
      virtual boost::shared_ptr<Node>
      getParent() const = 0;

      /**
       * <p>
       * Obtain a shared pointer to this <code>Node</code>.
       * </p>
       */
      boost::shared_ptr<Node> getThisShared() { return (shared_from_this()); }
      boost::shared_ptr<const Node> getThisShared() const { return (shared_from_this()); }

      /**
       * <p>
       * Retrieves this <code>Node</code>'s relative position and orientation.
       * </p>
       *
       * @return This <code>Node</code>'s relative position and orientation.
       */
      virtual TransformationMatrix<float>&
      getTransformation() const = 0;

      /**
       * <p>
       * Determines if children exist for this <code>Node</code>.
       * </p>
       *
       * @return True if children exist for this <code>Node</code>, false otherwise.
       */
      virtual bool
      hasChildren() const = 0;

      /**
       * <p>
       * Determines if the given <code>Node</code> is an ancestor of this <code>Node</code>.
       * </p>
       *
       * @param ancestor The <code>Node</code> to check.
       * @return True if the given <code>Node</code> is an ancestor of this <code>Node</code>, false otherwise.
       */
      virtual bool
      isAncestor(const Node& ancestor) const = 0;

      /**
       * <p>
       * Determines if this <code>Node</code> can collide with other <code>Node</code>s in the {@link simplicity::SceneGraph
       * SceneGraph} (determines if it should be included in collision detection).
       * </p>
       *
       * @return True if this <code>Node</code> can collide with other <code>Node</code>s in the <code>SceneGraph</code>, false otherwise.
       */
      virtual bool
      isCollidable() const = 0;

      /**
       * <p>
       * Determines if this <code>Node</code> can be modified.
       * </p>
       *
       * @return True if this <code>Node</code> can be modified, false otherwise.
       */
      virtual bool
      isModifiable() const = 0;

      /**
       * <p>
       * Determines if the given <code>Node</code> is a successor of this <code>Node</code>.
       * </p>
       *
       * @param successor The <code>Node</code> to check.
       * @return True if the given <code>Node</code> is a successor of this <code>Node</code>, false otherwise.
       */
      virtual bool
      isSuccessor(const Node& successor) const = 0;

      /**
       * <p>
       * Determines if this <code>Node</code> is visible (determines if it should be rendered).
       * </p>
       *
       * @return True if this <code>Node</code> is visible, false otherwise.
       */
      virtual bool
      isVisible() const = 0;

      /**
       * <p>
       * Removes a child from this <code>Node</code>.
       * </p>
       *
       * @param child The child to be removed.
       */
      virtual void
      removeChild(Node& child) = 0;

      /**
       * <p>
       * Sets the collision mode.
       * </p>
       *
       * @param collidable Determines if this <code>Node</code> can collide with other <code>Node</code>s in the
       * {@link simplicity.scenegraph.SceneGraph SceneGraph} (determines if it should be included in collision detection).
       */
      virtual void
      setCollidable(const bool collidable) = 0;

      /**
       * <p>
       * Sets this <code>Node</code>'s unique identifier. This identifier should be managed by the {@link simplicity.scenegraph.SceneGraph
       * SceneGraph}.
       * </p>
       *
       * @param id This <code>Node</code>'s unique identifier.
       */
      virtual void
      setID(const int id) = 0;

      /**
       * <p>
       * Sets the modification mode.
       * </p>
       *
       * @param modifiable Determines if this <code>Node</code> can be modified.
       */
      virtual void
      setModifiable(const bool modifiable) = 0;

      /**
       * <p>
       * Sets the <code>Node</code> directly above this <code>Node</code> in a {@link simplicity.scenegraph.SceneGraph SceneGraph}.
       * </p>
       *
       * @param parent The <code>Node</code> directly above this <code>Node</code> in a {@link simplicity.scenegraph.SceneGraph SceneGraph}.
       */
      virtual void
      setParent(boost::shared_ptr<Node> parent) = 0;

      /**
       * <p>
       * Sets this <code>Node</code>'s relative position and orientation.
       * </p>
       *
       * @param transformation This <code>Node</code>'s relative position and orientation.
       */
      virtual void
      setTransformation(boost::shared_ptr<TransformationMatrix<float> > transformation) = 0;

      /**
       * <p>
       * The visibility mode.
       * </p>
       *
       * @param visible Determines if this <code>Node</code> is visible (determines if it should be rendered).
       */
      virtual void
      setVisible(const bool visible) = 0;
  };
}

#endif /* NODE_H_ */
