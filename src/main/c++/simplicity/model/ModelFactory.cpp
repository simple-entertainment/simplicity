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

#include "../math/MathConstants.h"
#include "../math/MathFunctions.h"
#include "ModelFactory.h"

using namespace std;

// TODO All the doubleSided meshes have incorrect normals on the back side... they need to be reversed.
namespace simplicity
{
	vector<string> splitString(string& split, istream& source, char delimiter, unsigned int estimatedSplitCount);

	unique_ptr<ModelFactory> ModelFactory::instance = unique_ptr<ModelFactory>();

	const unsigned int MAX_SPLIT_LENGTH = 256;

	unique_ptr<Mesh> ModelFactory::createBoxMesh(const Vector3& halfExtents, shared_ptr<MeshBuffer> buffer,
			const Vector4& color, bool doubleSided)
	{
		unsigned int vertexCount = 24;
		unsigned int indexCount = 36;
		if (doubleSided)
		{
			indexCount *= 2;
		}

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;

		// Top
		insertRectangleVertices(meshData.vertexData, 0, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * -2.0f), color);

		// Bottom
		insertRectangleVertices(meshData.vertexData, 4, Vector3(-halfExtents.X(), -halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f), color);

		// North
		insertRectangleVertices(meshData.vertexData, 8, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * -2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// East
		insertRectangleVertices(meshData.vertexData, 12, Vector3(halfExtents.X(), halfExtents.Y(), -halfExtents.Z()),
			Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// South
		insertRectangleVertices(meshData.vertexData, 16, Vector3(-halfExtents.X(), halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// West
		insertRectangleVertices(meshData.vertexData, 20, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, 0.0f, halfExtents.Z() * -2.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// Indices
		meshData.indexCount = indexCount;

		insertRectangleIndices(meshData.indexData, 0, 0);
		insertRectangleIndices(meshData.indexData, 6, 4);
		insertRectangleIndices(meshData.indexData, 12, 8);
		insertRectangleIndices(meshData.indexData, 18, 12);
		insertRectangleIndices(meshData.indexData, 24, 16);
		insertRectangleIndices(meshData.indexData, 30, 20);

		if (doubleSided)
		{
			insertRectangleIndices(meshData.indexData, 36, 0, true);
			insertRectangleIndices(meshData.indexData, 42, 4, true);
			insertRectangleIndices(meshData.indexData, 48, 8, true);
			insertRectangleIndices(meshData.indexData, 54, 12, true);
			insertRectangleIndices(meshData.indexData, 60, 16, true);
			insertRectangleIndices(meshData.indexData, 66, 20, true);
		}

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::createCircleMesh(float radius, unsigned int divisions,
			shared_ptr<MeshBuffer> buffer, const Vector4& color)
	{
		unsigned int vertexCount = divisions + 1;
		unsigned int indexCount = divisions * 3;

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;
		insertCircleVertices(meshData.vertexData, 0, radius, divisions, Vector3(0.0f, 0.0f, 0.0f), color);

		// Indices
		meshData.indexCount = indexCount;
		insertCircleIndices(meshData.indexData, 0, 0, divisions);

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::createCubeMesh(float halfExtent, shared_ptr<MeshBuffer> buffer,
			const Vector4& color, bool doubleSided)
	{
		return createBoxMesh(Vector3(halfExtent, halfExtent, halfExtent), buffer, color, doubleSided);
	}

	unique_ptr<Mesh> ModelFactory::createCylinderMesh(float radius, float length, unsigned int divisions,
			shared_ptr<MeshBuffer> buffer, const Vector4& color, bool doubleSided, bool smooth)
	{
		unsigned int verticesInEnd = divisions + 1;
		unsigned int verticesInEnds = verticesInEnd * 2;
		unsigned int verticesInSide = 4;
		unsigned int verticesInSides = verticesInSide * divisions;
		unsigned int vertexCount = verticesInEnds + verticesInSides;

		unsigned int indicesInEnd = divisions * 3;
		unsigned int indicesInEnds = indicesInEnd * 2;
		unsigned int indicesInSide = 3 * 2;
		unsigned int indicesInSides = indicesInSide * divisions;
		unsigned int indexCount = indicesInEnds + indicesInSides;
		if (doubleSided)
		{
			indexCount *= 2;
		}

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
		MeshData& meshData = mesh->getData(false);

		Vector3 center(0.0f, 0.0f, 0.0f);
		Vector3 toBack(0.0f, 0.0f, -length);

		// Vertices
		meshData.vertexCount = vertexCount;

		// Front
		insertCircleVertices(meshData.vertexData, 0, radius, divisions, center, color);

		// Back
		insertCircleVertices(meshData.vertexData, verticesInEnd, radius, divisions, toBack, color);

		// Sides
		insertTunnelVertices(meshData.vertexData, verticesInEnds, radius, length, divisions, center, color, smooth);

		// Indices
		meshData.indexCount = indexCount;

		// Front
		insertCircleIndices(meshData.indexData, 0, 0, divisions);

		// Back
		insertCircleIndices(meshData.indexData, indicesInEnd, verticesInEnd, divisions, true);

		//Sides
		insertTunnelIndices(meshData.indexData, indicesInEnds, verticesInEnds, divisions);

		if (doubleSided)
		{
			// Front
			insertCircleIndices(meshData.indexData, indicesInEnds + indicesInSides, 0, divisions, true);

			// Back
			insertCircleIndices(meshData.indexData, indicesInEnds + indicesInSides + indicesInEnd, verticesInEnd, divisions);

			//Sides
			insertTunnelIndices(meshData.indexData, indicesInEnds + indicesInSides + indicesInEnds, verticesInEnds, divisions,
					true);
		}

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::createHeightMapMesh(const vector<vector<float>>& heightMap, unsigned int minX,
			unsigned int maxX, unsigned int minZ, unsigned int maxZ, shared_ptr<MeshBuffer> buffer,
			const Vector4& color)
	{
		unsigned int edgeLength = heightMap[0].size();
		unsigned int halfEdgeLength = static_cast<unsigned int>(floor(edgeLength / 2.0f));
		unsigned int width = maxX - minX;
		unsigned int depth = maxZ - minZ;
		unsigned int vertexCount = width * depth * 6;

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, vertexCount);
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

	unique_ptr<Mesh> ModelFactory::createHemisphereMesh(float radius, unsigned int divisions,
			shared_ptr<MeshBuffer> buffer, const Vector4& color, bool doubleSided)
	{
		unsigned int vertexCount = (divisions / 2 + 1) * (divisions + 1);
		unsigned int indexCount = (divisions / 2) * (divisions) * 6;
		if (doubleSided)
		{
			indexCount *= 2;
		}

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		unsigned int index = 0;

		for (unsigned int latitude = 0; latitude <= divisions / 2; latitude++)
		{
			for (unsigned int longitude = 0; longitude <= divisions; longitude++)
			{
				meshData.vertexData[index].color = color;
				meshData.vertexData[index].position = getPointOnSphere(radius, divisions, latitude, longitude);
				meshData.vertexData[index].normal = meshData.vertexData[index].position;
				meshData.vertexData[index].normal.normalize();
				index++;
			}
		}

		meshData.vertexCount = index;

		// Indices
		index = 0;

		for (unsigned int latitude = 0; latitude < divisions / 2; latitude++)
		{
			for (unsigned int longitude = 0; longitude < divisions; longitude++)
			{
				meshData.indexData[index++] = latitude * (divisions + 1) + longitude;
				meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude;
				meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude + 1;

				meshData.indexData[index++] = latitude * (divisions + 1) + longitude;
				meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude + 1;
				meshData.indexData[index++] = latitude * (divisions + 1) + longitude + 1;

				if (doubleSided)
				{
					meshData.indexData[index++] = latitude * (divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude + 1;
					meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude;

					meshData.indexData[index++] = latitude * (divisions + 1) + longitude;
					meshData.indexData[index++] = latitude * (divisions + 1) + longitude + 1;
					meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude + 1;
				}
			}
		}

		meshData.indexCount = index;

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::createMesh(shared_ptr<MeshBuffer> buffer, unsigned int vertexCount,
			unsigned int indexCount)
	{
		if (buffer == nullptr)
		{
			buffer = createMeshBuffer(vertexCount, indexCount);
		}

		return unique_ptr<Mesh>(new Mesh(buffer));
	}

	unique_ptr<Mesh> ModelFactory::createPrismMesh(const Vector3& halfExtents, shared_ptr<MeshBuffer> buffer,
			const Vector4& color)
	{
		unsigned int vertexCount = 18;
		unsigned int indexCount = 24;

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;
		Vector3 normal;

		// Bottom
		insertRectangleVertices(meshData.vertexData, 0, Vector3(-halfExtents.X(), -halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f), color);

		// North
		insertRectangleVertices(meshData.vertexData, 4, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * -2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// East
		insertTriangleVertices(meshData.vertexData, 8, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f),
			Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f), color);

		// South (slope)
		insertRectangleVertices(meshData.vertexData, 11, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f),
			Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f), color);

		// West
		insertTriangleVertices(meshData.vertexData, 15, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f),
			Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

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

	unique_ptr<Mesh> ModelFactory::createPyramidMesh(float halfBaseExtent, float height, shared_ptr<MeshBuffer> buffer,
			const Vector4& color)
	{
		unsigned int vertexCount = 16;
		unsigned int indexCount = 18;

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;

		// Bottom
		insertRectangleVertices(meshData.vertexData, 0, Vector3(-halfBaseExtent, -height * 0.5f, -halfBaseExtent),
			Vector3(halfBaseExtent * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfBaseExtent * 2.0f), color);

		// North
		insertTriangleVertices(meshData.vertexData, 4, Vector3(0.0f, height * 0.5f, 0.0f),
				Vector3(-halfBaseExtent, -height, halfBaseExtent), Vector3(halfBaseExtent, -height, halfBaseExtent),
				color);

		// East
		insertTriangleVertices(meshData.vertexData, 7, Vector3(0.0f, height * 0.5f, 0.0f),
				Vector3(halfBaseExtent, -height, halfBaseExtent), Vector3(halfBaseExtent, -height, -halfBaseExtent),
			color);

		// South
		insertTriangleVertices(meshData.vertexData, 10, Vector3(0.0f, height * 0.5f, 0.0f),
				Vector3(halfBaseExtent, -height, -halfBaseExtent), Vector3(-halfBaseExtent, -height, -halfBaseExtent),
			color);

		// West
		insertTriangleVertices(meshData.vertexData, 13, Vector3(0.0f, height * 0.5f, 0.0f),
				Vector3(-halfBaseExtent, -height, -halfBaseExtent), Vector3(-halfBaseExtent, -height, halfBaseExtent),
			color);

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

	unique_ptr<Mesh> ModelFactory::createSphereMesh(float radius, unsigned int divisions,
			shared_ptr<MeshBuffer> buffer, const Vector4& color, bool smooth)
	{
		unsigned int vertexCount = pow(divisions + 1, 2);
		unsigned int indexCount = pow(divisions, 2) * 6;
		if (!smooth)
		{
			vertexCount *= 4;
		}

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		unsigned int index = 0;

		for (unsigned int latitude = 0; latitude <= divisions; latitude++)
		{
			for (unsigned int longitude = 0; longitude <= divisions; longitude++)
			{
				if (smooth)
				{
					meshData.vertexData[index].color = color;
					meshData.vertexData[index].position = getPointOnSphere(radius, divisions, latitude, longitude);
					meshData.vertexData[index].normal = meshData.vertexData[index].position;
					meshData.vertexData[index].normal.normalize();
					index++;
				}
				else if (latitude != divisions && longitude != divisions)
				{
					Vector3 position0 = getPointOnSphere(radius, divisions, latitude, longitude);
					Vector3 position1 = getPointOnSphere(radius, divisions, latitude + 1, longitude);
					Vector3 position2 = getPointOnSphere(radius, divisions, latitude + 1, longitude + 1);
					Vector3 position3 = getPointOnSphere(radius, divisions, latitude, longitude + 1);

					Vector3 edge0 = position1 - position0;
					Vector3 edge1 = position2 - position0;
					if (latitude == divisions - 1)
					{
						edge1 = position3 - position0;
					}
					Vector3 normal = crossProduct(edge0, edge1);
					normal.normalize();

					meshData.vertexData[index].color = color;
					meshData.vertexData[index].position = position0;
					meshData.vertexData[index].normal = normal;
					index++;
					meshData.vertexData[index].color = color;
					meshData.vertexData[index].position = position1;
					meshData.vertexData[index].normal = normal;
					index++;
					meshData.vertexData[index].color = color;
					meshData.vertexData[index].position = position2;
					meshData.vertexData[index].normal = normal;
					index++;
					meshData.vertexData[index].color = color;
					meshData.vertexData[index].position = position3;
					meshData.vertexData[index].normal = normal;
					index++;
				}
			}
		}

		meshData.vertexCount = index;

		// Indices
		index = 0;

		for (unsigned int latitude = 0; latitude < divisions; latitude++)
		{
			for (unsigned int longitude = 0; longitude < divisions; longitude++)
			{
				if (smooth)
				{
					meshData.indexData[index++] = latitude * (divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude + 1;

					meshData.indexData[index++] = latitude * (divisions + 1) + longitude;
					meshData.indexData[index++] = (latitude + 1) * (divisions + 1) + longitude + 1;
					meshData.indexData[index++] = latitude * (divisions + 1) + longitude + 1;
				}
				else
				{
					unsigned int segmentIndex = (latitude * divisions + longitude) * 4;

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

	unique_ptr<Mesh> ModelFactory::createSquareMesh(float halfExtent, shared_ptr<MeshBuffer> buffer,
			const Vector4& color, bool doubleSided)
	{
		unsigned int vertexCount = 4;
		unsigned int indexCount = 6;
		if (doubleSided)
		{
			indexCount *= 2;
		}

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
		MeshData& meshData = mesh->getData(false);

		// Vertices
		meshData.vertexCount = vertexCount;

		insertRectangleVertices(meshData.vertexData, 0, Vector3(-halfExtent, halfExtent, 0.0f),
			Vector3(halfExtent * 2.0f, 0.0f, 0.0f), Vector3(0.0f, -halfExtent * 2.0f, 0.0f), color);

		// Indices
		meshData.indexCount = indexCount;

		insertRectangleIndices(meshData.indexData, 0, 0);

		if (doubleSided)
		{
			insertRectangleIndices(meshData.indexData, 6, 0, true);
		}

		mesh->releaseData();

		return move(mesh);
	}

	unique_ptr<Mesh> ModelFactory::createTriangleMesh(const Vector3& top, const Vector3& toBottomLeft,
			const Vector3& toBottomRight, shared_ptr<MeshBuffer> buffer, const Vector4& color, bool doubleSided)
	{
		unsigned int vertexCount = 3;
		unsigned int indexCount = 3;
		if (doubleSided)
		{
			indexCount *= 2;
		}

		unique_ptr<Mesh> mesh = createMesh(buffer, vertexCount, indexCount);
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

	ModelFactory* ModelFactory::getInstance()
	{
		return instance.get();
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
			indices[index] = vertexIndex + 2;
			indices[index + 1] = vertexIndex + 1;
			indices[index + 2] = vertexIndex;
			indices[index + 3] = vertexIndex;
			indices[index + 4] = vertexIndex + 3;
			indices[index + 5] = vertexIndex + 2;
		}
		else
		{
			indices[index] = vertexIndex;
			indices[index + 1] = vertexIndex + 1;
			indices[index + 2] = vertexIndex + 2;
			indices[index + 3] = vertexIndex + 2;
			indices[index + 4] = vertexIndex + 3;
			indices[index + 5] = vertexIndex;
		}
	}

	void ModelFactory::insertRectangleVertices(Vertex* vertices, unsigned int index, const Vector3& topLeft,
			const Vector3& toTopRight, const Vector3& toBottomLeft, const Vector4& color)
	{
		Vector3 normal = crossProduct(toTopRight, toBottomLeft);
		normal.normalize();

		float height = toBottomLeft.getMagnitude();
		float width = toTopRight.getMagnitude();

		float texHeight;
		float texWidth;
		if (height > width)
		{
			texHeight = height / width;
			texWidth = 1.0f;
		}
		else
		{
			texHeight = 1.0f;
			texWidth = width / height;
		}

		vertices[index].color = color;
		vertices[index].normal = normal;
		vertices[index].position = topLeft;
		vertices[index].texCoord = Vector2(0.0f, 0.0f);
		vertices[index + 1].color = color;
		vertices[index + 1].normal = normal;
		vertices[index + 1].position = topLeft + toBottomLeft;
		vertices[index + 1].texCoord = Vector2(0.0f, texHeight);
		vertices[index + 2].color = color;
		vertices[index + 2].normal = normal;
		vertices[index + 2].position = topLeft + toTopRight + toBottomLeft;
		vertices[index + 2].texCoord = Vector2(texWidth, texHeight);
		vertices[index + 3].color = color;
		vertices[index + 3].normal = normal;
		vertices[index + 3].position = topLeft + toTopRight;
		vertices[index + 3].texCoord = Vector2(texWidth, 0.0f);
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
			const Vector3& toBottomLeft, const Vector3& toBottomRight, const Vector4& color)
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
			unsigned int divisions, const Vector3& center, const Vector4& color, bool smooth)
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
			float scale, unsigned int normalCount, unsigned int positionCount, unsigned int texCoordCount,
			unsigned int vertexCount)
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
			if (lines[lineIndex].empty())
			{
				continue;
			}

			istringstream inputLineStream(lines[lineIndex]);
			vector<string> splitLine = splitString(split, inputLineStream, ' ', 4);

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
				unsigned int vertexCount = vertices.size();

				Vector3 edge0 = vertices[vertexCount - 1].position - vertices[vertexCount - 2].position;
				Vector3 edge1 = vertices[vertexCount - 1].position - vertices[vertexCount - 3].position;
				Vector3 faceNormal = crossProduct(edge0, edge1);
				faceNormal.normalize();

				vertices[vertexCount - 1].normal = faceNormal;
				vertices[vertexCount - 2].normal = faceNormal;
				vertices[vertexCount - 3].normal = faceNormal;
			}
		}

		unique_ptr<Mesh> mesh = createMesh(buffer, vertices.size(), 0);
		MeshData& meshData = mesh->getData(false);

		meshData.vertexCount = vertices.size();
		memcpy(meshData.vertexData, vertices.data(), vertices.size());

		mesh->releaseData();

		return move(mesh);
	}

	void ModelFactory::setInstance(unique_ptr<ModelFactory> instance)
	{
		ModelFactory::instance = move(instance);
	}

	vector<string> splitString(string& split, istream& source, char delimiter, unsigned int estimatedSplitCount)
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
