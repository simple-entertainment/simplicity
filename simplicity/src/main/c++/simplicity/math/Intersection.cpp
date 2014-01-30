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

		bool contains(const AABB2& aabb, const Circle& circle, const Vector2& circlePosition)
		{
			float aabbMaxX = aabb.center.X() + aabb.halfDimension;
			float aabbMinX = aabb.center.X() - aabb.halfDimension;
			float aabbMaxY = aabb.center.Y() + aabb.halfDimension;
			float aabbMinY = aabb.center.Y() - aabb.halfDimension;

			float circleMaxX = circlePosition.X() + circle.getRadius();
			float circleMinX = circlePosition.X() - circle.getRadius();
			float circleMaxY = circlePosition.Y() + circle.getRadius();
			float circleMinY = circlePosition.Y() - circle.getRadius();

			if (circleMaxX <= aabbMaxX && circleMinX >= aabbMinX &&
				circleMaxY <= aabbMaxY && circleMinY >= aabbMinY)
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

		bool intersect(const AABB2& a, const AABB2& b)
		{
			float aMaxX = a.center.X() + a.halfDimension;
			float aMinX = a.center.X() - a.halfDimension;
			float aMaxY = a.center.Y() + a.halfDimension;
			float aMinY = a.center.Y() - a.halfDimension;

			float bMaxX = b.center.X() + b.halfDimension;
			float bMinX = b.center.X() - b.halfDimension;
			float bMaxY = b.center.Y() + b.halfDimension;
			float bMinY = b.center.Y() - b.halfDimension;

			if (aMinX > bMaxX || bMinX > aMaxX || aMinY > bMaxY || bMinY > aMaxY)
			{
				return false;
			}
		
			return true;
		}

		bool intersect(const AABB2& aabb, const Circle& circle, const Vector2& circlePosition)
		{
			float aabbMaxX = aabb.center.X() + aabb.halfDimension;
			float aabbMinX = aabb.center.X() - aabb.halfDimension;
			float aabbMaxY = aabb.center.Y() + aabb.halfDimension;
			float aabbMinY = aabb.center.Y() - aabb.halfDimension;

			float circleMaxX = circlePosition.X() + circle.getRadius();
			float circleMinX = circlePosition.X() - circle.getRadius();
			float circleMaxY = circlePosition.Y() + circle.getRadius();
			float circleMinY = circlePosition.Y() - circle.getRadius();

			if ((circleMaxX <= aabbMaxX && circleMaxX >= aabbMinX) ||
				(circleMinX <= aabbMaxX && circleMinX >= aabbMinX))
			{
				if ((circleMaxY <= aabbMaxY && circleMaxY >= aabbMinY) ||
					(circleMinY <= aabbMaxY && circleMinY >= aabbMinY))
				{
					return true;
				}
			}

			return false;
		}

		bool intersect(const Circle& a, const Vector2& positionA, const Circle& b, const Vector2& positionB)
		{
			return (positionA - positionB).getMagnitude() < a.getRadius() + b.getRadius();
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

		bool intersect(const Model& a, const Model& b)
		{
			const Circle* circleA = dynamic_cast<const Circle*>(&a);
			if (circleA != NULL)
			{
				const Circle* circleB = dynamic_cast<const Circle*>(&b);
				if (circleB != NULL)
				{
					return intersect(*circleA, *circleB);
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

		bool sameSide(const Vector3& lineA, const Vector3& lineB, const Vector3& pointA, const Vector3& pointB)
		{
			Vector3 crossProduct0 = MathFunctions::crossProduct(lineB - lineA, pointA - lineA);
			Vector3 crossProduct1 = MathFunctions::crossProduct(lineB - lineA, pointB - lineA);

			return dotProduct(crossProduct0, crossProduct1) >= 0;
		}
	}
}
