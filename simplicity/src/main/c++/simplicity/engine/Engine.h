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
#include "../scene/Scene.h"

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
			* Called when an entity is added to the scene.
			* </p>
			*
			* @param entity The entity being added.
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
			*/
			virtual void onCloseScene(Scene& /* scene */)
			{
			}

			/**
			* <p>
			* Called after a scene is opened and before the first frame of that scene has started.
			* </p>
			* 
			* @param scene The scene.
			*/
			virtual void onOpenScene(Scene& /* scene */)
			{
			}

			/**
			* <p>
			* Called after a scene is paused and the last frame has finished.
			* </p>
			*/
			virtual void onPause()
			{
			}

			/**
			* <p>
			* Called after simplicity is paused and the last frame has finished.
			* </p>
			* 
			* @param scene The scene.
			*/
			virtual void onPauseScene(Scene& /* scene */)
			{
			}

			/**
			* <p>
			* Called after simplicity is played and before the first frame has started.
			* </p>
			*/
			virtual void onPlay()
			{
			}

			/**
			* <p>
			* Called when an entity is removed from the scene.
			* </p>
			*
			* @param entity The entity being removed.
			*/
			virtual void onRemoveEntity(Entity& /* entity */)
			{
			}

			/**
			* <p>
			* Called after simplicity is resumed and before the first frame has started.
			* </p>
			*/
			virtual void onResume()
			{
			}

			/**
			* <p>
			* Called after a scene is resumed and before the first frame has started.
			* </p>
			*
			* @param scene The scene.
			*/
			virtual void onResumeScene(Scene& /* scene */)
			{
			}

			/**
			 * <p>
			 * Called after simplicity is stopped and the last frame has finished.
			 * </p>
			 */
			virtual void onStop()
			{
			}
	};
}

#endif /* ENGINE_H_ */
