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
		color(),
		normal(normal),
		positionOnPlane(positionOnPlane),
		visible(true)
	{
	}

	const Vector4& Plane::getColor() const
	{
		return color;
	}

	const Vector3& Plane::getNormal() const
	{
		return normal;
	}

	Texture* Plane::getNormalMap() const
	{
		return NULL;
	}

	const Vector3& Plane::getPositionOnPlane() const
	{
		return positionOnPlane;
	}

	Model::PrimitiveType Plane::getPrimitiveType() const
	{
		return NA;
	}

	Texture* Plane::getTexture() const
	{
		return NULL;
	}

	unsigned short Plane::getTypeID() const
	{
		return TYPE_ID;
	}

	bool Plane::isVisible() const
	{
		return visible;
	}

	void Plane::setColor(const Vector4& color)
	{
		this->color = color;
	}

	void Plane::setNormal(const Vector3& normal)
	{
		this->normal = normal;
	}

	void Plane::setNormalMap(Texture*)
	{
	}

	void Plane::setPositionOnPlane(const Vector3& positionOnPlane)
	{
		this->positionOnPlane = positionOnPlane;
	}

	void Plane::setPrimitiveType(PrimitiveType)
	{
	}

	void Plane::setTexture(Texture*)
	{
	}

	void Plane::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
