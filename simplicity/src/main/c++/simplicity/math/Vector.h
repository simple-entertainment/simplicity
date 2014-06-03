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

#include <array>
#include <ostream>

namespace simplicity
{
	/**
	 * <p>
	 * A vector.
	 * </p>
	 */
	template<typename Data, unsigned int Size>
	class Vector
	{
		public:
			Vector();

			/**
			 * @param data The data to copy into the vector.
			 */
			Vector(const std::array<Data, Size>& data);

			/**
			 * @param data The data to copy into the vector.
			 */
			Vector(Data* data);

			/**
			 * @param d0 The first element of the vector.
			 * @param d1 The second element of the vector.
			 */
			Vector(Data d0, Data d1);

			/**
			 * @param d0 The first element of the vector.
			 * @param d1 The second element of the vector.
			 * @param d2 The third element of the vector.
			 */
			Vector(Data d0, Data d1, Data d2);

			/**
			 * @param d0 The first element of the vector.
			 * @param d1 The second element of the vector.
			 * @param d2 The third element of the vector.
			 * @param d3 The fourth element of the vector.
			 */
			Vector(Data d0, Data d1, Data d2, Data d3);

			/**
			 * @param original The vector to copy.
			 */
			Vector(const Vector<Data, Size>& original);

			/**
			 * @param original The vector to copy.
			 * @param d The last element of the vector.
			 */
			Vector(const Vector<Data, Size - 1>& original, Data d);

			/**
			 * <p>
			 * Retrieves the alpha value of a color vector (the fourth element of the vector).
			 * </p>
			 *
			 * @return The alpha value.
			 */
			Data& A();

			/**
			 * <p>
			 * Retrieves the alpha value of a color vector (the fourth element of the vector).
			 * </p>
			 *
			 * @return The alpha value.
			 */
			const Data& A() const;

			/**
			 * <p>
			 * Retrieves the blue value of a color vector (the third element of the vector).
			 * </p>
			 *
			 * @return The blue value.
			 */
			Data& B();

			/**
			 * <p>
			 * Retrieves the blue value of a color vector (the third element of the vector).
			 * </p>
			 *
			 * @return The blue value.
			 */
			const Data& B() const;

			/**
			 * <p>
			 * Retrieves the green value of a color vector (the second element of the vector).
			 * </p>
			 *
			 * @return The green value.
			 */
			Data& G();

			/**
			 * <p>
			 * Retrieves the green value of a color vector (the second element of the vector).
			 * </p>
			 *
			 * @return The green value.
			 */
			const Data& G() const;

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
			 * Retrieves the magnitude of this vector (also known as the length).
			 * </p>
			 *
			 * @return The magnitude of this vector.
			 */
			Data getMagnitude() const;

			/**
			 * <p>
			 * Retrieves the squared magnitude of this vector (also known as the squared length). This is faster than
			 * retrieving the magnitude so it is good for comparing magnitudes.
			 * </p>
			 *
			 * @return The squared magnitude of this vector.
			 */
			Data getMagnitudeSquared() const;

			/**
			 * <p>
			 * Negates this vector.
			 * </p>
			 */
			void negate();

			/**
			 * <p>
			 * Normalizes this vector.
			 * </p>
			 */
			void normalize();

			/**
			 * <p>
			 * Divides this vector by another vector.
			 * </p>
			 *
			 * @param rhs The vector to divide this vector by.
			 *
			 * @return This vector.
			 */
			Vector<Data, Size>& operator/=(const Vector<Data, Size>& rhs);

			/**
			 * <p>
			 * Divides this vector by a scalar.
			 * </p>
			 *
			 * @param rhs The scalar to divide this vector by.
			 *
			 * @return This vector.
			 */
			Vector<Data, Size>& operator/=(const Data scalar);

