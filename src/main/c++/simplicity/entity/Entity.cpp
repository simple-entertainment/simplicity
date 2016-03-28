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
#include "../math/MathFunctions.h"
#include "../scene/Scene.h"
#include "Component.h"
#include "Entity.h"

using namespace std;

namespace simplicity
{
	unsigned int Entity::nextId = 0;

	Entity::Entity(unsigned short category, const std::string& name) :
		category(category),
		components(),
		id(nextId++),
		name(name),
		scene(nullptr),
		transform()
	{
		transform.setIdentity();
	}

	void Entity::addComponent(unique_ptr<Component> component)
	{
		component->setEntity(this);
		components.push_back(move(component));

		if (scene != nullptr)
		{
			scene->onAddComponent(*components.back());
		}
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

	Vector3 Entity::getPosition() const
	{
		return simplicity::getPosition3(transform);
	}

	Scene* Entity::getScene() const
	{
		return scene;
	}

	Matrix44& Entity::getTransform()
	{
		return transform;
	}

	const Matrix44& Entity::getTransform() const
	{
		return transform;
	}

	unique_ptr<Component> Entity::removeComponent(Component& component)
	{
		unique_ptr<Component> removedComponent;
		vector<unique_ptr<Component>>::iterator result =
				find_if(components.begin(), components.end(), AddressEquals<Component>(component));

		if (result != components.end())
		{
			if (scene != nullptr)
			{
				scene->onRemoveComponent(component);
			}

			removedComponent = move(*result);
			removedComponent->setEntity(nullptr);
			components.erase(result);
		}

		return move(removedComponent);
	}

	void Entity::rotate(float angle, const Vector3& axis)
	{
		simplicity::rotate(transform, angle, axis);

		if (scene != nullptr)
		{
			scene->onTransformEntity(*this);
		}
	}

	void Entity::scale(const Vector3& scale)
	{
		simplicity::scale(transform, scale);

		if (scene != nullptr)
		{
			scene->onTransformEntity(*this);
		}
	}

	void Entity::setPosition(const Vector3& position)
	{
		simplicity::setPosition(transform, position);

		if (scene != nullptr)
		{
			scene->onTransformEntity(*this);
		}
	}

	void Entity::setScene(Scene* scene)
	{
		this->scene = scene;
	}

	void Entity::setTransform(const Matrix44& transform)
	{
		this->transform = transform;

		if (scene != nullptr)
		{
			scene->onTransformEntity(*this);
		}
	}

	void Entity::translate(const Vector3& translation)
	{
		simplicity::translate(transform, translation);

		if (scene != nullptr)
		{
			scene->onTransformEntity(*this);
		}
	}
}
