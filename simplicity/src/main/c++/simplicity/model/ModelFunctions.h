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
		void colorizeVertices(std::vector<Vertex>& vertices, const Vector4& color, unsigned int begin = 0,
				unsigned int end = 0);

		void flipTriangles(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, unsigned int begin = 0,
				unsigned int end = 0);

		std::unique_ptr<Circle> getCircleBoundsXZ(const std::vector<Vertex>& vertices);

		std::unique_ptr<Square> getSquareBoundsXZ(const std::vector<Vertex>& vertices);

		void rotateVertices(std::vector<Vertex>& vertices, float angle, const Vector3& axis, unsigned int begin = 0,
				unsigned int end = 0);

		void scaleVertices(std::vector<Vertex>& vertices, float scale, unsigned int begin = 0, unsigned int end = 0);

		std::unique_ptr<Mesh> subtract(const Mesh& lhs, const Mesh& rhs, const Matrix44& relativeTransform);

		void transformVertices(std::vector<Vertex>& vertices, const Matrix44& transformation, unsigned int begin = 0,
				unsigned int end = 0);

		void translateVertices(std::vector<Vertex>& vertices, const Vector3& translation, unsigned int begin = 0,
				unsigned int end = 0);
	}
}

#endif /* MODELFUNCTIONS_H_ */
