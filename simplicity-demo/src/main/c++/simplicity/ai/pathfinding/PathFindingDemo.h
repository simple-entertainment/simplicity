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
#include <simplicity/graph/UndirectedGraph.h>
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
			void addBackground();

			void addDescription();

			std::shared_ptr<Camera> addCamera() const;

			void addLight() const;

			void addObstacles(std::vector<std::pair<unsigned int, unsigned int> > locations);

			void addTitle();

			std::shared_ptr<Model> createGreySquareOnXZPlane(const bool dark) const;

			void createNavigationMesh();

			std::shared_ptr<Model> createSquareOnXZPlane(const ColourVector<>& colour) const;

			void displayOpenNodes(const std::vector<std::reference_wrapper<const Node> >& openNodes);

			void displayPath(const std::vector<std::reference_wrapper<const Node> >& path);

			const Graph<Node>& getNavigationMesh() const;

			std::vector<std::pair<unsigned int, unsigned int> > getRandomObstacleLocations() const;

			void initScene() const;

			void removeLocationsFromNavigationMesh(std::vector<std::pair<unsigned int, unsigned int> > locations);

			void removeAllEntities();

		private:
			static std::string OBSTACLE_ENTITY_NAME;

			static std::string OPEN_NODE_ENTITY_NAME;

			static std::string TILE_ENTITY_NAME;

			static std::string WAYPOINT_ENTITY_NAME;

			std::vector<reference_wrapper<Entity> > entities;

			UndirectedGraph<Node> navigationMesh;

			unsigned int openNodeIndex;

			unsigned int waypointIndex;

			std::shared_ptr<Model> createDescriptionLine(const std::string& line, const unsigned int lineNum) const;
	};
}

#endif /* PATHFINDINGDEMO_H_ */
