/*
 * Copyright © 2014 Simple Entertainment Limited
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
#include <map>

#include "Logs.h"

using namespace std;

namespace simplicity
{
	namespace Logs
	{
		Resource* getResource(unsigned short category);

		map<unsigned short, Resource*> resources;
		Resource* defaultResource;

		Resource* getResource(unsigned short category)
		{
			Resource* resource = resources[category];

			if (resource == NULL)
			{
				resource = defaultResource;
			}

			return resource;
		}

		void log(unsigned short category, const string& message)
		{
			Resource* resource = getResource(category);

			if (resource != NULL)
			{
				resource->appendData(message + '\n');
			}
		}

		void setResource(Resource* resource, unsigned short category)
		{
			if (category == Categories::ALL_CATEGORIES)
			{
				defaultResource = resource;
			}
			else
			{
				resources[category] = resource;
			}
		}
	}
}
