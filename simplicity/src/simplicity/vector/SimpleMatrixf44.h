/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEMATRIXF44_H_
#define SIMPLEMATRIXF44_H_

#include <string>
using namespace std;

#include "ArrayBackedObjectf.h"
#include "Matrixf.h"

namespace simplicity
{
    /**
     * <p>
     * A 4x4 dimensional matrix that stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleMatrixf44 : public ArrayBackedObjectf, public virtual Matrixf
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>SimpleMatrixf44</code>.
             * </p>
             *
             * <p>
             * The <code>SimpleMatrixf44</code> is initialised as an identity matrix.
             * </p>
             */
            SimpleMatrixf44();

            /**
             * <p>
             * Creates an instance of <code>SimpleMatrixf44</code>.
             * </p>
             *
             * <p>
             * The <code>SimpleMatrixf44</code> is initialised to the contents of the array given.
             * </p>
             *
             * @param array An array containing the initial elements for this <code>SimpleMatrixf44</code>.
             */
            SimpleMatrixf44(float* const array);

            /**
             * <p>
             * Disposes of an instance of <code>SimpleMatrixf44</code>.
             * </p>
             */
            virtual
            ~SimpleMatrixf44();

            float
            getDeterminant();

            /**
             * <p>
             * NOTE: This method uses Cramer's Rule to compute the inverse (computes many determinants). Gaussian Elimination could be a more efficient means
             * of computing the inverse.
             * </p>
             *
             * @throws SEInvalidOperationException Thrown if this <code>SimpleMatrixf44</code> has a determinant of 0.
             */
            void
            invert() throw (SEInvalidOperationException);

            void
            multiplyLeft(Matrixf* const leftMatrix);

            Matrixf*
            multiplyLeftCopy(Matrixf* const leftMatrix);

            void
            multiplyRight(Matrixf* const rightMatrix);

            Matrixf*
            multiplyRightCopy(Matrixf* const rightMatrix);

            void
            setIdentity();

            /**
             * <p>
             * Retrieves a textual representation of this <code>SimpleMatrixf44</code> in the following format.
             * </p>
             *
             * <pre>
             * ----------------
             *  x | x | x | x |
             * ----------------
             *  x | x | x | x |
             * ----------------
             *  x | x | x | x |
             * ----------------
             *  x | x | x | x |
             * ----------------
             * </pre>
             *
             * @return A textual representation of this <code>SimpleMatrixf44</code>.
             */
            string
            toString();

            void
            transpose();

        private:
            /**
             * <p>
             * The number of cells in a column of this 4x4 matrix.
             * </p>
             */
            static const int CELLS_IN_COLUMN = 4;

            /**
             * <p>
             * The number of cells in this 4x4 matrix.
             * </p>
             */
            static const int CELLS_IN_MATRIX = 16;

            /**
             * <p>
             * The number of cells in a row of this 4x4 matrix.
             * </p>
             */
            static const int CELLS_IN_ROW = 4;

            /**
             * <p>
             * Retrieves the determinant of a 3x3 column-major matrix. The matrix is formatted as follows:
             * </p>
             *
             * <pre>
             * -------------------
             * | f00 | f10 | f20 |
             * -------------------
             * | f01 | f11 | f21 |
             * -------------------
             * | f02 | f12 | f22 |
             * -------------------
             * </pre>
             *
             * @param f00 An element of the 3x3 matrix.
             * @param f10 An element of the 3x3 matrix.
             * @param f20 An element of the 3x3 matrix.
             * @param f01 An element of the 3x3 matrix.
             * @param f11 An element of the 3x3 matrix.
             * @param f21 An element of the 3x3 matrix.
             * @param f02 An element of the 3x3 matrix.
             * @param f12 An element of the 3x3 matrix.
             * @param f22 An element of the 3x3 matrix.
             *
             * @return The determinant of a 3x3 column-major matrix.
             */
            float
            getDeterminant33(const float f00, const float f10, const float f20, const float f01, const float f11, const float f21, const float f02,
                    const float f12, const float f22);

            /**
             * <p>
             * Multiplies the <code>SimpleMatrixf44</code>s given.
             * </p>
             *
             * @param leftMatrix The <code>SimpleMatrixf44</code> to be placed on the left hand side of the equation.
             * @param rightMatrix The <code>SimpleMatrixf44</code> to be placed on the right hand side of the equation.
             *
             * @return An array that contains the result of the multiplication.
             */
            float*
            multiply(SimpleMatrixf44* const leftMatrix, SimpleMatrixf44* const rightMatrix);
    };
}

#endif /* SIMPLEMATRIXF44_H_ */
