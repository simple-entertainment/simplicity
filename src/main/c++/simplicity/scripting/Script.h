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
#ifndef SCRIPT_H_
#define SCRIPT_H_

#include "../entity/Component.h"
#include "../scene/Scene.h"

namespace simplicity
{
	/**
	 * <p>
	 * Custom functionality that can be attached to an entity.
	 * </p>
	 */
	class SIMPLE_API Script : public Component
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~Script()
			{
			}

			/**
			 * <p>
			 * Executes this script. Called once per frame.
			 * </p>
			 *
			 * @param entity The entity this script is attached to.
			 */
			virtual void execute(Entity& /* entity */) = 0;

			/**
			* <p>
			* Called when an entity this script is attached to is added to the scene.
			* </p>
			*
			* @param entity The entity this script is attached to.
			*/
			virtual void onAddEntity(Entity& /* entity */)
			{
			}

			/**
			* <p>
			* Called after a scene is closed and the last frame of that scene has finished.
			* </p>
			*
			* @param scene The scene.
			* @param entity The entity this script is attached to.
			*/
			virtual void onCloseScene(Scene& /* scene */, Entity& /* entity */)
			{
			}

			/**
			* <p>
			* Called after a scene is opened and before the first frame of that scene has started.
			* </p>
			*
			* @param scene The scene.
			* @param entity The entity this script is attached to.
			*/
			virtual void onOpenScene(Scene& /* scene */, Entity& /* entity */)
			{
			}

			/**
			* <p>
			* Called after simplicity is paused and the last frame has finished.
			* </p>
			*
			* @param scene The scene.
			* @param entity The entity this script is attached to.
			*/
			virtual void onPauseScene(Scene& /* scene */, Entity& /* entity */)
			{
			}

			/**
			* <p>
			* Called when an entity this script is attached to is removed from the scene.
			* </p>
			*
			* @param entity The entity this script is attached to.
			*/
			virtual void onRemoveEntity(Entity& /* entity */)
			{
			}

			/**
			* <p>
			* Called after a scene is resumed and before the first frame has started.
			* </p>
			*
			* @param scene The scene.
			* @param entity The entity this script is attached to.
			*/
			virtual void onResumeScene(Scene& /* scene */, Entity& /* entity */)
			{
			}
	};
}

#endif /* SCRIPT_H_ */
