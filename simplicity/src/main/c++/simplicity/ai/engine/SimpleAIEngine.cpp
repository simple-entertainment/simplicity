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
#include <algorithm>

#include "SimpleAIEngine.h"

using namespace std;

namespace simplicity
{
	SimpleAIEngine::SimpleAIEngine()
	{
	}

	SimpleAIEngine::~SimpleAIEngine()
	{
	}

	void SimpleAIEngine::addEntity(shared_ptr<Entity> entity)
	{
		for (shared_ptr<Agent> agent : entity->getComponents<Agent>())
		{
			agents.push_back(agent);
		}
	}

	vector<shared_ptr<Action> > SimpleAIEngine::advance(vector<shared_ptr<Action> > actions)
	{
		// Does not use C++11 for loop as elements could be added to the vector while iterating.
		// Take care - this is a fragile 'solution'.
		for (unsigned int index = 0; index < agents.size(); index++)
		{
			vector<shared_ptr<Action> > agentActions = agents.at(index)->think();
			actions.insert(actions.end(), agentActions.begin(), agentActions.end());
		}

		return actions;
	}

	void SimpleAIEngine::destroy()
	{
	}

	const std::vector<shared_ptr<Agent> > SimpleAIEngine::getAgents()
	{
		return agents;
	}

	void SimpleAIEngine::onInit()
	{
	}

	void SimpleAIEngine::onReset()
	{
	}

	void SimpleAIEngine::removeEntity(const Entity& entity)
	{
		for (shared_ptr<Agent> agent : entity.getComponents<Agent>())
		{
			agents.erase(remove(agents.begin(), agents.end(), agent));
		}
	}
}
