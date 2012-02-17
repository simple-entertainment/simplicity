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

#include "SimpleVector4.h"

using namespace std;

namespace simplicity
{
	template<typename Data>
	SimpleVector4<Data>::SimpleVector4() :
		data()
	{
		data.at(0) = 0;
		data.at(1) = 0;
		data.at(2) = 0;
		data.at(3) = 1;
	}

	template<typename Data>
	SimpleVector4<Data>::SimpleVector4(const Data d0, const Data d1, const Data d2, const Data d3) :
		data()
	{
		data.at(0) = d0;
		data.at(1) = d1;
		data.at(2) = d2;
		data.at(3) = d3;
	}

	template<typename Data>
	SimpleVector4<Data>::SimpleVector4(const array<Data, SIZE>& data) :
		data(data)
	{
	}

	template<typename Data>
	void SimpleVector4<Data>::add(array<Data, SIZE>& lhs, const array<Data, SIZE>& rhs)
	{
		lhs.at(0) = lhs.at(0) + rhs.at(0);
		lhs.at(1) = lhs.at(1) + rhs.at(1);
		lhs.at(2) = lhs.at(2) + rhs.at(2);
		lhs.at(3) = 1;
	}

	template<typename Data>
	unique_ptr<Vector<Data, SimpleVector4<>::SIZE> > SimpleVector4<Data>::crossProduct(
		const Vector<Data, SIZE>& rhs) const
	{
		unique_ptr<SimpleVector4<> > crossProduct(new SimpleVector4<>);

		crossProduct->getData().at(0) = data.at(1) * rhs.getData().at(2) - data.at(2) * rhs.getData().at(1);
		crossProduct->getData().at(1) = data.at(2) * rhs.getData().at(0) - data.at(0) * rhs.getData().at(2);
		crossProduct->getData().at(2) = data.at(0) * rhs.getData().at(1) - data.at(1) * rhs.getData().at(0);
		crossProduct->getData().at(3) = 1;

		return move(crossProduct);
	}

	template<typename Data>
	Data SimpleVector4<Data>::dotProduct(const Vector<Data, SIZE>& otherVector)
	{
		const array<Data, SIZE>& otherData = otherVector.getData();
		Data dot = 0;

		for (int index = 0; index < 3; index++)
		{
			dot += data.at(index) * otherData.at(index);
		}

		return dot;
	}

	template<typename Data>
	bool SimpleVector4<Data>::equals(const Vector<Data, SIZE>& otherVector) const
	{
		return data == otherVector.getData();
	}

	template<typename Data>
	array<Data, SimpleVector4<>::SIZE>& SimpleVector4<Data>::getData()
	{
		return data;
	}

	template<typename Data>
	const array<Data, SimpleVector4<>::SIZE>& SimpleVector4<Data>::getData() const
	{
		return data;
	}

	template<typename Data>
	Data SimpleVector4<Data>::getLength() const
	{
		return sqrt(getLengthSquared());
	}

	template<typename Data>
	Data SimpleVector4<Data>::getLengthSquared() const
	{
		return data.at(0) * data.at(0) + data.at(1) * data.at(1) + data.at(2) * data.at(2);
	}

	template<typename Data>
	void SimpleVector4<Data>::homogenize()
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

	template<typename Data>
	void SimpleVector4<Data>::multiply(array<Data, SIZE>& lhs, const array<Data, SIZE>& rhs) const
	{
		lhs.at(0) = lhs.at(0) * rhs.at(0);
		lhs.at(1) = lhs.at(1) * rhs.at(1);
		lhs.at(2) = lhs.at(2) * rhs.at(2);
		lhs.at(3) = 1;
	}

	template<typename Data>
	array<Data, SimpleVector4<>::SIZE> SimpleVector4<Data>::multiplyWithMatrix(const array<Data, SIZE>& lhs,
	const array<Data, SIZE * SIZE>& rhs) const
	{
		array < Data, SIZE > product;

		// For every column in the matrix.
		for (unsigned int column = 0; column < SIZE; column++)
		{
			Data sum = 0;

			// For every element in the vector and every element in the current
			// column of the matrix.
			for (unsigned int element = 0; element < SIZE; element++)
			{
				// Add the product of the two to the value for the new vector.
				sum += lhs.at(element) * rhs.at((column * SIZE) + element);
			}

			product.at(column) = sum;
		}

		return product;
	}

	template<typename Data>
	void SimpleVector4<Data>::negate()
	{
		scale(data, -1);
	}

	template<typename Data>
	void SimpleVector4<Data>::normalize()
	{
		scale(data, 1 / getLength());
	}

