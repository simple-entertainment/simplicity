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
#include <simplicity/ai/pathfinding/LinearPathWalker.h>
#include <simplicity/math/SimpleTransformationMatrix.h>
#include <simplicity/math/SimpleTranslationVector.h>

#include "../../scene/MockNode.h"
#include "LinearPathWalkerTest.h"

using namespace std;
using namespace testing;

// Distance in one segment: 1.7321
// Distance on each axis when stepping 1.0: 1.5774
namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::LinearPathWalker#stepBackward(const float) stepBackward(const float)}
	 * with the special condition that the walker is already at the start of the path.
	 * </p>
	 */
	TEST_F(LinearPathWalkerTest, stepBackwardFromStart)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::shared_ptr<const MockNode> mockNode1(new testing::NiceMock<MockNode>);
		std::shared_ptr<const MockNode> mockNode2(new testing::NiceMock<MockNode>);
		SimpleTransformationMatrix<> transformation1;
		SimpleTransformationMatrix<> transformation2;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(testing::ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(testing::ReturnRef(transformation2));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector<>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector<>(2.0f, 2.0f, 2.0f, 1.0f));
		LinearPathWalker objectUnderTest(path);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.stepBackward(1.0f);

		// Verify test results.
		// //////////////////////////////////////////////////
		const TranslationVector<>& location = objectUnderTest.getLocation();

		ASSERT_NEAR(1.0f, location.getX(), 0.0001f);
		ASSERT_NEAR(1.0f, location.getY(), 0.0001f);
		ASSERT_NEAR(1.0f, location.getZ(), 0.0001f);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::LinearPathWalker#stepBackward(const float) stepBackward(const float)}
	 * with the special condition that the distance goes past the start of the path.
	 * </p>
	 */
	TEST_F(LinearPathWalkerTest, stepBackwardPastStart)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::shared_ptr<const MockNode> mockNode1(new testing::NiceMock<MockNode>);
		std::shared_ptr<const MockNode> mockNode2(new testing::NiceMock<MockNode>);
		SimpleTransformationMatrix<> transformation1;
		SimpleTransformationMatrix<> transformation2;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(testing::ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(testing::ReturnRef(transformation2));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector<>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector<>(2.0f, 2.0f, 2.0f, 1.0f));
		LinearPathWalker objectUnderTest(path);
		objectUnderTest.stepForward(1.0f);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.stepBackward(2.0f);

		// Verify test results.
		// //////////////////////////////////////////////////
		const TranslationVector<>& location = objectUnderTest.getLocation();

		ASSERT_NEAR(1.0f, location.getX(), 0.0001f);
		ASSERT_NEAR(1.0f, location.getY(), 0.0001f);
		ASSERT_NEAR(1.0f, location.getZ(), 0.0001f);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::LinearPathWalker#stepBackward(const float) stepBackward(const float)}.
	 * </p>
	 */
	TEST_F(LinearPathWalkerTest, stepBackward)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::shared_ptr<const MockNode> mockNode1(new testing::NiceMock<MockNode>);
		std::shared_ptr<const MockNode> mockNode2(new testing::NiceMock<MockNode>);
		SimpleTransformationMatrix<> transformation1;
		SimpleTransformationMatrix<> transformation2;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(testing::ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(testing::ReturnRef(transformation2));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector<>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector<>(2.0f, 2.0f, 2.0f, 1.0f));
		LinearPathWalker objectUnderTest(path);
		objectUnderTest.stepForward(1.0f);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.stepBackward(0.5f);

		// Verify test results.
		// //////////////////////////////////////////////////
		const TranslationVector<>& location = objectUnderTest.getLocation();

		ASSERT_NEAR(1.2887f, location.getX(), 0.0001f);
		ASSERT_NEAR(1.2887f, location.getY(), 0.0001f);
		ASSERT_NEAR(1.2887f, location.getZ(), 0.0001f);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::LinearPathWalker#stepForward(const float) stepForward(const float)}.
	 * </p>
	 */
	TEST_F(LinearPathWalkerTest, stepForward)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::shared_ptr<const MockNode> mockNode1(new testing::NiceMock<MockNode>);
		std::shared_ptr<const MockNode> mockNode2(new testing::NiceMock<MockNode>);
		SimpleTransformationMatrix<> transformation1;
		SimpleTransformationMatrix<> transformation2;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(testing::ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(testing::ReturnRef(transformation2));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector<>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector<>(2.0f, 2.0f, 2.0f, 1.0f));
		LinearPathWalker objectUnderTest(path);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.stepForward(1.0f);

		// Verify test results.
		// //////////////////////////////////////////////////
		const TranslationVector<>& location = objectUnderTest.getLocation();

		ASSERT_NEAR(1.5774f, location.getX(), 0.0001f);
		ASSERT_NEAR(1.5774f, location.getY(), 0.0001f);
		ASSERT_NEAR(1.5774f, location.getZ(), 0.0001f);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::LinearPathWalker#stepForward(const float) stepForward(const float)}
	 * with the special condition that the walker is already at the end of the path.
	 * </p>
	 */
	TEST_F(LinearPathWalkerTest, stepForwardFromEnd)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::shared_ptr<const MockNode> mockNode1(new testing::NiceMock<MockNode>);
		std::shared_ptr<const MockNode> mockNode2(new testing::NiceMock<MockNode>);
		SimpleTransformationMatrix<> transformation1;
		SimpleTransformationMatrix<> transformation2;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(testing::ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(testing::ReturnRef(transformation2));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector<>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector<>(2.0f, 2.0f, 2.0f, 1.0f));
		LinearPathWalker objectUnderTest(path);
		objectUnderTest.stepForward(2.0f);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.stepForward(1.0f);

		// Verify test results.
		// //////////////////////////////////////////////////
		const TranslationVector<>& location = objectUnderTest.getLocation();

		ASSERT_NEAR(2.0f, location.getX(), 0.0001f);
		ASSERT_NEAR(2.0f, location.getY(), 0.0001f);
		ASSERT_NEAR(2.0f, location.getZ(), 0.0001f);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::LinearPathWalker#stepForward(const float) stepForward(const float)}
	 * with the special condition that the distance goes past the end of the path.
	 * </p>
	 */
	TEST_F(LinearPathWalkerTest, stepForwardPastEnd)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::shared_ptr<const MockNode> mockNode1(new testing::NiceMock<MockNode>);
		std::shared_ptr<const MockNode> mockNode2(new testing::NiceMock<MockNode>);
		SimpleTransformationMatrix<> transformation1;
		SimpleTransformationMatrix<> transformation2;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(testing::ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(testing::ReturnRef(transformation2));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector<>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector<>(2.0f, 2.0f, 2.0f, 1.0f));
		LinearPathWalker objectUnderTest(path);

		// Perform test.
		// //////////////////////////////////////////////////
		objectUnderTest.stepForward(2.0f);

		// Verify test results.
		// //////////////////////////////////////////////////
		const TranslationVector<>& location = objectUnderTest.getLocation();

		ASSERT_NEAR(2.0f, location.getX(), 0.0001f);
		ASSERT_NEAR(2.0f, location.getY(), 0.0001f);
		ASSERT_NEAR(2.0f, location.getZ(), 0.0001f);
	}

	/**
	 * <p>
	 * Unit test the methods {@link simplicity::LinearPathWalker#stepForward(const float) stepForward(const float)} and
	 * {@link simplicity::LinearPathWalker#stepBackward(const float) stepBackward(const float)} with the special
	 * condition that the distance to step is zero.
	 * </p>
	 */
	TEST_F(LinearPathWalkerTest, stepZeroDistance)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::shared_ptr<const MockNode> mockNode1(new testing::NiceMock<MockNode>);
		std::shared_ptr<const MockNode> mockNode2(new testing::NiceMock<MockNode>);
		SimpleTransformationMatrix<> transformation1;
		SimpleTransformationMatrix<> transformation2;

		vector<shared_ptr<const Node> > path;
		path.push_back(mockNode1);
		path.push_back(mockNode2);

		// Provide stub behaviour.
		// //////////////////////////////////////////////////
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(testing::ReturnRef(transformation1));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(testing::ReturnRef(transformation2));

		// Initialise the test environment.
		// //////////////////////////////////////////////////
		transformation1.translate(SimpleTranslationVector<>(1.0f, 1.0f, 1.0f, 1.0f));
		transformation2.translate(SimpleTranslationVector<>(2.0f, 2.0f, 2.0f, 1.0f));
		LinearPathWalker objectUnderTest(path);

		// Perform forward test.
		// //////////////////////////////////////////////////
		objectUnderTest.stepForward(0.0f);

		// Verify forward test results.
		// //////////////////////////////////////////////////
		const TranslationVector<>& forwardLocation = objectUnderTest.getLocation();

		ASSERT_EQ(1.0f, forwardLocation.getX());
		ASSERT_EQ(1.0f, forwardLocation.getY());
		ASSERT_EQ(1.0f, forwardLocation.getZ());

		// Perform backward test.
		// //////////////////////////////////////////////////
		objectUnderTest.stepBackward(0.0f);

		// Verify backward test results.
		// //////////////////////////////////////////////////
		const TranslationVector<>& backwardLocation = objectUnderTest.getLocation();

		ASSERT_EQ(1.0f, backwardLocation.getX());
		ASSERT_EQ(1.0f, backwardLocation.getY());
		ASSERT_EQ(1.0f, backwardLocation.getZ());
	}
}
