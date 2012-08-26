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

#include "../common/AddressEquals.h"
#include "SimpleCompositeEngine.h"

using namespace std;

namespace simplicity
{
	SimpleCompositeEngine::SimpleCompositeEngine() :
		advanceIndex(0), compositeFrequency(1), engines()
	{
	}

	SimpleCompositeEngine::~SimpleCompositeEngine()
	{
	}

	void SimpleCompositeEngine::addEngine(shared_ptr<Engine> engine)
	{
		engines.push_back(engine);
	}

	void SimpleCompositeEngine::addEntity(shared_ptr<Entity> entity)
	{
		for (shared_ptr<Engine> engine : engines)
		{
			engine->addEntity(entity);
		}
	}

	vector<shared_ptr<Action> > SimpleCompositeEngine::advance(vector<shared_ptr<Action> > actions)
	{
		advanceIndex++;
		vector<shared_ptr<Action> > currentActions = actions;

		for (shared_ptr<Engine> engine : engines)
		{
			// If the sub-engine should be advanced at this time (if it's preferred frequency is a multiple of the
			// composite frequency).
			if (advanceIndex % (compositeFrequency / engine->getPreferredFrequency()) == 0)
			{
				currentActions = engine->advance(currentActions);
			}
		}

		return currentActions;
	}

	int SimpleCompositeEngine::calculateLCD(int a, int b) const
	{
		// Ensure that 'a' is the smaller of the two.
		if (a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		int gcd = a;

		if (b != 0)
		{
			gcd = a % b;
		}

		if (gcd == 0)
		{
			return (a);
		}

		return a * b / gcd;
	}

	void SimpleCompositeEngine::destroy()
	{
		for (shared_ptr<Engine> engine : engines)
		{
			engine->destroy();
		}
	}

	int SimpleCompositeEngine::getCompositeFrequency() const
	{
		int compositeFrequency = 1;

		for (shared_ptr<Engine> engine : engines)
		{
			compositeFrequency = calculateLCD(compositeFrequency, engine->getPreferredFrequency());
		}

		return compositeFrequency;
	}

	void SimpleCompositeEngine::onInit()
	{
		advanceIndex = 0;
		compositeFrequency = getCompositeFrequency();
		setPreferredFrequency(compositeFrequency);

		for (shared_ptr<Engine> engine : engines)
		{
			engine->init();
		}
	}

	void SimpleCompositeEngine::onReset()
	{
		advanceIndex = 0;
		setPreferredFrequency(getCompositeFrequency());

		for (shared_ptr<Engine> engine : engines)
		{
			engine->reset();
		}
	}

	void SimpleCompositeEngine::removeEngine(const Engine& engine)
	{
		engines.erase(remove_if(engines.begin(), engines.end(), AddressEquals<Engine>(engine)));
	}

	void SimpleCompositeEngine::removeEntity(const Entity& entity)
	{
		for (shared_ptr<Engine> engine : engines)
		{
			engine->removeEntity(entity);
		}
	}
}
