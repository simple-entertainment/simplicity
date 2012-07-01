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
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <simplicity/input/InputEvent.h>
#include <simplicity/SimpleEvents.h>
#include <simplicity/Simplicity.h>

#include "FreeglutEngine.h"

namespace simplicity
{
	namespace freeglut
	{
		/**
		 * <p>
		 * A proxy for keyboard events that can be used as a Freeglut callback.
		 * </p>
		 */
		void keyboard(const unsigned char key, const int x, const int y)
		{
			InputEvent event;
			event.type = InputEvent::Type::KEYBOARD_BUTTON;
			event.key = key;
			event.x = x;
			event.y = y;

			Simplicity::fireEvent(INPUT_EVENT, event);
		}

		/**
		 * <p>
		 * A proxy for motion events that can be used as a Freeglut callback.
		 * </p>
		 */
		void motion(const int x, const int y)
		{
			InputEvent event;
			event.type = InputEvent::Type::MOUSE_MOVE;
			event.x = x;
			event.y = y;

			Simplicity::fireEvent(INPUT_EVENT, event);
		}

		/**
		 * <p>
		 * A proxy for mouse events that can be used as a Freeglut callback.
		 * </p>
		 */
		void mouse(const int button, const int state, const int x, const int y)
		{
			InputEvent event;

			if (button == GLUT_LEFT_BUTTON)
			{
				event.mouseButton = InputEvent::MouseButton::LEFT;
			}
			else if (GLUT_MIDDLE_BUTTON)
			{
				event.mouseButton = InputEvent::MouseButton::MIDDLE;
			}
			else if (GLUT_RIGHT_BUTTON)
			{
				event.mouseButton = InputEvent::MouseButton::RIGHT;
			}

			if (state == GLUT_DOWN)
			{
				event.buttonState = InputEvent::ButtonState::DOWN;
			}
			else
			{
				event.buttonState = InputEvent::ButtonState::UP;
			}

			event.type = InputEvent::Type::MOUSE_BUTTON;
			event.x = x;
			event.y = y;

			Simplicity::fireEvent(INPUT_EVENT, event);
		}

		FreeglutEngine::FreeglutEngine(string title) :
			title(title)
		{
		}

		void FreeglutEngine::addEntity(shared_ptr<Entity> entity)
		{
		}

		shared_ptr<EngineInput> FreeglutEngine::advance(const shared_ptr<EngineInput> input)
		{
			glutMainLoopEvent();
			glutSwapBuffers();

			return input;
		}

		void FreeglutEngine::destroy()
		{
		}

		void FreeglutEngine::onInit()
		{
			int argc = 1;
			unique_ptr<char> argv(new char);
			char* argvPtr(argv.get());

			glutInit(&argc, &argvPtr);
			glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
			glutInitWindowSize(800, 800);
			glutCreateWindow(title.data());

			glutKeyboardFunc(keyboard);
			glutMotionFunc(motion);
			glutMouseFunc(mouse);
		}

		void FreeglutEngine::onReset()
		{
		}
	}
}
