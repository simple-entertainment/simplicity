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
#include <boost/math/constants/constants.hpp>

#include <simplicity/common/AddressEquals.h>
#include <simplicity/math/SimpleTransformationMatrix.h>
#include <simplicity/math/SimpleTranslationVector.h>
#include <simplicity/model/shape/Sphere.h>

#include "MockTreeNode.h"
#include "SimpleTreeNodeTest.h"

using namespace boost::math::constants;
using namespace std;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTreeNode#addChild(Node* const) addChild(Node* const)}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, addChild)
	{
		// Create dependencies.
		SimpleTreeNode child;

		// Perform test.
		objectUnderTest->addChild(child);

		// Verify test results.
		ASSERT_EQ(&child, &objectUnderTest->getChildren().at(0).get());
	}
	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTreeNode#copy() copy()}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, copy)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		Sphere component;
		SimpleTreeNode original;
		original.setComponent(&component);
		original.setId(1);

		SimpleTranslationVector<> translation;
		translation.setX(1.0f);
		translation.setY(2.0f);
		translation.setZ(3.0f);
		original.getTransformation().translate(translation);

		// Perform test.
		// //////////////////////////////////////////////////
		shared_ptr<TreeNode> objectUnderTest = dynamic_pointer_cast<TreeNode>(original.copy());

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(objectUnderTest->getChildren().empty());
		ASSERT_EQ(original.getComponent(), objectUnderTest->getComponent());
		ASSERT_TRUE(objectUnderTest->getConnectedNodes().empty());
		ASSERT_EQ(original.getId(), objectUnderTest->getId());
		ASSERT_EQ(NULL, objectUnderTest->getParent());
		ASSERT_EQ(original.getTransformation(), objectUnderTest->getTransformation());
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleTreeNode#operator=(const SimpleNode&) operator=(const SimpleNode&)}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, copyAssignment)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		Sphere component;
		SimpleTreeNode original;
		original.setComponent(&component);
		original.setId(1);

		SimpleTranslationVector<> translation;
		translation.setX(1.0f);
		translation.setY(2.0f);
		translation.setZ(3.0f);
		original.getTransformation().translate(translation);

		// Perform test.
		// //////////////////////////////////////////////////
		SimpleTreeNode objectUnderTest = original;

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(objectUnderTest.getChildren().empty());
		ASSERT_EQ(original.getComponent(), objectUnderTest.getComponent());
		ASSERT_TRUE(objectUnderTest.getConnectedNodes().empty());
		ASSERT_EQ(original.getId(), objectUnderTest.getId());
		ASSERT_EQ(NULL, objectUnderTest.getParent());
		ASSERT_EQ(original.getTransformation(), objectUnderTest.getTransformation());
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::SimpleTreeNode#SimpleNode(const SimpleNode&) SimpleNode(const SimpleNode&)}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, copyConstructor)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		Sphere component;
		SimpleTreeNode original;
		original.setComponent(&component);
		original.setId(1);

		SimpleTranslationVector<> translation;
		translation.setX(1.0f);
		translation.setY(2.0f);
		translation.setZ(3.0f);
		original.getTransformation().translate(translation);

		// Perform test.
		// //////////////////////////////////////////////////
		SimpleTreeNode objectUnderTest(original);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(objectUnderTest.getChildren().empty());
		ASSERT_EQ(original.getComponent(), objectUnderTest.getComponent());
		ASSERT_TRUE(objectUnderTest.getConnectedNodes().empty());
		ASSERT_EQ(original.getId(), objectUnderTest.getId());
		ASSERT_EQ(NULL, objectUnderTest.getParent());
		ASSERT_EQ(original.getTransformation(), objectUnderTest.getTransformation());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTreeNode#getAbsoluteTransformation() getAbsoluteTransformation()}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, getAbsoluteTransformation)
	{
		// Create dependencies.
		NiceMock<MockTreeNode> mockNode1;
		NiceMock<MockTreeNode> mockNode2;

		SimpleTransformationMatrix<> matrix1;
		SimpleTranslationVector<> translation(0.0f, 10.0f, 0.0f, 1.0f);
		matrix1.translate(translation);

		SimpleTransformationMatrix<> matrix2;
		SimpleTranslationVector<> rotateTranslation(1.0f, 0.0f, 0.0f, 1.0f);
		matrix2.rotate(90.0f * pi<float>() / 180.0f, rotateTranslation);

		SimpleTransformationMatrix<> matrix3;
		matrix3.multiply(matrix2);
		matrix3.multiply(matrix1);

		// Dictate correct behaviour.
		ON_CALL(mockNode1, getTransformation()).WillByDefault(ReturnRef(matrix1));
		ON_CALL(mockNode1, getParent()).WillByDefault(Return(&mockNode2));
		ON_CALL(mockNode2, getTransformation()).WillByDefault(ReturnRef(matrix2));
		ON_CALL(mockNode2, getParent()).WillByDefault(ReturnNull());

		// Initialise test environment.
		objectUnderTest->connectTo(mockNode1);

		// Perform test - Verify test results.
		bool equal = false;
		if (matrix3.getData() == objectUnderTest->getAbsoluteTransformation()->getData())
		{
			equal = true;
		}

		ASSERT_TRUE(equal);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTreeNode#hasChildren() hasChildren()}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, hasChildren)
	{
		// Create dependencies.
		SimpleTreeNode child;

		// Verify prerequisite state.
		ASSERT_FALSE(objectUnderTest->hasChildren());

		// Perform test.
		objectUnderTest->addChild(child);

		// Verify test results.
		ASSERT_TRUE(objectUnderTest->hasChildren());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTreeNode#isAncestor(Node* const) isAncestor(Node* const)}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, isAncestor)
	{
		SimpleTreeNode child;
		child.connectTo(*objectUnderTest);
		objectUnderTest->addChild(child);

		SimpleTreeNode grandChild;
		grandChild.connectTo(child);
		child.addChild(grandChild);

		ASSERT_TRUE(child.isAncestor(*objectUnderTest));
		ASSERT_TRUE(grandChild.isAncestor(*objectUnderTest));

		ASSERT_FALSE(child.isAncestor(child));
		ASSERT_FALSE(child.isAncestor(grandChild));
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTreeNode#isSuccessor(Node* const) isSuccessor(Node* const)}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, isSuccessor)
	{
		SimpleTreeNode child;
		child.connectTo(*objectUnderTest);
		objectUnderTest->addChild(child);

		SimpleTreeNode grandChild;
		grandChild.connectTo(child);
		child.addChild(grandChild);

		ASSERT_TRUE(child.isSuccessor(grandChild));
		ASSERT_TRUE(objectUnderTest->isSuccessor(grandChild));

		ASSERT_FALSE(child.isSuccessor(child));
		ASSERT_FALSE(child.isSuccessor(*objectUnderTest));
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleTreeNode#removeChild(Node* const) removeChild(Node* const)}.
	 * </p>
	 */
	TEST_F(SimpleTreeNodeTest, removeChild)
	{
		SimpleTreeNode child;

		objectUnderTest->addChild(child);

		objectUnderTest->removeChild(child);

		vector<reference_wrapper<TreeNode> > children = objectUnderTest->getChildren();
		vector<reference_wrapper<TreeNode> >::iterator iterator = find_if(children.begin(), children.end(),
			AddressEquals<TreeNode>(child));
		ASSERT_TRUE(iterator == children.end());
		ASSERT_FALSE(child.getParent());
	}
}
