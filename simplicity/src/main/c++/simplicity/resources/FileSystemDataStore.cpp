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
#include <fstream>

#include "FileSystemDataStore.h"
#include "FileSystemResource.h"

using namespace std;

namespace simplicity
{
	FileSystemDataStore::FileSystemDataStore(const string& directory) :
		directory(directory),
		resources()
	{
	}

	Resource* FileSystemDataStore::create(const string& name, unsigned short category, bool binary)
	{
		// Attempt to create a file.
		if (ofstream(getUri(name)).fail())
		{
			return NULL;
		}

		// Maybe the file already existed after-all and we already have a resource for it...
		if (resources[name] == NULL)
		{
			resources[name] = unique_ptr<Resource>(new FileSystemResource(category, name, getUri(name), binary));
		}

		return resources[name].get();
	}

	bool FileSystemDataStore::exists(const string& name)
	{
		// Attempt to open an existing file.
		if (ifstream(getUri(name)).fail())
		{
			return false;
		}

		return true;
	}

	Resource* FileSystemDataStore::get(const string& name, unsigned short category, bool binary)
	{
		if (!exists(name))
		{
			return NULL;
		}

		// If we do not have a resource for this file, create one.
		if (resources[name] == NULL)
		{
			resources[name] = unique_ptr<Resource>(new FileSystemResource(category, name, getUri(name), binary));
		}

		return resources[name].get();
	}

	string FileSystemDataStore::getUri(const string& name)
	{
		// TODO Absolute path with protocol i.e. "file:///" + cwd + ...
		return directory + "/" + name;
	}

	bool FileSystemDataStore::remove(Resource* resource)
	{
		// Attempt to delete the file.
		if (std::remove(resource->getUri().c_str()))
		{
			resources[resource->getName()] = NULL;
			resource = NULL;

			return true;
		}

		return false;
	}
}
