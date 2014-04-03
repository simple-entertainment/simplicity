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

#include "../common/NonCopyable.h"
#include "../model/Model.h"
#include "../model/shape/Cube.h"
#include "Graph.h"

namespace simplicity
{
	/**
	 * <p>
	 * A tree that uses a cube bounding volume. Once the subdivision threshold has been reached, it will create 8
	 * children, each with a bounding volume one-eighth the size of this one and any entities that can fit within them
	 * will be inserted into them instead of this node. This insertion works recursively until either the child nodes
	 * have a bounding volume too small to contain the entity or a node is found that has not yet reached its
	 * subdivision threshold.
	 * </p>
	 */
	class SIMPLE_API OcTree : public Graph, private NonCopyable
	{
		public:
			/**
			 * @param subdivideThreshold The number of entities that can be inserted into this graph before it creates
			 * children.
			 * @param boundary The bounding volume of this graph.
			 */
			OcTree(unsigned int subdivideThreshold, const Cube& boundary);

			void connectTo(Graph& graph);

			void disconnectFrom(Graph& graph);

			Matrix44 getAbsoluteTransform() const;

			const Model& getBoundary() const;

			std::vector<Graph*> getChildren() const;

			std::vector<Entity*>& getEntities();

			const std::vector<Entity*>& getEntities() const;

			std::vector<Entity*> getEntitiesWithinBounds(const Model& bounds, const Vector3& position) const;

			Graph* getParent();

			const Graph* getParent() const;

			Matrix44& getTransform();

			const Matrix44& getTransform() const;

			bool insert(Entity& entity);

			/**
			 * <p>
			 * This tree will ignore the request to be added to a particular parent as the placing of the entity is
			 * determined by the bounding volumes of the nodes and the number of entities already in the nodes.
			 * </p>
			 *
			 * @param entity The entity to insert.
			 * @param parent IGNORED!
			 *
			 * @return True if the insertion was successful, false otherwise.
			 */
			bool insert(Entity& entity, const Entity& parent);

			bool remove(const Entity& entity);

			void setParent(Graph* parent);

			void setTransform(const Matrix44& transform);

			void update(Entity& entity);

		private:
			Cube boundary;

			std::vector<std::unique_ptr<OcTree>> children;

			std::vector<Graph*> connections;

			std::vector<Entity*> entities;

			Graph* parent;

			unsigned int subdivideThreshold;

			Matrix44 transform;

			void addEntityFromChild();

			void getEntitiesWithinBounds(const Model& bounds, const Vector3& position,
					std::vector<Entity*>& entitiesWithinBounds) const;

			void shiftEntitiesUpward();

			void subdivide();
	};
}

#endif /* OCTTREE_H_ */
