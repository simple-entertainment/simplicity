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
#include "Entity.h"

using namespace std;

namespace simplicity
{
	template<typename ComponentType>
	vector<shared_ptr<ComponentType> > Entity::getComponents() const
	{
		vector<shared_ptr<ComponentType> > typedComponents;

		for (unsigned int index = 0; index < components.size(); index++)
		{
			shared_ptr<ComponentType> component(dynamic_pointer_cast<ComponentType>(components.at(index)));
			if (component.get() != NULL)
			{
				typedComponents.push_back(component);
			}
		}

		return typedComponents;
	}

	template<typename ComponentType>
	std::shared_ptr<ComponentType> Entity::getSingleComponent() const
	{
		for (unsigned int index = 0; index < components.size(); index++)
		{
			shared_ptr<ComponentType> component(dynamic_pointer_cast<ComponentType>(components.at(index)));
			if (component.get() != NULL)
			{
				return component;
			}
		}

		return std::shared_ptr<ComponentType>();
	}
}
