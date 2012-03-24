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
#include <math.h>

#include <boost/lexical_cast.hpp>

#include "SimpleVector.h"

using namespace std;

namespace simplicity
{
	template<typename Data, unsigned int Size>
	SimpleVector<Data, Size>::SimpleVector() :
		data()
	{
		data.at(0) = 0;
		data.at(1) = 0;
		data.at(2) = 0;
		data.at(3) = 1;
	}

	template<typename Data, unsigned int Size>
	SimpleVector<Data, Size>::SimpleVector(const Data d0, const Data d1, const Data d2, const Data d3) :
		data()
	{
		data.at(0) = d0;
		data.at(1) = d1;
		data.at(2) = d2;
		data.at(3) = d3;
	}

	template<typename Data, unsigned int Size>
	SimpleVector<Data, Size>::SimpleVector(const array<Data, Size>& data) :
		data(data)
	{
	}

	template<typename Data, unsigned int Size>
	void SimpleVector<Data, Size>::add(array<Data, Size>& lhs, const array<Data, Size>& rhs)
	{
		lhs.at(0) = lhs.at(0) + rhs.at(0);
		lhs.at(1) = lhs.at(1) + rhs.at(1);
		lhs.at(2) = lhs.at(2) + rhs.at(2);
		lhs.at(3) = 1;
	}

	template<typename Data, unsigned int Size>
	unique_ptr<Vector<Data, Size> > SimpleVector<Data, Size>::crossProduct(
		const Vector<Data, Size>& rhs) const
	{
		unique_ptr < SimpleVector<> > crossProduct(new SimpleVector<>);

		crossProduct->getData().at(0) = data.at(1) * rhs.getData().at(2) - data.at(2) * rhs.getData().at(1);
		crossProduct->getData().at(1) = data.at(2) * rhs.getData().at(0) - data.at(0) * rhs.getData().at(2);
		crossProduct->getData().at(2) = data.at(0) * rhs.getData().at(1) - data.at(1) * rhs.getData().at(0);
		crossProduct->getData().at(3) = 1;

		return move(crossProduct);
	}

	template<typename Data, unsigned int Size>
	Data SimpleVector<Data, Size>::dotProduct(const Vector<Data, Size>& otherVector)
	{
		const array<Data, Size>& otherData = otherVector.getData();
		Data dot = 0;

		for (int index = 0; index < 3; index++)
		{
			dot += data.at(index) * otherData.at(index);
		}

		return dot;
	}

	template<typename Data, unsigned int Size>
	bool SimpleVector<Data, Size>::equals(const Vector<Data, Size>& otherVector) const
	{
		return data == otherVector.getData();
	}

	template<typename Data, unsigned int Size>
	array<Data, Size>& SimpleVector<Data, Size>::getData()
	{
		return data;
	}

	template<typename Data, unsigned int Size>
	const array<Data, Size>& SimpleVector<Data, Size>::getData() const
	{
		return data;
	}

	template<typename Data, unsigned int Size>
	Data SimpleVector<Data, Size>::getLength() const
	{
		return sqrt(getLengthSquared());
	}

	template<typename Data, unsigned int Size>
	Data SimpleVector<Data, Size>::getLengthSquared() const
	{
		return data.at(0) * data.at(0) + data.at(1) * data.at(1) + data.at(2) * data.at(2);
	}

	template<typename Data, unsigned int Size>
	void SimpleVector<Data, Size>::homogenize()
	{
		if (data.at(3) == 1)
		{
			return;
		}

		data.at(0) = data.at(0) / data.at(3);
		data.at(1) = data.at(1) / data.at(3);
		data.at(2) = data.at(2) / data.at(3);
		data.at(3) = 1;
	}

	template<typename Data, unsigned int Size>
	void SimpleVector<Data, Size>::multiply(array<Data, Size>& lhs, const array<Data, Size>& rhs) const
	{
		lhs.at(0) = lhs.at(0) * rhs.at(0);
		lhs.at(1) = lhs.at(1) * rhs.at(1);
		lhs.at(2) = lhs.at(2) * rhs.at(2);
		lhs.at(3) = 1;
	}

	template<typename Data, unsigned int Size>
	array<Data, Size> SimpleVector<Data, Size>::multiplyWithMatrix(const array<Data, Size>& lhs,
	const array<Data, Size * Size>& rhs) const
	{
		array < Data, Size > product;

		// For every column in the matrix.
		for (unsigned int column = 0; column < Size; column++)
		{
			Data sum = 0;

			// For every element in the vector and every element in the current
			// column of the matrix.
			for (unsigned int element = 0; element < Size; element++)
			{
				// Add the product of the two to the value for the new vector.
				sum += lhs.at(element) * rhs.at((column * Size) + element);
			}

			product.at(column) = sum;
		}

		return product;
	}

