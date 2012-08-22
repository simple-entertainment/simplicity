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
#include <algorithm>

#include "../common/AddressEquals.h"
#include "NodeDoesNotExistException.h"

namespace simplicity
{
	template<typename NodeType>
	UndirectedGraph<NodeType>::UndirectedGraph() :
		nextId(0), nodes()
	{
	}

	template<typename NodeType>
	UndirectedGraph<NodeType>::UndirectedGraph(const UndirectedGraph<NodeType>& original) :
		nextId(0), nodes()
	{
		operator=(original);
	}

	template<typename NodeType>
	NodeType& UndirectedGraph<NodeType>::add(std::shared_ptr<NodeType> node)
	{
		NodeType& nodeRef = *node;

		node->setId(nextId++);
		nodes.push_back(move(node));

		return nodeRef;
	}

	template<typename NodeType>
	void UndirectedGraph<NodeType>::connect(NodeType& source, NodeType& destination)
	{
		source.connectTo(destination);
		destination.connectTo(source);
	}

	template<typename NodeType>
	void UndirectedGraph<NodeType>::disconnect(NodeType& source, NodeType& destination)
	{
		source.disconnectFrom(destination);
		destination.disconnectFrom(source);
	}

	template<typename NodeType>
	bool UndirectedGraph<NodeType>::exists(int id) const
	{
		for (shared_ptr<NodeType> node : nodes)
		{
			if (node->getId() == id)
			{
				return true;
			}
		}

		return false;
	}

	template<typename NodeType>
	bool UndirectedGraph<NodeType>::exists(NodeType& node) const
	{
		for (shared_ptr<NodeType> existingNode : nodes)
		{
			if (existingNode.get() == &node)
			{
				return true;
			}
		}

		return false;
	}

	template<typename NodeType>
	NodeType& UndirectedGraph<NodeType>::get(int id)
	{
		return const_cast<NodeType&>(static_cast<const UndirectedGraph<NodeType>&>(*this).get(id));
	}

	template<typename NodeType>
	const NodeType& UndirectedGraph<NodeType>::get(int id) const
	{
		for (shared_ptr<NodeType> node : nodes)
		{
			if (node->getId() == id)
			{
				return *node;
			}
		}

		throw NodeDoesNotExistException();
	}

	template<typename NodeType>
	const std::vector<std::shared_ptr<NodeType> >& UndirectedGraph<NodeType>::getAll() const
	{
		return nodes;
	}

	template<typename NodeType>
	UndirectedGraph<NodeType>& UndirectedGraph<NodeType>::operator=(const UndirectedGraph<NodeType>& original)
	{
		nextId = 0;
		nodes.clear();

		for (std::shared_ptr<NodeType> originalNode : original.getAll())
		{
			std::shared_ptr<NodeType> node = originalNode->copy();

			if (node->getId() >= nextId)
			{
				nextId = node->getId() + 1;
			}

			nodes.push_back(move(node));
		}

		for (std::shared_ptr<NodeType> originalNode : original.getAll())
		{
			for (std::reference_wrapper<NodeType> connectedNode : originalNode->getConnectedNodes())
			{
				get(originalNode->getId()).connectTo(get(connectedNode.get().getId()));
			}
		}

		return *this;
	}

	template<typename NodeType>
	void UndirectedGraph<NodeType>::remove(NodeType& node)
	{
		for (Node& connectedNode : node.getConnectedNodes())
		{
			disconnect(node, connectedNode);
		}

		nodes.erase(std::remove_if(nodes.begin(), nodes.end(), AddressEquals<NodeType>(node)));
	}
}
