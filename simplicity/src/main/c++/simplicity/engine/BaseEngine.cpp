/*
 * Copyright © 2011 Simple Entertainment Limited
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
#include <exception>
#include <string>

#include <boost/date_time.hpp>
#include <boost/thread.hpp>
#include <log4cpp/Category.hh>

#include "BaseEngine.h"

using namespace boost;
using namespace boost::posix_time;
using namespace boost::this_thread;
using namespace std;

namespace simplicity
{
	log4cpp::Category& BaseEngine::logger = log4cpp::Category::getInstance("simplicity::BaseEngine");

	const double BaseEngine::MILLISECONDS_IN_A_SECOND = 1000.0;

	BaseEngine::BaseEngine() :
		preferredFrequency(1), sleepTime(0L)
	{
	}

	BaseEngine::~BaseEngine()
	{
	}

	int BaseEngine::getPreferredFrequency() const
	{
		return preferredFrequency;
	}

	void BaseEngine::init()
	{
		onInit();

		interrupted = false;
		sleepTime = (long) (MILLISECONDS_IN_A_SECOND / preferredFrequency);
	}

	void BaseEngine::reset()
	{
		onReset();

		interrupted = false;
		sleepTime = (long) (MILLISECONDS_IN_A_SECOND / preferredFrequency);
	}

	void BaseEngine::run()
	{
		init();

		// Start by sleeping.
		ptime beforeAdvanceTime;
		long adjustedSleepTime = sleep(sleepTime);

		// While the engine has not been interrupted.
		while (!interrupted)
		{
			// Interrupt the engine if the thread has been interrupted.
			interruption_point();

			beforeAdvanceTime = microsec_clock::local_time();

			try
			{
				advance(vector<std::shared_ptr<Action> >());
			}
			catch (std::exception& e)
			{
				// Interrupt the engine.
				interrupted = true;
				logger.error("Failed to advance the engine.");
			}

			// Subtract the time taken to advance the engine from the time it needs to sleep for.
			adjustedSleepTime -=
				time_period(beforeAdvanceTime, microsec_clock::local_time()).length().total_milliseconds();

			// Sleep until the next advancement is due.
			adjustedSleepTime = sleep(adjustedSleepTime);
		}

		destroy();
	}

	void BaseEngine::setPreferredFrequency(const int preferredFrequency)
	{
		this->preferredFrequency = preferredFrequency;
	}

	long BaseEngine::sleep(const long adjustedSleepTime)
	{
		// If the engine needs to sleep.
		if (adjustedSleepTime > 0)
		{
			try
			{
				this_thread::sleep(milliseconds(adjustedSleepTime));
			}
			catch (thread_interrupted& e)
			{
				// Interrupt the engine.
				interrupted = true;
				logger.debug("The engine was interrupted while sleeping.");
			}

			// Return the standard sleep duration.
			return (sleepTime);
		}
		else
		{
			logger.warn("The engine ran over time.");

			// The engine has not slept as a result it has 'caught up' by the standard sleep duration.
			return (adjustedSleepTime + sleepTime);
		}
	}
}
