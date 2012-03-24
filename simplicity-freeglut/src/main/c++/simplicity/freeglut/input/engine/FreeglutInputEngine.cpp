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

#include <simplicity/Simplicity.h>

#include "../../FreeglutEvents.h"
#include "../FreeglutInputEvent.h"
#include "FreeglutInputEngine.h"

using namespace simplicity;
using namespace std;

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
			FreeglutInputEvent event;
			event.key = key;
			event.x = x;
			event.y = y;

			Simplicity::fireEvent(FREEGLUT_KEYBOARD_EVENT, event);
		}

		/**
		 * <p>
		 * A proxy for motion events that can be used as a Freeglut callback.
		 * </p>
		 */
		void motion(const int x, const int y)
		{
			FreeglutInputEvent event;
			event.x = x;
			event.y = y;

			Simplicity::fireEvent(FREEGLUT_MOTION_EVENT, event);
		}

		/**
		 * <p>
		 * A proxy for mouse events that can be used as a Freeglut callback.
		 * </p>
		 */
		void mouse(const int button, const int state, const int x, const int y)
		{
			FreeglutInputEvent event;
			event.button = button;
			event.state = state;
			event.x = x;
			event.y = y;

			Simplicity::fireEvent(FREEGLUT_MOUSE_EVENT, event);
		}

		void FreeglutInputEngine::addEntity(shared_ptr<Entity> entity)
		{
		}

		shared_ptr<EngineInput> FreeglutInputEngine::advance(const shared_ptr<EngineInput> input)
		{
			glutMainLoopEvent();

			return input;
		}

		void FreeglutInputEngine::destroy()
		{
		}

		void FreeglutInputEngine::onInit()
		{
			glutKeyboardFunc(keyboard);
			glutMotionFunc(motion);
			glutMouseFunc(mouse);
		}

		void FreeglutInputEngine::onReset()
		{
		}
	}
}
