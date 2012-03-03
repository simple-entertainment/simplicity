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
#ifndef SIMPLEOPENGLTEXTURE_H_
#define SIMPLEOPENGLTEXTURE_H_

#include <string>

#include <boost/gil/gil_all.hpp>

#include <GL/gl.h>

#include <simplicity/rendering/Texture.h>

namespace simplicity
{
	namespace opengl
	{
		class SimpleOpenGLTexture : public Texture
		{
			public:
				SimpleOpenGLTexture(const std::string& fileName, const unsigned int width, const unsigned int height,
					const bool hasAlpha);

				virtual ~SimpleOpenGLTexture();

				void select();

			private:
				std::string fileName;

				bool hasAlpha;

				unsigned int height;

				bool loaded;

				GLuint name;

				unsigned int width;

				void load();
		};
	}
}

#endif /* SIMPLEOPENGLTEXTURE_H_ */
