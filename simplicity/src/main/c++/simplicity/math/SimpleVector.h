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
#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

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
	template<typename Data = float, unsigned int Size = 4>
	class SimpleVector : public virtual Vector<Data, Size>
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimpleVector</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleVector</code> is initialised to <code>(0.0, 0.0, 0.0, 1.0)</code>.
			 * </p>
			 */
			SimpleVector();

			/**
			 * <p>
			 * Creates an instance of <code>SimpleVector</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleVector</code> is initialised to the components given.
			 * </p>
			 *
			 * @param d0 The first element of data in this <code>SimpleVector</code>.
			 * @param d1 The second element of data in this <code>SimpleVector</code>.
			 * @param d2 The third element of data in this <code>SimpleVector</code>.
			 * @param d3 The fourth element of data in this <code>SimpleVector</code>.
			 */
			SimpleVector(const Data d0, const Data d1, const Data d2, const Data d3);

			/**
			 * <p>
			 * Creates an instance of <code>SimpleVector</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleVector</code> is initialised to the contents of the vector given.
			 * </p>
			 *
			 * @param data An array containing the initial elements of this <code>SimpleVector</code>.
			 */
			SimpleVector(const std::array<Data, Size>& data);

			/**
			 * <p>
			 * Creates an instance of <code>SimpleVector</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleVector</code> is initialised to the contents of the vector given.
			 * </p>
			 *
			 * @param data An array containing the initial elements of this <code>SimpleVector</code>.
			 */
			SimpleVector(const std::array<Data, Size * Size>& data, unsigned int offset);

			std::unique_ptr<Vector<Data, Size> > crossProduct(const Vector<Data, Size>& rhs) const;

			Data dotProduct(const Vector<Data, Size>& otherVector);

			std::array<Data, Size>& getData();

			const std::array<Data, Size>& getData() const;

			Data getLength() const;

			Data getLengthSquared() const;

			void homogenize();

			void negate();

			void normalize();

			std::unique_ptr<Vector<Data, Size> > operator-(const Vector<Data, Size>& rhs) const;

			std::unique_ptr<Vector<Data, Size> > operator*(const Data rhs) const;

			std::unique_ptr<Vector<Data, Size> > operator*(const Matrix<Data, Size, Size>& rhs) const;

			std::unique_ptr<Vector<Data, Size> > operator*(const Vector<Data, Size>& rhs) const;

			Vector<Data, Size>& operator*=(const Data rhs);

			Vector<Data, Size>& operator*=(const Matrix<Data, Size, Size>& rhs);

			Vector<Data, Size>& operator*=(const Vector<Data, Size>& rhs);

			std::unique_ptr<Vector<Data, Size> > operator+(const Vector<Data, Size>& rhs) const;

			Vector<Data, Size>& operator+=(const Vector<Data, Size>& rhs);

			Vector<Data, Size>& operator-=(const Vector<Data, Size>& rhs);

			/**
			 * <p>
			 * Retrieves a textual representation of this <code>SimpleVector</code> in the following format.
			 * </p>
			 *
			 * <pre>
			 * ----------------
			 *  x | y | z | w |
			 * ----------------
			 * </pre>
			 *
			 * @return A textual representation of this <code>SimpleVector</code>.
			 */
			std::string toString() const;

		private:
			/**
			 * <p>
			 * The array that contains the data for this <code>SimpleVector</code>.
			 * </p>
			 */
			std::array<Data, Size> data;

			/**
			 * <p>
			 * Adds the <code>SimpleVector</code> data given.
			 * <p>
			 *
			 * <p>
			 * This method assumes both <code>SimSimpleVectorpleVector</code>s to be homogenised.
			 * </p>
			 *
			 * @param lhs The data to be placed on the left hand side of the equation.
			 * @param rhs The data to be placed on the right hand side of the equation.
			 */
			void add(std::array<Data, Size>& lhs, const std::array<Data, Size>& rhs);

			bool equals(const Vector<Data, Size>& otherVector) const;

			/**
			 * <p>
			 * Multiplies the <code>SimpleVector</code> data given.
			 * </p>
			 *
			 * <p>
			 * This method assumes both <code>SimpleVector</code>s to be homogenised.
			 * </p>
			 *
			 * @param lhs The data to be placed on the left hand side of the equation.
			 * @param rhs The data to be placed on the right hand side of the equation.
			 */
			void multiply(std::array<Data, Size>& lhs, const std::array<Data, Size>& rhs) const;

			/**
			 * <p>
			 * Multiplies this <code>SimpleVector</code> with the
			 * {@link com.se.simplicity.vector.SimpleMatrix SimpleMatrix} given. This <code>SimpleVector</code> is
			 * treated as a row vector and multiplied as follows:
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
			 * @param lhs The <code>SimpleVector</code> data to be placed on the left hand side of the equation.
			 * @param rhs The <code>SimpleMatrix</code> data to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication.
			 */
			std::array<Data, Size> multiplyWithMatrix(const std::array<Data, Size>& lhs,
			const std::array<Data, Size * Size>& rhs) const;

			/**
			 * <p>
			 * Scales the <code>SimpleVector</code> data given.
			 * </p>
			 *
			 * @param lhs The data to be scaled.
			 * @param rhs The scalar.
			 */
			void scale(std::array<Data, Size>& lhs, const Data rhs);

			void setData(const std::array<Data, Size>& data);

			/**
			 * <p>
			 * Performs a subtraction of the <code>SimpleVector</code> data given.
			 * </p>
			 *
			 * @param lhs The data to be placed on the left hand side of the equation.
			 * @param rhs The data to be placed on the right hand side of the equation.
			 *
			 * @return The result of the subtraction.
			 */
			void subtract(std::array<Data, Size>& lhs, const std::array<Data, Size>& rhs);
	};
}

#include "SimpleVector.tpp"

#endif /* SIMPLEVECTOR_H_ */
