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
#ifndef DEFINES_H_
#define DEFINES_H_

// Platforms
#if defined(_WIN32)
#	define SIMPLE_WINDOWS
#elif defined(__linux__)
#	define SIMPLE_LINUX
#endif

// Export/Import
#if defined(SIMPLE_WINDOWS) && defined(SIMPLE_SHARED)
#	define SIMPLE_API __declspec(dllexport)
#	define SIMPLE_API_TEMPLATE
#elif defined(SIMPLE_WINDOWS) && defined(SIMPLE_SHARED_EXE)
#	define SIMPLE_API __declspec(dllimport)
#	define SIMPLE_API_TEMPLATE extern
#else
#	define SIMPLE_API 
#endif

// Debug Breaking
#ifdef SIMPLE_WINDOWS
#   define DEBUG_BREAK __debugbreak()
#else
#   include <signal.h>
#   define DEBUG_BREAK raise(SIGTRAP)
#endif

namespace simplicity
{
	using byte = char;
}

namespace sim = simplicity;

#endif /* DEFINES_H_ */
