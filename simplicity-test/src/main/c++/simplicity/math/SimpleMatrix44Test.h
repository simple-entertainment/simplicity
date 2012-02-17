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
#ifndef SIMPLEMATRIX44TEST_H_
#define SIMPLEMATRIX44TEST_H_

#include <gtest/gtest.h>

#include <simplicity/math/SimpleMatrix44.h>

namespace simplicity
{
	/**
	 * <p>
	 * Unit tests for the class {@link simplicity::SimpleMatrix44 SimpleMatrix44}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimpleMatrix44Test : public testing::Test
	{
		protected:
			/**
			 * An instance of the class being unit tested.
			 */
			SimpleMatrix44<> objectUnderTest;

			/**
			 * <p>
			 * Setup to perform before each unit test.
			 * </p>
			 */
			void SetUp()
			{
				std::array<float, SimpleMatrix44<>::SIZE>& data = objectUnderTest.getData();

				data.at(0) = 1.0f;
				data.at(4) = 2.0f;
				data.at(8) = 3.0f;
				data.at(12) = 4.0f;
				data.at(1) = 2.0f;
				data.at(5) = 1.0f;
				data.at(9) = 4.0f;
				data.at(13) = 3.0f;
				data.at(2) = 3.0f;
				data.at(6) = 4.0f;
				data.at(10) = 1.0f;
				data.at(14) = 2.0f;
				data.at(3) = 0.0f;
				data.at(7) = 0.0f;
				data.at(11) = 0.0f;
				data.at(15) = 1.0f;
			}
	};
}

#endif /* SIMPLEMATRIX44TEST_H_ */