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
#include <map>

#include "../Categories.h"
#include "../math/Intersection.h"
#include "../math/MathFunctions.h"
#include "ModelFactory.h"
#include "ModelFunctions.h"

namespace simplicity
{
	namespace ModelFunctions
	{
		void colorizeVertices(vector<Vertex>& vertices, const Vector4& color)
		{
			for (Vertex& vertex : vertices)
			{
				vertex.color = color;
			}
		}

		unique_ptr<Circle> getCircleBoundsXZ(const std::vector<Vertex>& vertices)
		{
			Vector3 center(0.0f, 0.0f, 0.0f);
			float maxMagnitudeSquared = 0.0f;

			for (const Vertex& vertex : vertices)
			{
				center += vertex.position;
			}
			center /= vertices.size();

			for (const Vertex& vertex : vertices)
			{
				float magnitudeSquared = (vertex.position - center).getMagnitudeSquared();
				if (magnitudeSquared > maxMagnitudeSquared)
				{
					maxMagnitudeSquared = magnitudeSquared;
				}
			}

			unique_ptr<Circle> bounds(new Circle(sqrt(maxMagnitudeSquared)));
			bounds->setCategory(Categories::BOUNDS);
			setPosition(bounds->getTransform(), Vector3(center.X(), 0.0f, center.Z()));

			return move(bounds);
		}

		unique_ptr<Square> getSquareBoundsXZ(const std::vector<Vertex>& vertices)
		{
			float minX = 1000000.0f;
			float maxX = -1000000.0f;
			float minZ = 1000000.0f;
			float maxZ = -1000000.0f;

			for (const Vertex& vertex : vertices)
			{
				if (vertex.position.X() < minX)
				{
					minX = vertex.position.X();
				}
				if (vertex.position.X() > maxX)
				{
					maxX = vertex.position.X();
				}
				if (vertex.position.Z() < minZ)
				{
					minZ = vertex.position.Z();
				}
				if (vertex.position.Z() > maxZ)
				{
					maxZ = vertex.position.Z();
				}
			}

			float halfRangeX = (maxX - minX) / 2.0f;
			float centerX = maxX - halfRangeX;
			float halfRangeZ = (maxZ - minZ) / 2.0f;
			float centerZ = maxZ - halfRangeZ;

			unique_ptr<Square> bounds(new Square(max(halfRangeX, halfRangeZ)));
			bounds->setCategory(Categories::BOUNDS);
			setPosition(bounds->getTransform(), Vector3(centerX, 0.0f, centerZ));

			return move(bounds);
		}

		void rotateVertices(vector<Vertex>& vertices, float angle, const Vector3& axis)
		{
			Matrix33 rotationMatrix;
			rotationMatrix.setIdentity();
			rotate(rotationMatrix, angle, axis);

			for (Vertex& vertex : vertices)
			{
				vertex.position = rotationMatrix * vertex.position;
			}
		}

		void scaleVertices(vector<Vertex>& vertices, float scale)
		{
			for (Vertex& vertex : vertices)
			{
				vertex.position *= scale;
			}
		}

