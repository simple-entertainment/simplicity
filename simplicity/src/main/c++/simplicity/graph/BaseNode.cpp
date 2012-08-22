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
#include "../math/MathFactory.h"
#include "BaseNode.h"

namespace simplicity
{
	BaseNode::BaseNode() :
		/*boundingVolume(),*/ component(NULL), id(0), transformation(
			MathFactory::getInstance().createTransformationMatrix())
	{
	}

	/*BoundingVolume* BaseNode::getBoundingVolume()
	{
		return boundingVolume.get();
	}

	const BoundingVolume* BaseNode::getBoundingVolume() const
	{
		return boundingVolume.get();
	}*/

	Component* BaseNode::getComponent() const
	{
		return component;
	}

	int BaseNode::getId() const
	{
		return id;
	}

	TransformationMatrix<>& BaseNode::getTransformation() const
	{
		return *transformation;
	}

	BaseNode& BaseNode::operator=(const BaseNode& original)
	{
		setComponent(original.getComponent());
		setId(original.getId());
		getTransformation().setData(original.getTransformation().getData());

		return *this;
	}

	/*void BaseNode::getBoundingVolume(BoundingVolume* boundingVolume)
	{
		this->boundingVolume = boundingVolume;
	}*/

	void BaseNode::setComponent(Component* component)
	{
		this->component = component;
	}

	void BaseNode::setId(const int id)
	{
		this->id = id;
	}

	void BaseNode::setTransformation(unique_ptr<TransformationMatrix<> > transformation)
	{
		this->transformation = move(transformation);
	}
}
