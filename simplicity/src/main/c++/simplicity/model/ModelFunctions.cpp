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
#include "../math/Distance.h"
#include "../math/Intersection.h"
#include "../math/MathFunctions.h"
#include "ModelFactory.h"
#include "ModelFunctions.h"

using namespace std;

namespace simplicity
{
	namespace ModelFunctions
	{
		void getSortedPoints(const vector<Line>& intersections, const Line& lhsEdge,
				map<float, Vector3>& sortedIntersectionPoints, map<float, Vector3>& sortedEdgePoints);

		void subtract(const Mesh& lhs, const Mesh& rhs, vector<Vertex>& newVertices, vector<unsigned int>& newIndices,
						unsigned int newIndicesOffset, const Matrix44& relativeTransform, bool invert);
		void subtract(vector<Vertex>& vertices, vector<unsigned int>& indices, const vector<Line>& intersections,
				const Line& lhsEdge, const Vertex& templateVertex, bool intersectionAtEdge);

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

		/*
		 * Project the intersection points onto the corresponding edge and sort them based on how far along the
		 * edge they are. Also, find the points on the edge half way between the projected points and sort them
		 * based on how far along the edge they are.
		 */
		void getSortedPoints(const vector<Line>& intersections, const Line& lhsEdge,
				map<float, Vector3>& sortedIntersectionPoints, map<float, Vector3>& sortedEdgePoints)
		{
			Vector3 lhsEdgeVector = lhsEdge.getPointB() - lhsEdge.getPointA();
			float lhsEdgeVectorMagnitude = lhsEdgeVector.getMagnitude();

			for (unsigned int index = 0; index < intersections.size(); index++)
			{
				Vector3 intersectionA = intersections[index].getPointA();
				Vector3 intersectionB = intersections[index].getPointB();
				Vector3 projectionA = getProjection(intersectionA - lhsEdge.getPointA(), lhsEdgeVector);
				Vector3 projectionB = getProjection(intersectionB - lhsEdge.getPointA(), lhsEdgeVector);
				Vector3 toProjectionB = projectionB - projectionA;
				Vector3 edgePoint = projectionA + (toProjectionB * 0.5f);

				sortedEdgePoints[edgePoint.getMagnitude() / lhsEdgeVectorMagnitude] = lhsEdge.getPointA() + edgePoint;
				sortedIntersectionPoints[projectionA.getMagnitude() / lhsEdgeVectorMagnitude] = intersectionA;
				sortedIntersectionPoints[projectionB.getMagnitude() / lhsEdgeVectorMagnitude] = intersectionB;
			}

			// Add the endpoints of the edge to the edge points.
			sortedEdgePoints[0.0f] = lhsEdge.getPointA();
			sortedEdgePoints[1.0f] = lhsEdge.getPointB();

			// Remove duplicates
			map<float, Vector3>::iterator intersectionPointIter0 = sortedIntersectionPoints.begin();
			map<float, Vector3>::iterator intersectionPointIter1 = sortedIntersectionPoints.begin();
			intersectionPointIter1++;
			while (intersectionPointIter1 != sortedIntersectionPoints.end())
			{
				if (near(intersectionPointIter0->second, intersectionPointIter1->second))
				{
					sortedIntersectionPoints.erase(intersectionPointIter0);

					// Iterators invalidated - restart.
					intersectionPointIter0 = sortedIntersectionPoints.begin();
					intersectionPointIter1 = sortedIntersectionPoints.begin();
					intersectionPointIter1++;
				}
				else
				{
					intersectionPointIter0++;
					intersectionPointIter1++;
				}
			}
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
				//vertex.normal = rotationMatrix * vertex.normal;
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
			vector<Vertex> newVertices;
			newVertices.insert(newVertices.end(), lhs.getVertices().begin(), lhs.getVertices().end());
			newVertices.insert(newVertices.end(), rhs.getVertices().begin(), rhs.getVertices().end());
			vector<unsigned int> newIndices;
			newIndices.reserve(lhs.getIndices().size() + rhs.getIndices().size());

			subtract(lhs, rhs, newVertices, newIndices, 0, relativeTransform, false);

			Matrix44 inverseRelativeTransform = relativeTransform;
			inverseRelativeTransform.invert();
			//subtract(rhs, lhs, newVertices, newIndices, lhs.getVertices().size(), inverseRelativeTransform, true);

			return ModelFactory::getInstance().createMesh(newVertices, newIndices);
		}

