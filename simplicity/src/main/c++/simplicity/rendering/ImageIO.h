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
#ifndef ImageIO
#define ImageIO

#include <string>
#include <vector>

namespace simplicity
{
	namespace imageio
	{
		/**
		 * <p>
		 * Loads an image, using the extension to determine the image format. If the extension not recognised or no
		 * extension exists, the image format is assumed to be RAW. It is also assumed that the image has no alpha
		 * channel. For images with alpha channels, use {@link loadImage(const std::string&, const bool)}.
		 * </p>
		 *
		 * @param fileName The name of the file to load the image from.
		 */
		std::vector<char> loadImage(const std::string& fileName);

		/**
		 * <p>
		 * Loads an image, using the extension to determine the image format. If the extension not recognised or no
		 * extension exists, the image format is assumed to be RAW.
		 * </p>
		 *
		 * @param fileName The name of the file to load the image from.
		 * @param hasAlpha Determines whether the image to be loaded has an alpha channel.
		 */
		std::vector<char> loadImage(const std::string& fileName, const bool hasAlpha);

		/**
		 * <p>
		 * Loads a JPEG image.
		 * </p>
		 *
		 * @param fileName The name of the file to load the image from.
		 */
		std::vector<char> loadImageJpeg(const std::string& fileName);

		/**
		 * <p>
		 * Loads a PNG image.
		 * </p>
		 *
		 * @param fileName The name of the file to load the image from.
		 * @param hasAlpha Determines whether the image to be loaded has an alpha channel.
		 */
		std::vector<char> loadImagePng(const std::string& fileName, const bool hasAlpha);

		/**
		 * <p>
		 * Loads a RAW image.
		 * </p>
		 *
		 * @param fileName The name of the file to load the image from.
		 */
		std::vector<char> loadImageRaw(const std::string& fileName);
	}
}

#endif /* ImageIO */
