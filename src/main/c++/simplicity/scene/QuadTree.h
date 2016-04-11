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

#include "../common/NonCopyable.h"
#include "../model/Model.h"
#include "../model/shape/Square.h"
#include "SceneGraph.h"

namespace simplicity
{
	/**
	 * <p>
	 * A tree that uses a square bounding volume. Once the subdivision threshold has been reached, it will create 4
	 * children, each with a bounding volume one-fourth the size of this one and any entities that can fit within them
	 * will be inserted into them instead of this node. This insertion works recursively until either the child nodes
	 * have a bounding volume too small to contain the entity or a node is found that has not yet reached its
	 * subdivision threshold.
	 * </p>
	 *
	 * <p>
	 * When using this tree in a 3d scene, the bounding volume can be placed on any of the planes of the three major
	 * axis i.e. XY, XZ or YZ.
	 * </p>
	 */
	class SIMPLE_API QuadTree : public SceneGraph, private NonCopyable
	{
		public:
			/**
			 * <p>
			 * THe plane that the bounding volume is placed on.
			 * </p>
			 */
			enum class Plane
			{
				XY,
				XZ//,
				//YZ TODO
			};

			/**
			 * @param subdivideThreshold The number of entities that can be inserted into this graph before it creates
			 * children.
			 * @param bounds The bounding volume of this graph.
			 * @param plane The plane that the bounding volume will be placed on.
			 */
			QuadTree(unsigned int subdivideThreshold, const Square& bounds, Plane plane = Plane::XY);

			void connectTo(SceneGraph& graph) override;

			void disconnectFrom(SceneGraph& graph) override;

			Matrix44 getAbsoluteTransform() const override;

			const Shape& getBounds() const override;

			std::vector<SceneGraph*> getChildren() const override;

			std::vector<Entity*>& getEntities() override;

			const std::vector<Entity*>& getEntities() const override;

			std::vector<Entity*> getEntitiesWithinBounds(const Shape& bounds, const Vector3& position) const override;

			SceneGraph* getParent() override;

			const SceneGraph* getParent() const override;

			Matrix44& getTransform() override;

			const Matrix44& getTransform() const override;

			bool insert(Entity& entity) override;

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
			bool insert(Entity& entity, const Entity& parent) override;

			bool remove(const Entity& entity) override;

			void setParent(SceneGraph* parent) override;

			void setTransform(const Matrix44& transform) override;

			void update(Entity& entity) override;

		private:
			Matrix44 absoluteTransform;

			Square bounds;

			std::vector<std::unique_ptr<QuadTree>> children;

			std::vector<SceneGraph*> connections;

			std::vector<Entity*> entities;

			SceneGraph* parent;

			Plane plane;

			unsigned int subdivideThreshold;

			Matrix44 transform;

			void addEntityFromChild();

			void getEntitiesWithinBounds(const Shape& bounds, const Vector3& position,
					std::vector<Entity*>& entitiesWithinBounds) const;

			bool isWithinBounds(const Entity& entity, const Shape& bounds, const Vector3& position) const;

			Vector3 projectOntoPlane(const Vector3& position) const;

			void subdivide();
	};
}

#endif /* QUADTREE_H_ */
