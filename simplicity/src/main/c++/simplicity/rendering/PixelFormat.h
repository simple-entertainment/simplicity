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
#ifndef PIXELFORMAT_H_
#define PIXELFORMAT_H_

#include "../common/Defines.h"

namespace simplicity
{
	/**
	 * <p>
	 * A rendering pipeline.
	 * </p>
	 */
	enum class SIMPLE_API PixelFormat
	{
		BGR,
		BGRA,
		RGB,
		RGBA
	};
}

#endif /* PIXELFORMAT_H_ */
