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
#include <stack>

#include "../common/AddressEquals.h"
#include "../math/MathFactory.h"
#include "SimpleNode.h"
#include "PreorderConstNodeIterator.h"

using namespace std;

namespace simplicity
{
	SimpleNode::SimpleNode() :
		component(NULL), connectedNodes(), id(0), transformation(
			MathFactory::getInstance().createTransformationMatrix())
	{
	}

	SimpleNode::SimpleNode(const SimpleNode& original) :
		component(NULL), connectedNodes(), id(0), transformation(
			MathFactory::getInstance().createTransformationMatrix())
	{
		operator=(original);
	}

	SimpleNode::~SimpleNode()
	{
	}

	void SimpleNode::connectTo(Node& otherNode)
	{
		connectedNodes.push_back(otherNode);
	}

	void SimpleNode::disconnectFrom(Node& otherNode)
	{
		connectedNodes.erase(remove_if(connectedNodes.begin(), connectedNodes.end(), AddressEquals<Node>(otherNode)));
	}

	Component* SimpleNode::getComponent() const
	{
		return component;
	}

	vector<reference_wrapper<Node> > SimpleNode::getConnectedNodes() const
	{
		return connectedNodes;
	}

	int SimpleNode::getId() const
	{
		return id;
	}

	TransformationMatrix<>& SimpleNode::getTransformation() const
	{
		return *transformation;
	}

	SimpleNode& SimpleNode::operator=(const SimpleNode& original)
	{
		setComponent(original.getComponent());
		setId(original.getId());
		transformation->setData(original.getTransformation().getData());

		return *this;
	}

	void SimpleNode::setComponent(Component* component)
	{
		this->component = component;
	}

	void SimpleNode::setId(const int id)
	{
		this->id = id;
	}

	void SimpleNode::setTransformation(unique_ptr<TransformationMatrix<> > transformation)
	{
		this->transformation = move(transformation);
	}
}
