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
#include <map>
#include <vector>

#include "Messages.h"

using namespace std;

namespace simplicity
{
	namespace Messages
	{
		map<unsigned int, DeliveryOptions> deliveryOptions;

		vector<MessagingEngine*> engines;

		void addEngine(MessagingEngine* engine)
		{
			engines.push_back(engine);
		}

		void deregisterRecipient(unsigned short subject, function<Recipient> recipient)
		{
			for (MessagingEngine* engine : engines)
			{
				engine->deregisterRecipient(subject, recipient);
			}
		}

		void deregisterRecipient(unsigned short subject, unsigned short recipientCategory)
		{
			for (MessagingEngine* engine : engines)
			{
				engine->deregisterRecipient(subject, recipientCategory);
			}
		}

		const DeliveryOptions& getDeliveryOptions(unsigned short subject)
		{
			return deliveryOptions[subject];
		}

		void registerRecipient(unsigned short subject, function<Recipient> recipient)
		{
			for (MessagingEngine* engine : engines)
			{
				engine->registerRecipient(subject, recipient);
			}
		}

		void registerRecipient(unsigned short subject, unsigned short recipientCategory)
		{
			for (MessagingEngine* engine : engines)
			{
				engine->registerRecipient(subject, recipientCategory);
			}
		}

		void removeEngine(const MessagingEngine& engine)
		{
			engines.erase(remove(engines.begin(), engines.end(), &engine));
		}

		void send(unsigned short subject, const void* message)
		{
			for (MessagingEngine* engine : engines)
			{
				engine->send(subject, message);
			}
		}
	}

	void setDeliveryOptions(unsigned short subject, const DeliveryOptions& deliveryOptions)
	{
		Messages::deliveryOptions[subject] = deliveryOptions;
	}
}
