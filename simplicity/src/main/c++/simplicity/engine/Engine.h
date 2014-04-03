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
#ifndef ENGINE_H_
#define ENGINE_H_

#include "../common/NonCopyable.h"
#include "../entity/Entity.h"

namespace simplicity
{
	/**
	 * <p>
	 * Performs tasks every frame.
	 * </p>
	 */
	class SIMPLE_API Engine : private NonCopyable
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Engine()
			{
			}

			/**
			 * <p>
			 *	Called when an entity is added to the scene.
			 * </p>
			 *
			 * @param entity The entity being added.
			 */
			virtual void addEntity(Entity& entity) = 0;

			/**
			 * <p>
			 * Advances the engine, performing any tasks required for the current frame.
			 * </p>
			 *
			 * <p>
			 * Called once every frame.
			 * </p>
			 */
			virtual void advance() = 0;

			/**
			 * <p>
			 * Destroys the engine.
			 * </p>
			 *
			 * <p>
			 * Called after the last call to advance().
			 * </p>
			 */
			virtual void destroy() = 0;

			/**
			 * <p>
			 * Initializes the engine.
			 * </p>
			 *
			 * <p>
			 * Called before the first call to advance().
			 * </p>
			 */
			virtual void init() = 0;

			/**
			 * <p>
			 *	Called when an entity is removed from the scene.
			 * </p>
			 *
			 * @param entity The entity being removed.
			 */
			virtual void removeEntity(const Entity& entity) = 0;
	};
}

#endif /* ENGINE_H_ */
