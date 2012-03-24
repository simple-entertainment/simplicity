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
#ifndef FREEGLUTEVENT_H_
#define FREEGLUTEVENT_H_

namespace simplicity
{
	namespace freeglut
	{
		struct FreeglutInputEvent
		{
				/**
				 * <p>
				 * The button that triggered the event (mouse events only). A GLUT mouse button constant.
				 * </p>
				 */
				int button;

				/**
				 * <p>
				 * The key that was pressed (keyboard events only).
				 * </p>
				 */
				unsigned char key;

				/**
				 * <p>
				 * The new state of the button (mouse events only).
				 * </p>
				 */
				int state;

				/**
				 * <p>
				 * The location at which the event took place on the x axis (or the distance moved for motion events).
				 * </p>
				 */
				int x;

				/**
				 * <p>
				 * The location at which the event took place on the y axis (or the distance moved for motion events).
				 * </p>
				 */
				int y;
		};
	}
}

#endif /* FREEGLUTEVENT_H_ */
