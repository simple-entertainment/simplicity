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
	template<typename Data = float, unsigned int Size = 4>
	class Vector
	{
		public:
			/**
			 * <p>
			 * Disposes of an instance of <code>Vector</code> (included to allow polymorphic deletion).
			 * </p>
			 */
			virtual ~Vector()
			{
			}

			/**
			 * <p>
			 * Performs a cross product of this <code>Vector</code> and the <code>Vector</code> given. The
			 * <code>Vector</code> given is placed on the right hand side of the equation.
			 * </p>
			 *
			 * <p>
			 * This method assumes both <code>Vector</code>s to be homogenised.
			 * </p>
			 *
			 * @param rhs The <code>Vector</code> to be placed on the right hand side of the equation.
			 *
			 * @return A new <code>Vector</code> that is the result of the cross product of this <code>Vector</code> and
			 * the <code>Vector</code> given.
			 */
			virtual std::unique_ptr<Vector<Data, Size> > crossProduct(const Vector<Data, Size>& rhs) const = 0;

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
			virtual float dotProduct(const Vector<Data, Size>& otherVector) = 0;

			/**
			 * <p>
			 * Retrieves the data for this <code>Vector</code>.
			 * </p>
			 *
			 * @return The data for this <code>Vector</code>.
			 */
			virtual std::array<Data, Size>& getData() = 0;

			/**
			 * <p>
			 * Retrieves the data for this <code>Vector</code>.
			 * </p>
			 *
			 * @return The data for this <code>Vector</code>.
			 */
			virtual const std::array<Data, Size>& getData() const = 0;

			/**
			 * <p>
			 * Retrieves the length of this <code>Vector</code>.
			 * </p>
			 *
			 * @return The length of this <code>Vector</code>.
			 */
			virtual Data getLength() const = 0;

			/**
			 * <p>
			 * Retrieves the length of this <code>Vector</code> squared.
			 * </p>
			 *
			 * @return The length of this <code>Vector</code> squared.
			 */
			virtual Data getLengthSquared() const = 0;

			/**
			 * <p>
			 * Homogenises this <code>Vector</code>.
			 * </p>
			 *
			 * <p>
			 * Scales all values equally so that the <code>w</code> value of this <code>Vector</code> is
			 * <code>1.0f</code>.
			 * </p>
			 */
			virtual void homogenize() = 0;

			/**
			 * <p>
			 * Negates this <code>Vector</code>.
			 * </p>
			 */
			virtual void negate() = 0;

			/**
			 * <p>
			 * Scales this <code>Vector</code> to a unit length vector.
			 * </p>
			 */
			virtual void normalize() = 0;

			friend bool operator!=(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
			{
				// Allows polymorphic equality checking.
				return (!lhs.equals(rhs));
			}

			/**
			 * <p>
			 * Subtracts the <code>Vector</code> given from this <code>Vector</code>.
			 * <p>
			 *
			 * <p>
			 * This method assumes both <code>Vector</code>s to be homogenised.
			 * </p>
			 *
			 * @param rhs The <code>Vector</code> to subtract from this <code>Vector</code>.
			 *
			 * @return The result of the subtraction.
			 */
			virtual std::unique_ptr<Vector<Data, Size> > operator-(const Vector<Data, Size>& rhs) const = 0;

			/**
			 * <p>
			 * Scales this <code>Vector</code> by the scalar given.
			 * </p>
			 *
			 * @param rhs The scalar.
			 *
			 * @return The result of the scale.
			 */
			virtual std::unique_ptr<Vector<Data, Size> > operator*(const Data rhs) const = 0;

			/**
			 * <p>
			 * Multiplies this <code>Vector</code> with the {@link simplicity::Matrix Matrix} given. This
			 * <code>Vector</code> is treated as a row vector and multiplied as follows:
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
			 * @param matrix The <code>Matrix</code> to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication.
			 */
			virtual std::unique_ptr<Vector<Data, Size> > operator*(const Matrix<Data, Size * Size>& rhs) const = 0;

			/**
			 * <p>
			 * Subtracts the <code>Vector</code> given from this <code>Vector</code>.
			 * </p>
			 *
			 * @param rhs The <code>Vector</code> to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication.
			 */
			virtual std::unique_ptr<Vector<Data, Size> > operator*(const Vector<Data, Size>& rhs) const = 0;

			/**
			 * <p>
			 * Scales this <code>Vector</code> by the scalar given.
			 * </p>
			 *
			 * @param rhs The scalar.
			 *
			 * @return The result of the scale (this <code>Vector</code>).
			 */
			virtual Vector<Data, Size>& operator*=(const Data rhs) = 0;

			/**
			 * <p>
			 * Multiplies this <code>Vector</code> with the {@link simplicity::Matrix Matrix} given. This
			 * <code>Vector</code> is treated as a row vector and multiplied as follows:
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
			 * @param matrix The <code>Matrix</code> to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication (this <code>Vector</code>).
			 */
			virtual Vector<Data, Size>& operator*=(const Matrix<Data, Size * Size>& rhs) = 0;

			/**
			 * <p>
			 * Subtracts the <code>Vector</code> given from this <code>Vector</code>.
			 * </p>
			 *
			 * @param rhs The <code>Vector</code> to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication (this <code>Vector</code>).
			 */
			virtual Vector<Data, Size>& operator*=(const Vector<Data, Size>& rhs) = 0;

			/**
			 * <p>
			 * Adds the <code>Vector</code> given to this <code>Vector</code>.
			 * <p>
			 *
			 * <p>
			 * This method assumes both <code>Vector</code>s to be homogenised.
			 * </p>
			 *
			 * @param rhs The <code>Vector</code> to add to this <code>Vector</code>.
			 *
			 * @return The result of the addition.
			 */
			virtual std::unique_ptr<Vector<Data, Size> > operator+(const Vector<Data, Size>& rhs) const = 0;

			/**
			 * <p>
			 * Adds the <code>Vector</code> given to this <code>Vector</code>.
			 * <p>
			 *
			 * <p>
			 * This method assumes both <code>Vector</code>s to be homogenised.
			 * </p>
			 *
			 * @param rhs The <code>Vector</code> to add to this <code>Vector</code>.
			 *
			 * @return The result of the addition (this <code>Vector</code>).
			 */
			virtual Vector<Data, Size>& operator+=(const Vector<Data, Size>& rhs) = 0;

			/**
			 * <p>
			 * Subtracts the <code>Vector</code> given from this <code>Vector</code>.
			 * <p>
			 *
			 * <p>
			 * This method assumes both <code>Vector</code>s to be homogenised.
			 * </p>
			 *
			 * @param rhs The <code>Vector</code> to subtract from this <code>Vector</code>.
			 *
			 * @return The result of the subtraction (this <code>Vector</code>).
			 */
			virtual Vector<Data, Size>& operator-=(const Vector<Data, Size>& rhs) = 0;

			friend bool operator==(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
			{
				// Allows polymorphic equality checking.
				return (lhs.equals(rhs));
			}

			/**
			 * <p>
			 * Sets the data for this <code>Vector</code>.
			 * </p>
			 *
			 * @param data The data for this <code>Vector</code>.
			 */
			virtual void setData(const std::array<Data, Size>& data) = 0;

		private:
			/**
			 * <p>
			 * Called by the == operator to allow polymorphic equality checking.
			 * </p>
			 *
			 * @param otherVector The <code>Vector</code> to compare with this <code>Vector</code>.
			 */
			virtual bool equals(const Vector<Data, Size>& otherVector) const = 0;
	};
}

#endif /* VECTOR_H_ */
