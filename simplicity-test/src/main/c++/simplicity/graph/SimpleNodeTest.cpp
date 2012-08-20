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
#include <simplicity/math/SimpleTranslationVector.h>
#include <simplicity/model/shape/Sphere.h>

#include "SimpleNodeTest.h"

using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleNode#operator=(const SimpleNode&) operator=(const SimpleNode&)}.
	 * </p>
	 */
	TEST_F(SimpleNodeTest, copyAssignment)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		Sphere component;
		SimpleNode original;
		original.setComponent(&component);
		original.setId(1);

		SimpleTranslationVector<> translation;
		translation.setX(1.0f);
		translation.setY(2.0f);
		translation.setZ(3.0f);
		original.getTransformation().translate(translation);

		// Perform test.
		// //////////////////////////////////////////////////
		SimpleNode objectUnderTest = original;

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(original.getComponent(), objectUnderTest.getComponent());
		ASSERT_EQ(original.getId(), objectUnderTest.getId());
		ASSERT_EQ(original.getTransformation(), objectUnderTest.getTransformation());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleNode#SimpleNode(const SimpleNode&) SimpleNode(const SimpleNode&)}.
	 * </p>
	 */
	TEST_F(SimpleNodeTest, copyConstructor)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		Sphere component;
		SimpleNode original;
		original.setComponent(&component);
		original.setId(1);

		SimpleTranslationVector<> translation;
		translation.setX(1.0f);
		translation.setY(2.0f);
		translation.setZ(3.0f);
		original.getTransformation().translate(translation);

		// Perform test.
		// //////////////////////////////////////////////////
		SimpleNode objectUnderTest(original);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_EQ(original.getComponent(), objectUnderTest.getComponent());
		ASSERT_EQ(original.getId(), objectUnderTest.getId());
		ASSERT_EQ(original.getTransformation(), objectUnderTest.getTransformation());
	}
}
