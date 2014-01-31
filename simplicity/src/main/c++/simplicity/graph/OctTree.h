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
#ifndef OCTTREE_H_
#define OCTTREE_H_

#include <vector>

#include "../model/Model.h"
#include "../model/shape/Cube.h"
#include "Graph.h"

namespace simplicity
{
	class OctTree : public Graph
	{
		public:
			OctTree(unsigned int subdivideThreshold, const Cube& boundary);

			void addChild(std::unique_ptr<Graph> child);

			void connectTo(Graph& graph);

			void disconnectFrom(Graph& graph);

			Matrix44 getAbsoluteTransformation() const;

			const Model& getBoundary() const;

			std::vector<Graph*> getChildren() const;

			std::vector<Entity*>& getEntities();

			const std::vector<Entity*>& getEntities() const;

			std::vector<Entity*> getEntitiesWithinBounds(const Model& bounds, const Vector3& position) const;

			Graph* getParent();

			const Graph* getParent() const;

			Matrix44& getTransformation();

			const Matrix44& getTransformation() const;

			bool insert(Entity& entity);

			bool remove(const Entity& entity);

			std::unique_ptr<Graph> removeChild(Graph& child);

			void setParent(Graph* parent);

			void setTransformation(const Matrix44& transformation);

			void update(Entity& entity);

		private:
			Cube boundary;

			std::vector<std::unique_ptr<Graph>> children;

			std::vector<Graph*> connections;

			std::vector<Entity*> entities;

			Graph* parent;

			unsigned int subdivideThreshold;

			Matrix44 transformation;

			void addEntityFromChild();

			void shiftEntitiesUpward();

			void subdivide();

			bool withinBounds(const Entity& entity) const;
	};
}

#endif /* OCTTREE_H_ */