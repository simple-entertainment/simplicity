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
#ifndef SIMPLEGRAPH_H_
#define SIMPLEGRAPH_H_

#include <vector>

#include "../common/NonCopyable.h"
#include "../math/Matrix.h"
#include "../model/shape/Cube.h"
#include "Graph.h"

namespace simplicity
{
	class SIMPLE_API SimpleGraph : public Graph, private NonCopyable
	{
		public:
			SimpleGraph();

			void connectTo(Graph& graph) override;

			void disconnectFrom(Graph& graph) override;

			Matrix44 getAbsoluteTransform() const override;

			const Model& getBoundary() const override;

			std::vector<Graph*> getChildren() const override;

			std::vector<Entity*>& getEntities() override;

			const std::vector<Entity*>& getEntities() const override;

			std::vector<Entity*> getEntitiesWithinBounds(const Model& bounds, const Vector3& position) const override;

			Graph* getParent() override;

			const Graph* getParent() const override;

			Matrix44& getTransform() override;

			const Matrix44& getTransform() const override;

			bool insert(Entity& entity) override;

			bool insert(Entity& entity, const Entity& parent) override;

			bool remove(const Entity& entity) override;

			void setParent(Graph* parent) override;

			void setTransform(const Matrix44& transform) override;

			void update(Entity& entity) override;

		private:
			Cube boundary;

			std::vector<std::unique_ptr<SimpleGraph>> children;

			std::vector<Graph*> connections;

			std::vector<Entity*> entities;

			Graph* parent;

			Matrix44 transform;

			void addChild(std::unique_ptr<SimpleGraph> child);

			Matrix44 calculateRelativeTransform(const Matrix44& absoluteTransform) const;

			bool insertDirect(Entity& entity);

			std::unique_ptr<SimpleGraph> removeChild(SimpleGraph& child);

			void updateSuccessor(Entity& entity);
	};
}

#endif /* SIMPLEGRAPH_H_ */
