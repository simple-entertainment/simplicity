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
#ifndef FILESYSTEMRESOURCE_H_
#define FILESYSTEMRESOURCE_H_

#include <memory>

#include "Resource.h"

namespace simplicity
{
	class SIMPLE_API FileSystemResource : public Resource
	{
		public:
			FileSystemResource(unsigned short category, const std::string& name, const std::string& uri, bool binary);

			void appendData(const char* data, unsigned int length);

			void appendData(const std::string& data);

			unsigned short getCategory() const;

			std::string getData();

			std::unique_ptr<std::istream> getInputStream();

			const std::string& getName() const;

			std::unique_ptr<std::ostream> getOutputStream(bool append = true);

			const std::string& getUri() const;

			bool isBinary() const;

			void setData(const char* data, unsigned int length);

			void setData(const std::string& data);

		private:
			bool binary;

			unsigned short category;

			std::string name;

			std::string uri;
	};
}

#endif /* FILESYSTEMRESOURCE_H_ */
