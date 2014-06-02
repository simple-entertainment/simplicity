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
	class SIMPLE_API Mesh : public Model
	{
		public:
			/**
			* <p>
			* Retrieves the number of indices in this mesh.
			* </p>
			*
			* @return The number of indices in this mesh.
			*/
			virtual unsigned int getIndexCount() const = 0;

			/**
			 * <p>
			 * Retrieves the indices into the collection of vertices.
			 * </p>
			 *
			 * @return The indices into the collection of vertices.
			 */
			virtual unsigned int* getIndices() = 0;

			/**
			 * <p>
			 * Retrieves the indices into the collection of vertices.
			 * </p>
			 *
			 * @return The indices into the collection of vertices.
			 */
			virtual const unsigned int* getIndices() const = 0;

			/**
			* <p>
			* Retrieves the number of vertices in this mesh.
			* </p>
			*
			* @return The number of vertices in this mesh.
			*/
			virtual unsigned int getVertexCount() const = 0;

			/**
			 * <p>
			 * Retrieves the collection of vertices.
			 * </p>
			 *
			 * @return The collection of vertices.
			 */
			virtual Vertex* getVertices() = 0;

			/**
			 * <p>
			 * Retrieves the collection of vertices.
			 * </p>
			 *
			 * @return The collection of vertices.
			 */
			virtual const Vertex* getVertices() const = 0;

			/**
			 * <p>
			 * Initializes this mesh.
			 * </p>
			 */
			virtual void init() = 0;

			/**
			 * <p>
			 * Resizes the indices into the collection of vertices.
			 * </p>
			 *
			 * @param size The new size of the indices into the collection of vertices.
			 */
			virtual void resizeIndices(unsigned int size) = 0;

			/**
			 * <p>
			 * Resizes the collection of vertices.
			 * </p>
			 *
			 * @param size The new size of the collection of vertices.
			 */
			virtual void resizeVertices(unsigned int size) = 0;
	};
}

#endif /* MESH_H_ */
