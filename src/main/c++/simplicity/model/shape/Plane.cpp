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
#include "Plane.h"

namespace simplicity
{
	Plane::Plane(const Vector3& normal, const Vector3& positionOnPlane) :
		normal(normal),
		positionOnPlane(positionOnPlane)
	{
	}

	const Vector3& Plane::getNormal() const
	{
		return normal;
	}

	const Vector3& Plane::getPositionOnPlane() const
	{
		return positionOnPlane;
	}

	unsigned short Plane::getTypeID() const
	{
		return TYPE_ID;
	}

	void Plane::setNormal(const Vector3& normal)
	{
		this->normal = normal;
	}

	void Plane::setPositionOnPlane(const Vector3& positionOnPlane)
	{
		this->positionOnPlane = positionOnPlane;
	}
}
