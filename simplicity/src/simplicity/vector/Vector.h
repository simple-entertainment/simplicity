/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef VECTOR_H_
#define VECTOR_H_

#include "Matrix.h"

namespace simplicity
{
  /**
   * <p>
   * A vector.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data = float>
    class Vector
    {
      public:
        /**
         * <p>
         * Disposes of an instance of <code>Vector</code> (included to allow polymorphic deletion).
         * </p>
         */
        virtual
        ~Vector()
        {
        }

        /**
         * <p>
         * Adds the <code>Vector</code> given to this <code>Vector</code>.
         * <p>
         *
         * <p>
         * This <code>Vector</code> becomes the result of the addition.
         * </p>
         *
         * <p>
         * This method assumes both <code>Vector</code>s to be homogenised.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to add this <code>Vector</code> to.
         */
        virtual void
        add(const Vector<Data>& otherVector) = 0;

        /**
         * <p>
         * Adds the <code>Vector</code> given to this <code>Vector</code>.
         * <p>
         *
         * <p>
         * A new <code>Vector</code> is created as the result of the addition.
         * </p>
         *
         * <p>
         * This method assumes both <code>Vector</code>s to be homogenised.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to add this <code>Vector</code> to.
         *
         * @return A new <code>Vector</code> that is the result of sum of this <code>Vector</code> and the <code>Vector</code> given.
         */
        virtual boost::shared_ptr<Vector<Data> >
        addCopy(const Vector<Data>& otherVector) const = 0;

        /**
         * <p>
         * Performs a cross product of this <code>Vector</code> and the <code>Vector</code> given. The <code>Vector</code> given is placed on the right
         * hand side of the equation.
         * </p>
         *
         * <p>
         * This <code>Vector</code> becomes the result of the cross product.
         * </p>
         *
         * <p>
         * This method assumes both <code>Vector</code>s to be homogenised.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to be placed on the right hand side of the equation.
         */
        virtual void
        crossProductRight(const Vector<Data>& otherVector) = 0;

        /**
         * <p>
         * Performs a cross product of this <code>Vector</code> and the <code>Vector</code> given. The <code>Vector</code> given is placed on the right
         * hand side of the equation.
         * </p>
         *
         * <p>
         * A new <code>Vector</code> is created as the result of the cross product.
         * </p>
         *
         * <p>
         * This method assumes both <code>Vector</code>s to be homogenised.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to be placed on the right hand side of the equation.
         *
         * @return A new <code>Vector</code> that is the result of the cross product of this <code>Vector</code> and the <code>Vector</code> given.
         */
        virtual boost::shared_ptr<Vector<Data> >
        crossProductRightCopy(const Vector<Data>& otherVector) const = 0;

        /**
         * <p>
         * Performs a dot product of this <code>Vector</code> and the <code>Vector</code> given
         * </p>
         *
         * <p>
         * This method assumes both <code>Vector</code>s to be homogenised.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to perform the dot product with.
         *
         * @return The dot product of this <code>Vector</code> and the <code>Vector</code> given.
         */
        virtual float
        dotProduct(const Vector<Data>& otherVector) = 0;

        /**
         * <p>
         * Retrieves the length of this <code>Vector</code>.
         * </p>
         *
         * @return The length of this <code>Vector</code>.
         */
        virtual Data
        getLength() const = 0;

        /**
         * <p>
         * Retrieves the length of this <code>Vector</code> squared.
         * </p>
         *
         * @return The length of this <code>Vector</code> squared.
         */
        virtual Data
        getLengthSquared() const = 0;

        /**
         * <p>
         * Homogenises this <code>Vector</code>.
         * </p>
         *
         * <p>
         * Scales all values equally so that the <code>w</code> value of this <code>Vector</code> is <code>1.0f</code>.
         * </p>
         */
        virtual void
        homogenize() = 0;

        /**
         * <p>
         * Multiplies this <code>Vector</code> with the {@link com.se.simplicity.vector.Matrix Matrix} given. This <code>Vector</code> is treated as a
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
         * This <code>Vector</code> becomes the result of the multiplication.
         * </p>
         *
         * @param matrix The {@link com.se.simplicity.vector.Matrix Matrix} to be placed on the left hand side of the equation.
         */
        virtual void
        multiplyLeft(const Matrix<Data>& matrix) = 0;

