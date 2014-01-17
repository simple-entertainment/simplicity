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
	template<unsigned int Dimensions>
	Line<Dimensions>::Line(const Vector<float, Dimensions>& pointA, const Vector<float, Dimensions>& pointB) :
		colour(0.0f, 0.0f, 0.0f),
		pointA(pointA),
		pointB(pointB),
		visible(true)
	{
	}

	template<unsigned int Dimensions>
	const Vector4& Line<Dimensions>::getColour() const
	{
		return colour;
	}

	template<unsigned int Dimensions>
	Texture* Line<Dimensions>::getNormalMap() const
	{
		return NULL;
	}

	template<unsigned int Dimensions>
	const Vector<float, Dimensions>& Line<Dimensions>::getPointA() const
	{
		return pointA;
	}

	template<unsigned int Dimensions>
	const Vector<float, Dimensions>& Line<Dimensions>::getPointB() const
	{
		return pointB;
	}

	template<unsigned int Dimensions>
	Model::PrimitiveType Line<Dimensions>::getPrimitiveType() const
	{
		return Model::NA;
	}

	template<unsigned int Dimensions>
	Texture* Line<Dimensions>::getTexture() const
	{
		return NULL;
	}

	template<unsigned int Dimensions>
	bool Line<Dimensions>::isVisible() const
	{
		return visible;
	}

	template<unsigned int Dimensions>
	void Line<Dimensions>::render(Renderer& renderer) const
	{
		renderer.render(*this);
	}

	template<unsigned int Dimensions>
	void Line<Dimensions>::setColour(const Vector4& colour)
	{
		this->colour = colour;
	}

	template<unsigned int Dimensions>
	void Line<Dimensions>::setNormalMap(Texture*)
	{
	}

	template<unsigned int Dimensions>
	void Line<Dimensions>::setPointA(const Vector<float, Dimensions>& pointA)
	{
		this->pointA = pointA;
	}

	template<unsigned int Dimensions>
	void Line<Dimensions>::setPointB(const Vector<float, Dimensions>& pointB)
	{
		this->pointB = pointB;
	}

	template<unsigned int Dimensions>
	void Line<Dimensions>::setPrimitiveType(PrimitiveType)
	{
	}

	template<unsigned int Dimensions>
	void Line<Dimensions>::setTexture(Texture*)
	{
	}

	template<unsigned int Dimensions>
	void Line<Dimensions>::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