		unique_ptr<Mesh> subtract(const Mesh& lhs, const Mesh& rhs, const Matrix44& relativeTransform)
		{
			const vector<Vertex> lhsVertices = lhs.getVertices();
			const vector<unsigned int> lhsIndices = lhs.getIndices();
			const vector<Vertex> rhsVertices = rhs.getVertices();
			const vector<unsigned int> rhsIndices = rhs.getIndices();
			vector<Vertex> newVertices = lhsVertices;
			vector<unsigned int> newIndices;

			Matrix44 inverseRelativeTransform = relativeTransform;
			inverseRelativeTransform.invert();

			for (unsigned int lhsIndex = 0; lhsIndex < lhsIndices.size(); lhsIndex += 3)
			{
				Triangle lhsTriangle(lhsVertices[lhsIndices[lhsIndex]].position,
						lhsVertices[lhsIndices[lhsIndex + 1]].position,
						lhsVertices[lhsIndices[lhsIndex + 2]].position);

				// If the lhs triangle is contained within the rhs mesh, remove it.
				if (Intersection::contains(rhs, Point(lhsTriangle.getPointA()), inverseRelativeTransform))
				{
					if (Intersection::contains(rhs, Point(lhsTriangle.getPointB()), inverseRelativeTransform))
					{
						if (Intersection::contains(rhs, Point(lhsTriangle.getPointC()), inverseRelativeTransform))
						{
							// Not adding any indices...
							continue;
						}
					}
				}

				Vector3 lhsEdge0 = lhsTriangle.getPointB() - lhsTriangle.getPointA();
				Vector3 lhsEdge1 = lhsTriangle.getPointC() - lhsTriangle.getPointB();
				Vector3 lhsEdge2 = lhsTriangle.getPointA() - lhsTriangle.getPointC();
				Vector3 lhsNormal = crossProduct(lhsEdge0, lhsEdge1);
				lhsNormal.normalize();

				/*
				 * These 'out' vectors are vectors on the triangle's plane perpendicular to the edges of the triangle
				 * and in the direction that is 'outward' from the triangle.
				 */
				Vector3 lhsEdge0Out = crossProduct(lhsEdge0, lhsNormal);
				lhsEdge0Out.normalize();
				Vector3 lhsEdge1Out = crossProduct(lhsEdge1, lhsNormal);
				lhsEdge1Out.normalize();
				Vector3 lhsEdge2Out = crossProduct(lhsEdge2, lhsNormal);
				lhsEdge2Out.normalize();

				Vector3 lhsPointA((Vector4(lhsTriangle.getPointA(), 1.0f) * inverseRelativeTransform).getData());
				Vector3 lhsPointB((Vector4(lhsTriangle.getPointB(), 1.0f) * inverseRelativeTransform).getData());
				Vector3 lhsPointC((Vector4(lhsTriangle.getPointC(), 1.0f) * inverseRelativeTransform).getData());
				Triangle relativeLhsTriangle(lhsPointA, lhsPointB, lhsPointC);

				// Retrieve the lines of intersection with the lhs triangle.
				vector<Line> intersections[3];
				for (unsigned int rhsIndex = 0; rhsIndex < rhsIndices.size(); rhsIndex += 3)
				{
					Triangle rhsTriangle(rhsVertices[rhsIndices[rhsIndex]].position,
							rhsVertices[rhsIndices[rhsIndex + 1]].position,
							rhsVertices[rhsIndices[rhsIndex + 2]].position);

					Vector3 rhsEdge0 = rhsTriangle.getPointB() - rhsTriangle.getPointA();
					Vector3 rhsEdge1 = rhsTriangle.getPointC() - rhsTriangle.getPointA();
					Vector3 rhsNormal = crossProduct(rhsEdge0, rhsEdge1);
					rhsNormal.normalize();

					if (Intersection::intersect(rhsTriangle, relativeLhsTriangle, rhsNormal, lhsNormal))
					{
						Line intersection =
								Intersection::getIntersection(rhsTriangle, relativeLhsTriangle, rhsNormal, lhsNormal);

						float dotEdge0Out = dotProduct(rhsNormal, lhsEdge0Out);
						float dotEdge1Out = dotProduct(rhsNormal, lhsEdge1Out);
						float dotEdge2Out = dotProduct(rhsNormal, lhsEdge2Out);

						/*
						 * Add the intersection to the vector for the edge of the lhs triangle to which it is most
						 * closely aligned. Since we're talking about convex shapes the intersection should be on that
						 * edge's side of the rhs mesh.
						 */
						if (dotEdge0Out > dotEdge1Out && dotEdge0Out > dotEdge2Out)
						{
							intersections[0].push_back(intersection);
						}
						else if (dotEdge1Out > dotEdge0Out && dotEdge1Out > dotEdge2Out)
						{
							intersections[1].push_back(intersection);
						}
						else
						{
							intersections[2].push_back(intersection);
						}
					}
				}

				// If the lhs triangle does not intersect with the rhs mesh, preserve it.
				if (intersections[0].empty() && intersections[1].empty() && intersections[2].empty())
				{
					newIndices.push_back(lhsIndices[lhsIndex]);
					newIndices.push_back(lhsIndices[lhsIndex + 1]);
					newIndices.push_back(lhsIndices[lhsIndex = 2]);
					continue;
				}

				/*
				 * Project the intersection points onto the corresponding edge and sort them based on how far along the
				 * edge they are.
				 */
				map<float, Vector3> sortedIntersectionPoints;
				for (const Line& intersection : intersections[0])
				{
					Vector3 projection = getProjection(intersection.getPointA() - lhsTriangle.getPointA(), lhsEdge0);
					sortedIntersectionPoints[projection.getMagnitude() / lhsEdge0.getMagnitude()] =
							intersection.getPointA();
				}
				Vector3 projection = getProjection(intersections[0].back().getPointB() -
						lhsTriangle.getPointA(), lhsEdge0);
				sortedIntersectionPoints[projection.getMagnitude() / lhsEdge0.getMagnitude()] =
						intersections[0].back().getPointB();

				Vertex lhsVertexA = lhsVertices[lhsIndices[lhsIndex]];
				//Vertex lhsVertexB = lhsVertices[lhsIndices[lhsIndex + 1]];

				/*
				 * Connect the dots!
				 */
				for (map<float, Vector3>::iterator intersectionPointIter = sortedIntersectionPoints.begin();
						intersectionPointIter != sortedIntersectionPoints.end(); intersectionPointIter++)
				{
					if (intersectionPointIter == sortedIntersectionPoints.begin())
					{
						Vertex newIntersectionVertex = lhsVertexA;
						newIntersectionVertex.position =
								Vector3((Vector4(intersectionPointIter->second, 1.0f) * relativeTransform).getData());
						newVertices.push_back(newIntersectionVertex);

						Vertex newEdgeVertex = lhsVertexA;
						float projectionDistance = intersectionPointIter->first / 2.0f;
						newEdgeVertex.position = lhsTriangle.getPointA() + (lhsEdge0 * projectionDistance);
						newVertices.push_back(newEdgeVertex);

						newIndices.push_back(lhsIndices[lhsIndex]);
						newIndices.push_back(newVertices.size() - 1);
						newIndices.push_back(newVertices.size() - 2);
					}
				}
			}

			return ModelFactory::getInstance().createMesh(newVertices, newIndices);
		}

		void translateVertices(vector<Vertex>& vertices, const Vector3& translation)
		{
			for (Vertex& vertex : vertices)
			{
				vertex.position += translation;
			}
		}
	}
}
