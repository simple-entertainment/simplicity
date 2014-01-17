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

#include "Messages.h"

using namespace std;

namespace simplicity
{
	namespace Messages
	{
		map<unsigned short, vector<function<Recipient> > > recipients;

		void deregisterRecipient(unsigned short subject, function<Recipient> recipient)
		{
			vector<function<Recipient> >& registeredRecipients = recipients.find(subject)->second;

			for (vector<function<Recipient> >::iterator registeredRecipient = registeredRecipients.begin();
				registeredRecipient != registeredRecipients.end(); registeredRecipient++)
			{
				if (registeredRecipient->target_type() == recipient.target_type())
				{
					registeredRecipients.erase(registeredRecipient);
					return;
				}
			}
		}

		void registerRecipient(unsigned short subject, function<Recipient> recipient)
		{
			if (recipients.find(subject) == recipients.end())
			{
				recipients.insert(
					pair<unsigned short, vector<function<Recipient> > >(subject, vector<function<Recipient> >()));
			}

			recipients.find(subject)->second.push_back(recipient);
		}

		void send(unsigned short subject, const boost::any message)
		{
			if (recipients.find(subject) == recipients.end())
			{
				return;
			}

			vector<function<Recipient> >& registeredRecipients = recipients.find(subject)->second;

			// Does not use C++11 for loop as elements could be added to the vector while iterating.
			// Take care - this is a fragile 'solution'.
			for (unsigned int index = 0; index < registeredRecipients.size(); index++)
			{
				registeredRecipients.at(index)(message);
			}
		}
	}
}
