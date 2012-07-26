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

#include "NodeDoesNotExistException.h"

namespace simplicity
{
	template<typename NodeType>
	SimpleTree<NodeType>::SimpleTree(std::shared_ptr<NodeType> root) :
		nextId(0), nodes(), root(&add(move(root)))
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
	void SimpleTree<NodeType>::connect(Node& parent, Node& child)
	{
		if (child.getParent().get() != NULL)
		{
			disconnect(parent, *child.getParent());
		}

		parent.addChild(child.getThisShared());
		child.setParent(parent.getThisShared());
	}

	template<typename NodeType>
	void SimpleTree<NodeType>::disconnect(Node& parent, Node& child)
	{
		parent.removeChild(child);
		child.setParent(std::shared_ptr<NodeType>());
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
		return *root;
	}

	template<typename NodeType>
	const NodeType& SimpleTree<NodeType>::getRoot() const
	{
		return *root;
	}

	template<typename NodeType>
	void SimpleTree<NodeType>::remove(Node& node)
	{
		for (std::shared_ptr<Node> child : node.getChildren())
		{
			remove(*child);
		}

		if (node.getParent().get() != NULL)
		{
			node.getParent()->removeChild(node);
			node.setParent(std::shared_ptr<NodeType>());
		}

		nodes.erase(std::remove(nodes.begin(), nodes.end(), node.getThisShared()));
	}
}