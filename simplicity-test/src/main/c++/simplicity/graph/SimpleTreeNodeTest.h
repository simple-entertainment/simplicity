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
#ifndef SIMPLETREENODETEST_H_
#define SIMPLETREENODETEST_H_

#include <gtest/gtest.h>

#include <simplicity/graph/SimpleTreeNode.h>

namespace simplicity
{
	/**
	 * <p>
	 * Unit tests for the class {@link simplicity::SimpleTreeNode SimpleTreeNode}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleTreeNodeTest : public testing::Test
	{
		protected:
			std::shared_ptr<SimpleTreeNode> objectUnderTest;

			/**
			 * <p>
			 * Setup to perform before each unit test.
			 * </p>
			 */
			void SetUp()
			{
				objectUnderTest.reset(new SimpleTreeNode);
			}
	};
}

#endif /* SIMPLENODETEST_H_ */
