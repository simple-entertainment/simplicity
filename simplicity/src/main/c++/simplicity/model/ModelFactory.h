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
#ifndef MODELFACTORY_H_
#define MODELFACTORY_H_

#include <memory>
#include <vector>

#include "Mesh.h"
#include "Vertex.h"

namespace simplicity
{
	class ModelFactory
	{
		public:
			virtual ~ModelFactory()
			{
			}

			static void addCircleIndexList(std::vector<unsigned int>& indices, unsigned int index,
				unsigned int vertexIndex, unsigned int divisions, bool reverse = false);

			static void addCircleVertexList(std::vector<Vertex>& vertices, unsigned int index, float radius,
					unsigned int divisions, const Vector3& center, const Vector4& colour);

			static void addRectangleIndexList(std::vector<unsigned int>& indices, unsigned int index,
				unsigned int vertexIndex, bool reverse = false);

			static void addRectangleVertexList(std::vector<Vertex>& vertices, unsigned int index,
					const Vector3& topLeft, const Vector3& toTopRight, const Vector3& toBottomLeft,
					const Vector4& colour);

			static void addTriangleIndexList(std::vector<unsigned int>& indices, unsigned int index,
				unsigned int vertexIndex, bool reverse = false);

			static void addTriangleVertexList(std::vector<Vertex>& vertices, unsigned int index, const Vector3& top,
					const Vector3& toBottomLeft, const Vector3& toBottomRight, const Vector4& colour);

			static void addTunnelIndexList(std::vector<unsigned int>& indices, unsigned int index,
				unsigned int vertexIndex, unsigned int divisions, bool reverse = false);

			static void addTunnelVertexList(std::vector<Vertex>& vertices, unsigned int index, float radius,
					float length, unsigned int divisions, const Vector3& center, const Vector4& colour,
					bool smooth = true);

			std::unique_ptr<Mesh> createBoxMesh(const Vector3& halfExtents, const Vector4& color,
				bool doubleSided = false);

			std::unique_ptr<Mesh> createCircleMesh(float radius, unsigned int divisions, const Vector4& color);

			std::unique_ptr<Mesh> createCubeMesh(float halfExtent, const Vector4& color, bool doubleSided = false);

			std::unique_ptr<Mesh> createCylinderMesh(float radius, float length, unsigned int divisions,
					const Vector4& color, bool smooth = true);

			std::unique_ptr<Mesh> createHeightMapMesh(const std::vector<std::vector<float>>& heightMap,
					unsigned int minX, unsigned int maxX, unsigned int minZ, unsigned int maxZ, const Vector4& color);

			virtual std::unique_ptr<Mesh> createMesh(const std::vector<Vertex>& vertices) = 0;

			virtual std::unique_ptr<Mesh> createMesh(const std::vector<Vertex>& vertices,
				const std::vector<unsigned int>& indices) = 0;

			std::unique_ptr<Mesh> createPrismMesh(const Vector3& halfExtents, const Vector4& color);

			std::unique_ptr<Mesh> createPyramidMesh(float halfBaseExtent, float height, const Vector4& color);

			std::unique_ptr<Mesh> createSphereMesh(float radius, unsigned int divisions, const Vector4& color,
					bool smooth = true);

			std::unique_ptr<Mesh> createSquareMesh(float halfExtent, const Vector4& color, bool doubleSided = false);

			std::unique_ptr<Mesh> createTriangleMesh(const Vector3& top, const Vector3& toBottomLeft,
					const Vector3& toBottomRight, const Vector4& color, bool doubleSided = false);

			static ModelFactory& getInstance();

			static void setInstance(std::unique_ptr<ModelFactory> instance);

		private:
			static std::unique_ptr<ModelFactory> instance;

			Vector3 getPointOnSphere(float radius, unsigned int divisions, unsigned int latitude,
					unsigned int longitude);
	};
}

#endif /* MODELFACTORY_H_ */
