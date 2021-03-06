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

#include "../common/Category.h"
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
		struct MeshIntersection
		{
			MeshIntersection(Line intersection, Vector3 lhsNormal, Triangle lhsTriangle, unsigned int lhsTriangleIndex,
					Vector3 rhsNormal, Triangle rhsTriangle, unsigned int rhsTriangleIndex) :
				intersection(intersection),
				lhsNormal(lhsNormal),
				lhsTriangle(lhsTriangle),
				lhsTriangleIndex(lhsTriangleIndex),
				rhsNormal(rhsNormal),
				rhsTriangle(rhsTriangle),
				rhsTriangleIndex(rhsTriangleIndex)
			{
			}

			Line intersection;

			Vector3 lhsNormal;

			Triangle lhsTriangle;

			unsigned int lhsTriangleIndex;

			Vector3 rhsNormal;

			Triangle rhsTriangle;

			unsigned int rhsTriangleIndex;

			bool isPointIntersection()
			{
				return near(intersection.getPointA(), intersection.getPointB());
			}
		};

		vector<MeshIntersection> getIntersections(const MeshData& lhsData, const MeshData& rhsData,
				const Matrix44& relativeTransform);

		void getSortedEdgePoints(const vector<MeshIntersection>& intersections, const Line& lhsEdge,
				map<float, Vector3>& sortedEdgePoints);

		void getSortedIntersectionPoints(const vector<MeshIntersection>& intersections, const Line& lhsEdge,
				map<float, Vector3>& sortedIntersectionPoints);

		void removeIntersection(const MeshData& lhsData, const MeshData& rhsData, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Matrix44& relativeTransform);

		/*
		 * TODO Instead of using a 'template' vertex we should really be interpolating the normal, color and texture
		 * coordinates from the original vertices of the lhs triangle.
		 */
		void removeIntersection(const MeshData& lhsData, const MeshData& rhsData, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Triangle& lhsTriangle, unsigned int lhsTriangleIndex,
				unsigned int nextLhsTriangleIndex, const vector<MeshIntersection>* intersections,
				bool* currentIntersectionsAtEdge, const Matrix44& inverseRelativeTransform);

		void removeIntersection(vector<Vertex>& vertices, vector<unsigned int>& indices,
				const vector<MeshIntersection>& intersections, const Line& lhsEdge, const Vertex& templateVertex,
				bool intersectionAtEdge);

		void retainIntersection(const MeshData& lhsData, const Mesh& rhsData, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Matrix44& relativeTransform);

		/*
		 * TODO Instead of using a 'template' vertex we should really be interpolating the normal, color and texture
		 * coordinates from the original vertices of the lhs triangle.
		 */
		void retainIntersection(const MeshData& lhsData, const MeshData& rhsData, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Triangle& lhsTriangle, unsigned int lhsTriangleIndex,
				unsigned int nextLhsTriangleIndex, const vector<MeshIntersection>* intersections,
				const Matrix44& inverseRelativeTransform);

		void colorizeVertices(vector<Vertex>& vertices, const Vector4& color, unsigned int begin, unsigned int end)
		{
			colorizeVertices(vertices.data(), vertices.size(), color, begin, end);
		}

		void colorizeVertices(Vertex* vertices, unsigned int vertexCount, const Vector4& color, unsigned int begin,
				unsigned int end)
		{
			if (end == 0)
			{
				end = vertexCount;
			}

			for (unsigned int index = begin; index < end; index++)
			{
				vertices[index].color = color;
			}
		}

		void flipTriangles(std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, unsigned int begin,
				unsigned int end)
		{
			flipTriangles(vertices.data(), indices.data(), indices.size(), begin, end);
		}

		void flipTriangles(Vertex* vertices, const unsigned int* indices, unsigned int indexCount, unsigned int begin,
				unsigned int end)
		{
			if (end == 0)
			{
				end = indexCount;
			}

			for (unsigned int index = begin; index < end; index += 3)
			{
				Vertex temp = vertices[indices[index + 1]];
				vertices[indices[index + 1]] = vertices[indices[index + 2]];
				vertices[indices[index + 2]] = temp;

				vertices[indices[index]].normal.negate();
				vertices[indices[index + 1]].normal.negate();
				vertices[indices[index + 2]].normal.negate();
			}
		}

		unique_ptr<Circle> getCircleBoundsXZ(const Vertex* vertices, unsigned int vertexCount)
		{
			float maxMagnitudeSquared = 0.0f;

			for (unsigned int index = 0; index < vertexCount; index++)
			{
				float magnitudeSquared = vertices[index].position.getMagnitudeSquared();
				if (magnitudeSquared > maxMagnitudeSquared)
				{
					maxMagnitudeSquared = magnitudeSquared;
				}
			}

			unique_ptr<Circle> bounds(new Circle(sqrt(maxMagnitudeSquared)));
			return move(bounds);
		}

		vector<MeshIntersection> getIntersections(const MeshData& lhsData, const MeshData& rhsData,
				const Matrix44& relativeTransform)
		{
			vector<MeshIntersection> intersections;

			Matrix44 inverseRelativeTransform = relativeTransform;
			inverseRelativeTransform.invert();

			for (unsigned int lhsIndex = 0; lhsIndex < lhsData.indexCount; lhsIndex += 3)
			{
				Triangle lhsTriangle(lhsData[lhsIndex].position, lhsData[lhsIndex + 1].position,
						lhsData[lhsIndex + 2].position);

				Vector3 lhsEdge0 = lhsTriangle.getPointB() - lhsTriangle.getPointA();
				Vector3 lhsEdge1 = lhsTriangle.getPointC() - lhsTriangle.getPointA();
				Vector3 lhsNormal = crossProduct(lhsEdge0, lhsEdge1);
				lhsNormal.normalize();

				for (unsigned int rhsIndex = 0; rhsIndex < rhsData.indexCount; rhsIndex += 3)
				{
					Vector3 rhsPointA((relativeTransform * Vector4(rhsData[rhsIndex].position, 1.0f)).getData());
					Vector3 rhsPointB((relativeTransform * Vector4(rhsData[rhsIndex + 1].position, 1.0f)).getData());
					Vector3 rhsPointC((relativeTransform * Vector4(rhsData[rhsIndex + 2].position, 1.0f)).getData());
					Triangle rhsTriangle(rhsPointA, rhsPointB, rhsPointC);

					Vector3 rhsEdge0 = rhsPointB - rhsPointA;
					Vector3 rhsEdge1 = rhsPointC - rhsPointA;
					Vector3 rhsNormal = crossProduct(rhsEdge0, rhsEdge1);
					rhsNormal.normalize();

					if (Intersection::intersect(lhsTriangle, rhsTriangle, lhsNormal, rhsNormal))
					{
						intersections.push_back(MeshIntersection(
								Intersection::getIntersection(lhsTriangle, rhsTriangle, lhsNormal, rhsNormal),
								lhsNormal,
								lhsTriangle,
								lhsIndex / 3,
								rhsNormal,
								rhsTriangle,
								rhsIndex / 3));
					}
				}
			}

			return intersections;
		}

		/*
		 * Find the points on the edge half way between the projected points and sort them based on how far along the
		 * edge they are.
		 */
		void getSortedEdgePoints(const vector<MeshIntersection>& intersections, const Line& lhsEdge,
				map<float, Vector3>& sortedEdgePoints)
		{
			Vector3 lhsEdgeVector = lhsEdge.getPointB() - lhsEdge.getPointA();
			float lhsEdgeVectorMagnitude = lhsEdgeVector.getMagnitude();

			for (unsigned int index = 0; index < intersections.size(); index++)
			{
				Vector3 intersectionA = intersections[index].intersection.getPointA();
				Vector3 intersectionB = intersections[index].intersection.getPointB();
				Vector3 projectionA = getProjection(intersectionA - lhsEdge.getPointA(), lhsEdgeVector);
				Vector3 projectionB = getProjection(intersectionB - lhsEdge.getPointA(), lhsEdgeVector);
				Vector3 toProjectionB = projectionB - projectionA;
				Vector3 edgePoint = projectionA + (toProjectionB * 0.5f);

				sortedEdgePoints[edgePoint.getMagnitude() / lhsEdgeVectorMagnitude] = lhsEdge.getPointA() + edgePoint;
			}

			// Add the endpoints of the edge to the edge points.
			sortedEdgePoints[0.0f] = lhsEdge.getPointA();
			sortedEdgePoints[1.0f] = lhsEdge.getPointB();
		}

		/*
		 * Project the intersection points onto the corresponding edge and sort them based on how far along the
		 * edge they are.
		 */
		void getSortedIntersectionPoints(const vector<MeshIntersection>& intersections, const Line& lhsEdge,
				map<float, Vector3>& sortedIntersectionPoints)
		{
			Vector3 lhsEdgeVector = lhsEdge.getPointB() - lhsEdge.getPointA();
			float lhsEdgeVectorMagnitude = lhsEdgeVector.getMagnitude();

			for (unsigned int index = 0; index < intersections.size(); index++)
			{
				Vector3 intersectionA = intersections[index].intersection.getPointA();
				Vector3 intersectionB = intersections[index].intersection.getPointB();
				Vector3 projectionA = getProjection(intersectionA - lhsEdge.getPointA(), lhsEdgeVector);
				Vector3 projectionB = getProjection(intersectionB - lhsEdge.getPointA(), lhsEdgeVector);

				sortedIntersectionPoints[projectionA.getMagnitude() / lhsEdgeVectorMagnitude] = intersectionA;
				sortedIntersectionPoints[projectionB.getMagnitude() / lhsEdgeVectorMagnitude] = intersectionB;
			}

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

		unique_ptr<Square> getSquareBoundsXZ(const Vertex* vertices, unsigned int vertexCount)
		{
			float halfEdgeLength = 0.0f;

			for (unsigned int index = 0; index < vertexCount; index++)
			{
				const Vector3& position = vertices[index].position;

				if (position.X() > halfEdgeLength)
				{
					halfEdgeLength = position.X();
				}
				else if (-position.X() > halfEdgeLength)
				{
					halfEdgeLength = -position.X();
				}

				if (position.Z() < halfEdgeLength)
				{
					halfEdgeLength = position.Z();
				}
				else if (-position.Z() > halfEdgeLength)
				{
					halfEdgeLength = -position.Z();
				}
			}

			unique_ptr<Square> bounds(new Square(halfEdgeLength));
			return move(bounds);
		}

		void removeIntersection(const MeshData& lhsData, const MeshData& rhsData, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Matrix44& relativeTransform)
		{
			Matrix44 inverseRelativeTransform = relativeTransform;
			inverseRelativeTransform.invert();

			vector<MeshIntersection> intersections = getIntersections(lhsData, rhsData, relativeTransform);
			Triangle lhsTriangle = intersections[0].lhsTriangle;
			unsigned int lhsTriangleIndex = 0;

			// Populate the lhs triangle data.
			Vector3 lhsEdge0Vector = lhsTriangle.getPointB() - lhsTriangle.getPointA();
			Vector3 lhsEdge1Vector = lhsTriangle.getPointC() - lhsTriangle.getPointB();
			Vector3 lhsEdge2Vector = lhsTriangle.getPointA() - lhsTriangle.getPointC();
			/*
			 * These 'out' vectors are vectors on the lhs triangle's plane perpendicular to the edges of the triangle
			 * and in the direction that is 'outward' from the triangle.
			 */
			Vector3 lhsEdge0Out = crossProduct(lhsEdge0Vector, intersections[0].lhsNormal);
			lhsEdge0Out.normalize();
			Vector3 lhsEdge1Out = crossProduct(lhsEdge1Vector, intersections[0].lhsNormal);
			lhsEdge1Out.normalize();
			Vector3 lhsEdge2Out = crossProduct(lhsEdge2Vector, intersections[0].lhsNormal);
			lhsEdge2Out.normalize();

			// The intersections with the current lhs triangle, separated according to which edge they are most aligned.
			vector<MeshIntersection> currentIntersections[3];

			// Determines whether the intersections with the current lhs triangle end on the edge of the triangle.
			bool currentIntersectionsAtEdge[3] = {false, false, false};

			for (MeshIntersection& intersection : intersections)
			{
				// Disregard point intersections.
				if (intersection.isPointIntersection())
				{
					continue;
				}

				// If we've finished processing an lhs triangle.
				if (intersection.lhsTriangleIndex != lhsTriangleIndex)
				{
					removeIntersection(lhsData, rhsData, newVertices, newIndices, lhsTriangle, lhsTriangleIndex,
							intersection.lhsTriangleIndex, currentIntersections, currentIntersectionsAtEdge,
							inverseRelativeTransform);

					lhsTriangle = intersection.lhsTriangle;
					lhsTriangleIndex = intersection.lhsTriangleIndex;

					// Re-populate the lhs triangle data.
					Vector3 lhsEdge0Vector = lhsTriangle.getPointB() - lhsTriangle.getPointA();
					Vector3 lhsEdge1Vector = lhsTriangle.getPointC() - lhsTriangle.getPointB();
					Vector3 lhsEdge2Vector = lhsTriangle.getPointA() - lhsTriangle.getPointC();
					lhsEdge0Out = crossProduct(lhsEdge0Vector, intersection.lhsNormal);
					lhsEdge0Out.normalize();
					lhsEdge1Out = crossProduct(lhsEdge1Vector, intersection.lhsNormal);
					lhsEdge1Out.normalize();
					lhsEdge2Out = crossProduct(lhsEdge2Vector, intersection.lhsNormal);
					lhsEdge2Out.normalize();

					// Reset the intersection data.
					currentIntersections[0].clear();
					currentIntersections[1].clear();
					currentIntersections[2].clear();
					currentIntersectionsAtEdge[0] = false;
					currentIntersectionsAtEdge[1] = false;
					currentIntersectionsAtEdge[2] = false;
				}

				float dotEdge0Out = dotProduct(intersection.rhsNormal, lhsEdge0Out);
				float dotEdge1Out = dotProduct(intersection.rhsNormal, lhsEdge1Out);
				float dotEdge2Out = dotProduct(intersection.rhsNormal, lhsEdge2Out);

				/*
				 * Add the intersection to the vector for the edge of the lhs triangle to which it is most
				 * closely aligned. Since we're talking about convex shapes the intersection should be on that
				 * edge's side of the rhs mesh.
				 */
				if (dotEdge0Out > dotEdge1Out && dotEdge0Out > dotEdge2Out)
				{
					currentIntersections[0].push_back(intersection);
					Line edge(intersection.lhsTriangle.getPointA(), intersection.lhsTriangle.getPointB());
					if (near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointA()), 0.0f) ||
							near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointB()), 0.0f) ||
							near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointC()), 0.0f))
					{
						currentIntersectionsAtEdge[0] = true;
					}
				}
				else if (dotEdge1Out > dotEdge0Out && dotEdge1Out > dotEdge2Out)
				{
					currentIntersections[1].push_back(intersection);
					Line edge(intersection.lhsTriangle.getPointB(), intersection.lhsTriangle.getPointC());
					if (near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointA()), 0.0f) ||
							near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointB()), 0.0f) ||
							near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointC()), 0.0f))
					{
						currentIntersectionsAtEdge[1] = true;
					}
				}
				else
				{
					currentIntersections[2].push_back(intersection);
					Line edge(intersection.lhsTriangle.getPointC(), intersection.lhsTriangle.getPointA());
					if (near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointA()), 0.0f) ||
							near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointB()), 0.0f) ||
							near(Distance::distanceBetween(edge, intersection.rhsTriangle.getPointC()), 0.0f))
					{
						currentIntersectionsAtEdge[2] = true;
					}
				}
			}

			removeIntersection(lhsData, rhsData, newVertices, newIndices, lhsTriangle, lhsTriangleIndex,
					lhsData.indexCount / 3, currentIntersections, currentIntersectionsAtEdge,
					inverseRelativeTransform);
		}

		void removeIntersection(const MeshData& lhsData, const MeshData& rhsData, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Triangle& lhsTriangle, unsigned int lhsTriangleIndex,
				unsigned int nextLhsTriangleIndex, const vector<MeshIntersection>* intersections,
				bool* currentIntersectionsAtEdge, const Matrix44& inverseRelativeTransform)
		{
			Vertex templateVertex = lhsData[lhsTriangleIndex * 3];

			if (!intersections[0].empty())
			{
				Line lhsEdge0(lhsTriangle.getPointA(), lhsTriangle.getPointB());
				removeIntersection(newVertices, newIndices, intersections[0], lhsEdge0, templateVertex,
						currentIntersectionsAtEdge[0]);
			}
			if (!intersections[1].empty())
			{
				Line lhsEdge1(lhsTriangle.getPointB(), lhsTriangle.getPointC());
				removeIntersection(newVertices, newIndices, intersections[1], lhsEdge1, templateVertex,
						currentIntersectionsAtEdge[1]);
			}
			if (!intersections[2].empty())
			{
				Line lhsEdge2(lhsTriangle.getPointC(), lhsTriangle.getPointA());
				removeIntersection(newVertices, newIndices, intersections[2], lhsEdge2, templateVertex,
						currentIntersectionsAtEdge[2]);
			}

			/*
			 * If the current lhs triangle was intersected, move to the next lhs triangle. This implicitly
			 * handles the case where the first lhs triangle was not intersected (by not moving to the next lhs
			 * triangle).
			 */
			if (!intersections[0].empty() || !intersections[1].empty() || !intersections[2].empty())
			{
				lhsTriangleIndex++;
			}

			// Preserve any lhs triangles NOT within the rhs mesh that did not have any intersections.
			while(lhsTriangleIndex < nextLhsTriangleIndex)
			{
				unsigned int vertexIndex = lhsTriangleIndex * 3;

				Triangle lhsTriangle(lhsData[vertexIndex].position, lhsData[vertexIndex + 1].position,
						lhsData[vertexIndex + 2].position);

				if (Intersection::contains(rhsData, lhsTriangle, inverseRelativeTransform))
				{
					lhsTriangleIndex++;
					continue;
				}

				newVertices.push_back(lhsData[vertexIndex]);
				newVertices.push_back(lhsData[vertexIndex + 1]);
				newVertices.push_back(lhsData[vertexIndex + 2]);

				newIndices.push_back(newVertices.size() - 3);
				newIndices.push_back(newVertices.size() - 2);
				newIndices.push_back(newVertices.size() - 1);

				lhsTriangleIndex++;
			}
		}

		void removeIntersection(vector<Vertex>& vertices, vector<unsigned int>& indices,
				const vector<MeshIntersection>& intersections, const Line& lhsEdge, const Vertex& templateVertex,
				bool intersectionAtEdge)
		{
			map<float, Vector3> sortedEdgePoints;
			getSortedEdgePoints(intersections, lhsEdge, sortedEdgePoints);
			map<float, Vector3> sortedIntersectionPoints;
			getSortedIntersectionPoints(intersections, lhsEdge, sortedIntersectionPoints);

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

		void retainIntersection(const MeshData& lhsData, const MeshData& rhsData, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Matrix44& relativeTransform)
		{
			Matrix44 inverseRelativeTransform = relativeTransform;
			inverseRelativeTransform.invert();

			vector<MeshIntersection> intersections = getIntersections(lhsData, rhsData, relativeTransform);
			Triangle lhsTriangle = intersections[0].lhsTriangle;
			unsigned int lhsTriangleIndex = 0;

			// Populate the lhs triangle data.
			Vector3 lhsEdge0Vector = lhsTriangle.getPointB() - lhsTriangle.getPointA();
			Vector3 lhsEdge1Vector = lhsTriangle.getPointC() - lhsTriangle.getPointB();
			Vector3 lhsEdge2Vector = lhsTriangle.getPointA() - lhsTriangle.getPointC();
			/*
			 * These 'out' vectors are vectors on the lhs triangle's plane perpendicular to the edges of the triangle
			 * and in the direction that is 'outward' from the triangle.
			 */
			Vector3 lhsEdge0Out = crossProduct(lhsEdge0Vector, intersections[0].lhsNormal);
			lhsEdge0Out.normalize();
			Vector3 lhsEdge1Out = crossProduct(lhsEdge1Vector, intersections[0].lhsNormal);
			lhsEdge1Out.normalize();
			Vector3 lhsEdge2Out = crossProduct(lhsEdge2Vector, intersections[0].lhsNormal);
			lhsEdge2Out.normalize();

			// The intersections with the current lhs triangle, separated according to which edge they are most aligned.
			vector<MeshIntersection> currentIntersections[3];

			for (MeshIntersection& intersection : intersections)
			{
				// Disregard point intersections.
				if (intersection.isPointIntersection())
				{
					continue;
				}

				// If we've finished processing an lhs triangle.
				if (intersection.lhsTriangleIndex != lhsTriangleIndex)
				{
					retainIntersection(lhsData, rhsData, newVertices, newIndices, lhsTriangle, lhsTriangleIndex,
							intersection.lhsTriangleIndex, currentIntersections, inverseRelativeTransform);

					lhsTriangle = intersection.lhsTriangle;
					lhsTriangleIndex = intersection.lhsTriangleIndex;

					// Re-populate the lhs triangle data.
					Vector3 lhsEdge0Vector = lhsTriangle.getPointB() - lhsTriangle.getPointA();
					Vector3 lhsEdge1Vector = lhsTriangle.getPointC() - lhsTriangle.getPointB();
					Vector3 lhsEdge2Vector = lhsTriangle.getPointA() - lhsTriangle.getPointC();
					lhsEdge0Out = crossProduct(lhsEdge0Vector, intersection.lhsNormal);
					lhsEdge0Out.normalize();
					lhsEdge1Out = crossProduct(lhsEdge1Vector, intersection.lhsNormal);
					lhsEdge1Out.normalize();
					lhsEdge2Out = crossProduct(lhsEdge2Vector, intersection.lhsNormal);
					lhsEdge2Out.normalize();

					// Reset the intersection data.
					currentIntersections[0].clear();
					currentIntersections[1].clear();
					currentIntersections[2].clear();
				}

				float dotEdge0Out = dotProduct(intersection.rhsNormal, lhsEdge0Out);
				float dotEdge1Out = dotProduct(intersection.rhsNormal, lhsEdge1Out);
				float dotEdge2Out = dotProduct(intersection.rhsNormal, lhsEdge2Out);

				/*
				 * Add the intersection to the vector for the edge of the lhs triangle to which it is most
				 * closely aligned. Since we're talking about convex shapes the intersection should be on that
				 * edge's side of the rhs mesh.
				 */
				if (dotEdge0Out > dotEdge1Out && dotEdge0Out > dotEdge2Out)
				{
					currentIntersections[0].push_back(intersection);
				}
				else if (dotEdge1Out > dotEdge0Out && dotEdge1Out > dotEdge2Out)
				{
					currentIntersections[1].push_back(intersection);
				}
				else
				{
					currentIntersections[2].push_back(intersection);
				}
			}

			retainIntersection(lhsData, rhsData, newVertices, newIndices, lhsTriangle, lhsTriangleIndex,
					lhsData.indexCount / 3, currentIntersections, inverseRelativeTransform);
		}

		void retainIntersection(const MeshData& lhsData, const MeshData& rhsData, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Triangle& lhsTriangle, unsigned int lhsTriangleIndex,
				unsigned int nextLhsTriangleIndex, const vector<MeshIntersection>* intersections,
				const Matrix44& inverseRelativeTransform)
		{
			vector<Vector3> sortedIntersectionPoints;
			Line lhsEdge0(lhsTriangle.getPointA(), lhsTriangle.getPointB());
			Line lhsEdge1(lhsTriangle.getPointB(), lhsTriangle.getPointC());
			Line lhsEdge2(lhsTriangle.getPointC(), lhsTriangle.getPointA());

			if (!intersections[0].empty())
			{
				map<float, Vector3> sortedEdgeIntersectionPoints;
				getSortedIntersectionPoints(intersections[0], lhsEdge0, sortedEdgeIntersectionPoints);

				for (map<float, Vector3>::iterator sortedPointIter = sortedEdgeIntersectionPoints.begin();
						sortedPointIter != sortedEdgeIntersectionPoints.end(); sortedPointIter++)
				{
					sortedIntersectionPoints.push_back(sortedPointIter->second);
				}
			}

			if (!intersections[1].empty())
			{
				map<float, Vector3> sortedEdgeIntersectionPoints;
				getSortedIntersectionPoints(intersections[1], lhsEdge1, sortedEdgeIntersectionPoints);

				for (map<float, Vector3>::iterator sortedPointIter = sortedEdgeIntersectionPoints.begin();
						sortedPointIter != sortedEdgeIntersectionPoints.end(); sortedPointIter++)
				{
					sortedIntersectionPoints.push_back(sortedPointIter->second);
				}
			}

			if (!intersections[2].empty())
			{
				map<float, Vector3> sortedEdgeIntersectionPoints;
				getSortedIntersectionPoints(intersections[2], lhsEdge2, sortedEdgeIntersectionPoints);

				for (map<float, Vector3>::iterator sortedPointIter = sortedEdgeIntersectionPoints.begin();
						sortedPointIter != sortedEdgeIntersectionPoints.end(); sortedPointIter++)
				{
					sortedIntersectionPoints.push_back(sortedPointIter->second);
				}
			}

			Vector3 center(0.0f, 0.0f, 0.0f);
			for (Vector3& intersectionPoint : sortedIntersectionPoints)
			{
				center += intersectionPoint;
			}
			center /= static_cast<float>(sortedIntersectionPoints.size());

			Vertex templateVertex = lhsData[lhsTriangleIndex * 3];
			for (unsigned int index = 0; index < sortedIntersectionPoints.size(); index++)
			{
				Vertex vertexA = templateVertex;
				vertexA.position = sortedIntersectionPoints[index];
				newVertices.push_back(vertexA);

				Vertex vertexB = templateVertex;
				if (index < sortedIntersectionPoints.size() - 1)
				{
					vertexB.position = sortedIntersectionPoints[index + 1];
				}
				else
				{
					vertexB.position = sortedIntersectionPoints[0];
				}
				newVertices.push_back(vertexB);

				Vertex vertexC = templateVertex;
				vertexC.position = center;
				newVertices.push_back(vertexC);

				newIndices.push_back(newVertices.size() - 3);
				newIndices.push_back(newVertices.size() - 2);
				newIndices.push_back(newVertices.size() - 1);
			}

			/*
			 * If the current lhs triangle was intersected, move to the next lhs triangle. This implicitly
			 * handles the case where the first lhs triangle was not intersected (by not moving to the next lhs
			 * triangle).
			 */
			if (!intersections[0].empty() || !intersections[1].empty() || !intersections[2].empty())
			{
				lhsTriangleIndex++;
			}

			// Preserve any lhs triangles within the rhs mesh that did not have any intersections.
			while(lhsTriangleIndex < nextLhsTriangleIndex)
			{
				unsigned int vertexIndex = lhsTriangleIndex * 3;

				Triangle lhsTriangle(lhsData[vertexIndex].position, lhsData[vertexIndex + 1].position,
						lhsData[vertexIndex + 2].position);

				if (!Intersection::contains(rhsData, lhsTriangle, inverseRelativeTransform))
				{
					lhsTriangleIndex++;
					continue;
				}

				newVertices.push_back(lhsData[vertexIndex]);
				newVertices.push_back(lhsData[vertexIndex + 1]);
				newVertices.push_back(lhsData[vertexIndex + 2]);

				newIndices.push_back(newVertices.size() - 3);
				newIndices.push_back(newVertices.size() - 2);
				newIndices.push_back(newVertices.size() - 1);

				lhsTriangleIndex++;
			}
		}

		void rotateVertices(vector<Vertex>& vertices, float angle, const Vector3& axis, unsigned int begin,
				unsigned int end)
		{
			rotateVertices(vertices.data(), vertices.size(), angle, axis, begin, end);
		}

		void rotateVertices(Vertex* vertices, unsigned int vertexCount, float angle, const Vector3& axis,
				unsigned int begin, unsigned int end)
		{
			if (end == 0)
			{
				end = vertexCount;
			}

			Matrix33 rotationMatrix;
			rotationMatrix.setIdentity();
			rotate(rotationMatrix, angle, axis);

			for (unsigned int index = begin; index < end; index++)
			{
				//vertex.normal = rotationMatrix * vertex.normal;
				vertices[index].position = rotationMatrix * vertices[index].position;
			}
		}

		void scaleVertices(vector<Vertex>& vertices, float scale, unsigned int begin, unsigned int end)
		{
			scaleVertices(vertices.data(), vertices.size(), scale, begin, end);
		}

		void scaleVertices(Vertex* vertices, unsigned int vertexCount, float scale, unsigned int begin,
				unsigned int end)
		{
			if (end == 0)
			{
				end = vertexCount;
			}

			for (unsigned int index = begin; index < end; index++)
			{
				vertices[index].position *= scale;
			}
		}

		unique_ptr<Mesh> subtract(const Mesh& lhs, const Mesh& rhs, const Matrix44& relativeTransform,
				shared_ptr<MeshBuffer> buffer)
		{
			vector<Vertex> newVertices;
			vector<unsigned int> newIndices;

			// TODO Cannot access multiple meshes at once with glMapBuffer!!! Persistent mapping will help here!
			const MeshData& lhsData = lhs.getData();
			const MeshData& rhsData = rhs.getData();

			// Guesstimate to avoid too much allocations.
			// TODO Why bother with this? Just go direct to the buffer!!!
			newVertices.reserve(lhsData.vertexCount + rhsData.vertexCount);
			newIndices.reserve(lhsData.indexCount + rhsData.indexCount);

			removeIntersection(lhsData, rhsData, newVertices, newIndices, relativeTransform);
			unsigned int removeEnd = newIndices.size();

			Matrix44 inverseRelativeTransform = relativeTransform;
			inverseRelativeTransform.invert();
			retainIntersection(rhsData, lhsData, newVertices, newIndices, inverseRelativeTransform);
			transformVertices(newVertices, relativeTransform, removeEnd);
			flipTriangles(newVertices, newIndices, removeEnd);

			lhs.releaseData();
			rhs.releaseData();

			if (buffer == nullptr)
			{
				buffer = ModelFactory::createMeshBuffer(newVertices.size(), newIndices.size());
			}

			unique_ptr<Mesh> difference(new Mesh(buffer));

			MeshData& differenceData = difference->getData(false);
			differenceData.vertexCount = newVertices.size();
			memcpy(differenceData.vertexData, newVertices.data(), newVertices.size());
			differenceData.indexCount = newIndices.size();
			memcpy(differenceData.indexData, newIndices.data(), newIndices.size());
			difference->releaseData();

			return move(difference);
		}

		void transformVertices(std::vector<Vertex>& vertices, const Matrix44& transformation, unsigned int begin,
				unsigned int end)
		{
			transformVertices(vertices.data(), vertices.size(), transformation, begin, end);
		}

		void transformVertices(Vertex* vertices, unsigned int vertexCount, const Matrix44& transformation,
				unsigned int begin, unsigned int end)
		{
			if (end == 0)
			{
				end = vertexCount;
			}

			for (unsigned int index = begin; index < end; index++)
			{
				vertices[index].position =
						Vector3((transformation * Vector4(vertices[index].position, 1.0f)).getData());
			}
		}

		void translateVertices(vector<Vertex>& vertices, const Vector3& translation, unsigned int begin,
				unsigned int end)
		{
			translateVertices(vertices.data(), vertices.size(), translation, begin, end);
		}

		void translateVertices(Vertex* vertices, unsigned int vertexCount, const Vector3& translation,
				unsigned int begin, unsigned int end)
		{
			if (end == 0)
			{
				end = vertexCount;
			}

			for (unsigned int index = begin; index < end; index++)
			{
				vertices[index].position += translation;
			}
		}
	}
}