		void subtract(const Mesh& lhs, const Mesh& rhs, vector<Vertex>& newVertices, vector<unsigned int>& newIndices,
				unsigned int newIndicesOffset, const Matrix44& relativeTransform, bool invert)
		{
			const vector<Vertex>& lhsVertices = lhs.getVertices();
			const vector<unsigned int>& lhsIndices = lhs.getIndices();
			const vector<Vertex>& rhsVertices = rhs.getVertices();
			const vector<unsigned int>& rhsIndices = rhs.getIndices();

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

				// Retrieve the lines of intersection with the lhs triangle.
				vector<Line> intersections[3];
				bool intersectionsAtEdge[3] = {false, false, false};
				for (unsigned int rhsIndex = 0; rhsIndex < rhsIndices.size(); rhsIndex += 3)
				{
					Vector3 rhsPointA((relativeTransform * Vector4(rhsVertices[rhsIndices[rhsIndex]].position, 1.0f)).getData());
					Vector3 rhsPointB((relativeTransform * Vector4(rhsVertices[rhsIndices[rhsIndex + 1]].position, 1.0f)).getData());
					Vector3 rhsPointC((relativeTransform * Vector4(rhsVertices[rhsIndices[rhsIndex + 2]].position, 1.0f)).getData());
					Triangle rhsTriangle(rhsPointA, rhsPointB, rhsPointC);

					Vector3 rhsEdge0 = rhsTriangle.getPointB() - rhsTriangle.getPointA();
					Vector3 rhsEdge1 = rhsTriangle.getPointC() - rhsTriangle.getPointA();
					Vector3 rhsNormal = crossProduct(rhsEdge0, rhsEdge1);
					rhsNormal.normalize();

					if (Intersection::intersect(lhsTriangle, rhsTriangle, lhsNormal, rhsNormal))
					{
						Line intersection = Intersection::getIntersection(lhsTriangle, rhsTriangle, lhsNormal, rhsNormal);

						// Disregard point intersections.
						if (near(intersection.getPointA(), intersection.getPointB()))
						{
							continue;
						}

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
							Line edge(lhsTriangle.getPointA(), lhsTriangle.getPointB());
							if (near(Distance::distanceBetween(edge, rhsPointA), 0.0f) ||
									near(Distance::distanceBetween(edge, rhsPointB), 0.0f) ||
									near(Distance::distanceBetween(edge, rhsPointC), 0.0f))
							{
								intersectionsAtEdge[0] = true;
							}
						}
						else if (dotEdge1Out > dotEdge0Out && dotEdge1Out > dotEdge2Out)
						{
							intersections[1].push_back(intersection);
							Line edge(lhsTriangle.getPointB(), lhsTriangle.getPointC());
							if (near(Distance::distanceBetween(edge, rhsPointA), 0.0f) ||
									near(Distance::distanceBetween(edge, rhsPointB), 0.0f) ||
									near(Distance::distanceBetween(edge, rhsPointC), 0.0f))
							{
								intersectionsAtEdge[1] = true;
							}
						}
						else
						{
							intersections[2].push_back(intersection);
							Line edge(lhsTriangle.getPointC(), lhsTriangle.getPointA());
							if (near(Distance::distanceBetween(edge, rhsPointA), 0.0f) ||
									near(Distance::distanceBetween(edge, rhsPointB), 0.0f) ||
									near(Distance::distanceBetween(edge, rhsPointC), 0.0f))
							{
								intersectionsAtEdge[2] = true;
							}
						}
					}
				}

				// If the lhs triangle does not intersect with the rhs mesh, preserve it.
				if (intersections[0].empty() && intersections[1].empty() && intersections[2].empty())
				{
					newIndices.push_back(lhsIndices[lhsIndex] + newIndicesOffset);
					newIndices.push_back(lhsIndices[lhsIndex + 1] + newIndicesOffset);
					newIndices.push_back(lhsIndices[lhsIndex + 2] + newIndicesOffset);
					continue;
				}

