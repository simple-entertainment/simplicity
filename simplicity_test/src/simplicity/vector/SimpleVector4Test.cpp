/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleVector4Test.h"

using namespace simplicity;

namespace simplicity
{
  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.add add()}.
   * </p>
   */TEST_F(SimpleVector4Test, add)
  {
    fTestObject.add(SimpleVector4<float> (4.0f, 2.0f, 7.5f, 3.9f));

    array<float, 4>& data = fTestObject.getData();

    ASSERT_EQ(5.0f, data.at(0));
    ASSERT_EQ(4.0f, data.at(1));
    ASSERT_EQ(10.5f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.crossProduct crossProduct()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, crossProduct)
  {
    fTestObject.crossProductRight(SimpleVector4<float>(3.0f, 2.0f, 1.0f, 0.0f));

    array<float, 4>& data = fTestObject.getData();

    ASSERT_EQ(-4.0f, data.at(0));
    ASSERT_EQ(8.0f, data.at(1));
    ASSERT_EQ(-4.0f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::.SimpleVectorf4.dotProduct dotProduct()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, dotProduct)
  {
    ASSERT_EQ(30.5f, fTestObject.dotProduct(SimpleVector4<float>(4.0f, 2.0f, 7.5f, 3.9f)));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.getLength getLength()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, getLength)
  {
    ASSERT_EQ(3.741657387f, fTestObject.getLength());
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.getLengthSquared getLengthSquared()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, getLengthSquared)
  {
    ASSERT_EQ(14.0f, fTestObject.getLengthSquared());
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.homogenize homogenize()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, homogenize)
  {
    array<float, 4>& data = fTestObject.getData();

    data.at(0) = 2.0f;
    data.at(1) = 4.0f;
    data.at(2) = 6.0f;
    data.at(3) = 2.0f;

    fTestObject.homogenize();

    ASSERT_EQ(1.0f, data.at(0));
    ASSERT_EQ(2.0f, data.at(1));
    ASSERT_EQ(3.0f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.homogenize homogenize()} for the special condition where this
   * {@link simplicity::SimpleVectorf4 SimpleVectorf4} is already homogenized.
   * </p>
   */
  TEST_F(SimpleVector4Test, homogenizeNotRequired)
  {
    fTestObject.homogenize();

    array<float, 4> data = fTestObject.getData();

    ASSERT_EQ(1.0f, data.at(0));
    ASSERT_EQ(2.0f, data.at(1));
    ASSERT_EQ(3.0f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.multiplyMatrixLeft multiplyMatrixLeft()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, multiplyMatrixLeft)
  {
    SimpleMatrix44<float> matrix;
    array<float, 16>& matrixData = matrix.getData();

    matrixData.at(0) = 1.0f;
    matrixData.at(4) = 2.0f;
    matrixData.at(8) = 3.0f;
    matrixData.at(12) = 4.0f;
    matrixData.at(1) = 2.0f;
    matrixData.at(5) = 1.0f;
    matrixData.at(9) = 4.0f;
    matrixData.at(13) = 3.0f;
    matrixData.at(2) = 3.0f;
    matrixData.at(6) = 4.0f;
    matrixData.at(10) = 1.0f;
    matrixData.at(14) = 2.0f;
    matrixData.at(3) = 0.0f;
    matrixData.at(7) = 0.0f;
    matrixData.at(11) = 0.0f;
    matrixData.at(15) = 1.0f;

    fTestObject.multiplyLeft(matrix);

    array<float, 4>& data = fTestObject.getData();

    ASSERT_EQ(18.0f, data.at(0));
    ASSERT_EQ(19.0f, data.at(1));
    ASSERT_EQ(16.0f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.multiplyMatrixRight multiplyMatrixRight()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, multiplyMatrixRight)
  {
    SimpleMatrix44<float> matrix;
    array<float, 16>& matrixData = matrix.getData();

    matrixData.at(0) = 1.0f;
    matrixData.at(4) = 2.0f;
    matrixData.at(8) = 3.0f;
    matrixData.at(12) = 4.0f;
    matrixData.at(1) = 2.0f;
    matrixData.at(5) = 1.0f;
    matrixData.at(9) = 4.0f;
    matrixData.at(13) = 3.0f;
    matrixData.at(2) = 3.0f;
    matrixData.at(6) = 4.0f;
    matrixData.at(10) = 1.0f;
    matrixData.at(14) = 2.0f;
    matrixData.at(3) = 0.0f;
    matrixData.at(7) = 0.0f;
    matrixData.at(11) = 0.0f;
    matrixData.at(15) = 1.0f;

    fTestObject.multiplyRight(matrix);

    array<float, 4>& data = fTestObject.getData();

    ASSERT_EQ(14.0f, data.at(0));
    ASSERT_EQ(16.0f, data.at(1));
    ASSERT_EQ(14.0f, data.at(2));
    ASSERT_EQ(17.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.multiplyVectorRight multiplyVectorRight()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, multiplyVectorRight)
  {
    SimpleVector4<float> otherVector;
    array<float, 4>& otherData = otherVector.getData();

    otherData.at(0) = 4.0f;
    otherData.at(1) = 5.0f;
    otherData.at(2) = 6.0f;
    otherData.at(3) = 1.0f;

    fTestObject.multiplyRight(otherVector);

    array<float, 4> data = fTestObject.getData();

    ASSERT_EQ(4.0f, data.at(0));
    ASSERT_EQ(10.0f, data.at(1));
    ASSERT_EQ(18.0f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.negate negate()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, negate)
  {
    fTestObject.negate();

    array<float, 4>& data = fTestObject.getData();

    ASSERT_EQ(-1.0f, data.at(0));
    ASSERT_EQ(-2.0f, data.at(1));
    ASSERT_EQ(-3.0f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.normalize normalize()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, normalize)
  {
    array<float, 4>& data = fTestObject.getData();

    data.at(0) = 0.0f;
    data.at(1) = 0.0f;
    data.at(2) = 3.0f;
    data.at(3) = 1.0f;

    fTestObject.normalize();

    ASSERT_EQ(0.0f, data.at(0));
    ASSERT_EQ(0.0f, data.at(1));
    ASSERT_EQ(1.0f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }

  /**
   * <p>
   * Unit test the method {@link simplicity::SimpleVectorf4.subtract subtract()}.
   * </p>
   */
  TEST_F(SimpleVector4Test, subtract)
  {
    fTestObject.subtractRight(SimpleVector4<float>(4.0f, 2.0f, 7.5f, 3.9f));

    array<float, 4>& data = fTestObject.getData();

    ASSERT_EQ(-3.0f, data.at(0));
    ASSERT_EQ(0.0f, data.at(1));
    ASSERT_EQ(-4.5f, data.at(2));
    ASSERT_EQ(1.0f, data.at(3));
  }
}
