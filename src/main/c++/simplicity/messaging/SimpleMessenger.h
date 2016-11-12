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
#ifndef SIMPLEMESSENGER_H_
#define SIMPLEMESSENGER_H_

#include <queue>

#include "Messenger.h"

namespace simplicity
{
	/**
	 * <p>
	 * A messenger that delivers messages to local receivers.
	 * </p>
	 */
	class SIMPLE_API SimpleMessenger : public Messenger
	{
		public:
			SimpleMessenger();

			void deregisterRecipient(unsigned short subject, std::function<Recipient> recipient)  override;

			void deregisterRecipient(unsigned short subject, unsigned short recipientCategory)  override;
				
			void registerRecipient(unsigned short subject, std::function<Recipient> recipient) override;

			void registerRecipient(unsigned short subject, unsigned short recipientCategory) override;

			void send(const Message& message) override;

		private:
			std::map<unsigned short, std::vector<std::function<Recipient>>> recipients;
	};
}

#endif /* SIMPLEMESSENGER_H_ */