				if (!intersections[0].empty())
				{
					subtract(newVertices, newIndices, intersections[0],
							Line(lhsTriangle.getPointA(), lhsTriangle.getPointB()), lhsVertices[lhsIndices[lhsIndex]],
							intersectionsAtEdge[0]);
				}
				if (!intersections[1].empty())
				{
					subtract(newVertices, newIndices, intersections[1],
							Line(lhsTriangle.getPointB(), lhsTriangle.getPointC()), lhsVertices[lhsIndices[lhsIndex]],
							intersectionsAtEdge[1]);
				}
				if (!intersections[2].empty())
				{
					subtract(newVertices, newIndices, intersections[2],
							Line(lhsTriangle.getPointC(), lhsTriangle.getPointA()), lhsVertices[lhsIndices[lhsIndex]],
							intersectionsAtEdge[2]);
				}
			}
		}

		void subtract(vector<Vertex>& vertices, vector<unsigned int>& indices, const vector<Line>& intersections,
				const Line& lhsEdge, const Vertex& templateVertex, bool intersectionAtEdge)
		{
			map<float, Vector3> sortedEdgePoints;
			map<float, Vector3> sortedIntersectionPoints;
			getSortedPoints(intersections, lhsEdge, sortedIntersectionPoints, sortedEdgePoints);

			// Connect the dots!
			bool gap = false;
			map<float, Vector3>::iterator intersectionPointIter = sortedIntersectionPoints.begin();
			map<float, Vector3>::iterator edgePointIter = sortedEdgePoints.begin();
			while (intersectionPointIter != sortedIntersectionPoints.end())
			{
				if (gap)
				{
					gap = false;
				}
				else
				{
					// Create a triangle between two edge points and an intersection point.
					Vertex vertexAA = templateVertex;
					vertexAA.position = intersectionPointIter->second;
					vertices.push_back(vertexAA);

					Vertex vertexAB = templateVertex;
					vertexAB.position = edgePointIter->second;
					vertices.push_back(vertexAB);

					edgePointIter++;
					if (edgePointIter == sortedEdgePoints.end())
					{
						// Oops... we've reached the end of the edge points which means this triangle isn't needed.
						// This happens if a gap was created in the lhs edge by the intersections.
						vertices.pop_back();
						vertices.pop_back();
					}
					else
					{
						Vertex vertexAC = templateVertex;
						vertexAC.position = edgePointIter->second;
						vertices.push_back(vertexAC);
					}
				}

				Vertex templateVertex2 = templateVertex;
				templateVertex2.color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

				// Create a triangle between two intersection points and an edge point.
				Vertex vertexBA = templateVertex2;
				vertexBA.position = intersectionPointIter->second;
				vertices.push_back(vertexBA);

				intersectionPointIter++;
				if (intersectionPointIter == sortedIntersectionPoints.end())
				{
					// Oops... we've reached the end of the intersection points which means this triangle isn't needed.
					vertices.pop_back();
				}
				else
				{
					Vertex vertexBB = templateVertex2;
					vertexBB.position = edgePointIter->second;
					vertices.push_back(vertexBB);

					Vertex vertexBC = templateVertex2;
					vertexBC.position = intersectionPointIter->second;
					vertices.push_back(vertexBC);
				}

				if (intersectionPointIter != sortedIntersectionPoints.end())
				{
					indices.push_back(vertices.size() - 6);
					indices.push_back(vertices.size() - 5);
					indices.push_back(vertices.size() - 4);

					// If an intersection point is on the line then a gap in the edge has been created!
					if (near(Distance::distanceBetween(lhsEdge, Point(intersectionPointIter->second)),  0.0f))
					{
						edgePointIter++;

						/*
						 * Although... just maybe... the intersection ended exactly on the edge in which case there is
						 * no gap... If that's true we should stick with the same intersection point.
						 */
						if (!intersectionAtEdge)
						{
							intersectionPointIter++;
						}

						edgePointIter++;
						gap = true;
					}
				}

				indices.push_back(vertices.size() - 3);
				indices.push_back(vertices.size() - 2);
				indices.push_back(vertices.size() - 1);
			}
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
