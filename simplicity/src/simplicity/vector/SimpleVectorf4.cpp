/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <math.h>

#include <boost/lexical_cast.hpp>
using namespace boost;

#include "SimpleVectorf4.h"

namespace simplicity
{
    SimpleVectorf4::SimpleVectorf4()
    {
        float* array = new float[CELLS_IN_VECTOR];

        array[0] = 0.0f;
        array[1] = 0.0f;
        array[2] = 0.0f;
        array[3] = 1.0f;

        setArray(array);
        setLength(CELLS_IN_VECTOR);
    }

    SimpleVectorf4::SimpleVectorf4(const float f0, const float f1, const float f2, const float f3)
    {
        float* array = new float[CELLS_IN_VECTOR];

        array[0] = f0;
        array[1] = f1;
        array[2] = f2;
        array[3] = f3;

        setArray(array);
        setLength(CELLS_IN_VECTOR);
    }

    SimpleVectorf4::SimpleVectorf4(float* const array)
    {
        setArray(array);
        setLength(CELLS_IN_VECTOR);
    }

    SimpleVectorf4::~SimpleVectorf4()
    {
    }

    float*
    SimpleVectorf4::add(SimpleVectorf4* const leftVector, SimpleVectorf4* const rightVector)
    {
        float* leftArray = leftVector->getArray();
        float* rightArray = rightVector->getArray();
        float* addArray = new float[CELLS_IN_VECTOR];

        addArray[0] = leftArray[0] + rightArray[0];
        addArray[1] = leftArray[1] + rightArray[1];
        addArray[2] = leftArray[2] + rightArray[2];
        addArray[3] = 1.0f;

        return (addArray);
    }

    void
    SimpleVectorf4::add(Vectorf* const vector)
    {
        setArray(add(this, dynamic_cast<SimpleVectorf4*>(vector)));
    }

    Vectorf*
    SimpleVectorf4::addCopy(Vectorf* const vector)
    {
        return (new SimpleVectorf4(add(this, dynamic_cast<SimpleVectorf4*>(vector))));
    }

    float*
    SimpleVectorf4::crossProduct(SimpleVectorf4* const leftVector, SimpleVectorf4* const rightVector)
    {
        float* leftArray = leftVector->getArray();
        float* rightArray = rightVector->getArray();
        float* crossArray = new float[CELLS_IN_VECTOR];

        crossArray[0] = leftArray[1] * rightArray[2] - leftArray[2] * rightArray[1];
        crossArray[1] = leftArray[2] * rightArray[0] - leftArray[0] * rightArray[2];
        crossArray[2] = leftArray[0] * rightArray[1] - leftArray[1] * rightArray[0];
        crossArray[3] = 1.0f;

        return (crossArray);
    }

    void
    SimpleVectorf4::crossProductRight(Vectorf* const vector)
    {
        setArray(crossProduct(this, dynamic_cast<SimpleVectorf4*>(vector)));
    }

    Vectorf*
    SimpleVectorf4::crossProductRightCopy(Vectorf* const vector)
    {
        return (new SimpleVectorf4(crossProduct(this, dynamic_cast<SimpleVectorf4*>(vector))));
    }

    float
    SimpleVectorf4::dotProduct(Vectorf* const vector)
    {
        float* firstArray = getArray();
        float* secondArray = (dynamic_cast<SimpleVectorf4*>(vector))->getArray();
        float dot = 0.0f;

        for (int index = 0; index < 3; index++)
        {
            dot += firstArray[index] * secondArray[index];
        }

        return (dot);
    }

    float
    SimpleVectorf4::getLength()
    {
        return (sqrt(getLengthSquared()));
    }

    float
    SimpleVectorf4::getLengthSquared()
    {
        float* array = getArray();

        return (array[0] * array[0] + array[1] * array[1] + array[2] * array[2]);
    }

    void
    SimpleVectorf4::homogenize()
    {
        float* array = getArray();

        if (array[3] == 1.0f)
        {
            return;
        }

        array[0] = array[0] / array[3];
        array[1] = array[1] / array[3];
        array[2] = array[2] / array[3];
        array[3] = 1.0f;
    }

    float*
    SimpleVectorf4::multiply(SimpleVectorf4* const leftVector, SimpleVectorf4* const rightVector)
    {
        float* leftArray = leftVector->getArray();
        float* rightArray = rightVector->getArray();
        float* multArray = new float[CELLS_IN_VECTOR];

        multArray[0] = leftArray[0] * rightArray[0];
        multArray[1] = leftArray[1] * rightArray[1];
        multArray[2] = leftArray[2] * rightArray[2];
        multArray[3] = 1.0f;

        return (multArray);
    }

