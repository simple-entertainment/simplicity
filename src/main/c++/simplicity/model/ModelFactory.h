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

#include "../resources/Resource.h"
#include "Mesh.h"
#include "MeshBuffer.h"

namespace simplicity
{
	/**
	 * <p>
	 * A factory that creates meshes of various pre-defined shapes or using specified vertices and indices.
	 * </p>
	 */
	class SIMPLE_API ModelFactory
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~ModelFactory()
			{
			}

			/**
			 * <p>
			 * Creates a box mesh.
			 * </p>
			 *
			 * @param halfExtents The half extents (half the lengths on each dimension) of the box.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the box.
			 * @param doubleSided Determines if the box should be double-sided (face inward and outward).
			 *
			 * @return A box mesh.
			 */
			std::unique_ptr<Mesh> createBoxMesh(const Vector3& halfExtents,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
					bool doubleSided = false);

			/**
			 * <p>
			 * Creates an allocated mesh buffer with enough space for the given quantities of vertices and indices.
			 * </p>
			 *
			 * @param vertexCount The number of vertices to allocate space for.
			 * @param indexCount The number of indices to allocate space for. If this is set to 0, the vertices are
			 * assumed to be non-indexed.
			 * @param accessHint The hinted accessibility of the buffer's data.
			 *
			 * @return An allocated mesh buffer with enough space for the given quantities of vertices and indices.
			 */
			virtual std::shared_ptr<MeshBuffer> createMeshBuffer(unsigned int vertexCount, unsigned int indexCount = 0,
					Buffer::AccessHint accessHint = Buffer::AccessHint::NONE) = 0;

