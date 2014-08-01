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
#include "Point.h"

namespace simplicity
{
	Point::Point(const Vector3& point) :
		color(0.0f, 0.0f, 0.0f),
		point(point),
		visible(true)
	{
	}

	const Vector4& Point::getColor() const
	{
		return color;
	}

	Texture* Point::getNormalMap() const
	{
		return nullptr;
	}

	const Vector3& Point::getPoint() const
	{
		return point;
	}

	Texture* Point::getTexture() const
	{
		return nullptr;
	}

	unsigned short Point::getTypeID() const
	{
		return TYPE_ID;
	}

	bool Point::isVisible() const
	{
		return visible;
	}

	void Point::setColor(const Vector4& color)
	{
		this->color = color;
	}

	void Point::setNormalMap(Texture*)
	{
	}

	void Point::setPoint(const Vector3& point)
	{
		this->point = point;
	}

	void Point::setTexture(Texture*)
	{
	}

	void Point::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
