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

#include "engine/RunnableEngine.h"

namespace simplicity
{
	class Simplicity
	{
		public:
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

			static void finish();

			/**
			 * <p>
			 * Initialises simplicity with the given {@link simplicity::Engine Engine}.
			 * </p>
			 *
			 * @param engine The <code>Engine</code> to initialise simplicity with.
			 */
			static void init(std::unique_ptr<RunnableEngine> engine);

			static void start();

		private:
			/**
			 * <p>
			 * The {@link simplicity::Engine Engine} that does the actual work for simplicity.
			 * </p>
			 */
			static std::unique_ptr<RunnableEngine> engine;

			/**
			 * <p>
			 * The {@link simplicity::Entity Entity}s managed by simplicity.
			 * </p>
			 */
			static std::vector<std::shared_ptr<Entity> > entities;

			Simplicity();

			~Simplicity();
	};
}

#endif /* SIMPLICITY_H_ */
