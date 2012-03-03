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
#include <GL/gl.h>
#include <GL/glu.h>

#include <simplicity/rendering/ImageIO.h>

#include "SimpleOpenGLTexture.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		SimpleOpenGLTexture::SimpleOpenGLTexture(const string& fileName, const unsigned int width,
			const unsigned int height) :
			fileName(fileName), height(height), loaded(false), name(), width(width)
		{
		}

		SimpleOpenGLTexture::~SimpleOpenGLTexture()
		{
			if (loaded)
			{
				glDeleteTextures(1, &name);
			}
		}

		void SimpleOpenGLTexture::load()
		{
			vector<char> data(imageio::loadImage(fileName));

			glGenTextures(1, &name);

			glBindTexture(GL_TEXTURE_2D, name);

			// select modulate to mix texture with color for shading
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);

			// when texture area is small, bilinear filter the closest mipmap
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
			// when texture area is large, bilinear filter the first mipmap
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			// texture should tile
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

			// build our texture mipmaps
			gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data.data());

			loaded = true;
		}

		void SimpleOpenGLTexture::select()
		{
			if (!loaded)
			{
				load();
			}

			glBindTexture(GL_TEXTURE_2D, name);
		}
	}
}
