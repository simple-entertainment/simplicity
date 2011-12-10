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
#ifndef MOCKNODE_H_
#define MOCKNODE_H_

#include <gmock/gmock.h>

#include <simplicity/scene/Node.h>

namespace simplicity
{
	/**
	 * <p>
	 * A mock implementation of {@link simplicity::MockNode MockNode}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class MockNode : public simplicity::Node
	{
		public:
			MOCK_METHOD1(addChild, void(boost::shared_ptr<Node> child));
			MOCK_CONST_METHOD0(getAbsoluteTransformation, const TransformationMatrix<float>&());
			//MOCK_CONST_METHOD0(getBounds, boost::shared_ptr<simplicity::BoundingVolume>());
			MOCK_CONST_METHOD0(getChildren, const std::vector<boost::shared_ptr<Node> >&());
			MOCK_CONST_METHOD0(getId, int());
			MOCK_CONST_METHOD0(getParent, boost::shared_ptr<Node>());
			MOCK_CONST_METHOD0(getTransformation, TransformationMatrix<float>&());
			MOCK_CONST_METHOD0(hasChildren, bool());
			MOCK_CONST_METHOD1(isAncestor, bool(const Node& ancestor));
			MOCK_CONST_METHOD0(isCollidable, bool());
			MOCK_CONST_METHOD0(isModifiable, bool());
			MOCK_CONST_METHOD1(isSuccessor, bool(const Node& successor));
			MOCK_CONST_METHOD0(isVisible, bool());
			MOCK_METHOD1(removeChild, void(Node& child));
			MOCK_METHOD1(setCollidable, void(const bool collidable));
			MOCK_METHOD1(setId, void(const int id));
			MOCK_METHOD1(setModifiable, void(const bool modifiable));
			MOCK_METHOD1(setParent, void(boost::shared_ptr<Node> parent));
			MOCK_METHOD1(setTransformation, void(boost::shared_ptr<TransformationMatrix<float> > transformation));
			MOCK_METHOD1(setVisible, void(const bool visible));
	};
}

#endif /* MOCKNODE_H_ */
