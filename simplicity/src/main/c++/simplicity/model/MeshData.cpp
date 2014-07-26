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
#include "MeshData.h"

namespace simplicity
{
	MeshData::MeshData() :
		vertexCount(0),
		vertexData(nullptr),
		indexCount(0),
		indexData(nullptr)
	{
	}

	Vertex& MeshData::operator[](unsigned int index)
	{
		if (indexCount == 0)
		{
			return vertexData[index];
		}

		return vertexData[indexData[index]];
	}

	const Vertex& MeshData::operator[](unsigned int index) const
	{
		if (indexCount == 0)
		{
			return vertexData[index];
		}

		return vertexData[indexData[index]];
	}

	unsigned int MeshData::size() const
	{
		if (indexCount == 0)
		{
			return vertexCount;
		}

		return indexCount;
	}
}
