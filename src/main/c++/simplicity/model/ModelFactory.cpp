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
#include <sstream>

#include "../logging/Logs.h"

#include "../math/MathConstants.h"
#include "../math/MathFunctions.h"
#include "ModelFactory.h"

using namespace std;

// TODO All the doubleSided meshes have incorrect normals on the back side... they need to be reversed.
namespace simplicity
{
	unique_ptr<ModelFactory> ModelFactory::instance = unique_ptr<ModelFactory>();

	const unsigned int MAX_SPLIT_LENGTH = 256;

	unique_ptr<Mesh> ModelFactory::cookBoxMesh(const Recipe& recipe)
	{
		unsigned int vertexCount = 24;
		unsigned int indexCount = 0;
		if (recipe.inwardFaces)
		{
			indexCount += 36;
		}
		if (recipe.outwardFaces)
		{
			indexCount += 36;
		}

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount, recipe.buffer);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;
		const Vector3& dimensions = recipe.dimensions;
		Vector3 halfDimensions = dimensions * 0.5f;

		// Top
		insertRectangleVertices(meshData.vertexData, 0,
								Vector3(-halfDimensions.X(), halfDimensions.Y(), -halfDimensions.Z()),
								Vector3(dimensions.X(), 0.0f, 0.0f),
								Vector3(0.0f, 0.0f, dimensions.Z()),
								recipe.color);

		// Bottom
		insertRectangleVertices(meshData.vertexData, 4,
								Vector3(-halfDimensions.X(), -halfDimensions.Y(), halfDimensions.Z()),
								Vector3(dimensions.X(), 0.0f, 0.0f),
								Vector3(0.0f, 0.0f, -dimensions.Z()),
								recipe.color);

		// North
		insertRectangleVertices(meshData.vertexData, 8,
								Vector3(halfDimensions.X(), halfDimensions.Y(), -halfDimensions.Z()),
								Vector3(-dimensions.X(), 0.0f, 0.0f),
								Vector3(0.0f, -dimensions.Y(), 0.0f),
								recipe.color);

		// East
		insertRectangleVertices(meshData.vertexData, 12,
								Vector3(halfDimensions.X(), halfDimensions.Y(), halfDimensions.Z()),
								Vector3(0.0f, 0.0f, -dimensions.Z()),
								Vector3(0.0f, -dimensions.Y(), 0.0f),
								recipe.color);

		// South
		insertRectangleVertices(meshData.vertexData, 16,
								Vector3(-halfDimensions.X(), halfDimensions.Y(), halfDimensions.Z()),
								Vector3(dimensions.X(), 0.0f, 0.0f),
								Vector3(0.0f, -dimensions.Y(), 0.0f),
								recipe.color);

		// West
		insertRectangleVertices(meshData.vertexData, 20,
								Vector3(-halfDimensions.X(), halfDimensions.Y(), -halfDimensions.Z()),
								Vector3(0.0f, 0.0f, dimensions.Z()),
								Vector3(0.0f, -dimensions.Y(), 0.0f),
								recipe.color);

		// Indices
		meshData.indexCount = indexCount;

		unsigned int index = 0;
		unsigned int vertexIndex = 0;
		if (recipe.inwardFaces)
		{
			for (unsigned int faceIndex = 0; faceIndex < 6; faceIndex++)
			{
				insertRectangleIndices(meshData.indexData, index, vertexIndex, true);
				index += 6;
				vertexIndex += 4;
			}
		}
		if (recipe.outwardFaces)
		{
			for (unsigned int faceIndex = 0; faceIndex < 6; faceIndex++)
			{
				insertRectangleIndices(meshData.indexData, index, vertexIndex);
				index += 6;
				vertexIndex += 4;
			}
		}

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::cookCircleMesh(const Recipe& recipe)
	{
		unsigned int vertexCount = recipe.divisions + 1;
		unsigned int indexCount = recipe.divisions * 3;

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount, recipe.buffer);
		MeshData& meshData = mesh->getData(false);

		float radius = recipe.dimensions[0] * 0.5f;

		// Vertices
		meshData.vertexCount = vertexCount;
		insertCircleVertices(meshData.vertexData, 0, radius, recipe.divisions, Vector3(0.0f, 0.0f, 0.0f),
							 recipe.color);

		// Indices
		meshData.indexCount = indexCount;
		insertCircleIndices(meshData.indexData, 0, 0, recipe.divisions);

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::cookCubeMesh(const Recipe& recipe)
	{
		Recipe boxRecipe;
		boxRecipe.buffer = recipe.buffer;
		boxRecipe.color = recipe.color;
		boxRecipe.dimensions[0] = recipe.dimensions[0];
		boxRecipe.dimensions[1] = recipe.dimensions[0];
		boxRecipe.dimensions[2] = recipe.dimensions[0];
		boxRecipe.inwardFaces = recipe.inwardFaces;
		boxRecipe.outwardFaces = recipe.outwardFaces;

		return cookBoxMesh(boxRecipe);
	}

