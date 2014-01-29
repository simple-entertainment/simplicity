/*
 * Copyright © 2013 Simple Entertainment Limited
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
#include "Component.h"
#include "Entity.h"

namespace simplicity
{
	Component::Component() :
		entity(NULL),
		transformation()
	{
		transformation.setIdentity();
	}

	Component::~Component()
	{
	}

	Entity* Component::getEntity()
	{
		return entity;
	}

	const Entity* Component::getEntity() const
	{
		return entity;
	}

	void Component::setEntity(Entity* entity)
	{
		this->entity = entity;
	}

	Matrix44& Component::getTransformation()
	{
		return transformation;
	}

	const Matrix44& Component::getTransformation() const
	{
		return transformation;
	}

	void Component::setTransformation(const Matrix44& transformation)
	{
		this->transformation = transformation;
	}
}
