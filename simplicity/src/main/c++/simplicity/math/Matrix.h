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
#include <memory>

namespace simplicity
{
	template<typename Data, unsigned int Size>
	class Vector;

	/**
	 * <p>
	 * A matrix.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	template<typename Data = float, unsigned int Size = 16, unsigned int Height = 4>
	class Matrix
	{
		public:
			/**
			 * <p>
			 * Disposes of an instance of <code>Matrix</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~Matrix()
			{
			}

			/**
			 * <p>
			 * Retrieves the data for this <code>Matrix</code>.
			 * </p>
			 *
			 * @return The data for this <code>Matrix</code>.
			 */
			virtual std::array<Data, Size>& getData() = 0;

			/**
			 * <p>
			 * Retrieves the data for this <code>Matrix</code>.
			 * </p>
			 *
			 * @return The data for this <code>Matrix</code>.
			 */
			virtual const std::array<Data, Size>& getData() const = 0;

			/**
			 * <p>
			 * Retrieves the determinant of this <code>Matrix</code>.
			 * </p>
			 *
			 * @return The determinant of this <code>Matrix</code>.
			 */
			virtual Data getDeterminant() const = 0;

			/**
			 * <p>
			 * Attempts to set this <code>Matrix</code> to the inverse of this <code>Matrix</code>.
			 * </p>
			 *
			 * @throw SEInvalidOperationException If this <code>SimpleMatrix44</code> has a determinant of 0.
			 */
			virtual void invert() = 0;

			friend bool operator!=(const Matrix<Data, Size>& lhs, const Matrix<Data, Size>& rhs)
			{
				// Allows polymorphic equality checking.
				return (!lhs.equals(rhs));
			}

			/**
			 * <p>
			 * Multiplies this <code>Matrix</code> with the <code>Matrix</code> given. The <code>Matrix</code> given is
			 * placed on the right hand side of the equation.
			 * </p>
			 *
			 * @param leftMatrix The <code>Matrix</code> to be placed on the right hand side of the multiplication with
			 * this <code>Matrix</code>.
			 *
			 * @return The result of the multiplication.
			 */
			virtual std::unique_ptr<Matrix<Data, Size> > operator*(const Matrix<Data, Size>& rhs) const = 0;

			/**
			 * <p>
			 * Multiplies this <code>Matrix</code> with the {@link simplicity::Vector Vector} given. The
			 * <code>Vector</code> is treated as a column vector and multiplied as follows:
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
			 * @param rhs The <code>Vector</code> to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication.
			 */
			virtual std::unique_ptr<Vector<Data, Height> > operator*(const Vector<Data, Height>& rhs) const = 0;

			/**
			 * <p>
			 * Multiplies this <code>Matrix</code> with the <code>Matrix</code> given. The <code>Matrix</code> given is
			 * placed on the right hand side of the equation.
			 * </p>
			 *
			 * @param rhs The <code>Matrix</code> to be placed on the right hand side of the multiplication with
			 * this <code>Matrix</code>.
			 *
			 * @return The result of the multiplication (this <code>Matrix</code>).
			 */
			virtual Matrix<Data, Size>& operator*=(const Matrix<Data, Size>& rhs) = 0;

			friend bool operator==(const Matrix<Data, Size>& lhs, const Matrix<Data, Size>& rhs)
			{
				// Allows polymorphic equality checking.
				return (lhs.equals(rhs));
			}

			/**
			 * <p>
			 * Sets the data for this <code>Matrix</code>.
			 * </p>
			 *
			 * @param data The data for this <code>Matrix</code>.
			 */
			virtual void setData(const std::array<Data, Size>& data) = 0;

			/**
			 * <p>
			 * Sets this <code>Matrix</code> to the identity matrix.
			 * </p>
			 */
			virtual void setIdentity() = 0;

			/**
			 * <p>
			 * Sets this <code>Matrix</code> to the transpose of this <code>Matrix</code>.
			 * </p>
			 */
			virtual void transpose() = 0;

		private:
			/**
			 * <p>
			 * Called by the == operator to allow polymorphic equality checking.
			 * </p>
			 *
			 * @param otherMatrix The <code>Matrix</code> to compare with this <code>Matrix</code>.
			 */
			virtual bool equals(const Matrix<Data, Size>& otherMatrix) const = 0;
	};
}

#endif /* MATRIX_H_ */
