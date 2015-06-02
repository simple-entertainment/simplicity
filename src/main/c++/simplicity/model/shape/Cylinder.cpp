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
#include "Cylinder.h"

namespace simplicity
{
	Cylinder::Cylinder(float length, float radius) :
		length(length),
		radius(radius)
	{
	}

	float Cylinder::getLength() const
	{
		return length;
	}

	float Cylinder::getRadius() const
	{
		return radius;
	}

	unsigned short Cylinder::getTypeID() const
	{
		return TYPE_ID;
	}

	void Cylinder::setLength(const float length)
	{
		this->length = length;
	}

	void Cylinder::setRadius(const float radius)
	{
		this->radius = radius;
	}
}
