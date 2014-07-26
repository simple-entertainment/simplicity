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
#ifndef MESHBUFFER_H_
#define MESHBUFFER_H_

#include "Mesh.h"

namespace simplicity
{
	/**
	 * <p>
	 * A buffer used to store mesh data.
	 * </p>
	 */
	class SIMPLE_API MeshBuffer
	{
		public:
			/**
			 * <p>
			 * A hint for the accessibility of the buffer's data.
			 * </p>
			 */
			enum class AccessHint
			{
				/**
				 * <p>
				 * No access is required.
				 * </p>
				 */
				NONE,

				/**
				 * <p>
				 * Read-only access is required.
				 * </p>
				 */
				READ,

				/**
				 * <p>
				 * Read and write access is required.
				 * </p>
				 */
				READ_WRITE,

				/**
				 * <p>
				 * Write access is required.
				 * </p>
				 */
				WRITE
			};

			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~MeshBuffer()
			{
			}

			/**
			 * <p>
			 * Retrieves the hinted accessibility of this buffer's data.
			 * </p>
			 *
			 * @return The hinted accessibility of this buffer's data.
			 */
			virtual AccessHint getAccessHint() const = 0;

			/**
			 * <p>
			 * Retrieves the position of the first index stored for the given mesh.
			 * </p>
			 *
			 * @param mesh The mesh to retrive the base index for. Returns 0 if this buffer is not indexed.
			 *
			 * @return The position of the first index stored for the given mesh.
			 */
			virtual unsigned int getBaseIndex(const Mesh& mesh) const = 0;

			/**
			 * <p>
			 * Retrieves the position of the first vertex stored for the given mesh.
			 * </p>
			 *
			 * @param mesh The mesh to retrive the base vertex for.
			 *
			 * @return The position of the first vertex stored for the given mesh.
			 */
			virtual unsigned int getBaseVertex(const Mesh& mesh) const = 0;

			/**
			 * <p>
			 * Retrieves the (possibly indexed) vertex data for the given mesh. Every call to this function should be
			 * matched with a call to releaseData with the same mesh when you are finished with the data.
			 * </p>
			 *
			 * @param mesh The mesh to retrieve the data for.
			 * @param readable Determines whether the data returned should be readable.
			 * @param writable Determines whether the data returned should be writable.
			 *
			 * @return The (possibly indexed) vertex data for the given mesh.
			 */
			virtual MeshData& getData(const Mesh& mesh, bool readable, bool writable) = 0;

			/**
			 * <p>
			 * Retrieves the (possibly indexed) vertex data for the given mesh. Every call to this function should be
			 * matched with a call to releaseData with the same mesh when you are finished with the data.
			 * </p>
			 *
			 * @param mesh The mesh to retrieve the data for.
			 *
			 * @return The (possibly indexed) vertex data for the given mesh.
			 */
			virtual const MeshData& getData(const Mesh& mesh) const = 0;

			/**
			 * <p>
			 * Retrieves the number of indices stored for the given mesh.
			 * </p>
			 *
			 * @param mesh The mesh to retrive the index count for.
			 *
			 * @return The number of indices stored for the given mesh. Returns 0 if this buffer is not indexed.
			 */
			virtual unsigned int getIndexCount(const Mesh& mesh) const = 0;

			/**
			 * <p>
			 * Retrieves the number of vertices stored for the given mesh.
			 * </p>
			 *
			 * @param mesh The mesh to retrive the vertex count for.
			 *
			 * @return The number of vertices stored for the given mesh.
			 */
			virtual unsigned int getVertexCount(const Mesh& mesh) const = 0;

			/**
			 * <p>
			 * Determines if the vertices stored in this buffer are indexed.
			 * </p>
			 *
			 * @return True if the vertices stored in this buffer are indexed, false otherwise.
			 */
			virtual bool isIndexed() const = 0;

			/**
			 * <p>
			 * Releases the (possibly indexed) vertex data for the given mesh.
			 * </p>
			 *
			 * @param mesh The mesh to release the data for.
			 */
			virtual void releaseData(const Mesh& mesh) const = 0;
	};
}

#endif /* MESHBUFFER_H_ */
