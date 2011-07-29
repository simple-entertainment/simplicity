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

#include <boost/array.hpp>

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
        SimpleMatrix44(boost::array<Data, 16> data);

        /**
         * <p>
         * Retrieves the array that contains the data for this <code>SimpleMatrix44</code>.
         * </p>
         *
         * @return The array that contains the data for this <code>SimpleMatrix44</code>.
         */
        boost::array<Data, CELLS_IN_MATRIX> &
        getData();

        /**
         * <p>
         * Retrieves a copy of the array that contains the data for this <code>SimpleMatrix44</code>.
         * </p>
         *
         * @return A copy of the array that contains the data for this <code>SimpleMatrix44</code>.
         */
        boost::array<Data, CELLS_IN_MATRIX>
        getDataCopy() const;

        Data
        getDeterminant() const;

        const Data* const
        getRawData() const;

        /**
         * <p>
         * NOTE: This method uses Cramer's Rule to compute the inverse (computes many determinants). Gaussian Elimination could be a more efficient means
         * of computing the inverse.
         * </p>
         *
         * @throws SEInvalidOperationException Thrown if this <code>SimpleMatrix44</code> has a determinant of 0.
         */
        void
        invert();

        void
        multiplyLeft(const Matrix<Data>& leftMatrix);

        boost::shared_ptr<Matrix<Data> >
        multiplyLeftCopy(const Matrix<Data>& leftMatrix) const;

        void
        multiplyRight(const Matrix<Data>& rightMatrix);

        boost::shared_ptr<Matrix<Data> >
        multiplyRightCopy(const Matrix<Data>& rightMatrix) const;

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
        std::string
        toString() const;

        void
        transpose();

      private:
        /**
         * <p>
         * The array that contains the data for this <code>SimpleMatrix44</code>.
         * </p>
         */
        boost::array<Data, CELLS_IN_MATRIX> fData;

        bool
        equals(const Matrix<Data>& otherMatrix) const;

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
        getDeterminant33(const Data d00, const Data d10, const Data d20, const Data d01, const Data d11, const Data d21,
            const Data d02, const Data d12, const Data d22) const;

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
        boost::array<Data, CELLS_IN_MATRIX>
        multiply(const SimpleMatrix44<Data>& leftMatrix, const SimpleMatrix44<Data>& rightMatrix) const;
    };
}

#include "SimpleMatrix44.tpp"

#endif /* SIMPLEMATRIX44_H_ */
