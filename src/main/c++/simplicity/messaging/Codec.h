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

#include "Message.h"

namespace simplicity
{
	/**
	 * <p>
	 * Encodes and decodes messages to and from raw bytes.
	 * </p>
	 */
	class SIMPLE_API Codec
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Codec()
			{
			}

			/**
			 * <p>
			 * Decodes a message from raw bytes.
			 * </p>
			 *
			 * @param data The raw bytes to decode the message from.
			 *
			 * @return The decoded message.
			 */
			virtual Message decode(const byte* data) = 0;

			/**
			 * <p>
			 * Encodes a message to raw bytes.
			 * </p>
			 *
			 * @param message The message to encode.
			 *
			 * @return The encoded message.
			 */
			virtual std::vector<byte> encode(const Message& message) = 0;
	};
}

#endif /* CODEC_H_ */
