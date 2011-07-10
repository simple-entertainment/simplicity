/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/math/constants/constants.hpp>
using namespace boost::math::constants;

#include <simplicity/vector/SimpleTransformationMatrix44.h>
#include <simplicity/vector/SimpleTranslationVector4.h>
using namespace simplicity;

#include "MockNode.h"
#include "SimpleNodeTest.h"

namespace simplicity_test
{
  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleNode#addChild(Node* const) addChild(Node* const)}.
   * </p>
   */
  TEST_F(SimpleNodeTest, addChild)
  {
    // Create dependencies.
    SimpleNode* child = new SimpleNode();

    // Perform test.
    fTestObject.addChild(child);

    // Verify test results.
    ASSERT_EQ(child, fTestObject.getChildren().at(0));
    ASSERT_EQ(&fTestObject, child->getParent());

    // Cleanup
    delete child;
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleNode#getAbsoluteTransformation() getAbsoluteTransformation()}.
   * </p>
   */
  TEST_F(SimpleNodeTest, getAbsoluteTransformation)
    {
      // Create dependencies.
      MockNode mockNode1;
      MockNode mockNode2;
      SimpleTransformationMatrix44<float> matrix1;
      matrix1.translate(new SimpleTranslationVector4<float>(0.0f, 10.0f, 0.0f, 1.0f));
      SimpleTransformationMatrix44<float> matrix2;
      matrix2.rotate(90.0f * pi<float>() / 180.0f, new SimpleTranslationVector4<float>(1.0f, 0.0f, 0.0f, 1.0f));
      SimpleTransformationMatrix44<float> matrix3;
      matrix3.multiplyLeft(&matrix1);
      matrix3.multiplyLeft(&matrix2);

      // Dictate correct behaviour.
      EXPECT_CALL(mockNode1, getTransformation()).WillRepeatedly(Return(&matrix1));
      EXPECT_CALL(mockNode1, getParent()).WillRepeatedly(Return(&mockNode2));
      EXPECT_CALL(mockNode2, getTransformation()).WillRepeatedly(Return(&matrix2));
      EXPECT_CALL(mockNode2, getParent()).WillRepeatedly(Return((Node*) NULL));

      // Initialise test environment.
      fTestObject.setParent(&mockNode1);

      dynamic_cast<SimpleMatrix44<float>*> (fTestObject.getAbsoluteTransformation())->getData();

      // Perform test - Verify test results.
      bool equal = false;
      if (matrix3.getData() == dynamic_cast<SimpleMatrix44<float>*> (fTestObject.getAbsoluteTransformation())->getData())
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
      SimpleNode * child = new SimpleNode();

      // Verify prerequisite state.
      ASSERT_FALSE(fTestObject.hasChildren());

      // Perform test.
      fTestObject.addChild(child);

      // Verify test results.
      ASSERT_TRUE(fTestObject.hasChildren());
    }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleNode#isAncestor(Node* const) isAncestor(Node* const)}.
   * </p>
   */
  TEST_F(SimpleNodeTest, isAncestor)
    {
      SimpleNode * child = new SimpleNode();
      fTestObject.addChild(child);

      SimpleNode * grandChild = new SimpleNode();
      child->addChild(grandChild);

      ASSERT_TRUE(child->isAncestor(&fTestObject));
      ASSERT_TRUE(grandChild->isAncestor(&fTestObject));

      ASSERT_FALSE(child->isAncestor(child));
      ASSERT_FALSE(child->isAncestor(grandChild));
    }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleNode#isSuccessor(Node* const) isSuccessor(Node* const)}.
   * </p>
   */
  TEST_F(SimpleNodeTest, isSuccessor)
    {
      SimpleNode * child = new SimpleNode();
      fTestObject.addChild(child);

      SimpleNode * grandChild = new SimpleNode();
      child->addChild(grandChild);

      ASSERT_TRUE(child->isSuccessor(grandChild));
      ASSERT_TRUE(fTestObject.isSuccessor(grandChild));

      ASSERT_FALSE(child->isSuccessor(child));
      ASSERT_FALSE(child->isSuccessor(&fTestObject));
    }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleNode#removeChild(Node* const) removeChild(Node* const)}.
   * </p>
   */
  TEST_F(SimpleNodeTest, removeChild)
    {
      SimpleNode * child = new SimpleNode();

      fTestObject.addChild(child);

      fTestObject.removeChild(child);

      vector<Node *> children = fTestObject.getChildren();
      vector<Node *>::iterator iterator = find(children.begin(), children.end(), child);
      ASSERT_TRUE(iterator == children.end());
      ASSERT_FALSE(child->getParent());
    }
}