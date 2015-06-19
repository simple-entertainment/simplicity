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
#ifndef LOGS_H_
#define LOGS_H_

#include "../common/Category.h"
#include "../resources/Resource.h"

namespace simplicity
{
	namespace Logs
	{
		/**
		 * <p>
		 * Logs a debug message using printf formatting.
		 * </p>
		 *
		 * <p>
		 * message is not a const reference because MSVC can't handle variadics after reference types...
		 * </p>
		 *
		 * @param tag The tag to log the message with.
		 * @param message The message to log.
		 * @param ... The arguments to include in the message.
		 */
		SIMPLE_API void debug(const std::string& tag, std::string message, ...);

		/**
		 * <p>
		 * Logs an error message using printf formatting.
		 * </p>
		 *
		 * <p>
		 * message is not a const reference because MSVC can't handle variadics after reference types...
		 * </p>
		 *
		 * @param tag The tag to log the message with.
		 * @param message The message to log.
		 * @param ... The arguments to include in the message.
		 */
		SIMPLE_API void error(const std::string& tag, std::string message, ...);

		/**
		 * <p>
		 * Logs a fatal message using printf formatting.
		 * </p>
		 *
		 * <p>
		 * message is not a const reference because MSVC can't handle variadics after reference types...
		 * </p>
		 *
		 * @param tag The tag to log the message with.
		 * @param message The message to log.
		 * @param ... The arguments to include in the message.
		 */
		SIMPLE_API void fatal(const std::string& tag, std::string message, ...);

		/**
		 * <p>
		 * Logs an info message using printf formatting.
		 * </p>
		 *
		 * <p>
		 * message is not a const reference because MSVC can't handle variadics after reference types...
		 * </p>
		 *
		 * @param tag The tag to log the message with.
		 * @param message The message to log.
		 * @param ... The arguments to include in the message.
		 */
		SIMPLE_API void info(const std::string& tag, std::string message, ...);

		/**
		 * <p>
		 * Logs a warning message using printf formatting.
		 * </p>
		 *
		 * <p>
		 * message is not a const reference because MSVC can't handle variadics after reference types...
		 * </p>
		 *
		 * @param tag The tag to log the message with.
		 * @param message The message to log.
		 * @param ... The arguments to include in the message.
		 */
		SIMPLE_API void warning(const std::string& tag, std::string message, ...);

		/**
		 * <p>
		 * Sets the resource for a particular tag prefix. Logs will be sent to the resource for the longest matching tag
		 * prefix. Setting the resource for the empty string ("") tag prefix will set the default resource which will be
		 * used for tags that do not have a resource set for a matching tag prefix.
		 * </p>
		 *
		 * @param resource The resource.
		 * @param tagPrefix The prefix of the tags to send to the resource.
		 */
		SIMPLE_API void setResource(Resource* resource, const std::string& tagPrefix);
	}
}

#endif /* LOGS_H_ */
