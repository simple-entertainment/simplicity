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
#include "Text.h"

using namespace std;

namespace simplicity
{
	Text::Text(const std::string& text) :
		color(0.0f, 0.0f, 0.0f, 1.0f),
		text(text),
		visible(true)
	{
	}

	const Vector4& Text::getColor() const
	{
		return color;
	}

	Texture* Text::getNormalMap() const
	{
		return nullptr;
	}

	Model::PrimitiveType Text::getPrimitiveType() const
	{
		return PrimitiveType::NA;
	}

	const string& Text::getText() const
	{
		return text;
	}

	Texture* Text::getTexture() const
	{
		return nullptr;
	}

	unsigned short Text::getTypeID() const
	{
		return TYPE_ID;
	}

	bool Text::isVisible() const
	{
		return visible;
	}

	void Text::setColor(const Vector4& color)
	{
		this->color = color;
	}

	void Text::setNormalMap(Texture*)
	{
	}

	void Text::setPrimitiveType(PrimitiveType)
	{
	}

	void Text::setText(const std::string& text)
	{
		this->text = text;
	}

	void Text::setTexture(Texture*)
	{
	}

	void Text::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
