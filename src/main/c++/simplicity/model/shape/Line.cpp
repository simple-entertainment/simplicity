/*
 * Copyright © 2013 Simple Entertainment Limited
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
#include "Line.h"

namespace simplicity
{
	Line::Line(const Vector3& pointA, const Vector3& pointB) :
		pointA(pointA),
		pointB(pointB)
	{
	}

	const Vector3& Line::getPointA() const
	{
		return pointA;
	}

	const Vector3& Line::getPointB() const
	{
		return pointB;
	}

	unsigned short Line::getTypeID() const
	{
		return TYPE_ID;
	}

	void Line::setPointA(const Vector3& pointA)
	{
		this->pointA = pointA;
	}

	void Line::setPointB(const Vector3& pointB)
	{
		this->pointB = pointB;
	}
}
