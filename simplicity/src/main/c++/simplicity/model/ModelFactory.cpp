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
#include "../math/MathFunctions.h"
#include "ModelFactory.h"

using namespace std;

namespace simplicity
{
	unique_ptr<ModelFactory> ModelFactory::instance = unique_ptr<ModelFactory>();

	void ModelFactory::addRectangleIndexList(vector<unsigned int>& indices, unsigned int index,
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

	void ModelFactory::addRectangleVertexList(vector<Vertex>& vertices, unsigned int index, const Vector4& colour,
		const Vector3& topLeft, const Vector3& toTopRight, const Vector3& toBottomLeft)
	{
		Vector3 normal = MathFunctions::crossProduct(toTopRight, toBottomLeft);
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

		vertices[index].color = colour;
		vertices[index].normal = normal;
		vertices[index].position = topLeft;
		vertices[index].texCoord = Vector2(texWidth, 0.0f);
		vertices[index + 1].color = colour;
		vertices[index + 1].normal = normal;
		vertices[index + 1].position = topLeft + toTopRight;
		vertices[index + 1].texCoord = Vector2(0.0f, 0.0f);
		vertices[index + 2].color = colour;
		vertices[index + 2].normal = normal;
		vertices[index + 2].position = topLeft + toTopRight + toBottomLeft;
		vertices[index + 2].texCoord = Vector2(0.0f, texHeight);
		vertices[index + 3].color = colour;
		vertices[index + 3].normal = normal;
		vertices[index + 3].position = topLeft + toBottomLeft;
		vertices[index + 3].texCoord = Vector2(texWidth, texHeight);
	}

	void ModelFactory::addTriangleIndexList(std::vector<unsigned int>& indices, unsigned int index,
		unsigned int vertexIndex, bool reverse)
	{
		if (reverse)
		{
			indices[index] = vertexIndex;
			indices[index + 1] = vertexIndex + 1;
			indices[index + 2] = vertexIndex + 2;
		}
		else
		{
			indices[index] = vertexIndex + 2;
			indices[index + 1] = vertexIndex + 1;
			indices[index + 2] = vertexIndex;
		}
	}

	void ModelFactory::addTriangleVertexList(std::vector<Vertex>& vertices, unsigned int index, const Vector4& colour,
		const Vector3& top, const Vector3& toBottomLeft, const Vector3& toBottomRight)
	{
		Vector3 normal = MathFunctions::crossProduct(toBottomRight, toBottomLeft);
		normal.normalize();

		Vector3 across = (top + toBottomRight) - (top + toBottomLeft);
		float scalarProjection = MathFunctions::getScalarProjection(toBottomRight, across);
		float texWidthAtTop = scalarProjection / across.getMagnitude();
		Vector3 projection = across;
		projection.normalize();
		projection *= scalarProjection;
		Vector3 down = toBottomRight - projection;
		float texHeightAtBottom = down.getMagnitude() / across.getMagnitude();

		vertices[index].color = colour;
		vertices[index].normal = normal;
		vertices[index].position = top;
		vertices[index].texCoord = Vector2(texWidthAtTop, 0.0f);
		vertices[index + 1].color = colour;
		vertices[index + 1].normal = normal;
		vertices[index + 1].position = top + toBottomLeft;
		vertices[index + 1].texCoord = Vector2(1.0f, texHeightAtBottom);
		vertices[index + 2].color = colour;
		vertices[index + 2].normal = normal;
		vertices[index + 2].position = top + toBottomRight;
		vertices[index + 2].texCoord = Vector2(0.0f, texHeightAtBottom);
	}

	void ModelFactory::colorizeVertices(vector<Vertex>& vertices, const Vector4& color)
	{
		for (unsigned int index = 0; index < vertices.size(); index++)
		{
			vertices[index].color = color;
		}
	}

	unique_ptr<Mesh> ModelFactory::createBoxMesh(const Vector3& halfExtents, const Vector4& color, bool doubleSided)
	{
		// Vertices
		vector<Vertex> vertices(24);

		// Top
		addRectangleVertexList(vertices, 0, color, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * -2.0f));

		// Bottom
		addRectangleVertexList(vertices, 4, color, Vector3(-halfExtents.X(), -halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f));

		// North
		addRectangleVertexList(vertices, 8, color, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * -2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f));

