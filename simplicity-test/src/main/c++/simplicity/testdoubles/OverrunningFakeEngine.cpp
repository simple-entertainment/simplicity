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
#include <boost/thread.hpp>

#include "OverrunningFakeEngine.h"

using namespace boost;
using namespace std;

namespace simplicity
{
	const double OverrunningFakeEngine::FRACTION_OF_FREQUENCY_TO_WAIT = 1.5;

	log4cpp::Category& OverrunningFakeEngine::logger = log4cpp::Category::getInstance(
		"simplicity::OverrunningFakeEngine");

	const double OverrunningFakeEngine::MILLISECONDS_IN_A_SECOND = 1000.0;

	OverrunningFakeEngine::OverrunningFakeEngine() :
		advanceCount(0), advanceIndex(0), destroyCount(0), initCount(0), overrunIndex(-1)
	{
	}

	OverrunningFakeEngine::~OverrunningFakeEngine()
	{
	}

	void OverrunningFakeEngine::addEntity(std::shared_ptr<Entity> entity)
	{
	}

	std::shared_ptr<EngineInput> OverrunningFakeEngine::advance(const std::shared_ptr<EngineInput> input)
	{
		advanceCount++;

		if (++advanceIndex == overrunIndex)
		{
			try
			{
				this_thread::sleep(
					posix_time::milliseconds(
						MILLISECONDS_IN_A_SECOND / getPreferredFrequency() * FRACTION_OF_FREQUENCY_TO_WAIT));
			}
			catch (thread_interrupted& e)
			{
				logger.error("The engine was interrupted while advancing.");
			}
		}

		return std::shared_ptr<EngineInput>();
	}

	void OverrunningFakeEngine::destroy()
	{
		destroyCount++;
	}

	int OverrunningFakeEngine::getAdvanceCount()
	{
		return advanceCount;
	}

	int OverrunningFakeEngine::getDestroyCount()
	{
		return destroyCount;
	}

	int OverrunningFakeEngine::getInitCount()
	{
		return initCount;
	}

	int OverrunningFakeEngine::getOverrunIndex() const
	{
		return overrunIndex;
	}

	void OverrunningFakeEngine::onInit()
	{
		initCount++;
	}

	void OverrunningFakeEngine::onReset()
	{
	}

	void OverrunningFakeEngine::setOverrunIndex(const int overrunIndex)
	{
		this->overrunIndex = overrunIndex;
	}
}
