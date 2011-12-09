/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/math/constants/constants.hpp>

#include <simplicity/math/SimpleTransformationMatrix44.h>
#include <simplicity/math/SimpleTranslationVector4.h>
#include <simplicity/scenegraph/MockNode.h>

#include "SimpleOpenGLCameraTest.h"

using namespace boost;
using namespace boost::math::constants;
using namespace testing;

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleJOGLCamera#getFrameHeight() getFrameHeight()}.
     * </p>
     */
    TEST_F(SimpleOpenGLCameraTest, getFrameHeight)
    {
      ASSERT_EQ(0.1f * 0.75f, fTestObject.getFrameHeight());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleJOGLCamera#getPickCamera() getPickCamera()}.
     * </p>
     */
    TEST_F(SimpleOpenGLCameraTest, getPickCamera)
    {
      Pick pick;
      pick.x = 0.05f;
      pick.y = 0.0375f;
      pick.width = 0.001f;
      pick.height = 0.00075f;

      shared_ptr<SimpleOpenGLCamera> pickCamera(dynamic_pointer_cast<SimpleOpenGLCamera> (fTestObject.getPickCamera(pick)));

      ASSERT_EQ(fTestObject.getFarClippingDistance(), pickCamera->getFarClippingDistance());
      ASSERT_EQ(fTestObject.getFrameAspectRatio(), pickCamera->getFrameAspectRatio());
      ASSERT_EQ(0.001f, pickCamera->getFrameWidth());
      ASSERT_EQ(0.0f, pickCamera->getFrameX());
      ASSERT_EQ(0.0f, pickCamera->getFrameY());
      ASSERT_EQ(fTestObject.getNearClippingDistance(), pickCamera->getNearClippingDistance());
      ASSERT_EQ(fTestObject.getNode(), pickCamera->getNode());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleOpenGLCamera#getTransformation() getTransformation()}.
     * </p>
     */
    TEST_F(SimpleOpenGLCameraTest, getTransformation)
    {
      shared_ptr<MockNode> mockNode(new MockNode);
      SimpleTransformationMatrix44<float> matrix;
      SimpleTranslationVector4<float> translation(1.0f, 0.0f, 0.0f, 1.0f);
      matrix.rotate(90.0f * pi<float>() / 180.0f, translation);

      fTestObject.setNode(mockNode);

      EXPECT_CALL(*mockNode, getAbsoluteTransformation()).WillRepeatedly(ReturnRef(matrix));

      SimpleTransformationMatrix44<float> invertedMatrix;
      invertedMatrix.multiplyRight(matrix);
      invertedMatrix.invert();

      ASSERT_TRUE(invertedMatrix == fTestObject.getTransformation());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleOpenGLCamera#getTransformation() getTransformation()} with the special condition that
     * the {@link simplicity::opengl::SimpleOpenGLCamera SimpleOpenGLCamera} being tested does not have a <code>Node</code>.
     * </p>
     */
    TEST_F(SimpleOpenGLCameraTest, getTransformationNoNode)
    {
      ASSERT_TRUE(fTestObject.getTransformation() == SimpleMatrix44<float> ());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleOpenGLCamera#setFrameHeight(float) setFrameHeight(float)}.
     * </p>
     */
    TEST_F(SimpleOpenGLCameraTest, setFrameHeight)
    {
      fTestObject.setFrameHeight(0.1f);

      ASSERT_EQ(1.0f, fTestObject.getFrameAspectRatio());
      ASSERT_EQ(0.1f, fTestObject.getFrameHeight());
    }
  }
}
