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
#include "Component.h"
#include "Entity.h"

using namespace std;

namespace simplicity
{
	unsigned int Entity::nextId = 0;

	Entity::Entity(unsigned short category, const std::string& name) :
		category(category),
		id(nextId++),
		name(name),
		sharedComponents(),
		transform(),
		uniqueComponents()
	{
		transform.setIdentity();
	}

	void Entity::addSharedComponent(shared_ptr<Component> component)
	{
		sharedComponents.push_back(component);
	}

	void Entity::addUniqueComponent(unique_ptr<Component> component)
	{
		uniqueComponents.push_back(move(component));
	}

	unsigned short Entity::getCategory() const
	{
		return category;
	}

	unsigned int Entity::getId() const
	{
		return id;
	}

	const string& Entity::getName() const
	{
		return name;
	}

	Matrix44& Entity::getTransform()
	{
		return transform;
	}

	const Matrix44& Entity::getTransform() const
	{
		return transform;
	}

	shared_ptr<Component> Entity::removeSharedComponent(Component* component)
	{
		shared_ptr<Component> removedComponent;
		vector<shared_ptr<Component>>::iterator result =
				find_if(sharedComponents.begin(), sharedComponents.end(), AddressEquals<Component>(*component));

		if (result != sharedComponents.end())
		{
			removedComponent.swap(*result);
			sharedComponents.erase(result);
			component = NULL;
		}

		return removedComponent;
	}

	unique_ptr<Component> Entity::removeUniqueComponent(Component* component)
	{
		unique_ptr<Component> removedComponent;
		vector<unique_ptr<Component>>::iterator result =
				find_if(uniqueComponents.begin(), uniqueComponents.end(), AddressEquals<Component>(*component));

		if (result != uniqueComponents.end())
		{
			removedComponent.swap(*result);
			uniqueComponents.erase(result);
			component = NULL;
		}

		return move(removedComponent);
	}

	void Entity::setTransform(const Matrix44& transform)
	{
		this->transform = transform;
	}
}
