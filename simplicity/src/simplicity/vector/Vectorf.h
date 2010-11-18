/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef VECTORF_H_
#define VECTORF_H_

#include "Matrixf.h"

namespace simplicity
{
    /**
     * <p>
     * A vector that stores its data in a <code>float</code> array.
     * </p>
     *
     * @author Gary Buyn
     */
    class Vectorf
    {
        public:
            /**
             * <p>
             * Adds the <code>Vectorf</code> given to this <code>Vectorf</code>.
             * <p>
             *
             * <p>
             * This <code>Vectorf</code> becomes the result of the addition.
             * </p>
             *
             * <p>
             * This method assumes both <code>Vectorf</code>s to be homogenised.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to add this <code>Vectorf</code> to.
             */
            virtual void
            add(Vectorf* const vector) = 0;

            /**
             * <p>
             * Adds the <code>Vectorf</code> given to this <code>Vectorf</code>.
             * <p>
             *
             * <p>
             * A new <code>Vectorf</code> is created as the result of the addition.
             * </p>
             *
             * <p>
             * This method assumes both <code>Vectorf</code>s to be homogenised.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>Vectorf</code>.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to add this <code>Vectorf</code> to.
             *
             * @return A new <code>Vectorf</code> that is the result of sum of this <code>Vectorf</code> and the <code>Vectorf</code> given.
             */
            virtual Vectorf*
            addCopy(Vectorf* const vector) = 0;

            /**
             * <p>
             * Performs a cross product of this <code>Vectorf</code> and the <code>Vectorf</code> given. The <code>Vectorf</code> given is placed on the right
             * hand side of the equation.
             * </p>
             *
             * <p>
             * This <code>Vectorf</code> becomes the result of the cross product.
             * </p>
             *
             * <p>
             * This method assumes both <code>Vectorf</code>s to be homogenised.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
             */
            virtual void
            crossProductRight(Vectorf* const vector) = 0;

            /**
             * <p>
             * Performs a cross product of this <code>Vectorf</code> and the <code>Vectorf</code> given. The <code>Vectorf</code> given is placed on the right
             * hand side of the equation.
             * </p>
             *
             * <p>
             * A new <code>Vectorf</code> is created as the result of the cross product.
             * </p>
             *
             * <p>
             * This method assumes both <code>Vectorf</code>s to be homogenised.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>Vectorf</code>.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
             *
             * @return A new <code>Vectorf</code> that is the result of the cross product of this <code>Vectorf</code> and the <code>Vectorf</code> given.
             */
            virtual Vectorf*
            crossProductRightCopy(Vectorf* const vector) = 0;

            /**
             * <p>
             * Performs a dot product of this <code>Vectorf</code> and the <code>Vectorf</code> given
             * </p>
             *
             * <p>
             * This method assumes both <code>Vectorf</code>s to be homogenised.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to perform the dot product with.
             *
             * @return The dot product of this <code>Vectorf</code> and the <code>Vectorf</code> given.
             */
            virtual float
            dotProduct(Vectorf* const vector) = 0;

            /**
             * <p>
             * Retrieves the length of this <code>Vectorf</code>.
             * </p>
             *
             * @return The length of this <code>Vectorf</code>.
             */
            virtual float
            getLength() = 0;

            /**
             * <p>
             * Retrieves the length of this <code>Vectorf</code> squared.
             * </p>
             *
             * @return The length of this <code>Vectorf</code> squared.
             */
            virtual float
            getLengthSquared() = 0;

            /**
             * <p>
             * Homogenises this <code>Vectorf</code>.
             * </p>
             *
             * <p>
             * Scales all values equally so that the <code>w</code> value of this <code>Vectorf</code> is <code>1.0f</code>.
             * </p>
             */
            virtual void
            homogenize() = 0;

            /**
             * <p>
             * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This <code>Vectorf</code> is treated as a
             * column vector and multiplied as follows:
             * </p>
             *
             * <pre>
             * ----------------     -----
             *  x | x | x | x |  *  | x |
             * ----------------     -----
             *  x | x | x | x |     | x |
             * ----------------     -----
             *  x | x | x | x |     | x |
             * ----------------     -----
             *  x | x | x | x |     | x |
             * ----------------     -----
             * </pre>
             *
             * <p>
             * This <code>Vectorf</code> becomes the result of the multiplication.
             * </p>
             *
             * @param matrix The {@link com.se.simplicity.vector.Matrixf Matrixf} to be placed on the left hand side of the equation.
             */
            virtual void
            multiplyLeft(Matrixf* const matrix) = 0;

