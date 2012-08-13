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
#ifndef PATHFINDINGDEMO_H_
#define PATHFINDINGDEMO_H_

#include <simplicity/Entity.h>
#include <simplicity/rendering/engine/RenderingEngine.h>
#include <simplicity/rendering/Light.h>

#include "../../Demo.h"

namespace simplicity
{
	class PathFindingDemo : public Demo
	{
		public:
			PathFindingDemo();

		protected:
			/**
			 * <p>
			 * Adds the background scene to the given node.
			 * </p>
			 *
			 * @parentNode The node under which the background scene is to be added.
			 */
			void addBackground(Node& parentNode);

			/**
			 * <p>
			 * Adds the camera scene to the given node.
			 * </p>
			 *
			 * @param parentNode The node under which the camera scene is to be added.
			 *
			 * @return The camera that has been added.
			 */
			std::shared_ptr<Camera> addCamera(Node& parentNode);

			/**
			 * <p>
			 * Adds the light scene to the given node.
			 * </p>
			 *
			 * @param parentNode The node under which the light scene is to be added.
			 *
			 * @return The light that has been added.
			 */
			std::shared_ptr<Light> addLight(Node& parentNode);

			/**
			 * <p>
			 * Creates a light or dark grey square on the XZ plane with dimensions 1x1 centered on the origin.
			 * </p>
			 *
			 * @param dark Determines whether a light or dark square should be created.
			 *
			 * @return The light or dark grey square.
			 */
			std::shared_ptr<Model> createGreySquareOnXZPlane(const bool dark);

			/**
			 * <p>
			 * Creates obstacle entities and removes the location of these obstacles from the full path.
			 * </p>
			 *
			 * @return The obstacle entities.
			 */
			std::vector<std::shared_ptr<Entity> > createObstacles();

			/**
			 * <p>
			 * Creates a square on the XZ plane with dimensions 1x1 centred on the origin.
			 * </p>
			 *
			 * @param colour The colour of the square.
			 *
			 * @return The square.
			 */
			std::shared_ptr<Model> createSquareOnXZPlane(const ColourVector<>& colour);

			/**
			 * <p>
			 * Displays the given 'open' nodes using the given rendering engine.
			 * </p>
			 *
			 * @param renderingEngine The engine to display the path with.
			 * @param openNodes The 'open' nodes to display.
			 */
			void displayOpenNodes(const std::vector<std::reference_wrapper<const Node> >& openNodes);

			/**
			 * <p>
			 * Displays the given path using the given rendering engine.
			 * </p>
			 *
			 * @param renderingEngine The engine to display the path with.
			 * @param path The path to display.
			 */
			void displayPath(const std::vector<std::reference_wrapper<const Node> >& path);

			/**
			 * <p>
			 * Retrieves the navigation mesh.
			 * </p>
			 *
			 * @return The navigation mesh.
			 */
			std::vector<std::shared_ptr<Node> >& getNavigationMesh();

			/**
			 * <p>
			 * Populates the navigation mesh (does not take obstacles into account).
			 * </p>
			 */
			void populateNavigationMesh();

		protected:
			std::vector<std::shared_ptr<Entity> > createDescription();

			std::shared_ptr<Entity> createTitle();

		private:
			static std::string OBSTACLE_ENTITY_NAME;

			static std::string OPEN_NODE_ENTITY_NAME;

			static std::string WAYPOINT_ENTITY_NAME;

			/**
			 * <p>
			 * The navigation mesh from which the shortest path is to be found.
			 * </p>
			 */
			std::vector<std::shared_ptr<Node> > navigationMesh;

			unsigned int obstacleIndex;

			unsigned int openNodeIndex;

			unsigned int waypointIndex;

			std::shared_ptr<Entity> createDescriptionLine(const std::string& line, const unsigned int lineNum);
	};
}

#endif /* PATHFINDINGDEMO_H_ */
