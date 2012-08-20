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
#ifndef TREE_H_
#define TREE_H_

#include "Graph.h"

namespace simplicity
{
	template<typename NodeType>
	class Tree : public Graph<NodeType>
	{
		public:
			/**
			 * Connects a child to a parent. If the child is already connected to another parent, it is first
			 * disconnected from that parent.
			 *
			 * @param parent The parent of the connection to be created.
			 * @param child The child of the connection to be created.
			 */
			virtual void connect(NodeType& parent, NodeType& child) = 0;

			/**
			 * Disconnects a child from a parent.
			 *
			 * @param parent The parent of the connection to be removed.
			 * @param child The child of the connection to be removed.
			 */
			virtual void disconnect(NodeType& parent, NodeType& child) = 0;

			/**
			 * Retrieves the root {@link simplicity::Node Node} of this <code>Tree</code>.
			 *
			 * @return The root <code>Node</code> of this <code>Tree</code>.
			 */
			virtual NodeType& getRoot() = 0;

			/**
			 * Retrieves the root {@link simplicity::Node Node} of this <code>Tree</code>.
			 *
			 * @return The root <code>Node</code> of this <code>Tree</code>.
			 */
			virtual const NodeType& getRoot() const = 0;
	};
}

#endif /* TREE_H_ */
