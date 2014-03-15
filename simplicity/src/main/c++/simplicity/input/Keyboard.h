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
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <map>

namespace simplicity
{
	namespace Keyboard
	{
		/**
		 * <p>
		 * The buttons on a keyboard.
		 * </p>
		 */
		enum Button
		{
			ZERO,
			ONE,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
			SEVEN,
			EIGHT,
			NINE,

			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,

			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,

			APOSTROPHE,
			ARROW_DOWN,
			ARROW_LEFT,
			ARROW_RIGHT,
			ARROW_UP,
			ASTERISK,
			AT,
			BACKSLASH,
			BACKSPACE,
			COLON,
			COMMA,
			DELETE,
			END,
			ESCAPE,
			EQUALS,
			GRAVE,
			HOME,
			INSERT,
			LEFT_ALT,
			LEFT_BRACKET,
			LEFT_CTRL,
			LEFT_SHIFT,
			MINUS,
			PAGE_DOWN,
			PAGE_UP,
			PERIOD,
			RETURN,
			RIGHT_ALT,
			RIGHT_BRACKET,
			RIGHT_CTRL,
			RIGHT_SHIFT,
			SEMICOLON,
			SLASH,
			SPACE,
			TAB,
			UNDERLINE,

			UNKNOWN_BUTTON
		};
	}

	/**
	 * <p>
	 * Creates a map from ASCII characters to Keyboard::Button enum values.
	 * </p>
	 *
	 * @return A map from ASCII characters to Keyboard::Button enum values.
	 */
	std::map<unsigned char, Keyboard::Button> createAsciiKeyboardButtonMap();
}

#endif /* KEYBOARD_H_ */