			/**
			 * <p>
			 * Creates a circle mesh.
			 * </p>
			 *
			 * @param radius The radius of the circle.
			 * @param divisions The number of divisions in the circle (more divisions result in a more rounded surface).
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the circle.
			 *
			 * @return A circle mesh.
			 */
			std::unique_ptr<Mesh> createCircleMesh(float radius, unsigned int divisions,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f));

			/**
			 * <p>
			 * Creates a cube mesh.
			 * </p>
			 *
			 * @param halfExtent The half extents (half the lengths on all dimensions) of the cube.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the cube.
			 * @param doubleSided Determines if the cube should be double-sided (face inward and outward).
			 *
			 * @return A cube mesh.
			 */
			std::unique_ptr<Mesh> createCubeMesh(float halfExtent,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
					bool doubleSided = false);

			/**
			 * <p>
			 * Creates a cylinder mesh.
			 * </p>
			 *
			 * @param radius The radius of the cylinder.
			 * @param length The length of the cylinder.
			 * @param divisions The number of divisions in the cylinder (more divisions result in a more rounded
			 * surface).
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the cylinder.
			 * @param doubleSided Determines if the cylinder should be double-sided (face inward and outward).
			 * @param smooth Determines if the normals should simulate a smooth rounded surface.
			 *
			 * @return A cylinder mesh.
			 */
			std::unique_ptr<Mesh> createCylinderMesh(float radius, float length, unsigned int divisions,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
					bool doubleSided = false,
					bool smooth = true);

			/**
			 * <p>
			 * Creates a mesh from a height map. The height map should have the dimensions maxX - minX and maxY - minY.
			 * </p>
			 *
			 * @param heightMap The height map.
			 * @param minX The minimum position on the x axis.
			 * @param maxX The maximum position on the x axis.
			 * @param minZ The minimum position on the y axis.
			 * @param maxZ The maximum position on the y axis.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the height map mesh.
			 *
			 * @return A height map mesh.
			 */
			std::unique_ptr<Mesh> createHeightMapMesh(const std::vector<std::vector<float>>& heightMap,
					unsigned int minX, unsigned int maxX, unsigned int minZ, unsigned int maxZ,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f));

			/**
			 * <p>
			 * Creates a hemisphere mesh.
			 * </p>
			 *
			 * @param radius The radius of the hemisphere.
			 * @param divisions The number of divisions in the hemisphere (more divisions result in a more rounded
			 * surface).
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the hemisphere.
			 * @param doubleSided Determines if the hemisphere should be double-sided (face inward and outward).
			 *
			 * @return A hemisphere mesh.
			 */
			std::unique_ptr<Mesh> createHemisphereMesh(float radius, unsigned int divisions,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
					bool doubleSided = false);

			/**
			 * <p>
			 * Creates a prism mesh.
			 * </p>
			 *
			 * @param halfExtents The half extents (half the lengths on each dimension) of the prism.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the prism.
			 *
			 * @return A prism mesh.
			 */
			std::unique_ptr<Mesh> createPrismMesh(const Vector3& halfExtents,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f));

			/**
			 * <p>
			 * Creates a pyramid mesh.
			 * </p>
			 *
			 * @param halfBaseExtent The half extents (half the lengths on the base dimensions) of the pyramid.
			 * @param height The height of the pyramid.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the pyramid.
			 *
			 * @return A pyramid mesh.
			 */
			std::unique_ptr<Mesh> createPyramidMesh(float halfBaseExtent, float height,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f));

			/**
			 * <p>
			 * Creates a rectangle mesh.
			 * </p>
			 *
			 * @param halfWidth The half extent (half the length) of the width of the rectangle.
			 * @param halfHeight The half extent (half the length) of the height of the rectangle.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the rectangle.
			 * @param doubleSided Determines if the rectangle should be double-sided (face both ways).
			 *
			 * @return A rectangle mesh.
			 */
			std::unique_ptr<Mesh> createRectangleMesh(float halfWidth, float halfHeight,
													  std::shared_ptr<MeshBuffer> buffer = nullptr,
													  const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
													  bool doubleSided = false);

			/**
			 * <p>
			 * Creates a sphere mesh.
			 * </p>
			 *
			 * @param radius The radius of the sphere.
			 * @param divisions The number of divisions in the sphere (more divisions result in a more rounded
			 * surface).
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the sphere.
			 * @param smooth Determines if the normals should simulate a smooth rounded surface.
			 *
			 * @return A sphere mesh.
			 */
			std::unique_ptr<Mesh> createSphereMesh(float radius, unsigned int divisions,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
					bool smooth = true);

			/**
			 * <p>
			 * Creates a square mesh.
			 * </p>
			 *
			 * @param halfExtent The half extents (half the lengths on both dimensions) of the square.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the square.
			 * @param doubleSided Determines if the square should be double-sided (face both ways).
			 *
			 * @return A square mesh.
			 */
			std::unique_ptr<Mesh> createSquareMesh(float halfExtent,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
					bool doubleSided = false);

			/**
			 * <p>
			 * Creates a triangle mesh.
			 * </p>
			 *
			 * @param top The top corner position of the triangle.
			 * @param toBottomLeft A vector from the top corner position to the bottom left corner position.
			 * @param toBottomRight A vector from the top corner position to the bottom right corner position.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the triangle.
			 * @param doubleSided Determines if the triangle should be double-sided (face both ways).
			 *
			 * @return A triangle mesh.
			 */
			std::unique_ptr<Mesh> createTriangleMesh(const Vector3& top, const Vector3& toBottomLeft,
					const Vector3& toBottomRight,
					std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
					bool doubleSided = false);

			/**
			 * <p>
			 * Retrieves the concrete factory instance used to create the meshes.
			 * </p>
			 *
			 * @return The concrete factory instance.
			 */
			static ModelFactory* getInstance();

			/**
			 * <p>
			 * Inserts the indices of a circle with the specified properties into the indices provided.
			 * </p>
			 *
			 * @param indices The indices to insert the circle indices into.
			 * @param index The index at which to insert the circle indices.
			 * @param vertexIndex The index of the first vertex that makes up the circle geometry.
			 * @param divisions The number of divisions in the circle.
			 * @param reverse Determines if the circle should be reversed (face the opposite direction).
			 */
			static void insertCircleIndices(unsigned int* indices, unsigned int index, unsigned int vertexIndex,
					unsigned int divisions, bool reverse = false);

			/**
			 * <p>
			 * Inserts the vertices of a circle with the specified properties into the vertices provided.
			 * </p>
			 *
			 * @param vertices The vertices to insert the circle vertices into.
			 * @param index The index at which to insert the circle vertices.
			 * @param radius The radius of the circle.
			 * @param divisions The number of divisions in the circle.
			 * @param center The center position of the circle.
			 * @param color The color of the circle.
			 */
			static void insertCircleVertices(Vertex* vertices, unsigned int index, float radius,
					unsigned int divisions, const Vector3& center, const Vector4& color);

			/**
			 * <p>
			 * Inserts the indices of a rectangle into the indices provided.
			 * </p>
			 *
			 * @param indices The indices to insert the rectangle indices into.
			 * @param index The index at which to insert the rectangle indices.
			 * @param vertexIndex The index of the first vertex that makes up the rectangle geometry.
			 * @param reverse Determines if the rectangle should be reversed (face the opposite direction).
			 */
			static void insertRectangleIndices(unsigned int* indices, unsigned int index, unsigned int vertexIndex,
					bool reverse = false);

			/**
			 * <p>
			 * Inserts the vertices of a rectangle with the specified properties into the vertices provided.
			 * </p>
			 *
			 * @param vertices The vertices to insert the rectangle vertices into.
			 * @param index The index at which to insert the rectangle vertices.
			 * @param topLeft The top left corner position of the rectangle.
			 * @param toTopRight The top right corner position of the rectangle.
			 * @param toBottomLeft The bottom left corner position of the rectangle.
			 * @param color The color of the rectangle.
			 */
			static void insertRectangleVertices(Vertex* vertices, unsigned int index, const Vector3& topLeft,
					const Vector3& toTopRight, const Vector3& toBottomLeft, const Vector4& color);

			/**
			 * <p>
			 * Inserts the indices of a triangle into the indices provided.
			 * </p>
			 *
			 * @param indices The indices to insert the triangle indices into.
			 * @param index The index at which to insert the triangle indices.
			 * @param vertexIndex The index of the first vertex that makes up the triangle geometry.
			 * @param reverse Determines if the triangle should be reversed (face the opposite direction).
			 */
			static void insertTriangleIndices(unsigned int* indices, unsigned int index, unsigned int vertexIndex,
					bool reverse = false);

			/**
			 * <p>
			 * Inserts the vertices of a triangle with the specified properties into the vertices provided.
			 * </p>
			 *
			 * @param vertices The vertices to insert the triangle vertices into.
			 * @param index The index at which to insert the triangle vertices.
			 * @param top The top corner position of the triangle.
			 * @param toBottomLeft A vector from the top corner position to the bottom left corner position.
			 * @param toBottomRight A vector from the top corner position to the bottom right corner position.
			 * @param color The color of the triangle.
			 */
			static void insertTriangleVertices(Vertex* vertices, unsigned int index, const Vector3& top,
					const Vector3& toBottomLeft, const Vector3& toBottomRight, const Vector4& color);

			/**
			 * <p>
			 * Inserts the indices of a tunnel with the specified properties into the indices provided.
			 * </p>
			 *
			 * @param indices The indices to insert the tunnel indices into.
			 * @param index The index at which to insert the tunnel indices.
			 * @param vertexIndex The index of the first vertex that makes up the tunnel geometry.
			 * @param divisions The number of divisions in the tunnel.
			 * @param reverse Determines if the tunnel should be reversed (face inward instead of outward).
			 */
			static void insertTunnelIndices(unsigned int* indices, unsigned int index, unsigned int vertexIndex,
					unsigned int divisions, bool reverse = false);

			/**
			 * <p>
			 * Inserts the vertices of a tunnel with the specified properties into the vertices provided.
			 * </p>
			 *
			 * @param vertices The vertices to insert the tunnel vertices into.
			 * @param index The index at which to insert the tunnel vertices.
			 * @param radius The radius of the tunnel.
			 * @param length The length of the tunnel.
			 * @param divisions The number of divisions in the tunnel.
			 * @param center The center position of the tunnel.
			 * @param color The color of the tunnel.
			 * @param smooth Determines if the normals should simulate a smooth rounded surface.
			 */
			static void insertTunnelVertices(Vertex* vertices, unsigned int index, float radius, float length,
					unsigned int divisions, const Vector3& center, const Vector4& color, bool smooth = true);

			/**
			 * <p>
			 * Loads a model from OBJ data.
			 * </p>
			 *
			 * <p>
			 * NOTE: The Model described in the .OBJ data must be constructed entirely from triangle polygons.
			 * </p>
			 *
			 * @param resource The resource containing the OBJ data.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the model.
			 * @param scale The scale of the model.
			 *
			 * @return The model created from the OBJ data.
			 */
			std::unique_ptr<Mesh> loadObj(Resource& resource, std::shared_ptr<MeshBuffer> buffer = nullptr,
					const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f), float scale = 1.0f);

			/**
			 * <p>
			 * Loads a model from OBJ data. This is faster than the version that does not take countsas it is able to
			 * pre-allocate the correctly-sized memory blocks.
			 * </p>
			 *
			 * <p>
			 * NOTE: The Model described in the .OBJ data must be constructed entirely from triangle polygons.
			 * </p>
			 *
			 * @param resource The resource containing the OBJ data.
			 * @param buffer The buffer used to store the mesh data (optional).
			 * @param color The color of the model.
			 * @param scale The scale of the model.
			 * @param normalCount The number of normals in the mesh.
			 * @param positionCount The number of positions in the mesh.
			 * @param texCoordCount The number of texture coordinates in the mesh.
			 * @param vertexCount The number of vertices in the mesh.
			 *
			 * @return The model created from the OBJ data.
			 */
			std::unique_ptr<Mesh> loadObj(Resource& resource, std::shared_ptr<MeshBuffer> buffer, const Vector4& color,
					float scale, unsigned int normalCount, unsigned int positionCount, unsigned int texCoordCount,
					unsigned int vertexCount);

			/**
			 * <p>
			 * Sets the concrete factory instance used to create the meshes.
			 * </p>
			 *
			 * @param instance The concrete factory instance.
			 */
			static void setInstance(std::unique_ptr<ModelFactory> instance);

		private:
			static std::unique_ptr<ModelFactory> instance;

			std::unique_ptr<Mesh> createMesh(std::shared_ptr<MeshBuffer> buffer, unsigned int vertexCount,
					unsigned int indexCount);

			Vector3 getPointOnSphere(float radius, unsigned int divisions, unsigned int latitude,
					unsigned int longitude);
	};
}

#endif /* MODELFACTORY_H_ */
