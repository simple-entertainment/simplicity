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
#include "Keyboard.h"

using namespace std;

namespace simplicity
{
	map<unsigned char, Keyboard::Button> createAsciiButtonMap()
	{
		map<unsigned char, Keyboard::Button> asciiButtonMap;

		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('0', Keyboard::Button::ZERO));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('1', Keyboard::Button::ONE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('2', Keyboard::Button::TWO));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('3', Keyboard::Button::THREE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('4', Keyboard::Button::FOUR));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('5', Keyboard::Button::FIVE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('6', Keyboard::Button::SIX));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('7', Keyboard::Button::SEVEN));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('8', Keyboard::Button::EIGHT));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('9', Keyboard::Button::NINE));

		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('a', Keyboard::Button::A));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('A', Keyboard::Button::A));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('b', Keyboard::Button::B));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('B', Keyboard::Button::B));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('c', Keyboard::Button::C));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('C', Keyboard::Button::C));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('d', Keyboard::Button::D));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('D', Keyboard::Button::D));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('e', Keyboard::Button::E));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('E', Keyboard::Button::E));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('f', Keyboard::Button::F));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('F', Keyboard::Button::F));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('g', Keyboard::Button::G));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('G', Keyboard::Button::G));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('h', Keyboard::Button::H));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('H', Keyboard::Button::H));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('i', Keyboard::Button::I));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('I', Keyboard::Button::I));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('j', Keyboard::Button::J));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('J', Keyboard::Button::J));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('k', Keyboard::Button::K));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('K', Keyboard::Button::K));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('l', Keyboard::Button::L));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('L', Keyboard::Button::L));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('m', Keyboard::Button::M));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('M', Keyboard::Button::M));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('n', Keyboard::Button::N));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('N', Keyboard::Button::N));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('o', Keyboard::Button::O));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('O', Keyboard::Button::O));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('p', Keyboard::Button::P));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('P', Keyboard::Button::P));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('q', Keyboard::Button::Q));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('Q', Keyboard::Button::Q));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('r', Keyboard::Button::R));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('R', Keyboard::Button::R));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('s', Keyboard::Button::S));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('S', Keyboard::Button::S));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('t', Keyboard::Button::T));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('T', Keyboard::Button::T));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('u', Keyboard::Button::U));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('U', Keyboard::Button::U));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('v', Keyboard::Button::V));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('V', Keyboard::Button::V));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('w', Keyboard::Button::W));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('W', Keyboard::Button::W));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('x', Keyboard::Button::X));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('X', Keyboard::Button::X));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('y', Keyboard::Button::Y));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('Y', Keyboard::Button::Y));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('z', Keyboard::Button::Z));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('Z', Keyboard::Button::Z));

		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('\'', Keyboard::Button::APOSTROPHE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('*', Keyboard::Button::ASTERISK));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('@', Keyboard::Button::AT));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('\\', Keyboard::Button::BACKSLASH));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('\b', Keyboard::Button::BACKSPACE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>(':', Keyboard::Button::COLON));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>(',', Keyboard::Button::COMMA));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>(127, Keyboard::Button::DELETE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('\e', Keyboard::Button::ESCAPE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('=', Keyboard::Button::EQUALS));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('`', Keyboard::Button::GRAVE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('(', Keyboard::Button::LEFT_BRACKET));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('-', Keyboard::Button::MINUS));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('.', Keyboard::Button::PERIOD));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('\r', Keyboard::Button::RETURN));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>(')', Keyboard::Button::RIGHT_BRACKET));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>(';', Keyboard::Button::SEMICOLON));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('/', Keyboard::Button::SLASH));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>(' ', Keyboard::Button::SPACE));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('\t', Keyboard::Button::TAB));
		asciiButtonMap.insert(pair<unsigned char, Keyboard::Button>('_', Keyboard::Button::UNDERLINE));

		return asciiButtonMap;
	}
}
