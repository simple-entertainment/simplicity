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
			FileSystemResource(Type type, const std::string& name, const std::string& absolutePath, bool binary);

			void appendData(const char* data, unsigned int length) override;

			void appendData(const std::string& data) override;

			std::string getAbsolutePath() const override;

			std::string getData() const override;

			std::unique_ptr<std::istream> getInputStream() const override;

			const std::string& getName() const override;

			std::unique_ptr<std::ostream> getOutputStream(bool append = true) override;

			Type getType() const override;

			std::string getUri() const override;

			bool isBinary() const override;

			void setData(const char* data, unsigned int length) override;

			void setData(const std::string& data) override;

		private:
			std::string absolutePath;

			bool binary;

			std::string name;

			Type type;
	};
}

#endif /* FILESYSTEMRESOURCE_H_ */
