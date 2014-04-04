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
		 * Logs a message.
		 * </p>
		 *
		 * @param category The category to log the message in.
		 * @param message The message to log.
		 */
		SIMPLE_API void log(unsigned short category, const std::string& message);

		/**
		 * <p>
		 * Sets the resource for a particular category. Setting the resource for the Categories::ALL_CATEGORIES
		 * category will set the default resource which will be used for categories that do not have a resource
		 * explicitly set for them.
		 * </p>
		 *
		 * @param resource The resource.
		 * @param category The category the resource will be used for.
		 */
		SIMPLE_API void setResource(Resource* resource, unsigned short category);
	}
}

#endif /* LOGS_H_ */
