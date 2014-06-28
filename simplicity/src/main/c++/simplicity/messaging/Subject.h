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
#ifndef SUBJECT_H_
#define SUBJECT_H_

namespace simplicity
{
	namespace Subject
	{
		static const unsigned short CLIENT_CONNECTED = 0;

		/**
		 * <p>
		 * Raised when a keyboard button changes state.
		 * </p>
		 */
		static const unsigned short KEYBOARD_BUTTON = 1;

		/**
		 * <p>
		 * Raised when a mouse button changes state.
		 * </p>
		 */
		static const unsigned short MOUSE_BUTTON = 2;

		/**
		 * <p>
		 * Raised when a mouse is move.
		 * </p>
		 */
		static const unsigned short MOUSE_MOVE = 3;

		/**
		 * <p>
		 * User defined subjects should start with this ID.
		 * </p>
		 *
		 * <p>
		 * For example:
		 * </p>
		 *
		 * <pre><code>
		 * const unsigned short MY_SUBJECT_1 = USER_ID_0;
		 * const unsigned short MY_SUBJECT_2 = USER_ID_0 + 1;
		 * </code></pre>
		 */
		static const unsigned short USER_ID_0 = 128;
	}
}

#endif /* SUBJECT_H_ */
