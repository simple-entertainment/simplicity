/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleTranslationVector4Test.h"

namespace simplicity
{
  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleTranslationVector4.translateX translateX()}.
   * </p>
   */
  TEST_F(SimpleTranslationVector4Test, translateX)
  {
    fTestObject.setX(1.0f);
    fTestObject.translateX(1.0f);

    ASSERT_EQ(2.0f, fTestObject.getX());
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleTranslationVector4.translateY translateY()}.
   * </p>
   */TEST_F(SimpleTranslationVector4Test, translateY)
  {
    fTestObject.setY(1.0f);
    fTestObject.translateY(1.0f);

    ASSERT_EQ(2.0f, fTestObject.getY());
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleTranslationVector4.translateZ translateZ()}.
   * </p>
   */TEST_F(SimpleTranslationVector4Test, translateZ)
  {
    fTestObject.setZ(1.0f);
    fTestObject.translateZ(1.0f);

    ASSERT_EQ(2.0f, fTestObject.getZ());
  }
}
