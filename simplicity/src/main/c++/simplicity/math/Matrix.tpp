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
#include <algorithm>
#include <cstring>

#include "Matrix.h"

namespace simplicity
{
	template<typename Data>
	Data getDeterminant33(const Data d00, const Data d10, const Data d20,
		const Data d01, const Data d11, const Data d21, const Data d02, const Data d12, const Data d22);

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows>::Matrix() :
		data()
	{
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows>::Matrix(const Matrix<Data, Columns, Rows>& original) :
		data()
	{
		operator=(original);
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows>::Matrix(const std::array<Data, Columns * Rows>& data) :
		data()
	{
		setData(data);
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows>::Matrix(Data* data) :
		data()
	{
		setData(data);
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Data* Matrix<Data, Columns, Rows>::getData()
	{
		return data;
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	const Data* Matrix<Data, Columns, Rows>::getData() const
	{
		return data;
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Data Matrix<Data, Columns, Rows>::getDeterminant() const
	{
		Data determinant = data[0]
			* ((data[5] * data[10] * data[15] + data[6] * data[11] * data[13]
				+ data[7] * data[9] * data[14]) - data[7] * data[10] * data[13]
				- data[5] * data[11] * data[14] - data[6] * data[9] * data[15]);

		determinant -= data[1]
			* ((data[4] * data[10] * data[15] + data[6] * data[11] * data[12]
				+ data[7] * data[8] * data[14]) - data[7] * data[10] * data[12]
				- data[4] * data[11] * data[14] - data[6] * data[8] * data[15]);

		determinant += data[2]
			* ((data[4] * data[9] * data[15] + data[5] * data[11] * data[12]
				+ data[7] * data[8] * data[13]) - data[7] * data[9] * data[12]
				- data[4] * data[11] * data[13] - data[5] * data[8] * data[15]);

		determinant -= data[3]
			* ((data[4] * data[9] * data[14] + data[5] * data[10] * data[12]
				+ data[6] * data[8] * data[13]) - data[6] * data[9] * data[12]
				- data[4] * data[10] * data[13] - data[5] * data[8] * data[14]);

		return determinant;
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	void Matrix<Data, Columns, Rows>::invert()
	{
		Data determinant = getDeterminant();

		if (determinant == 0)
		{
			//throw SEInvalidOperationException();
		}

		Data invDeterminant = 1 / determinant;

		// Calculate determinants for each value in this matrix.
		Data d00 = getDeterminant33(data[5], data[6], data[7], data[9], data[10], data[11],
			data[13], data[14], data[15]);
		Data d01 = -getDeterminant33(data[4], data[6], data[7], data[8], data[10], data[11],
			data[12], data[14], data[15]);
		Data d02 = getDeterminant33(data[4], data[5], data[7], data[8], data[9], data[11],
			data[12], data[13], data[15]);
		Data d03 = -getDeterminant33(data[4], data[5], data[6], data[8], data[9], data[10],
			data[12], data[13], data[14]);

		Data d10 = -getDeterminant33(data[1], data[2], data[3], data[9], data[10], data[11],
			data[13], data[14], data[15]);
		Data d11 = getDeterminant33(data[0], data[2], data[3], data[8], data[10], data[11],
			data[12], data[14], data[15]);
		Data d12 = -getDeterminant33(data[0], data[1], data[3], data[8], data[9], data[11],
			data[12], data[13], data[15]);
		Data d13 = getDeterminant33(data[0], data[1], data[2], data[8], data[9], data[10],
			data[12], data[13], data[14]);

		Data d20 = getDeterminant33(data[1], data[2], data[3], data[5], data[6], data[7], data[13],
			data[14], data[15]);
		Data d21 = -getDeterminant33(data[0], data[2], data[3], data[4], data[6], data[7],
			data[12], data[14], data[15]);
		Data d22 = getDeterminant33(data[0], data[1], data[3], data[4], data[5], data[7], data[12],
			data[13], data[15]);
		Data d23 = -getDeterminant33(data[0], data[1], data[2], data[4], data[5], data[6],
			data[12], data[13], data[14]);

		Data d30 = -getDeterminant33(data[1], data[2], data[3], data[5], data[6], data[7], data[9],
			data[10], data[11]);
		Data d31 = getDeterminant33(data[0], data[2], data[3], data[4], data[6], data[7], data[8],
			data[10], data[11]);
		Data d32 = -getDeterminant33(data[0], data[1], data[3], data[4], data[5], data[7], data[8],
			data[9], data[11]);
		Data d33 = getDeterminant33(data[0], data[1], data[2], data[4], data[5], data[6], data[8],
			data[9], data[10]);

		// Transpose and divide by the determinant.
		data[0] = d00 * invDeterminant;
		data[1] = d10 * invDeterminant;
		data[2] = d20 * invDeterminant;
		data[3] = d30 * invDeterminant;
		data[4] = d01 * invDeterminant;
		data[5] = d11 * invDeterminant;
		data[6] = d21 * invDeterminant;
		data[7] = d31 * invDeterminant;
		data[8] = d02 * invDeterminant;
		data[9] = d12 * invDeterminant;
		data[10] = d22 * invDeterminant;
		data[11] = d32 * invDeterminant;
		data[12] = d03 * invDeterminant;
		data[13] = d13 * invDeterminant;
		data[14] = d23 * invDeterminant;
		data[15] = d33 * invDeterminant;
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Data& Matrix<Data, Columns, Rows>::operator[](unsigned int index)
	{
		return data[index];
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	const Data& Matrix<Data, Columns, Rows>::operator[](unsigned int index) const
	{
		return data[index];
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows>& Matrix<Data, Columns, Rows>::operator*=(const Matrix<Data, Rows, Columns>& rhs)
	{
		Data productData[Columns * Rows];

		// For every row in the left hand matrix.
		for (unsigned int row = 0; row < Rows; row++)
		{
			// For every column in the right hand matrix.
			for (unsigned int column = 0; column < Columns; column++)
			{
				Data sum = 0;

				// For every element in the current row of the left hand matrix and every element in the current column
				// of the right hand matrix.
				for (unsigned int element = 0; element < Columns; element++)
				{
					// Add the product of the two to the value for the new matrix.
					sum += data[row + (element * Rows)] * rhs.getData()[column * Columns + element];
				}

				productData[column * Columns + row] = sum;
			}
		}

		memcpy(data, productData, Columns * Rows * sizeof(Data));

		return *this;
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows>& Matrix<Data, Columns, Rows>::operator=(const Matrix<Data, Columns, Rows>& original)
	{
		for (unsigned int index = 0; index < Columns * Rows; index++)
		{
			data[index] = original.data[index];
		}

		return *this;
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	void Matrix<Data, Columns, Rows>::setData(const std::array<Data, Columns * Rows>& data)
	{
		copy(begin(data.data()), end(data.data()), begin(this->data));
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	void Matrix<Data, Columns, Rows>::setData(Data* data)
	{
		copy(data, data + Columns * Rows, begin(this->data));
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	void Matrix<Data, Columns, Rows>::setIdentity()
	{
		for (unsigned int row = 0; row < Rows; row++)
		{
			for (unsigned int column = 0; column < Columns; column++)
			{
				if (column == row)
				{
					data[row * Columns + column] = 1;
				}
				else
				{
					data[row * Columns + column] = 0;
				}
			}
		}
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	void Matrix<Data, Columns, Rows>::transpose()
	{
		Data temp = 0;

		temp = data[1];
		data[1] = data[4];
		data[4] = temp;

		temp = data[2];
		data[2] = data[8];
		data[8] = temp;

		temp = data[3];
		data[3] = data[12];
		data[12] = temp;

		temp = data[6];
		data[6] = data[9];
		data[9] = temp;

		temp = data[7];
		data[7] = data[13];
		data[13] = temp;

		temp = data[11];
		data[11] = data[14];
		data[14] = temp;
	}

	template<typename Data>
	Data getDeterminant33(const Data d00, const Data d10, const Data d20,
		const Data d01, const Data d11, const Data d21, const Data d02, const Data d12, const Data d22)
	{
		return d00 * (d11 * d22 - d12 * d21) - d10 * (d01 * d22 - d02 * d21) + d20 * (d01 * d12 - d02 * d11);
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	Matrix<Data, Columns, Rows> operator*(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Rows, Columns>& rhs)
	{
		Matrix<Data, Columns, Rows> product = lhs;
		product *= rhs;

		return product;
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	bool operator!=(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Columns, Rows>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	std::ostream& operator<<(std::ostream& stream, const Matrix<Data, Columns, Rows>& matrix)
	{
		for (unsigned int row = 0; row < Rows; row++)
		{
			stream << "[";

			for (unsigned int column = 0; column < Columns; column++)
			{
				stream << matrix.getData()[row * Columns + column];
				if (column < Columns - 1)
				{
					stream << ",";
				}
			}

			stream << "]";

			if (row < Rows - 1)
			{
				stream << "\n";
			}
		}

		return stream;
	}

	template<typename Data, unsigned int Columns, unsigned int Rows>
	bool operator==(const Matrix<Data, Columns, Rows>& lhs, const Matrix<Data, Columns, Rows>& rhs)
	{
		for (unsigned int index = 0; index < Columns * Rows; index++)
		{
			if (lhs[index] != rhs[index])
			{
				return false;
			}
		}

		return true;
	}
}
