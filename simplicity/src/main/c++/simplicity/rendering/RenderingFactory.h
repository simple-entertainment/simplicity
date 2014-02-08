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
	class RenderingFactory
	{
		public:
			virtual ~RenderingFactory()
			{
			}

			virtual std::unique_ptr<Texture> createTexture(const unsigned char* data, unsigned int width,
					unsigned int height) = 0;

			virtual std::unique_ptr<Texture> createTexture(const std::string& fileName) = 0;

			static RenderingFactory& getInstance();

			static void setInstance(std::unique_ptr<RenderingFactory> instance);

		private:
			static std::unique_ptr<RenderingFactory> instance;
	};
}

#endif /* RENDERINGFACTORY_H_ */
