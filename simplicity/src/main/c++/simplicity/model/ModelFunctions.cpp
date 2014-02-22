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

		vector<MeshIntersection> getIntersections(const Mesh& lhs, const Mesh& rhs, const Matrix44& relativeTransform);

		void getSortedPoints(const vector<MeshIntersection>& intersections, const Line& lhsEdge,
				map<float, Vector3>& sortedIntersectionPoints, map<float, Vector3>& sortedEdgePoints);

		void removeIntersection(const Mesh& lhs, const Mesh& rhs, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Matrix44& relativeTransform);

		void removeIntersection(const Mesh& lhs, vector<Vertex>& newVertices, vector<unsigned int>& newIndices,
				const Triangle& lhsTriangle, unsigned int lhsTriangleIndex, unsigned int nextLhsTriangleIndex,
				const vector<MeshIntersection>* currentIntersections, bool* currentIntersectionsAtEdge,
				const Vertex& templateVertex);

		/*
		 * TODO Instead of using a 'template' vertex we should really be interpolating the normal, color and texture
		 * coordinates from the original vertices of the lhs triangle.
		 */
		void removeIntersection(vector<Vertex>& vertices, vector<unsigned int>& indices,
				const vector<MeshIntersection>& intersections, const Line& lhsEdge, const Vertex& templateVertex,
				bool intersectionAtEdge);

		void retainIntersection(const Mesh& lhs, const Mesh& rhs, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Matrix44& relativeTransform);

		void retainIntersection(const Mesh& lhs, vector<Vertex>& newVertices, vector<unsigned int>& newIndices,
				const Triangle& lhsTriangle, unsigned int lhsTriangleIndex, unsigned int nextLhsTriangleIndex,
				const vector<MeshIntersection>* currentIntersections, bool* currentIntersectionsAtEdge,
				const Vertex& templateVertex);

		/*
		 * TODO Instead of using a 'template' vertex we should really be interpolating the normal, color and texture
		 * coordinates from the original vertices of the lhs triangle.
		 */
		void retainIntersection(vector<Vertex>& vertices, vector<unsigned int>& indices,
				const vector<MeshIntersection>& intersections, const Line& lhsEdge, const Vertex& templateVertex,
				bool intersectionAtEdge);

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

		vector<MeshIntersection> getIntersections(const Mesh& lhs, const Mesh& rhs, const Matrix44& relativeTransform)
		{
			vector<MeshIntersection> intersections;

			Matrix44 inverseRelativeTransform = relativeTransform;
			inverseRelativeTransform.invert();

			for (unsigned int lhsIndex = 0; lhsIndex < lhs.getIndices().size(); lhsIndex += 3)
			{
				Triangle lhsTriangle(lhs.getVertices()[lhs.getIndices()[lhsIndex]].position,
						lhs.getVertices()[lhs.getIndices()[lhsIndex + 1]].position,
						lhs.getVertices()[lhs.getIndices()[lhsIndex + 2]].position);

				// If the lhs triangle is contained within the rhs mesh, no intersections!
				if (Intersection::contains(rhs, Point(lhsTriangle.getPointA()), inverseRelativeTransform))
				{
					if (Intersection::contains(rhs, Point(lhsTriangle.getPointB()), inverseRelativeTransform))
					{
						if (Intersection::contains(rhs, Point(lhsTriangle.getPointC()), inverseRelativeTransform))
						{
							continue;
						}
					}
				}

				Vector3 lhsEdge0 = lhsTriangle.getPointB() - lhsTriangle.getPointA();
				Vector3 lhsEdge1 = lhsTriangle.getPointC() - lhsTriangle.getPointA();
				Vector3 lhsNormal = crossProduct(lhsEdge0, lhsEdge1);
				lhsNormal.normalize();

				for (unsigned int rhsIndex = 0; rhsIndex < rhs.getIndices().size(); rhsIndex += 3)
				{
					Vector3 rhsPointA((relativeTransform *
							Vector4(rhs.getVertices()[rhs.getIndices()[rhsIndex]].position, 1.0f)).getData());
					Vector3 rhsPointB((relativeTransform *
							Vector4(rhs.getVertices()[rhs.getIndices()[rhsIndex + 1]].position, 1.0f)).getData());
					Vector3 rhsPointC((relativeTransform *
							Vector4(rhs.getVertices()[rhs.getIndices()[rhsIndex + 2]].position, 1.0f)).getData());
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
		 * Project the intersection points onto the corresponding edge and sort them based on how far along the
		 * edge they are. Also, find the points on the edge half way between the projected points and sort them
		 * based on how far along the edge they are.
		 */
		void getSortedPoints(const vector<MeshIntersection>& intersections, const Line& lhsEdge,
				map<float, Vector3>& sortedIntersectionPoints, map<float, Vector3>& sortedEdgePoints)
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

		void removeIntersection(const Mesh& lhs, const Mesh& rhs, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Matrix44& relativeTransform)
		{
			vector<MeshIntersection> intersections = getIntersections(lhs, rhs, relativeTransform);
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
					Vertex templateVertex = lhs.getVertices()[lhs.getIndices()[lhsTriangleIndex * 3]];
					removeIntersection(lhs, newVertices, newIndices, lhsTriangle, lhsTriangleIndex,
							intersection.lhsTriangleIndex, currentIntersections, currentIntersectionsAtEdge,
							templateVertex);

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

			Vertex templateVertex = lhs.getVertices()[lhs.getIndices()[lhsTriangleIndex * 3]];
			removeIntersection(lhs, newVertices, newIndices, lhsTriangle, lhsTriangleIndex,
					lhs.getIndices().size() / 3, currentIntersections, currentIntersectionsAtEdge, templateVertex);
		}

		void removeIntersection(const Mesh& lhs, vector<Vertex>& newVertices, vector<unsigned int>& newIndices,
				const Triangle& lhsTriangle, unsigned int lhsTriangleIndex, unsigned int nextLhsTriangleIndex,
				const vector<MeshIntersection>* currentIntersections, bool* currentIntersectionsAtEdge,
				const Vertex& templateVertex)
		{
			Line lhsEdge0(lhsTriangle.getPointA(), lhsTriangle.getPointB());
			Line lhsEdge1(lhsTriangle.getPointB(), lhsTriangle.getPointC());
			Line lhsEdge2(lhsTriangle.getPointC(), lhsTriangle.getPointA());

			if (!currentIntersections[0].empty())
			{
				removeIntersection(newVertices, newIndices, currentIntersections[0], lhsEdge0, templateVertex,
						currentIntersectionsAtEdge[0]);
			}
			if (!currentIntersections[1].empty())
			{
				removeIntersection(newVertices, newIndices, currentIntersections[1], lhsEdge1, templateVertex,
						currentIntersectionsAtEdge[1]);
			}
			if (!currentIntersections[2].empty())
			{
				removeIntersection(newVertices, newIndices, currentIntersections[2], lhsEdge2, templateVertex,
						currentIntersectionsAtEdge[2]);
			}

			/*
			 * If the current lhs triangle was intersected, move to the next lhs triangle. This implicitly
			 * handles the case where the first lhs triangle was not intersected (by not moving to the next lhs
			 * triangle).
			 */
			if (!currentIntersections[0].empty() ||
					!currentIntersections[1].empty() ||
					!currentIntersections[2].empty())
			{
				lhsTriangleIndex++;
			}

			// Preserve any lhs triangles that did not have any intersections.
			while(lhsTriangleIndex < nextLhsTriangleIndex)
			{
				unsigned int vertexIndex = lhsTriangleIndex * 3;

				newVertices.push_back(lhs.getVertices()[lhs.getIndices()[vertexIndex]]);
				newVertices.push_back(lhs.getVertices()[lhs.getIndices()[vertexIndex + 1]]);
				newVertices.push_back(lhs.getVertices()[lhs.getIndices()[vertexIndex + 2]]);

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

		void retainIntersection(const Mesh& lhs, const Mesh& rhs, vector<Vertex>& newVertices,
				vector<unsigned int>& newIndices, const Matrix44& relativeTransform)
		{
			vector<MeshIntersection> intersections = getIntersections(lhs, rhs, relativeTransform);
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
					Vertex templateVertex = lhs.getVertices()[lhs.getIndices()[lhsTriangleIndex * 3]];
					retainIntersection(lhs, newVertices, newIndices, lhsTriangle, lhsTriangleIndex,
							intersection.lhsTriangleIndex, currentIntersections, currentIntersectionsAtEdge,
							templateVertex);

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

			Vertex templateVertex = lhs.getVertices()[lhs.getIndices()[lhsTriangleIndex * 3]];
			retainIntersection(lhs, newVertices, newIndices, lhsTriangle, lhsTriangleIndex,
					lhs.getIndices().size() / 3, currentIntersections, currentIntersectionsAtEdge, templateVertex);
		}

		void retainIntersection(const Mesh& lhs, vector<Vertex>& newVertices, vector<unsigned int>& newIndices,
				const Triangle& lhsTriangle, unsigned int lhsTriangleIndex, unsigned int nextLhsTriangleIndex,
				const vector<MeshIntersection>* currentIntersections, bool* currentIntersectionsAtEdge,
				const Vertex& templateVertex)
		{
			Line lhsEdge0(lhsTriangle.getPointA(), lhsTriangle.getPointB());
			Line lhsEdge1(lhsTriangle.getPointB(), lhsTriangle.getPointC());
			Line lhsEdge2(lhsTriangle.getPointC(), lhsTriangle.getPointA());

			if (!currentIntersections[0].empty())
			{
				retainIntersection(newVertices, newIndices, currentIntersections[0], lhsEdge0, templateVertex,
						currentIntersectionsAtEdge[0]);
			}
			if (!currentIntersections[1].empty())
			{
				retainIntersection(newVertices, newIndices, currentIntersections[1], lhsEdge1, templateVertex,
						currentIntersectionsAtEdge[1]);
			}
			if (!currentIntersections[2].empty())
			{
				retainIntersection(newVertices, newIndices, currentIntersections[2], lhsEdge2, templateVertex,
						currentIntersectionsAtEdge[2]);
			}

			/*
			 * If the current lhs triangle was intersected, move to the next lhs triangle. This implicitly
			 * handles the case where the first lhs triangle was not intersected (by not moving to the next lhs
			 * triangle).
			 */
			if (!currentIntersections[0].empty() ||
					!currentIntersections[1].empty() ||
					!currentIntersections[2].empty())
			{
				lhsTriangleIndex++;
			}

			// Preserve any lhs triangles that did not have any intersections.
			while(lhsTriangleIndex < nextLhsTriangleIndex)
			{
				unsigned int vertexIndex = lhsTriangleIndex * 3;

				newVertices.push_back(lhs.getVertices()[lhs.getIndices()[vertexIndex]]);
				newVertices.push_back(lhs.getVertices()[lhs.getIndices()[vertexIndex + 1]]);
				newVertices.push_back(lhs.getVertices()[lhs.getIndices()[vertexIndex + 2]]);

				newIndices.push_back(newVertices.size() - 3);
				newIndices.push_back(newVertices.size() - 2);
				newIndices.push_back(newVertices.size() - 1);

				lhsTriangleIndex++;
			}
		}

		void retainIntersection(vector<Vertex>& vertices, vector<unsigned int>& indices,
				const vector<MeshIntersection>& intersections, const Line& lhsEdge, const Vertex& templateVertex,
				bool intersectionAtEdge)
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
			vector<unsigned int> newIndices;

			// Guesstimate to avoid too much allocations.
			newVertices.reserve(lhs.getVertices().size() + rhs.getVertices().size());
			newIndices.reserve(lhs.getIndices().size() + rhs.getIndices().size());

			removeIntersection(lhs, rhs, newVertices, newIndices, relativeTransform);

			Matrix44 inverseRelativeTransform = relativeTransform;
			inverseRelativeTransform.invert();
			//retainIntersection(rhs, lhs, newVertices, newIndices, inverseRelativeTransform);

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
