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

#include "../common/Category.h"
#include "ConsoleDataStore.h"
#include "FileSystemDataStore.h"
#include "Resources.h"

using namespace std;

namespace simplicity
{
	namespace Resources
	{
		DataStore* getDataStore(Resource::Type type);

		map<Resource::Type, unique_ptr<DataStore>> dataStores;

		Resource* create(const string& name, bool binary)
		{
			return getDataStore(Resource::Type::USER)->create(name, binary);
		}

		bool exists(const string& name, Resource::Type type)
		{
			return getDataStore(type)->exists(name);
		}

		Resource* get(const string& name, Resource::Type type, bool binary)
		{
			return getDataStore(type)->get(name, binary);
		}

		DataStore* getDataStore(Resource::Type type)
		{
			DataStore* dataStore = dataStores[type].get();

			if (dataStore == nullptr)
			{
				// Provide the default data store.
				if (type == Resource::Type::ASSET)
				{
					unique_ptr<DataStore> assetDataStore(new FileSystemDataStore(type, "assets"));
					dataStores[type] = move(assetDataStore);
				}
				else if (type == Resource::Type::CONSOLE)
				{
					unique_ptr<DataStore> consoleDataStore(new ConsoleDataStore);
					dataStores[type] = move(consoleDataStore);
				}
				else if (type == Resource::Type::USER)
				{
					unique_ptr<DataStore> userDataStore(new FileSystemDataStore(type, "~/simplicity-user"));
					dataStores[type] = move(userDataStore);
				}

				dataStore = dataStores[type].get();
			}

			return dataStore;
		}

		bool remove(const Resource* resource)
		{
			return getDataStore(resource->getType())->remove(resource);
		}

		void setDataStore(unique_ptr<DataStore> dataStore, Resource::Type type)
		{
			dataStores[type] = move(dataStore);
		}
	}
}
