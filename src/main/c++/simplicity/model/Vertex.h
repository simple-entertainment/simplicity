/*
 * Copyright © 2012 Simple Entertainment Limited
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
#ifndef VERTEX_H_
#define VERTEX_H_

#include "../common/Defines.h"
#include "../math/Vector.h"

namespace simplicity
{
	/**
	 * <p>
	 * A vertex in a mesh.
	 * </p>
	 */
	struct SIMPLE_API Vertex
	{
		/**
		 * <p>
		 * The color of the vertex.
		 * </p>
		 */
		Vector4 color;

		/**
		 * <p>
		 * The normal of the vertex.
		 * </p>
		 */
		Vector3 normal;

		/**
		 * <p>
		 * The position of the vertex.
		 * </p>
		 */
		Vector3 position;

		/**
		 * <p>
		 * The texture coordinate of the vertex.
		 * </p>
		 */
		Vector2 texCoord;
	};
}

#endif /* VERTEX_H_ */
