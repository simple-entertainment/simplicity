/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/lexical_cast.hpp>
using namespace boost;

#include "SimpleMatrixf44.h"

namespace simplicity
{

    SimpleMatrixf44::SimpleMatrixf44()
    {
        setArray(new float[CELLS_IN_MATRIX]);
        setLength(CELLS_IN_MATRIX);

        setIdentity();
    }

    SimpleMatrixf44::SimpleMatrixf44(float* const array)
    {
        setArray(array);
        setLength(CELLS_IN_MATRIX);
    }

    SimpleMatrixf44::~SimpleMatrixf44()
    {
    }

    float
    SimpleMatrixf44::getDeterminant()
    {
        float* array = getArray();

        float determinant = array[0] * ((array[5] * array[10] * array[15] + array[6] * array[11] * array[13] + array[7] * array[9] * array[14])
                - array[7] * array[10] * array[13] - array[5] * array[11] * array[14] - array[6] * array[9] * array[15]);

        determinant -= array[1] * ((array[4] * array[10] * array[15] + array[6] * array[11] * array[12] + array[7] * array[8] * array[14]) - array[7]
                * array[10] * array[12] - array[4] * array[11] * array[14] - array[6] * array[8] * array[15]);

        determinant += array[2] * ((array[4] * array[9] * array[15] + array[5] * array[11] * array[12] + array[7] * array[8] * array[13]) - array[7]
                * array[9] * array[12] - array[4] * array[11] * array[13] - array[5] * array[8] * array[15]);

        determinant -= array[3] * ((array[4] * array[9] * array[14] + array[5] * array[10] * array[12] + array[6] * array[8] * array[13]) - array[6]
                * array[9] * array[12] - array[4] * array[10] * array[13] - array[5] * array[8] * array[14]);

        return (determinant);
    }

    float
    SimpleMatrixf44::getDeterminant33(const float f00, const float f10, const float f20, const float f01, const float f11, const float f21,
            const float f02, const float f12, const float f22)
    {
        return (f00 * (f11 * f22 - f12 * f21) - f10 * (f01 * f22 - f02 * f21) + f20 * (f01 * f12 - f02 * f11));
    }

    void
    SimpleMatrixf44::invert() throw (SEInvalidOperationException)
    {
        float* array = getArray();
        float determinant = getDeterminant();

        if (determinant == 0.0f)
        {
            throw SEInvalidOperationException();
        }

        float invDeterminant = 1.0f / determinant;

        // Calculate determinants for each value in this matrix.
        float f00 = getDeterminant33(array[5], array[6], array[7], array[9], array[10], array[11], array[13], array[14], array[15]);
        float f01 = -getDeterminant33(array[4], array[6], array[7], array[8], array[10], array[11], array[12], array[14], array[15]);
        float f02 = getDeterminant33(array[4], array[5], array[7], array[8], array[9], array[11], array[12], array[13], array[15]);
        float f03 = -getDeterminant33(array[4], array[5], array[6], array[8], array[9], array[10], array[12], array[13], array[14]);

        float f10 = -getDeterminant33(array[1], array[2], array[3], array[9], array[10], array[11], array[13], array[14], array[15]);
        float f11 = getDeterminant33(array[0], array[2], array[3], array[8], array[10], array[11], array[12], array[14], array[15]);
        float f12 = -getDeterminant33(array[0], array[1], array[3], array[8], array[9], array[11], array[12], array[13], array[15]);
        float f13 = getDeterminant33(array[0], array[1], array[2], array[8], array[9], array[10], array[12], array[13], array[14]);

        float f20 = getDeterminant33(array[1], array[2], array[3], array[5], array[6], array[7], array[13], array[14], array[15]);
        float f21 = -getDeterminant33(array[0], array[2], array[3], array[4], array[6], array[7], array[12], array[14], array[15]);
        float f22 = getDeterminant33(array[0], array[1], array[3], array[4], array[5], array[7], array[12], array[13], array[15]);
        float f23 = -getDeterminant33(array[0], array[1], array[2], array[4], array[5], array[6], array[12], array[13], array[14]);

        float f30 = -getDeterminant33(array[1], array[2], array[3], array[5], array[6], array[7], array[9], array[10], array[11]);
        float f31 = getDeterminant33(array[0], array[2], array[3], array[4], array[6], array[7], array[8], array[10], array[11]);
        float f32 = -getDeterminant33(array[0], array[1], array[3], array[4], array[5], array[7], array[8], array[9], array[11]);
        float f33 = getDeterminant33(array[0], array[1], array[2], array[4], array[5], array[6], array[8], array[9], array[10]);

        // Transpose and divide by the determinant.
        array[0] = f00 * invDeterminant;
        array[1] = f10 * invDeterminant;
        array[2] = f20 * invDeterminant;
        array[3] = f30 * invDeterminant;
        array[4] = f01 * invDeterminant;
        array[5] = f11 * invDeterminant;
        array[6] = f21 * invDeterminant;
        array[7] = f31 * invDeterminant;
        array[8] = f02 * invDeterminant;
        array[9] = f12 * invDeterminant;
        array[10] = f22 * invDeterminant;
        array[11] = f32 * invDeterminant;
        array[12] = f03 * invDeterminant;
        array[13] = f13 * invDeterminant;
        array[14] = f23 * invDeterminant;
        array[15] = f33 * invDeterminant;
    }

