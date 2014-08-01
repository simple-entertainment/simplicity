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
#include "Mesh.h"
#include "MeshBuffer.h"

using namespace std;

namespace simplicity
{
	Mesh::Mesh(shared_ptr<MeshBuffer> buffer) :
			buffer(buffer),
			color(0.0f, 0.0f, 0.0f, 1.0f),
			visible(true)
	{
	}

	MeshBuffer* Mesh::getBuffer() const
	{
		return buffer.get();
	}

	const Vector4& Mesh::getColor() const
	{
		return color;
	}

	MeshData& Mesh::getData(bool readable)
	{
		return buffer->getData(*this, readable);
	}

	const MeshData& Mesh::getData() const
	{
		return buffer->getData(*this);
	}

	Texture* Mesh::getNormalMap() const
	{
		return nullptr;
	}

	Texture* Mesh::getTexture() const
	{
		return nullptr;
	}

	unsigned short Mesh::getTypeID() const
	{
		return TYPE_ID;
	}

	bool Mesh::isVisible() const
	{
		return visible;
	}

	void Mesh::releaseData() const
	{
		buffer->releaseData(*this);
	}

	void Mesh::setColor(const Vector4& color)
	{
		this->color = color;
	}

	void Mesh::setNormalMap(Texture* /* normalMap */)
	{
	}

	void Mesh::setTexture(Texture* /* texture */)
	{
	}

	void Mesh::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
