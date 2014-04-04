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
		color(0.0f, 0.0f, 0.0f),
		pointA(pointA),
		pointB(pointB),
		visible(true)
	{
	}

	const Vector4& Line::getColor() const
	{
		return color;
	}

	Texture* Line::getNormalMap() const
	{
		return NULL;
	}

	const Vector3& Line::getPointA() const
	{
		return pointA;
	}

	const Vector3& Line::getPointB() const
	{
		return pointB;
	}

	Model::PrimitiveType Line::getPrimitiveType() const
	{
		return Model::NA;
	}

	Texture* Line::getTexture() const
	{
		return NULL;
	}

	unsigned short Line::getTypeID() const
	{
		return TYPE_ID;
	}

	bool Line::isVisible() const
	{
		return visible;
	}

	void Line::setColor(const Vector4& color)
	{
		this->color = color;
	}

	void Line::setNormalMap(Texture*)
	{
	}

	void Line::setPointA(const Vector3& pointA)
	{
		this->pointA = pointA;
	}

	void Line::setPointB(const Vector3& pointB)
	{
		this->pointB = pointB;
	}

	void Line::setPrimitiveType(PrimitiveType)
	{
	}

	void Line::setTexture(Texture*)
	{
	}

	void Line::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