    void
    SimpleVectorf4::multiplyLeft(Matrixf* const matrix)
    {
        setArray(multiplyLeft(dynamic_cast<SimpleMatrixf44*>(matrix)));
    }

    float*
    SimpleVectorf4::multiplyLeft(SimpleMatrixf44* const matrix)
    {
        float* mArray = matrix->getArray();
        float* vArray = getArray();
        float* multArray = new float[CELLS_IN_VECTOR];

        float sum = 0.0f;

        // For every row in the matrix.
        for (int row = 0; row < CELLS_IN_VECTOR; row++)
        {
            // For every element in the vector and every element in the current
            // row of the matrix.
            for (int element = 0; element < CELLS_IN_VECTOR; element++)
            {
                // Add the product of the two to the value for the new vector.
                sum += mArray[row + (element * CELLS_IN_VECTOR)] * vArray[element];
            }

            multArray[row] = sum;
            sum = 0.0f;
        }

        return (multArray);
    }

    Vectorf*
    SimpleVectorf4::multiplyLeftCopy(Matrixf* const matrix)
    {
        return (new SimpleVectorf4(multiplyLeft(dynamic_cast<SimpleMatrixf44*>(matrix))));
    }

    void
    SimpleVectorf4::multiplyRight(Matrixf* const matrix)
    {
        setArray(multiplyRight(dynamic_cast<SimpleMatrixf44*>(matrix)));
    }

    float*
    SimpleVectorf4::multiplyRight(SimpleMatrixf44* const matrix)
    {
        float* vArray = getArray();
        float* mArray = matrix->getArray();
        float* multArray = new float[CELLS_IN_VECTOR];

        float sum = 0.0f;

        // For every column in the matrix.
        for (int column = 0; column < CELLS_IN_VECTOR; column++)
        {
            // For every element in the vector and every element in the current
            // column of the matrix.
            for (int element = 0; element < CELLS_IN_VECTOR; element++)
            {
                // Add the product of the two to the value for the new vector.
                sum += vArray[element] * mArray[(column * CELLS_IN_VECTOR) + element];
            }

            multArray[column] = sum;
            sum = 0.0f;
        }

        return (multArray);
    }

    void
    SimpleVectorf4::multiplyRight(Vectorf* const vector)
    {
        setArray(multiply(this, dynamic_cast<SimpleVectorf4*>(vector)));
    }

    Vectorf*
    SimpleVectorf4::multiplyRightCopy(Matrixf* const matrix)
    {
        return (new SimpleVectorf4(multiplyRight(dynamic_cast<SimpleMatrixf44*>(matrix))));
    }

    Vectorf*
    SimpleVectorf4::multiplyRightCopy(Vectorf* const vector)
    {
        return (new SimpleVectorf4(multiply(this, dynamic_cast<SimpleVectorf4*>(vector))));
    }

    void
    SimpleVectorf4::negate()
    {
        scale(-1.0f);
    }

    void
    SimpleVectorf4::normalize()
    {
        float* array = getArray();

        float sum = array[0] + array[1] + array[2];

        scale(1.0f / sum);
    }

    void
    SimpleVectorf4::scale(const float scalar)
    {
        float* array = getArray();

        array[0] = array[0] * scalar;
        array[1] = array[1] * scalar;
        array[2] = array[2] * scalar;
    }

    float*
    SimpleVectorf4::subtract(SimpleVectorf4* const leftVector, SimpleVectorf4* const rightVector)
    {
        float* leftArray = leftVector->getArray();
        float* rightArray = rightVector->getArray();
        float* subArray = new float[CELLS_IN_VECTOR];

        subArray[0] = leftArray[0] - rightArray[0];
        subArray[1] = leftArray[1] - rightArray[1];
        subArray[2] = leftArray[2] - rightArray[2];
        subArray[3] = 1.0f;

        return (subArray);
    }

    void
    SimpleVectorf4::subtractRight(Vectorf* const vector)
    {
        setArray(subtract(this, dynamic_cast<SimpleVectorf4*>(vector)));
    }

    Vectorf*
    SimpleVectorf4::subtractRightCopy(Vectorf* const vector)
    {
        return (new SimpleVectorf4(subtract(this, dynamic_cast<SimpleVectorf4*>(vector))));
    }

    string
    SimpleVectorf4::toString()
    {
        float* array = getArray();
        string vectorString = "";

        vectorString += "-------------------------\n";
        vectorString += "| " + lexical_cast<string> (array[0]) + " | " + lexical_cast<string> (array[1]) + " | " + lexical_cast<string> (array[2])
                + " | " + lexical_cast<string> (array[3]) + " |\n";
        vectorString += "-------------------------\n";

        return (vectorString);
    }
}