	template<typename Data, unsigned int Size>
	void SimpleVector<Data, Size>::negate()
	{
		scale(data, -1);
	}

	template<typename Data, unsigned int Size>
	void SimpleVector<Data, Size>::normalize()
	{
		scale(data, 1 / getLength());
	}

	template<typename Data, unsigned int Size>
	std::unique_ptr<Vector<Data, Size> > SimpleVector<Data, Size>::operator-(const Vector<Data, Size>& rhs) const
	{
		std::unique_ptr < SimpleVector<Data, Size> > sum(new SimpleVector<Data, Size>(data));
		const_cast<SimpleVector<>*>(this)->subtract(sum->getData(), rhs.getData());

		return move(sum);
	}

	template<typename Data, unsigned int Size>
	std::unique_ptr<Vector<Data, Size> > SimpleVector<Data, Size>::operator*(const Data rhs) const
	{
		std::unique_ptr < SimpleVector<Data, Size> > product(new SimpleVector<Data, Size>(data));
		const_cast<SimpleVector<>*>(this)->scale(product->getData(), rhs);

		return move(product);
	}

	template<typename Data, unsigned int Size>
	std::unique_ptr<Vector<Data, Size> > SimpleVector<Data, Size>::operator*(const Matrix<Data, Size, Size>& rhs) const
	{
		return std::unique_ptr < SimpleVector<Data, Size>
			> (new SimpleVector<Data, Size>(multiplyWithMatrix(data, rhs.getData())));
	}

	template<typename Data, unsigned int Size>
	std::unique_ptr<Vector<Data, Size> > SimpleVector<Data, Size>::operator*(const Vector<Data, Size>& rhs) const
	{
		std::unique_ptr < SimpleVector<Data, Size> > product(new SimpleVector<Data, Size>(data));
		multiply(product->getData(), rhs.getData());

		return move(product);
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& SimpleVector<Data, Size>::operator*=(const Data rhs)
	{
		scale(data, rhs);

		return *this;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& SimpleVector<Data, Size>::operator*=(const Matrix<Data, Size, Size>& rhs)
	{
		data = multiplyWithMatrix(data, rhs.getData());

		return *this;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& SimpleVector<Data, Size>::operator*=(const Vector<Data, Size>& rhs)
	{
		multiply(data, rhs.getData());

		return *this;
	}

	template<typename Data, unsigned int Size>
	std::unique_ptr<Vector<Data, Size> > SimpleVector<Data, Size>::operator+(const Vector<Data, Size>& rhs) const
	{
		std::unique_ptr < SimpleVector<Data, Size> > sum(new SimpleVector<Data, Size>(data));
		const_cast<SimpleVector<>*>(this)->add(sum->getData(), rhs.getData());

		return move(sum);
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& SimpleVector<Data, Size>::operator+=(const Vector<Data, Size>& rhs)
	{
		add(data, rhs.getData());

		return *this;
	}

	template<typename Data, unsigned int Size>
	Vector<Data, Size>& SimpleVector<Data, Size>::operator-=(const Vector<Data, Size>& rhs)
	{
		subtract(data, rhs.getData());

		return *this;
	}

	template<typename Data, unsigned int Size>
	void SimpleVector<Data, Size>::scale(array<Data, Size>& lhs, const Data rhs)
	{
		lhs.at(0) = lhs.at(0) * rhs;
		lhs.at(1) = lhs.at(1) * rhs;
		lhs.at(2) = lhs.at(2) * rhs;
	}

	template<typename Data, unsigned int Size>
	void SimpleVector<Data, Size>::setData(const array<Data, Size>& data)
	{
		this->data = data;
	}

	template<typename Data, unsigned int Size>
	void SimpleVector<Data, Size>::subtract(array<Data, Size>& lhs, const array<Data, Size>& rhs)
	{
		lhs.at(0) = lhs.at(0) - rhs.at(0);
		lhs.at(1) = lhs.at(1) - rhs.at(1);
		lhs.at(2) = lhs.at(2) - rhs.at(2);
		lhs.at(3) = 1;
	}

	template<typename Data, unsigned int Size>
	string SimpleVector<Data, Size>::toString() const
	{
		string vectorString = "";

		vectorString += "-------------------------\n";
		vectorString += "| " + boost::lexical_cast < string > (data.at(0)) + " | " + boost::lexical_cast < string
			> (data.at(1)) + " | " + boost::lexical_cast < string > (data.at(2)) + " | " + boost::lexical_cast < string
			> (data.at(3)) + " |\n";
		vectorString += "-------------------------\n";

		return vectorString;
	}
}
