/*
 * Copyright © 2014 Simple Entertainment Limited
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
#ifndef CODEC_H_
#define CODEC_H_

#include <vector>

#include "../common/Defines.h"

namespace simplicity
{
	class SIMPLE_API Codec
	{
		public:
			virtual void* decode(const byte* data) = 0;

			virtual std::vector<byte> encode(unsigned short subject, const void* message) = 0;

			virtual unsigned int getDecodeReadLength() = 0;
	};
}

#endif /* CODEC_H_ */