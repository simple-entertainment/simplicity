/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEVECTOR4_H_
#define SIMPLEVECTOR4_H_

#include <string>

#include <boost/array.hpp>

#include "SimpleMatrix44.h"
#include "Vector.h"

namespace simplicity
{
  /**
   * <p>
   * A 4 dimensional vector that stores its data in an array.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data>
    class SimpleVector4 : public virtual Vector<Data>
    {
      public:
        /**
         * <p>
         * The number of cells in this vector.
         * </p>
         */
        static int const CELLS_IN_VECTOR = 4;

        /**
         * <p>
         * Creates an instance of <code>SimpleVector4</code>.
         * </p>
         *
         * <p>
         * The <code>SimpleVector4</code> is initialised to <code>(0.0, 0.0, 0.0, 1.0)</code>.
         * </p>
         */
        SimpleVector4();

        /**
         * <p>
         * Creates an instance of <code>SimpleVector4</code>.
         * </p>
         *
         * <p>
         * The <code>SimpleVector4</code> is initialised to the components given.
         * </p>
         *
         * @param d0 The first element of data in this <code>SimpleVector4</code>.
         * @param d1 The second element of data in this <code>SimpleVector4</code>.
         * @param d2 The third element of data in this <code>SimpleVector4</code>.
         * @param d3 The fourth element of data in this <code>SimpleVector4</code>.
         */
        SimpleVector4(const Data d0, const Data d1, const Data d2, const Data d3);

        /**
         * <p>
         * Creates an instance of <code>SimpleVector4</code>.
         * </p>
         *
         * <p>
         * The <code>SimpleVector4</code> is initialised to the contents of the vector given.
         * </p>
         *
         * @param data An array containing the initial elements of this <code>SimpleVector4</code>.
         */
        SimpleVector4(boost::array<Data, CELLS_IN_VECTOR> data);

        void
        add(const Vector<Data>& otherVector);

        boost::shared_ptr<Vector<Data> >
        addCopy(const Vector<Data>& otherVector) const;

        void
        crossProductRight(const Vector<Data>& otherVector);

        boost::shared_ptr<Vector<Data> >
        crossProductRightCopy(const Vector<Data>& otherVector) const;

        Data
        dotProduct(const Vector<Data>& otherVector);

        /**
         * <p>
         * Retrieves the array that contains the data for this <code>SimpleVector4</code>.
         * </p>
         *
         * @return The array that contains the data for this <code>SimpleVector4</code>.
         */
        boost::array<Data, CELLS_IN_VECTOR>&
        getData();

        /**
         * <p>
         * Retrieves a copy of the array that contains the data for this <code>SimpleVector4</code>.
         * </p>
         *
         * @return A copy of the array that contains the data for this <code>SimpleVector4</code>.
         */
        boost::array<Data, CELLS_IN_VECTOR>
        getDataCopy() const;

        Data
        getLength() const;

        Data
        getLengthSquared() const;

        void
        homogenize();

        void
        multiplyLeft(const Matrix<Data>& otherMatrix);

        boost::shared_ptr<Vector<Data> >
        multiplyLeftCopy(const Matrix<Data>& otherMatrix) const;

        void
        multiplyRight(const Matrix<Data>& otherMatrix);

        void
        multiplyRight(const Vector<Data>& otherVector);

        boost::shared_ptr<Vector<Data> >
        multiplyRightCopy(const Matrix<Data>& otherMatrix) const;

        boost::shared_ptr<Vector<Data> >
        multiplyRightCopy(const Vector<Data>& otherVector) const;

        void
        negate();

        void
        normalize();

        void
        scale(const Data scalar);

        void
        subtractRight(const Vector<Data>& otherVector);

        boost::shared_ptr<Vector<Data> >
        subtractRightCopy(const Vector<Data>& otherVector) const;

        /**
         * <p>
         * Retrieves a textual representation of this <code>SimpleVector4</code> in the following format.
         * </p>
         *
         * <pre>
         * ----------------
         *  x | y | z | w |
         * ----------------
         * </pre>
         *
         * @return A textual representation of this <code>SimpleVector4</code>.
         */
        string
        toString() const;

