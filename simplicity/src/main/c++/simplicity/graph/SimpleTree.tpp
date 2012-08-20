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
	SimpleTree<NodeType>::SimpleTree(std::shared_ptr<NodeType> root) :
		nextId(0), nodes(), root(add(move(root)))
	{
	}

	template<typename NodeType>
	NodeType& SimpleTree<NodeType>::add(std::shared_ptr<NodeType> node)
	{
		NodeType& nodeRef = *node;

		node->setId(nextId++);
		nodes.push_back(move(node));

		return nodeRef;
	}

	template<typename NodeType>
	void SimpleTree<NodeType>::connect(NodeType& parent, NodeType& child)
	{
		if (child.getParent() != NULL)
		{
			disconnect(*child.getParent(), child);
		}

		child.connectTo(parent);
		parent.addChild(child);
	}

	template<typename NodeType>
	void SimpleTree<NodeType>::disconnect(NodeType& parent, NodeType& child)
	{
		child.disconnectFrom(parent);
		parent.removeChild(child);
	}

	template<typename NodeType>
	NodeType& SimpleTree<NodeType>::get(int id)
	{
		return const_cast<NodeType&>(static_cast<const SimpleTree<NodeType>&>(*this).get(id));
	}

	template<typename NodeType>
	const NodeType& SimpleTree<NodeType>::get(int id) const
	{
		for (std::shared_ptr<NodeType> node : nodes)
		{
			if (node->getId() == id)
			{
				return *node;
			}
		}

		throw NodeDoesNotExistException();
	}

	template<typename NodeType>
	const std::vector<std::shared_ptr<NodeType> >& SimpleTree<NodeType>::getAll() const
	{
		return nodes;
	}

	template<typename NodeType>
	NodeType& SimpleTree<NodeType>::getRoot()
	{
		return root;
	}

	template<typename NodeType>
	const NodeType& SimpleTree<NodeType>::getRoot() const
	{
		return root;
	}

	template<typename NodeType>
	void SimpleTree<NodeType>::remove(NodeType& node)
	{
		for (unsigned int index = 0; index < node.getChildren().size(); index++)
		{
			remove(node.getChildren().at(index).get());
		}

		if (node.getParent() != NULL)
		{
			disconnect(*node.getParent(), node);
		}

		nodes.erase(std::remove_if(nodes.begin(), nodes.end(), AddressEquals<NodeType>(node)));
	}
}
