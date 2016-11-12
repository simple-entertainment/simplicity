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
#include "SimpleMessenger.h"

using namespace std;

namespace simplicity
{
	SimpleMessenger::SimpleMessenger() :
		recipients()
	{
	}

	void SimpleMessenger::deregisterRecipient(unsigned short subject, function<Recipient> recipient)
	{
		vector<function<Recipient>>& subjectRecipients = recipients[subject];

		subjectRecipients.erase(remove_if(subjectRecipients.begin(), subjectRecipients.end(),
			[recipient](const function<Recipient>& existingRecipient)
			{
				return existingRecipient.target_type() == recipient.target_type();
			}));
	}

	void SimpleMessenger::deregisterRecipient(unsigned short /* subject */,
		unsigned short /* recipientCategory */)
	{
	}

	void SimpleMessenger::registerRecipient(unsigned short subject, function<Recipient> recipient)
	{
		recipients[subject].push_back(recipient);
	}

	void SimpleMessenger::registerRecipient(unsigned short /* subject */, unsigned short /* recipientCategory */)
	{
	}

	void SimpleMessenger::send(const Message& message)
	{
		auto recipientsIter = recipients.find(message.subject);
		if (recipientsIter == recipients.end() || recipientsIter->second.empty())
		{
			return;
		}

		// A copy of the recipients is used so that modifications to the recipient list can be made by the recipient
		// (e.g. removing itself) without effecting this loop.
		vector<function<Recipient>> subjectRecipients = recipientsIter->second;
		for (function<Recipient> subjectRecipient : subjectRecipients)
		{
			if (subjectRecipient(message))
			{
				break;
			}
		}
	}
}
