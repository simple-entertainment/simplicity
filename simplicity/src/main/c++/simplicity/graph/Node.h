/*
 * Copyright © 2011 Simple Entertainment Limited
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
#ifndef NODE_H_
#define NODE_H_

#include <vector>

#include "../Component.h"
#include "../math/TransformationMatrix.h"
#include "BoundingVolume.h"

namespace simplicity
{
	/**
	 * <p>
	 * A node in a {@link simplicity::Graph Graph}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class Node
	{
		public:
			virtual void connectTo(Node& otherNode) = 0;

			/**
			 * <p>
			 * Allows for polymorphic copying.
			 * </p>
			 */
			virtual std::shared_ptr<Node> copy() const = 0;

			virtual void disconnectFrom(Node& otherNode) = 0;

			//virtual BoundingVolume* getBoundingVolume() = 0;

			//virtual const BoundingVolume* getBoundingVolume() const = 0;

			virtual Component* getComponent() const = 0;

			virtual std::vector<std::reference_wrapper<Node> > getConnectedNodes() const = 0;

			/**
			 * <p>
			 * Retrieves this <code>Node</code>'s unique identifier.
			 * </p>
			 *
			 * @return This <code>Node</code>'s unique identifier.
			 */
			virtual int getId() const = 0;

			/**
			 * <p>
			 * Retrieves this <code>Node</code>'s relative position and orientation.
			 * </p>
			 *
			 * @return This <code>Node</code>'s relative position and orientation.
			 */
			virtual TransformationMatrix<>& getTransformation() const = 0;

			//virtual void setBoundingVolume(shared_ptr<BoundingVolume> boundingVolume) = 0;

			virtual void setComponent(Component* component) = 0;

			/**
			 * <p>
			 * Sets this <code>Node</code>'s unique identifier. This identifier should be managed by the
			 * {@link simplicity::Scene Scene}.
			 * </p>
			 *
			 * @param id This <code>Node</code>'s unique identifier.
			 */
			virtual void setId(const int id) = 0;

			/**
			 * <p>
			 * Sets this <code>Node</code>'s relative position and orientation.
			 * </p>
			 *
			 * @param transformation This <code>Node</code>'s relative position and orientation.
			 */
			virtual void setTransformation(std::unique_ptr<TransformationMatrix<> > transformation) = 0;
	};
}

#endif /* NODE_H_ */
