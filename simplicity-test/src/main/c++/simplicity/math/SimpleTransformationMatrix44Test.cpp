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
#include <boost/math/constants/constants.hpp>

#include <simplicity/math/SimpleTranslationVector4.h>

#include "SimpleTransformationMatrix44Test.h"

using namespace boost::math::constants;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTransformationMatrix44#rotate() rotate()}.
	 * </p>
	 */
	TEST_F(SimpleTransformationMatrix44Test, rotate)
	{
		objectUnderTest.rotate(pi<float>() / 2.0f, SimpleTranslationVector4<>(0.0f, 1.0f, 0.0f, 1.0f));

		array<float, SimpleTransformationMatrix44<>::SIZE>& data = objectUnderTest.getData();

		ASSERT_NEAR(0.0f, data.at(0), 0.0000001f);
		ASSERT_NEAR(0.0f, data.at(1), 0.0000001f);
		ASSERT_NEAR(-1.0f, data.at(2), 0.0000001f);
		ASSERT_NEAR(0.0f, data.at(4), 0.0000001f);
		ASSERT_NEAR(1.0f, data.at(5), 0.0000001f);
		ASSERT_NEAR(0.0f, data.at(6), 0.0000001f);
		ASSERT_NEAR(1.0f, data.at(8), 0.0000001f);
		ASSERT_NEAR(0.0f, data.at(9), 0.0000001f);
		ASSERT_NEAR(0.0f, data.at(10), 0.0000001f);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTransformationMatrix44#translate() translate()}.
	 * </p>
	 */
	TEST_F(SimpleTransformationMatrix44Test, translate)
	{
		array<float, SimpleTransformationMatrix44<>::SIZE>& data = objectUnderTest.getData();

		data.at(12) = 1.0f;
		data.at(13) = 2.0f;
		data.at(14) = 3.0f;

		objectUnderTest.translate(SimpleTranslationVector4<>(1.0f, 2.0f, 3.0f, 1.0f));

		ASSERT_EQ(2.0f, data.at(12));
		ASSERT_EQ(4.0f, data.at(13));
		ASSERT_EQ(6.0f, data.at(14));
	}
}