	unique_ptr<Mesh> ModelFactory::cookCylinderMesh(const Recipe& recipe)
	{
		unsigned int verticesInEnd = recipe.divisions + 1;
		unsigned int verticesInEnds = verticesInEnd * 2;
		unsigned int verticesInSide = 4;
		unsigned int verticesInSides = verticesInSide * recipe.divisions;
		unsigned int vertexCount = verticesInEnds + verticesInSides;

		unsigned int indicesInEnd = recipe.divisions * 3;
		unsigned int indicesInEnds = indicesInEnd * 2;
		unsigned int indicesInSide = 3 * 2;
		unsigned int indicesInSides = indicesInSide * recipe.divisions;
		unsigned int indexCount = 0;
		if (recipe.inwardFaces)
		{
			indexCount += indicesInEnds + indicesInSides;
		}
		if (recipe.outwardFaces)
		{
			indexCount += indicesInEnds + indicesInSides;
		}

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount,recipe.buffer);
		MeshData& meshData = mesh->getData(false);

		float radius = recipe.dimensions[0] * 0.5f;
		float length = recipe.dimensions[1];
		Vector3 center(0.0f, 0.0f, 0.0f);
		Vector3 toBack(0.0f, 0.0f, -length);

		// Vertices
		meshData.vertexCount = vertexCount;
		// Front
		insertCircleVertices(meshData.vertexData, 0, radius, recipe.divisions, center, recipe.color);
		// Back
		insertCircleVertices(meshData.vertexData, verticesInEnd, radius, recipe.divisions, toBack, recipe.color);
		// Sides
		insertTunnelVertices(meshData.vertexData, verticesInEnds, radius, length, recipe.divisions, center,
							 recipe.color, recipe.smooth);

		unsigned int index = 0;
		if (recipe.inwardFaces)
		{
			// Front
			insertCircleIndices(meshData.indexData, index, 0, recipe.divisions, true);
			// Back
			insertCircleIndices(meshData.indexData, index + indicesInEnd, verticesInEnd, recipe.divisions);
			//Sides
			insertTunnelIndices(meshData.indexData, index + indicesInEnds, verticesInEnds, recipe.divisions, true);

			index += indicesInEnds + indicesInSides;
		}
		if (recipe.outwardFaces)
		{
			// Indices
			meshData.indexCount = indexCount;
			// Front
			insertCircleIndices(meshData.indexData, index, 0, recipe.divisions);
			// Back
			insertCircleIndices(meshData.indexData, index + indicesInEnd, verticesInEnd, recipe.divisions, true);
			//Sides
			insertTunnelIndices(meshData.indexData, index + indicesInEnds, verticesInEnds, recipe.divisions);
		}

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::cookHemisphereMesh(const Recipe& recipe)
	{
		unsigned int vertexCount = (recipe.divisions / 2 + 1) * (recipe.divisions + 1);
		unsigned int indexCount = 0;
		if (recipe.inwardFaces)
		{
			indexCount += (recipe.divisions / 2) * (recipe.divisions) * 6;
		}
		if (recipe.outwardFaces)
		{
			indexCount += (recipe.divisions / 2) * (recipe.divisions) * 6;
		}

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount, recipe.buffer);
		MeshData& meshData = mesh->getData(false);

		float radius = recipe.dimensions[0] * 0.5f;

		// Vertices
		unsigned int index = 0;
		for (unsigned int latitude = 0; latitude <= recipe.divisions / 2; latitude++)
		{
			for (unsigned int longitude = 0; longitude <= recipe.divisions; longitude++)
			{
				meshData.vertexData[index].color = recipe.color;
				meshData.vertexData[index].position = getPointOnSphere(radius, recipe.divisions, latitude, longitude);
				meshData.vertexData[index].normal = meshData.vertexData[index].position;
				meshData.vertexData[index].normal.normalize();
				index++;
			}
		}

		meshData.vertexCount = index;

		// Indices
		index = 0;
		for (unsigned int latitude = 0; latitude < recipe.divisions / 2; latitude++)
		{
			for (unsigned int longitude = 0; longitude < recipe.divisions; longitude++)
			{
				if (recipe.inwardFaces)
				{
					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude + 1;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude;

					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude;
					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude + 1;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude + 1;
				}
				if (recipe.outwardFaces)
				{
					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude + 1;

					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude + 1;
					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude + 1;
				}
			}
		}

