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
#ifndef SIMPLICITY_H_
#define SIMPLICITY_H_

#include <map>

#include <boost/any.hpp>

#include "engine/Engine.h"

namespace simplicity
{
	/**
	 * <p>
	 * The interface to The Simplicity Engine.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Simplicity
	{
		public:
			typedef void(Observer)(const boost::any);

			/**
			 * <p>
			 * Adds the given {@link simplicity::Entity Entity}s to the <code>Entity</code>s managed by simplicity.
			 * </p>
			 *
			 * @param entities The <code>Entity</code>s to be managed by simplicity.
			 */
			static void addEntities(std::vector<std::shared_ptr<Entity> > entities);

			/**
			 * <p>
			 * Adds the given {@link simplicity::Entity Entity} to the <code>Entity</code>s managed by simplicity.
			 * </p>
			 *
			 * @param entity The <code>Entity</code> to be managed by simplicity.
			 */
			static void addEntity(std::shared_ptr<Entity> entity);

			/**
			 * <p>
			 * Deregisters the given observer from the given event. Standard simplicity events can be found in
			 * SimpleEvents.h.
			 * </p>
			 *
			 * @param eventName The name of the event to deregister the observer from.
			 * @param observer The observer to deregister.
			 */
			static void deregisterObserver(const std::string eventName, std::function<Observer> observer);

			/**
			 * <p>
			 * Fires the given event, notifying all registered observers.
			 * </p>
			 *
			 * @param eventName The name of the event to fire.
			 * @param data Data associated with the event.
			 */
			static void fireEvent(const std::string eventName, const boost::any data);

			/**
			 * <p>
			 * Retrieves the {@link simplicity::Entity Entity} with the given name from the <code>Entity</code>s managed
			 * by simplicity.
			 * </p>
			 *
			 * @param name The name of the <code>Entity</code> to retrieve.
			 *
			 * @return The <code>Entity</code> with the given name.
			 */
			static std::shared_ptr<Entity> getEntity(const std::string name);

			/**
			 * <p>
			 * Initialises simplicity with the given {@link simplicity::Engine Engine}.
			 * </p>
			 *
			 * @param engine The <code>Engine</code> to initialise simplicity with.
			 */
			static void init(std::unique_ptr<Engine> engine);

			/**
			 * <p>
			 * Registers an observer for the given event. Standard simplicity events can be found in SimpleEvents.h.
			 * </p>
			 *
			 * @param eventName The name of the event to register the observer with.
			 * @param observer The observer to notify when the event is fired.
			 */
			static void registerObserver(const std::string eventName, std::function<Observer> observer);

			/**
			 * <p>
			 * Removes the {@link simplicity::Entity Entity} with the given name from the <code>Entity</code>s managed
			 * by simplicity.
			 * </p>
			 *
			 * @param name The name of the <code>Entity</code> to be removed from simplicity.
			 */
			static void removeEntity(const std::string name);

			/**
			 * <p>
			 * Resets simplicity so that it may be started again.
			 * </p>
			 */
			static void reset();

			/**
			 * <p>
			 * Starts simplicity.
			 * </p>
			 */
			static void start();

			/**
			 * <p>
			 * Stops simplicity.
			 * </p>
			 */
			static void stop();

		private:
			/**
			 * <p>
			 * The {@link simplicity::Engine Engine} that does the actual work for simplicity.
			 * </p>
			 */
			static std::unique_ptr<Engine> engine;

			/**
			 * <p>
			 * The {@link simplicity::Entity Entity}s managed by simplicity.
			 * </p>
			 */
			static std::map<const std::string, std::shared_ptr<Entity> > entities;

			/**
			 * <p>
			 * The observers to any events fired within simplicity.
			 * </p>
			 */
			static std::map<const std::string, std::vector<std::function<Observer> > > observers;

			Simplicity();
	};
}

#endif /* SIMPLICITY_H_ */
