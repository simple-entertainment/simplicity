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

#include "../input/KeyboardButtonEvent.h"
#include "../input/MouseMoveEvent.h"
#include "../math/MathFunctions.h"
#include "../messaging/Messages.h"
#include "../messaging/Subject.h"
#include "FlyingCameraEngine.h"

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

	void FlyingCameraEngine::advance()
	{
		if (buttonStates[Keyboard::Button::W] == Button::State::DOWN)
		{
			translate(camera.getTransform(), Vector4(0.0f, 0.0f, -0.1f, 1.0f));
		}

		if (buttonStates[Keyboard::Button::A] == Button::State::DOWN)
		{
			translate(camera.getTransform(), Vector4(-0.1f, 0.0f, 0.0f, 1.0f));
		}

		if (buttonStates[Keyboard::Button::S] == Button::State::DOWN)
		{
			translate(camera.getTransform(), Vector4(0.0f, 0.0f, 0.1f, 1.0f));
		}

		if (buttonStates[Keyboard::Button::D] == Button::State::DOWN)
		{
			translate(camera.getTransform(), Vector4(0.1f, 0.0f, 0.0f, 1.0f));
		}
	}

	bool FlyingCameraEngine::onKeyboardButton(const Message& message)
	{
		const KeyboardButtonEvent* event = static_cast<const KeyboardButtonEvent*>(message.body);
		buttonStates[event->button] = event->buttonState;

		return false;
	}

	bool FlyingCameraEngine::onMouseMove(const Message& message)
	{
		const MouseMoveEvent* event = static_cast<const MouseMoveEvent*>(message.body);

		if (x != -1)
		{
			int deltaX = event->x - x;
			int deltaY = event->y - y;
			rotate(camera.getTransform(), deltaX * -0.01f, Vector4(0.0f, 1.0f, 0.0f, 1.0f));
			rotate(camera.getTransform(), deltaY * -0.01f, Vector4(1.0f, 0.0f, 0.0f, 1.0f));
		}

		x = event->x;
		y = event->y;

		return false;
	}

	void FlyingCameraEngine::onPlay()
	{
		buttonStates[Keyboard::Button::W] = Button::State::UP;
		buttonStates[Keyboard::Button::A] = Button::State::UP;
		buttonStates[Keyboard::Button::S] = Button::State::UP;
		buttonStates[Keyboard::Button::D] = Button::State::UP;

		Messages::registerRecipient(Subject::KEYBOARD_BUTTON, bind(&FlyingCameraEngine::onKeyboardButton, this,
			placeholders::_1));
		Messages::registerRecipient(Subject::MOUSE_MOVE, bind(&FlyingCameraEngine::onMouseMove, this,
			placeholders::_1));
	}

	void FlyingCameraEngine::onStop()
	{
		Messages::deregisterRecipient(Subject::KEYBOARD_BUTTON, bind(&FlyingCameraEngine::onKeyboardButton, this,
			placeholders::_1));
		Messages::deregisterRecipient(Subject::MOUSE_MOVE, bind(&FlyingCameraEngine::onMouseMove, this,
			placeholders::_1));
	}
}
