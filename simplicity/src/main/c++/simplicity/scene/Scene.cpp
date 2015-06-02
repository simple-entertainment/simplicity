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
#include "../Simplicity.h"
#include "Scene.h"

using namespace std;

namespace simplicity
{
	Scene::Scene() :
			entities(),
			entitiesToBeAdded(),
			entitiesToBeAddedParents(),
			entitiesToBeRemoved(),
			graphs()
	{
	}

	void Scene::addEntity(unique_ptr<Entity> entity)
	{
		entitiesToBeAdded.push_back(move(entity));
	}

	void Scene::addEntity(unique_ptr<Entity> entity, const Entity& parent)
	{
		entitiesToBeAddedParents[entity.get()] = &parent;
		entitiesToBeAdded.push_back(move(entity));
	}

	void Scene::addGraph(unique_ptr<Graph> graph)
    {
    	graphs.push_back(move(graph));
    }

	void Scene::addPendingEntities()
	{
		for (unsigned int entityIndex = 0; entityIndex < entitiesToBeAdded.size(); entityIndex++)
		{
			Simplicity::getCompositeEngine()->onAddEntity(*entitiesToBeAdded[entityIndex]);

			for (unsigned int graphIndex = 0; graphIndex < graphs.size(); graphIndex++)
			{
				const Entity* parent = nullptr;//entitiesToBeAddedParents[entitiesToBeAdded[entityIndex].get()];
				if (parent == nullptr)
				{
					graphs[graphIndex]->insert(*entitiesToBeAdded[entityIndex]);
				}
				else
				{
					graphs[graphIndex]->insert(*entitiesToBeAdded[entityIndex], *parent);
				}
			}

			entities.push_back(move(entitiesToBeAdded[entityIndex]));
		}
		entitiesToBeAdded.clear();
	}

    vector<Entity*> Scene::getEntities(unsigned short category)
	{
    	vector<Entity*> rawEntities;

    	for (unsigned int index = 0; index < entities.size(); index++)
    	{
			if (category == Category::ALL_CATEGORIES || entities[index]->getCategory() == category)
    		{
    			rawEntities.push_back(entities[index].get());
    		}
    	}

    	return rawEntities;
	}

	void Scene::removeEntity(Entity* entity)
	{
		entitiesToBeRemoved.push_back(entity);
	}

	void Scene::removePendingEntities()
	{
		for (unsigned int entityIndex = 0; entityIndex < entitiesToBeRemoved.size(); entityIndex++)
		{
			vector<unique_ptr<Entity>>::iterator result =
					find_if(entities.begin(), entities.end(), AddressEquals<Entity>(*entitiesToBeRemoved[entityIndex]));

			if (result != entities.end())
			{
				Simplicity::getCompositeEngine()->onRemoveEntity(**result);

				for (unsigned int graphIndex = 0; graphIndex < graphs.size(); graphIndex++)
				{
					graphs[graphIndex]->remove(**result);
				}

				entities.erase(result);
			}
		}
		entitiesToBeRemoved.clear();
	}

    void Scene::updateGraphs(Entity& entity)
    {
    	for (unsigned int index = 0; index < graphs.size(); index++)
    	{
    		graphs[index]->update(entity);
    	}
    }
}
