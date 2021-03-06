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
#include <iostream>

#include "ConsoleResource.h"

using namespace std;

namespace simplicity
{
	ConsoleResource::ConsoleResource(const string& name) :
		name(name)
	{
	}

	void ConsoleResource::appendData(const char* data, unsigned int length)
	{
		if (name == "err")
		{
			cerr.write(data, length);
		}
		else if (name == "out")
		{
			cout.write(data, length);
		}
	}

	void ConsoleResource::appendData(const string& data)
	{
		appendData(data.data(), data.size());
	}

	string ConsoleResource::getAbsolutePath() const
	{
		return name;
	}

	string ConsoleResource::getData() const
	{
		string data;

		if (name == "in")
		{
			int begin = static_cast<int>(cin.tellg());
			cin.seekg(0, ios_base::end);
			int end = static_cast<int>(cin.tellg());
			cin.seekg(-begin, ios_base::end);

			data.resize(end - begin);
			cin.read(&data[0], end - begin);
		}

		return data;
	}

	unique_ptr<istream> ConsoleResource::getInputStream() const
	{
		return unique_ptr<istream>();
	}

	const string& ConsoleResource::getName() const
	{
		return name;
	}

	unique_ptr<ostream> ConsoleResource::getOutputStream(bool /* append */)
	{
		return unique_ptr<ostream>();
	}

	Resource::Type ConsoleResource::getType() const
	{
		return Type::CONSOLE;
	}

	string ConsoleResource::getUri() const
	{
		return name;
	}

	bool ConsoleResource::isBinary() const
	{
		return false;
	}

	void ConsoleResource::setData(const char* data, unsigned int length)
	{
		if (name == "err")
		{
			cerr << "\x1B[2J\x1B[H";
			cerr.write(data, length);
		}
		else if (name == "out")
		{
			cout << "\x1B[2J\x1B[H";
			cout.write(data, length);
		}
	}

	void ConsoleResource::setData(const string& data)
	{
		setData(&data[0], data.size());
	}
}