      private:
        /**
         * <p>
         * The array that contains the data for this <code>SimpleVector4</code>.
         * </p>
         */
        boost::array<Data, CELLS_IN_VECTOR> fData;

        /**
         * <p>
         * Adds the <code>SimpleVector4</code> given to this <code>SimpleVector4</code>.
         * <p>
         *
         * <p>
         * This method assumes both <code>SimSimpleVector4pleVector</code>s to be homogenised.
         * </p>
         *
         * @param leftVector The <code>SimpleVector4</code> to be placed on the left hand side of the equation.
         * @param rightVector The <code>SimpleVector4</code> to be placed on the right hand side of the equation.
         *
         * @return A array that contains the result of the addition.
         */
        boost::array<Data, CELLS_IN_VECTOR>
        add(const SimpleVector4<Data>& leftVector, const SimpleVector4<Data>& rightVector) const;

        /**
         * <p>
         * Performs a cross product of the <code>SimpleVector4</code>s given.
         * </p>
         *
         * <p>
         * This method assumes both <code>SimpleVector4</code>s to be homogenised.
         * </p>
         *
         * @param leftVector The <code>SimpleVector4</code> to be placed on the left hand side of the equation.
         * @param rightVector The <code>SimpleVector4</code> to be placed on the right hand side of the equation.
         *
         * @return A array that contains the result of the cross product.
         */
        boost::array<Data, CELLS_IN_VECTOR>
        crossProduct(const SimpleVector4<Data>& leftVector, const SimpleVector4<Data>& rightVector) const;

        /**
         * <p>
         * Multiplies the <code>SimpleVector4</code>s given.
         * </p>
         *
         * <p>
         * This method assumes both <code>SimpleVector4</code>s to be homogenised.
         * </p>
         *
         * @param leftVector The <code>SimpleVector4</code> to be placed on the left hand side of the equation.
         * @param rightVector The <code>SimpleVector4</code> to be placed on the right hand side of the equation.
         *
         * @return A array that contains the result of the multiplication.
         */
        boost::array<Data, CELLS_IN_VECTOR>
        multiply(const SimpleVector4<Data>& leftVector, const SimpleVector4<Data>& rightVector) const;

        /**
         * <p>
         * Multiplies this <code>SimpleVector4</code> with the {@link com.se.simplicity.vector.SimpleMatrix44 SimpleMatrix44} given. This <code>SimpleVector4</code> is treated as a
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
         * @param matrix The <code>SimpleMatrix44</code> to be multiplied.
         *
         * @return An array that contains the result of the multiplication.
         */
        boost::array<Data, CELLS_IN_VECTOR>
        multiplyLeftInternal(const SimpleMatrix44<Data>& otherMatrix) const;

        /**
         * <p>
         * Multiplies this <code>SimpleVector4</code> with the {@link com.se.simplicity.vector.SimpleMatrix44 SimpleMatrix44} given. This <code>SimpleVector4</code> is treated as a
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
         * @param matrix The <code>SimpleMatrix44</code> to be multiplied.
         *
         * @return An array that contains the result of the multiplication.
         */
        boost::array<Data, CELLS_IN_VECTOR>
        multiplyRightInternal(const SimpleMatrix44<Data>& otherMatrix) const;

        /**
         * <p>
         * Performs a subtraction of the <code>SimpleVector4</code>s given.
         * </p>
         *
         * @param leftVector The <code>SimpleVector4</code> to be placed on the left hand side of the equation.
         * @param rightVector The <code>SimpleVector4</code> to be placed on the right hand side of the equation.
         *
         * @return An array that contains the result of the subtraction.
         */
        boost::array<Data, CELLS_IN_VECTOR>
        subtract(const SimpleVector4<Data>& leftVector, const SimpleVector4<Data>& rightVector) const;
    };
}

#include "SimpleVector4.tpp"

#endif /* SIMPLEVECTOR4_H_ */
