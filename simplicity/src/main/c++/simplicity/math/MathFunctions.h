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
#ifndef MATHFUNCTIONS_H_
#define MATHFUNCTIONS_H_

#include "../model/Plane.h"
#include "Matrix.h"
#include "Vector.h"

namespace simplicity
{
	template<typename Data>
	Data crossProduct(const Vector<Data, 2>& lhs, const Vector<Data, 2>& rhs);

	template<typename Data>
	Vector<Data, 3> crossProduct(const Vector<Data, 3>& lhs, const Vector<Data, 3>& rhs);

	template<typename Data>
	float getAngleBetween(const Vector<Data, 2>& lhs, const Vector<Data, 2>& rhs);

	template<typename Data>
	float getAngleBetween(const Vector<Data, 3>& lhs, const Vector<Data, 3>& rhs);

	template<typename Data>
	float getAngleBetweenNormalized(const Vector<Data, 2>& lhs, const Vector<Data, 2>& rhs);

	template<typename Data>
	float getAngleBetweenNormalized(const Vector<Data, 3>& lhs, const Vector<Data, 3>& rhs);

	template<typename Data>
	Vector<Data, 3> getOut3(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 3> getOut3(const Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	Vector<Data, 4> getOut4(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 4> getOut4(const Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	Vector<Data, 3> getProjection(const Vector<Data, 3>& lhs, const Plane& rhs);

	template<typename Data, unsigned int Size>
	Vector<Data, Size> getProjection(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	template<typename Data>
	Data getProximity(const Vector<Data, 2>& lhs, const Vector<Data, 2>& rhs);

	template<typename Data>
	Data getProximity(const Vector<Data, 3>& lhs, const Vector<Data, 3>& rhs);

	bool getRandomBool();

	bool getRandomBool(float trueChance);

	float getRandomFloat(float min, float max);

	int getRandomInt(int min, int max);

	template<typename Data>
	Vector<Data, 3> getRight3(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 3> getRight3(const Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	Vector<Data, 4> getRight4(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 4> getRight4(const Matrix<Data, 4, 4>& matrix);

	template<typename Data, unsigned int Size>
	float getScalarProjection(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	template<typename Data>
	Vector<Data, 2> getPosition2(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 2> getPosition2(const Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	Vector<Data, 3> getPosition3(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 3> getPosition3(const Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	Vector<Data, 4> getPosition4(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 4> getPosition4(const Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	Vector<Data, 3> getUp3(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 3> getUp3(const Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	Vector<Data, 4> getUp4(Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	const Vector<Data, 4> getUp4(const Matrix<Data, 4, 4>& matrix);

	template<typename Data>
	void homogenize(Vector<Data, 2>& vector);

	bool near(float a, float b);

	/**
	 * <p>
	 * Multiplies the given Vector with the given Matrix. The Vector is placed on the right hand side of the
	 * equation and treated as a column vector:
	 * </p>
	 *
	 * ----------------     -----
	 *  x | x | x | x |  *  | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	Vector<Data, Rows> operator*(const Matrix<Data, Columns, Rows>& matrix, const Vector<Data, Rows>& vector);

	/**
	 * <p>
	 * Multiplies the given Vector with the given Matrix. The Vector is placed on the left hand side of the
	 * equation and treated as a row vector:
	 * </p>
	 *
	 * -----------------     -----------------
	 * | x | x | x | x |  *  | x | x | x | x |
	 * -----------------     -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	Vector<Data, Columns> operator*(const Vector<Data, Columns>& vector, const Matrix<Data, Columns, Rows>& matrix);

	template<typename Data>
	void rotate(Matrix<Data, 3, 3>& matrix, const Data angle, const Vector<Data, 3>& axis);

	template<typename Data>
	void rotate(Matrix<Data, 4, 4>& matrix, const Data angle, const Vector<Data, 3>& axis);

	template<typename Data>
	void rotate(Matrix<Data, 4, 4>& matrix, const Data angle, const Vector<Data, 4>& axis);

	template<typename Data>
	void rotate(Vector<Data, 2>& vector, const Data angle);

	template<typename Data>
	void scale(Matrix<Data, 4, 4>& matrix, const Vector<Data, 3>& scale);

	template<typename Data>
	void setPosition(Matrix<Data, 4, 4>& matrix, const Vector<Data, 3>& position);

	template<typename Data>
	void setPosition(Matrix<Data, 4, 4>& matrix, const Vector<Data, 4>& position);

	template<typename Data>
	void setScale(Matrix<Data, 4, 4>& matrix, const Vector<Data, 3>& scale);

	template<typename Data>
	void translate(Matrix<Data, 4, 4>& matrix, const Vector<Data, 3>& translation);

	template<typename Data>
	void translate(Matrix<Data, 4, 4>& matrix, const Vector<Data, 4>& translation);
}

#include "MathFunctions.tpp"

#endif /* MATHFUNCTIONS_H_ */
