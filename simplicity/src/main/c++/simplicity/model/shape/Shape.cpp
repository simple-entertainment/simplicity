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
#include "Shape.h"

namespace simplicity
{
	Shape::Shape(const Vector2& position) :
		colour(0.0f, 0.0f, 0.0f, 1.0f),
		levelOfDetail(1),
		position(position),
		primitiveType(TRIANGLE_LIST),
		visible(true)
	{
	}

	Shape::~Shape()
	{
	}

	const Vector4& Shape::getColour() const
	{
		return colour;
	}

	unsigned int Shape::getLevelOfDetail() const
	{
		return levelOfDetail;
	}

	Texture* Shape::getNormalMap() const
	{
		return NULL;
	}

	const Vector2& Shape::getPosition() const
	{
		return position;
	}

	Model::PrimitiveType Shape::getPrimitiveType() const
	{
		return primitiveType;
	}

	Texture* Shape::getTexture() const
	{
		return NULL;
	}

	bool Shape::isVisible() const
	{
		return visible;
	}

	void Shape::setColour(const Vector4& colour)
	{
		this->colour = colour;
	}

	void Shape::setLevelOfDetail(unsigned int levelOfDetail)
	{
		this->levelOfDetail = levelOfDetail;
	}

	void Shape::setNormalMap(Texture*)
	{
	}

	void Shape::setPosition(const Vector2& position)
	{
		this->position = position;
	}

	void Shape::setPrimitiveType(PrimitiveType primitiveType)
	{
		this->primitiveType = primitiveType;
	}

	void Shape::setTexture(Texture*)
	{
	}

	void Shape::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
