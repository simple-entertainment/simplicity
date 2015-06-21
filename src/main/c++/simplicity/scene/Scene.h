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
#include "../graph/Graph.h"
#include "../messaging/Message.h"

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
			 * Queues an entity to be added to the scene before the next frame.
			 * </p>
			 *
			 * @param entity The entity.
			 */
			void addEntity(std::unique_ptr<Entity> entity);

			/**
			 * <p>
			 * Queues an entity to be added to the scene before the next frame.
			 * </p>
			 *
			 * @param entity The entity.
			 * @param parent The parent under which to add the entity.
			 */
			void addEntity(std::unique_ptr<Entity> entity, const Entity& parent);

			/**
			 * <p>
			 * Adds a graph to the scene.
			 * </p>
			 *
			 * @param graph The graph.
			 */
			void addGraph(std::unique_ptr<Graph> graph);

			/**
			 * <p>
			 * Adds the entities that have been queued.
			 * </p>
			 */
			void addPendingEntities();

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
			 * Retrieves the entities.
			 * </p>
			 *
			 * @return The entities.
			 */
			std::vector<Entity*> getEntities(unsigned short category = Category::ALL_CATEGORIES);

			/**
			 * <p>
			 * Retrieves a single graph. If more than one world representation of the specified type exist, the first one
			 * found will be returned.
			 * </p>
			 *
			 * @return The graph.
			 */
			template<typename GraphType>
			GraphType* getGraph();

			/**
			 * <p>
			 * Retrieves the graphs.
			 * </p>
			 *
			 * @return The graphs.
			 */
			template<typename GraphType>
			std::vector<GraphType*> getGraphs();

			/**
			 * <p>
			 * Pauses this scene.
			 * </p>
			 */
			void pause();

			/**
			 * <p>
			 * Queues an entity to be removed from the scene before the next frame.
			 * </p>
			 *
			 * @param entity The entity to remove.
			 */
			void removeEntity(Entity* entity);

			/**
			 * <p>
			 * Removes the entities that have been queued.
			 * </p>
			 */
			void removePendingEntities();

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

			/**
			 * <p>
			 * Updates the graphs to reflect any changes to the specified entity.
			 * </p>
			 *
			 * @param entity The entity whose changes are to be reflected.
			 */
			void updateGraphs(Entity& entity);

		private:
			std::vector<std::unique_ptr<Entity>> entities;

			std::vector<std::unique_ptr<Entity>> entitiesToBeAdded;

			std::map<Entity*, const Entity*> entitiesToBeAddedParents;

			std::vector<const Entity*> entitiesToBeRemoved;

			std::vector<std::unique_ptr<Graph>> graphs;

			bool mouseCaptureEnabled;

			WindowEngine* windowEngine;

			bool onMouseButton(const Message& message);
	};
}

#include "Scene.tpp"

#endif /* SCENE_H_ */
