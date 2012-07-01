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
#ifndef INPUTEVENT_H_
#define INPUTEVENT_H_

namespace simplicity
{
	struct InputEvent
	{
			enum ButtonState
			{
				DOWN,

				NO_BUTTON_STATE,

				UP
			};

			enum MouseButton
			{
				LEFT,

				MIDDLE,

				NO_MOUSE_BUTTON,

				RIGHT
			};

			enum Type
			{
				KEYBOARD_BUTTON,

				MOUSE_BUTTON,

				MOUSE_MOVE,

				NO_TYPE
			};

			InputEvent() :
				mouseButton(MouseButton::NO_MOUSE_BUTTON), buttonState(ButtonState::NO_BUTTON_STATE), type(
					Type::NO_TYPE), x(0), y(0)
			{
			}

			/**
			 * <p>
			 * The button that triggered the event (mouse events only).
			 * </p>
			 */
			MouseButton mouseButton;

			/**
			 * <p>
			 * The key that triggered the event (keyboard events only).
			 * </p>
			 */
			unsigned char key;

			/**
			 * <p>
			 * The new state of the button (mouse events only).
			 * </p>
			 */
			ButtonState buttonState;

			/**
			 * <p>
			 * The type of event that occurred.
			 * </p>
			 */
			Type type;

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

#endif /* INPUTEVENT_H_ */
