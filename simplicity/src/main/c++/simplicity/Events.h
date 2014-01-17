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
#ifndef EVENTS_H_
#define EVENTS_H_

namespace simplicity
{
	namespace Events
	{
		const unsigned short ADD_ENTITY = 0;

		const unsigned short KEYBOARD_BUTTON = 1;

		const unsigned short MOUSE_BUTTON = 2;

		const unsigned short MOUSE_MOVE = 3;

		const unsigned short PICK = 4;

		const unsigned short QUIT = 5;

		const unsigned short REMOVE_ENTITY = 6;

		const unsigned short USER_ID_0 = 128;
	}
}

#endif /* EVENTS_H_ */
