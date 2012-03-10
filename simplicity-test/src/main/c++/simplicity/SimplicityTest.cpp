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
#include "SimplicityTest.h"

#include "MockComponent.h"

using namespace std;

namespace simplicity
{
	bool testObserverCalled = false;

	void testObserver(boost::any source)
	{
		testObserverCalled = true;
	}

	/**
	 * <p>
	 * Unit test the method
	 * {@link simplicity::Simplicity#addEntity(std::shared_ptr<Entity>) addEntity(std::shared_ptr<Entity>)}.
	 * </p>
	 */
	TEST_F(SimplicityTest, addEntity)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<Entity> entity(new Entity("entity"));

		// Perform test.
		// //////////////////////////////////////////////////
		Simplicity::addEntity(entity);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(Simplicity::getEntity("entity").get() != NULL);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::Simplicity#fireEvent(std::string) fireEvent(std::string)}.
	 * </p>
	 */
	TEST_F(SimplicityTest, fireEvent)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::function<void(boost::any)> observer(testObserver);

		// Initialise test environment.
		// //////////////////////////////////////////////////
		testObserverCalled = false;
		Simplicity::registerObserver("testEvent", observer);

		// Perform test.
		// //////////////////////////////////////////////////
		Simplicity::fireEvent("testEvent", this);

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(testObserverCalled);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::Simplicity#getEntity(std::string) getEntity(std::string)}.
	 * </p>
	 */
	TEST_F(SimplicityTest, getEntity)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		shared_ptr<Entity> entity(new Entity("entity"));

		// Initialise test environment.
		// //////////////////////////////////////////////////
		Simplicity::addEntity(entity);

		// Perform test - Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(Simplicity::getEntity("entity").get() != NULL);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::Simplicity#getEntity(std::string) getEntity(std::string)} with the
	 * special case that an <code>Entity</code> with the given name cannot be found.
	 * </p>
	 */
	TEST_F(SimplicityTest, getEntityNotExists)
	{
		// Perform test - Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(Simplicity::getEntity("entity").get() == NULL);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::Simplicity#reset() reset()}.
	 * </p>
	 */
	TEST_F(SimplicityTest, reset)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::unique_ptr<MockEngine> mockEngine(new testing::NiceMock<MockEngine>);
		std::shared_ptr<Entity> entity(new Entity("entity"));
		std::function<void(boost::any)> observer(testObserver);

		// Initialise test environment.
		// //////////////////////////////////////////////////
		testObserverCalled = false;
		Simplicity::init(move(mockEngine));
		Simplicity::addEntity(entity);
		Simplicity::registerObserver("testEvent", observer);

		// Perform test.
		// //////////////////////////////////////////////////
		Simplicity::reset();

		// Verify test results.
		// //////////////////////////////////////////////////
		ASSERT_TRUE(Simplicity::getEntity("entity").get() == NULL);

		Simplicity::fireEvent("testEvent", this);
		ASSERT_FALSE(testObserverCalled);
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::Simplicity#start() start()}.
	 * </p>
	 */
	TEST_F(SimplicityTest, start)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::unique_ptr<MockEngine> mockEngine(new testing::NiceMock<MockEngine>);
		MockEngine& engineRef = *mockEngine;

		// Initialise test environment.
		// //////////////////////////////////////////////////
		Simplicity::init(move(mockEngine));

		// Dictate expected results.
		// //////////////////////////////////////////////////
		EXPECT_CALL(engineRef, run());

		// Perform test.
		// //////////////////////////////////////////////////
		Simplicity::start();

		// Cleanup.
		// //////////////////////////////////////////////////
		Simplicity::stop();
		Simplicity::reset();
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::Simplicity#stop() stop()}.
	 * </p>
	 */
	TEST_F(SimplicityTest, stop)
	{
		// Create dependencies.
		// //////////////////////////////////////////////////
		std::unique_ptr<MockEngine> mockEngine(new testing::NiceMock<MockEngine>);
		MockEngine& engineRef = *mockEngine;

		// Initialise test environment.
		// //////////////////////////////////////////////////
		Simplicity::init(move(mockEngine));

		// Dictate expected results.
		// //////////////////////////////////////////////////
		EXPECT_CALL(engineRef, destroy());

		// Perform test.
		// //////////////////////////////////////////////////
		Simplicity::stop();

		// Cleanup.
		// //////////////////////////////////////////////////
		Simplicity::reset();
	}
}
