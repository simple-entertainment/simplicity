/*
 * Copyright © 2015 Simple Entertainment Limited
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
#include "AbstractModel.h"

using namespace std;

namespace simplicity
{
	AbstractModel::AbstractModel() :
			color(),
			texture(nullptr),
			visible(true)
	{
	}

	const Vector4& AbstractModel::getColor() const
	{
		return color;
	}

	Texture* AbstractModel::getTexture() const
	{
		return texture.get();
	}

	bool AbstractModel::isVisible() const
	{
		return visible;
	}

	void AbstractModel::setColor(const Vector4& color)
	{
		this->color = color;
	}

	void AbstractModel::setTexture(shared_ptr<Texture> texture)
	{
		this->texture = texture;
	}

	void AbstractModel::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
