/*
 * Copyright © Simple Entertainment Limited 2011
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

#include <simplicity/Demo.h>
#include <simplicity/Entity.h>
#include <simplicity/rendering/engine/RenderingEngine.h>
#include <simplicity/rendering/Light.h>

namespace simplicity
{
	class PathFindingDemo : public Demo
	{
		protected:
			/**
			 * <p>
			 * Adds the background scene to the given node.
			 * </p>
			 *
			 * @parentNode The node under which the background scene is to be added.
			 */
			void addBackground(std::shared_ptr<Node> parentNode);

			/**
			 * <p>
			 * Adds the camera scene to the given node.
			 * </p>
			 *
			 * @param parentNode The node under which the camera scene is to be added.
			 *
			 * @return The camera that has been added.
			 */
			std::shared_ptr<Camera> addCamera(std::shared_ptr<Node> parentNode);

			/**
			 * <p>
			 * Adds the light scene to the given node.
			 * </p>
			 *
			 * @param parentNode The node under which the light scene is to be added.
			 *
			 * @return The light that has been added.
			 */
			std::shared_ptr<Light> addLight(std::shared_ptr<Node> parentNode);

			/**
			 * <p>
			 * Creates a light or dark grey square on the XZ plane with dimensions 1x1 centered on the origin.
			 * </p>
			 *
			 * @param dark Determines whether a light or dark square should be created.
			 *
			 * @return A node containing the light or dark grey square.
			 */
			std::shared_ptr<Node> createGreySquareOnXZPlane(const bool dark);

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
			 * Creates a square on the XZ plane with dimensions 1x1 centered on the origin.
			 * </p>
			 *
			 * @param colour The colour of the square.
			 *
			 * @return A node containing the square.
			 */
			std::shared_ptr<Node> createSquareOnXZPlane(const RGBAColourVector<>& colour);

			/**
			 * <p>
			 * Displays the given 'open' nodes using the given rendering engine.
			 * </p>
			 *
			 * @param renderingEngine The engine to display the path with.
			 * @param openNodes The 'open' nodes to display.
			 */
			void displayOpenNodes(RenderingEngine& renderingEngine,
				const std::vector<std::shared_ptr<const Node> >& openNodes);

			/**
			 * <p>
			 * Displays the given path using the given rendering engine.
			 * </p>
			 *
			 * @param renderingEngine The engine to display the path with.
			 * @param path The path to display.
			 */
			void displayPath(RenderingEngine& renderingEngine, const std::vector<std::shared_ptr<const Node> >& path);

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

		private:
			/**
			 * <p>
			 * The navigation mesh from which the shortest path is to be found.
			 * </p>
			 */
			std::vector<std::shared_ptr<Node> > navigationMesh;
	};
}

#endif /* PATHFINDINGDEMO_H_ */
