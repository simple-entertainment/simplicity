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

#include "FreeglutWindowEngine.h"

namespace simplicity
{
	namespace freeglut
	{
		void FreeglutWindowEngine::addEntity(shared_ptr<Entity> entity)
		{
		}

		shared_ptr<EngineInput> FreeglutWindowEngine::advance(const shared_ptr<EngineInput> input)
		{
			glutSwapBuffers();

			return input;
		}

		void FreeglutWindowEngine::destroy()
		{
		}

		void FreeglutWindowEngine::onInit()
		{
			int argc = 1;
			unique_ptr<char> argv(new char);
			char* argvPtr(argv.get());

			glutInit(&argc, &argvPtr);
			glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
			glutInitWindowSize(800, 800);
			glutCreateWindow("Cyclops Renegade");

			glutMainLoopEvent();
		}

		void FreeglutWindowEngine::onReset()
		{
		}
	}
}
