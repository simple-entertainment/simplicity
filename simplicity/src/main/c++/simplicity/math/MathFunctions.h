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
	/**
	 * <p>
	 * Retrieves the outward facing (negative z) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The outward facing (negative z) axis.
	 */
	template<typename Data>
	Vector<Data, 3> getOut3(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the outward facing (negative z) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The outward facing (negative z) axis.
	 */
	template<typename Data>
	const Vector<Data, 3> getOut3(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the outward facing (negative z) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The outward facing (negative z) axis.
	 */
	template<typename Data>
	Vector<Data, 4> getOut4(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the outward facing (negative z) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The outward facing (negative z) axis.
	 */
	template<typename Data>
	const Vector<Data, 4> getOut4(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the position of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The position.
	 */
	template<typename Data>
	Vector<Data, 2> getPosition2(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the position of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The position.
	 */
	template<typename Data>
	const Vector<Data, 2> getPosition2(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the position of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The position.
	 */
	template<typename Data>
	Vector<Data, 3> getPosition3(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the position of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The position.
	 */
	template<typename Data>
	const Vector<Data, 3> getPosition3(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the position of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The position.
	 */
	template<typename Data>
	Vector<Data, 4> getPosition4(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the position of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The position.
	 */
	template<typename Data>
	const Vector<Data, 4> getPosition4(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the projection of a vector onto a plane.
	 * </p>
	 *
	 * @param projectee The vector to project.
	 * @param target The plane to project onto.
	 *
	 * @return The projection.
	 */
	template<typename Data>
	Vector<Data, 3> getProjection(const Vector<Data, 3>& projectee, const Plane& target);

	/**
	 * <p>
	 * Retrieves a random boolean value.
	 * </p>
	 *
	 * @return A random boolean value.
	 */
	SIMPLE_API bool getRandomBool();

	/**
	 * <p>
	 * Retrieves a random boolean value.
	 * </p>
	 *
	 * @param trueChance A value in the range [0,1] where 1 is a 100% chance of true being returned and 0 is a 0%
	 * chance of true being returned.
	 *
	 * @return A random boolean value.
	 */
	SIMPLE_API bool getRandomBool(float trueChance);

	/**
	 * <p>
	 * Retrieves a random floating point value within the specified range.
	 * </p>
	 *
	 * @param min The minimum value that can be returned.
	 * @param max The maximum value that can be returned.
	 *
	 * @return A random floating point value.
	 */
	SIMPLE_API float getRandomFloat(float min, float max);

	/**
	 * <p>
	 * Retrieves a random integer value within the specified range.
	 * </p>
	 *
	 * @param min The minimum value that can be returned.
	 * @param max The maximum value that can be returned.
	 *
	 * @return A random integer value.
	 */
	SIMPLE_API int getRandomInt(int min, int max);

	/**
	 * <p>
	 * Retrieves the rightward facing (positive x) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The rightward facing (positive x) axis.
	 */
	template<typename Data>
	Vector<Data, 3> getRight3(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the rightward facing (positive x) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The rightward facing (positive x) axis.
	 */
	template<typename Data>
	const Vector<Data, 3> getRight3(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the rightward facing (positive x) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The rightward facing (positive x) axis.
	 */
	template<typename Data>
	Vector<Data, 4> getRight4(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the rightward facing (positive x) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The rightward facing (positive x) axis.
	 */
	template<typename Data>
	const Vector<Data, 4> getRight4(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the rightward facing (positive y) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The rightward facing (positive y) axis.
	 */
	template<typename Data>
	Vector<Data, 3> getUp3(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the rightward facing (positive y) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The rightward facing (positive y) axis.
	 */
	template<typename Data>
	const Vector<Data, 3> getUp3(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the rightward facing (positive y) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The rightward facing (positive y) axis.
	 */
	template<typename Data>
	Vector<Data, 4> getUp4(Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Retrieves the rightward facing (positive y) axis of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 *
	 * @return The rightward facing (positive y) axis.
	 */
	template<typename Data>
	const Vector<Data, 4> getUp4(const Matrix<Data, 4, 4>& matrix);

	/**
	 * <p>
	 * Determines if two floating point values are 'near' to each-other. This helps to determine equality of values
	 * which have been derived through different calculations and as a result of floating point inaccuracy are slightly
	 * different.
	 * </p>
	 *
	 * @param a The first floating point value.
	 * @param b The second floating point value.
	 *
	 * @return True if the floating point values are within 4dp of each-other, false otherwise.
	 */
	SIMPLE_API bool near(float a, float b);

	/**
	 * <p>
	 * Determines if all the corresponding values of two vectors are 'near' to each-other. This helps to determine
	 * equality of vectors which have been derived through different calculations and as a result of floating point
	 * inaccuracy are slightly different.
	 * </p>
	 *
	 * @param a The first vector.
	 * @param b The second vector.
	 *
	 * @return True if all the corresponding values of the vectors are within 4dp of each-other, false otherwise.
	 */
	template<typename Data, unsigned int Size>
	bool near(const Vector<Data, Size>& a, const Vector<Data, Size>& b);

	/**
	 * <p>
	 * Multiplies a vector with a matrix. The vector is placed on the right hand side of the equation and treated as a
	 * column vector:
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
	 *
	 * @param matrix The matrix.
	 * @param vector The vector.
	 *
	 * @return The product.
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	Vector<Data, Rows> operator*(const Matrix<Data, Columns, Rows>& matrix, const Vector<Data, Rows>& vector);

	/**
	 * <p>
	 * Multiplies a vector with a matrix. The vector is placed on the left hand side of the equation and treated as a
	 * row vector:
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
	 *
	 * @param vector The vector.
	 * @param matrix The matrix.
	 *
	 * @return The product.
	 */
	template<typename Data, unsigned int Columns, unsigned int Rows>
	Vector<Data, Columns> operator*(const Vector<Data, Columns>& vector, const Matrix<Data, Columns, Rows>& matrix);

	/**
	 * <p>
	 * Rotates a rotation matrix around an axis.
	 * </p>
	 *
	 * @param matrix The matrix to rotate.
	 * @param angle The angle to rotate the matrix.
	 * @param axis The axis to rotate the matrix around.
	 */
	template<typename Data>
	void rotate(Matrix<Data, 3, 3>& matrix, const Data angle, const Vector<Data, 3>& axis);

	/**
	 * <p>
	 * Rotates a transformation matrix around an axis.
	 * </p>
	 *
	 * @param matrix The matrix to rotate.
	 * @param angle The angle to rotate the matrix.
	 * @param axis The axis to rotate the matrix around.
	 */
	template<typename Data>
	void rotate(Matrix<Data, 4, 4>& matrix, const Data angle, const Vector<Data, 3>& axis);

	/**
	 * <p>
	 * Rotates a transformation matrix around an axis.
	 * </p>
	 *
	 * @param matrix The matrix to rotate.
	 * @param angle The angle to rotate the matrix.
	 * @param axis The axis to rotate the matrix around.
	 */
	template<typename Data>
	void rotate(Matrix<Data, 4, 4>& matrix, const Data angle, const Vector<Data, 4>& axis);

	/**
	 * <p>
	 * Scales a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix to scale.
	 * @param scale The scalar.
	 */
	template<typename Data>
	void scale(Matrix<Data, 4, 4>& matrix, const Vector<Data, 3>& scale);

	/**
	 * <p>
	 * Sets the position of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 * @param position The position.
	 */
	template<typename Data>
	void setPosition(Matrix<Data, 4, 4>& matrix, const Vector<Data, 3>& position);

	/**
	 * <p>
	 * Sets the position of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 * @param position The position.
	 */
	template<typename Data>
	void setPosition(Matrix<Data, 4, 4>& matrix, const Vector<Data, 4>& position);

	/**
	 * <p>
	 * Sets the seed used to generate random numbers.
	 * </p>
	 *
	 * @param seed The random number generator seed.
	 */
	SIMPLE_API void setRandomSeed(unsigned int seed);

	/**
	 * <p>
	 * Sets the scale of a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix.
	 * @param scale The scalar.
	 */
	template<typename Data>
	void setScale(Matrix<Data, 4, 4>& matrix, const Vector<Data, 3>& scale);

	/**
	 * <p>
	 * Translates a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix to translate.
	 * @param translation The translation.
	 */
	template<typename Data>
	void translate(Matrix<Data, 4, 4>& matrix, const Vector<Data, 3>& translation);

	/**
	 * <p>
	 * Translates a transformation matrix.
	 * </p>
	 *
	 * @param matrix The matrix to translate.
	 * @param translation The translation.
	 */
	template<typename Data>
	void translate(Matrix<Data, 4, 4>& matrix, const Vector<Data, 4>& translation);
}

#include "MathFunctions.tpp"

#endif /* MATHFUNCTIONS_H_ */
