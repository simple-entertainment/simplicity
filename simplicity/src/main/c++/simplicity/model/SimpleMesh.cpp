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
#include "SimpleMesh.h"

using namespace std;

namespace simplicity
{
	SimpleMesh::SimpleMesh() :
		color(0.0f, 0.0f, 0.0f, 1.0f),
		indices(),
		position(0.0f, 0.0f),
		primitiveType(TRIANGLE_LIST),
		vertices(),
		visible(true)
	{
	}

	SimpleMesh::SimpleMesh(const vector<unsigned int>& indices, const vector<Vertex>& vertices) :
		color(0.0f, 0.0f, 0.0f, 1.0f),
		indices(indices),
		position(0.0f, 0.0f),
		primitiveType(TRIANGLE_LIST),
		vertices(vertices),
		visible(true)
	{
	}

	const Vector4& SimpleMesh::getColor() const
	{
		return color;
	}

	vector<unsigned int>& SimpleMesh::getIndices()
	{
		return indices;
	}

	const vector<unsigned int>& SimpleMesh::getIndices() const
	{
		return indices;
	}

	Texture* SimpleMesh::getNormalMap() const
	{
		return NULL;
	}

	const Vector2& SimpleMesh::getPosition() const
	{
		return position;
	}

	Model::PrimitiveType SimpleMesh::getPrimitiveType() const
	{
		return primitiveType;
	}

	Texture* SimpleMesh::getTexture() const
	{
		return NULL;
	}

	vector<Vertex>& SimpleMesh::getVertices()
	{
		return vertices;
	}

	const vector<Vertex>& SimpleMesh::getVertices() const
	{
		return vertices;
	}

	bool SimpleMesh::isVisible() const
	{
		return visible;
	}

	void SimpleMesh::render(Renderer& renderer) const
	{
		renderer.render(*this);
	}

	void SimpleMesh::setColor(const Vector4& color)
	{
		this->color = color;
	}

	void SimpleMesh::setNormalMap(Texture*)
	{
	}

	void SimpleMesh::setPosition(const Vector2& position)
	{
		this->position = position;
	}

	void SimpleMesh::setPrimitiveType(PrimitiveType)
	{
		this->primitiveType = primitiveType;
	}

	void SimpleMesh::setTexture(Texture*)
	{
	}

	void SimpleMesh::setVisible(bool visible)
	{
		this->visible = visible;
	}
}
