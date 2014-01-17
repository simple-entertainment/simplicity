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
	template<typename Data, unsigned int Size>
	class Vector
	{
		public:
			Vector();

			Vector(const Vector<Data, Size>& original);

			Vector(const std::array<Data, Size>& data);

			Vector(Data* data, bool takeOwnership);

			Vector(Data d0, Data d1);

			Vector(Data d0, Data d1, Data d2);

			Vector(Data d0, Data d1, Data d2, Data d3);

			~Vector();

			Data& A();

			const Data& A() const;

			Data& B();

			const Data& B() const;

			Data& G();

			const Data& G() const;

			Data* getData();

			const Data* getData() const;

			Data getMagnitude() const;

			Data getMagnitudeSquared() const;

			void negate();

			void normalize();

			Vector<Data, Size>& operator/=(const Vector<Data, Size>& rhs);

			Vector<Data, Size>& operator/=(const Data scalar);

			Data& operator[](unsigned int index);

			const Data& operator[](unsigned int index) const;

			Vector<Data, Size>& operator*=(const Vector<Data, Size>& rhs);

			Vector<Data, Size>& operator*=(const Data scalar);

			Vector<Data, Size>& operator+=(const Vector<Data, Size>& rhs);

			Vector<Data, Size>& operator=(const Vector<Data, Size>& original);

			Vector<Data, Size>& operator-=(const Vector<Data, Size>& rhs);

			Data& R();

			const Data& R() const;

			void setData(const std::array<Data, Size>& data);

			void setData(Data* data, bool takeOwnership);

			Data& W();

			Data& X();

			Data& Y();

			Data& Z();

			const Data& W() const;

			const Data& X() const;

			const Data& Y() const;

			const Data& Z() const;

		private:
			Data* data;

			bool dataOwner;
	};

	typedef Vector<float, 2> Vector2;

	typedef Vector<float, 3> Vector3;

	typedef Vector<float, 4> Vector4;

	template<typename Data, unsigned int Size>
	Data dotProduct(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	template<typename Data, unsigned int Size>
	bool operator!=(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator/(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator/(const Vector<Data, Size>& lhs, Data scalar);

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator*(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator*(const Vector<Data, Size>& lhs, Data scalar);

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator+(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator-(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);

	template<typename Data, unsigned int Size>
	std::ostream& operator<<(std::ostream& stream, const Vector<Data, Size>& vector);

	template<typename Data, unsigned int Size>
	bool operator==(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs);
}

#include "Vector.tpp"

#endif /* VECTOR_H_ */
