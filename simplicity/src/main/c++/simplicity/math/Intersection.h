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

#include "../model/Line.h"
#include "../model/Mesh.h"
#include "../model/Model.h"
#include "../model/Plane.h"
#include "../model/Point.h"
#include "../model/shape/Circle.h"
#include "../model/shape/Cube.h"
#include "../model/shape/Square.h"
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

		bool contains(const Cube& a, const Cube& b, const Vector3& relativePosition);

		bool contains(const Mesh& mesh, const Point& point, const Matrix44& relativeTransform);

		bool contains(const Mesh& mesh, const Triangle& triangle, const Matrix44& relativeTransform);

		bool contains(const Model& a, const Model& b, const Vector3& relativePosition);

		bool contains(const Square& square, const Circle& circle, const Vector2& relativePosition);

		bool contains(const Square& a, const Square& b, const Vector2& relativePosition);

		bool contains(const Triangle& triangle, const Point& point);

		Vector3 getIntersection(const Line& lineSegment, const Plane& plane);

		Line getIntersection(const Triangle& a, const Triangle& b, const Matrix44& relativeTransform);

		Line getIntersection(const Triangle& a, const Triangle& relativeB, const Vector3& normalA,
				const Vector3& normalB);

		float getIntersectionTime(const Line& lineSegment, const Plane& plane);

		bool intersect(const Circle& a, const Circle& b, const Vector2& relativePosition);

		bool intersect(const Circle& circle, const Square& square, const Vector2& relativePosition);

		bool intersect(const Cube& a, const Cube& b, const Vector3& relativePosition);

		bool intersect(const Line& lineSegment, const Plane& plane);

		bool intersect(const Line& lineSegment, const Triangle& triangle);

		bool intersect(const Model& a, const Model& b, const Vector3& relativePosition);

		RelativePosition intersect(const Plane& plane, const Point& point);

		bool intersect(const Plane& plane, const Triangle& triangle);

		bool intersect(const Square& a, const Square& b, const Vector2& relativePosition);

		bool intersect(const Triangle& a, const Triangle& b, const Matrix44& relativeTransform);

		bool intersect(const Triangle& a, const Triangle& relativeB, const Vector3& normalA, const Vector3& normalB);
	}
}

#endif /* INTERSECTION_H_ */
