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
#include <boost/thread.hpp>

#include "OverrunningFakeRunnableEngine.h"

using namespace boost;
using namespace std;

namespace simplicity
{
	log4cpp::Category& OverrunningFakeRunnableEngine::logger = log4cpp::Category::getInstance(
		"simplicity::OverrunningFakeRunnableEngine");

	OverrunningFakeRunnableEngine::OverrunningFakeRunnableEngine() :
		advanceCount(0), advanceIndex(0), destroyCount(0), initCount(0), overrunIndex(-1)
	{
	}

	OverrunningFakeRunnableEngine::~OverrunningFakeRunnableEngine()
	{
	}

	void OverrunningFakeRunnableEngine::addEntities(vector<shared_ptr<Entity> > entities)
	{
	}

	void OverrunningFakeRunnableEngine::addEntity(shared_ptr<Entity> entity)
	{
	}

	shared_ptr<EngineInput> OverrunningFakeRunnableEngine::advance(const shared_ptr<EngineInput> input)
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

		return shared_ptr<EngineInput>();
	}

	void OverrunningFakeRunnableEngine::destroy()
	{
		destroyCount++;
	}

	int OverrunningFakeRunnableEngine::getAdvanceCount()
	{
		return advanceCount;
	}

	int OverrunningFakeRunnableEngine::getDestroyCount()
	{
		return destroyCount;
	}

	int OverrunningFakeRunnableEngine::getInitCount()
	{
		return initCount;
	}

	int OverrunningFakeRunnableEngine::getOverrunIndex() const
	{
		return overrunIndex;
	}

	void OverrunningFakeRunnableEngine::init()
	{
		initCount++;

		RunnableEngine::init();
	}

	void OverrunningFakeRunnableEngine::initInternal()
	{
		RunnableEngine::initInternal();
	}

	void OverrunningFakeRunnableEngine::reset()
	{
	}

	void OverrunningFakeRunnableEngine::setOverrunIndex(const int overrunIndex)
	{
		this->overrunIndex = overrunIndex;
	}
}