			/**
			 * <p>
			 * Provides access to the elements of this vector.
			 * </p>
			 *
			 * @param index The index of the element to access.
			 *
			 * @return The element at the specified index.
			 */
			Data& operator[](unsigned int index);

			/**
			 * <p>
			 * Provides access to the elements of this vector.
			 * </p>
			 *
			 * @param index The index of the element to access.
			 *
			 * @return The element at the specified index.
			 */
			const Data& operator[](unsigned int index) const;

			/**
			 * <p>
			 * Multiplies this vector by another vector.
			 * </p>
			 *
			 * @param rhs The vector to multiply this vector by.
			 *
			 * @return This vector.
			 */
			Vector<Data, Size>& operator*=(const Vector<Data, Size>& rhs);

			/**
			 * <p>
			 * Multiplies this vector by a scalar.
			 * </p>
			 *
			 * @param rhs The scalar to multiply this vector by.
			 *
			 * @return This vector.
			 */
			Vector<Data, Size>& operator*=(const Data scalar);

			/**
			 * <p>
			 * Adds another vector to this vector.
			 * </p>
			 *
			 * @param rhs The vector to add to this vector.
			 *
			 * @return This vector.
			 */
			Vector<Data, Size>& operator+=(const Vector<Data, Size>& rhs);

			/**
			 * <p>
			 * Modifies this vector to be equal to another vector.
			 * </p>
			 *
			 * @param original The vector to make this vector equal to.
			 *
			 * @return This vector.
			 */
			Vector<Data, Size>& operator=(const Vector<Data, Size>& original);

			/**
			 * <p>
			 * Subtracts another vector to this vector.
			 * </p>
			 *
			 * @param rhs The vector to subtract from this vector.
			 *
			 * @return This vector.
			 */
			Vector<Data, Size>& operator-=(const Vector<Data, Size>& rhs);

			/**
			 * <p>
			 * Retrieves the red value of a color vector (the first element of the vector).
			 * </p>
			 *
			 * @return The red value.
			 */
			Data& R();

			/**
			 * <p>
			 * Retrieves the red value of a color vector (the first element of the vector).
			 * </p>
			 *
			 * @return The red value.
			 */
			const Data& R() const;

			/**
			 * <p>
			 * Sets the data of this vector.
			 * </p>
			 *
			 * @param data The data.
			 */
			void setData(const std::array<Data, Size>& data);

			/**
			 * <p>
			 * Sets the data of this vector.
			 * </p>
			 *
			 * @param data The data.
			 */
			void setData(Data* data);

			/**
			 * <p>
			 * Retrieves the w value of a position vector (the fourth element of the vector).
			 * </p>
			 *
			 * @return The w value.
			 */
			Data& W();

			/**
			 * <p>
			 * Retrieves the w value of a position vector (the fourth element of the vector).
			 * </p>
			 *
			 * @return The w value.
			 */
			const Data& W() const;

			/**
			 * <p>
			 * Retrieves the x value of a position vector (the first element of the vector).
			 * </p>
			 *
			 * @return The x value.
			 */
			Data& X();

			/**
			 * <p>
			 * Retrieves the x value of a position vector (the first element of the vector).
			 * </p>
			 *
			 * @return The x value.
			 */
			const Data& X() const;

			/**
			 * <p>
			 * Retrieves the y value of a position vector (the second element of the vector).
			 * </p>
			 *
			 * @return The y value.
			 */
			Data& Y();

			/**
			 * <p>
			 * Retrieves the y value of a position vector (the second element of the vector).
			 * </p>
			 *
			 * @return The y value.
			 */
			const Data& Y() const;

			/**
			 * <p>
			 * Retrieves the z value of a position vector (the third element of the vector).
			 * </p>
			 *
			 * @return The z value.
			 */
			Data& Z();

			/**
			 * <p>
			 * Retrieves the z value of a position vector (the third element of the vector).
			 * </p>
			 *
			 * @return The z value.
			 */
			const Data& Z() const;

