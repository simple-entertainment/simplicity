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

#include "../common/Buffer.h"
#include "../rendering/Pipeline.h"
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
			 * The type of primitive the models in a buffer are constructed from.
			 * </p>
			 */
			enum class PrimitiveType
			{
				/**
				 * <p>
				 * A list of lines.
				 * </p>
				 */
				LINE_LIST,

				/**
				 * <p>
				 * A strip of lines.
				 * </p>
				 */
				LINE_STRIP,

				/**
				 * <p>
				 * A list of points.
				 * </p>
				 */
				POINTS,

				/**
				 * <p>
				 * A list of triangles.
				 * </p>
				 */
				TRIANGLE_LIST,

				/**
				 * <p>
				 * A strip of triangles.
				 * </p>
				 */
				TRIANGLE_STRIP
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
			virtual Buffer::AccessHint getAccessHint() const = 0;

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
			 * <p>
			 * Prefer the const overload of this function if you do not need to write to this buffer.
			 * </p>
			 *
			 * @param mesh The mesh to retrieve the data for.
			 * @param readable Determines whether the data returned should be readable.
			 *
			 * @return The (possibly indexed) vertex data for the given mesh.
			 */
			virtual MeshData& getData(const Mesh& mesh, bool readable) = 0;

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
			 * Retrieves the pipeline used to render this buffer.
			 * </p>
			 *
			 * @return The pipeline used to render this buffer.
			 */
			virtual Pipeline* getPipeline() const = 0;

			/**
			 * <p>
			 * Retrieves the type of primitive the models in is buffer are constructed from.
			 * </p>
			 *
			 * @return The type of primitive the models in is buffer are constructed from.
			 */
			virtual PrimitiveType getPrimitiveType() const = 0;

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

			/**
			 * <p>
			 * Sets the pipeline used to render this buffer.
			 * </p>
			 *
			 * @param pipeline The pipeline used to render this buffer.
			 */
			virtual void setPipeline(std::shared_ptr<Pipeline> pipeline) = 0;

			/**
			 * <p>
			 * Sets the type of primitive the models in is buffer are constructed from.
			 * </p>
			 *
			 * @param primitiveType The type of primitive the models in is buffer are constructed from.
			 */
			virtual void setPrimitiveType(PrimitiveType primitiveType) = 0;
	};
}

#endif /* MESHBUFFER_H_ */
