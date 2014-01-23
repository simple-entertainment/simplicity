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
#include <functional>

#include "../Events.h"
#include "../input/KeyboardButtonEvent.h"
#include "../input/MouseMoveEvent.h"
#include "../math/MathFunctions.h"
#include "../Messages.h"
#include "FlyingCameraEngine.h"

using namespace boost;
using namespace std;

namespace simplicity
{
	FlyingCameraEngine::FlyingCameraEngine(Entity& camera) :
		buttonStates(),
		camera(camera),
		x(-1),
		y(-1)
	{
	}

	void FlyingCameraEngine::addEntity(Entity&)
	{
	}

	void FlyingCameraEngine::advance()
	{
		if (buttonStates[Keyboard::Button::W] == Button::State::DOWN)
		{
			MathFunctions::translate(camera.getTransformation(), Vector4(0.0f, 0.0f, -0.1f, 1.0f));
		}

		if (buttonStates[Keyboard::Button::A] == Button::State::DOWN)
		{
			MathFunctions::translate(camera.getTransformation(), Vector4(-0.1f, 0.0f, 0.0f, 1.0f));
		}

		if (buttonStates[Keyboard::Button::S] == Button::State::DOWN)
		{
			MathFunctions::translate(camera.getTransformation(), Vector4(0.0f, 0.0f, 0.1f, 1.0f));
		}

		if (buttonStates[Keyboard::Button::D] == Button::State::DOWN)
		{
			MathFunctions::translate(camera.getTransformation(), Vector4(0.1f, 0.0f, 0.0f, 1.0f));
		}
	}

	void FlyingCameraEngine::destroy()
	{
		Messages::deregisterRecipient(Events::KEYBOARD_BUTTON, bind(&FlyingCameraEngine::onKeyboardButton, this,
				placeholders::_1));
		Messages::deregisterRecipient(Events::MOUSE_MOVE, bind(&FlyingCameraEngine::onMouseMove, this,
				placeholders::_1));
	}

	void FlyingCameraEngine::init()
	{
		buttonStates[Keyboard::Button::W] = Button::State::UP;
		buttonStates[Keyboard::Button::A] = Button::State::UP;
		buttonStates[Keyboard::Button::S] = Button::State::UP;
		buttonStates[Keyboard::Button::D] = Button::State::UP;

		Messages::registerRecipient(Events::KEYBOARD_BUTTON, bind(&FlyingCameraEngine::onKeyboardButton, this,
				placeholders::_1));
		Messages::registerRecipient(Events::MOUSE_MOVE, bind(&FlyingCameraEngine::onMouseMove, this,
				placeholders::_1));


	}

	void FlyingCameraEngine::onKeyboardButton(any message)
	{
		KeyboardButtonEvent* event = any_cast<KeyboardButtonEvent*>(message);
		buttonStates[event->button] = event->buttonState;
	}

	void FlyingCameraEngine::onMouseMove(any message)
	{
		MouseMoveEvent* event = any_cast<MouseMoveEvent*>(message);

		if (x != -1)
		{
			int deltaX = event->x - x;
			int deltaY = event->y - y;
			MathFunctions::rotate(camera.getTransformation(), deltaX * -0.01f, Vector4(0.0f, 1.0f, 0.0f, 1.0f));
			MathFunctions::rotate(camera.getTransformation(), deltaY * -0.01f, Vector4(1.0f, 0.0f, 0.0f, 1.0f));
		}

		x = event->x;
		y = event->y;
	}

	void FlyingCameraEngine::removeEntity(const Entity&)
	{
	}
}