		meshData.indexCount = index;

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::cookMesh(const Recipe& recipe)
	{
		if (recipe.shape == Recipe::Shape::BOX)
		{
			return cookBoxMesh(recipe);
		}
		else if (recipe.shape == Recipe::Shape::CIRCLE)
		{
			return cookCircleMesh(recipe);
		}
		else if (recipe.shape == Recipe::Shape::CUBE)
		{
			return cookCubeMesh(recipe);
		}
		else if (recipe.shape == Recipe::Shape::CYLINDER)
		{
			return cookCylinderMesh(recipe);
		}
		else if (recipe.shape == Recipe::Shape::HEMISPHERE)
		{
			return cookHemisphereMesh(recipe);
		}
		else if (recipe.shape == Recipe::Shape::PRISM)
		{
			return cookPrismMesh(recipe);
		}
		else if (recipe.shape == Recipe::Shape::PYRAMID)
		{
			return cookPyramidMesh(recipe);
		}
		else if (recipe.shape == Recipe::Shape::RECTANGLE)
		{
			return cookRectangleMesh(recipe);
		}
		else if (recipe.shape == Recipe::Shape::SPHERE)
		{
			return cookSphereMesh(recipe);
		}

		return nullptr;
	}

	unique_ptr<Mesh> ModelFactory::cookPrismMesh(const Recipe& recipe)
	{
		unsigned int vertexCount = 18;
		unsigned int indexCount = 24;

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount, recipe.buffer);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;
		const Vector3& dimensions = recipe.dimensions;

		// Bottom
		insertRectangleVertices(meshData.vertexData, 0,
								Vector3(-dimensions.X(), -dimensions.Y(), -dimensions.Z()),
								Vector3(dimensions.X() * 2.0f, 0.0f, 0.0f),
								Vector3(0.0f, 0.0f, dimensions.Z() * 2.0f),
								recipe.color);

		// North
		insertRectangleVertices(meshData.vertexData, 4,
								Vector3(dimensions.X(), dimensions.Y(), dimensions.Z()),
								Vector3(dimensions.X() * -2.0f, 0.0f, 0.0f),
								Vector3(0.0f, dimensions.Y() * -2.0f, 0.0f),
								recipe.color);

		// East
		insertTriangleVertices(meshData.vertexData, 8,
							   Vector3(dimensions.X(), dimensions.Y(), dimensions.Z()),
							   Vector3(0.0f, dimensions.Y() * -2.0f, 0.0f),
							   Vector3(0.0f, dimensions.Y() * -2.0f, dimensions.Z() * -2.0f),
							   recipe.color);

		// South (slope)
		insertRectangleVertices(meshData.vertexData, 11,
								Vector3(-dimensions.X(), dimensions.Y(), dimensions.Z()),
								Vector3(dimensions.X() * 2.0f, 0.0f, 0.0f),
								Vector3(0.0f, dimensions.Y() * -2.0f, dimensions.Z() * -2.0f),
								recipe.color);

		// West
		insertTriangleVertices(meshData.vertexData, 15,
							   Vector3(-dimensions.X(), dimensions.Y(), dimensions.Z()),
							   Vector3(0.0f, dimensions.Y() * -2.0f, dimensions.Z() * -2.0f),
							   Vector3(0.0f, dimensions.Y() * -2.0f, 0.0f),
							   recipe.color);

		// Indices
		meshData.indexCount = indexCount;

		insertRectangleIndices(meshData.indexData, 0, 0);
		insertRectangleIndices(meshData.indexData, 6, 4);
		insertTriangleIndices(meshData.indexData, 12, 8);
		insertRectangleIndices(meshData.indexData, 15, 11);
		insertTriangleIndices(meshData.indexData, 21, 15);

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::cookPyramidMesh(const Recipe& recipe)
	{
		unsigned int vertexCount = 16;
		unsigned int indexCount = 18;

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount, recipe.buffer);
		MeshData& meshData = mesh->getData(false);

		float halfBaseExtent = recipe.dimensions[0] / 2.0f;
		float height = recipe.dimensions[1];
		float halfHeight = height / 2.0f;

		// Vertices
		meshData.vertexCount = vertexCount;

		// Bottom
		insertRectangleVertices(meshData.vertexData, 0,
								Vector3(-halfBaseExtent, -halfHeight, -halfBaseExtent),
								Vector3(0.0f, 0.0f, halfBaseExtent * 2.0f),
								Vector3(halfBaseExtent * 2.0f, 0.0f, 0.0f),
								recipe.color);

		// North
		insertTriangleVertices(meshData.vertexData, 4,
							   Vector3(0.0f, halfHeight, 0.0f),
							   Vector3(-halfBaseExtent, -height, halfBaseExtent),
							   Vector3(halfBaseExtent, -height, halfBaseExtent),
							   recipe.color);

