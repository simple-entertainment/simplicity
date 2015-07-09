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
#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <memory>

#include "../common/Category.h"
#include "DataStore.h"

namespace simplicity
{
	namespace Resources
	{
		/**
		 * <p>
		 * Creates a resource.
		 * </p>
		 *
		 * @param name The name of the resource.
		 * @param category The category to create the resource in.
		 * @param binary Deterimes whether the resource should contain binary data.
		 *
		 * @return The resource if it was created, nullptr otherwise.
		 */
		SIMPLE_API Resource* create(const std::string& name, unsigned short category = Category::UNCATEGORIZED,
									bool binary = false);

		/**
		 * <p>
		 * Determines if a resource exists.
		 * </p>
		 *
		 * @param name The name of the resource.
		 * @param category The category to search in.
		 *
		 * @return True if the resource exists, false otherwise.
		 */
		SIMPLE_API bool exists(const std::string& name, unsigned short category = Category::UNCATEGORIZED);

		/**
		 * <p>
		 * Retrieves a resource.
		 * </p>
		 *
		 * @param name The name of the resource.
		 * @param category The category to retrieve from.
		 * @param binary Deterimes whether the resource contains binary data.
		 *
		 * @return The resource if it exists, nullptr otherwise.
		 */
		SIMPLE_API Resource* get(const std::string& name, unsigned short category = Category::UNCATEGORIZED,
								 bool binary = false);

		/**
		 * <p>
		 * Deletes a resource.
		 * </p>
		 *
		 * @param resource The resource to delete.
		 *
		 * @return True if the resource was deleted, false otherwise.
		 */
		SIMPLE_API bool remove(Resource* resource);

		/**
		 * <p>
		 * Sets the data store for a particular category. Setting the data store for the Categories::ALL_CATEGORIES
		 * category will set the default data store which will be used for categories that do not have a data store
		 * explicitly set for them.
		 * </p>
		 *
		 * @param dataStore The data store.
		 * @param category The category the data store will be used for.
		 */
		SIMPLE_API void setDataStore(std::unique_ptr<DataStore> dataStore, unsigned short category);
	}
}

#endif /* RESOURCES_H_ */
