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
#include "MessagesTest.h"

using namespace std;

namespace simplicity
{
	bool testRecipientCalled = false;

	void testRecipient(boost::any message)
	{
		testRecipientCalled = true;
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::Messages#deregisterRecipient(std::string, std::function<Messages::Recipient>) deregisterRecipient(std::string, std::function<Messages::Recipient>)}.
	 * </p>
	 */
	TEST_F(MessagesTest, deregisterRecipient)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::function<Messages::Recipient> recipient(testRecipient);

		// Initialise test environment.
		// //////////////////////////////////////////////////
		testRecipientCalled = false;
		Messages::registerRecipient("test", recipient);

		// Perform test.
		// //////////////////////////////////////////////////
		Messages::deregisterRecipient("test", recipient);

		// Verify test results.
		// //////////////////////////////////////////////////
		Messages::send("test", this);
		ASSERT_FALSE(testRecipientCalled);
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::Messages#registerRecipient(std::string, std::function<Messages::Recipient>) registerRecipient(std::string, std::function<Messages::Recipient>)}.
	 * </p>
	 */
	TEST_F(MessagesTest, registerRecipient)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::function<Messages::Recipient> recipient(testRecipient);

		// Initialise test environment.
		// //////////////////////////////////////////////////
		testRecipientCalled = false;

		// Perform test.
		// //////////////////////////////////////////////////
		Messages::registerRecipient("test", recipient);

		// Verify test results.
		// //////////////////////////////////////////////////
		Messages::send("test", this);
		ASSERT_TRUE(testRecipientCalled);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::Messages#send(std::string, boost::any) send(std::string, boost::any)}.
	 * </p>
	 */
	TEST_F(MessagesTest, send)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::function<Messages::Recipient> recipient(testRecipient);

		// Initialise test environment.
		// //////////////////////////////////////////////////
		testRecipientCalled = false;
		Messages::registerRecipient("test", recipient);

		// Perform test.
		// //////////////////////////////////////////////////
		Messages::send("test", this);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(testRecipientCalled);
	}
}
