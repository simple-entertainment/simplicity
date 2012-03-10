/*
 * Copyright © 2011 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef NODE_H_
#define NODE_H_

#include <vector>

#include "../math/TransformationMatrix.h"
#include "../model/BoundingVolume.h"

namespace simplicity
{
	/**
	 * <p>
	 * A component of a {@link simplicity::Scene Scene}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Node : public std::enable_shared_from_this<Node>
	{
		public:
			/**
			 * <p>
			 * Adds a child to this <code>Node</code>.
			 * </p>
			 *
			 * @param child The <code>Node</code> to add to this <code>Node</code>'s children.
			 */
			virtual void addChild(std::shared_ptr<Node> child) = 0;

			/**
			 * <p>
			 * Retrieves this <code>Node</code>'s absolute position and orientation.
			 * </p>
			 *
			 * @return This <code>Node</code>'s absolute position and orientation.
			 */
			virtual std::unique_ptr<TransformationMatrix<> > getAbsoluteTransformation() const = 0;

			/**
			 * <p>
			 * Retrieves a volume containing all the {@link simplicity::Model Model}s within the subgraph of which this
			 * <code>Node</code> is the root.
			 * </p>
			 *
			 * @return A volume containing all the <code>Model</code>s within the subgraph of which this
			 * <code>Node</code> is the root.
			 */
			// virtual const BoundingVolume& getBounds() const = 0; TODO Create BoundingVolume

			/**
			 * <p>
			 * Retrieves the <code>Node</code>s directly below this <code>Node</code> in a
			 * {@link simplicity::Scene Scene}.
			 * </p>
			 *
			 * @return The <code>Node</code>s directly below this <code>Node</code> in a <code>Scene</code>.
			 */
			virtual const std::vector<std::shared_ptr<Node> >& getChildren() const = 0;

			/**
			 * <p>
			 * Retrieves this <code>Node</code>'s unique identifier.
			 * </p>
			 *
			 * @return This <code>Node</code>'s unique identifier.
			 */
			virtual int getId() const = 0;

			/**
			 * <p>
			 * Retrieves the <code>Node</code> directly above this <code>Node</code> in a
			 * {@link simplicity::Scene Scene}.
			 * </p>
			 *
			 * @return The <code>Node</code> directly above this <code>Node</code> in a <code>Scene</code>.
			 */
			virtual std::shared_ptr<Node> getParent() const = 0;

			/**
			 * <p>
			 * Obtain a shared pointer to this <code>Node</code>.
			 * </p>
			 */
			std::shared_ptr<Node> getThisShared()
			{
				return (shared_from_this());
			}
			std::shared_ptr<const Node> getThisShared() const
			{
				return (shared_from_this());
			}

			/**
			 * <p>
			 * Retrieves this <code>Node</code>'s relative position and orientation.
			 * </p>
			 *
			 * @return This <code>Node</code>'s relative position and orientation.
			 */
			virtual TransformationMatrix<>& getTransformation() const = 0;

			/**
			 * <p>
			 * Determines if children exist for this <code>Node</code>.
			 * </p>
			 *
			 * @return True if children exist for this <code>Node</code>, false otherwise.
			 */
			virtual bool hasChildren() const = 0;

			/**
			 * <p>
			 * Determines if the given <code>Node</code> is an ancestor of this <code>Node</code>.
			 * </p>
			 *
			 * @param ancestor The <code>Node</code> to check.
			 * @return True if the given <code>Node</code> is an ancestor of this <code>Node</code>, false otherwise.
			 */
			virtual bool isAncestor(const Node& ancestor) const = 0;

			/**
			 * <p>
			 * Determines if this <code>Node</code> can collide with other <code>Node</code>s in the
			 * {@link simplicity::Scene Scene} (determines if it should be included in collision detection).
			 * </p>
			 *
			 * @return True if this <code>Node</code> can collide with other <code>Node</code>s in the
			 * <code>Scene</code>, false otherwise.
			 */
			virtual bool isCollidable() const = 0;

			/**
			 * <p>
			 * Determines if this <code>Node</code> can be modified.
			 * </p>
			 *
			 * @return True if this <code>Node</code> can be modified, false otherwise.
			 */
			virtual bool isModifiable() const = 0;

			/**
			 * <p>
			 * Determines if the given <code>Node</code> is a successor of this <code>Node</code>.
			 * </p>
			 *
			 * @param successor The <code>Node</code> to check.
			 * @return True if the given <code>Node</code> is a successor of this <code>Node</code>, false otherwise.
			 */
			virtual bool isSuccessor(const Node& successor) const = 0;

			/**
			 * <p>
			 * Determines if this <code>Node</code> is visible (determines if it should be rendered).
			 * </p>
			 *
			 * @return True if this <code>Node</code> is visible, false otherwise.
			 */
			virtual bool isVisible() const = 0;

			/**
			 * <p>
			 * Removes a child from this <code>Node</code>.
			 * </p>
			 *
			 * @param child The child to be removed.
			 */
			virtual void removeChild(Node& child) = 0;

			/**
			 * <p>
			 * Sets the collision mode.
			 * </p>
			 *
			 * @param collidable Determines if this <code>Node</code> can collide with other <code>Node</code>s in the
			 * {@link simplicity.scenegraph.Scene Scene} (determines if it should be included in collision detection).
			 */
			virtual void setCollidable(const bool collidable) = 0;

			/**
			 * <p>
			 * Sets this <code>Node</code>'s unique identifier. This identifier should be managed by the
			 * {@link simplicity::Scene Scene}.
			 * </p>
			 *
			 * @param id This <code>Node</code>'s unique identifier.
			 */
			virtual void setId(const int id) = 0;

			/**
			 * <p>
			 * Sets the modification mode.
			 * </p>
			 *
			 * @param modifiable Determines if this <code>Node</code> can be modified.
			 */
			virtual void setModifiable(const bool modifiable) = 0;

			/**
			 * <p>
			 * Sets the <code>Node</code> directly above this <code>Node</code> in a {@link simplicity::Scene Scene}.
			 * </p>
			 *
			 * @param parent The <code>Node</code> directly above this <code>Node</code> in a <code>Scene</code>.
			 */
			virtual void setParent(std::shared_ptr<Node> parent) = 0;

			/**
			 * <p>
			 * Sets this <code>Node</code>'s relative position and orientation.
			 * </p>
			 *
			 * @param transformation This <code>Node</code>'s relative position and orientation.
			 */
			virtual void setTransformation(std::unique_ptr<TransformationMatrix<> > transformation) = 0;

			/**
			 * <p>
			 * The visibility mode.
			 * </p>
			 *
			 * @param visible Determines if this <code>Node</code> is visible (determines if it should be rendered).
			 */
			virtual void setVisible(const bool visible) = 0;
	};
}

#endif /* NODE_H_ */
