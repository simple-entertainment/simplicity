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
#include "SimpleMeshBuffer.h"

using namespace std;

namespace simplicity
{
	SimpleMeshBuffer::SimpleMeshBuffer(const unsigned int vertexCount, unsigned int indexCount, AccessHint accessHint) :
			accessHint(accessHint),
			baseIndices(),
			baseVertices(),
			indexCounts(),
			indexData(indexCount),
			indexed(indexCount > 0),
			meshData(),
			nextFreeIndex(0),
			nextFreeVertex(0),
			vertexCounts(),
			vertexData(vertexCount)
	{
	}

	MeshBuffer::AccessHint SimpleMeshBuffer::getAccessHint() const
	{
		return accessHint;
	}

	unsigned int SimpleMeshBuffer::getBaseIndex(const Mesh& mesh) const
	{
		return baseIndices[&mesh];
	}

	unsigned int SimpleMeshBuffer::getBaseVertex(const Mesh& mesh) const
	{
		return baseVertices[&mesh];
	}

	MeshData& SimpleMeshBuffer::getData(const Mesh& mesh, bool /* readable */, bool /* writable */)
	{
		const MeshData& meshData = static_cast<const SimpleMeshBuffer*>(this)->getData(mesh);
		return const_cast<MeshData&>(meshData);
	}

	const MeshData& SimpleMeshBuffer::getData(const Mesh& mesh) const
	{
		// Sorry about the const casts!!!
		// Fear not though, the MeshData object they are being given to is returned as const.

		if (baseVertices.find(&mesh) == baseVertices.end())
		{
			baseVertices[&mesh] = nextFreeVertex;
			vertexCounts[&mesh] = 0;
		}

		meshData.vertexCount = vertexCounts[&mesh];
		meshData.vertexData = const_cast<Vertex*>(&vertexData[baseVertices[&mesh]]);

		if (indexed)
		{
			if (baseIndices.find(&mesh) == baseIndices.end())
			{
				baseIndices[&mesh] = nextFreeIndex;
				indexCounts[&mesh] = 0;
			}

			meshData.indexCount = indexCounts[&mesh];
			meshData.indexData = const_cast<unsigned int*>(&indexData[baseIndices[&mesh]]);
		}

		return meshData;
	}

	unsigned int SimpleMeshBuffer::getIndexCount(const Mesh& mesh) const
	{
		return indexCounts[&mesh];
	}

	unsigned int SimpleMeshBuffer::getVertexCount(const Mesh& mesh) const
	{
		return vertexCounts[&mesh];
	}

	bool SimpleMeshBuffer::isIndexed() const
	{
		return indexed;
	}

	void SimpleMeshBuffer::releaseData(const Mesh& mesh) const
	{
		vertexCounts[&mesh] = meshData.vertexCount;

		unsigned int verticesEnd = baseVertices[&mesh] + vertexCounts[&mesh];
		if (verticesEnd > nextFreeVertex)
		{
			nextFreeVertex = verticesEnd;
		}

		if (indexed)
		{
			indexCounts[&mesh] = meshData.indexCount;

			unsigned int indicesEnd = baseIndices[&mesh] + indexCounts[&mesh];
			if (indicesEnd > nextFreeIndex)
			{
				nextFreeIndex = indicesEnd;
			}
		}
	}
}