    float*
    SimpleMatrixf44::multiply(SimpleMatrixf44* const leftMatrix, SimpleMatrixf44* const rightMatrix)
    {
        float* leftArray = leftMatrix->getArray();
        float* rightArray = rightMatrix->getArray();
        float* multArray = new float[CELLS_IN_MATRIX];

        float sum = 0.0f;

        // For every row in the left hand matrix.
        for (int row = 0; row < CELLS_IN_COLUMN; row++)
        {
            // For every column in the right hand matrix.
            for (int column = 0; column < CELLS_IN_ROW; column++)
            {
                // For every element in the current row of the left hand matrix and
                // every element in the current column of the right hand matrix.
                for (int element = 0; element < CELLS_IN_ROW; element++)
                {
                    // Add the product of the two to the value for the new
                    // matrix.
                    sum += leftArray[row + (element * CELLS_IN_COLUMN)] * rightArray[(column * CELLS_IN_ROW) + element];
                }

                multArray[(column * CELLS_IN_ROW) + row] = sum;
                sum = 0.0f;
            }
        }

        return (multArray);
    }

    void
    SimpleMatrixf44::multiplyLeft(Matrixf* const leftMatrix)
    {
        setArray(multiply(dynamic_cast<SimpleMatrixf44*>(leftMatrix), this));
    }

    Matrixf*
    SimpleMatrixf44::multiplyLeftCopy(Matrixf* const leftMatrix)
    {
        return (new SimpleMatrixf44(multiply(dynamic_cast<SimpleMatrixf44*>(leftMatrix), this)));
    }

    void
    SimpleMatrixf44::multiplyRight(Matrixf* const rightMatrix)
    {
        setArray(multiply(this, dynamic_cast<SimpleMatrixf44*>(rightMatrix)));
    }

    Matrixf*
    SimpleMatrixf44::multiplyRightCopy(Matrixf* const rightMatrix)
    {
        return (new SimpleMatrixf44(multiply(this, dynamic_cast<SimpleMatrixf44*>(rightMatrix))));
    }

    void
    SimpleMatrixf44::setIdentity()
    {
        float* array = getArray();

        array[0] = 1.0f;
        array[1] = 0.0f;
        array[2] = 0.0f;
        array[3] = 0.0f;

        array[4] = 0.0f;
        array[5] = 1.0f;
        array[6] = 0.0f;
        array[7] = 0.0f;

        array[8] = 0.0f;
        array[9] = 0.0f;
        array[10] = 1.0f;
        array[11] = 0.0f;

        array[12] = 0.0f;
        array[13] = 0.0f;
        array[14] = 0.0f;
        array[15] = 1.0f;
    }

    string
    SimpleMatrixf44::toString()
    {
        float* array = getArray();
        string matrixString = "";

        matrixString += "-------------------------\n";
        matrixString += "| " + lexical_cast<string> (array[0]) + " | " + lexical_cast<string> (array[4]) + " | " + lexical_cast<string> (array[8])
                + " | " + lexical_cast<string> (array[12]) + " |\n";
        matrixString += "-------------------------\n";
        matrixString += "| " + lexical_cast<string> (array[1]) + " | " + lexical_cast<string> (array[5]) + " | " + lexical_cast<string> (array[9])
                + " | " + lexical_cast<string> (array[13]) + " |\n";
        matrixString += "-------------------------\n";
        matrixString += "| " + lexical_cast<string> (array[2]) + " | " + lexical_cast<string> (array[6]) + " | " + lexical_cast<string> (array[10])
                + " | " + lexical_cast<string> (array[14]) + " |\n";
        matrixString += "-------------------------\n";
        matrixString += "| " + lexical_cast<string> (array[3]) + " | " + lexical_cast<string> (array[7]) + " | " + lexical_cast<string> (array[11])
                + " | " + lexical_cast<string> (array[15]) + " |\n";
        matrixString += "-------------------------\n";

        return (matrixString);
    }

    void
    SimpleMatrixf44::transpose()
    {
        float* array = getArray();
        float temp = -1;

        temp = array[1];
        array[1] = array[4];
        array[4] = temp;

        temp = array[2];
        array[2] = array[8];
        array[8] = temp;

        temp = array[3];
        array[3] = array[12];
        array[12] = temp;

        temp = array[6];
        array[6] = array[9];
        array[9] = temp;

        temp = array[7];
        array[7] = array[13];
        array[13] = temp;

        temp = array[11];
        array[11] = array[14];
        array[14] = temp;
    }
}
