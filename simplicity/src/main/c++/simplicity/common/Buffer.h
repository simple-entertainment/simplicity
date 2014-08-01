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
#ifndef BUFFER_H_
#define BUFFER_H_

#include "Defines.h"

namespace simplicity
{
	/**
	 * <p>
	 * A buffer used to store data.
	 * </p>
	 */
	class SIMPLE_API Buffer
	{
		public:
			/**
			 * <p>
			 * A hint for the accessibility of a buffer's data.
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
			 * The type of data stored in a buffer.
			 * </p>
			 */
			enum class DataType
			{
				/**
				 * <p>
				 * The buffer does not store any particular type of data.
				 * </p>
				 */
				NONE,

				/**
				 * <p>
				 * The buffer stores indices.
				 * </p>
				 */
				INDICES,

				/**
				 * <p>
				 * The buffer stores data that is accessible from shaders.
				 * </p>
				 */
				SHADER_DATA,

				/**
				 * <p>
				 * The buffer stores vertices.
				 * </p>
				 */
				VERTICES
			};

			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Buffer()
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
			 * Retrieves this buffer's data. Every call to this function should be matched with a call to releaseData
			 * with the same mesh when you are finished with the data.
			 * </p>
			 *
			 * <p>
			 * Prefer the const overload of this function if you do not need to write to this buffer.
			 * </p>
			 *
			 * @param readable Determines whether the data returned should be readable.
			 *
			 * @return This buffer's data.
			 */
			virtual byte* getData(bool readable) = 0;

			/**
			 * <p>
			 * Retrieves this buffer's data. Every call to this function should be matched with a call to releaseData
			 * with the same mesh when you are finished with the data.
			 * </p>
			 *
			 * @return This buffer's data.
			 */
			virtual const byte* getData() const = 0;

			/**
			 * <p>
			 * Retrieves the type of data stored in this buffer.
			 * </p>
			 */
			virtual DataType getDataType() const = 0;

			/**
			 * <p>
			 * Releases this buffer's data.
			 * </p>
			 */
			virtual void releaseData() const = 0;
	};
}

#endif /* BUFFER_H_ */
