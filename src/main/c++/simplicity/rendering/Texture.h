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
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../common/Defines.h"
#include "PixelFormat.h"

namespace simplicity
{
	/**
	 * <p>
	 * A texture.
	 * </p>
	 */
	class SIMPLE_API Texture
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Texture()
			{
			}

			/**
			 * <p>
			 * Applies this texture.
			 * </p>
			 */
			virtual void apply() = 0;

			/**
			 * <p>
			 * Retrieves the height of this texture.
			 * </p>
			 *
			 * @return The height of this texture.
			 */
			virtual unsigned int getHeight() const = 0;

			/**
			 * <p>
			 * Retrieves the format of this texture.
			 * </p>
			 *
			 * @return The format of this texture.
			 */
			virtual PixelFormat getPixelFormat() const = 0;

			/**
			 * <p>
			 * Retrieves the raw texture data.
			 * </p>
			 *
			 * @return The raw texture data.
			 */
			virtual const char* getRawData() const = 0;

			/**
			 * <p>
			 * Retrieves the width of this texture.
			 * </p>
			 *
			 * @return The width of this texture.
			 */
			virtual unsigned int getWidth() const = 0;

			/**
			 * <p>
			 * Initializes this texture.
			 * </p>
			 */
			virtual void init() = 0;

			/**
			 * <p>
			 * Sets the raw texture data.
			 * </p>
			 *
			 * @param rawData The raw texture data.
			 */
			virtual void setRawData(const char* rawData) = 0;
	};
}

#endif /* TEXTURE_H_ */
