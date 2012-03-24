/*
 * Copyright © 2012 Simple Entertainment Limited
 *
 * This file is part of The Simplicity Engine.
 *
 * The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEMATRIX_H_
#define SIMPLEMATRIX_H_

#include <string>

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
	template<typename Data = float, unsigned int Columns = 4, unsigned int Rows = 4>
	class SimpleMatrix : public virtual Matrix<Data, Columns, Rows>
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleMatrix</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleMatrix</code> is initialised as an identity matrix.
			 * </p>
			 */
			SimpleMatrix();

			/**
			 * <p>
			 * Creates an instance of <code>SimpleMatrix</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleMatrix</code> is initialised to the contents of the array given.
			 * </p>
			 *
			 * @param data An array containing the initial elements for this <code>SimpleMatrix</code>.
			 */
			SimpleMatrix(const std::array<Data, Columns * Rows>& data);

			std::array<Data, Columns * Rows>& getData();

			const std::array<Data, Columns * Rows>& getData() const;

			Data getDeterminant() const;

			/**
			 * <p>
			 * NOTE: This method uses Cramer's Rule to compute the inverse (computes many determinants). Gaussian
			 * Elimination could be a more efficient means of computing the inverse.
			 * </p>
			 *
			 * @throws SEInvalidOperationException Thrown if this <code>SimpleMatrix</code> has a determinant of 0.
			 */
			void invert();

			std::unique_ptr<Matrix<Data, Columns, Rows> > operator*(const Matrix<Data, Rows, Columns>& rhs) const;

			std::unique_ptr<Vector<Data, Rows> > operator*(const Vector<Data, Rows>& rhs) const;

			Matrix<Data, Columns, Rows>& operator*=(const Matrix<Data, Rows, Columns>& rhs);

			void setData(const std::array<Data, Columns * Rows>& data);

			void setIdentity();

			/**
			 * <p>
			 * Retrieves a textual representation of this <code>SimpleMatrix</code> in the following format.
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
			 * @return A textual representation of this <code>SimpleMatrix</code>.
			 */
			std::string toString() const;

			void transpose();

		private:
			/**
			 * <p>
			 * The array that contains the data for this <code>SimpleMatrix</code>.
			 * </p>
			 */
			std::array<Data, Columns * Rows> data;

			bool equals(const Matrix<Data, Columns, Rows>& otherMatrix) const;

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
			Data getDeterminant33(const Data d00, const Data d10, const Data d20, const Data d01, const Data d11,
				const Data d21, const Data d02, const Data d12, const Data d22) const;

			/**
			 * <p>
			 * Multiplies the <code>SimpleMatrix</code> data given.
			 * </p>
			 *
			 * @param lhs The data to be placed on the left hand side of the equation.
			 * @param rhs The data to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication.
			 */
			std::array<Data, Columns * Rows> multiply(const std::array<Data, Columns * Rows>& lhs
				, const std::array<Data, Columns * Rows>& rhs) const;

			/**
			 * <p>
			 * Multiplies this <code>SimpleMatrix</code>'s data with the given {@link simplicity::Vector Vector} data.
			 * The <code>Vector</code> is treated as a column vector and multiplied as follows:
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
			 * @param lhs The <code>SimpleMatrix</code> data to be placed on the left hand side of the equation.
			 * @param rhs The <code>Vector</code> data to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication.
			 */
			std::array<Data, Rows> multiplyWithVector(const std::array<Data, Columns * Rows>& lhs
				, const std::array<Data, Rows>& rhs) const;
	};
}

#include "SimpleMatrix.tpp"

#endif /* SIMPLEMATRIX_H_ */