	template<typename Data>
	std::unique_ptr<Vector<Data, SimpleVector4<>::SIZE> > SimpleVector4<Data>::operator-(
		const Vector<Data, SIZE>& rhs) const
	{
		std::unique_ptr<SimpleVector4<Data> > sum(new SimpleVector4<Data>(data));
		const_cast<SimpleVector4<>*>(this)->subtract(sum->getData(), rhs.getData());

		return move(sum);
	}

	template<typename Data>
	std::unique_ptr<Vector<Data, SimpleVector4<>::SIZE> > SimpleVector4<Data>::operator*(const Data rhs) const
	{
		std::unique_ptr<SimpleVector4<Data> > product(new SimpleVector4<Data>(data));
		const_cast<SimpleVector4<>*>(this)->scale(product->getData(), rhs);

		return move(product);
	}

	template<typename Data>
	std::unique_ptr<Vector<Data, SimpleVector4<>::SIZE> > SimpleVector4<Data>::operator*(
		const Matrix<Data, SimpleVector4<>::SIZE * SimpleVector4<>::SIZE>& rhs) const
	{
		return std::unique_ptr < SimpleVector4<Data>
			> (new SimpleVector4<Data>(multiplyWithMatrix(data, rhs.getData())));
	}

	template<typename Data>
	std::unique_ptr<Vector<Data, SimpleVector4<>::SIZE> > SimpleVector4<Data>::operator*(
		const Vector<Data, SimpleVector4<>::SIZE>& rhs) const
	{
		std::unique_ptr<SimpleVector4<Data> > product(new SimpleVector4<Data>(data));
		multiply(product->getData(), rhs.getData());

		return move(product);
	}

	template<typename Data>
	Vector<Data, SimpleVector4<>::SIZE>& SimpleVector4<Data>::operator*=(const Data rhs)
	{
		scale(data, rhs);

		return *this;
	}

	template<typename Data>
	Vector<Data, SimpleVector4<>::SIZE>& SimpleVector4<Data>::operator*=(
		const Matrix<Data, SimpleVector4<>::SIZE * SimpleVector4<>::SIZE>& rhs)
	{
		data = multiplyWithMatrix(data, rhs.getData());

		return *this;
	}

	template<typename Data>
	Vector<Data, SimpleVector4<>::SIZE>& SimpleVector4<Data>::operator*=(const Vector<Data, SimpleVector4<>::SIZE>& rhs)
	{
		multiply(data, rhs.getData());

		return *this;
	}

	template<typename Data>
	std::unique_ptr<Vector<Data, SimpleVector4<>::SIZE> > SimpleVector4<Data>::operator+(
		const Vector<Data, SIZE>& rhs) const
	{
		std::unique_ptr<SimpleVector4<Data> > sum(new SimpleVector4<Data>(data));
		const_cast<SimpleVector4<>*>(this)->add(sum->getData(), rhs.getData());

		return move(sum);
	}

	template<typename Data>
	Vector<Data, SimpleVector4<>::SIZE>& SimpleVector4<Data>::operator+=(const Vector<Data, SIZE>& rhs)
	{
		add(data, rhs.getData());

		return *this;
	}

	template<typename Data>
	Vector<Data, SimpleVector4<>::SIZE>& SimpleVector4<Data>::operator-=(const Vector<Data, SIZE>& rhs)
	{
		subtract(data, rhs.getData());

		return *this;
	}

	template<typename Data>
	void SimpleVector4<Data>::scale(array<Data, SIZE>& lhs, const Data rhs)
	{
		lhs.at(0) = lhs.at(0) * rhs;
		lhs.at(1) = lhs.at(1) * rhs;
		lhs.at(2) = lhs.at(2) * rhs;
	}

	template<typename Data>
	void SimpleVector4<Data>::subtract(array<Data, SIZE>& lhs, const array<Data, SIZE>& rhs)
	{
		lhs.at(0) = lhs.at(0) - rhs.at(0);
		lhs.at(1) = lhs.at(1) - rhs.at(1);
		lhs.at(2) = lhs.at(2) - rhs.at(2);
		lhs.at(3) = 1;
	}

	template<typename Data>
	string SimpleVector4<Data>::toString() const
	{
		string vectorString = "";

		vectorString += "-------------------------\n";
		vectorString += "| " + boost::lexical_cast<string>(data.at(0)) + " | " + boost::lexical_cast<string>(data.at(1))
			+ " | " + boost::lexical_cast<string>(data.at(2)) + " | " + boost::lexical_cast<string>(data.at(3))
			+ " |\n";
		vectorString += "-------------------------\n";

		return vectorString;
	}
}
