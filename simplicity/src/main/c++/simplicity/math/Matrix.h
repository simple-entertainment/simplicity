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
#ifndef MATRIX_H_
#define MATRIX_H_

#include <array>
#include <ostream>

namespace simplicity
{
	/**
	 * <p>
	 * A column-major matrix. Not the kind with Keanu Reeves in it. I'm sorry if you were looking for that one. This is
	 * the mathematical kind.
	 * </p>
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	class Matrix
	{
		public:
			Matrix();

			/**
			 * @param original The matrix to copy.
			 */
			Matrix(const Matrix<Data, Columns, Rows>& original);

			/**
			 * @param data The data to copy into the matrix.
			 */
			Matrix(const std::array<Data, Columns * Rows>& data);

			/**
			 * @param data The data to copy into the matrix.
			 */
			Matrix(Data* data);

			/**
			 * <p>
			 * Retrieves a pointer to the raw data.
			 * </p>
			 *
			 * @return A pointer to the raw data.
			 */
			Data* getData();

			/**
			 * <p>
			 * Retrieves a pointer to the raw data.
			 * </p>
			 *
			 * @return A pointer to the raw data.
			 */
			const Data* getData() const;

			/**
			 * <p>
			 * Determines the determinant... whoah.
			 * </p>
			 *
			 * @return The determined determinant. Not to say the the determinant has a determined personality, just
			 * that it has indeed been determined.
			 */
			Data getDeterminant() const;

			/**
			 * <p>
			 * Inverts this matrix.
			 * </p>
			 */
			void invert();

			/**
			 * <p>
			 * Provides access to the elements of this matrix.
			 * </p>
			 *
			 * @param index The index of the element to access.
			 *
			 * @return The element at the specified index.
			 */
			Data& operator[](unsigned int index);

			/**
			 * <p>
			 * Provides access to the elements of this matrix.
			 * </p>
			 *
			 * @param index The index of the element to access.
			 *
			 * @return The element at the specified index.
			 */
			const Data& operator[](unsigned int index) const;

			/**
			 * <p>
			 * Multiplies this matrix by another matrix.
			 * </p>
			 *
			 * @param rhs The matrix to multiply this matrix by.
			 *
			 * @return This matrix.
			 */
			Matrix<Data, Columns, Rows>& operator*=(const Matrix<Data, Rows, Columns>& rhs);

			/**
			 * <p>
			 * Modifies this matrix to be equal to another matrix.
			 * </p>
			 *
			 * @param original The matrix to make this matrix equal to.
			 *
			 * @return This matrix.
			 */
			Matrix<Data, Columns, Rows>& operator=(const Matrix<Data, Columns, Rows>& original);

			/**
			 * <p>
			 * Sets the data of this matrix.
			 * </p>
			 *
			 * @param data The data.
			 */
			void setData(const std::array<Data, Columns * Rows>& data);

			/**
			 * <p>
			 * Sets the data of this matrix.
			 * </p>
			 *
			 * @param data The data.
			 */
			void setData(Data* data);

			/**
			 * <p>
			 * Sets this matrix to the identity matrix.
			 * </p>
			 */
			void setIdentity();

			/**
			 * <p>
			 * Transposes this matrix.
			 * </p>
			 */
			void transpose();

		private:
			Data data[Columns * Rows];
	};

	/**
	 * <p>
	 * A 3x3 floating point matrix.
	 * </p>
	 */
	typedef Matrix<float, 3, 3> Matrix33;

	/**
	 * <p>
	 * A 4x4 floating point matrix.
	 * </p>
	 */
	typedef Matrix<float, 4, 4> Matrix44;

	/**
	 * <p>
	 * Multiplies two matrices.
	 * </p>
	 *
	 * @param lhs The matrix on the left-hand-side of the equation.
	 * @param rhs The matrix on the right-hand-side of the equation.
	 *
	 * @return The product.
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows> operator*(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Rows, Columns>& rhs);

	/**
	 * <p>
	 * Multiplies this matrix by another matrix.
	 * </p>
	 *
	 * @param rhs The matrix to multiply this matrix by.
	 *
	 * @return This matrix.
	 */
	// Specialized for speed!
	template<>
	Matrix<float, 4, 4>& Matrix<float, 4, 4>::operator*=(const Matrix<float, 4, 4>& rhs);

	/**
	 * <p>
	 * Determines if two matrices are unequal.
	 * </p>
	 *
	 * @param lhs The matrix on the left-hand-side of the equation.
	 * @param rhs The matrix on the right-hand-side of the equation.
	 *
	 * @return True if the matrices are unequal, false otherwise.
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	bool operator!=(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Columns, Rows>& rhs);

	/**
	 * <p>
	 * Sends a textual representation of a matrix to an output stream.
	 * </p>
	 *
	 * @param stream The output stream.
	 * @param matrix The matrix.
	 *
	 * @return The output stream.
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	std::ostream& operator<<(std::ostream& stream, const Matrix<Data, Columns, Rows>& matrix);

	/**
	 * <p>
	 * Determines if two matrices are equal.
	 * </p>
	 *
	 * @param lhs The matrix on the left-hand-side of the equation.
	 * @param rhs The matrix on the right-hand-side of the equation.
	 *
	 * @return True if the matrices are equal, false otherwise.
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	bool operator==(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Columns, Rows>& rhs);
}

#include "Matrix.tpp"

#endif /* MATRIX_H_ */
