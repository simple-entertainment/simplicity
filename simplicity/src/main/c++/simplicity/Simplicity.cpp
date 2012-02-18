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
#include "Simplicity.h"

using namespace std;

namespace simplicity
{
	unique_ptr<RunnableEngine> Simplicity::engine = unique_ptr<RunnableEngine>();

	vector<shared_ptr<Entity> > Simplicity::entities = vector<shared_ptr<Entity> >();

	Simplicity::Simplicity()
	{
	}

	Simplicity::~Simplicity()
	{
	}

	void Simplicity::addEntities(vector<shared_ptr<Entity> > entities)
	{
		for (shared_ptr<Entity> entity : entities)
		{
			Simplicity::entities.push_back(entity);
			engine->addEntity(entity);
		}
	}

	void Simplicity::addEntity(shared_ptr<Entity> entity)
	{
		entities.push_back(entity);
		engine->addEntity(entity);
	}

	void Simplicity::finish()
	{
		engine->destroy();
	}

	void Simplicity::init(unique_ptr<RunnableEngine> engine)
	{
		Simplicity::engine = move(engine);
	}

	void Simplicity::start()
	{
		engine->run();
	}
}
