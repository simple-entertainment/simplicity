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
#include <simplicity/scene/MockNode.h>

#include "SimpleOpenGLLightTest.h"

using namespace boost::math::constants;
using namespace testing;

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Unit test the method {@link simplicity::opengl::SimpleOpenGLCamera#getTransformation() getTransformation()}.
     * </p>
     */
    TEST_F(SimpleOpenGLLightTest, getTransformation)
    {
      shared_ptr<MockNode> mockNode(new MockNode);
      SimpleTransformationMatrix44<> matrix;
      SimpleTranslationVector4<> translation(1.0f, 0.0f, 0.0f, 1.0f);
      matrix.rotate(90.0f * pi<float>() / 180.0f, translation);

      fTestObject.setNode(mockNode);

      // TODO Uncomment when unique_ptr is supported!
      //EXPECT_CALL(*mockNode, getAbsoluteTransformation()).WillRepeatedly(ReturnRef(matrix));

      //SimpleTransformationMatrix44<> invertedMatrix;
      //invertedMatrix.multiplyRight(matrix);
      //invertedMatrix.invert();

      //ASSERT_TRUE(invertedMatrix == fTestObject.getTransformation());
    }
  }
}
