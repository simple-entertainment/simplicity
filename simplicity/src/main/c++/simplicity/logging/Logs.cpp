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

#include "../resources/Resources.h"
#include "Logs.h"

using namespace std;

const unsigned int MAX_ARG_BUFFER_SIZE = 1024;

namespace simplicity
{
	namespace Logs
	{
		Resource* getResource(unsigned short category);

		map<unsigned short, Resource*> resources;
		Resource* defaultResource = nullptr;

		Resource* getResource(unsigned short category)
		{
			Resource* resource = resources[category];

			if (resource == nullptr)
			{
				// Provide the default logging resource.
				if (defaultResource == nullptr)
				{
					setResource(Resources::get("out", Category::CONSOLE), Category::ALL_CATEGORIES);
				}

				resource = defaultResource;
			}

			return resource;
		}

		void log(unsigned short category, string message, ...)
		{
			std::string formattedMessage(message.size() + MAX_ARG_BUFFER_SIZE, 'x');

			va_list args;
			va_start(args, message);
			vsnprintf(&formattedMessage[0], formattedMessage.size(), message.c_str(), args);
			va_end(args);

			// Cut off the trailing 'x's.
			formattedMessage = formattedMessage.c_str();

			// For error and fatal logs, cause the debugger to break.
			if (category == Category::ERROR_LOG ||
				category == Category::FATAL_LOG)
			{
				DEBUG_BREAK;
			}

			Resource* resource = getResource(category);
			if (resource == nullptr)
			{
				return;
			}

			time_t now;
			time(&now);
			string timeString(80, 'x');
			strftime(&timeString[0], timeString.size(), "%d-%m-%Y %I:%M:%S", localtime(&now));

			// Remove the trailing 'x's.
			timeString = timeString.c_str();

			resource->appendData(timeString + " :: " + formattedMessage + '\n');
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
