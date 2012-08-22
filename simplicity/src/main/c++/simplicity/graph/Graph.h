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
#ifndef GRAPH_H_
#define GRAPH_H_

#include <memory>
#include <vector>

#include "Node.h"

namespace simplicity
{
	template<typename NodeType>
	class Graph
	{
		public:
			virtual NodeType& add(std::shared_ptr<NodeType> node) = 0;

			virtual void connect(NodeType& source, NodeType& destination) = 0;

			virtual void disconnect(NodeType& source, NodeType& destination) = 0;

			virtual bool exists(int id) const = 0;

			virtual bool exists(NodeType& node) const = 0;

			virtual NodeType& get(int id) = 0;

			virtual const NodeType& get(int id) const = 0;

			virtual const std::vector<std::shared_ptr<NodeType> >& getAll() const = 0;

			virtual void remove(NodeType& node) = 0;
	};
}

#endif /* GRAPH_H_ */
