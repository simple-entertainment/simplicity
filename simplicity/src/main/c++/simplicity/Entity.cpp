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

#include "common/AddressEquals.h"

#include "Entity.h"

using namespace std;

namespace simplicity
{
	Entity::Entity(const string& name) :
		components(), name(name)
	{
	}

	Entity::~Entity()
	{
	}

	void Entity::addComponent(shared_ptr<Component> component)
	{
		components.push_back(component);
	}

	const string& Entity::getName() const
	{
		return name;
	}

	void Entity::removeComponent(const Component& component)
	{
		vector<shared_ptr<Component> >::iterator sharedComponent(
			find_if(components.begin(), components.end(), AddressEquals<Component>(component)));

		components.erase(sharedComponent);
	}
}