            /**
             * <p>
             * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This <code>Vectorf</code> is treated as a
             * column vector and multiplied as follows:
             * </p>
             *
             * <pre>
             * ----------------     -----
             *  x | x | x | x |  *  | x |
             * ----------------     -----
             *  x | x | x | x |     | x |
             * ----------------     -----
             *  x | x | x | x |     | x |
             * ----------------     -----
             *  x | x | x | x |     | x |
             * ----------------     -----
             * </pre>
             *
             * <p>
             * A new <code>Vectorf</code> is created as the result of the multiplication.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>Vectorf</code>.
             * </p>
             *
             * @param matrix The {@link com.se.simplicity.vector.Matrixf Matrixf} to be placed on the left hand side of the equation.
             *
             * @return A new <code>Vectorf</code> that is the result of the multiplication of this <code>Vectorf</code> and the
             * {@link com.se.simplicity.vector.Matrixf Matrixf} given.
             */
            virtual Vectorf*
            multiplyLeftCopy(Matrixf* const matrix) = 0;

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
             * <p>
             * This <code>Vectorf</code> becomes the result of the multiplication.
             * </p>
             *
             * @param matrix The {@link com.se.simplicity.vector.Matrixf Matrixf} to be placed on the right hand side of the equation.
             */
            virtual void
            multiplyRight(Matrixf* const matrix) = 0;

            /**
             * <p>
             * Multiplies this <code>Vectorf</code> with the <code>Vectorf</code> given. The <code>Vectorf</code> given is placed on the right hand side of
             * the equation.
             * </p>
             *
             * <p>
             * This <code>Vectorf</code> becomes the result of the multiplication.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
             */
            virtual void
            multiplyRight(Vectorf* const vector) = 0;

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
             * <p>
             * A new <code>Vectorf</code> is created as the result of the multiplication.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>Vectorf</code>.
             * </p>
             *
             * @param matrix The {@link com.se.simplicity.vector.Matrixf Matrixf} to be placed on the right hand side of the equation.
             *
             * @return A new <code>Vectorf</code> that is the result of the multiplication of this <code>Vectorf</code> and the
             * {@link com.se.simplicity.vector.Matrixf Matrixf} given.
             */
            virtual Vectorf*
            multiplyRightCopy(Matrixf* const matrix) = 0;

            /**
             * <p>
             * Multiplies this <code>Vectorf</code> with the <code>Vectorf</code> given. The <code>Vectorf</code> given is placed on the right hand side of
             * the equation.
             * </p>
             *
             * <p>
             * A new <code>Vectorf</code> is created as the result of the multiplication.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>Vectorf</code>.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
             *
             * @return A new <code>Vectorf</code> that is the result of the multiplication of this <code>Vectorf</code> and the <code>Vectorf</code> given.
             */
            virtual Vectorf*
            multiplyRightCopy(Vectorf* const vector) = 0;

            /**
             * <p>
             * Negates this <code>Vectorf</code>.
             * </p>
             */
            virtual void
            negate() = 0;

            /**
             * <p>
             * Scales this <code>Vectorf</code> to a unit length vector.
             * </p>
             */
            virtual void
            normalize() = 0;

            /**
             * <p>
             * Scales this <code>Vectorf</code> by the scalar given.
             * </p>
             *
             * @param scalar The factor to scale this <code>Vectorf</code> by.
             */
            virtual void
            scale(const float scalar) = 0;

            /**
             * <p>
             * Subtracts the <code>Vectorf</code> given from this <code>Vectorf</code>. The <code>Vectorf</code> given is placed on the right hand side of the
             * equation.
             * </p>
             *
             * <p>
             * This <code>Vectorf</code> becomes the result of the subtraction.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
             */
            virtual void
            subtractRight(Vectorf* const vector) = 0;

            /**
             * <p>
             * Subtracts the <code>Vectorf</code> given from this <code>Vectorf</code>. The <code>Vectorf</code> given is placed on the right hand side of the
             * equation.
             * </p>
             *
             * <p>
             * A new <code>Vectorf</code> is created as the result of the subtraction.
             * </p>
             *
             * <p>
             * The caller must assume ownership of the returned <code>Vectorf</code>.
             * </p>
             *
             * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
             *
             * @return A new <code>Vectorf</code> that is the result of the subtraction of the <code>Vectorf</code> given from this <code>Vectorf</code>.
             */
            virtual Vectorf*
            subtractRightCopy(Vectorf* const vector) = 0;
    };
}

#endif /* VECTORF_H_ */
