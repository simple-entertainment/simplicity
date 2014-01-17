/*
 * Copyright © 2013 Simple Entertainment Limited
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
#ifndef QUADTREE_H_
#define QUADTREE_H_

#include <vector>

#include "../model/Model.h"
#include "AABB2.h"
#include "Graph.h"

namespace simplicity
{
	class QuadTree : public Graph
	{
		public:
			QuadTree(unsigned int subdivideThreshold, const AABB2& boundary);

			void addChild(std::unique_ptr<Graph> child);

			void connectTo(Graph& graph);

			void disconnectFrom(Graph& graph);

			Matrix44 getAbsoluteTransformation() const;

			const AABB2& getBoundary() const;

			std::vector<Graph*> getChildren() const;

			std::vector<Entity*>& getEntities();

			const std::vector<Entity*>& getEntities() const;

			Graph* getParent();

			const Graph* getParent() const;

			Matrix44& getTransformation();

			const Matrix44& getTransformation() const;

			bool insert(Entity& entity);

			std::vector<Entity*> queryRange(const AABB2& range) const;

			bool remove(const Entity& entity);

			std::unique_ptr<Graph> removeChild(Graph& child);

			void setParent(Graph* parent);

			void setTransformation(const Matrix44& transformation);

			void update(Entity& entity);

		private:
			AABB2 boundary;

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

#endif /* QUADTREE_H_ */
