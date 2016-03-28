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
#ifndef SCENE_H_
#define SCENE_H_

#include <map>

#include "../common/NonCopyable.h"
#include "../entity/Entity.h"
#include "../messaging/Message.h"
#include "SceneState.h"

namespace simplicity
{
	class WindowEngine;

	/**
	 * <p>
	 * A scene.
	 * </p>
	 */
	class SIMPLE_API Scene : private NonCopyable
	{
		public:
			Scene();

			/**
			 * <p>
			 * Adds the given entity to the scene.
			 * </p>
			 *
			 * @param entity The entity.
			 */
			void addEntity(std::unique_ptr<Entity> entity);

			/**
			 * <p>
			 * Adds state to the scene.
			 * </p>
			 *
			 * @param state The state.
			 */
			void addState(std::unique_ptr<SceneState> state);

			/**
			 * <p>
			 * Determines if the mouse should be captured while this scene is open.
			 * </p>
			 *
			 * @return True if the mouse should be captured while this scene is open, false otherwise.
			 */
			bool capturesMouse();

			/**
			 * <p>
			 * Retrieves the entity with the given name.
			 * </p>
			 *
			 * @return The entity with the given name.
			 */
			Entity* getEntity(const std::string& name);

			/**
			 * <p>
			 * Retrieves the entities.
			 * </p>
			 *
			 * @return The entities.
			 */
			std::vector<Entity*> getEntities(unsigned short category = Category::ALL_CATEGORIES);

			/**
			 * <p>
			 * Retrieves the state.
			 * </p>
			 *
			 * @return The state.
			 */
			template<typename StateType>
			std::vector<StateType*> getState();

			/**
			 * <p>
			 * Called when a component is added to an entity.
			 * </p>
			 *
			 * @param component The component being added.
			 */
			void onAddComponent(Component& component);

			/**
			 * <p>
			 * Called when a component is removed from an entity.
			 * </p>
			 *
			 * @param component The component being removed.
			 */
			void onRemoveComponent(Component& component);

			/**
			 * <p>
			 * Updates the scene to reflect any changes to the specified entity.
			 * </p>
			 *
			 * <p>
			 * This function only needs to be called if you are directly manipulating the transform of the entity. The
			 * convenience functions of the entity class i.e. rotate(), scale(), setPosition() and translate() will call
			 * this function for you.
			 * </p>
			 *
			 * @param entity The entity whose changes are to be reflected.
			 */
			void onTransformEntity(Entity& entity);

			/**
			 * <p>
			 * Opens this scene.
			 * </p>
			 */
			void open();

			/**
			 * <p>
			 * Pauses this scene.
			 * </p>
			 */
			void pause();

			/**
			 * <p>
			 * Removes the given entity from the scene.
			 * </p>
			 *
			 * @param entity The entity to remove.
			 *
			 * @return The removed entity.
			 */
			std::unique_ptr<Entity> removeEntity(Entity& entity);

			/**
			 * <p>
			 * Removes the given state from the scene.
			 * </p>
			 *
			 * @param state The state to remove.
			 *
			 * @return The removed state.
			 */
			std::unique_ptr<SceneState> removeState(SceneState& state);

			/**
			 * <p>
			 * Resumes this scene.
			 * </p>
			 */
			void resume();

			/**
			 * <p>
			 * Sets if the mouse should be captured while this scene is open.
			 * </p>
			 *
			 * @param capturesMouse True if the mouse should be captured while this scene is open, false otherwise.
			 */
			void setCapturesMouse(bool capturesMouse);

		private:
			std::vector<std::unique_ptr<Entity>> entities;

			bool isOpen;

			bool mouseCaptureEnabled;

			std::vector<std::unique_ptr<SceneState>> state;

			WindowEngine* windowEngine;

			bool onMouseButton(const Message& message);
	};
}

#include "Scene.tpp"

#endif /* SCENE_H_ */
