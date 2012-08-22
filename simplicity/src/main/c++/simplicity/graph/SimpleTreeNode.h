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

#include "BaseNode.h"
#include "TreeNode.h"

namespace simplicity
{
	class SimpleTreeNode : public virtual TreeNode, public BaseNode
	{
		public:
			SimpleTreeNode();

			SimpleTreeNode(const SimpleTreeNode& original);

			void addChild(TreeNode& child);

			void connectTo(Node& otherNode);

			std::shared_ptr<Node> copy() const;

			void disconnectFrom(Node& otherNode);

			std::unique_ptr<TransformationMatrix<> > getAbsoluteTransformation() const;

			std::vector<std::reference_wrapper<TreeNode> > getChildren() const;

			std::vector<std::reference_wrapper<Node> > getConnectedNodes() const;

			TreeNode* getParent() const;

			bool hasChildren() const;

			bool isAncestor(const TreeNode& ancestor) const;

			bool isSuccessor(const TreeNode& successor) const;

			SimpleTreeNode& operator=(const SimpleTreeNode& original);

			void removeChild(TreeNode& child);

			void setParent(TreeNode* parent);

		private:
			std::vector<std::reference_wrapper<TreeNode> > children;

			TreeNode* parent;
	};
}

#endif /* SIMPLETREENODE_H_ */
