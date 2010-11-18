/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEVECTORF4_H_
#define SIMPLEVECTORF4_H_

#include <string>
using namespace std;

#include "ArrayBackedObjectf.h"
#include "SimpleMatrixf44.h"
#include "Vectorf.h"

namespace simplicity
{
    /**
     * <p>
     * A 4 dimensional vector that stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class SimpleVectorf4 : public ArrayBackedObjectf, public virtual Vectorf
    {
        public:
            /**
             * <p>
             * Creates an instance of <code>SimpleVectorf4</code>.
             * </p>
             *
             * <p>
             * The <code>SimpleVectorf4</code> is initialised to <code>(0.0f, 0.0f, 0.0f, 1.0f)</code>.
             * </p>
             */
            SimpleVectorf4();

            /**
             * <p>
             * Creates an instance of <code>SimpleVectorf4</code>.
             * </p>
             *
             * <p>
             * The <code>SimpleVectorf4</code> is initialised to the components given.
             * </p>
             *
             * @param f0 The first element of this <code>SimpleVectorf4</code>.
             * @param f1 The second element of this <code>SimpleVectorf4</code>.
             * @param f2 The third element of this <code>SimpleVectorf4</code>.
             * @param f3 The fourth element of this <code>SimpleVectorf4</code>.
             */
            SimpleVectorf4(const float f0, const float f1, const float f2, const float f3);

            /**
             * <p>
             * Creates an instance of <code>SimpleVectorf4</code>.
             * </p>
             *
             * <p>
             * The <code>SimpleVectorf4</code> is initialised to the contents of the array given.
             * </p>
             *
             * <p>
             * This <code>SimpleVectorf4</code> will assume ownership of the given array.
             * </p>
             *
             * @param array An array containing the initial elements of this <code>SimpleVectorf4</code>.
             */
            SimpleVectorf4(float* const array);

            virtual
            ~SimpleVectorf4();

            void
            add(Vectorf* const vector);

            Vectorf*
            addCopy(Vectorf* const vector);

            void
            crossProductRight(Vectorf* const vector);

            Vectorf*
            crossProductRightCopy(Vectorf* const vector);

            float
            dotProduct(Vectorf* const vector);

            float
            getLength();

            float
            getLengthSquared();

            void
            homogenize();

            void
            multiplyLeft(Matrixf* const matrix);

            Vectorf*
            multiplyLeftCopy(Matrixf* const matrix);

            void
            multiplyRight(Matrixf* const matrix);

            void
            multiplyRight(Vectorf* const vector);

            Vectorf*
            multiplyRightCopy(Matrixf* const matrix);

            Vectorf*
            multiplyRightCopy(Vectorf* const vector);

            void
            negate();

            void
            normalize();

            void
            scale(const float scalar);

            void
            subtractRight(Vectorf* const vector);

            Vectorf*
            subtractRightCopy(Vectorf* const vector);

            /**
             * <p>
             * Retrieves a textual representation of this <code>SimpleVectorf4</code> in the following format.
             * </p>
             *
             * <pre>
             * ----------------
             *  x | y | z | w |
             * ----------------
             * </pre>
             *
             * @return A textual representation of this <code>SimpleVectorf4</code>.
             */
            string
            toString();

        private:
            /**
             * <p>
             * The number of cells in this vector.
             * </p>
             */
            static const int CELLS_IN_VECTOR = 4;

            /**
             * <p>
             * Adds the <code>SimpleVectorf</code> given to this <code>SimpleVectorf</code>.
             * <p>
             *
             * <p>
             * This method assumes both <code>SimpleVectorf</code>s to be homogenised.
             * </p>
             *
             * @param leftVector The <code>SimpleVectorf4</code> to be placed on the left hand side of the equation.
             * @param rightVector The <code>SimpleVectorf4</code> to be placed on the right hand side of the equation.
             *
             * @return An array that contains the result of the addition.
             */
            float*
            add(SimpleVectorf4* const leftVector, SimpleVectorf4* const rightVector);

            /**
             * <p>
             * Performs a cross product of the <code>SimpleVectorf4</code>s given.
             * </p>
             *
             * <p>
             * This method assumes both <code>SimpleVectorf4</code>s to be homogenised.
             * </p>
             *
             * @param leftVector The <code>SimpleVectorf4</code> to be placed on the left hand side of the equation.
             * @param rightVector The <code>SimpleVectorf4</code> to be placed on the right hand side of the equation.
             *
             * @return An array that contains the result of the cross product.
             */
            float*
            crossProduct(SimpleVectorf4* const leftVector, SimpleVectorf4* const rightVector);

            /**
             * <p>
             * Multiplies the <code>SimpleVectorf4</code>s given.
             * </p>
             *
             * <p>
             * This method assumes both <code>SimpleVectorf4</code>s to be homogenised.
             * </p>
             *
             * @param leftVector The <code>SimpleVectorf4</code> to be placed on the left hand side of the equation.
             * @param rightVector The <code>SimpleVectorf4</code> to be placed on the right hand side of the equation.
             *
             * @return An array that contains the result of the multiplication.
             */
            float*
            multiply(SimpleVectorf4* const leftVector, SimpleVectorf4* const rightVector);

            /**
             * <p>
             * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This <code>Vectorf</code> is treated as a
             * column vector and multiplied as follows:
             * </p>
             *
             * <pre>
             *   -----------------     -----
             *   | x | x | x | x |  *  | x |
             *   -----------------     -----
             *   | x | x | x | x |     | x |
             *   -----------------     -----
             *   | x | x | x | x |     | x |
             *   -----------------     -----
             *   | x | x | x | x |     | x |
             *   -----------------     -----
             * </pre>
             *
             * @param matrix The <code>SimpleMatrixf44</code> to be multiplied.
             *
             * @return An array that contains the result of the multiplication.
             */
            float*
            multiplyLeft(SimpleMatrixf44* const matrix);

            /**
             * <p>
             * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This <code>Vectorf</code> is treated as a
             * row vector and multiplied as follows:
             * </p>
             *
             * <pre>
             * -----------------     -----------------
             * | x | x | x | x |  *  | x | x | x | x |
             * -----------------     -----------------
             *                       | x | x | x | x |
             *                       -----------------
             *                       | x | x | x | x |
             *                       -----------------
             *                       | x | x | x | x |
             *                       -----------------
             * </pre>
             *
             * @param matrix The <code>SimpleMatrixf44</code> to be multiplied.
             *
             * @return An array that contains the result of the multiplication.
             */
            float*
            multiplyRight(SimpleMatrixf44* const matrix);

            /**
             * <p>
             * Performs a subtraction of the <code>SimpleVectorf</code>s given from this <code>Vectorf</code>.
             * </p>
             *
             * @param leftVector The <code>SimpleVectorf4</code> to be placed on the left hand side of the equation.
             * @param rightVector The <code>SimpleVectorf4</code> to be placed on the right hand side of the equation.
             *
             * @return An array that contains the result of the subtraction.
             */
            float*
            subtract(SimpleVectorf4* const leftVector, SimpleVectorf4* const rightVector);
    };
}

#endif /* SIMPLEVECTORF4_H_ */
