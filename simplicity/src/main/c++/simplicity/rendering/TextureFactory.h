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
#ifndef TEXTUREFACTORY_H_
#define TEXTUREFACTORY_H_

#include <memory>

#include "Texture.h"

namespace simplicity
{
	class TextureFactory
	{
		public:
			static const TextureFactory& getInstance();

			static void setInstance(std::unique_ptr<TextureFactory> instance);

			virtual ~TextureFactory();

			virtual std::shared_ptr<Texture> createTexture(const std::string& fileName, const unsigned int width,
				const unsigned int height) const = 0;

		private:
			static std::unique_ptr<TextureFactory> instance;
	};
}

#endif /* TEXTUREFACTORY_H_ */
