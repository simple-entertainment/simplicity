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
#ifndef RECIPIENT_H_
#define RECIPIENT_H_

#include "Message.h"

namespace simplicity
{
	/**
	 * <p>
	 * The function signature required to receive messages. A recipient can consume a message, stopping it from being
	 * sent to any remaining recipients.
	 * </p>
	 *
	 * @param The message being received.
	 *
	 * @return True if the message has been consumed, false otherwise.
	 */
	using Recipient = bool(const Message&);

	// TODO Replace with system ID based sending (0 = all connected systems)
	namespace RecipientCategory
	{
		/**
		 * <p>
		 * All clients.
		 * </p>
		 */
		static const unsigned short CLIENT = 0;

		/**
		 * <p>
		 * The server.
		 * </p>
		 */
		static const unsigned short SERVER = 1;
	}
}

#endif /* RECIPIENT_H_ */
