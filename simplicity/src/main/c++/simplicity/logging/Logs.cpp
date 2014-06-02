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
#include <cassert>
#include <cstdarg>
#include <map>

#include "Logs.h"

using namespace std;

const unsigned int MAX_ARG_BUFFER_SIZE = 1024;

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

		void log(unsigned short category, const string& message, ...)
		{
			if (category == Category::ERROR_LOG ||
				category == Category::FATAL_LOG)
			{
				assert(false);
			}

			Resource* resource = getResource(category);
			if (resource != NULL)
			{
				std::string buffer(message.size() + MAX_ARG_BUFFER_SIZE, ' ');

				va_list args;
				va_start(args, message);
				vsnprintf(&buffer[0], buffer.size(), message.data(), args);
				va_end(args);

				resource->appendData(buffer + '\n');
			}
		}

		void setResource(Resource* resource, unsigned short category)
		{
			if (category == Category::ALL_CATEGORIES)
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
