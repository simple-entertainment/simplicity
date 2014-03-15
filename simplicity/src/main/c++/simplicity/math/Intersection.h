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
		/**
		 * <p>
		 * The relative position of a point in relation to a plane.
		 * </p>
		 */
		enum RelativePosition
		{
			/**
			 * <p>
			 * The point is behind of the plane.
			 * </p>
			 */
			BEHIND,

			/**
			 * <p>
			 * The point is in front of the plane.
			 * </p>
			 */

			INFRONT,
			/**
			 * <p>
			 * The point is on the plane.
			 * </p>
			 */
			ON_PLANE
		};

		/**
		 * <p>
		 * Determines if cube a contains cube b.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param a The container.
		 * @param b The containee.
		 * @param relativePosition The position of b relative to a.
		 *
		 * @return True if cube a contains cube b, false otherwise.
		 */
		bool contains(const Cube& a, const Cube& b, const Vector3& relativePosition);

		/**
		 * <p>
		 * Determines if a mesh contains a point.
		 * </p>
		 *
		 * @param mesh The container.
		 * @param point The containee.
		 * @param relativeTransform The position and orientation of the point relative to the mesh.
		 *
		 * @return True if the mesh contains the point, false otherwise.
		 */
		bool contains(const Mesh& mesh, const Point& point, const Matrix44& relativeTransform);

		/**
		 * <p>
		 * Determines if a mesh contains a triangle.
		 * </p>
		 *
		 * @param mesh The container.
		 * @param triangle The containee.
		 * @param relativeTransform The position and orientation of the triangle relative to the mesh.
		 *
		 * @return True if the mesh contains the triangle, false otherwise.
		 */
		bool contains(const Mesh& mesh, const Triangle& triangle, const Matrix44& relativeTransform);

		/**
		 * <p>
		 * Determines if model a contains model b. This generic version is provided to handle the case where the types
		 * of the models are unknown.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param a The container.
		 * @param b The containee.
		 * @param relativePosition The position of b relative to a.
		 *
		 * @return True if model a contains model b, false otherwise.
		 */
		bool contains(const Model& a, const Model& b, const Vector3& relativePosition);

		/**
		 * <p>
		 * Determines if a square contains a circle.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param square The container.
		 * @param circle The containee.
		 * @param relativePosition The position of the circle relative to the square.
		 *
		 * @return True if the square contains model the circle, false otherwise.
		 */
		bool contains(const Square& square, const Circle& circle, const Vector2& relativePosition);

		/**
		 * <p>
		 * Determines if square a contains square b.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param a The container.
		 * @param b The containee.
		 * @param relativePosition The position of b relative to a.
		 *
		 * @return True if square a contains square b, false otherwise.
		 */
		bool contains(const Square& a, const Square& b, const Vector2& relativePosition);

		/**
		 * <p>
		 * Determines if a triangle contains a point.
		 * </p>
		 *
		 * <p>
		 * This function assumes the points of both models to be in the same space.
		 * </p>
		 *
		 * @param triangle The container.
		 * @param point The containee.
		 *
		 * @return True if the triangle contains the point, false otherwise.
		 */
		bool contains(const Triangle& triangle, const Point& point);

		/**
		 * <p>
		 * Determines the point of intersection of a line segment and a plane.
		 * </p>
		 *
		 * @param lineSegment The line segment.
		 * @param plane The plane.
		 *
		 * @return The point of intersection.
		 */
		Vector3 getIntersection(const Line& lineSegment, const Plane& plane);

		/**
		 * <p>
		 * Determines the line of intersection of triangle a and triangle b.
		 * </p>
		 *
		 * <p>
		 * If the triangles intersect at a point, the two points of the line returned will be identical.
		 * </p>
		 *
		 * <p>
		 * This function assumes an intersection exists. Use an intersect() function to determine if this is the case
		 * before calling this function.
		 * </p>
		 *
		 * @param a The first triangle.
		 * @param b The second triangle.
		 * @param relativeTransform The position and orientation of triangle b relative to triangle a.
		 *
		 * @return The line of intersection.
		 */
		Line getIntersection(const Triangle& a, const Triangle& b, const Matrix44& relativeTransform);

		/**
		 * <p>
		 * Determines the line of intersection of triangle a and triangle relativeB. This overload is faster than the
		 * other triangle-triangle intersection one, when doing multiple calls with the same triangles it is best to
		 * calculate the data needed to call this overload before hand.
		 * </p>
		 *
		 * <p>
		 * If the triangles intersect at a point, the two points of the line returned will be identical.
		 * </p>
		 *
		 * <p>
		 * This function assumes an intersection exists. Use an intersect() function to determine if this is the case
		 * before calling this function.
		 * </p>
		 *
		 * @param a The first triangle.
		 * @param relativeB The second triangle (whose points are in the same space as the first triangle).
		 * @param normalA The normal of the first triangle.
		 * @param normalB The normal of the second triangle.
		 *
		 * @return The line of intersection.
		 */
		Line getIntersection(const Triangle& a, const Triangle& relativeB, const Vector3& normalA,
				const Vector3& normalB);

		/**
		 * <p>
		 * Determines how far along a line segment the intersection with a plane occurs.
		 * </p>
		 *
		 * @param lineSegment The line segment.
		 * @param plane The plane.
		 *
		 * @return The distance along the line segment where the intersection occurs (value is in the range [0,1]).
		 */
		float getIntersectionTime(const Line& lineSegment, const Plane& plane);

		/**
		 * <p>
		 * Determines if circle a and circle b intersect.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param a The first circle.
		 * @param b The second circle.
		 * @param relativePosition The position of b relative to a.
		 *
		 * @return True if circle a and circle b intersect, false otherwise.
		 */
		bool intersect(const Circle& a, const Circle& b, const Vector2& relativePosition);

		/**
		 * <p>
		 * Determines if a circle and a square intersect.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param circle The circle.
		 * @param square The square.
		 * @param relativePosition The position of the square relative to the circle.
		 *
		 * @return True if the circle and the square intersect, false otherwise.
		 */
		bool intersect(const Circle& circle, const Square& square, const Vector2& relativePosition);

		/**
		 * <p>
		 * Determines if cube a and cube b intersect.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param a The first cube.
		 * @param b The second cube.
		 * @param relativePosition The position of b relative to a.
		 *
		 * @return True if cube a and cube b intersect, false otherwise.
		 */
		bool intersect(const Cube& a, const Cube& b, const Vector3& relativePosition);

		/**
		 * <p>
		 * Determines if a line segment and a plane intersect.
		 * </p>
		 *
		 * <p>
		 * This function assumes the points of both models to be in the same space.
		 * </p>
		 *
		 * @param lineSegment The line segment.
		 * @param plane The plane.
		 *
		 * @return True if the line segment and the plane intersect, false otherwise.
		 */
		bool intersect(const Line& lineSegment, const Plane& plane);

		/**
		 * <p>
		 * Determines if a line segment and a triangle intersect.
		 * </p>
		 *
		 * <p>
		 * This function assumes the points of both models to be in the same space.
		 * </p>
		 *
		 * @param lineSegment The line segment.
		 * @param triangle The triangle.
		 *
		 * @return True if the line segment and the triangle intersect, false otherwise.
		 */
		bool intersect(const Line& lineSegment, const Triangle& triangle);

		/**
		 * <p>
		 * Determines if model a and model b intersect. This generic version is provided to handle the case where the
		 * types of the models are unknown.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param a The first model.
		 * @param b The second model.
		 * @param relativePosition The position of b relative to a.
		 *
		 * @return True if model a and model b intersect, false otherwise.
		 */
		bool intersect(const Model& a, const Model& b, const Vector3& relativePosition);

		/**
		 * <p>
		 * Determines if a plane and a point intersect.
		 * </p>
		 *
		 * <p>
		 * This function assumes the points of both models to be in the same space.
		 * </p>
		 *
		 * @param plane The plane.
		 * @param point The point.
		 *
		 * @return The position of the point relative to the plane.
		 */
		RelativePosition intersect(const Plane& plane, const Point& point);

		/**
		 * <p>
		 * Determines if a plane and a triangle intersect.
		 * </p>
		 *
		 * <p>
		 * This function assumes the points of both models to be in the same space.
		 * </p>
		 *
		 * @param plane The plane.
		 * @param triangle The triangle.
		 *
		 * @return True if the plane and the triangle intersect, false otherwise.
		 */
		bool intersect(const Plane& plane, const Triangle& triangle);

		/**
		 * <p>
		 * Determines if square a and square b intersect.
		 * </p>
		 *
		 * <p>
		 * This function does not support models with differing orientations.
		 * </p>
		 *
		 * @param a The first square.
		 * @param b The second square.
		 * @param relativePosition The position of b relative to a.
		 *
		 * @return True if square a and square b intersect, false otherwise.
		 */
		bool intersect(const Square& a, const Square& b, const Vector2& relativePosition);

		/**
		 * <p>
		 * Determines if triangle a and triangle b intersect.
		 * </p>
		 *
		 * @param a The first triangle.
		 * @param b The second triangle.
		 * @param relativeTransform The position and orientation of the triangle b relative to triangle a.
		 *
		 * @return True if triangle a and triangle b intersect, false otherwise.
		 */
		bool intersect(const Triangle& a, const Triangle& b, const Matrix44& relativeTransform);

		/**
		 * <p>
		 * Determines if triangle a and triangle relativeB intersect.
		 * </p>
		 *
		 * @param a The first triangle.
		 * @param relativeB The second triangle (whose points are in the same space as the first triangle).
		 * @param normalA The normal of the first triangle.
		 * @param normalB The normal of the second triangle.
		 *
		 * @return True if triangle a and triangle relativeB intersect, false otherwise.
		 */
		bool intersect(const Triangle& a, const Triangle& relativeB, const Vector3& normalA, const Vector3& normalB);
	}
}

#endif /* INTERSECTION_H_ */
