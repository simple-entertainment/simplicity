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
#include <algorithm>

#include "../common/AddressEquals.h"
#include "SimpleNode.h"

using namespace std;

namespace simplicity
{
	SimpleNode::SimpleNode() :
		connectedNodes()
	{
	}

	SimpleNode::SimpleNode(const SimpleNode& original) :
		connectedNodes()
	{
		operator=(original);
	}

	void SimpleNode::connectTo(Node& otherNode)
	{
		connectedNodes.push_back(otherNode);
	}

	std::shared_ptr<Node> SimpleNode::copy() const
	{
		std::shared_ptr<Node> copy(new SimpleNode(*this));
		return copy;
	}

	void SimpleNode::disconnectFrom(Node& otherNode)
	{
		connectedNodes.erase(remove_if(connectedNodes.begin(), connectedNodes.end(), AddressEquals<Node>(otherNode)));
	}

	vector<reference_wrapper<Node> > SimpleNode::getConnectedNodes() const
	{
		return connectedNodes;
	}

	SimpleNode& SimpleNode::operator=(const SimpleNode& original)
	{
		BaseNode::operator=(original);
		connectedNodes.clear();

		return *this;
	}
}
