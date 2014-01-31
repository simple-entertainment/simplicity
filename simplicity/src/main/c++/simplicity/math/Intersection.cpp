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
#include "MathFunctions.h"
#include "Intersection.h"

using namespace std;

namespace simplicity
{
	namespace Intersection
	{
		RelativePosition intersect(const Plane& plane, const Vector3& point);
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

			if (aMinX > bMaxX || bMinX > aMaxX || aMinY > bMaxY || bMinY > aMaxY)
			{
				return false;
			}

			return true;
		}

		bool sameSide(const Vector3& lineA, const Vector3& lineB, const Vector3& pointA, const Vector3& pointB)
		{
			Vector3 crossProduct0 = crossProduct(lineB - lineA, pointA - lineA);
			Vector3 crossProduct1 = crossProduct(lineB - lineA, pointB - lineA);

			return dotProduct(crossProduct0, crossProduct1) >= 0;
		}
	}
}
