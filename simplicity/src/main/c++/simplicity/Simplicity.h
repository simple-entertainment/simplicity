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

#include "engine/Engine.h"
#include "scene/Scene.h"

namespace simplicity
{
	/**
	 * <p>
	 * The interface to The Simplicity Engine.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	namespace Simplicity
	{
		/**
		 * <p>
		 * Adds the given {@link simplicity::Entity Entity}s to the <code>Entity</code>s managed by simplicity.
		 * </p>
		 *
		 * @param entities The <code>Entity</code>s to be managed by simplicity.
		 */
		void addEntities(std::vector<std::shared_ptr<Entity> > entities);

		/**
		 * <p>
		 * Adds the given {@link simplicity::Entity Entity} to the <code>Entity</code>s managed by simplicity.
		 * </p>
		 *
		 * @param entity The <code>Entity</code> to be managed by simplicity.
		 */
		void addEntity(std::shared_ptr<Entity> entity);

		/**
		 * <p>
		 * Adds the given {@link simplicity::Entity Entity} to the <code>Entity</code>s managed by simplicity.
		 * </p>
		 *
		 * @param entity The <code>Entity</code> to be managed by simplicity.
		 * @param node The <code>TreeNode</code> to add to the scene (will be removed when the <code>Entity</code> is
		 * removed).
		 */
		void addEntity(shared_ptr<Entity> entity, shared_ptr<TreeNode> node);

		/**
		 * <p>
		 * Adds the given {@link simplicity::Entity Entity} to the <code>Entity</code>s managed by simplicity.
		 * </p>
		 *
		 * @param entity The <code>Entity</code> to be managed by simplicity.
		 * @param node The <code>TreeNode</code> to add to the scene (will be removed when the <code>Entity</code> is
		 * removed).
		 * @param parent The parent to add the <code>TreeNode</code> to.
		 */
		void addEntity(shared_ptr<Entity> entity, shared_ptr<TreeNode> node, TreeNode& parent);

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
		Entity& getEntity(const std::string name);

		Scene* getScene();

		/**
		 * <p>
		 * Removes the {@link simplicity::Entity Entity} with the given name from the <code>Entity</code>s managed
		 * by simplicity.
		 * </p>
		 *
		 * @param name The name of the <code>Entity</code> to be removed from simplicity.
		 */
		void removeEntity(const std::string name);

		/**
		 * <p>
		 * Resets simplicity so that it may be started again.
		 * </p>
		 */
		void reset();

		/**
		 * <p>
		 * Initialises simplicity with the given {@link simplicity::Engine Engine}.
		 * </p>
		 *
		 * @param engine The <code>Engine</code> to initialise simplicity with.
		 */
		void setEngine(std::shared_ptr<Engine> engine);

		/**
		 * <p>
		 * Initialises simplicity with the given {@link simplicity::Scene Scene}.
		 * </p>
		 *
		 * @param scene The <code>Scene</code> to initialise simplicity with.
		 */
		void setScene(std::shared_ptr<Scene> scene);

		/**
		 * <p>
		 * Starts simplicity.
		 * </p>
		 */
		void start();

		/**
		 * <p>
		 * Stops simplicity.
		 * </p>
		 */
		void stop();
	}
}

#endif /* SIMPLICITY_H_ */
