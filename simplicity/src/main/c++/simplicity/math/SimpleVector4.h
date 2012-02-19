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
#ifndef SIMPLEVECTOR4_H_
#define SIMPLEVECTOR4_H_

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
	template<typename Data = float>
	class SimpleVector4 : public virtual Vector<Data, 4>
	{
		public:
			/**
			 * <p>
			 * The number of cells in this vector.
			 * </p>
			 */
			static const unsigned int SIZE = 4;

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
			SimpleVector4(const Data d0, const Data d1, const Data d2, const Data d3);

			/**
			 * <p>
			 * Creates an instance of <code>SimpleVector4</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleVector4</code> is initialised to the contents of the vector given.
			 * </p>
			 *
			 * @param data An array containing the initial elements of this <code>SimpleVector4</code>.
			 */
			SimpleVector4(const std::array<Data, SIZE>& data);

			/**
			 * <p>
			 * Creates an instance of <code>SimpleVector4</code>.
			 * </p>
			 *
			 * <p>
			 * The <code>SimpleVector4</code> is initialised to the contents of the vector given.
			 * </p>
			 *
			 * @param data An array containing the initial elements of this <code>SimpleVector4</code>.
			 */
			SimpleVector4(const std::array<Data, SIZE * SIZE>& data, unsigned int offset);

			std::unique_ptr<Vector<Data, SIZE> > crossProduct(const Vector<Data, SIZE>& rhs) const;

			Data dotProduct(const Vector<Data, SIZE>& otherVector);

			std::array<Data, SIZE>& getData();

			const std::array<Data, SIZE>& getData() const;

			Data getLength() const;

			Data getLengthSquared() const;

			void homogenize();

			void negate();

			void normalize();

			std::unique_ptr<Vector<Data, SIZE> > operator-(const Vector<Data, SIZE>& rhs) const;

			std::unique_ptr<Vector<Data, SIZE> > operator*(const Data rhs) const;

			std::unique_ptr<Vector<Data, SIZE> > operator*(const Matrix<Data, SIZE * SIZE>& rhs) const;

			std::unique_ptr<Vector<Data, SIZE> > operator*(const Vector<Data, SIZE>& rhs) const;

			Vector<Data, SIZE>& operator*=(const Data rhs);

			Vector<Data, SIZE>& operator*=(const Matrix<Data, SIZE * SIZE>& rhs);

			Vector<Data, SIZE>& operator*=(const Vector<Data, SIZE>& rhs);

			std::unique_ptr<Vector<Data, SIZE> > operator+(const Vector<Data, SIZE>& rhs) const;

			Vector<Data, SIZE>& operator+=(const Vector<Data, SIZE>& rhs);

			Vector<Data, SIZE>& operator-=(const Vector<Data, SIZE>& rhs);

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
			std::string toString() const;

		private:
			/**
			 * <p>
			 * The array that contains the data for this <code>SimpleVector4</code>.
			 * </p>
			 */
			std::array<Data, SIZE> data;

			/**
			 * <p>
			 * Adds the <code>SimpleVector4</code> data given.
			 * <p>
			 *
			 * <p>
			 * This method assumes both <code>SimSimpleVector4pleVector</code>s to be homogenised.
			 * </p>
			 *
			 * @param lhs The data to be placed on the left hand side of the equation.
			 * @param rhs The data to be placed on the right hand side of the equation.
			 */
			void add(std::array<Data, SIZE>& lhs, const std::array<Data, SIZE>& rhs);

			bool equals(const Vector<Data, SIZE>& otherVector) const;

			/**
			 * <p>
			 * Multiplies the <code>SimpleVector4</code> data given.
			 * </p>
			 *
			 * <p>
			 * This method assumes both <code>SimpleVector4</code>s to be homogenised.
			 * </p>
			 *
			 * @param lhs The data to be placed on the left hand side of the equation.
			 * @param rhs The data to be placed on the right hand side of the equation.
			 */
			void multiply(std::array<Data, SIZE>& lhs, const std::array<Data, SIZE>& rhs) const;

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
			 * @param lhs The <code>SimpleVector4</code> data to be placed on the left hand side of the equation.
			 * @param rhs The <code>SimpleMatrix44</code> data to be placed on the right hand side of the equation.
			 *
			 * @return The result of the multiplication.
			 */
			std::array<Data, SIZE> multiplyWithMatrix(const std::array<Data, SIZE>& lhs,
			const std::array<Data, SIZE * SIZE>& rhs) const;

			/**
			 * <p>
			 * Scales the <code>SimpleVector4</code> data given.
			 * </p>
			 *
			 * @param lhs The data to be scaled.
			 * @param rhs The scalar.
			 */
			void scale(std::array<Data, SIZE>& lhs, const Data rhs);

			void setData(const std::array<Data, SIZE>& data);

			/**
			 * <p>
			 * Performs a subtraction of the <code>SimpleVector4</code> data given.
			 * </p>
			 *
			 * @param lhs The data to be placed on the left hand side of the equation.
			 * @param rhs The data to be placed on the right hand side of the equation.
			 *
			 * @return The result of the subtraction.
			 */
			void subtract(std::array<Data, SIZE>& lhs, const std::array<Data, SIZE>& rhs);
	};
}

#include "SimpleVector4.tpp"

#endif /* SIMPLEVECTOR4_H_ */
