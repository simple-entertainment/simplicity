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
#ifndef SIMPLEPATHFINDERTEST_H_
#define SIMPLEPATHFINDERTEST_H_

#include <gtest/gtest.h>

#include <simplicity/ai/pathfinding/SimplePathFinder.h>
#include <simplicity/scene/SimpleNode.h>

namespace simplicity
{
	/**
	 * <p>
	 * Unit tests for the class {@link simplicity::SimplePathFinder SimplePathFinder}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimplePathFinderTest : public testing::Test
	{
		protected:
			const static unsigned int COLUMNS = 5;

			const static unsigned int ROWS = 5;

			std::vector<std::shared_ptr<Node> > pathNodes;

			void SetUp()
			{
				// Create full path
				for (unsigned int column = 0; column < COLUMNS; column++)
				{
					for (unsigned int row = 0; row < ROWS; row++)
					{
						std::shared_ptr<Node> pathNode(new SimpleNode);
						pathNodes.push_back(pathNode);
					}
				}

				for (unsigned int column = 0; column < COLUMNS; column++)
				{
					for (unsigned int row = 0; row < ROWS; row++)
					{
						if (column > 0)
						{
							pathNodes.at(column * ROWS + row)->addChild(pathNodes.at((column - 1) * ROWS + row));
						}
						if (column < COLUMNS - 1)
						{
							pathNodes.at(column * ROWS + row)->addChild(pathNodes.at((column + 1) * ROWS + row));
						}
						if (row > 0)
						{
							pathNodes.at(column * ROWS + row)->addChild(pathNodes.at(column * ROWS + (row - 1)));
						}
						if (row < ROWS - 1)
						{
							pathNodes.at(column * ROWS + row)->addChild(pathNodes.at(column * ROWS + (row + 1)));
						}
					}
				}
			}
	};
}

#endif /* SIMPLEPATHFINDERTEST_H_ */
