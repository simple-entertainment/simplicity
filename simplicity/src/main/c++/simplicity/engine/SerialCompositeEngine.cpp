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
#include "SerialCompositeEngine.h"

namespace simplicity
{
	SerialCompositeEngine::SerialCompositeEngine() :
			engines()
	{
	}

	void SerialCompositeEngine::addEngine(unique_ptr<Engine> engine)
	{
		engines.push_back(move(engine));
	}

	void SerialCompositeEngine::addEntity(Entity& entity)
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->addEntity(entity);
		}
	}

	void SerialCompositeEngine::advance()
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->advance();
		}
	}

	void SerialCompositeEngine::destroy()
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->destroy();
		}
	}

	void SerialCompositeEngine::init()
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->init();
		}
	}

	unique_ptr<Engine> SerialCompositeEngine::removeEngine(Engine* engine)
	{
		unique_ptr<Engine> removedEngine;
		vector<unique_ptr<Engine>>::iterator result =
				find_if(engines.begin(), engines.end(), AddressEquals<Engine>(*engine));

		if (result != engines.end())
		{
			removedEngine.swap(*result);
			engines.erase(result);
			engine = NULL;
		}

		return move(removedEngine);
	}

	void SerialCompositeEngine::removeEntity(const Entity& entity)
	{
		for (unsigned int index = 0; index < engines.size(); index++)
		{
			engines[index]->removeEntity(entity);
		}
	}
}
