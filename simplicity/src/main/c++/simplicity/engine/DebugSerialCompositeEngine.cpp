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
#include "../common/AddressEquals.h"
#include "../common/Timer.h"
#include "DebugSerialCompositeEngine.h"

using namespace std;
using namespace std::chrono;

namespace simplicity
{
	DebugSerialCompositeEngine::DebugSerialCompositeEngine() :
			engineFrameTimes(),
			engines(),
			frameCount(0),
			framesPerSecond(0),
			frameTime(0.0f)
	{
	}

	void DebugSerialCompositeEngine::addEngine(unique_ptr<Engine> engine)
	{
		engineFrameTimes.push_back(0.0f);
		engines.push_back(move(engine));
	}

	void DebugSerialCompositeEngine::addEntity(Entity& entity)
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->addEntity(entity);
		}
	}

	void DebugSerialCompositeEngine::advance()
	{
		Timer frameTimer;

		for (unsigned int index = 0; index < engines.size(); index++)
		{
			Timer engineFrameTimer;

			engines[index]->advance();

			engineFrameTimes[index] = engineFrameTimer.getElapsedTime();
		}

		frameTime = frameTimer.getElapsedTime();

		frameCount++;

		// If at least one second has passed since the last FPS was recorded.
		time_point<high_resolution_clock> frameEndTime = high_resolution_clock::now();
		if (duration_cast<seconds>(frameEndTime - lastFrameCountTime).count() >= 1)
		{
			lastFrameCountTime = frameEndTime;
			framesPerSecond = frameCount;
			frameCount = 0;
		}
	}

	void DebugSerialCompositeEngine::destroy()
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->destroy();
		}
	}

	const vector<float>& DebugSerialCompositeEngine::getEngineFrameTimes() const
	{
		return engineFrameTimes;
	}

	const vector<unique_ptr<Engine>>& DebugSerialCompositeEngine::getEngines() const
	{
		return engines;
	}

	unsigned int DebugSerialCompositeEngine::getFramesPerSecond() const
	{
		return framesPerSecond;
	}

	float DebugSerialCompositeEngine::getFrameTime() const
	{
		return frameTime;
	}

	void DebugSerialCompositeEngine::init()
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->init();
		}

		lastFrameCountTime = high_resolution_clock::now();
	}

	unique_ptr<Engine> DebugSerialCompositeEngine::removeEngine(Engine* engine)
	{
		unique_ptr<Engine> removedEngine;
		vector<unique_ptr<Engine>>::iterator result =
				find_if(engines.begin(), engines.end(), AddressEquals<Engine>(*engine));

		if (result != engines.end())
		{
			removedEngine = move(*result);
			engines.erase(result);
			engine = NULL;
		}

		return move(removedEngine);
	}

	void DebugSerialCompositeEngine::removeEntity(const Entity& entity)
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->removeEntity(entity);
		}
	}
}
