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
	unique_ptr<Engine> Simplicity::engine = unique_ptr<Engine>();

	map<const string, shared_ptr<Entity> > Simplicity::entities = map<const string, shared_ptr<Entity> >();

	map<const string, vector<function<void(const boost::any)> > > Simplicity::observers = map<const string,
		vector<function<void(const boost::any)> > >();

	Simplicity::Simplicity()
	{
	}

	void Simplicity::addEntities(vector<shared_ptr<Entity> > entities)
	{
		for (shared_ptr<Entity> entity : entities)
		{
			addEntity(entity);
		}
	}

	void Simplicity::addEntity(shared_ptr<Entity> entity)
	{
		entities.insert(pair<const string, shared_ptr<Entity> >(entity->getName(), entity));
		engine->addEntity(entity);
	}

	void Simplicity::deregisterObserver(const string eventName, function<void(const boost::any)> observer)
	{
		// TODO Add support for this when using proper C++11, currently equality of functions does not seem to be
		// supported so function to be erased cannot be found.
		// vector<function<void(const boost::any)> >& eventObservers(observers.find(eventName)->second);

		// eventObservers.erase(find(eventObservers.begin(), eventObservers.end(), observer));
	}

	void Simplicity::fireEvent(const string eventName, const boost::any source)
	{
		if (observers.find(eventName) == observers.end())
		{
			return;
		}

		for (function<void(const boost::any)> observer : observers.find(eventName)->second)
		{
			observer(source);
		}
	}

	shared_ptr<Entity> Simplicity::getEntity(const string name)
	{
		return entities.find(name)->second;
	}

	void Simplicity::init(unique_ptr<Engine> engine)
	{
		Simplicity::engine = move(engine);
	}

	void Simplicity::registerObserver(const string eventName, function<void(const boost::any)> observer)
	{
		if (observers.find(eventName) == observers.end())
		{
			observers.insert(
				pair<const string, vector<function<void(const boost::any)> > >(eventName,
					vector<function<void(const boost::any)> >()));
		}

		observers.find(eventName)->second.push_back(observer);
	}

	void Simplicity::removeEntity(const string name)
	{
		entities.erase(name);
	}

	void Simplicity::reset()
	{
		engine.reset();
		entities.clear();
		observers.clear();
	}

	void Simplicity::start()
	{
		engine->run();
	}

	void Simplicity::stop()
	{
		engine->destroy();
	}
}
