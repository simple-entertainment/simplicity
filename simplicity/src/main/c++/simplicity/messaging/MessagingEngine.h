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
#ifndef MESSAGINGENGINE_H_
#define MESSAGINGENGINE_H_

#include "../engine/Engine.h"
#include "Messages.h"

namespace simplicity
{
	namespace RecipientCategory
	{
		static const unsigned short CLIENT = 0;

		static const unsigned short SERVER = 1;
	}

	/**
	 * <p>
	 * An engine that forwards messages from senders to receivers.
	 * </p>
	 */
	class SIMPLE_API MessagingEngine : public Engine
	{
		public:
			/**
			 * <p>
			 * Deregisters the given recipient from the given subject.
			 * </p>
			 *
			 * @param subject The subject to deregister the recipient from.
			 * @param recipient The recipient to deregister.
			 */
			virtual void deregisterRecipient(unsigned short subject, std::function<Recipient> recipient) = 0;

			/**
			 * <p>
			 * Deregisters the given recipient category from the given subject.
			 * </p>
			 *
			 * @param subject The subject to deregister the recipient from.
			 * @param recipientCategory The recipient category to deregister.
			 */
			virtual void deregisterRecipient(unsigned short subject, unsigned short recipientCategory) = 0;

			/**
			 * <p>
			 * Registers a recipient for the given subject.
			 * </p>
			 *
			 * @param subject The subject to register the recipient with.
			 * @param recipient The recipient to send messages of the given subject to.
			 */
			virtual void registerRecipient(unsigned short subject, std::function<Recipient> recipient) = 0;

			/**
			 * <p>
			 * Registers a recipient category for the given subject.
			 * </p>
			 *
			 * @param subject The subject to register the recipient with.
			 * @param recipientCategory The recipient category to send messages of the given subject to.
			 */
			virtual void registerRecipient(unsigned short subject, unsigned short recipientCategory) = 0;

			/**
			 * <p>
			 * Sends the given message to all registered recipients.
			 * </p>
			 *
			 * @param message The message to send.
			 */
			virtual void send(const Message& message) = 0;
	};
}

#endif /* MESSAGINGENGINE_H_ */