		// East
		addRectangleVertexList(vertices, 12, color, Vector3(halfExtents.X(), halfExtents.Y(), -halfExtents.Z()),
			Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f));

		// South
		addRectangleVertexList(vertices, 16, color, Vector3(-halfExtents.X(), halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f));

		// West
		addRectangleVertexList(vertices, 20, color, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, 0.0f, halfExtents.Z() * -2.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f));

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

		addRectangleIndexList(indices, 0, 0);
		addRectangleIndexList(indices, 6, 4);
		addRectangleIndexList(indices, 12, 8);
		addRectangleIndexList(indices, 18, 12);
		addRectangleIndexList(indices, 24, 16);
		addRectangleIndexList(indices, 30, 20);

		if (doubleSided)
		{
			addRectangleIndexList(indices, 36, 0, true);
			addRectangleIndexList(indices, 42, 4, true);
			addRectangleIndexList(indices, 48, 8, true);
			addRectangleIndexList(indices, 54, 12, true);
			addRectangleIndexList(indices, 60, 16, true);
			addRectangleIndexList(indices, 66, 20, true);
		}

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createCubeMesh(float halfExtent, const Vector4& color, bool doubleSided)
	{
		return createBoxMesh(Vector3(halfExtent, halfExtent, halfExtent), color, doubleSided);
	}

	unique_ptr<Mesh> ModelFactory::createHeightMapMesh(const vector<vector<float>>& heightMap, const Vector4& color)
	{
		unsigned int edgeLength = heightMap[0].size();
		unsigned int halfEdgeLength = edgeLength / 2;

		// Vertices
		vector<Vertex> vertices(pow(edgeLength - 1, 2) * 6);

		for (unsigned int x = 0; x < edgeLength - 1; x++)
		{
			for (unsigned int z = 0; z < edgeLength - 1; z++)
			{
				Vector3 position0((float) x - halfEdgeLength, heightMap[x][z],
						(float) z - halfEdgeLength);
				Vector3 position1((float) x - halfEdgeLength, heightMap[x][z + 1],
						(float) z - halfEdgeLength + 1.0f);
				Vector3 position2((float) x - halfEdgeLength + 1.0f, heightMap[x + 1][z + 1],
						(float) z - halfEdgeLength + 1.0f);
				Vector3 position3((float) x - halfEdgeLength + 1.0f, heightMap[x + 1][z],
						(float) z - halfEdgeLength);

				Vector3 edge0 = position1 - position0;
				edge0.normalize();
				Vector3 edge1 = position2 - position0;
				edge1.normalize();
				Vector3 normal = MathFunctions::crossProduct(edge0, edge1);

				Vertex vertex0;
				vertex0.color = color;
				vertex0.normal = normal;
				vertex0.position = position0;
				vertices.push_back(vertex0);

				Vertex vertex1;
				vertex1.color = color;
				vertex1.normal = normal;
				vertex1.position = position1;
				vertices.push_back(vertex1);

				Vertex vertex2;
				vertex2.color = color;
				vertex2.normal = normal;
				vertex2.position = position2;
				vertices.push_back(vertex2);

				Vertex vertex3;
				vertex3.color = color;
				vertex3.normal = normal;
				vertex3.position = position0;
				vertices.push_back(vertex3);

				Vertex vertex4;
				vertex4.color = color;
				vertex4.normal = normal;
				vertex4.position = position2;
				vertices.push_back(vertex4);

				Vertex vertex5;
				vertex5.color = color;
				vertex5.normal = normal;
				vertex5.position = position3;
				vertices.push_back(vertex5);
			}
		}

		return createMesh(vertices);
	}

	unique_ptr<Mesh> ModelFactory::createPrismMesh(const Vector3& halfExtents, const Vector4& color)
	{
		// Vertices
		vector<Vertex> vertices(18);
		Vector3 normal;

		// Bottom
		addRectangleVertexList(vertices, 0, color, Vector3(-halfExtents.X(), -halfExtents.Y(), -halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfExtents.Z() * 2.0f));

		// North
		addRectangleVertexList(vertices, 4, color, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * -2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f));

		// East
		addTriangleVertexList(vertices, 8, color, Vector3(halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f));

		// South (slope)
		addRectangleVertexList(vertices, 11, color, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(halfExtents.X() * 2.0f, 0.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f));

		// West
		addTriangleVertexList(vertices, 15, color, Vector3(-halfExtents.X(), halfExtents.Y(), halfExtents.Z()),
			Vector3(0.0f, halfExtents.Y() * -2.0f, 0.0f), Vector3(0.0f, halfExtents.Y() * -2.0f, halfExtents.Z() * -2.0f));

		// Indices
		vector<unsigned int> indices(24);

		addRectangleIndexList(indices, 0, 0);
		addRectangleIndexList(indices, 6, 4);
		addTriangleIndexList(indices, 12, 8);
		addRectangleIndexList(indices, 15, 11);
		addTriangleIndexList(indices, 21, 15);

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createPyramidMesh(float halfBaseExtent, float height, const Vector4& color)
	{
		// Vertices
		vector<Vertex> vertices(16);

		// Bottom
		addRectangleVertexList(vertices, 0, color, Vector3(-halfBaseExtent, 0.0f, -halfBaseExtent),
			Vector3(halfBaseExtent * 2.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, halfBaseExtent * 2.0f));

		// North
		addTriangleVertexList(vertices, 4, color, Vector3(0.0f, height, 0.0f),
			Vector3(halfBaseExtent, -height, halfBaseExtent), Vector3(-halfBaseExtent, -height, halfBaseExtent));

		// East
		addTriangleVertexList(vertices, 7, color, Vector3(0.0f, height, 0.0f),
			Vector3(halfBaseExtent, -height, -halfBaseExtent), Vector3(halfBaseExtent, -height, halfBaseExtent));

		// South
		addTriangleVertexList(vertices, 10, color, Vector3(0.0f, height, 0.0f),
			Vector3(-halfBaseExtent, -height, -halfBaseExtent), Vector3(halfBaseExtent, -height, -halfBaseExtent));

		// West
		addTriangleVertexList(vertices, 13, color, Vector3(0.0f, height, 0.0f),
			Vector3(-halfBaseExtent, -height, halfBaseExtent), Vector3(-halfBaseExtent, -height, -halfBaseExtent));

		// Indices
		vector<unsigned int> indices(18);

		addRectangleIndexList(indices, 0, 0);
		addTriangleIndexList(indices, 6, 4);
		addTriangleIndexList(indices, 9, 7);
		addTriangleIndexList(indices, 12, 10);
		addTriangleIndexList(indices, 15, 13);

		return createMesh(vertices, indices);
	}

	unique_ptr<Mesh> ModelFactory::createSquareMesh(float halfExtent, const Vector4& color, bool doubleSided)
	{
		// Vertices
		vector<Vertex> vertices(4);

		addRectangleVertexList(vertices, 0, color, Vector3(-halfExtent, halfExtent, 0.0f),
			Vector3(halfExtent * 2.0f, 0.0f, 0.0f), Vector3(0.0f, -halfExtent * 2.0f, 0.0f));

		// Indices
		vector<unsigned int> indices;
		if (doubleSided)
		{
			indices.resize(12);
			addRectangleIndexList(indices, 0, 0);
			addRectangleIndexList(indices, 6, 0, true);
		}
		else
		{
			indices.resize(6);
			addRectangleIndexList(indices, 0, 0);
		}

		return createMesh(vertices, indices);
	}

	ModelFactory& ModelFactory::getInstance()
	{
		return *instance;
	}

	void ModelFactory::scaleVertices(vector<Vertex>& vertices, float scale)
	{
		for (unsigned int index = 0; index < vertices.size(); index++)
		{
			vertices[index].position *= scale;
		}
	}

	void ModelFactory::setInstance(unique_ptr<ModelFactory> instance)
	{
		ModelFactory::instance = move(instance);
	}
}
