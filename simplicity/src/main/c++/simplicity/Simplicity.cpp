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

#include "common/AddressEquals.h"
#include "engine/SerialCompositeEngine.h"
#include "messaging/Events.h"
#include "Simplicity.h"

using namespace std;
using namespace std::chrono;

namespace simplicity
{
	namespace Simplicity
	{
		void addPendingEntities();
		void removePendingEntities();

		unique_ptr<CompositeEngine> compositeEngine(new SerialCompositeEngine);
		vector<unique_ptr<Entity>> entities;
		vector<unique_ptr<Entity>> entitiesToBeAdded;
		map<Entity*, const Entity*> entitiesToBeAddedParents;
		vector<const Entity*> entitiesToBeRemoved;
		float frameTime = 0.0f;
		float totalTime = 0.0f;
		bool initialised = false;
		unsigned short maxFrameRate = 0;
		bool paused = false;
		time_point<high_resolution_clock> playTime;
		bool stopped = false;
        vector<unique_ptr<Graph>> worldRepresentations;

		void addEngine(unique_ptr<Engine> engine)
		{
			if (initialised)
			{
				engine->init();
			}

			compositeEngine->addEngine(move(engine));
		}

		void addEntity(unique_ptr<Entity> entity)
		{
			entitiesToBeAdded.push_back(move(entity));
		}

		void addEntity(unique_ptr<Entity> entity, const Entity& parent)
		{
			entitiesToBeAddedParents[entity.get()] = &parent;
			entitiesToBeAdded.push_back(move(entity));
		}

		void addPendingEntities()
		{
			for (unsigned int entityIndex = 0; entityIndex < entitiesToBeAdded.size(); entityIndex++)
			{
				compositeEngine->addEntity(*entitiesToBeAdded[entityIndex]);

                for (unsigned int worldIndex = 0; worldIndex < worldRepresentations.size(); worldIndex++)
                {
                	const Entity* parent = NULL;//entitiesToBeAddedParents[entitiesToBeAdded[entityIndex].get()];
                	if (parent == NULL)
                	{
                		worldRepresentations[worldIndex]->insert(*entitiesToBeAdded[entityIndex]);
                	}
                	else
                	{
                		worldRepresentations[worldIndex]->insert(*entitiesToBeAdded[entityIndex], *parent);
                	}
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

        vector<Entity*> getEntities(unsigned short category)
		{
        	vector<Entity*> rawEntities;

        	for (unsigned int index = 0; index < entities.size(); index++)
        	{
        		if (category == Categories::ALL_CATEGORIES || entities[index]->getCategory() == category)
        		{
        			rawEntities.push_back(entities[index].get());
        		}
        	}

        	return rawEntities;
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
				compositeEngine->init();

				initialised = true;
				playTime = high_resolution_clock::now();
			}

			while (!paused && !stopped)
			{
				time_point<high_resolution_clock> frameStartTime = high_resolution_clock::now();

				addPendingEntities();
				compositeEngine->advance();
				removePendingEntities();

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

		void removeEntity(Entity* entity)
		{
			entitiesToBeRemoved.push_back(entity);
		}

		void removePendingEntities()
		{
			for (unsigned int entityIndex = 0; entityIndex < entitiesToBeRemoved.size(); entityIndex++)
			{
				vector<unique_ptr<Entity>>::iterator result =
						find_if(entities.begin(), entities.end(), AddressEquals<Entity>(*entitiesToBeRemoved[entityIndex]));

				if (result != entities.end())
				{
					compositeEngine->removeEntity(**result);

					for (unsigned int worldIndex = 0; worldIndex < worldRepresentations.size(); worldIndex++)
					{
						worldRepresentations[worldIndex]->remove(**result);
					}

					entities.erase(result);
				}
			}
			entitiesToBeRemoved.clear();
		}

		void setCompositeEngine(unique_ptr<CompositeEngine> compositeEngine)
		{
			Simplicity::compositeEngine.release();
			Simplicity::compositeEngine.swap(compositeEngine);
		}

		void setMaxFrameRate(unsigned short maxFrameRate)
		{
			Simplicity::maxFrameRate = maxFrameRate;
		}

		void stop()
		{
			stopped = true;
		}

        void updateWorldRepresentations(Entity& entity)
        {
        	for (unsigned int index = 0; index < worldRepresentations.size(); index++)
        	{
        		worldRepresentations[index]->update(entity);
        	}
        }
	}
}
