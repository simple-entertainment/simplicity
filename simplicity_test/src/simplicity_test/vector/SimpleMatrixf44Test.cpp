/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleMatrixf44Test.h"

namespace simplicity_test
{
    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleMatrixf44.getDeterminant getDeterminant()}.
     * </p>
     */
    TEST_F(SimpleMatrixf44Test, getDeterminant)
    {
        ASSERT_EQ(20.0f, fTestObject.getDeterminant());
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleMatrixf44.invert invert()}.
     * </p>
     *
     * @throws SEInvalidOperationException Thrown by the method being unit tested.
     */
    TEST_F(SimpleMatrixf44Test, invert)
    {
        fTestObject.invert();

        float* array = fTestObject.getArray();

        ASSERT_EQ(-0.75f, array[0]);
        ASSERT_EQ(0.5f, array[1]);
        ASSERT_EQ(0.25f, array[2]);
        ASSERT_EQ(0.0f, array[3]);
        ASSERT_EQ(0.5f, array[4]);
        ASSERT_EQ(-0.4f, array[5]);
        ASSERT_EQ(0.1f, array[6]);
        ASSERT_EQ(0.0f, array[7]);
        ASSERT_EQ(0.25f, array[8]);
        ASSERT_EQ(0.1f, array[9]);
        ASSERT_EQ(-0.15f, array[10]);
        ASSERT_EQ(0.0f, array[11]);
        ASSERT_EQ(1.0f, array[12]);
        ASSERT_EQ(-1.0f, array[13]);
        ASSERT_EQ(-1.0f, array[14]);
        ASSERT_EQ(1.0f, array[15]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleMatrixf44.invert invert()} for the special condition where the
     * {@link simplicity::SimpleMatrixf44 SimpleMatrixf44} being tested has a determinant of 0.
     * </p>
     */
    TEST_F(SimpleMatrixf44Test, invertDeterminant0)
    {
        float* array = fTestObject.getArray();

        array[0] = 0.0f;
        array[4] = 0.0f;
        array[8] = 0.0f;
        array[12] = 0.0f;
        array[1] = 0.0f;
        array[5] = 0.0f;
        array[9] = 0.0f;
        array[13] = 0.0f;
        array[2] = 0.0f;
        array[6] = 0.0f;
        array[10] = 0.0f;
        array[14] = 0.0f;
        array[3] = 0.0f;
        array[7] = 0.0f;
        array[11] = 0.0f;
        array[15] = 0.0f;

        ASSERT_THROW(fTestObject.invert(), SEInvalidOperationException);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleMatrixf44.multiply multiply()}.
     * </p>
     */
    TEST_F(SimpleMatrixf44Test, multiply)
    {
        SimpleMatrixf44 otherMatrix;
        float* otherArray = otherMatrix.getArray();

        otherArray[0] = 1.0f;
        otherArray[4] = 2.0f;
        otherArray[8] = 3.0f;
        otherArray[12] = 4.0f;
        otherArray[1] = 2.0f;
        otherArray[5] = 1.0f;
        otherArray[9] = 4.0f;
        otherArray[13] = 3.0f;
        otherArray[2] = 3.0f;
        otherArray[6] = 4.0f;
        otherArray[10] = 1.0f;
        otherArray[14] = 2.0f;
        otherArray[3] = 0.0f;
        otherArray[7] = 0.0f;
        otherArray[11] = 0.0f;
        otherArray[15] = 1.0f;

        fTestObject.multiplyLeft(&otherMatrix);

        float* array = fTestObject.getArray();

        ASSERT_EQ(14.0f, array[0]);
        ASSERT_EQ(16.0f, array[1]);
        ASSERT_EQ(14.0f, array[2]);
        ASSERT_EQ(0.0f, array[3]);
        ASSERT_EQ(16.0f, array[4]);
        ASSERT_EQ(21.0f, array[5]);
        ASSERT_EQ(14.0f, array[6]);
        ASSERT_EQ(0.0f, array[7]);
        ASSERT_EQ(14.0f, array[8]);
        ASSERT_EQ(14.0f, array[9]);
        ASSERT_EQ(26.0f, array[10]);
        ASSERT_EQ(0.0f, array[11]);
        ASSERT_EQ(20.0f, array[12]);
        ASSERT_EQ(22.0f, array[13]);
        ASSERT_EQ(28.0f, array[14]);
        ASSERT_EQ(1.0f, array[15]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleMatrixf44.setIdentity setIdentity()}.
     * </p>
     */
    TEST_F(SimpleMatrixf44Test, setIdentity)
    {
        fTestObject.setIdentity();

        float* array = fTestObject.getArray();

        ASSERT_EQ(1.0f, array[0]);
        ASSERT_EQ(0.0f, array[1]);
        ASSERT_EQ(0.0f, array[2]);
        ASSERT_EQ(0.0f, array[3]);
        ASSERT_EQ(0.0f, array[4]);
        ASSERT_EQ(1.0f, array[5]);
        ASSERT_EQ(0.0f, array[6]);
        ASSERT_EQ(0.0f, array[7]);
        ASSERT_EQ(0.0f, array[8]);
        ASSERT_EQ(0.0f, array[9]);
        ASSERT_EQ(1.0f, array[10]);
        ASSERT_EQ(0.0f, array[11]);
        ASSERT_EQ(0.0f, array[12]);
        ASSERT_EQ(0.0f, array[13]);
        ASSERT_EQ(0.0f, array[14]);
        ASSERT_EQ(1.0f, array[15]);
    }

    /**
     * <p>
     * Unit test the method {@link simplicity::SimpleMatrixf44.transpose transpose()}.
     * </p>
     */
    TEST_F(SimpleMatrixf44Test, transpose)
    {
        fTestObject.transpose();

        float* array = fTestObject.getArray();

        ASSERT_EQ(1.0f, array[0]);
        ASSERT_EQ(2.0f, array[1]);
        ASSERT_EQ(3.0f, array[2]);
        ASSERT_EQ(4.0f, array[3]);
        ASSERT_EQ(2.0f, array[4]);
        ASSERT_EQ(1.0f, array[5]);
        ASSERT_EQ(4.0f, array[6]);
        ASSERT_EQ(3.0f, array[7]);
        ASSERT_EQ(3.0f, array[8]);
        ASSERT_EQ(4.0f, array[9]);
        ASSERT_EQ(1.0f, array[10]);
        ASSERT_EQ(2.0f, array[11]);
        ASSERT_EQ(0.0f, array[12]);
        ASSERT_EQ(0.0f, array[13]);
        ASSERT_EQ(0.0f, array[14]);
        ASSERT_EQ(1.0f, array[15]);
    }
}
