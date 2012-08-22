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
#ifndef SIMPLETREENODE_H_
#define SIMPLETREENODE_H_

#include "TreeNode.h"

namespace simplicity
{
	class SimpleTreeNode : public TreeNode
	{
		public:
			SimpleTreeNode();

			SimpleTreeNode(const SimpleTreeNode& original);

			virtual ~SimpleTreeNode();

			void addChild(TreeNode& child);

			void connectTo(Node& parent);

			std::shared_ptr<Node> copy() const;

			void disconnectFrom(Node& parent);

			std::unique_ptr<TransformationMatrix<> > getAbsoluteTransformation() const;

			const std::vector<std::reference_wrapper<TreeNode> >& getChildren() const;

			Component* getComponent() const;

			std::vector<std::reference_wrapper<Node> > getConnectedNodes() const;

			int getId() const;

			TreeNode* getParent() const;

			TransformationMatrix<>& getTransformation() const;

			bool hasChildren() const;

			bool isAncestor(const TreeNode& ancestor) const;

			bool isSuccessor(const TreeNode& successor) const;

			SimpleTreeNode& operator=(const SimpleTreeNode& original);

			void removeChild(TreeNode& child);

			void setComponent(Component* component);

			void setId(const int id);

			void setTransformation(std::unique_ptr<TransformationMatrix<> > transformation);

		private:
			std::vector<std::reference_wrapper<TreeNode> > children;

			Component* component;

			int id;

			TreeNode* parent;

			/**
			 * <p>
			 * This <code>SimpleNode</code>'s relative position and orientation.
			 * </p>
			 */
			std::unique_ptr<TransformationMatrix<> > transformation;
	};
}

#endif /* SIMPLETREENODE_H_ */
