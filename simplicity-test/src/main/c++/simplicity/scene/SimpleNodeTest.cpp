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

#include <simplicity/math/SimpleTransformationMatrix.h>
#include <simplicity/math/SimpleTranslationVector.h>

#include "MockNode.h"
#include "SimpleNodeTest.h"

using namespace boost::math::constants;
using namespace testing;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleNode#addChild(Node* const) addChild(Node* const)}.
	 * </p>
	 */
	TEST_F(SimpleNodeTest, addChild)
	{
		// Create dependencies.
		std::shared_ptr<SimpleNode> child(new SimpleNode);

		// Perform test.
		fTestObject->addChild(child);

		// Verify test results.
		ASSERT_EQ(child, fTestObject->getChildren().at(0));
		ASSERT_EQ(fTestObject, child->getParent());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleNode#getAbsoluteTransformation() getAbsoluteTransformation()}.
	 * </p>
	 */
	TEST_F(SimpleNodeTest, getAbsoluteTransformation)
	{
		// Create dependencies.
		std::shared_ptr<MockNode> mockNode1(new NiceMock<MockNode>);
		std::shared_ptr<MockNode> mockNode2(new NiceMock<MockNode>);

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
		ON_CALL(*mockNode1, getTransformation()).WillByDefault(ReturnRef(matrix1));
		ON_CALL(*mockNode1, getParent()).WillByDefault(Return(mockNode2));
		ON_CALL(*mockNode2, getTransformation()).WillByDefault(ReturnRef(matrix2));
		ON_CALL(*mockNode2, getParent()).WillByDefault(Return(std::shared_ptr<Node>()));

		// Initialise test environment.
		fTestObject->setParent(mockNode1);

		// Perform test - Verify test results.
		bool equal = false;
		if (matrix3.getData() == fTestObject->getAbsoluteTransformation()->getData())
		{
			equal = true;
		}

		ASSERT_TRUE(equal);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleNode#hasChildren() hasChildren()}.
	 * </p>
	 */
	TEST_F(SimpleNodeTest, hasChildren)
	{
		// Create dependencies.
		std::shared_ptr<Node> child(new SimpleNode);

		// Verify prerequisite state.
		ASSERT_FALSE(fTestObject->hasChildren());

		// Perform test.
		fTestObject->addChild(child);

		// Verify test results.
		ASSERT_TRUE(fTestObject->hasChildren());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleNode#isAncestor(Node* const) isAncestor(Node* const)}.
	 * </p>
	 */
	TEST_F(SimpleNodeTest, isAncestor)
	{
		std::shared_ptr<Node> child(new SimpleNode);
		fTestObject->addChild(child);

		std::shared_ptr<Node> grandChild(new SimpleNode);
		child->addChild(grandChild);

		ASSERT_TRUE(child->isAncestor(*fTestObject));
		ASSERT_TRUE(grandChild->isAncestor(*fTestObject));

		ASSERT_FALSE(child->isAncestor(*child));
		ASSERT_FALSE(child->isAncestor(*grandChild));
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleNode#isSuccessor(Node* const) isSuccessor(Node* const)}.
	 * </p>
	 */
	TEST_F(SimpleNodeTest, isSuccessor)
	{
		std::shared_ptr<Node> child(new SimpleNode);
		fTestObject->addChild(child);

		std::shared_ptr<Node> grandChild(new SimpleNode);
		child->addChild(grandChild);

		ASSERT_TRUE(child->isSuccessor(*grandChild));
		ASSERT_TRUE(fTestObject->isSuccessor(*grandChild));

		ASSERT_FALSE(child->isSuccessor(*child));
		ASSERT_FALSE(child->isSuccessor(*fTestObject));
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::SimpleNode#removeChild(Node* const) removeChild(Node* const)}.
	 * </p>
	 */
	TEST_F(SimpleNodeTest, removeChild)
	{
		std::shared_ptr<Node> child(new SimpleNode);

		fTestObject->addChild(child);

		fTestObject->removeChild(*child);

		vector <std::shared_ptr<Node> > children = fTestObject->getChildren();
		vector<std::shared_ptr<Node> >::iterator iterator = find(children.begin(), children.end(), child);
		ASSERT_TRUE(iterator == children.end());
		ASSERT_FALSE(child->getParent());
	}
}
