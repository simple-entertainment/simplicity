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
#include "SimpleTranslationVector.h"

namespace simplicity
{
	template<class Data>
	SimpleTranslationVector<Data>::SimpleTranslationVector() :
		SimpleVector<Data, SIZE>()
	{
	}

	template<class Data>
	SimpleTranslationVector<Data>::SimpleTranslationVector(const Data x, const Data y, const Data z, const Data w) :
		SimpleVector<Data, SIZE>(x, y, z, w)
	{
	}

	template<class Data>
	SimpleTranslationVector<Data>::SimpleTranslationVector(const array<Data, SIZE>& data) :
		SimpleVector<Data>(data)
	{
	}

	template<typename Data>
	Data SimpleTranslationVector<Data>::getProximity(const TranslationVector<>& other) const
	{
		SimpleTranslationVector<> difference = *this;
		difference.subtract(other);

		return difference.getLength();
	}

	template<typename Data>
	Data SimpleTranslationVector<Data>::getW() const
	{
		return this->getData().at(3);
	}

	template<typename Data>
	Data SimpleTranslationVector<Data>::getX() const
	{
		return this->getData().at(0);
	}

	template<typename Data>
	Data SimpleTranslationVector<Data>::getY() const
	{
		return this->getData().at(1);
	}

	template<typename Data>
	Data SimpleTranslationVector<Data>::getZ() const
	{
		return this->getData().at(2);
	}

	template<typename Data>
	void SimpleTranslationVector<Data>::setX(const Data x)
	{
		this->getData().at(0) = x;
	}

	template<typename Data>
	void SimpleTranslationVector<Data>::setY(const Data y)
	{
		this->getData().at(1) = y;
	}

	template<typename Data>
	void SimpleTranslationVector<Data>::setZ(const Data z)
	{
		this->getData().at(2) = z;
	}

	template<typename Data>
	void SimpleTranslationVector<Data>::translateX(const Data x)
	{
		this->getData().at(0) += x;
	}

	template<typename Data>
	void SimpleTranslationVector<Data>::translateY(const Data y)
	{
		this->getData().at(1) += y;
	}

	template<typename Data>
	void SimpleTranslationVector<Data>::translateZ(const Data z)
	{
		this->getData().at(2) += z;
	}
}
