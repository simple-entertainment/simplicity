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

#include "../Simplicity.h"
#include "Messages.h"
#include "Messenger.h"
#include "SimpleMessenger.h"

using namespace std;

namespace simplicity
{
	namespace Messages
	{
		map<unsigned int, unique_ptr<Codec>> codecs;

		unique_ptr<Messenger> defaultMessenger(new SimpleMessenger);

		vector<Messenger*> messengers;

		void addMessenger(Messenger* engine)
		{
			messengers.push_back(engine);
		}

		void deregisterRecipient(unsigned short subject, function<Recipient> recipient)
		{
			for (Messenger* messenger : messengers)
			{
				messenger->deregisterRecipient(subject, recipient);
			}
		}

		void deregisterRecipient(unsigned short subject, unsigned short recipientCategory)
		{
			for (Messenger* messenger : messengers)
			{
				messenger->deregisterRecipient(subject, recipientCategory);
			}
		}

		Codec* getCodec(unsigned short subject)
		{
			return codecs[subject].get();
		}

		void registerRecipient(unsigned short subject, function<Recipient> recipient)
		{
			// Provide the default messenger.
			if (messengers.size() == 0)
			{
				addMessenger(defaultMessenger.get());
			}

			for (Messenger* messenger : messengers)
			{
				messenger->registerRecipient(subject, recipient);
			}
		}

		void registerRecipient(unsigned short subject, unsigned short recipientCategory)
		{
			// Provide the default messenger.
			if (messengers.size() == 0)
			{
				addMessenger(defaultMessenger.get());
			}

			for (Messenger* messenger : messengers)
			{
				messenger->registerRecipient(subject, recipientCategory);
			}
		}

		void removeMessenger(const Messenger& messenger)
		{
			messengers.erase(remove(messengers.begin(), messengers.end(), &messenger));
		}

		void send(const Message& message)
		{
			for (Messenger* messenger : messengers)
			{
				messenger->send(message);
			}
		}

		void setCodec(unsigned short subject, unique_ptr<Codec> codec)
		{
			codecs[subject] = move(codec);
		}
	}
}
