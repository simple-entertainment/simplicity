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
#ifndef MOCKTREENODE_H_
#define MOCKTREENODE_H_

#include <gmock/gmock.h>

#include <simplicity/graph/TreeNode.h>

namespace simplicity
{
	/**
	 * <p>
	 * A mock implementation of {@link simplicity::MockNode MockNode}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class MockTreeNode : public TreeNode
	{
		public:
			MOCK_METHOD1(addChild, void(TreeNode& child));
			//MOCK_CONST_METHOD0(getAbsoluteTransformation, std::unique_ptr<TransformationMatrix<> >());
			MOCK_METHOD1(connectTo, void(Node& parent));
			MOCK_CONST_METHOD0(copy, std::shared_ptr<Node>());
			MOCK_METHOD1(disconnectFrom, void(Node& parent));
			MOCK_CONST_METHOD0(getComponent, Component*());
			MOCK_CONST_METHOD0(getConnectedNodes, std::vector<std::reference_wrapper<Node> >());
			MOCK_CONST_METHOD0(getChildren, std::vector<std::reference_wrapper<TreeNode> >());
			MOCK_CONST_METHOD0(getId, int());
			MOCK_CONST_METHOD0(getParent, TreeNode*());
			MOCK_CONST_METHOD0(getTransformation, TransformationMatrix<>&());
			MOCK_CONST_METHOD0(hasChildren, bool());
			MOCK_CONST_METHOD1(isAncestor, bool(const TreeNode& ancestor));
			MOCK_CONST_METHOD1(isSuccessor, bool(const TreeNode& successor));
			MOCK_METHOD1(removeChild, void(TreeNode& child));
			MOCK_METHOD1(setComponent, void(Component* id));
			MOCK_METHOD1(setId, void(const int id));
			MOCK_METHOD1(setParent, void(TreeNode* parent));
			//MOCK_METHOD1(setTransformation, void(std::unique_ptr<TransformationMatrix<> > transformation));

			// TODO Mock this properly when it is supported!
			std::unique_ptr<TransformationMatrix<> > getAbsoluteTransformation() const
			{
				return std::unique_ptr<TransformationMatrix<> >();
			}

			// TODO Mock this properly when it is supported!
			void setTransformation(std::unique_ptr<TransformationMatrix<> > transformation)
			{
			}
	};
}

#endif /* MOCKTREENODE_H_ */
