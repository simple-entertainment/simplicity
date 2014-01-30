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
#include "Component.h" // Must be after Entity.h

using namespace std;

namespace simplicity
{
	template<typename ComponentType>
	ComponentType* Entity::getComponent(unsigned short category) const
	{
		for (unsigned int index = 0; index < uniqueComponents.size(); index++)
		{
			if (category == Categories::ALL_CATEGORIES || uniqueComponents[index]->getCategory() == category)
			{
				ComponentType* component = dynamic_cast<ComponentType*>(uniqueComponents[index].get());
				if (component != NULL)
				{
					return component;
				}
			}
		}

		for (unsigned int index = 0; index < sharedComponents.size(); index++)
		{
			if (category == Categories::ALL_CATEGORIES || sharedComponents[index]->getCategory() == category)
			{
				ComponentType* component = dynamic_cast<ComponentType*>(sharedComponents[index].get());
				if (component != NULL)
				{
					return component;
				}
			}
		}

		return NULL;
	}

	template<typename ComponentType>
	std::vector<ComponentType*> Entity::getComponents(unsigned short category) const
	{
		std::vector<ComponentType*> typedComponents;

		for (unsigned int index = 0; index < uniqueComponents.size(); index++)
		{
			if (category == Categories::ALL_CATEGORIES || uniqueComponents[index]->getCategory() == category)
			{
				ComponentType* component = dynamic_cast<ComponentType*>(uniqueComponents[index].get());
				if (component != NULL)
				{
					typedComponents.push_back(component);
				}
			}
		}

		for (unsigned int index = 0; index < sharedComponents.size(); index++)
		{
			if (category == Categories::ALL_CATEGORIES || sharedComponents[index]->getCategory() == category)
			{
				ComponentType* component = dynamic_cast<ComponentType*>(sharedComponents[index].get());
				if (component != NULL)
				{
					typedComponents.push_back(component);
				}
			}
		}

		return typedComponents;
	}
}