		// East
		insertTriangleVertices(meshData.vertexData, 7,
							   Vector3(0.0f, halfHeight, 0.0f),
							   Vector3(halfBaseExtent, -height, halfBaseExtent),
							   Vector3(halfBaseExtent, -height, -halfBaseExtent),
							   recipe.color);

		// South
		insertTriangleVertices(meshData.vertexData, 10,
							   Vector3(0.0f, halfHeight, 0.0f),
							   Vector3(halfBaseExtent, -height, -halfBaseExtent),
							   Vector3(-halfBaseExtent, -height, -halfBaseExtent),
							   recipe.color);

		// West
		insertTriangleVertices(meshData.vertexData, 13,
							   Vector3(0.0f, halfHeight, 0.0f),
							   Vector3(-halfBaseExtent, -height, -halfBaseExtent),
							   Vector3(-halfBaseExtent, -height, halfBaseExtent),
							   recipe.color);

		// Indices
		meshData.indexCount = indexCount;

		insertRectangleIndices(meshData.indexData, 0, 0);
		insertTriangleIndices(meshData.indexData, 6, 4);
		insertTriangleIndices(meshData.indexData, 9, 7);
		insertTriangleIndices(meshData.indexData, 12, 10);
		insertTriangleIndices(meshData.indexData, 15, 13);

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::cookRectangleMesh(const Recipe& recipe)
	{
		unsigned int vertexCount = 4;
		unsigned int indexCount = 0;
		if (recipe.inwardFaces)
		{
			indexCount += 6;
		}
		if (recipe.outwardFaces)
		{
			indexCount += 6;
		}

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount, recipe.buffer);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;

		insertRectangleVertices(meshData.vertexData, 0,
								Vector3(-recipe.dimensions.X() * 0.5f, recipe.dimensions.Y() * 0.5f, 0.0f),
								Vector3(recipe.dimensions.X(), 0.0f, 0.0f),
								Vector3(0.0f, -recipe.dimensions.Y(), 0.0f),
								recipe.color);

		// Indices
		meshData.indexCount = indexCount;

		unsigned int index = 0;
		if (recipe.inwardFaces)
		{
			insertRectangleIndices(meshData.indexData, index, 0, true);

			index += 6;
		}
		if (recipe.outwardFaces)
		{
			insertRectangleIndices(meshData.indexData, index, 0);
		}

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::cookSphereMesh(const Recipe& recipe)
	{
		unsigned int vertexCount = pow(recipe.divisions + 1, 2);
		unsigned int indexCount = pow(recipe.divisions, 2) * 6;
		if (!recipe.smooth)
		{
			vertexCount *= 4;
		}

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount, recipe.buffer);
		MeshData& meshData = mesh->getData(false);

		float radius = recipe.dimensions[0] * 0.5f;

		// Vertices
		unsigned int index = 0;

		for (unsigned int latitude = 0; latitude <= recipe.divisions; latitude++)
		{
			for (unsigned int longitude = 0; longitude <= recipe.divisions; longitude++)
			{
				if (recipe.smooth)
				{
					meshData.vertexData[index].color = recipe.color;
					meshData.vertexData[index].position =
							getPointOnSphere(radius, recipe.divisions, latitude, longitude);
					meshData.vertexData[index].normal = meshData.vertexData[index].position;
					meshData.vertexData[index].normal.normalize();
					index++;
				}
				else if (latitude != recipe.divisions && longitude != recipe.divisions)
				{
					Vector3 position0 = getPointOnSphere(radius, recipe.divisions, latitude, longitude);
					Vector3 position1 = getPointOnSphere(radius, recipe.divisions, latitude + 1, longitude);
					Vector3 position2 = getPointOnSphere(radius, recipe.divisions, latitude + 1, longitude + 1);
					Vector3 position3 = getPointOnSphere(radius, recipe.divisions, latitude, longitude + 1);

					Vector3 edge0 = position1 - position0;
					Vector3 edge1 = position2 - position0;
					if (latitude == recipe.divisions - 1)
					{
						edge1 = position3 - position0;
					}
					Vector3 normal = crossProduct(edge0, edge1);
					normal.normalize();

					meshData.vertexData[index].color = recipe.color;
					meshData.vertexData[index].position = position0;
					meshData.vertexData[index].normal = normal;
					index++;
					meshData.vertexData[index].color = recipe.color;
					meshData.vertexData[index].position = position1;
					meshData.vertexData[index].normal = normal;
					index++;
					meshData.vertexData[index].color = recipe.color;
					meshData.vertexData[index].position = position2;
					meshData.vertexData[index].normal = normal;
					index++;
					meshData.vertexData[index].color = recipe.color;
					meshData.vertexData[index].position = position3;
					meshData.vertexData[index].normal = normal;
					index++;
				}
			}
		}

