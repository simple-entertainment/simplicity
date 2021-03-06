/*
 * Copyright � 2014 Simple Entertainment Limited
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
#ifndef SIMPLECODEC_H_
#define SIMPLECODEC_H_

#include <cstddef>
#include <memory>

#include "Codec.h"

namespace simplicity
{
	/**
	 * <p>
	 * A codec that can be used to encode and decode basic value types such as structs. A SimpleCodec<nullptr_t> will
	 * produce zero bytes when encoded.
	 * </p>
	 */
	template<typename BodyType>
	class SimpleCodec : public simplicity::Codec
	{
		public:
			SimpleCodec();

			Message decode(const byte* data) override;

			std::vector<simplicity::byte> encode(const Message& message) override;

		private:
			BodyType decodedBody;
	};

	template<>
	class SimpleCodec<std::nullptr_t> : public simplicity::Codec
	{
		public:
			Message decode(const byte* data) override;

			std::vector<simplicity::byte> encode(const Message& message) override;
	};
}

#include "SimpleCodec.tpp"

#endif /* SIMPLECODEC_H_ */
