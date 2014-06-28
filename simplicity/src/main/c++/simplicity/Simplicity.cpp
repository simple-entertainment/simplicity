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
#include <map>
#include <thread>
#include <vector>

#include "common/Timer.h"
#include "engine/SerialCompositeEngine.h"
#include "messaging/Subject.h"
#include "Simplicity.h"

using namespace std;
using namespace std::chrono;

namespace simplicity
{
	namespace Simplicity
	{
		unique_ptr<CompositeEngine> compositeEngine(new SerialCompositeEngine);
		Scene* currentScene = nullptr;
		float frameTime = 0.0f;
		unsigned long id = 0;
		unsigned short maxFrameRate = 0;
		bool newlyOpenedScene = true;
		bool paused = false;
		map<string, unique_ptr<Scene>> scenes;
		bool stopped = true;
		float totalTime = 0.0f;
		Timer totalTimer;

		void addEngine(unique_ptr<Engine> engine)
		{
			compositeEngine->addEngine(move(engine));
		}

		void addScene(const string& name, unique_ptr<Scene> scene)
		{
			if (currentScene == nullptr)
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

		unsigned long getId()
		{
			return id;
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

		bool isPlaying()
		{
			return !paused && !stopped;
		}

		void openScene(const string& name)
		{
			currentScene = scenes[name].get();

			if (isPlaying())
			{
				newlyOpenedScene = true;
			}
		}

		void pause()
		{
			paused = true;
		}

		void play()
		{
			if (paused)
			{
				compositeEngine->onResume();

				paused = false;
				totalTimer.resume();
			}

			if (stopped)
			{
				compositeEngine->onPlay();

				stopped = false;
				totalTimer.reset();
			}

			while (!paused && !stopped)
			{
				Timer frameTimer;

				currentScene->addPendingEntities();

				if (newlyOpenedScene)
				{
					compositeEngine->onOpenScene(*currentScene);
					newlyOpenedScene = false;
				}

				compositeEngine->advance();

				currentScene->removePendingEntities();

				frameTime = frameTimer.getElapsedTime();
				totalTime = totalTimer.getElapsedTime();

				if (maxFrameRate != 0)
				{
					// Limit the frame rate.
					float sleepTime = 1.0f / maxFrameRate - frameTime;
					sleepTime *= 1000.0f;
					if (sleepTime > 0.0f)
					{
						this_thread::sleep_for(milliseconds(static_cast<long>(sleepTime)));
					}
				}
			}

			if (paused)
			{
				totalTimer.pause();

				compositeEngine->onPause();
			}

			if (stopped)
			{
				compositeEngine->onStop();
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

		void setId(unsigned long id)
		{
			Simplicity::id = id;
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
