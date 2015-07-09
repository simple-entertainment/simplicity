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
#ifndef SIMPLEMESHBUFFER_H_
#define SIMPLEMESHBUFFER_H_

#include <map>
#include <vector>

#include "MeshBuffer.h"

namespace simplicity
{
	/**
	 * <p>
	 * A simple implementation of a mesh buffer. No fancy GPU stuff here.
	 * </p>
	 */
	class SIMPLE_API SimpleMeshBuffer : public MeshBuffer
	{
		public:
			/**
			 * @param vertexCount The number of vertices to allocate space for.
			 * @param indexCount The number of indices to allocate space for.
			 * @param accessHint The hinted accessibility of this buffer's data.
			 */
			SimpleMeshBuffer(const unsigned int vertexCount, unsigned int indexCount, Buffer::AccessHint accessHint);

			Buffer::AccessHint getAccessHint() const override;

			unsigned int getBaseIndex(const Mesh& mesh) const override;

			unsigned int getBaseVertex(const Mesh& mesh) const override;

			MeshData& getData(const Mesh& mesh, bool readable) override;

			const MeshData& getData(const Mesh& mesh) const override;

			unsigned int getIndexCount(const Mesh& mesh) const override;

			Pipeline* getPipeline() const override;

			PrimitiveType getPrimitiveType() const override;

			unsigned int getVertexCount(const Mesh& mesh) const override;

			bool isIndexed() const override;

			void releaseData(const Mesh& mesh) const override;

			void setPipeline(std::shared_ptr<Pipeline> pipeline) override;

			void setPrimitiveType(PrimitiveType primitiveType) override;

		private:
			Buffer::AccessHint accessHint;

			mutable Mesh* accessingMesh;

			mutable std::map<const Mesh*, unsigned int> baseIndices;

			mutable std::map<const Mesh*, unsigned int> baseVertices;

			mutable std::map<const Mesh*, unsigned int> indexCounts;

			std::vector<unsigned int> indexData;

			bool indexed;

			mutable MeshData meshData;

			mutable unsigned int nextFreeIndex;

			mutable unsigned int nextFreeVertex;

			std::shared_ptr<Pipeline> pipeline;

			PrimitiveType primitiveType;

			mutable std::map<const Mesh*, unsigned int> vertexCounts;

			std::vector<Vertex> vertexData;
	};
}

#endif /* SIMPLEMESHBUFFER_H_ */
