/*
 * Copyright © Simple Entertainment Limited 2011
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
#include <boost/function.hpp>
#include <boost/thread.hpp>

#include "RunnableEngineTest.h"

using namespace boost;

namespace simplicity
{
	/**
	 * <p>
	 * Unit test the method {@link simplicity::RunnableEngine#run() run()}.
	 * </p>
	 */
	TEST_F(RunnableEngineTest, run)
	{
		// Initialise test environment.
		fTestObject.setPreferredFrequency(5);

		// Perform test.
		thread engineThread(bind(&OverrunningFakeRunnableEngine::run, &fTestObject));

		this_thread::sleep(posix_time::milliseconds(2500));

		engineThread.interrupt();
		engineThread.join();

		// Verify test results.
		ASSERT_EQ(1, fTestObject.getInitCount());
		ASSERT_EQ(12, fTestObject.getAdvanceCount());
		ASSERT_EQ(1, fTestObject.getDestroyCount());
	}

	/**
	 * <p>
	 * Unit test the method {@link simplicity::RunnableEngine#run() run()} with the special condition that it runs
	 * longer than is allowed by its preferred frequency.
	 * </p>
	 */
	TEST_F(RunnableEngineTest, runOverrunFrequency)
	{
		// Initialise test environment.
		fTestObject.setPreferredFrequency(5);
		fTestObject.setOverrunIndex(2);

		// Perform test.
		thread engineThread(bind(&OverrunningFakeRunnableEngine::run, &fTestObject));

		this_thread::sleep(posix_time::milliseconds(2500));

		engineThread.interrupt();
		engineThread.join();

		// Verify test results.
		ASSERT_EQ(12, fTestObject.getAdvanceCount());
	}
}
