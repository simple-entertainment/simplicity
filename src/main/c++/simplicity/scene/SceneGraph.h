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
#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_

#include <memory>
#include <vector>

#include "../math/Matrix.h"
#include "../model/Model.h"
#include "SceneState.h"

namespace simplicity
{
	/**
	 * <p>
	 * An interconnected collection of nodes. The nodes in the graph are themselves graphs in their own right and so
	 * they can also contain multiple nodes. Tree structures can be created as well as DAGs (directed acyclic graphs)
	 * etc. using this interface. Each node can contain multiple entities.
	 * </p>
	 */
	class SIMPLE_API SceneGraph : public SceneState
	{
		public:
			/**
			 * <p>
			 * Connects this node to another node.
			 * </p>
			 *
			 * @param graph The node to connect this node to.
			 */
			virtual void connectTo(SceneGraph& graph) = 0;

			/**
			 * <p>
			 * Disconnects this node from another node.
			 * </p>
			 *
			 * @param graph The node to disconnect this node from.
			 */
			virtual void disconnectFrom(SceneGraph& graph) = 0;

			/**
			 * <p>
			 * Retrieves the absolute position and orientation of this graph.
			 * </p>
			 *
			 * @return The absolute position and orientation of this graph.
			 */
			virtual Matrix44 getAbsoluteTransform() const = 0;

			/**
			 * <p>
			 * Retrieves the bounding volume for this node. This bounding volume contains all the entities of this node
			 * as well as the entities of its successor nodes.
			 * </p>
			 *
			 * @return The bounding volume for this node.
			 */
			virtual const Model& getBoundary() const = 0;

			/**
			 * <p>
			 * Retrieves the nodes in this graph.
			 * </p>
			 *
			 * @return The nodes in this graph.
			 */
			virtual std::vector<SceneGraph*> getChildren() const = 0;
			// TODO could we just return a const reference to the smart pointer vector?

			/**
			 * <p>
			 * Retrieves the entities in this node. This does not include the entities of its successor nodes.
			 * </p>
			 *
			 * @return The entities in this node.
			 */
			virtual std::vector<Entity*>& getEntities() = 0;

			/**
			 * <p>
			 * Retrieves the entities in this node. This does not include the entities of its successor nodes.
			 * </p>
			 *
			 * @return The entities in this node.
			 */
			virtual const std::vector<Entity*>& getEntities() const = 0;

			/**
			 * <p>
			 * Retrieves the entities within this graph whose bounds intersect with the bounds given. This includes the
			 * entities of its successor nodes.
			 * </p>
			 *
			 * @param bounds The bounds to check against.
			 * @param position The position of the bounds.
			 *
			 * @return The entities within this graph whose bounds intersect with the bounds given.
			 */
			virtual std::vector<Entity*> getEntitiesWithinBounds(const Model& bounds, const Vector3& position) const = 0;

			/**
			 * <p>
			 * Retrieves the parent of this graph (the graph in which this graph is a node).
			 * </p>
			 *
			 * @return The parent of this graph.
			 */
			virtual SceneGraph* getParent() = 0;

			/**
			 * <p>
			 * Retrieves the parent of this graph (the graph in which this graph is a node).
			 * </p>
			 *
			 * @return The parent of this graph.
			 */
			virtual const SceneGraph* getParent() const = 0;

			/**
			 * <p>
			 * Retrieves the position and orientation of this graph relative to its parent.
			 * </p>
			 *
			 * @return The position and orientation of this graph relative to its parent.
			 */
			virtual Matrix44& getTransform() = 0;

			/**
			 * <p>
			 * Retrieves the position and orientation of this graph relative to its parent.
			 * </p>
			 *
			 * @return The position and orientation of this graph relative to its parent.
			 */
			virtual const Matrix44& getTransform() const = 0;

			/**
			 * <p>
			 * Inserts an entity into the graph.
			 * </p>
			 *
			 * @param entity The entity to insert.
			 *
			 * @return True if the insertion was successful, false otherwise.
			 */
			virtual bool insert(Entity& entity) = 0;

			/**
			 * <p>
			 * Inserts an entity into the graph under the given parent. To be successful, the parent must be this graph
			 * or one of its successors. Some implementations e.g. QuadTree and OctTree may ignore the request and
			 * insert the entity where they need to in order to maintain the graph's integrity.
			 * </p>
			 *
			 * @param entity The entity to insert.
			 * @param parent The parent to insert the entity under.
			 *
			 * @return True if the insertion was successful, false otherwise.
			 */
			virtual bool insert(Entity& entity, const Entity& parent) = 0;

			void onAddComponent(Component& component) override;

			void onAddEntity(Entity& entity) override;

			void onRemoveComponent(Component& component) override;

			void onRemoveEntity(Entity& entity) override;

			void onTransformEntity(Entity& entity) override;

			/**
			 * <p>
			 * Removes an entity from the graph.
			 * </p>
			 *
			 * @param entity The entity to remove.
			 */
			virtual bool remove(const Entity& entity) = 0;

			/**
			 * <p>
			 * Sets the parent of this graph (the graph in which this graph is a node).
			 * </p>
			 *
			 * @param parent The parent of this graph.
			 */
			virtual void setParent(SceneGraph* parent) = 0;

			/**
			 * <p>
			 * Sets the position and orientation of this graph relative to its parent.
			 * </p>
			 *
			 * @param transform The position and orientation of this graph relative to its parent.
			 */
			virtual void setTransform(const Matrix44& transform) = 0;

			/**
			 * <p>
			 * Updates this graph to reflect any changes to the given entity e.g. a change in position and/or
			 * orientation.
			 * </p>
			 *
			 * @param entity The entity who's changes should be reflected in this graph.
			 */
			virtual void update(Entity& entity) = 0;
	};
}

#endif /* SCENEGRAPH_H_ */
