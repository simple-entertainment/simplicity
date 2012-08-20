/*
 * Copyright © 2012 Simple Entertainment Limited
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
#ifndef MOCKTREE_H_
#define MOCKTREE_H_

#include <gmock/gmock.h>

#include <simplicity/graph/Tree.h>
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
	template<typename NodeType = TreeNode>
	class MockTree : public Tree<NodeType>
	{
		public:
			MOCK_METHOD1_T(add, NodeType&(std::shared_ptr<NodeType> node));
			MOCK_METHOD2_T(connect, void(NodeType& parent, NodeType& child));
			MOCK_METHOD2_T(disconnect, void(NodeType& parent, NodeType& child));
			MOCK_METHOD1_T(get, NodeType&(int id));
			MOCK_CONST_METHOD1_T(get, const NodeType&(int id));
			MOCK_CONST_METHOD0_T(getAll, const std::vector<std::shared_ptr<NodeType> >&());
			MOCK_METHOD0_T(getRoot, NodeType&());
			MOCK_CONST_METHOD0_T(getRoot, const NodeType&());
			MOCK_METHOD1_T(remove, void(NodeType& node));
	};
}

#endif /* MOCKTREE_H_ */
