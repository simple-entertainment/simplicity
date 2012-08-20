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
#include <memory>

#include "GraphFunctions.h"

namespace simplicity
{
	namespace GraphFunctions
	{
		template<typename GraphType, typename NodeType, typename ConcreteNodeType>
		GraphType copy(const GraphType& original)
		{
			GraphType copy;

			for (std::shared_ptr<NodeType> originalNode : original.getAll())
			{
				std::shared_ptr<NodeType> node(new ConcreteNodeType(*dynamic_pointer_cast<ConcreteNodeType>(originalNode)));
				copy.add(node);
			}

			for (std::shared_ptr<NodeType> originalNode : original.getAll())
			{
				for (std::reference_wrapper<NodeType> connectedNode : originalNode->getConnectedNodes())
				{
					copy.get(originalNode->getId()).connectTo(copy.get(connectedNode.get().getId()));
				}
			}

			return copy;
		}
	}
}
