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
#include <simplicity/ai/pathfinding/BezierPathInterpolator.h>
#include <simplicity/vector/SimpleTransformationMatrix44.h>
#include <simplicity/vector/SimpleTranslationVector4.h>

#include "../../scenegraph/MockNode.h"
#include "BezierPathInterpolatorTest.h"

using namespace boost;
using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::BezierPathInterpolator#interpolate(const float) interpolate(const float)} with the special
	 * condition that the path contains only one node (all interpolations should resolve to the same point as the node).
	 * </p>
	 */
	TEST_F(BezierPathInterpolatorTest, interpolateOneNode)
	{
	    // Create dependencies.
	    // //////////////////////////////////////////////////
		shared_ptr<MockNode> mockNode(new NiceMock<MockNode>);
		SimpleTransformationMatrix44<float> transformation;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode);

	    // Provide stub behaviour.
	    // //////////////////////////////////////////////////
		ON_CALL(*mockNode, getTransformation()).WillByDefault(ReturnRef(transformation));

	    // Initialise the test environment.
	    // //////////////////////////////////////////////////
		transformation.translate(SimpleTranslationVector4<float>(1.0f, 1.0f, 1.0f, 1.0f));

	    // Perform test.
	    // //////////////////////////////////////////////////
		BezierPathInterpolator interpolator(path);

	    // Verify test results.
	    // //////////////////////////////////////////////////
		shared_ptr<TranslationVector<float> > point1 = interpolator.interpolate(0.0f);
		ASSERT_NEAR(1.0f, point1->getX(), 0.0001f);
		ASSERT_NEAR(1.0f, point1->getY(), 0.0001f);
		ASSERT_NEAR(1.0f, point1->getZ(), 0.0001f);

		shared_ptr<TranslationVector<float> > point2 = interpolator.interpolate(0.5f);
		ASSERT_NEAR(1.0f, point2->getX(), 0.0001f);
		ASSERT_NEAR(1.0f, point2->getY(), 0.0001f);
		ASSERT_NEAR(1.0f, point2->getZ(), 0.0001f);

		shared_ptr<TranslationVector<float> > point3 = interpolator.interpolate(1.0f);
		ASSERT_NEAR(1.0f, point3->getX(), 0.0001f);
		ASSERT_NEAR(1.0f, point3->getY(), 0.0001f);
		ASSERT_NEAR(1.0f, point3->getZ(), 0.0001f);
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::BezierPathInterpolator#interpolate(const float) interpolate(const float)} with the special
	 * condition that the path contains three nodes (should result in curved-line interpolation).
	 * </p>
	 */
	TEST_F(BezierPathInterpolatorTest, interpolateThreeNodes)
	{
	    // Create dependencies.
	    // //////////////////////////////////////////////////
		shared_ptr<MockNode> mockNode1(new NiceMock<MockNode>);
		shared_ptr<MockNode> mockNode2(new NiceMock<MockNode>);
		shared_ptr<MockNode> mockNode3(new NiceMock<MockNode>);
		SimpleTransformationMatrix44<float> transformation1;
		SimpleTransformationMatrix44<float> transformation2;
		SimpleTransformationMatrix44<float> transformation3;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);
		path.push_back(mockNode3);

	    // Provide stub behaviour.
	    // //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(ReturnRef(transformation2));
		ON_CALL(*mockNode3, getTransformation()).WillByDefault(ReturnRef(transformation3));

	    // Initialise the test environment.
	    // //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector4<float>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector4<float>(2.0f, 2.0f, 2.0f, 1.0f));
		transformation3.translate(SimpleTranslationVector4<float>(3.0f, 1.0f, 1.0f, 1.0f));

	    // Perform test.
	    // //////////////////////////////////////////////////
		BezierPathInterpolator interpolator(path);

	    // Verify test results.
	    // //////////////////////////////////////////////////
		shared_ptr<TranslationVector<float> > point1 = interpolator.interpolate(0.0f);
		ASSERT_NEAR(1.0f, point1->getX(), 0.0001f);
		ASSERT_NEAR(1.0f, point1->getY(), 0.0001f);
		ASSERT_NEAR(1.0f, point1->getZ(), 0.0001f);

		shared_ptr<TranslationVector<float> > point2 = interpolator.interpolate(0.5f);
		ASSERT_NEAR(2.0f, point2->getX(), 0.0001f);
		ASSERT_NEAR(1.5f, point2->getY(), 0.0001f);
		ASSERT_NEAR(1.5f, point2->getZ(), 0.0001f);

		shared_ptr<TranslationVector<float> > point3 = interpolator.interpolate(1.0f);
		ASSERT_NEAR(3.0f, point3->getX(), 0.0001f);
		ASSERT_NEAR(1.0f, point3->getY(), 0.0001f);
		ASSERT_NEAR(1.0f, point3->getZ(), 0.0001f);
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::BezierPathInterpolator#interpolate(const float) interpolate(const float)} with the special
	 * condition that the path contains two nodes (should result in straight-line interpolation).
	 * </p>
	 */
	TEST_F(BezierPathInterpolatorTest, interpolateTwoNodes)
	{
	    // Create dependencies.
	    // //////////////////////////////////////////////////
		shared_ptr<MockNode> mockNode1(new NiceMock<MockNode>);
		shared_ptr<MockNode> mockNode2(new NiceMock<MockNode>);
		SimpleTransformationMatrix44<float> transformation1;
		SimpleTransformationMatrix44<float> transformation2;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);

	    // Provide stub behaviour.
	    // //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(ReturnRef(transformation2));

	    // Initialise the test environment.
	    // //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector4<float>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector4<float>(2.0f, 2.0f, 2.0f, 1.0f));

	    // Perform test.
	    // //////////////////////////////////////////////////
		BezierPathInterpolator interpolator(path);

	    // Verify test results.
	    // //////////////////////////////////////////////////
		shared_ptr<TranslationVector<float> > point1 = interpolator.interpolate(0.0f);
		ASSERT_NEAR(1.0f, point1->getX(), 0.0001f);
		ASSERT_NEAR(1.0f, point1->getY(), 0.0001f);
		ASSERT_NEAR(1.0f, point1->getZ(), 0.0001f);

		shared_ptr<TranslationVector<float> > point2 = interpolator.interpolate(0.5f);
		ASSERT_NEAR(1.5f, point2->getX(), 0.0001f);
		ASSERT_NEAR(1.5f, point2->getY(), 0.0001f);
		ASSERT_NEAR(1.5f, point2->getZ(), 0.0001f);

		shared_ptr<TranslationVector<float> > point3 = interpolator.interpolate(1.0f);
		ASSERT_NEAR(2.0f, point3->getX(), 0.0001f);
		ASSERT_NEAR(2.0f, point3->getY(), 0.0001f);
		ASSERT_NEAR(2.0f, point3->getZ(), 0.0001f);
	}
}
