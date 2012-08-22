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

#include <simplicity/graph/Node.h>

namespace simplicity
{
	/**
	 * <p>
	 * A mock implementation of {@link simplicity::MockNode MockNode}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class MockNode : public Node
	{
		public:
			MOCK_METHOD1(connectTo, void(Node& otherNode));
			MOCK_CONST_METHOD0(copy, std::shared_ptr<Node>());
			MOCK_METHOD1(disconnectFrom, void(Node& otherNode));
			MOCK_CONST_METHOD0(getComponent, Component*());
			MOCK_CONST_METHOD0(getConnectedNodes, std::vector<std::reference_wrapper<Node> >());
			MOCK_CONST_METHOD0(getId, int());
			MOCK_CONST_METHOD0(getTransformation, TransformationMatrix<>&());
			MOCK_METHOD1(setComponent, void(Component* id));
			MOCK_METHOD1(setId, void(const int id));
			//MOCK_METHOD1(setTransformation, void(std::unique_ptr<TransformationMatrix<> > transformation));

			// TODO Mock this properly when it is supported!
			void setTransformation(std::unique_ptr<TransformationMatrix<> > transformation)
			{
			}
	};
}

#endif /* MOCKNODE_H_ */
