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
#include "SimpleModelNode.h"

using namespace std;

namespace simplicity
{
	SimpleModelNode::SimpleModelNode()
	{
	}

	SimpleModelNode::~SimpleModelNode()
	{
	}

	shared_ptr<Model> SimpleModelNode::getModel() const
	{
		return (model);
	}

	void SimpleModelNode::setModel(shared_ptr<Model> model)
	{
		this->model = model;
	}
}
