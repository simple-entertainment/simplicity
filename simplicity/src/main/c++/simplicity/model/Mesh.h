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
#ifndef MESH_H_
#define MESH_H_

#include <vector>

#include "Model.h"
#include "Vertex.h"

namespace simplicity
{
	/**
	 * <p>
	 * A collection of indexed vertices.
	 * </p>
	 */
	class Mesh : public Model
	{
		public:
			/**
			 * <p>
			 * Retrieves the indices into the collection of vertices.
			 * </p>
			 *
			 * @return The indices into the collection of vertices.
			 */
			virtual std::vector<unsigned int>& getIndices() = 0;

			/**
			 * <p>
			 * Retrieves the indices into the collection of vertices.
			 * </p>
			 *
			 * @return The indices into the collection of vertices.
			 */
			virtual const std::vector<unsigned int>& getIndices() const = 0;

			/**
			 * <p>
			 * Retrieves the collection of vertices.
			 * </p>
			 *
			 * @return The collection of vertices.
			 */
			virtual std::vector<Vertex>& getVertices() = 0;

			/**
			 * <p>
			 * Retrieves the collection of vertices.
			 * </p>
			 *
			 * @return The collection of vertices.
			 */
			virtual const std::vector<Vertex>& getVertices() const = 0;
	};
}

#endif /* MESH_H_ */
