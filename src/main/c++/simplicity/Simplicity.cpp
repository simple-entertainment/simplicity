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
#include "Simplicity.h"

using namespace std;
using namespace std::chrono;

namespace simplicity
{
	namespace Simplicity
	{
		unique_ptr<CompositeEngine> compositeEngine;
		float frameTime = 0.0f;
		unsigned long id = 0;
		unsigned short maxFrameRate = 0;
		Scene* scene = nullptr;
		map<string, unique_ptr<Scene>> scenes;
		Scene* sceneToBeOpened = nullptr;
		State state = State::STOPPED;
		float totalTime = 0.0f;
		Timer totalTimer;

		void addEngine(unique_ptr<Engine> engine)
		{
			// Provide the default composite engine.
			if (compositeEngine == nullptr)
			{
				compositeEngine = unique_ptr<CompositeEngine>(new SerialCompositeEngine);
			}

			compositeEngine->addEngine(move(engine));
		}

		void addScene(const string& name, unique_ptr<Scene> scene)
		{
			if (scenes.size() == 0)
			{
				sceneToBeOpened = scene.get();
			}

			scenes[name] = move(scene);
		}

		void finishPlayback()
		{
			if (state == State::PAUSED || state == State::STOPPED)
			{
				return;
			}

			// TODO Close all scenes?
			scene->pause();
			compositeEngine->onPause();

			if (state == State::PAUSING)
			{
				totalTimer.pause();
				state = State::PAUSED;
			}

			if (state == State::STOPPING)
			{
				compositeEngine->onStop();
				state = State::STOPPED;
			}
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
			if (scene == nullptr)
			{
				if (sceneToBeOpened == nullptr)
				{
					// Provide a default scene.
					unique_ptr<Scene> defaultScene(new Scene);
					addScene("default", move(defaultScene));
				}

				return sceneToBeOpened;
			}

			return scene;
		}

		State getState()
		{
			return state;
		}

		float getTotalTime()
		{
			return totalTime;
		}

		void openScene(const string& name)
		{
			sceneToBeOpened = scenes[name].get();
		}

		void pause()
		{
			state = State::PAUSING;
		}

		void play()
		{
			startPlayback();

			while (state == State::PLAYING)
			{
				playOneFrame();
			}

			finishPlayback();
		}

		void playOneFrame()
		{
			Timer frameTimer;

			if (sceneToBeOpened != nullptr)
			{
				if (scene != nullptr)
				{
					scene->pause();
					compositeEngine->onCloseScene(*scene);
				}

				scene = sceneToBeOpened;
				sceneToBeOpened = nullptr;

				compositeEngine->onBeforeOpenScene(*scene);

				scene->open();
				compositeEngine->onOpenScene(*scene);
				scene->resume();
			}

			compositeEngine->advance(*scene);

			frameTime = frameTimer.getElapsedTime();
			totalTime = totalTimer.getElapsedTime();

			if (maxFrameRate != 0)
			{
				// Limit the frame rate.
				float sleepTime = 1.0f / maxFrameRate - frameTime;
				if (sleepTime > 0.0f)
				{
					this_thread::sleep_for(milliseconds(static_cast<long>(sleepTime * 1000)));
				}
			}
		}

		unique_ptr<Engine> removeEngine(Engine& engine)
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

		void startPlayback()
		{
			if (state == State::PLAYING)
			{
				return;
			}

			if (state == State::PAUSED)
			{
				totalTimer.resume();
			}

			if (state == State::STOPPED)
			{
				compositeEngine->onPlay();

				totalTimer.reset();
			}

			compositeEngine->onResume();
			if (scene != nullptr)
			{
				scene->resume();
			}

			state = State::PLAYING;
		}

		void stop()
		{
			state = State::STOPPING;
		}
	}
}
