/*      _                 _ _      _ _
 *     (_)               | (_)    (_) |
 *  ___ _ _ __ ___  _ __ | |_  ___ _| |_ _   _
 * / __| | '_ ` _ \| '_ \| | |/ __| | __| | | |
 * \__ \ | | | | | | |_) | | | (__| | |_| |_| |
 * |___/_|_| |_| |_| .__/|_|_|\___|_|\__|\__, |
 *                 | |                    __/ |
 *                 |_|                   |___/
 *
 * This file is part of simplicity. See the LICENSE file for the full license governing this code.
 */
#ifndef SCENESTATE_H
#define SCENESTATE_H

#include "../entity/Component.h"
#include "../entity/Entity.h"

namespace simplicity
{
	class SIMPLE_API SceneState
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~SceneState()
			{
			}

			/**
			 * <p>
			 * Called when a component is added to an entity.
			 * </p>
			 *
			 * @param component The component being added.
			 */
			virtual void onAddComponent(Component& component)
			{
			}

			/**
			 * <p>
			 * Called when an entity is added to the scene.
			 * </p>
			 *
			 * @param entity The entity being added.
			 */
			virtual void onAddEntity(Entity& entity)
			{
			}

			/**
			 * <p>
			 * Called when a component is removed from an entity.
			 * </p>
			 *
			 * @param component The component being removed.
			 */
			virtual void onRemoveComponent(Component& component)
			{
			}

			/**
			 * <p>
			 * Called when an entity is removed from the scene.
			 * </p>
			 *
			 * @param entity The entity being removed.
			 */
			virtual void onRemoveEntity(Entity& entity)
			{
			}

			/**
			 * <p>
			 * Called when an entity's transform is modified.
			 * </p>
			 *
			 * <p>
			 * This function is not guaranteed to be called, see Scene#onTransformEntity() for more information.
			 * </p>
			 *
			 * @param entity The entity whose changes are to be reflected.
			 */
			virtual void onTransformEntity(Entity& entity)
			{
			}
	};
}

#endif /* SCENESTATE_H */
