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
	 * A matrix.
	 * </p>
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	class Matrix
	{
		public:
			Matrix();

			Matrix(const Matrix<Data, Columns, Rows>& original);

			Matrix(const std::array<Data, Columns * Rows>& data);

			Matrix(Data* data);

			Data* getData();

			const Data* getData() const;

			Data getDeterminant() const;

			void invert();

			Data& operator[](unsigned int index);

			const Data& operator[](unsigned int index) const;

			Matrix<Data, Columns, Rows>& operator*=(const Matrix<Data, Rows, Columns>& rhs);

			Matrix<Data, Columns, Rows>& operator=(const Matrix<Data, Columns, Rows>& original);

			void setData(const std::array<Data, Columns * Rows>& data);

			void setData(Data* data);

			void setIdentity();

			void transpose();

		private:
			Data data[Columns * Rows];
	};

	typedef Matrix<float, 3, 3> Matrix33;

	typedef Matrix<float, 4, 4> Matrix44;

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows> operator*(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Rows, Columns>& rhs);

	template<typename Data, unsigned int Columns, unsigned int Rows>
	bool operator!=(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Columns, Rows>& rhs);

	template<typename Data, unsigned int Columns, unsigned int Rows>
	std::ostream& operator<<(std::ostream& stream, const Matrix<Data, Columns, Rows>& matrix);

	template<typename Data, unsigned int Columns, unsigned int Rows>
	bool operator==(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Columns, Rows>& rhs);
}

#include "Matrix.tpp"

#endif /* MATRIX_H_ */