        /**
         * <p>
         * Multiplies this <code>Vector</code> with the {@link com.se.simplicity.vector.Matrix Matrix} given. This <code>Vector</code> is treated as a
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
         * A new <code>Vector</code> is created as the result of the multiplication.
         * </p>
         *
         * @param matrix The {@link com.se.simplicity.vector.Matrix Matrix} to be placed on the left hand side of the equation.
         *
         * @return A new <code>Vector</code> that is the result of the multiplication of this <code>Vector</code> and the
         * {@link com.se.simplicity.vector.Matrix Matrix} given.
         */
        virtual boost::shared_ptr<Vector<Data> >
        multiplyLeftCopy(const Matrix<Data>& matrix) const = 0;

        /**
         * <p>
         * Multiplies this <code>Vector</code> with the {@link com.se.simplicity.vector.Matrix Matrix} given. This <code>Vector</code> is treated as a
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
         * This <code>Vector</code> becomes the result of the multiplication.
         * </p>
         *
         * @param matrix The {@link com.se.simplicity.vector.Matrix Matrix} to be placed on the right hand side of the equation.
         */
        virtual void
        multiplyRight(const Matrix<Data>& matrix) = 0;

        /**
         * <p>
         * Multiplies this <code>Vector</code> with the <code>Vector</code> given. The <code>Vector</code> given is placed on the right hand side of
         * the equation.
         * </p>
         *
         * <p>
         * This <code>Vector</code> becomes the result of the multiplication.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to be placed on the right hand side of the equation.
         */
        virtual void
        multiplyRight(const Vector<Data>& otherVector) = 0;

        /**
         * <p>
         * Multiplies this <code>Vector</code> with the {@link com.se.simplicity.vector.Matrix Matrix} given. This <code>Vector</code> is treated as a
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
         * A new <code>Vector</code> is created as the result of the multiplication.
         * </p>
         *
         * @param matrix The {@link com.se.simplicity.vector.Matrix Matrix} to be placed on the right hand side of the equation.
         *
         * @return A new <code>Vector</code> that is the result of the multiplication of this <code>Vector</code> and the
         * {@link com.se.simplicity.vector.Matrix Matrix} given.
         */
        virtual boost::shared_ptr<Vector<Data> >
        multiplyRightCopy(const Matrix<Data>& matrix) const = 0;

        /**
         * <p>
         * Multiplies this <code>Vector</code> with the <code>Vector</code> given. The <code>Vector</code> given is placed on the right hand side of
         * the equation.
         * </p>
         *
         * <p>
         * A new <code>Vector</code> is created as the result of the multiplication.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to be placed on the right hand side of the equation.
         *
         * @return A new <code>Vector</code> that is the result of the multiplication of this <code>Vector</code> and the <code>Vector</code> given.
         */
        virtual boost::shared_ptr<Vector<Data> >
        multiplyRightCopy(const Vector<Data>& otherVector) const = 0;

        /**
         * <p>
         * Negates this <code>Vector</code>.
         * </p>
         */
        virtual void
        negate() = 0;

        /**
         * <p>
         * Scales this <code>Vector</code> to a unit length vector.
         * </p>
         */
        virtual void
        normalize() = 0;

        /**
         * <p>
         * Scales this <code>Vector</code> by the scalar given.
         * </p>
         *
         * @param scalar The factor to scale this <code>Vector</code> by.
         */
        virtual void
        scale(const Data scalar) = 0;

        /**
         * <p>
         * Subtracts the <code>Vector</code> given from this <code>Vector</code>. The <code>Vector</code> given is placed on the right hand side of the
         * equation.
         * </p>
         *
         * <p>
         * This <code>Vector</code> becomes the result of the subtraction.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to be placed on the right hand side of the equation.
         */
        virtual void
        subtractRight(const Vector<Data>& otherVector) = 0;

        /**
         * <p>
         * Subtracts the <code>Vector</code> given from this <code>Vector</code>. The <code>Vector</code> given is placed on the right hand side of the
         * equation.
         * </p>
         *
         * <p>
         * A new <code>Vector</code> is created as the result of the subtraction.
         * </p>
         *
         * @param otherVector The <code>Vector</code> to be placed on the right hand side of the equation.
         *
         * @return A new <code>Vector</code> that is the result of the subtraction of the <code>Vector</code> given from this <code>Vector</code>.
         */
        virtual boost::shared_ptr<Vector<Data> >
        subtractRightCopy(const Vector<Data>& otherVector) const = 0;
    };
}

#endif /* VECTOR_H_ */
