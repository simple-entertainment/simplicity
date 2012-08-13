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
#ifndef SIMPLENODE_H_
#define SIMPLENODE_H_

#include "Node.h"

namespace simplicity
{
	/**
	 * <p>
	 * A simple component of a {@link simplicity::Scene Scene}.
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
			virtual ~SimpleNode();

			void addChild(std::shared_ptr<Node> child);

			std::unique_ptr<TransformationMatrix<> > getAbsoluteTransformation() const;

			// const BoundingVolume& getBounds() const; TODO Create BoundingVolume

			const std::vector<std::shared_ptr<Node> >& getChildren() const;

			int getId() const;

			Node* getParent() const;

			TransformationMatrix<>& getTransformation() const;

			bool hasChildren() const;

			bool isAncestor(const Node& ancestor) const;

			bool isCollidable() const;

			bool isModifiable() const;

			bool isSuccessor(const Node& successor) const;

			bool isVisible() const;

			void removeChild(Node& child);

			void setCollidable(const bool collidable);

			void setId(const int id);

			void setModifiable(const bool modifiable);

			void setParent(Node* parent);

			void setTransformation(std::unique_ptr<TransformationMatrix<> > transformation);

			void setVisible(const bool visible);

		private:
			/**
			 * <p>
			 * A volume containing all the {@link simplicity::Model Model}s within the subgraph of which this
			 * <code>SimpleNode</code> is the root.
			 * </p>
			 */
			// BoundingVolume& bounds; TODO Create BoundingVolume
			/**
			 * <p>
			 * The <code>SimpleNode</code>s directly below this <code>SimpleNode</code> in a
			 * {@link simplicity::Scene Scene}.
			 * </p>
			 */
			std::vector<std::shared_ptr<Node> > children;

			/**
			 * <p>
			 * The collision mode. Determines if this <code>SimpleNode</code> can collide with other
			 * <code>SimpleNode</code>s in the {@link simplicity::Scene Scene} (determines if it should be included in
			 * collision detection).
			 * </p>
			 */
			bool collidable;

			/**
			 * <p>
			 * This <code>SimpleNode</code>'s unique identifier. This unique identifier is managed by the
			 * {@link simplicity::Scene Scene}.
			 * </p>
			 */
			int id;

			/**
			 * <p>
			 * The modification mode. Determines if this <code>SimpleNode</code> can be modified.
			 * </p>
			 */
			bool modifiable;

			/**
			 * <p>
			 * The <code>SimpleNode</code> directly above this <code>SimpleNode</code> in a
			 * {@link simplicity::Scene Scene}.
			 * </p>
			 */
			Node* parent;

			/**
			 * <p>
			 * This <code>SimpleNode</code>'s relative position and orientation.
			 * </p>
			 */
			std::unique_ptr<TransformationMatrix<> > transformation;

			/**
			 * <p>
			 * The visibility mode. Determines if this <code>SimpleNode</code> is visible (determines if it should be
			 * rendered).
			 * </p>
			 */
			bool visible;
	};
}

#endif /* SIMPLENODE_H_ */
