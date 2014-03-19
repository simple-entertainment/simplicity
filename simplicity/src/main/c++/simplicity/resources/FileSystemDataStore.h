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
#ifndef FILESYSTEMDATASTORE_H_
#define FILESYSTEMDATASTORE_H_

#include <map>
#include <memory>

#include "DataStore.h"

namespace simplicity
{
	class FileSystemDataStore : public DataStore
	{
		public:
			FileSystemDataStore(const std::string& directory);

			Resource* create(const std::string& name, unsigned short category, bool binary);

			bool exists(const std::string& name);

			Resource* get(const std::string& name, unsigned short category, bool binary);

			bool remove(Resource* resource);

		private:
			std::string directory;

			std::map<std::string, std::unique_ptr<Resource>> resources;

			std::string getUri(const std::string& name);
	};
}

#endif /* FILESYSTEMDATASTORE_H_ */
