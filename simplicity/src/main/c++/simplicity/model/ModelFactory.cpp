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
#include "../math/MathConstants.h"
#include "../math/MathFunctions.h"
#include "ModelFactory.h"

using namespace std;

// TODO All the doubleSided meshes have incorrect normals on the back side... they need to be reversed.
namespace simplicity
{
	unique_ptr<ModelFactory> ModelFactory::instance = unique_ptr<ModelFactory>();

	unique_ptr<Mesh> ModelFactory::createBoxMesh(const Vector3& halfExtents, const Vector4& color, bool doubleSided)
	{
		// Vertices
		vector<Vertex> vertices(24);

		// Top
		insertRectangleVertices(vertices, 0, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * -2.0f), color);

		// Bottom
		insertRectangleVertices(vertices, 4, Vector3(-halfExtents.X(), -halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f), color);

		// North
		insertRectangleVertices(vertices, 8, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * -2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// East
		insertRectangleVertices(vertices, 12, Vector3(halfExtents.X(), halfExtents.Y(), -halfExtents.Z()),
			Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// South
		insertRectangleVertices(vertices, 16, Vector3(-halfExtents.X(), halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// West
		insertRectangleVertices(vertices, 20, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, 0.0f, halfExtents.Z() * -2.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// Indices
		vector<unsigned int> indices;
		if (doubleSided)
		{
			indices.resize(72);
		}
		else
		{
			indices.resize(36);
		}

		insertRectangleIndices(indices, 0, 0);
		insertRectangleIndices(indices, 6, 4);
		insertRectangleIndices(indices, 12, 8);
		insertRectangleIndices(indices, 18, 12);
		insertRectangleIndices(indices, 24, 16);
		insertRectangleIndices(indices, 30, 20);

		if (doubleSided)
		{
			insertRectangleIndices(indices, 36, 0, true);
			insertRectangleIndices(indices, 42, 4, true);
			insertRectangleIndices(indices, 48, 8, true);
			insertRectangleIndices(indices, 54, 12, true);
			insertRectangleIndices(indices, 60, 16, true);
			insertRectangleIndices(indices, 66, 20, true);
		}

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createCircleMesh(float radius, unsigned int divisions, const Vector4& color)
	{
		// Vertices
		vector<Vertex> vertices(divisions + 1);
		insertCircleVertices(vertices, 0, radius, divisions, Vector3(0.0f, 0.0f, 0.0f), color);

		// Indices
		vector<unsigned int> indices(divisions * 3);
		insertCircleIndices(indices, 0, 0, divisions);

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createCubeMesh(float halfExtent, const Vector4& color, bool doubleSided)
	{
		return createBoxMesh(Vector3(halfExtent, halfExtent, halfExtent), color, doubleSided);
	}

	unique_ptr<Mesh> ModelFactory::createCylinderMesh(float radius, float length, unsigned int divisions,
			const Vector4& color, bool doubleSided, bool smooth)
	{
		Vector3 center(0.0f, 0.0f, 0.0f);
		Vector3 toBack(0.0f, 0.0f, -length);

		// Vertices
		unsigned int verticesInEnd = divisions + 1;
		unsigned int verticesInEnds = verticesInEnd * 2;
		unsigned int verticesInSide = 4;
		unsigned int verticesInSides = verticesInSide * divisions;
		vector<Vertex> vertices(verticesInEnds + verticesInSides);

		// Front
		insertCircleVertices(vertices, 0, radius, divisions, center, color);

		// Back
		insertCircleVertices(vertices, verticesInEnd, radius, divisions, toBack, color);

		// Sides
		insertTunnelVertices(vertices, verticesInEnds, radius, length, divisions, center, color, smooth);

		// Indices
		unsigned int indicesInEnd = divisions * 3;
		unsigned int indicesInEnds = indicesInEnd * 2;
		unsigned int indicesInSide = 3 * 2;
		unsigned int indicesInSides = indicesInSide * divisions;
		vector<unsigned int> indices;
		if (doubleSided)
		{
			indices.resize((indicesInEnds + indicesInSides) * 2);
		}
		else
		{
			indices.resize(indicesInEnds + indicesInSides);
		}

		// Front
		insertCircleIndices(indices, 0, 0, divisions);

		// Back
		insertCircleIndices(indices, indicesInEnd, verticesInEnd, divisions, true);

		//Sides
		insertTunnelIndices(indices, indicesInEnds, verticesInEnds, divisions);

		if (doubleSided)
		{
			// Front
			insertCircleIndices(indices, indicesInEnds + indicesInSides, 0, divisions, true);

			// Back
			insertCircleIndices(indices, indicesInEnds + indicesInSides + indicesInEnd, verticesInEnd, divisions);

			//Sides
			insertTunnelIndices(indices, indicesInEnds + indicesInSides + indicesInEnds, verticesInEnds, divisions,
					true);
		}

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createHeightMapMesh(const vector<vector<float>>& heightMap, unsigned int minX,
			unsigned int maxX, unsigned int minZ, unsigned int maxZ, const Vector4& color)
	{
		unsigned int edgeLength = heightMap[0].size();
		unsigned int halfEdgeLength = static_cast<unsigned int>(floor(edgeLength / 2.0f));
		unsigned int width = maxX - minX;
		unsigned int depth = maxZ - minZ;

		// Vertices
		vector<Vertex> vertices(width * depth * 6);

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

				insertTriangleVertices(vertices, vertexIndex, position0, toPosition1, toPosition2, color);

				Vector3 toPosition3 = position3 - position0;

				insertTriangleVertices(vertices, vertexIndex + 3, position0, toPosition2, toPosition3, color);
			}
		}

		return createMesh(vertices);
	}

	unique_ptr<Mesh> ModelFactory::createHemisphereMesh(float radius, unsigned int divisions, const Vector4& color,
			bool doubleSided)
	{
		vector<Vertex> vertices;

		for (unsigned int latitude = 0; latitude <= divisions / 2; latitude++)
		{
			for (unsigned int longitude = 0; longitude <= divisions; longitude++)
			{
				Vertex vertex;
				vertex.color = color;
				vertex.position = getPointOnSphere(radius, divisions, latitude, longitude);
				Vector3 normal = vertex.position;
				normal.normalize();
				vertex.normal = normal;
				vertices.push_back(vertex);
			}
		}

		vector<unsigned int> indices;

		for (unsigned int latitude = 0; latitude < divisions / 2; latitude++)
		{
			for (unsigned int longitude = 0; longitude < divisions; longitude++)
			{
				indices.push_back(latitude * (divisions + 1) + longitude);
				indices.push_back((latitude + 1) * (divisions + 1) + longitude);
				indices.push_back((latitude + 1) * (divisions + 1) + longitude + 1);

				indices.push_back(latitude * (divisions + 1) + longitude);
				indices.push_back((latitude + 1) * (divisions + 1) + longitude + 1);
				indices.push_back(latitude * (divisions + 1) + longitude + 1);

				if (doubleSided)
				{
					indices.push_back(latitude * (divisions + 1) + longitude);
					indices.push_back((latitude + 1) * (divisions + 1) + longitude + 1);
					indices.push_back((latitude + 1) * (divisions + 1) + longitude);

					indices.push_back(latitude * (divisions + 1) + longitude);
					indices.push_back(latitude * (divisions + 1) + longitude + 1);
					indices.push_back((latitude + 1) * (divisions + 1) + longitude + 1);
				}
			}
		}

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createPrismMesh(const Vector3& halfExtents, const Vector4& color)
	{
		// Vertices
		vector<Vertex> vertices(18);
		Vector3 normal;

		// Bottom
		insertRectangleVertices(vertices, 0, Vector3(-halfExtents.X(), -halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f), color);

		// North
		insertRectangleVertices(vertices, 4, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * -2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// East
		insertTriangleVertices(vertices, 8, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f),
			Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f), color);

		// South (slope)
		insertRectangleVertices(vertices, 11, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f),
			Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f), color);

		// West
		insertTriangleVertices(vertices, 15, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f),
			Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), color);

		// Indices
		vector<unsigned int> indices(24);

		insertRectangleIndices(indices, 0, 0);
		insertRectangleIndices(indices, 6, 4);
		insertTriangleIndices(indices, 12, 8);
		insertRectangleIndices(indices, 15, 11);
		insertTriangleIndices(indices, 21, 15);

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createPyramidMesh(float halfBaseExtent, float height, const Vector4& color)
	{
		// Vertices
		vector<Vertex> vertices(16);

		// Bottom
		insertRectangleVertices(vertices, 0, Vector3(-halfBaseExtent, -height * 0.5f, -halfBaseExtent),
			Vector3(halfBaseExtent * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfBaseExtent * 2.0f), color);

		// North
		insertTriangleVertices(vertices, 4, Vector3(0.0f, height * 0.5f, 0.0f),
				Vector3(-halfBaseExtent, -height, halfBaseExtent), Vector3(halfBaseExtent, -height, halfBaseExtent),
				color);

		// East
		insertTriangleVertices(vertices, 7, Vector3(0.0f, height * 0.5f, 0.0f),
				Vector3(halfBaseExtent, -height, halfBaseExtent), Vector3(halfBaseExtent, -height, -halfBaseExtent),
			color);

		// South
		insertTriangleVertices(vertices, 10, Vector3(0.0f, height * 0.5f, 0.0f),
				Vector3(halfBaseExtent, -height, -halfBaseExtent), Vector3(-halfBaseExtent, -height, -halfBaseExtent),
			color);

		// West
		insertTriangleVertices(vertices, 13, Vector3(0.0f, height * 0.5f, 0.0f),
				Vector3(-halfBaseExtent, -height, -halfBaseExtent), Vector3(-halfBaseExtent, -height, halfBaseExtent),
			color);

		// Indices
		vector<unsigned int> indices(18);

		insertRectangleIndices(indices, 0, 0);
		insertTriangleIndices(indices, 6, 4);
		insertTriangleIndices(indices, 9, 7);
		insertTriangleIndices(indices, 12, 10);
		insertTriangleIndices(indices, 15, 13);

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createSphereMesh(float radius, unsigned int divisions, const Vector4& color,
			bool smooth)
	{
		vector<Vertex> vertices;

		for (unsigned int latitude = 0; latitude <= divisions; latitude++)
		{
			for (unsigned int longitude = 0; longitude <= divisions; longitude++)
			{
				if (smooth)
				{
					Vertex vertex;
					vertex.color = color;
					vertex.position = getPointOnSphere(radius, divisions, latitude, longitude);
					Vector3 normal = vertex.position;
					normal.normalize();
					vertex.normal = normal;
					vertices.push_back(vertex);
				}
				else if (latitude != divisions && longitude != divisions)
				{
					Vertex vertex0;
					vertex0.color = color;
					vertex0.position = getPointOnSphere(radius, divisions, latitude, longitude);
					Vertex vertex1;
					vertex1.color = color;
					vertex1.position = getPointOnSphere(radius, divisions, latitude + 1, longitude);
					Vertex vertex2;
					vertex2.color = color;
					vertex2.position = getPointOnSphere(radius, divisions, latitude + 1, longitude + 1);
					Vertex vertex3;
					vertex3.color = color;
					vertex3.position = getPointOnSphere(radius, divisions, latitude, longitude + 1);

					Vector3 edge0 = vertex1.position - vertex0.position;
					Vector3 edge1 = vertex2.position - vertex0.position;
					if (latitude == divisions - 1)
					{
						edge1 = vertex3.position - vertex0.position;
					}
					Vector3 normal = crossProduct(edge0, edge1);
					normal.normalize();

					vertex0.normal = normal;
					vertex1.normal = normal;
					vertex2.normal = normal;
					vertex3.normal = normal;

					vertices.push_back(vertex0);
					vertices.push_back(vertex1);
					vertices.push_back(vertex2);
					vertices.push_back(vertex3);
				}
			}
		}

		vector<unsigned int> indices;

		for (unsigned int latitude = 0; latitude < divisions; latitude++)
		{
			for (unsigned int longitude = 0; longitude < divisions; longitude++)
			{
				if (smooth)
				{
					indices.push_back(latitude * (divisions + 1) + longitude);
					indices.push_back((latitude + 1) * (divisions + 1) + longitude);
					indices.push_back((latitude + 1) * (divisions + 1) + longitude + 1);

					indices.push_back(latitude * (divisions + 1) + longitude);
					indices.push_back((latitude + 1) * (divisions + 1) + longitude + 1);
					indices.push_back(latitude * (divisions + 1) + longitude + 1);
				}
				else
				{
					unsigned int segmentIndex = (latitude * divisions + longitude) * 4;

					indices.push_back(segmentIndex);
					indices.push_back(segmentIndex + 1);
					indices.push_back(segmentIndex + 2);

					indices.push_back(segmentIndex);
					indices.push_back(segmentIndex + 2);
					indices.push_back(segmentIndex + 3);
				}
			}
		}

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createSquareMesh(float halfExtent, const Vector4& color, bool doubleSided)
	{
		// Vertices
		vector<Vertex> vertices(4);

		insertRectangleVertices(vertices, 0, Vector3(-halfExtent, halfExtent, 0.0f),
			Vector3(halfExtent * 2.0f, 0.0f, 0.0f), Vector3(0.0f, -halfExtent * 2.0f, 0.0f), color);

		// Indices
		vector<unsigned int> indices;
		if (doubleSided)
		{
			indices.resize(12);
			insertRectangleIndices(indices, 0, 0);
			insertRectangleIndices(indices, 6, 0, true);
		}
		else
		{
			indices.resize(6);
			insertRectangleIndices(indices, 0, 0);
		}

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createTriangleMesh(const Vector3& top, const Vector3& toBottomLeft,
			const Vector3& toBottomRight, const Vector4& color, bool doubleSided)
	{
		// Vertices
		vector<Vertex> vertices(3);

		insertTriangleVertices(vertices, 0, top, toBottomLeft, toBottomRight, color);

		// Indices
		vector<unsigned int> indices;
		if (doubleSided)
		{
			indices.resize(6);
			insertTriangleIndices(indices, 0, 0);
			insertTriangleIndices(indices, 3, 0, true);
		}
		else
		{
			indices.resize(3);
			insertTriangleIndices(indices, 0, 0);
		}

		return createMesh(vertices, indices);
	}

	ModelFactory& ModelFactory::getInstance()
	{
		return *instance;
	}

	Vector3 ModelFactory::getPointOnSphere(float radius, unsigned int divisions, unsigned int latitude,
			unsigned int longitude)
	{
		float a = MathConstants::PI * latitude / divisions;
		float b = 2 * MathConstants::PI * longitude / divisions;

		return Vector3(sin(a) * cos(b) * radius, sin(a) * sin(b) * radius, cos(a) * radius);
	}

	void ModelFactory::insertCircleIndices(std::vector<unsigned int>& indices, unsigned int index,
			unsigned int vertexIndex, unsigned int divisions, bool reverse)
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

	void ModelFactory::insertCircleVertices(std::vector<Vertex>& vertices, unsigned int index, float radius,
			unsigned int divisions, const Vector3& center, const Vector4& color)
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

	void ModelFactory::insertRectangleIndices(vector<unsigned int>& indices, unsigned int index,
		unsigned int vertexIndex, bool reverse)
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

	void ModelFactory::insertRectangleVertices(vector<Vertex>& vertices, unsigned int index, const Vector3& topLeft,
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
		vertices[index].texCoord = Vector2(texWidth, 0.0f);
		vertices[index + 1].color = color;
		vertices[index + 1].normal = normal;
		vertices[index + 1].position = topLeft + toTopRight;
		vertices[index + 1].texCoord = Vector2(0.0f, 0.0f);
		vertices[index + 2].color = color;
		vertices[index + 2].normal = normal;
		vertices[index + 2].position = topLeft + toTopRight + toBottomLeft;
		vertices[index + 2].texCoord = Vector2(0.0f, texHeight);
		vertices[index + 3].color = color;
		vertices[index + 3].normal = normal;
		vertices[index + 3].position = topLeft + toBottomLeft;
		vertices[index + 3].texCoord = Vector2(texWidth, texHeight);
	}

	void ModelFactory::insertTriangleIndices(std::vector<unsigned int>& indices, unsigned int index,
		unsigned int vertexIndex, bool reverse)
	{
		if (reverse)
		{
			indices[index] = vertexIndex;
			indices[index + 1] = vertexIndex + 2;
			indices[index + 2] = vertexIndex + 1;
		}
		else
		{
			indices[index] = vertexIndex;
			indices[index + 1] = vertexIndex + 1;
			indices[index + 2] = vertexIndex + 2;
		}
	}

	void ModelFactory::insertTriangleVertices(std::vector<Vertex>& vertices, unsigned int index, const Vector3& top,
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
		vertices[index + 1].texCoord = Vector2(1.0f, texHeightAtBottom);
		vertices[index + 2].color = color;
		vertices[index + 2].normal = normal;
		vertices[index + 2].position = top + toBottomRight;
		vertices[index + 2].texCoord = Vector2(0.0f, texHeightAtBottom);
	}

	void ModelFactory::insertTunnelIndices(std::vector<unsigned int>& indices, unsigned int index,
			unsigned int vertexIndex, unsigned int divisions, bool reverse)
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

	void ModelFactory::insertTunnelVertices(std::vector<Vertex>& vertices, unsigned int index, float radius,
			float length, unsigned int divisions, const Vector3& center, const Vector4& color, bool smooth)
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

	void ModelFactory::setInstance(unique_ptr<ModelFactory> instance)
	{
		ModelFactory::instance = move(instance);
	}
}
