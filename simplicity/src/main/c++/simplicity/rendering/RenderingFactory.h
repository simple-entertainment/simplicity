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

#include "Texture.h"

namespace simplicity
{
	/**
	 * <p>
	 * A factory that creates textures.
	 * </p>
	 */
	class RenderingFactory
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
			 * @param width The width of the texture.
			 * @param height The height of the texture.
			 *
			 * @return The texture.
			 */
			virtual std::unique_ptr<Texture> createTexture(const char* data, unsigned int width,
					unsigned int height) = 0;

			/**
			 * <p>
			 * Creates a texture from a file.
			 * </p>
			 *
			 * @param fileName The name of the file.
			 *
			 * @return The texture.
			 */
			virtual std::unique_ptr<Texture> createTexture(const std::string& fileName) = 0;

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
