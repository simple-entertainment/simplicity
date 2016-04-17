/*
 * Copyright © 2015 Simple Entertainment Limited
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
#include "PixelFormat.h"

namespace simplicity
{
	unsigned int getPixelDepth(PixelFormat format)
	{
		if (format == PixelFormat::BGR || format == PixelFormat::RGB)
		{
			return 3;
		}

		if (format == PixelFormat::BGR_HDR || format == PixelFormat::RGB_HDR)
		{
			return 6;
		}

		if (format == PixelFormat::BGRA || format == PixelFormat::RGBA)
		{
			return 4;
		}

		if (format == PixelFormat::BGRA_HDR || format == PixelFormat::RGBA_HDR)
		{
			return 8;
		}

		return 0;
	}

	bool hasTransparency(PixelFormat format)
	{
		return format == PixelFormat::BGRA || format == PixelFormat::BGRA_HDR ||
			   format == PixelFormat::RGBA || format == PixelFormat::RGBA_HDR;
	}
}
