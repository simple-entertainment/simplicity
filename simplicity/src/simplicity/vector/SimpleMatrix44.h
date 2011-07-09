/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEMATRIX44_H_
#define SIMPLEMATRIX44_H_

#include <string>
using namespace std;

#include <boost/array.hpp>
using namespace boost;

#include "Matrix.h"

namespace simplicity
{
  /**
   * <p>
   * A 4x4 dimensional matrix that stores its data in an array.
   * </p>
   *
   * @author Gary Buyn
   */
  template<class Data>
    class SimpleMatrix44 : public virtual Matrix<Data>
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>SimpleMatrix44</code>.
         * </p>
         *
         * <p>
         * The <code>SimpleMatrix44</code> is initialised as an identity matrix.
         * </p>
         */
        SimpleMatrix44();

        /**
         * <p>
         * Creates an instance of <code>SimpleMatrix44</code>.
         * </p>
         *
         * <p>
         * The <code>SimpleMatrix44</code> is initialised to the contents of the array given.
         * </p>
         *
         * @param data An array containing the initial elements for this <code>SimpleMatrix44</code>.
         */
        SimpleMatrix44(array<Data, 16> data);

        /**
         * <p>
         * Retrieves the array that contains the data for this <code>SimpleMatrix44</code>.
         * </p>
         *
         * @return The array that contains the data for this <code>SimpleMatrix44</code>.
         */
        array<Data, 16> &
        getData();

        /**
         * <p>
         * Retrieves a copy of the array that contains the data for this <code>SimpleMatrix44</code>.
         * </p>
         *
         * @return A copy of the array that contains the data for this <code>SimpleMatrix44</code>.
         */
        array<Data, 16>
        getDataCopy() const;

        Data
        getDeterminant() const;

        /**
         * <p>
         * NOTE: This method uses Cramer's Rule to compute the inverse (computes many determinants). Gaussian Elimination could be a more efficient means
         * of computing the inverse.
         * </p>
         *
         * @throws SEInvalidOperationException Thrown if this <code>SimpleMatrix44</code> has a determinant of 0.
         */
        void
        invert() throw (SEInvalidOperationException);

        void
        multiplyLeft(Matrix<Data> const * const leftMatrix);

        Matrix<Data> *
        multiplyLeftCopy(Matrix<Data> const * const leftMatrix) const;

        void
        multiplyRight(Matrix<Data> const * const rightMatrix);

        Matrix<Data> *
        multiplyRightCopy(Matrix<Data> const * const rightMatrix) const;

        void
        setIdentity();

        /**
         * <p>
         * Retrieves a textual representation of this <code>SimpleMatrix44</code> in the following format.
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
         * @return A textual representation of this <code>SimpleMatrix44</code>.
         */
        string
        toString() const;

        void
        transpose();

      protected:
        /**
         * <p>
         * The number of cells in a column of this 4x4 matrix.
         * </p>
         */
        static int const CELLS_IN_COLUMN = 4;

        /**
         * <p>
         * The number of cells in this 4x4 matrix.
         * </p>
         */
        static int const CELLS_IN_MATRIX = 16;

        /**
         * <p>
         * The number of cells in a row of this 4x4 matrix.
         * </p>
         */
        static int const CELLS_IN_ROW = 4;

      private:
        /**
         * <p>
         * The array that contains the data for this <code>SimpleMatrix44</code>.
         * </p>
         */
        array<Data, 16> fData;

        /**
         * <p>
         * Retrieves the determinant of a 3x3 column-major matrix. The matrix is formatted as follows:
         * </p>
         *
         * <pre>
         * -------------------
         * | d00 | d10 | d20 |
         * -------------------
         * | d01 | d11 | d21 |
         * -------------------
         * | d02 | d12 | d22 |
         * -------------------
         * </pre>
         *
         * @param d00 An element of data in the 3x3 matrix.
         * @param d10 An element of data in the 3x3 matrix.
         * @param d20 An element of data in the 3x3 matrix.
         * @param d01 An element of data in the 3x3 matrix.
         * @param d11 An element of data in the 3x3 matrix.
         * @param d21 An element of data in the 3x3 matrix.
         * @param d02 An element of data in the 3x3 matrix.
         * @param d12 An element of data in the 3x3 matrix.
         * @param d22 An element of data in the 3x3 matrix.
         *
         * @return The determinant of a 3x3 column-major matrix.
         */
        Data
        getDeterminant33(Data const d00, Data const d10, Data const d20, Data const d01, Data const d11, Data const d21,
            Data const d02, Data const d12, Data const d22) const;

        /**
         * <p>
         * Multiplies the <code>SimpleMatrix44</code>s given.
         * </p>
         *
         * @param leftMatrix The <code>SimpleMatrix44</code> to be placed on the left hand side of the equation.
         * @param rightMatrix The <code>SimpleMatrix44</code> to be placed on the right hand side of the equation.
         *
         * @return An array that contains the result of the multiplication.
         */
        array<Data, 16>
        multiply(SimpleMatrix44<Data> const & leftMatrix, SimpleMatrix44<Data> const & rightMatrix) const;
    };
}

#include "SimpleMatrix44.tpp"

#endif /* SIMPLEMATRIX44_H_ */
