/*
 * Copyright © 2012 Simple Entertainment Limited
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
#ifndef BUTTON_H_
#define BUTTON_H_

namespace simplicity
{
	namespace Button
	{
		/**
		 * <p>
		 * The different states a physical button can be in.
		 * </p>
		 */
		enum class State
		{
			/**
			 * <p>
			 * The button is down (pressed).
			 * </p>
			 */
			DOWN,

			/**
			 * <p>
			 * The button is up (not pressed).
			 * </p>
			 */
			UP,

			/**
			 * <p>
			 * The state of the button is unknown.
			 * </p>
			 */
			UNKNOWN_STATE
		};
	}
}

#endif /* BUTTON_H_ */
