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
#ifndef GRAPH_H_
#define GRAPH_H_

#include <memory>
#include <vector>

#include "../Entity.h"
#include "../math/Matrix.h"
#include "../model/Model.h"

namespace simplicity
{
	class Graph
	{
		public:
			virtual ~Graph()
			{
			}

			virtual void connectTo(Graph& graph) = 0;

			virtual void disconnectFrom(Graph& graph) = 0;

			virtual Matrix44 getAbsoluteTransform() const = 0;

			virtual const Model& getBoundary() const = 0;

			virtual std::vector<Graph*> getChildren() const = 0;

			virtual std::vector<Entity*>& getEntities() = 0;

			virtual const std::vector<Entity*>& getEntities() const = 0;

			virtual std::vector<Entity*> getEntitiesWithinBounds(const Model& bounds, const Vector3& position) const = 0;

			virtual Graph* getParent() = 0;

			virtual const Graph* getParent() const = 0;

			virtual Matrix44& getTransform() = 0;

			virtual const Matrix44& getTransform() const = 0;

			virtual bool insert(Entity& entity) = 0;

			virtual bool insert(Entity& entity, const Entity& parent) = 0;

			virtual bool remove(const Entity& entity) = 0;

			virtual void setParent(Graph* parent) = 0;

			virtual void setTransform(const Matrix44& transform) = 0;

			virtual void update(Entity& entity) = 0;
	};
}

#endif /* GRAPH_H_ */
