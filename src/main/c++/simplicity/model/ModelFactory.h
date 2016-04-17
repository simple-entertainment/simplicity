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
			 * Contains all the information required to cook a simple-shaped mesh.
			 * </p>
			 */
			struct Recipe
			{
				enum class Shape
				{
					BOX,
					CIRCLE,
					CYLINDER,
					HEMISPHERE,
					PRISM,
					PYRAMID,
					RECTANGLE,
					SPHERE
				};

				Recipe() :
					buffer(nullptr),
					color(1.0f, 1.0f, 1.0f, 1.0f),
					dimensions(1.0f, 1.0f, 1.0f),
					divisions(10),
					inwardFaces(false),
					outwardFaces(true),
					shape(Shape::BOX),
					smooth(false)
				{
				}

				/**
				 * <p>
				 * The buffer used to store the mesh data (optional).
				 * </p>
				 */
				std::shared_ptr<MeshBuffer> buffer;

				/**
				 * <p>
				 * The color to apply to all vertices.
				 * </p>
				 */
				Vector4 color;

				/**
				 * <p>
				 * The dimensions of the shape. Different shapes interpret these dimensions differently:
				 * </p>
				 *
				 * <p>
				 * <pre>
				 * BOX			[width, height, depth]
				 * CIRCLE		[diameter, <ignored>, <ignored>]
				 * CYLINDER		[diameter, length, <ignored>]
				 * HEMISPHERE	[diameter, <ignored>, <ignored>]
				 * PRISM		[width, height, depth]
				 * PYRAMID		[width/depth, height, <ignored>]
				 * RECTANGLE	[width, height, <ignored>]
				 * SPHERE		[diameter, <ignored>, <ignored>]
				 * </pre>
				 * </p>
				 */
				Vector3 dimensions;

				/**
				 * <p>
				 * The number of divisions in the shape (more divisions result in a more rounded surface). This value is
				 * only used by the CIRCLE, CYLINDER, HEMISPHERE and SPHERE shapes.
				 * </p>
				 */
				unsigned int divisions;

				/**
				 * <p>
				 * Determines if the inward faces should be included. If this is true, the mesh will be visible from
				 * the inside.
				 * </p>
				 */
				bool inwardFaces;

				/**
				 * <p>
				 * Determines if the outward faces should be included. If this is true, the mesh will be visible from
				 * the outside.
				 * </p>
				 */
				bool outwardFaces;

				/**
				 * <p>
				 * The shape to cook.
				 * </p>
				 */
				Shape shape;

				/**
				 * <p>
				 * Determines if the normals should simulate a smooth rounded surface. This value is only used by the
				 * CIRCLE, CYLINDER, HEMISPHERE and SPHERE shapes.
				 * </p>
				 */
				bool smooth;
			};

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
			 * Cooks a simple-shaped mesh using the given recipe.
			 * </p>
			 *
			 * <p>
			 * This is a work in progress so some recipe information may be ignored by some shapes.
			 * </p>
			 *
			 * @param recipe The recipe to cook.
			 *
			 * @return The simple-shaped mesh.
			 */
			static std::unique_ptr<Mesh> cookMesh(const Recipe& recipe);

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
			static std::unique_ptr<Mesh> createHeightMapMesh(const std::vector<std::vector<float>>& heightMap,
															 unsigned int minX, unsigned int maxX, unsigned int minZ,
															 unsigned int maxZ,
															 std::shared_ptr<MeshBuffer> buffer = nullptr,
															 const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f));

			/**
			 * <p>
			 * Creates an empty mesh.
			 * </p>
			 *
			 * @param vertexCount The number of vertices to allocate space for.
			 * @param indexCount The number of indices to allocate space for. If this is set to 0, the vertices are
			 * assumed to be non-indexed.
			 * @param buffer The recipe to cook.
			 *
			 * @return The empty mesh.
			 */
			static std::unique_ptr<Mesh> createMesh(unsigned int vertexCount, unsigned int indexCount = 0,
													std::shared_ptr<MeshBuffer> buffer = nullptr);

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
			static std::shared_ptr<MeshBuffer> createMeshBuffer(unsigned int vertexCount, unsigned int indexCount = 0,
																Buffer::AccessHint accessHint = Buffer::AccessHint::NONE);

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
			static std::unique_ptr<Mesh> createTriangleMesh(const Vector3& top, const Vector3& toBottomLeft,
															const Vector3& toBottomRight,
															std::shared_ptr<MeshBuffer> buffer = nullptr,
															const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
															bool doubleSided = false);

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
			static void insertCircleVertices(Vertex* vertices, unsigned int index, float radius, unsigned int divisions,
											 const Vector3& center, const Vector4& color);

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
												const Vector3& toTopRight, const Vector3& toBottomLeft,
												const Vector4& color);

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
											   const Vector3& toBottomLeft, const Vector3& toBottomRight,
											   const Vector4& color);

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
											 unsigned int divisions, const Vector3& center, const Vector4& color,
											 bool smooth = true);

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
			static std::unique_ptr<Mesh> loadObj(Resource& resource, std::shared_ptr<MeshBuffer> buffer = nullptr,
												 const Vector4& color = Vector4(1.0f, 1.0f, 1.0f, 1.0f),
												 float scale = 1.0f);

			/**
			 * <p>
			 * Loads a model from OBJ data. This is faster than the version that does not take counts as it is able to
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
			static std::unique_ptr<Mesh> loadObj(Resource& resource, std::shared_ptr<MeshBuffer> buffer,
												 const Vector4& color, float scale, unsigned int normalCount,
												 unsigned int positionCount, unsigned int texCoordCount,
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

			static std::unique_ptr<Mesh> cookBoxMesh(const Recipe& recipe);

			static std::unique_ptr<Mesh> cookCircleMesh(const Recipe& recipe);

			static std::unique_ptr<Mesh> cookCylinderMesh(const Recipe& recipe);

			static std::unique_ptr<Mesh> cookHemisphereMesh(const Recipe& recipe);

			static std::unique_ptr<Mesh> cookPrismMesh(const Recipe& recipe);

			static std::unique_ptr<Mesh> cookPyramidMesh(const Recipe& recipe);

			static std::unique_ptr<Mesh> cookRectangleMesh(const Recipe& recipe);

			static std::unique_ptr<Mesh> cookSphereMesh(const Recipe& recipe);

			virtual std::shared_ptr<MeshBuffer> createMeshBufferInternal(unsigned int vertexCount,
																		 unsigned int indexCount,
																		 Buffer::AccessHint accessHint) = 0;

			static Vector3 getPointOnSphere(float radius, unsigned int divisions, unsigned int latitude,
											unsigned int longitude);

			static std::vector<std::string> splitString(std::string& split, std::istream& source, char delimiter,
														unsigned int estimatedSplitCount);
	};
}

#endif /* MODELFACTORY_H_ */
