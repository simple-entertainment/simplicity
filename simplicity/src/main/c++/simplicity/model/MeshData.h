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
#ifndef MESHDATA_H_
#define MESHDATA_H_

#include "Vertex.h"

namespace simplicity
{
	/**
	 * <p>
	 * An access provider for the data of a mesh.
	 * </p>
	 */
	struct SIMPLE_API MeshData
	{
		MeshData();

		/**
		 * <p>
		 * The number of vertices in the mesh.
		 * </p>
		 */
		unsigned int vertexCount;

		/**
		 * <p>
		 * The vertices in the mesh.
		 * </p>
		 */
		Vertex* vertexData;

		/**
		 * <p>
		 * The number of indices in the mesh.
		 * </p>
		 */
		unsigned int vertexData;

		/**
		 * <p>
		 * The indices in the mesh.
		 * </p>
		 */
		unsigned int* indexData;

		/**
		 * <p>
		 * Retrieves a vertex in the mesh.
		 * </p>
		 *
		 * <p>
		 * If the vertices are indexed this function is equivalent to vertexData[indexData[index]]. If they are not
		 * this function is equivalent to vertexData[index].
		 * </p>
		 *
		 * @param index The index of the vertetx to access.
		 *
		 * @return The vertex in the mesh at the given index.
		 */
		Vertex& operator[](unsigned int index);

		/**
		 * <p>
		 * Retrieves a vertex in the mesh.
		 * </p>
		 *
		 * <p>
		 * If the vertices are indexed this function is equivalent to vertexData[indexData[index]]. If they are not
		 * this function is equivalent to vertexData[index].
		 * </p>
		 *
		 * @param index The index of the vertetx to access.
		 *
		 * @return The vertex in the mesh at the given index.
		 */
		const Vertex& operator[](unsigned int index) const;

		/**
		 * <p>
		 * Retrieves the size of the mesh.
		 * </p>
		 *
		 * <p>
		 * If the vertices are indexed this function is equivalent to indexCount. If they are not
		 * this function is equivalent to vertexCount.
		 * </p>
		 *
		 * @return The size of the mesh.
		 */
		unsigned int size() const;
	};
}

#endif /* MESHDATA_H_ */
