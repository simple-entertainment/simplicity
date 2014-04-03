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
#ifndef MODELFUNCTIONS_H_
#define MODELFUNCTIONS_H_

#include <memory>

#include "../math/Vector.h"
#include "Point.h"
#include "shape/Circle.h"
#include "shape/Square.h"
#include "Vertex.h"

namespace simplicity
{
	namespace ModelFunctions
	{
		/**
		 * <p>
		 * Sets the color of the specified vertices.
		 * </p>
		 *
		 * @param vertices The vertices to colorize.
		 * @param color The color of the vertices.
		 * @param begin The index of the first vertex to colorize (default is 0).
		 * @param end The index of the last vertex to colorize (exclusive, default is 0 which is used to signify the
		 * end of the vertices).
		 */
		SIMPLE_API void colorizeVertices(std::vector<Vertex>& vertices, const Vector4& color,
				unsigned int begin = 0, unsigned int end = 0);

		/**
		 * <p>
		 * Flips the specified faces to face the opposite direction.
		 * </p>
		 *
		 * @param vertices The faces to flip.
		 * @param indices The indices of the faces to flip.
		 * @param begin The index of the first face to flip (default is 0).
		 * @param end The index of the last face to flip (exclusive, default is 0 which is used to signify the end of
		 * the faces).
		 */
		SIMPLE_API void flipTriangles(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices,
				unsigned int begin = 0, unsigned int end = 0);

		/**
		 * <p>
		 * Calculates a circular bounding volume on the XZ plane for the given vertices.
		 * </p>
		 *
		 * @param vertices The vertices.
		 *
		 * @return A circular bounding volume on the XZ plane.
		 */
		SIMPLE_API std::unique_ptr<Circle> getCircleBoundsXZ(const std::vector<Vertex>& vertices);

		/**
		 * <p>
		 * Calculates a square bounding volume on the XZ plane for the given vertices.
		 * </p>
		 *
		 * @param vertices The vertices.
		 *
		 * @return A square bounding volume on the XZ plane.
		 */
		SIMPLE_API std::unique_ptr<Square> getSquareBoundsXZ(const std::vector<Vertex>& vertices);

		/**
		 * <p>
		 * Rotates the specified vertices.
		 * </p>
		 *
		 * @param vertices The vertices to rotate.
		 * @param angle The angle to rotate the vertices.
		 * @param axis The axis to rotate the vertices around.
		 * @param begin The index of the first vertex to rotate (default is 0).
		 * @param end The index of the last vertex to rotate (exclusive, default is 0 which is used to signify the end
		 * of the vertices).
		 */
		SIMPLE_API void rotateVertices(std::vector<Vertex>& vertices, float angle, const Vector3& axis,
				unsigned int begin = 0, unsigned int end = 0);

		/**
		 * <p>
		 * Scales the specified vertices.
		 * </p>
		 *
		 * @param vertices The vertices to scale.
		 * @param scale The scalar.
		 * @param begin The index of the first vertex to scale (default is 0).
		 * @param end The index of the last vertex to scale (exclusive, default is 0 which is used to signify the end
		 * of the vertices).
		 */
		SIMPLE_API void scaleVertices(std::vector<Vertex>& vertices, float scale, unsigned int begin = 0,
				unsigned int end = 0);

		/**
		 * <p>
		 * Subtracts one model from another.
		 * </p>
		 *
		 * <p>
		 * UNDER CONSTRUCTION
		 * </p>
		 *
		 * @param lhs The model to subtract from.
		 * @param rhs The model to subtract.
		 * @param relativeTransform The position and orientation of the rhs model relative to the lhs model.
		 *
		 * @return The result of the subtraction.
		 */
		SIMPLE_API std::unique_ptr<Mesh> subtract(const Mesh& lhs, const Mesh& rhs,
				const Matrix44& relativeTransform);

		/**
		 * <p>
		 * Transforms the specified vertices.
		 * </p>
		 *
		 * @param vertices The vertices to transform.
		 * @param transformation The transformation.
		 * @param begin The index of the first vertex to transform (default is 0).
		 * @param end The index of the last vertex to transform (exclusive, default is 0 which is used to signify the
		 * end of the vertices).
		 */
		SIMPLE_API void transformVertices(std::vector<Vertex>& vertices, const Matrix44& transformation,
				unsigned int begin = 0, unsigned int end = 0);

		/**
		 * <p>
		 * Translates the specified vertices.
		 * </p>
		 *
		 * @param vertices The vertices to translate.
		 * @param translation The translation.
		 * @param begin The index of the first vertex to translate (default is 0).
		 * @param end The index of the last vertex to translate (exclusive, default is 0 which is used to signify the
		 * end of the vertices).
		 */
		SIMPLE_API void translateVertices(std::vector<Vertex>& vertices, const Vector3& translation,
				unsigned int begin = 0, unsigned int end = 0);
	}
}

#endif /* MODELFUNCTIONS_H_ */
