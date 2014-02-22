/*
 * Copyright © 2013 Simple Entertainment Limited
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
#include "Intersection.h"
#include "MathFunctions.h"

using namespace std;

namespace simplicity
{
	namespace Intersection
	{
		RelativePosition intersect(const Plane& plane, const Vector3& point);
		bool intersect(const Triangle& lhs, const Triangle& rhs, const Vector3& normalLhs);
		bool sameSide(const Vector3& lineA, const Vector3& lineB, const Vector3& pointA, const Vector3& pointB);

		bool contains(const Cube& a, const Cube& b, const Vector3& relativePosition)
		{
			float aMaxX = a.getHalfEdgeLength();
			float aMinX = -a.getHalfEdgeLength();
			float aMaxY = a.getHalfEdgeLength();
			float aMinY = -a.getHalfEdgeLength();
			float aMaxZ = a.getHalfEdgeLength();
			float aMinZ = -a.getHalfEdgeLength();

			float bMaxX = relativePosition.X() + b.getHalfEdgeLength();
			float bMinX = relativePosition.X() - b.getHalfEdgeLength();
			float bMaxY = relativePosition.Y() + b.getHalfEdgeLength();
			float bMinY = relativePosition.Y() - b.getHalfEdgeLength();
			float bMaxZ = relativePosition.Z() + b.getHalfEdgeLength();
			float bMinZ = relativePosition.Z() - b.getHalfEdgeLength();

			if (bMaxX <= aMaxX && bMinX >= aMinX &&
				bMaxY <= aMaxY && bMinY >= aMinY &&
				bMaxZ <= aMaxZ && bMinZ >= aMinZ)
			{
				return true;
			}

			return false;
		}

		bool contains(const Model& a, const Model& b, const Vector3& relativePosition)
		{
			const Cube* cubeA = dynamic_cast<const Cube*>(&a);
			if (cubeA != NULL)
			{
				const Cube* cubeB = dynamic_cast<const Cube*>(&b);
				if (cubeB != NULL)
				{
					return contains(*cubeA, *cubeB, relativePosition);
				}
			}

			const Square* squareA = dynamic_cast<const Square*>(&a);
			if (squareA != NULL)
			{
				const Circle* circleB = dynamic_cast<const Circle*>(&b);
				if (circleB != NULL)
				{
					Vector2 relativePosition2(relativePosition.X(), relativePosition.Y());
					return contains(*squareA, *circleB, relativePosition2);
				}

				const Square* squareB = dynamic_cast<const Square*>(&b);
				if (squareB != NULL)
				{
					Vector2 relativePosition2(relativePosition.X(), relativePosition.Y());
					return contains(*squareA, *squareB, relativePosition2);
				}
			}

			return false;
		}

		bool contains(const Mesh& mesh, const Point& point, const Matrix44& relativeTransform)
		{
			const vector<unsigned int>& indices = mesh.getIndices();
			const vector<Vertex>& vertices = mesh.getVertices();
			for (unsigned int index = 0; index < indices.size(); index += 3)
			{
				Vector3 edge0 = vertices[indices[index + 1]].position - vertices[indices[index]].position;
				Vector3 edge1 = vertices[indices[index + 2]].position - vertices[indices[index]].position;

				Vector3 normal = crossProduct(edge0, edge1);
				Plane plane(normal, vertices[indices[index]].position);

				Vector3 pointVector((relativeTransform * Vector4(point.getPoint(), 1.0f)).getData());

				if (intersect(plane, pointVector) == RelativePosition::INFRONT)
				{
					return false;
				}
			}

			return true;
		}

		bool contains(const Mesh& mesh, const Triangle& triangle, const Matrix44& relativeTransform)
		{
			const vector<unsigned int>& indices = mesh.getIndices();
			const vector<Vertex>& vertices = mesh.getVertices();
			for (unsigned int index = 0; index < indices.size(); index += 3)
			{
				Vector3 edge0 = vertices[indices[index + 1]].position - vertices[indices[index]].position;
				Vector3 edge1 = vertices[indices[index + 2]].position - vertices[indices[index]].position;

				Vector3 normal = crossProduct(edge0, edge1);
				Plane plane(normal, vertices[indices[index]].position);

				Vector3 pointA((relativeTransform * Vector4(triangle.getPointA(), 1.0f)).getData());
				Vector3 pointB((relativeTransform * Vector4(triangle.getPointB(), 1.0f)).getData());
				Vector3 pointC((relativeTransform * Vector4(triangle.getPointC(), 1.0f)).getData());

				if (intersect(plane, pointA) == RelativePosition::INFRONT ||
						intersect(plane, pointB) == RelativePosition::INFRONT ||
						intersect(plane, pointC) == RelativePosition::INFRONT)
				{
					return false;
				}
			}

			return true;
		}

		bool contains(const Square& square, const Circle& circle, const Vector2& relativePosition)
		{
			float squareMaxX = square.getHalfEdgeLength();
			float squareMinX = -square.getHalfEdgeLength();
			float squareMaxY = square.getHalfEdgeLength();
			float squareMinY = -square.getHalfEdgeLength();

			float circleMaxX = relativePosition.X() + circle.getRadius();
			float circleMinX = relativePosition.X() - circle.getRadius();
			float circleMaxY = relativePosition.Y() + circle.getRadius();
			float circleMinY = relativePosition.Y() - circle.getRadius();

			if (circleMaxX <= squareMaxX && circleMinX >= squareMinX &&
				circleMaxY <= squareMaxY && circleMinY >= squareMinY)
			{
				return true;
			}

			return false;
		}

		bool contains(const Square& a, const Square& b, const Vector2& relativePosition)
		{
			float aMaxX = a.getHalfEdgeLength();
			float aMinX = -a.getHalfEdgeLength();
			float aMaxY = a.getHalfEdgeLength();
			float aMinY = -a.getHalfEdgeLength();

			float bMaxX = relativePosition.X() + b.getHalfEdgeLength();
			float bMinX = relativePosition.X() - b.getHalfEdgeLength();
			float bMaxY = relativePosition.Y() + b.getHalfEdgeLength();
			float bMinY = relativePosition.Y() - b.getHalfEdgeLength();

			if (bMaxX <= aMaxX && bMinX >= aMinX &&
				bMaxY <= aMaxY && bMinY >= aMinY)
			{
				return true;
			}

			return false;
		}

		bool contains(const Triangle& triangle, const Point& point)
		{
			if (!sameSide(triangle.getPointA(), triangle.getPointB(), point.getPoint(), triangle.getPointC()))
			{
				return false;
			}

			if (!sameSide(triangle.getPointB(), triangle.getPointC(), point.getPoint(), triangle.getPointA()))
			{
				return false;
			}

			return sameSide(triangle.getPointC(), triangle.getPointA(), point.getPoint(), triangle.getPointB());
		}

		Vector3 getIntersection(const Line& lineSegment, const Plane& plane)
		{
			Vector3 toPointB = lineSegment.getPointB() - lineSegment.getPointA();

			float d = dotProduct((plane.getPositionOnPlane() - lineSegment.getPointA()), plane.getNormal()) /
					dotProduct(toPointB, plane.getNormal());

			return toPointB * d + lineSegment.getPointA();
		}

		Line getIntersection(const Triangle& a, const Triangle& b, const Matrix44& relativeTransform)
		{
			Vector3 edgeA0 = a.getPointB() - a.getPointA();
			Vector3 edgeA1 = a.getPointC() - a.getPointA();
			Vector3 normalA = crossProduct(edgeA0, edgeA1);

			Vector3 pointBA((Vector4(b.getPointA(), 1.0f) * relativeTransform).getData());
			Vector3 pointBB((Vector4(b.getPointB(), 1.0f) * relativeTransform).getData());
			Vector3 pointBC((Vector4(b.getPointC(), 1.0f) * relativeTransform).getData());
			Triangle relativeB(pointBA, pointBB, pointBC);

			Vector3 edgeB0 = relativeB.getPointB() - relativeB.getPointA();
			Vector3 edgeB1 = relativeB.getPointC() - relativeB.getPointA();
			Vector3 normalB = crossProduct(edgeB0, edgeB1);

			return getIntersection(a, relativeB, normalA, normalB);
		}

		Line getIntersection(const Triangle& a, const Triangle& relativeB, const Vector3& normalA,
				const Vector3& normalB)
		{
			Plane planeA(normalA, a.getPointA());

			RelativePosition relativeBA = intersect(planeA, relativeB.getPointA());
			RelativePosition relativeBB = intersect(planeA, relativeB.getPointB());
			RelativePosition relativeBC = intersect(planeA, relativeB.getPointC());

			// If all the vertices of triangle B are on the same side of the plane of triangle A, there is no
			// intersection.
			if (relativeBA == relativeBB && relativeBB == relativeBC)
			{
				// No intersection!
			}

			Plane planeB(normalB, relativeB.getPointA());

			RelativePosition relativeAA = intersect(planeB, a.getPointA());
			RelativePosition relativeAB = intersect(planeB, a.getPointB());
			RelativePosition relativeAC = intersect(planeB, a.getPointC());

			// If all the vertices of triangle A are on the same side of the plane of triangle B, there is no
			// intersection.
			if (relativeAA == relativeAB && relativeAB == relativeAC)
			{
				// No intersection!
			}

			// Retrieve all the points where the edges of the triangles intersect the plane of the other triangle.
			Vector3 intersectionPoints[4];
			unsigned int pointIndex = 0;
			if (relativeAA != relativeAB)
			{
				intersectionPoints[pointIndex++] = getIntersection(Line(a.getPointA(), a.getPointB()), planeB);
			}
			if (relativeAB != relativeAC)
			{
				intersectionPoints[pointIndex++] = getIntersection(Line(a.getPointB(), a.getPointC()), planeB);
			}
			if (relativeAC != relativeAA)
			{
				intersectionPoints[pointIndex++] = getIntersection(Line(a.getPointC(), a.getPointA()), planeB);
			}
			if (relativeBA != relativeBB)
			{
				intersectionPoints[pointIndex++] =
						getIntersection(Line(relativeB.getPointA(), relativeB.getPointB()), planeA);
			}
			if (relativeBB != relativeBC)
			{
				intersectionPoints[pointIndex++] =
						getIntersection(Line(relativeB.getPointB(), relativeB.getPointC()), planeA);
			}
			if (relativeBC != relativeBA)
			{
				intersectionPoints[pointIndex++] =
						getIntersection(Line(relativeB.getPointC(), relativeB.getPointA()), planeA);
			}

			/*
			 * Solve the equation of a line:
			 *     P = P0 + Dt
			 * Where:
			 *     P0 is any point on the line.
			 *     D is the direction vector of the line.
			 * Reference:
			 *     http://en.wikipedia.org/wiki/Linear_equation#Parametric_form
			 *
			 * Rearrange to solve for t:
			 *     t = (P - P0) / D
			 *
			 * This isn't going to work because we need a scalar result... luckily we can just use one dimension:
			 *     t = (Px - P0x) / Dx
			 */
			Vector3 D = intersectionPoints[1] - intersectionPoints[0];
			D.normalize();
			// Avoid a divide by zero :)
			unsigned int axis = 0;
			if (D.X() != 0.0f)
			{
				axis = 0;
			}
			else if (D.Y() != 0.0f)
			{
				axis = 1;
			}
			else
			{
				axis = 2;
			}
			float maxT;
			float minT;
			float t[4];
			for (pointIndex = 0; pointIndex < 4; pointIndex++)
			{
				t[pointIndex] = (intersectionPoints[pointIndex][axis] - intersectionPoints[0][axis]) / D[axis];

				if (pointIndex == 0 || t[pointIndex] > maxT)
				{
					maxT = t[pointIndex];
				}
				if (pointIndex == 0 || t[pointIndex] < minT)
				{
					minT = t[pointIndex];
				}
			}

			/**
			 * Now that we have t for all the intersection points, we want to keep only the two points that are not the
			 * max or min. That will leave us with the two 'inside' points on our line i.e. the intersection!
			 */
			Vector3 linePoints[2];
			unsigned int linePointIndex = 0;
			bool maxTSkipped = false;
			bool minTSkipped = false;
			for (pointIndex = 0; pointIndex < 4; pointIndex++)
			{
				if (!maxTSkipped && t[pointIndex] == maxT)
				{
					maxTSkipped = true;
					continue;
				}

				if (!minTSkipped && t[pointIndex] == minT)
				{
					minTSkipped = true;
					continue;
				}

				linePoints[linePointIndex++] = intersectionPoints[pointIndex];
			}

			return Line(linePoints[0], linePoints[1]);
		}

		float getIntersectionTime(const Line& lineSegment, const Plane& plane)
		{
			return dotProduct(plane.getNormal(), plane.getPositionOnPlane() - lineSegment.getPointA()) /
				dotProduct(plane.getNormal(), lineSegment.getPointB() - lineSegment.getPointA());
		}

		bool intersect(const Circle& a, const Circle& b, const Vector2& relativePosition)
		{
			return relativePosition.getMagnitude() < a.getRadius() + b.getRadius();
		}

		bool intersect(const Circle& circle, const Square& square, const Vector2& relativePosition)
		{
			float circleMaxX = relativePosition.X() + circle.getRadius();
			float circleMinX = relativePosition.X() - circle.getRadius();
			float circleMaxY = relativePosition.Y() + circle.getRadius();
			float circleMinY = relativePosition.Y() - circle.getRadius();

			float squareMaxX = square.getHalfEdgeLength();
			float squareMinX = -square.getHalfEdgeLength();
			float squareMaxY = square.getHalfEdgeLength();
			float squareMinY = -square.getHalfEdgeLength();

			if ((circleMaxX <= squareMaxX && circleMaxX >= squareMinX) ||
				(circleMinX <= squareMaxX && circleMinX >= squareMinX))
			{
				if ((circleMaxY <= squareMaxY && circleMaxY >= squareMinY) ||
					(circleMinY <= squareMaxY && circleMinY >= squareMinY))
				{
					return true;
				}
			}

			return false;
		}

		bool intersect(const Cube& a, const Cube& b, const Vector3& relativePosition)
		{
			float aMaxX = a.getHalfEdgeLength();
			float aMinX = -a.getHalfEdgeLength();
			float aMaxY = a.getHalfEdgeLength();
			float aMinY = -a.getHalfEdgeLength();
			float aMaxZ = a.getHalfEdgeLength();
			float aMinZ = -a.getHalfEdgeLength();

			float bMaxX = relativePosition.X() + b.getHalfEdgeLength();
			float bMinX = relativePosition.X() - b.getHalfEdgeLength();
			float bMaxY = relativePosition.Y() + b.getHalfEdgeLength();
			float bMinY = relativePosition.Y() - b.getHalfEdgeLength();
			float bMaxZ = relativePosition.Z() + b.getHalfEdgeLength();
			float bMinZ = relativePosition.Z() - b.getHalfEdgeLength();

			if (aMinX > bMaxX || bMinX > aMaxX || aMinY > bMaxY || bMinY > aMaxY || aMinZ > bMaxZ || bMinZ > aMaxZ)
			{
				return false;
			}

			return true;
		}

		bool intersect(const Line& lineSegment, const Plane& plane)
		{
			RelativePosition startPosition = intersect(plane, lineSegment.getPointA());
			RelativePosition finishPosition = intersect(plane, lineSegment.getPointB());

			if ((startPosition == BEHIND && finishPosition == INFRONT) ||
				(startPosition == INFRONT && finishPosition == BEHIND) ||
				startPosition == ON_PLANE ||
				finishPosition == ON_PLANE)
			{
				return true;
			}

			return false;
		}

		bool intersect(const Line& lineSegment, const Triangle& triangle)
		{
			Vector3 edge0 = triangle.getPointB() - triangle.getPointA();
			Vector3 edge1 = triangle.getPointC() - triangle.getPointA();
			Vector3 normal = crossProduct(edge0, edge1);
			Plane plane(normal, triangle.getPointA());

			if (intersect(lineSegment, plane))
			{
				if (contains(triangle, getIntersection(lineSegment, plane)))
				{
					return true;
				}
			}

			return false;
		}

		bool intersect(const Model& a, const Model& b, const Vector3& relativePosition)
		{
			const Circle* circleA = dynamic_cast<const Circle*>(&a);
			if (circleA != NULL)
			{
				const Circle* circleB = dynamic_cast<const Circle*>(&b);
				if (circleB != NULL)
				{
					Vector2 relativePosition2(relativePosition.X(), relativePosition.Y());
					return intersect(*circleA, *circleB, relativePosition2);
				}

				const Square* squareB = dynamic_cast<const Square*>(&b);
				if (squareB != NULL)
				{
					Vector2 relativePosition2(relativePosition.X(), relativePosition.Y());
					return intersect(*circleA, *squareB, relativePosition2);
				}
			}

			const Cube* cubeA = dynamic_cast<const Cube*>(&a);
			if (cubeA != NULL)
			{
				const Cube* cubeB = dynamic_cast<const Cube*>(&b);
				if (cubeB != NULL)
				{
					return intersect(*cubeA, *cubeB, relativePosition);
				}
			}

			const Square* squareA = dynamic_cast<const Square*>(&a);
			if (squareA != NULL)
			{
				const Circle* circleB = dynamic_cast<const Circle*>(&b);
				if (circleB != NULL)
				{
					Vector2 relativePosition2(relativePosition.X(), relativePosition.Y());
					return intersect(*circleB, *squareA, relativePosition2);
				}

				const Square* squareB = dynamic_cast<const Square*>(&b);
				if (squareB != NULL)
				{
					Vector2 relativePosition2(relativePosition.X(), relativePosition.Y());
					return intersect(*squareA, *squareB, relativePosition2);
				}
			}

			return false;
		}

		bool intersect(const Plane& plane, const Triangle& triangle)
		{
			/*if (intersect(plane, triangle[0], triangle[1]))
			{
				return true;
			}

			if (intersect(plane, triangle[1], triangle[2]))
			{
				return true;
			}

			if (intersect(plane, triangle[2], triangle[0]))
			{
				return true;
			}*/

			return false;
		}

		RelativePosition intersect(const Plane& plane, const Point& point)
		{
			return intersect(plane, point.getPoint());
		}

		RelativePosition intersect(const Plane& plane, const Vector3& point)
		{
			float referenceDistance = dotProduct(plane.getNormal(), plane.getPositionOnPlane());
			float distance = dotProduct(plane.getNormal(), point) - referenceDistance;

			if (distance < 0.0f)
			{
				return BEHIND;
			}
			else if (distance > 0.0f)
			{
				return INFRONT;
			}
			else
			{
				return ON_PLANE;
			}
		}

		bool intersect(const Square& a, const Square& b, const Vector2& relativePosition)
		{
			float aMaxX = a.getHalfEdgeLength();
			float aMinX = -a.getHalfEdgeLength();
			float aMaxY = a.getHalfEdgeLength();
			float aMinY = -a.getHalfEdgeLength();

			float bMaxX = relativePosition.X() + b.getHalfEdgeLength();
			float bMinX = relativePosition.X() - b.getHalfEdgeLength();
			float bMaxY = relativePosition.Y() + b.getHalfEdgeLength();
			float bMinY = relativePosition.Y() - b.getHalfEdgeLength();

			if (aMinX < bMaxX && bMinX < aMaxX && aMinY < bMaxY && bMinY < aMaxY)
			{
				return true;
			}

			return false;
		}

		bool intersect(const Triangle& lhs, const Triangle& rhs, const Vector3& normalLhs)
		{
			Plane planeA(normalLhs, lhs.getPointA());

			Line lineRhsAB(rhs.getPointA(), rhs.getPointB());
			if (intersect(lineRhsAB, planeA))
			{
				if (contains(lhs, getIntersection(lineRhsAB, planeA)))
				{
					return true;
				}
			}

			Line lineRhsBC(rhs.getPointB(), rhs.getPointC());
			if (intersect(lineRhsBC, planeA))
			{
				if (contains(lhs, getIntersection(lineRhsBC, planeA)))
				{
					return true;
				}
			}

			Line lineRhsCA(rhs.getPointC(), rhs.getPointA());
			if (intersect(lineRhsCA, planeA))
			{
				if (contains(lhs, getIntersection(lineRhsCA, planeA)))
				{
					return true;
				}
			}

			return false;
		}

		bool intersect(const Triangle& a, const Triangle& b, const Matrix44& relativeTransform)
		{
			Vector3 pointBA((Vector4(b.getPointA(), 1.0f) * relativeTransform).getData());
			Vector3 pointBB((Vector4(b.getPointB(), 1.0f) * relativeTransform).getData());
			Vector3 pointBC((Vector4(b.getPointC(), 1.0f) * relativeTransform).getData());
			Triangle relativeB(pointBA, pointBC, pointBC);

			Vector3 edgeA0 = a.getPointB() - a.getPointA();
			Vector3 edgeA1 = a.getPointC() - a.getPointA();
			Vector3 normalA = crossProduct(edgeA0, edgeA1);

			if (intersect(a, relativeB, normalA))
			{
				return true;
			}

			Vector3 edgeB0 = pointBB - pointBA;
			Vector3 edgeB1 = pointBC - pointBA;
			Vector3 normalB = crossProduct(edgeB0, edgeB1);

			if (intersect(relativeB, a, normalB))
			{
				return true;
			}

			return false;
		}

		bool intersect(const Triangle& a, const Triangle& relativeB, const Vector3& normalA, const Vector3& normalB)
		{
			return intersect(a, relativeB, normalA) || intersect(relativeB, a, normalB);
		}

		bool sameSide(const Vector3& lineA, const Vector3& lineB, const Vector3& pointA, const Vector3& pointB)
		{
			Vector3 crossProduct0 = crossProduct(lineB - lineA, pointA - lineA);
			Vector3 crossProduct1 = crossProduct(lineB - lineA, pointB - lineA);

			return dotProduct(crossProduct0, crossProduct1) >= 0;
		}
	}
}
