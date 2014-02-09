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
#include <cmath>

#include "Vector.h"

namespace simplicity
{
	template<typename Data, unsigned int Size>
	Vector<Data, Size>::Vector() :
		data()
	{
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>::Vector(const std::array<Data, Size>& data) :
		data()
	{
		setData(data);
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>::Vector(Data* data) :
		data()
	{
		setData(data);
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>::Vector(Data d0, Data d1) :
		data()
	{
		data[0] = d0;
		data[1] = d1;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>::Vector(Data d0, Data d1, Data d2) :
		data()
	{
		data[0] = d0;
		data[1] = d1;
		data[2] = d2;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>::Vector(Data d0, Data d1, Data d2, Data d3) :
		data()
	{
		data[0] = d0;
		data[1] = d1;
		data[2] = d2;
		data[3] = d3;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>::Vector(const Vector<Data, Size>& original) :
		data()
	{
		operator=(original);
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>::Vector(const Vector<Data, Size - 1>& original, Data d) :
		data()
	{
		for (unsigned int index = 0; index < Size - 1; index++)
		{
			data[index] = original.getData()[index];
		}
		
		data[Size - 1] = d;
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::A()
	{
		return data[3];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::A() const
	{
		return data[3];
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::B()
	{
		return data[2];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::B() const
	{
		return data[2];
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::G()
	{
		return data[1];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::G() const
	{
		return data[1];
	}

	template<typename Data, unsigned int Size>
	Data* Vector<Data, Size>::getData()
	{
		return data;
	}

	template<typename Data, unsigned int Size>
	const Data* Vector<Data, Size>::getData() const
	{
		return data;
	}

	template<typename Data, unsigned int Size>
	Data Vector<Data, Size>::getMagnitude() const
	{
		return sqrt(getMagnitudeSquared());
	}

	template<typename Data, unsigned int Size>
	Data Vector<Data, Size>::getMagnitudeSquared() const
	{
		Data magnitudeSquared = 0;

		for (unsigned int index = 0; index < Size; index++)
		{
			magnitudeSquared += pow(data[index], 2);
		}

		return magnitudeSquared;
	}

	template<typename Data, unsigned int Size>
	void Vector<Data, Size>::negate()
	{
		operator*=(-1);
	}

	template<typename Data, unsigned int Size>
	void Vector<Data, Size>::normalize()
	{
		operator*=(1 / getMagnitude());
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& Vector<Data, Size>::operator/=(const Vector<Data, Size>& rhs)
	{
		for (unsigned int index = 0; index < Size; index++)
		{
			data[index] /= rhs.data[index];
		}

		return *this;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& Vector<Data, Size>::operator/=(const Data scalar)
	{
		for (unsigned int index = 0; index < Size; index++)
		{
			data[index] /= scalar;
		}

		return *this;
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::operator[](unsigned int index)
	{
		return data[index];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::operator[](unsigned int index) const
	{
		return data[index];
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& Vector<Data, Size>::operator*=(const Vector<Data, Size>& rhs)
	{
		for (unsigned int index = 0; index < Size; index++)
		{
			data[index] *= rhs.data[index];
		}

		return *this;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& Vector<Data, Size>::operator*=(const Data scalar)
	{
		for (unsigned int index = 0; index < Size; index++)
		{
			data[index] *= scalar;
		}

		return *this;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& Vector<Data, Size>::operator+=(const Vector<Data, Size>& rhs)
	{
		for (unsigned int index = 0; index < Size; index++)
		{
			data[index] += rhs.data[index];
		}

		return *this;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& Vector<Data, Size>::operator=(const Vector<Data, Size>& original)
	{
		for (unsigned int index = 0; index < Size; index++)
		{
			data[index] = original.data[index];
		}

		return *this;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& Vector<Data, Size>::operator-=(const Vector<Data, Size>& rhs)
	{
		for (unsigned int index = 0; index < Size; index++)
		{
			data[index] -= rhs.data[index];
		}

		return *this;
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::R()
	{
		return data[0];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::R() const
	{
		return data[0];
	}

	template<typename Data, unsigned int Size>
	void Vector<Data, Size>::setData(const std::array<Data, Size>& data)
	{
		std::copy(std::begin(data.data()), std::end(data.data()), std::begin(this->data));
	}

	template<typename Data, unsigned int Size>
	void Vector<Data, Size>::setData(Data* data)
	{
		std::copy(data, data + Size, std::begin(this->data));
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::W()
	{
		return data[3];
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::X()
	{
		return data[0];
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::Y()
	{
		return data[1];
	}

	template<typename Data, unsigned int Size>
	Data& Vector<Data, Size>::Z()
	{
		return data[2];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::W() const
	{
		return data[3];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::X() const
	{
		return data[0];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::Y() const
	{
		return data[1];
	}

	template<typename Data, unsigned int Size>
	const Data& Vector<Data, Size>::Z() const
	{
		return data[2];
	}

	template<typename Data, unsigned int Size>
	Data dotProduct(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
	{
		Data dot = 0;

		for (unsigned int index = 0; index < Size; index++)
		{
			dot += lhs[index] * rhs[index];
		}

		return dot;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator-(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
	{
		Vector<Data, Size> sum = lhs;
		sum -= rhs;

		return sum;
	}

	template<typename Data, unsigned int Size>
	bool operator!=(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator/(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
	{
		Vector<Data, Size> product = lhs;
		product /= rhs;

		return product;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator/(const Vector<Data, Size>& lhs, Data scalar)
	{
		Vector<Data, Size> product = lhs;
		product /= scalar;

		return product;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator*(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
	{
		Vector<Data, Size> product = lhs;
		product *= rhs;

		return product;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator*(const Vector<Data, Size>& lhs, Data scalar)
	{
		Vector<Data, Size> product = lhs;
		product *= scalar;

		return product;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size> operator+(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
	{
		Vector<Data, Size> sum = lhs;
		sum += rhs;

		return sum;
	}

	template<typename Data, unsigned int Size>
	std::ostream& operator<<(std::ostream& stream, const Vector<Data, Size>& vector)
	{
		stream << "[";

		for (unsigned int index = 0; index < Size; index++)
		{
			stream << vector[index];
			if (index < Size - 1)
			{
				stream << ",";
			}
		}

		stream << "]";

		return stream;
	}

	template<typename Data, unsigned int Size>
	bool operator==(const Vector<Data, Size>& lhs, const Vector<Data, Size>& rhs)
	{
		for (unsigned int index = 0; index < Size; index++)
		{
			if (lhs[index] == rhs[index])
			{
				return false;
			}
		}

		return true;
	}
}
