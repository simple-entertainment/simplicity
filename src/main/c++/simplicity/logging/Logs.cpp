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
		Resource* getResource(const string& tag);
		void log(const string& severity, const string& tag, string message, ...);

		map<string, Resource*> resources;
		Resource* defaultResource = nullptr;

		void debug(const string& tag, string message, ...)
		{
			va_list args;
			va_start(args, message);
			log("DEBUG", tag, message, args);
			va_end(args);
		}

		void error(const string& tag, string message, ...)
		{
			va_list args;
			va_start(args, message);
			log("ERROR", tag, message, args);
			va_end(args);
		}

		void fatal(const string& tag, string message, ...)
		{
			va_list args;
			va_start(args, message);
			log("FATAL", tag, message, args);
			va_end(args);
		}

		Resource* getResource(const string& tag)
		{
			Resource* resource = nullptr;

			unsigned int matchingPrefixLength = 0;
			for (pair<string, Resource*> candidateResource : resources)
			{
				unsigned int prefixLength = candidateResource.first.size();
				if (prefixLength <= matchingPrefixLength)
				{
					continue;
				}

				if (prefixLength <= tag.size() && candidateResource.first == tag.substr(0, prefixLength))
				{
					resource = candidateResource.second;
					matchingPrefixLength = prefixLength;
				}
			}

			if (resource == nullptr)
			{
				// Provide the default logging resource.
				if (defaultResource == nullptr)
				{
					setResource(Resources::get("out", Category::CONSOLE), "");
				}

				resource = defaultResource;
			}

			return resource;
		}

		void info(const string& tag, string message, ...)
		{
			va_list args;
			va_start(args, message);
			log("INFO", tag, message, args);
			va_end(args);
		}

		void log(const string& severity, const string& tag, string message, ...)
		{
			std::string formattedMessage(message.size() + MAX_ARG_BUFFER_SIZE, 'x');

			va_list args;
			va_start(args, message);
			vsnprintf(&formattedMessage[0], formattedMessage.size(), message.c_str(), args);
			va_end(args);

			// Cut off the trailing 'x's.
			formattedMessage = formattedMessage.c_str();

			// For error and fatal logs, cause the debugger to break.
			if (severity == "ERROR" ||
				severity == "FATAL")
			{
				DEBUG_BREAK;
			}

			Resource* resource = getResource(tag);
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

			resource->appendData(timeString + " || " + tag + " || " + severity + " || " + formattedMessage + '\n');
		}

		void setResource(Resource* resource, const string& tagPrefix)
		{
			if (tagPrefix.size() == 0)
			{
				defaultResource = resource;
			}
			else
			{
				resources[tagPrefix] = resource;
			}
		}

		void warning(const string& tag, string message, ...)
		{
			va_list args;
			va_start(args, message);
			log("WARNING", tag, message, args);
			va_end(args);
		}
	}
}
