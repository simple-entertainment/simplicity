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
#ifndef TREENODE_H_
#define TREENODE_H_

#include "Node.h"

namespace simplicity
{
	/**
	 * <p>
	 * A node in a {@link simplicity::Tree Tree}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class TreeNode : public virtual Node
	{
		public:
			/**
			 * <p>
			 * Adds a child to this <code>TreeNode</code>.
			 * </p>
			 *
			 * @param child The <code>TreeNode</code> to add to this <code>TreeNode</code>'s children.
			 */
			virtual void addChild(TreeNode& child) = 0;

			/**
			 * <p>
			 * Retrieves this <code>TreeNode</code>'s absolute position and orientation.
			 * </p>
			 *
			 * @return This <code>TreeNode</code>'s absolute position and orientation.
			 */
			virtual std::unique_ptr<TransformationMatrix<> > getAbsoluteTransformation() const = 0;

			/**
			 * <p>
			 * Retrieves the <code>TreeNode</code>s directly below this <code>TreeNode</code> in the
			 * {@link simplicity::Tree Tree}.
			 * </p>
			 *
			 * @return The <code>TreeNode</code>s directly below this <code>TreeNode</code> in the <code>Tree</code>.
			 */
			virtual std::vector<std::reference_wrapper<TreeNode> > getChildren() const = 0;

			/**
			 * <p>
			 * Retrieves the <code>TreeNode</code> directly above this <code>TreeNode</code> in the
			 * {@link simplicity::Tree Tree}.
			 * </p>
			 *
			 * @return The <code>TreeNode</code> directly above this <code>TreeNode</code> in the <code>Tree</code>.
			 */
			virtual TreeNode* getParent() const = 0;

			/**
			 * <p>
			 * Determines if children exist for this <code>TreeNode</code>.
			 * </p>
			 *
			 * @return True if children exist for this <code>TreeNode</code>, false otherwise.
			 */
			virtual bool hasChildren() const = 0;

			/**
			 * <p>
			 * Determines if the given <code>TreeNode</code> is an ancestor of this <code>TreeNode</code>.
			 * </p>
			 *
			 * @param ancestor The <code>TreeNode</code> to check.
			 * @return True if the given <code>TreeNode</code> is an ancestor of this <code>TreeNode</code>, false
			 * otherwise.
			 */
			virtual bool isAncestor(const TreeNode& ancestor) const = 0;

			/**
			 * <p>
			 * Determines if the given <code>TreeNode</code> is a successor of this <code>TreeNode</code>.
			 * </p>
			 *
			 * @param successor The <code>TreeNode</code> to check.
			 * @return True if the given <code>TreeNode</code> is a successor of this <code>TreeNode</code>, false
			 * otherwise.
			 */
			virtual bool isSuccessor(const TreeNode& successor) const = 0;

			/**
			 * <p>
			 * Removes a child from this <code>TreeNode</code>.
			 * </p>
			 *
			 * @param child The child to be removed.
			 */
			virtual void removeChild(TreeNode& child) = 0;

			virtual void setParent(TreeNode* parent) = 0;
	};
}

#endif /* TREENODE_H_ */
