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
#include "SimpleColourVector.h"

namespace simplicity
{
	template<typename Data>
	SimpleColourVector<Data>::SimpleColourVector() :
		SimpleVector<Data>()
	{
	}

	template<typename Data>
	SimpleColourVector<Data>::SimpleColourVector(const Data r, const Data g, const Data b, const Data a) :
		SimpleVector<Data>(r, g, b, a)
	{
	}

	template<typename Data>
	SimpleColourVector<Data>::SimpleColourVector(const array<Data, SIZE>& data) :
		SimpleVector<Data>(data)
	{
	}

	template<typename Data>
	Data SimpleColourVector<Data>::getAlpha() const
	{
		return SimpleVector < Data > ::getData().at(3);
	}

	template<typename Data>
	Data SimpleColourVector<Data>::getBlue() const
	{
		return SimpleVector < Data > ::getData().at(2);
	}

	template<typename Data>
	Data SimpleColourVector<Data>::getGreen() const
	{
		return SimpleVector < Data > ::getData().at(1);
	}

	template<typename Data>
	Data SimpleColourVector<Data>::getRed() const
	{
		return SimpleVector < Data > ::getData().at(0);
	}

	template<typename Data>
	void SimpleColourVector<Data>::setAlpha(const Data alpha)
	{
		SimpleVector < Data > ::getData().at(3) = alpha;
	}

	template<typename Data>
	void SimpleColourVector<Data>::setBlue(const Data blue)
	{
		SimpleVector < Data > ::getData().at(2) = blue;
	}

	template<typename Data>
	void SimpleColourVector<Data>::setGreen(const Data green)
	{
		SimpleVector < Data > ::getData().at(1) = green;
	}

	template<typename Data>
	void SimpleColourVector<Data>::setRed(const Data red)
	{
		SimpleVector < Data > ::getData().at(0) = red;
	}
}
