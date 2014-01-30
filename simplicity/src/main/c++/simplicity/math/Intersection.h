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
#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include <vector>

#include "../graph/AABB2.h"
#include "../model/Line.h"
#include "../model/Plane.h"
#include "../model/Point.h"
#include "../model/shape/Circle.h"
#include "../model/shape/Triangle.h"

namespace simplicity
{
	namespace Intersection
	{
		enum RelativePosition
		{
			BEHIND,
			INFRONT,
			ON_PLANE
		};

		bool contains(const AABB2& aabb, const Circle& circle, const Vector2& circlePosition);

		bool contains(const Triangle& triangle, const Point& point);

		float getIntersectionTime(const Line& lineSegment, const Plane& plane);

		bool intersect(const AABB2& a, const AABB2& b);

		bool intersect(const AABB2& aabb, const Circle& circle, const Vector2& circlePosition);

		bool intersect(const Circle& a, const Vector2& positionA, const Circle& b, const Vector2& positionB);

		bool intersect(const Line& lineSegment, const Plane& plane);

		bool intersect(const Model& a, const Model& b);

		bool intersect(const Plane& plane, const Triangle& triangle);

		RelativePosition intersect(const Plane& plane, const Point& point);
	}
}

#endif /* INTERSECTION_H_ */
