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
#include "ConsoleDataStore.h"
#include "ConsoleResource.h"

using namespace std;

namespace simplicity
{
	ConsoleDataStore::ConsoleDataStore() :
		resources()
	{
	}

	Resource* ConsoleDataStore::create(const string& /* name */, bool /* binary */)
	{
		return nullptr;
	}

	bool ConsoleDataStore::exists(const string& name)
	{
		return name == "err" || name == "in" || name == "out";
	}

	Resource* ConsoleDataStore::get(const string& name, bool /* binary */)
	{
		if (!exists(name))
		{
			return nullptr;
		}

		// If we do not have a resource for this console, create one.
		if (resources[name] == nullptr)
		{
			resources[name] = unique_ptr<Resource>(new ConsoleResource(name));
		}

		return resources[name].get();
	}

	bool ConsoleDataStore::remove(const Resource* /* resource */)
	{
		return false;
	}
}
