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
using namespace std;

#include <boost/array.hpp>
using namespace boost;

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
        SimpleVector4(Data const d0, Data const d1, Data const d2, Data const d3);

        /**
         * <p>
         * Creates an instance of <code>SimpleVector4</code>.
         * </p>
         *
         * <p>
         * The <code>SimpleVector4</code> is initialised to the contents of the vector given.
         * </p>
         *
         * <p>
         * This <code>SimpleVector4</code> will assume ownership of the given array.
         * </p>
         *
         * @param data An array containing the initial elements of this <code>SimpleVector4</code>.
         */
        SimpleVector4(array<Data, 4> data);

        void
        add(Vector<Data> const * const otherVector);

        Vector<Data> *
        addCopy(Vector<Data> const * const otherVector) const ;

        void
        crossProductRight(Vector<Data> const * const otherVector);

        Vector<Data> *
        crossProductRightCopy(Vector<Data> const * const otherVector) const ;

        Data
        dotProduct(Vector<Data> const * const otherVector);

        /**
         * <p>
         * Retrieves the array that contains the data for this <code>SimpleVector4</code>.
         * </p>
         *
         * <p>
         * This <code>SimpleVector4</code> will retain ownership of the returned array.
         * </p>
         *
         * @return The array that contains the data for this <code>SimpleVector4</code>.
         */
        array<Data, 4> &
        getData();

        /**
         * <p>
         * Retrieves a copy of the array that contains the data for this <code>SimpleVector4</code>.
         * </p>
         *
         * <p>
         * This <code>SimpleVector4</code> will retain ownership of the returned array.
         * </p>
         *
         * @return A copy of the array that contains the data for this <code>SimpleVector4</code>.
         */
        array<Data, 4>
        getDataCopy() const;

        Data
        getLength() const;

        Data
        getLengthSquared() const;

        void
        homogenize();

        void
        multiplyLeft(Matrix<Data> const * const otherMatrix);

        Vector<Data> *
        multiplyLeftCopy(Matrix<Data> const * const otherMatrix) const;

        void
        multiplyRight(Matrix<Data> const * const otherMatrix);

        void
        multiplyRight(Vector<Data> const * const otherVector);

        Vector<Data> *
        multiplyRightCopy(Matrix<Data> const * const otherMatrix) const;

        Vector<Data> *
        multiplyRightCopy(Vector<Data> const * const otherVector) const;

        void
        negate();

        void
        normalize();

        void
        scale(const Data scalar);

        void
        subtractRight(Vector<Data> const * const otherVector);

        Vector<Data>*
        subtractRightCopy(Vector<Data> const * const otherVector) const;

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
         * The number of cells in this vector.
         * </p>
         */
        static int const CELLS_IN_VECTOR = 4;

      private:
        /**
         * <p>
         * The array that contains the data for this <code>SimpleVector4</code>.
         * </p>
         */
        array<Data, CELLS_IN_VECTOR> fData;

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
        array<Data, 4>
        add(SimpleVector4<Data> const & leftVector, SimpleVector4<Data> const & rightVector) const;

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
        array<Data, 4>
        crossProduct(SimpleVector4<Data> const & leftVector, SimpleVector4<Data> const & rightVector) const;

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
        array<Data, 4>
        multiply(SimpleVector4<Data> const & leftVector, SimpleVector4<Data> const & rightVector) const;

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
        array<Data, 4>
        multiplyLeft(SimpleMatrix44<Data> const & otherMatrix) const;

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
        array<Data, 4>
        multiplyRight(SimpleMatrix44<Data> const & otherMatrix) const;

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
        array<Data, 4>
        subtract(SimpleVector4<Data> const & leftVector, SimpleVector4<Data> const & rightVector) const;
    };
}

#include "SimpleVector4.tpp"

#endif /* SIMPLEVECTOR4_H_ */
