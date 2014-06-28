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
#ifndef MESSAGES_H_
#define MESSAGES_H_

#include <functional>
#include <memory>

#include "Codec.h"
#include "Message.h"

namespace simplicity
{
	class MessagingEngine;

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

	namespace Messages
	{
		SIMPLE_API void addEngine(MessagingEngine* engine);

		/**
		 * <p>
		 * Deregisters the given recipient from the given subject.
		 * </p>
		 *
		 * @param subject The subject to deregister the recipient from.
		 * @param recipient The recipient to deregister.
		 */
		SIMPLE_API void deregisterRecipient(unsigned short subject, std::function<Recipient> recipient);

		/**
		* <p>
		* Deregisters the given recipient category from the given subject.
		* </p>
		*
		* @param subject The subject to deregister the recipient from.
		* @param recipientCategory The recipient category to deregister.
		*/
		SIMPLE_API void deregisterRecipient(unsigned short subject, unsigned short recipientCategory);

		SIMPLE_API Codec* getCodec(unsigned short subject);

		/**
		 * <p>
		 * Registers a recipient for the given subject.
		 * </p>
		 *
		 * @param subject The subject to register the recipient with.
		 * @param recipient The recipient to send messages of the given subject to.
		 */
		SIMPLE_API void registerRecipient(unsigned short subject, std::function<Recipient> recipient);

		/**
		* <p>
		* Registers a recipient category for the given subject.
		* </p>
		*
		* @param subject The subject to register the recipient with.
		* @param recipientCategory The recipient category to send messages of the given subject to.
		*/
		SIMPLE_API void registerRecipient(unsigned short subject, unsigned short recipientCategory);

		SIMPLE_API void removeEngine(const MessagingEngine& engine);

		/**
		 * <p>
		 * Sends the given message to all registered recipients.
		 * </p>
		 *
		 * @param message The message to send.
		 */
		SIMPLE_API void send(const Message& message);

		SIMPLE_API void setCodec(unsigned short subject, std::unique_ptr<Codec> codec);
	}
}

#endif /* MESSAGES_H_ */
