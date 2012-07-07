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

#include "../SENotSupportedException.h"
#include "SimpleCompositeEngine.h"

using namespace std;

namespace simplicity
{
	SimpleCompositeEngine::SimpleCompositeEngine() :
		engines()
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
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines.at(index)->addEntity(entity);
		}
	}

	shared_ptr<EngineInput> SimpleCompositeEngine::advance(const shared_ptr<EngineInput> input)
	{
		advanceIndex++;
		shared_ptr<EngineInput> currentInput = input;

		// For every sub-engine.
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			// If the sub-engine should be advanced at this time (if it's preferred frequency is a multiple of the
			// composite frequency).
			if (advanceIndex % (compositeFrequency / engines.at(index)->getPreferredFrequency()) == 0)
			{
				currentInput = engines.at(index)->advance(currentInput);
			}
		}

		return (currentInput);
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

		return (a * b / gcd);
	}

	void SimpleCompositeEngine::destroy()
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines.at(index)->destroy();
		}
	}

	int SimpleCompositeEngine::getCompositeFrequency() const
	{
		int newCompositeFrequency = 1;

		if (!engines.empty())
		{
			newCompositeFrequency = engines.at(0)->getPreferredFrequency();

			// For every sub-engine (except for the first one).
			for (unsigned int index = 0; index < engines.size(); index++)
			{
				int preferredFrequency = engines.at(index)->getPreferredFrequency();

				newCompositeFrequency = calculateLCD(newCompositeFrequency, preferredFrequency);
			}
		}

		return (newCompositeFrequency);
	}

	void SimpleCompositeEngine::onInit()
	{
		advanceIndex = 0;
		compositeFrequency = getCompositeFrequency();

		BaseEngine::setPreferredFrequency(compositeFrequency);

		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines.at(index)->init();
		}
	}

	void SimpleCompositeEngine::onReset()
	{
		advanceIndex = 0;
		compositeFrequency = getCompositeFrequency();

		BaseEngine::setPreferredFrequency(compositeFrequency);

		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines.at(index)->reset();
		}
	}

	void SimpleCompositeEngine::removeEngine(const shared_ptr<Engine> engine)
	{
		vector<shared_ptr<Engine> >::iterator iterator = engines.begin();
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			if (engines.at(index) == engine)
			{
				engines.erase(iterator);
				break;
			}

			iterator++;
		}
	}

	void SimpleCompositeEngine::removeEntity(const Entity& entity)
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines.at(index)->removeEntity(entity);
		}
	}
}
