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
#include <chrono>
#include <map>
#include <thread>
#include <vector>

#include "engine/SerialCompositeEngine.h"
#include "messaging/Events.h"
#include "Simplicity.h"

using namespace std;
using namespace std::chrono;

namespace simplicity
{
	namespace Simplicity
	{
		unique_ptr<CompositeEngine> compositeEngine(new SerialCompositeEngine);
		Scene* currentScene = NULL;
		float frameTime = 0.0f;
		float totalTime = 0.0f;
		bool initialised = false;
		unsigned short maxFrameRate = 0;
		bool paused = false;
		time_point<high_resolution_clock> playTime;
		map<string, unique_ptr<Scene>> scenes;
		bool stopped = false;

		void addEngine(unique_ptr<Engine> engine)
		{
			if (initialised)
			{
				engine->init();
			}

			compositeEngine->addEngine(move(engine));
		}

		void addScene(const string& name, unique_ptr<Scene> scene)
		{
			if (currentScene == NULL)
			{
				currentScene = scene.get();
			}

			scenes[name] = move(scene);
		}

		CompositeEngine* getCompositeEngine()
		{
			return compositeEngine.get();
		}

		float getDeltaTime()
		{
			return frameTime;
		}

		unsigned short getMaxFrameRate()
		{
			return maxFrameRate;
		}

		Scene* getScene()
		{
			return currentScene;
		}

		float getTotalTime()
		{
			return totalTime;
		}

		void openScene(const string& name)
		{
			currentScene = scenes[name].get();
		}

		void pause()
		{
			paused = true;
		}

		void play()
		{
			if (stopped)
			{
				return;
			}

			paused = false;

			if (!initialised)
			{
				compositeEngine->init();

				initialised = true;
				playTime = high_resolution_clock::now();
			}

			while (!paused && !stopped)
			{
				time_point<high_resolution_clock> frameStartTime = high_resolution_clock::now();

				currentScene->addPendingEntities();
				compositeEngine->advance();
				currentScene->removePendingEntities();

				time_point<high_resolution_clock> frameEndTime = high_resolution_clock::now();
				frameTime = duration_cast<nanoseconds>(frameEndTime - frameStartTime).count() / 1000000000.0f;
				totalTime = duration_cast<nanoseconds>(frameEndTime - playTime).count() / 1000000000.0f;

				if (maxFrameRate != 0)
				{
					float sleepTime = 1.0f / maxFrameRate - frameTime;
					sleepTime *= 1000.0f;
					if (sleepTime > 0.0f)
					{
						this_thread::sleep_for(milliseconds((long) sleepTime));
					}
				}
			}
		}

		unique_ptr<Engine> removeEngine(Engine* engine)
		{
			return compositeEngine->removeEngine(engine);
		}

		void setCompositeEngine(unique_ptr<CompositeEngine> compositeEngine)
		{
			Simplicity::compositeEngine = move(compositeEngine);
		}

		void setMaxFrameRate(unsigned short maxFrameRate)
		{
			Simplicity::maxFrameRate = maxFrameRate;
		}

		void stop()
		{
			stopped = true;
		}
	}
}
