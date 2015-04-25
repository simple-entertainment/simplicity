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

#include "FileSystemResource.h"

using namespace std;

namespace simplicity
{
	FileSystemResource::FileSystemResource(unsigned short category, const string& name, const string& uri, bool binary) :
		binary(binary),
		category(category),
		name(name),
		uri(uri)
	{
	}

	void FileSystemResource::appendData(const char* data, unsigned int length)
	{
		unique_ptr<ostream> outputStream = getOutputStream();

		outputStream->write(data, length);
	}

	void FileSystemResource::appendData(const string& data)
	{
		appendData(data.data(), data.size());
	}

	unsigned short FileSystemResource::getCategory() const
	{
		return category;
	}

	string FileSystemResource::getData()
	{
		unique_ptr<istream> inputStream = getInputStream();

		istreambuf_iterator<char> begin(*inputStream);
		istreambuf_iterator<char> end;

		return string(begin, end);
	}

	unique_ptr<istream> FileSystemResource::getInputStream()
	{
		ios_base::openmode mode = ios_base::in;
		if (binary)
		{
			mode |= ios_base::binary;
		}

		return unique_ptr<istream>(new ifstream(uri, mode));
	}

	const string& FileSystemResource::getName() const
	{
		return name;
	}

	unique_ptr<ostream> FileSystemResource::getOutputStream(bool append)
	{
		ios_base::openmode mode = ios_base::out;
		if (append)
		{
			mode |= ios_base::app;
		}
		if (binary)
		{
			mode |= ios_base::binary;
		}

		return unique_ptr<ostream>(new ofstream(uri, mode));
	}

	const string& FileSystemResource::getUri() const
	{
		return uri;
	}

	bool FileSystemResource::isBinary() const
	{
		return binary;
	}

	void FileSystemResource::setData(const char* data, unsigned int length)
	{
		ios_base::openmode mode = ios_base::out | ios_base::trunc;
		if (binary)
		{
			mode |= ios_base::binary;
		}

		ofstream stream(uri, mode);

		stream.write(data, length);
	}

	void FileSystemResource::setData(const string& data)
	{
		setData(&data[0], data.size());
	}
}
