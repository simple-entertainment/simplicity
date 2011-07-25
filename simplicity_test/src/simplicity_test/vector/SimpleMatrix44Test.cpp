/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleMatrix44Test.h"

using namespace simplicity;

namespace simplicity_test
{
  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleMatrix44.getDeterminant getDeterminant()}.
   * </p>
   */
  TEST_F(SimpleMatrix44Test, getDeterminant)
  {
    ASSERT_EQ(20.0f, fTestObject.getDeterminant());
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleMatrix44.invert invert()}.
   * </p>
   *
   * @throws SEInvalidOperationException Thrown by the method being unit tested.
   */
  TEST_F(SimpleMatrix44Test, invert)
  {
    fTestObject.invert();

    array<float, 16>& data = fTestObject.getData();

    ASSERT_EQ(-0.75f, data.at(0));
    ASSERT_EQ(0.5f, data.at(1));
    ASSERT_EQ(0.25f, data.at(2));
    ASSERT_EQ(0.0f, data.at(3));
    ASSERT_EQ(0.5f, data.at(4));
    ASSERT_EQ(-0.4f, data.at(5));
    ASSERT_EQ(0.1f, data.at(6));
    ASSERT_EQ(0.0f, data.at(7));
    ASSERT_EQ(0.25f, data.at(8));
    ASSERT_EQ(0.1f, data.at(9));
    ASSERT_EQ(-0.15f, data.at(10));
    ASSERT_EQ(0.0f, data.at(11));
    ASSERT_EQ(1.0f, data.at(12));
    ASSERT_EQ(-1.0f, data.at(13));
    ASSERT_EQ(-1.0f, data.at(14));
    ASSERT_EQ(1.0f, data.at(15));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleMatrix44.invert invert()} for the special condition where the
   * {@link simplicity::SimpleMatrix44 SimpleMatrix44} being tested has a determinant of 0.
   * </p>
   */
  TEST_F(SimpleMatrix44Test, invertDeterminant0)
  {
    array<float, 16>& data = fTestObject.getData();

    data.at(0) = 0.0f;
    data.at(4) = 0.0f;
    data.at(8) = 0.0f;
    data.at(12) = 0.0f;
    data.at(1) = 0.0f;
    data.at(5) = 0.0f;
    data.at(9) = 0.0f;
    data.at(13) = 0.0f;
    data.at(2) = 0.0f;
    data.at(6) = 0.0f;
    data.at(10) = 0.0f;
    data.at(14) = 0.0f;
    data.at(3) = 0.0f;
    data.at(7) = 0.0f;
    data.at(11) = 0.0f;
    data.at(15) = 0.0f;

    ASSERT_THROW(fTestObject.invert(), SEInvalidOperationException);
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleMatrix44.multiply multiply()}.
   * </p>
   */
  TEST_F(SimpleMatrix44Test, multiply)
  {
    SimpleMatrix44<float> otherMatrix;
    array<float, 16>& otherData = otherMatrix.getData();

    otherData.at(0) = 1.0f;
    otherData.at(4) = 2.0f;
    otherData.at(8) = 3.0f;
    otherData.at(12) = 4.0f;
    otherData.at(1) = 2.0f;
    otherData.at(5) = 1.0f;
    otherData.at(9) = 4.0f;
    otherData.at(13) = 3.0f;
    otherData.at(2) = 3.0f;
    otherData.at(6) = 4.0f;
    otherData.at(10) = 1.0f;
    otherData.at(14) = 2.0f;
    otherData.at(3) = 0.0f;
    otherData.at(7) = 0.0f;
    otherData.at(11) = 0.0f;
    otherData.at(15) = 1.0f;

    fTestObject.multiplyLeft(otherMatrix);

    array<float, 16>& data = fTestObject.getData();

    ASSERT_EQ(14.0f, data.at(0));
    ASSERT_EQ(16.0f, data.at(1));
    ASSERT_EQ(14.0f, data.at(2));
    ASSERT_EQ(0.0f, data.at(3));
    ASSERT_EQ(16.0f, data.at(4));
    ASSERT_EQ(21.0f, data.at(5));
    ASSERT_EQ(14.0f, data.at(6));
    ASSERT_EQ(0.0f, data.at(7));
    ASSERT_EQ(14.0f, data.at(8));
    ASSERT_EQ(14.0f, data.at(9));
    ASSERT_EQ(26.0f, data.at(10));
    ASSERT_EQ(0.0f, data.at(11));
    ASSERT_EQ(20.0f, data.at(12));
    ASSERT_EQ(22.0f, data.at(13));
    ASSERT_EQ(28.0f, data.at(14));
    ASSERT_EQ(1.0f, data.at(15));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleMatrix44.setIdentity setIdentity()}.
   * </p>
   */
  TEST_F(SimpleMatrix44Test, setIdentity)
  {
    fTestObject.setIdentity();

    array<float, 16>& data = fTestObject.getData();

    ASSERT_EQ(1.0f, data.at(0));
    ASSERT_EQ(0.0f, data.at(1));
    ASSERT_EQ(0.0f, data.at(2));
    ASSERT_EQ(0.0f, data.at(3));
    ASSERT_EQ(0.0f, data.at(4));
    ASSERT_EQ(1.0f, data.at(5));
    ASSERT_EQ(0.0f, data.at(6));
    ASSERT_EQ(0.0f, data.at(7));
    ASSERT_EQ(0.0f, data.at(8));
    ASSERT_EQ(0.0f, data.at(9));
    ASSERT_EQ(1.0f, data.at(10));
    ASSERT_EQ(0.0f, data.at(11));
    ASSERT_EQ(0.0f, data.at(12));
    ASSERT_EQ(0.0f, data.at(13));
    ASSERT_EQ(0.0f, data.at(14));
    ASSERT_EQ(1.0f, data.at(15));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleMatrix44.transpose transpose()}.
   * </p>
   */
  TEST_F(SimpleMatrix44Test, transpose)
  {
    fTestObject.transpose();

    array<float, 16>& data = fTestObject.getData();

    ASSERT_EQ(1.0f, data.at(0));
    ASSERT_EQ(2.0f, data.at(1));
    ASSERT_EQ(3.0f, data.at(2));
    ASSERT_EQ(4.0f, data.at(3));
    ASSERT_EQ(2.0f, data.at(4));
    ASSERT_EQ(1.0f, data.at(5));
    ASSERT_EQ(4.0f, data.at(6));
    ASSERT_EQ(3.0f, data.at(7));
    ASSERT_EQ(3.0f, data.at(8));
    ASSERT_EQ(4.0f, data.at(9));
    ASSERT_EQ(1.0f, data.at(10));
    ASSERT_EQ(2.0f, data.at(11));
    ASSERT_EQ(0.0f, data.at(12));
    ASSERT_EQ(0.0f, data.at(13));
    ASSERT_EQ(0.0f, data.at(14));
    ASSERT_EQ(1.0f, data.at(15));
  }
}
