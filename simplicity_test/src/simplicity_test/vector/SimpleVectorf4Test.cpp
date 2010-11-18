/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleVectorf4Test.h"

namespace simplicity_test
{
    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.add add()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, add)
    {
        fTestObject.add(new SimpleVectorf4(4.0f, 2.0f, 7.5f, 3.9f));

        float* array = fTestObject.getArray();

        ASSERT_EQ(5.0f, array[0]);
        ASSERT_EQ(4.0f, array[1]);
        ASSERT_EQ(10.5f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.crossProduct crossProduct()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, crossProduct)
    {
        fTestObject.crossProductRight(new SimpleVectorf4(3.0f, 2.0f, 1.0f, 0.0f));

        float* array = fTestObject.getArray();

        ASSERT_EQ(-4.0f, array[0]);
        ASSERT_EQ(8.0f, array[1]);
        ASSERT_EQ(-4.0f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::.SimpleVectorf4.dotProduct dotProduct()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, dotProduct)
    {
        ASSERT_EQ(30.5f, fTestObject.dotProduct(new SimpleVectorf4(4.0f, 2.0f, 7.5f, 3.9f)));
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.getLength getLength()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, getLength)
    {
        ASSERT_EQ(3.741657387f, fTestObject.getLength());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.getLengthSquared getLengthSquared()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, getLengthSquared)
    {
        ASSERT_EQ(14.0f, fTestObject.getLengthSquared());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.homogenize homogenize()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, homogenize)
    {
        float* array = fTestObject.getArray();

        array[0] = 2.0f;
        array[1] = 4.0f;
        array[2] = 6.0f;
        array[3] = 2.0f;

        fTestObject.homogenize();

        ASSERT_EQ(1.0f, array[0]);
        ASSERT_EQ(2.0f, array[1]);
        ASSERT_EQ(3.0f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.homogenize homogenize()} for the special condition where this
     * {@link simplicity::SimpleVectorf4 SimpleVectorf4} is already homogenized.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, homogenizeNotRequired)
    {
        fTestObject.homogenize();

        float* array = fTestObject.getArray();

        ASSERT_EQ(1.0f, array[0]);
        ASSERT_EQ(2.0f, array[1]);
        ASSERT_EQ(3.0f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.multiplyMatrixLeft multiplyMatrixLeft()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, multiplyMatrixLeft)
    {
        SimpleMatrixf44 matrix;
        float* matrixArray = matrix.getArray();

        matrixArray[0] = 1.0f;
        matrixArray[4] = 2.0f;
        matrixArray[8] = 3.0f;
        matrixArray[12] = 4.0f;
        matrixArray[1] = 2.0f;
        matrixArray[5] = 1.0f;
        matrixArray[9] = 4.0f;
        matrixArray[13] = 3.0f;
        matrixArray[2] = 3.0f;
        matrixArray[6] = 4.0f;
        matrixArray[10] = 1.0f;
        matrixArray[14] = 2.0f;
        matrixArray[3] = 0.0f;
        matrixArray[7] = 0.0f;
        matrixArray[11] = 0.0f;
        matrixArray[15] = 1.0f;

        // TODO Find out why this cast is required!
        fTestObject.multiplyLeft((Matrixf*) &matrix);

        float* array = fTestObject.getArray();

        ASSERT_EQ(18.0f, array[0]);
        ASSERT_EQ(19.0f, array[1]);
        ASSERT_EQ(16.0f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.multiplyMatrixRight multiplyMatrixRight()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, multiplyMatrixRight)
    {
        SimpleMatrixf44 matrix;
        float* matrixArray = matrix.getArray();

        matrixArray[0] = 1.0f;
        matrixArray[4] = 2.0f;
        matrixArray[8] = 3.0f;
        matrixArray[12] = 4.0f;
        matrixArray[1] = 2.0f;
        matrixArray[5] = 1.0f;
        matrixArray[9] = 4.0f;
        matrixArray[13] = 3.0f;
        matrixArray[2] = 3.0f;
        matrixArray[6] = 4.0f;
        matrixArray[10] = 1.0f;
        matrixArray[14] = 2.0f;
        matrixArray[3] = 0.0f;
        matrixArray[7] = 0.0f;
        matrixArray[11] = 0.0f;
        matrixArray[15] = 1.0f;

        // TODO Find out why this cast is required!
        fTestObject.multiplyRight((Matrixf*) &matrix);

        float* array = fTestObject.getArray();

        ASSERT_EQ(14.0f, array[0]);
        ASSERT_EQ(16.0f, array[1]);
        ASSERT_EQ(14.0f, array[2]);
        ASSERT_EQ(17.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.multiplyVectorRight multiplyVectorRight()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, multiplyVectorRight)
    {
        SimpleVectorf4 otherVector;
        float* otherArray = otherVector.getArray();

        otherArray[0] = 4.0f;
        otherArray[1] = 5.0f;
        otherArray[2] = 6.0f;
        otherArray[3] = 1.0f;

        fTestObject.multiplyRight(&otherVector);

        float* array = fTestObject.getArray();

        ASSERT_EQ(4.0f, array[0]);
        ASSERT_EQ(10.0f, array[1]);
        ASSERT_EQ(18.0f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.negate negate()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, negate)
    {
        fTestObject.negate();

        float* array = fTestObject.getArray();

        ASSERT_EQ(-1.0f, array[0]);
        ASSERT_EQ(-2.0f, array[1]);
        ASSERT_EQ(-3.0f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.normalize normalize()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, normalize)
    {
        float* array = fTestObject.getArray();

        array[0] = 0.0f;
        array[1] = 0.0f;
        array[2] = 3.0f;
        array[3] = 1.0f;

        fTestObject.normalize();

        array = fTestObject.getArray();

        ASSERT_EQ(0.0f, array[0]);
        ASSERT_EQ(0.0f, array[1]);
        ASSERT_EQ(1.0f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleVectorf4.subtract subtract()}.
     * </p>
     */
    TEST_F(SimpleVectorf4Test, subtract)
    {
        fTestObject.subtractRight(new SimpleVectorf4(4.0f, 2.0f, 7.5f, 3.9f));

        float* array = fTestObject.getArray();

        ASSERT_EQ(-3.0f, array[0]);
        ASSERT_EQ(0.0f, array[1]);
        ASSERT_EQ(-4.5f, array[2]);
        ASSERT_EQ(1.0f, array[3]);
    }
}
