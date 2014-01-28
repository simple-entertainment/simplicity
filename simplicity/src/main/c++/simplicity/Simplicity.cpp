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
#include <algorithm>
#include <chrono>
#include <map>
#include <thread>
#include <vector>

#include <boost/timer/timer.hpp>

#include "Events.h"
#include "common/AddressEquals.h"
#include "Simplicity.h"

using namespace boost::timer;
using namespace std;

namespace simplicity
{
	namespace Simplicity
	{
		void addPendingEntities();
		void removePendingEntities();

		vector<unique_ptr<Engine>> engines;
		vector<unique_ptr<Entity>> entities;
		vector<unique_ptr<Entity>> entitiesToBeAdded;
		vector<const Entity*> entitiesToBeRemoved;
		float frameTime = 0.0f;
		cpu_timer frameTimer;
		float totalTime = 0.0f;
		cpu_timer totalTimer;
		bool initialised = false;
		unsigned short maxFrameRate = 0;
		bool paused = false;
		bool stopped = false;
        vector<unique_ptr<Graph>> worldRepresentations;

		void addEngine(unique_ptr<Engine> engine)
		{
			engines.push_back(move(engine));

			if (initialised)
			{
				engine->init();
			}
		}

		void addEntity(unique_ptr<Entity> entity)
		{
			entitiesToBeAdded.push_back(move(entity));
		}

		void addPendingEntities()
		{
			for (unsigned int entityIndex = 0; entityIndex < entitiesToBeAdded.size(); entityIndex++)
			{
				for (unsigned int engineIndex = 0; engineIndex < engines.size(); engineIndex++)
				{
					engines[engineIndex]->addEntity(*entitiesToBeAdded[entityIndex]);
				}

                for (unsigned int worldIndex = 0; worldIndex < worldRepresentations.size(); worldIndex++)
                {
                    worldRepresentations[worldIndex]->insert(*entitiesToBeAdded[entityIndex]);
                }

				entities.push_back(move(entitiesToBeAdded[entityIndex]));
			}
			entitiesToBeAdded.clear();
		}

        void addWorldRepresentation(unique_ptr<Graph> graph)
        {
        	worldRepresentations.push_back(move(graph));
        }

		float getDeltaTime()
		{
			return frameTime;
		}

		unsigned short getMaxFrameRate()
		{
			return maxFrameRate;
		}

		float getTotalTime()
		{
			return totalTime;
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
				totalTimer.start();

				for (unsigned int index = 0; index < engines.size(); index++)
				{
					engines[index]->init();
				}

				initialised = true;
			}

			while (!paused && !stopped)
			{
				frameTimer.start();

				addPendingEntities();
				for (unsigned int index = 0; index < engines.size(); index++)
				{
					engines[index]->advance();
				}
				removePendingEntities();

				frameTimer.stop();
				frameTime = frameTimer.elapsed().wall / 1000000000.0f;
				totalTime = totalTimer.elapsed().wall / 1000000000.0f;

				if (maxFrameRate != 0)
				{
					float sleepTime = 1.0f / maxFrameRate - frameTime;
					sleepTime *= 1000.0f;
					if (sleepTime > 0.0f)
					{
						this_thread::sleep_for(chrono::milliseconds((long) sleepTime));
					}
				}
			}
		}

		void removeEngine(const Engine& engine)
		{
			vector<unique_ptr<Engine>>::iterator result =
					find_if(engines.begin(), engines.end(), AddressEquals<Engine>(engine));

			if (result != engines.end())
			{
				engines.erase(result);
			}
		}

		void removeEntity(const Entity& entity)
		{
			vector<unique_ptr<Entity>>::iterator result =
					find_if(entities.begin(), entities.end(), AddressEquals<Entity>(entity));

			if (result != entities.end())
			{
				entitiesToBeRemoved.push_back(result->get());
			}
		}

		void removePendingEntities()
		{
			for (unsigned int entityIndex = 0; entityIndex < entitiesToBeRemoved.size(); entityIndex++)
			{
				vector<unique_ptr<Entity>>::iterator result =
						find_if(entities.begin(), entities.end(), AddressEquals<Entity>(*entitiesToBeRemoved[entityIndex]));

				if (result != entities.end())
				{
					for (unsigned int engineIndex = 0; engineIndex < engines.size(); engineIndex++)
					{
						engines[engineIndex]->removeEntity(**result);
					}

					for (unsigned int worldIndex = 0; worldIndex < worldRepresentations.size(); worldIndex++)
					{
						worldRepresentations[worldIndex]->remove(**result);
					}

					entities.erase(result);
				}
			}
			entitiesToBeRemoved.clear();
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
