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

	map<const string, vector<function<Simplicity::Observer> > > Simplicity::observers = map<const string,
		vector<function<Simplicity::Observer> > >();

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

	void Simplicity::deregisterObserver(const string eventName, function<Observer> observer)
	{
		vector<function<Observer> >& registeredObservers = observers.find(eventName)->second;

		for (vector<function<Observer> >::iterator registeredObserver = registeredObservers.begin();
			registeredObserver != registeredObservers.end(); registeredObserver++)
		{
			if (registeredObserver->target_type() == observer.target_type())
			{
				registeredObservers.erase(registeredObserver);
				return;
			}
		}
	}

	void Simplicity::fireEvent(const string eventName, const boost::any data)
	{
		if (observers.find(eventName) == observers.end())
		{
			return;
		}

		vector<function<Observer> >& registeredObservers = observers.find(eventName)->second;

		// Does not use C++11 for loop as elements could be added to the vector while iterating.
		// Take care - this is a fragile 'solution'.
		for (unsigned int index = 0; index < registeredObservers.size(); index++)
		{
			registeredObservers.at(index)(data);
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

	void Simplicity::registerObserver(const string eventName, function<Observer> observer)
	{
		if (observers.find(eventName) == observers.end())
		{
			observers.insert(
				pair<const string, vector<function<Observer> > >(eventName, vector<function<Observer> >()));
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
