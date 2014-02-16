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
#include "Timer.h"

using namespace std::chrono;

namespace simplicity
{
	Timer::Timer() :
		startTime(high_resolution_clock::now())
	{
	}

	float Timer::getElapsedTime()
	{
		time_point<high_resolution_clock> now = high_resolution_clock::now();

		return duration_cast<nanoseconds>(now - startTime).count() / 1000000000.0f;
	}
}