		private:
			Data data[Size];
	};

	/**
	 * <p>
	 * A 2 floating point vector.
	 * </p>
	 */
	using Vector2 = Vector<float, 2>;

	/**
	 * <p>
	 * A 3 floating point vector.
	 * </p>
	 */
	using Vector3 = Vector<float, 3>;

	/**
	 * <p>
	 * A 4 floating point vector.
	 * </p>
	 */
	using Vector4 = Vector<float, 4>;
	
	/**
	 * <p>
	 * Calculates the cross product of two vectors.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The vector on the right-hand-side of the equation.
	 *
	 * @return The cross product of two vectors.
	 */
	template<typename Data>
	Data crossProduct(const Vector<Data, 2>& lhs, const Vector<Data, 2>& rhs);

	/**
	* <p>
	* Calculates the cross product of two vectors.
	* </p>
	*
	* @param lhs The vector on the left-hand-side of the equation.
	* @param rhs The vector on the right-hand-side of the equation.
	*
	* @return The cross product of two vectors.
	*/
	template<typename Data>
	Vector<Data, 3> crossProduct(const Vector<Data, 3>& lhs, const Vector<Data, 3>& rhs);

	/**
	* <p>
	* Calculates the dot product of two vectors.
	* </p>
	*
	* @param lhs The vector on the left-hand-side of the equation.
	* @param rhs The vector on the right-hand-side of the equation.
	*
	* @return The dot product of two vectors.
	*/
	template<typename Data, unsigned int Size>
	Data dotProduct(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	/**
	* <p>
	* Calculates the angle between two vectors (in radians).
	* </p>
	*
	* @param a The first vector.
	* @param b The second vector.
	*
	* @return The angle between two vectors (in radians).
	*/
	template<typename Data>
	float getAngleBetween(const Vector<Data, 2>& a, const Vector<Data, 2>& b);

	/**
	* <p>
	* Calculates the angle between two vectors (in radians).
	* </p>
	*
	* @param a The first vector.
	* @param b The second vector.
	*
	* @return The angle between two vectors (in radians).
	*/
	template<typename Data>
	float getAngleBetween(const Vector<Data, 3>& a, const Vector<Data, 3>& b);

	/**
	* <p>
	* Calculates the angle between two vectors (in radians). Both vectors are assumed to be normalized i.e. unit
	* length vectors. This version is faster than the one that does not assume the vectors to be normalized as it has
	* to normalize them to determine the angle.
	* </p>
	*
	* @param normalizedA The first normalized vector.
	* @param normalizedB The second normalized vector.
	*
	* @return The angle between two vectors (in radians).
	*/
	template<typename Data>
	float getAngleBetweenNormalized(const Vector<Data, 2>& normalizedA, const Vector<Data, 2>& normalizedB);

	/**
	* <p>
	* Calculates the angle between two vectors (in radians). Both vectors are assumed to be normalized i.e. unit
	* length vectors. This version is faster than the one that does not assume the vectors to be normalized as it has
	* to normalize them to determine the angle.
	* </p>
	*
	* @param normalizedA The first normalized vector.
	* @param normalizedB The second normalized vector.
	*
	* @return The angle between two vectors (in radians).
	*/
	template<typename Data>
	float getAngleBetweenNormalized(const Vector<Data, 3>& normalizedA, const Vector<Data, 3>& normalizedB);
	
	/**
	 * <p>
	 * Retrieves the projection of one vector onto another.
	 * </p>
	 *
	 * @param projectee The vector to project.
	 * @param target The vector to project onto.
	 *
	 * @return The projection.
	 */
	template<typename Data, unsigned int Size>
	Vector<Data, Size> getProjection(const Vector<Data, Size>& projectee, const Vector<Data, Size>& target);

	/**
	* <p>
	* Retrieves the proximity of two vectors i.e. the shortest distance between them.
	* </p>
	*
	* @param a The first vector.
	* @param b The second vector.
	*
	* @return The proximity.
	*/
	template<typename Data>
	Data getProximity(const Vector<Data, 2>& a, const Vector<Data, 2>& b);

	/**
	* <p>
	* Retrieves the proximity of two vectors i.e. the shortest distance between them.
	* </p>
	*
	* @param a The first vector.
	* @param b The second vector.
	*
	* @return The proximity.
	*/
	template<typename Data>
	Data getProximity(const Vector<Data, 3>& a, const Vector<Data, 3>& b);

	/**
	* <p>
	* Retrieves the scalar projection of one vector onto another.
	* </p>
	*
	* @param projectee The vector to project.
	* @param target The vector to project onto.
	*
	* @return The scalar projection.
	*/
	template<typename Data, unsigned int Size>
	float getScalarProjection(const Vector<Data, Size>& projectee, const Vector<Data, Size>& target);

	/**
	* <p>
	* Homogenizes a homogeneous 3D vector.
	* </p>
	*
	* @param vector The vector.
	*/
	template<typename Data>
	void homogenize(Vector<Data, 4>& vector);

	/**
	 * <p>
	 * Determines if two vectors are unequal.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The vector on the right-hand-side of the equation.
	 *
	 * @return True if the vectors are unequal, false otherwise.
	 */
	template<typename Data, unsigned int Size>
	bool operator!=(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	/**
	 * <p>
	 * Divides two vectors.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The vector on the right-hand-side of the equation.
	 *
	 * @return The product.
	 */
	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator/(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	/**
	 * <p>
	 * Divides a vector by a scalar.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The scalar on the right-hand-side of the equation.
	 *
	 * @return The product.
	 */
	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator/(const Vector<Data, Size>& lhs, Data rhs);

	/**
	 * <p>
	 * Multiples a vector by a scalar.
	 * </p>
	 *
	 * @param lhs The scalar on the left-hand-side of the equation.
	 * @param rhs The vector on the right-hand-side of the equation.
	 *
	 * @return The product.
	 */
	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator*(Data lhs, const Vector<Data, Size>& rhs);

	/**
	 * <p>
	 * Multiples a vector by a scalar.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The scalar on the right-hand-side of the equation.
	 *
	 * @return The product.
	 */
	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator*(const Vector<Data, Size>& lhs, Data rhs);

	/**
	 * <p>
	 * Multiplies two vectors.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The vector on the right-hand-side of the equation.
	 *
	 * @return The product.
	 */
	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator*(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	/**
	 * <p>
	 * Adds two vectors.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The vector on the right-hand-side of the equation.
	 *
	 * @return The sum.
	 */
	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator+(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	/**
	 * <p>
	 * Subtracts two vectors.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The vector on the right-hand-side of the equation.
	 *
	 * @return The sum.
	 */
	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator-(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	/**
	 * <p>
	 * Sends a textual representation of a vector to an output stream.
	 * </p>
	 *
	 * @param stream The output stream.
	 * @param vector The vector.
	 *
	 * @return The output stream.
	 */
	template<typename Data, unsigned int Size>
	std::ostream& operator<<(std::ostream& stream, const Vector<Data, Size>& vector);

	/**
	 * <p>
	 * Determines if two vectors are equal.
	 * </p>
	 *
	 * @param lhs The vector on the left-hand-side of the equation.
	 * @param rhs The vector on the right-hand-side of the equation.
	 *
	 * @return True if the vectors are equal, false otherwise.
	 */
	template<typename Data, unsigned int Size>
	bool operator==(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	/**
	* <p>
	* Rotates a 2D vector.
	* </p>
	*
	* @param vector The vector to rotate.
	* @param angle The angle to rotate the vector.
	*/
	template<typename Data>
	void rotate(Vector<Data, 2>& vector, const Data angle);
}

#include "Vector.tpp"

#endif /* VECTOR_H_ */
