/*
 * Copyright © 2014 Simple Entertainment Limited
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
#include "Triangle.h"

namespace simplicity
{
	Triangle::Triangle(const Vector3& pointA, const Vector3& pointB, const Vector3& pointC) :
		pointA(pointA),
		pointB(pointB),
		pointC(pointC)
	{
	}

	const Vector3& Triangle::getPointA() const
	{
		return pointA;
	}

	const Vector3& Triangle::getPointB() const
	{
		return pointB;
	}

	const Vector3& Triangle::getPointC() const
	{
		return pointC;
	}

	void Triangle::render(Renderer& renderer) const
	{
		renderer.render(*this);
	}

	void Triangle::setPointA(const Vector3& pointA)
	{
		this->pointA = pointA;
	}

	void Triangle::setPointB(const Vector3& pointB)
	{
		this->pointB = pointB;
	}

	void Triangle::setPointC(const Vector3& pointC)
	{
		this->pointC = pointC;
	}
}
