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
#ifndef DATASTORE_H_
#define DATASTORE_H_

#include "../entity/Categories.h"
#include "Resource.h"

namespace simplicity
{
	/**
	 * <p>
	 * A data storage facility.
	 * </p>
	 */
	class SIMPLE_API DataStore
	{
		public:
			/**
			 * <p>
			 * Allows polymorphism.
			 * </p>
			 */
			virtual ~DataStore()
			{
			}

			/**
			 * <p>
			 * Creates a resource.
			 * </p>
			 *
			 * @param name The name of the resource.
			 * @param category The category to create the resource in.
			 * @param binary Is it a binary resource?
			 *
			 * @return The resource if it was created, NULL otherwise.
			 */
			virtual Resource* create(const std::string& name, unsigned short category, bool binary = false) = 0;

			/**
			 * <p>
			 * Determines if a resource exists.
			 * </p>
			 *
			 * @param name The name of the resource.
			 *
			 * @return True if the resource exists, false otherwise.
			 */
			virtual bool exists(const std::string& name) = 0;

			/**
			 * <p>
			 * Retrieves a resource.
			 * </p>
			 *
			 * @param name The name of the resource.
			 * @param category The category to retrieve from.
			 * @param binary Is it a binary resource?
			 *
			 * @return The resource if it exists, NULL otherwise.
			 */
			virtual Resource* get(const std::string& name, unsigned short category, bool binary = false) = 0;

			/**
			 * <p>
			 * Deletes a resource.
			 * </p>
			 *
			 * @param resource The resource to delete.
			 *
			 * @return True if the resource was deleted, false otherwise.
			 */
			virtual bool remove(Resource* resource) = 0;
	};
}

#endif /* DATASTORE_H_ */
