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
		DataStore* getDataStore(unsigned short category);

		map<unsigned short, unique_ptr<DataStore>> dataStores;
		unique_ptr<DataStore> defaultDataStore = nullptr;

		Resource* create(const string& name, unsigned short category, bool binary)
		{
			return getDataStore(category)->create(name, category, binary);
		}

		bool exists(const string& name, unsigned short category)
		{
			return getDataStore(category)->exists(name);
		}

		Resource* get(const string& name, unsigned short category, bool binary)
		{
			return getDataStore(category)->get(name, category, binary);
		}

		DataStore* getDataStore(unsigned short category)
		{
			DataStore* dataStore = dataStores[category].get();

			if (dataStore == nullptr)
			{
				// Provide the default datastores.
				if (defaultDataStore == nullptr)
				{
					unique_ptr<DataStore> defaultDataStore(new FileSystemDataStore("."));
					setDataStore(move(defaultDataStore), Category::ALL_CATEGORIES);

					if (dataStores[Category::CONSOLE] == nullptr)
					{
						unique_ptr<DataStore> consoleDataStore(new ConsoleDataStore);
						setDataStore(move(consoleDataStore), Category::CONSOLE);
					}

					if (category == Category::CONSOLE)
					{
						return dataStores[category].get();
					}
				}

				dataStore = defaultDataStore.get();
			}

			return dataStore;
		}

		bool remove(Resource* resource)
		{
			return getDataStore(resource->getCategory())->remove(resource);
		}

		void setDataStore(unique_ptr<DataStore> dataStore, unsigned short category)
		{
			if (category == Category::ALL_CATEGORIES)
			{
				defaultDataStore = move(dataStore);
			}
			else
			{
				dataStores[category] = move(dataStore);
			}
		}
	}
}