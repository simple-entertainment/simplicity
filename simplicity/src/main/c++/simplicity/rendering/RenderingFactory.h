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
#ifndef RENDERINGFACTORY_H_
#define RENDERINGFACTORY_H_

#include <memory>
#include <string>

#include "../resources/Resource.h"
#include "PixelFormat.h"
#include "Texture.h"

namespace simplicity
{
	/**
	 * <p>
	 * A factory that creates textures.
	 * </p>
	 */
	class SIMPLE_API RenderingFactory
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~RenderingFactory()
			{
			}

			/**
			 * <p>
			 * Creates a texture from in-memory data.
			 * </p>
			 *
			 * @param data The texture data.
			 * @param length The length of the data.
			 * @param format The format of the texture.
			 *
			 * @return The texture.
			 */
			virtual std::unique_ptr<Texture> createTexture(const char* data, unsigned int length, PixelFormat format) = 0;

			/**
			 * <p>
			 * Creates a texture from raw (i.e. non-encoded RGBA float) in-memory data.
			 * </p>
			 *
			 * @param data The texture data.
			 * @param width The width of the texture.
			 * @param height The height of the texture.
			 * @param format The format of the texture.
			 *
			 * @return The texture.
			 */
			virtual std::unique_ptr<Texture> createTexture(char* rawData, unsigned int width, unsigned int height,
					PixelFormat format) = 0;

			/**
			 * <p>
			 * Creates a texture from a resource.
			 * </p>
			 *
			 * @param image The image resource.
			 * @param format The format of the texture.
			 *
			 * @return The texture.
			 */
			virtual std::unique_ptr<Texture> createTexture(Resource& image, PixelFormat format) = 0;

			/**
			 * <p>
			 * Retrieves the concrete factory instance used to create the textures.
			 * </p>
			 *
			 * @return The concrete factory instance.
			 */
			static RenderingFactory* getInstance();

			/**
			 * <p>
			 * Sets the concrete factory instance used to create the textures.
			 * </p>
			 *
			 * @param instance The concrete factory instance.
			 */
			static void setInstance(std::unique_ptr<RenderingFactory> instance);

		private:
			static std::unique_ptr<RenderingFactory> instance;
	};
}

#endif /* RENDERINGFACTORY_H_ */
