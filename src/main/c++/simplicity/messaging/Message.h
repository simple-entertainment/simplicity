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
#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "../common/Defines.h"

namespace simplicity
{
	/**
	 * <p>
	 * A message.
	 * </p>
	 */
	struct SIMPLE_API Message
	{
		Message();

		/**
		 * @param subject The purpose for sending the information.
		 * @param body The information being sent.
		 */
		Message(unsigned short subject, const void* body);
		
		/**
		 * <p>
		 * The information being sent.
		 * </p>
		 */
		const void* body;
		
		/**
		 * <p>
		 * The ID of the system where this message originated. This is only relevant if the message is being sent from
		 * one system to another e.g. across a network.
		 * </p>
		 */
		unsigned long senderSystemId;

		/**
		 * <p>
		 * The purpose for sending the information.
		 * </p>
		 */
		unsigned short subject;
	};
}

#endif /* MESSAGE_H_ */