		meshData.vertexCount = index;

		// Indices
		index = 0;

		for (unsigned int latitude = 0; latitude < recipe.divisions; latitude++)
		{
			for (unsigned int longitude = 0; longitude < recipe.divisions; longitude++)
			{
				if (recipe.smooth)
				{
					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude + 1;

					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (recipe.divisions + 1) + longitude + 1;
					meshData.indexData[index++] = latitude * (recipe.divisions + 1) + longitude + 1;
				}
				else
				{
					unsigned int segmentIndex = (latitude * recipe.divisions + longitude) * 4;

					meshData.indexData[index++] = segmentIndex;
					meshData.indexData[index++] = segmentIndex + 1;
					meshData.indexData[index++] = segmentIndex + 2;

					meshData.indexData[index++] = segmentIndex;
					meshData.indexData[index++] = segmentIndex + 2;
					meshData.indexData[index++] = segmentIndex + 3;
				}
			}
		}

		meshData.indexCount = index;

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::createHeightMapMesh(const vector<vector<float>>& heightMap, unsigned int minX,
													   unsigned int maxX, unsigned int minZ, unsigned int maxZ,
													   shared_ptr<MeshBuffer> buffer, const Vector4& color)
	{
		unsigned int edgeLength = static_cast<unsigned int>(heightMap[0].size());
		unsigned int halfEdgeLength = static_cast<unsigned int>(floor(edgeLength / 2.0f));
		unsigned int width = maxX - minX;
		unsigned int depth = maxZ - minZ;
		unsigned int vertexCount = width * depth * 6;

		unique_ptr<Mesh> mesh = createMesh(vertexCount, vertexCount, buffer);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;

		for (unsigned int x = minX; x < maxX; x++)
		{
			for (unsigned int z = minZ; z < maxZ; z++)
			{
				unsigned int vertexIndex = ((x - minX) * width + (z - minZ)) * 6;

				Vector3 position0((float) x - halfEdgeLength, heightMap[x][z],
								  (float) z - halfEdgeLength);
				Vector3 position1((float) x - halfEdgeLength, heightMap[x][z + 1],
								  (float) z - halfEdgeLength + 1.0f);
				Vector3 position2((float) x - halfEdgeLength + 1.0f, heightMap[x + 1][z + 1],
								  (float) z - halfEdgeLength + 1.0f);
				Vector3 position3((float) x - halfEdgeLength + 1.0f, heightMap[x + 1][z],
								  (float) z - halfEdgeLength);

				Vector3 toPosition1 = position1 - position0;
				Vector3 toPosition2 = position2 - position0;

				insertTriangleVertices(meshData.vertexData, vertexIndex, position0, toPosition1, toPosition2, color);

				Vector3 toPosition3 = position3 - position0;

				insertTriangleVertices(meshData.vertexData, vertexIndex + 3, position0, toPosition2, toPosition3, color);
			}
		}

		// Indices
		if (mesh->getBuffer()->isIndexed())
		{
			meshData.indexCount = vertexCount;
			for (unsigned int index = 0; index < vertexCount; index++)
			{
				meshData.indexData[index] = index;
			}
		}

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::createMesh(unsigned int vertexCount, unsigned int indexCount,
											  shared_ptr<MeshBuffer> buffer)
	{
		if (buffer == nullptr)
		{
			buffer = createMeshBuffer(vertexCount, indexCount);
		}

		return unique_ptr<Mesh>(new Mesh(buffer));
	}

	shared_ptr<MeshBuffer> ModelFactory::createMeshBuffer(unsigned int vertexCount, unsigned int indexCount,
														  Buffer::AccessHint accessHint)
	{
		return instance->createMeshBufferInternal(vertexCount, indexCount, accessHint);
	}

	unique_ptr<Mesh> ModelFactory::createTriangleMesh(const Vector3& top, const Vector3& toBottomLeft,
													  const Vector3& toBottomRight, shared_ptr<MeshBuffer> buffer,
													  const Vector4& color, bool doubleSided)
	{
		unsigned int vertexCount = 3;
		unsigned int indexCount = 3;
		if (doubleSided)
		{
			indexCount *= 2;
		}

		unique_ptr<Mesh> mesh = createMesh(vertexCount, indexCount, buffer);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;

		insertTriangleVertices(meshData.vertexData, 0, top, toBottomLeft, toBottomRight, color);

		// Indices
		meshData.indexCount = indexCount;

		insertTriangleIndices(meshData.indexData, 0, 0);

		if (doubleSided)
		{
			insertTriangleIndices(meshData.indexData, 3, 0, true);
		}

		mesh->releaseData();

		return move(mesh);
	}

	Vector3 ModelFactory::getPointOnSphere(float radius, unsigned int divisions, unsigned int latitude,
										   unsigned int longitude)
	{
		float a = MathConstants::PI * latitude / divisions;
		float b = 2 * MathConstants::PI * longitude / divisions;

		return Vector3(sin(a) * cos(b) * radius, sin(a) * sin(b) * radius, cos(a) * radius);
	}

	void ModelFactory::insertCircleIndices(unsigned int* indices, unsigned int index, unsigned int vertexIndex,
										   unsigned int divisions, bool reverse)
	{
		for (unsigned int division = 0; division < divisions; division++)
		{
			unsigned int index1 = division + 1;
			unsigned int index2 = 0;
			if (division == divisions - 1)
			{
				index2 = 1;
			}
			else
			{
				index2 = division + 2;
			}

			if (reverse)
			{
				indices[index + division * 3] = vertexIndex;
				indices[index + division * 3 + 1] = vertexIndex + index1;
				indices[index + division * 3 + 2] = vertexIndex + index2;
			}
			else
			{
				indices[index + division * 3] = vertexIndex;
				indices[index + division * 3 + 1] = vertexIndex + index2;
				indices[index + division * 3 + 2] = vertexIndex + index1;
			}
		}
	}

	void ModelFactory::insertCircleVertices(Vertex* vertices, unsigned int index, float radius, unsigned int divisions,
											const Vector3& center, const Vector4& color)
	{
		Vector3 normal(0.0f, 0.0f, 1.0f);

		vertices[index].color = color;
		vertices[index].normal = normal;
		vertices[index].position = center;

		for (unsigned int division = 0; division < divisions; division++)
		{
			float toPosition = 2 * MathConstants::PI * division / divisions;
			Vector3 position(sin(toPosition), cos(toPosition), 0.0f);
			position *= radius;

			vertices[index + division + 1].color = color;
			vertices[index + division + 1].normal = normal;
			vertices[index + division + 1].position = center + position;
		}
	}

	void ModelFactory::insertRectangleIndices(unsigned int* indices, unsigned int index, unsigned int vertexIndex,
											  bool reverse)
	{
		if (reverse)
		{
			indices[index] = vertexIndex;
			indices[index + 1] = vertexIndex + 2;
			indices[index + 2] = vertexIndex + 1;
			indices[index + 3] = vertexIndex;
			indices[index + 4] = vertexIndex + 3;
			indices[index + 5] = vertexIndex + 2;
		}
		else
		{
			indices[index] = vertexIndex;
			indices[index + 1] = vertexIndex + 1;
			indices[index + 2] = vertexIndex + 2;
			indices[index + 3] = vertexIndex;
			indices[index + 4] = vertexIndex + 2;
			indices[index + 5] = vertexIndex + 3;
		}
	}

	void ModelFactory::insertRectangleVertices(Vertex* vertices, unsigned int index, const Vector3& topLeft,
											   const Vector3& toTopRight, const Vector3& toBottomLeft,
											   const Vector4& color)
	{
		Vector3 normal = crossProduct(toBottomLeft, toTopRight);
		normal.normalize();

		vertices[index].color = color;
		vertices[index].normal = normal;
		vertices[index].position = topLeft;
		vertices[index].texCoord = Vector2(0.0f, 0.0f);
		vertices[index + 1].color = color;
		vertices[index + 1].normal = normal;
		vertices[index + 1].position = topLeft + toBottomLeft;
		vertices[index + 1].texCoord = Vector2(0.0f, 1.0f);
		vertices[index + 2].color = color;
		vertices[index + 2].normal = normal;
		vertices[index + 2].position = topLeft + toTopRight + toBottomLeft;
		vertices[index + 2].texCoord = Vector2(1.0f, 1.0f);
		vertices[index + 3].color = color;
		vertices[index + 3].normal = normal;
		vertices[index + 3].position = topLeft + toTopRight;
		vertices[index + 3].texCoord = Vector2(1.0f, 0.0f);
	}

	void ModelFactory::insertTriangleIndices(unsigned int* indices, unsigned int index, unsigned int vertexIndex,
											 bool reverse)
	{
		if (reverse)
		{
			indices[index] = vertexIndex + 2;
			indices[index + 1] = vertexIndex + 1;
			indices[index + 2] = vertexIndex;
		}
		else
		{
			indices[index] = vertexIndex;
			indices[index + 1] = vertexIndex + 1;
			indices[index + 2] = vertexIndex + 2;
		}
	}

	void ModelFactory::insertTriangleVertices(Vertex* vertices, unsigned int index, const Vector3& top,
											  const Vector3& toBottomLeft, const Vector3& toBottomRight,
											  const Vector4& color)
	{
		Vector3 normal = crossProduct(toBottomRight, toBottomLeft);
		normal.normalize();

		Vector3 across = (top + toBottomRight) - (top + toBottomLeft);
		float scalarProjection = getScalarProjection(toBottomRight, across);
		float texWidthAtTop = scalarProjection / across.getMagnitude();
		Vector3 projection = across;
		projection.normalize();
		projection *= scalarProjection;
		Vector3 down = toBottomRight - projection;
		float texHeightAtBottom = down.getMagnitude() / across.getMagnitude();

		vertices[index].color = color;
		vertices[index].normal = normal;
		vertices[index].position = top;
		vertices[index].texCoord = Vector2(texWidthAtTop, 0.0f);
		vertices[index + 1].color = color;
		vertices[index + 1].normal = normal;
		vertices[index + 1].position = top + toBottomLeft;
		vertices[index + 1].texCoord = Vector2(0.0f, texHeightAtBottom);
		vertices[index + 2].color = color;
		vertices[index + 2].normal = normal;
		vertices[index + 2].position = top + toBottomRight;
		vertices[index + 2].texCoord = Vector2(1.0f, texHeightAtBottom);
	}

	void ModelFactory::insertTunnelIndices(unsigned int* indices, unsigned int index, unsigned int vertexIndex,
										   unsigned int divisions, bool reverse)
	{
		for (unsigned int division = 0; division < divisions; division++)
		{
			unsigned int indexOffset = index + division * 6;
			unsigned int vertexIndexOffset = vertexIndex + division * 4;

			if (reverse)
			{
				indices[indexOffset] = vertexIndexOffset + 1;
				indices[indexOffset + 1] = vertexIndexOffset + 2;
				indices[indexOffset + 2] = vertexIndexOffset;

				indices[indexOffset + 3] = vertexIndexOffset + 2;
				indices[indexOffset + 4] = vertexIndexOffset + 1;
				indices[indexOffset + 5] = vertexIndexOffset + 3;
			}
			else
			{
				indices[indexOffset] = vertexIndexOffset;
				indices[indexOffset + 1] = vertexIndexOffset + 2;
				indices[indexOffset + 2] = vertexIndexOffset + 1;

				indices[indexOffset + 3] = vertexIndexOffset + 3;
				indices[indexOffset + 4] = vertexIndexOffset + 1;
				indices[indexOffset + 5] = vertexIndexOffset + 2;
			}
		}
	}

	void ModelFactory::insertTunnelVertices(Vertex* vertices, unsigned int index, float radius, float length,
											unsigned int divisions, const Vector3& center, const Vector4& color,
											bool smooth)
	{
		Vector3 toEnd(0.0f, 0.0f, -length);

		for (unsigned int division = 0; division < divisions; division++)
		{
			float radiansToPositionA = 2 * MathConstants::PI * division / divisions;
			float radiansToPositionB = 2 * MathConstants::PI * (division + 1) / divisions;
			Vector3 positionA(sin(radiansToPositionA), cos(radiansToPositionA), 0.0f);
			Vector3 positionB(sin(radiansToPositionB), cos(radiansToPositionB), 0.0f);
			positionA *= radius;
			positionB *= radius;

			unsigned int indexOffset = index + division * 4;

			vertices[indexOffset].color = color;
			vertices[indexOffset].position = center + positionA;
			vertices[indexOffset + 1].color = color;
			vertices[indexOffset + 1].position = center + positionA + toEnd;
			vertices[indexOffset + 2].color = color;
			vertices[indexOffset + 2].position = center + positionB;
			vertices[indexOffset + 3].color = color;
			vertices[indexOffset + 3].position = center + positionB + toEnd;

			if (smooth)
			{
				vertices[indexOffset].normal = positionA;
				vertices[indexOffset].normal.normalize();
				vertices[indexOffset + 1].normal = positionA;
				vertices[indexOffset + 1].normal.normalize();
				vertices[indexOffset + 2].normal = positionB;
				vertices[indexOffset + 2].normal.normalize();
				vertices[indexOffset + 3].normal = positionB;
				vertices[indexOffset + 3].normal.normalize();
			}
			else
			{
				Vector3 edge0 = positionB - positionA;
				Vector3 edge1 = toEnd;
				Vector3 normal = crossProduct(edge0, edge1);

				vertices[indexOffset].normal = normal;
				vertices[indexOffset + 1].normal = normal;
				vertices[indexOffset + 2].normal = normal;
				vertices[indexOffset + 3].normal = normal;
			}
		}
	}

	unique_ptr<Mesh> ModelFactory::loadObj(Resource& resource, shared_ptr<MeshBuffer> buffer, const Vector4& color,
										   float scale)
	{
		return loadObj(resource, buffer, color, scale, 0, 0, 0, 0);
	}

	unique_ptr<Mesh> ModelFactory::loadObj(Resource& resource, shared_ptr<MeshBuffer> buffer, const Vector4& color,
										   float scale, unsigned int normalCount, unsigned int positionCount,
										   unsigned int texCoordCount, unsigned int vertexCount)
	{
		vector<Vertex> vertices;
		vertices.reserve(vertexCount);

		unique_ptr<istream> inputStream = resource.getInputStream();

		// This is constructed here and passed to splitString each time for performance reasons... should probably
		// profile this though.
		string split(MAX_SPLIT_LENGTH, ' ');

		vector<string> lines = splitString(split, *inputStream, '\n',
			normalCount + positionCount + texCoordCount + vertexCount / 3 + 50);

		vector<vector<string>> faces;
		faces.reserve(vertexCount / 3);
		vector<Vector3> normals;
		normals.reserve(normalCount);
		vector<Vector3> positions;
		positions.reserve(positionCount);
		vector<Vector2> texCoords;
		texCoords.reserve(texCoordCount);

		for (unsigned int lineIndex = 0; lineIndex < lines.size(); lineIndex++)
		{
			Logs::debug("simplicity", lines[lineIndex].c_str());

			if (lines[lineIndex].empty())
			{
				continue;
			}

			istringstream inputLineStream(lines[lineIndex]);
			vector<string> splitLine = splitString(split, inputLineStream, ' ', 4);

			Logs::debug("simplicity", "\"%s\"", splitLine[0].c_str());

			if (splitLine[0] == "v")
			{
				Vector3 position(
					(float) atof(splitLine[1].c_str()) * scale,
					(float) atof(splitLine[2].c_str()) * scale,
					(float) atof(splitLine[3].c_str()) * scale);
				positions.push_back(position);
			}
			else if (splitLine[0] == "vn")
			{
				Vector3 normal(
					(float) atof(splitLine[1].c_str()),
					(float) atof(splitLine[2].c_str()),
					(float) atof(splitLine[3].c_str()));
				normals.push_back(normal);
			}
			else if (splitLine[0] == "vt")
			{
				Vector2 texCoord(
					(float) atof(splitLine[1].c_str()),
					1.0f - (float) atof(splitLine[2].c_str()));
				texCoords.push_back(texCoord);
			}
			else if (splitLine[0] == "f")
			{
				faces.push_back(splitLine);
			}
		}

		// Read the faces from the file and populate the arrays.
		for (unsigned int faceIndex = 0; faceIndex < faces.size(); faceIndex++)
		{
			vector<string> face = faces[faceIndex];

			for (unsigned int vertexIndex = 1; vertexIndex < face.size() - 1; vertexIndex++)
			{
				istringstream inputFaceStream(face[vertexIndex]);
				vector<string> splitVertex = splitString(split, inputFaceStream, '/', 3);

				Vertex vertex;
				vertex.color = color;

				if (!normals.empty())
				{
					vertex.normal = normals[atoi(splitVertex[2].c_str()) - 1];
				}

				vertex.position = positions[atoi(splitVertex[0].c_str()) - 1];

				if (!texCoords.empty())
				{
					vertex.texCoord = texCoords[atoi(splitVertex[1].c_str()) - 1];
				}

				vertices.push_back(vertex);
			}

			// Create face normals if none were provided.
			if (normals.empty())
			{
				unsigned int vertexCount = static_cast<unsigned int>(vertices.size());

				Vector3 edge0 = vertices[vertexCount - 1].position - vertices[vertexCount - 2].position;
				Vector3 edge1 = vertices[vertexCount - 1].position - vertices[vertexCount - 3].position;
				Vector3 faceNormal = crossProduct(edge0, edge1);
				faceNormal.normalize();

				vertices[vertexCount - 1].normal = faceNormal;
				vertices[vertexCount - 2].normal = faceNormal;
				vertices[vertexCount - 3].normal = faceNormal;
			}
		}

		unique_ptr<Mesh> mesh = createMesh(static_cast<unsigned int>(vertices.size()), 0, buffer);
		MeshData& meshData = mesh->getData(false);

		meshData.vertexCount = static_cast<unsigned int>(vertices.size());
		memcpy(meshData.vertexData, vertices.data(), vertices.size());

		mesh->releaseData();

		return move(mesh);
	}

	void ModelFactory::setInstance(unique_ptr<ModelFactory> instance)
	{
		ModelFactory::instance = move(instance);
	}

	vector<string> ModelFactory::splitString(string& split, istream& source, char delimiter,
											 unsigned int estimatedSplitCount)
	{
		vector<string> splits;
		splits.reserve(estimatedSplitCount);

		while (!source.eof())
		{
			source.getline(&split[0], split.size(), delimiter);
			splits.push_back(split);
		}

		return splits;
	}
}
