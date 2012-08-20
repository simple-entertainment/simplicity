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
#include "NodeFactory.h"
#include "SimpleNodeFactory.h"

using namespace std;

namespace simplicity
{
	unique_ptr<NodeFactory> NodeFactory::instance = unique_ptr<NodeFactory>();

	NodeFactory::~NodeFactory()
	{
	}

	const NodeFactory& NodeFactory::getInstance()
	{
		if (instance.get() == NULL)
		{
			instance.reset(new SimpleNodeFactory);
		}

		return *instance;
	}

	void NodeFactory::setInstance(unique_ptr<NodeFactory> instance)
	{
		NodeFactory::instance = move(instance);
	}
}
