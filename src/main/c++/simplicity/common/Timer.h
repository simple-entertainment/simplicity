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
#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>

#include "Defines.h"

namespace simplicity
{
	/**
	 * <p>
	 * A high precision timer.
	 * </p>
	 */
	class SIMPLE_API Timer
	{
		public:
			Timer();

			/**
			 * <p>
			 * Retrieves the time that has elapsed since the construction of this timer in seconds.
			 * </p>
			 *
			 * @return The time that has elapsed since the construction of this timer (in seconds).
			 */
			float getElapsedTime();

			bool isPaused();

			void pause();

			void reset();

			void resume();

		private:
			bool paused;

			float pauseDuration;

			std::chrono::time_point<std::chrono::high_resolution_clock> pauseTime;

			std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

			float getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> beginTime);
	};
}

#endif /* TIMER_H_ */
