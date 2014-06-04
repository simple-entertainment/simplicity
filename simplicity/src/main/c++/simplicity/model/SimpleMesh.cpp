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
	SimpleMesh::SimpleMesh(const vector<unsigned int>& indices, const vector<Vertex>& vertices) :
		color(0.0f, 0.0f, 0.0f, 1.0f),
		indices(indices),
		primitiveType(PrimitiveType::TRIANGLE_LIST),
		vertices(vertices),
		visible(true)
	{
	}

	Mesh::Access SimpleMesh::getAccess() const
	{
		return Access::READ_WRITE;
	}

	const Vector4& SimpleMesh::getColor() const
	{
		return color;
	}

	unsigned int SimpleMesh::getIndexCount() const
	{
		return indices.size();
	}

	unsigned int* SimpleMesh::getIndices()
	{
		return indices.data();
	}

	const unsigned int* SimpleMesh::getIndices() const
	{
		return indices.data();
	}

	Texture* SimpleMesh::getNormalMap() const
	{
		return nullptr;
	}

	Model::PrimitiveType SimpleMesh::getPrimitiveType() const
	{
		return primitiveType;
	}

	Texture* SimpleMesh::getTexture() const
	{
		return nullptr;
	}

	unsigned short SimpleMesh::getTypeID() const
	{
		return TYPE_ID;
	}

	unsigned int SimpleMesh::getVertexCount() const
	{
		return vertices.size();
	}

	Vertex* SimpleMesh::getVertices()
	{
		return vertices.data();
	}

	const Vertex* SimpleMesh::getVertices() const
	{
		return vertices.data();
	}

	void SimpleMesh::init()
	{
	}

	bool SimpleMesh::isVisible() const
	{
		return visible;
	}

	void SimpleMesh::resizeIndices(unsigned int size)
	{
		indices.resize(size);
	}

	void SimpleMesh::resizeVertices(unsigned int size)
	{
		vertices.resize(size);
	}

	void SimpleMesh::setColor(const Vector4& color)
	{
		this->color = color;
	}

	void SimpleMesh::setNormalMap(Texture*)
	{
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
