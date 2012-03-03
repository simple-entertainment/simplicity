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
#include <fstream>
#include <iostream>

#include <boost/gil/extension/io/jpeg_io.hpp>

#include "ImageIO.h"

using namespace boost::gil;
using namespace std;

namespace simplicity
{
	namespace imageio
	{
		vector<char> loadImage(const string& fileName)
		{
			string::size_type extensionIndex(fileName.rfind("."));
			if (extensionIndex == string::npos)
			{
				return loadImageRaw(fileName);
			}

			string extension(fileName.substr(extensionIndex + 1, fileName.size() - extensionIndex));
			if (extension == "jpeg" || extension == "jpg")
			{
				return loadImageJpeg(fileName);
			}
			else
			{
				return loadImageRaw(fileName);
			}
		}

		vector<char> loadImageJpeg(const string& fileName)
		{
			vector<char> data;
			rgb8_image_t image;
			jpeg_read_and_convert_image(fileName.data(), image);
			rgb8_image_t::const_view_t view(const_view(image));
			data.reserve(image.width() * image.height() * view.num_channels());

			for (rgb8_image_t::const_view_t::iterator iterator(view.begin()); iterator != view.end(); iterator++)
			{
				data.push_back(at_c<0>(*iterator));
				data.push_back(at_c<1>(*iterator));
				data.push_back(at_c<2>(*iterator));
			}

			return data;
		}

		vector<char> loadImageRaw(const string& fileName)
		{
			vector<char> data;

			ifstream rawFile(fileName, ios::in | ios::binary | ios::ate);
			if (rawFile.is_open())
			{
				ifstream::pos_type size = rawFile.tellg();
				data.reserve(size);
				rawFile.seekg(0, ios::beg);
				rawFile.read(data.data(), size);
				rawFile.close();
			}

			return data;
		}
	}
}
