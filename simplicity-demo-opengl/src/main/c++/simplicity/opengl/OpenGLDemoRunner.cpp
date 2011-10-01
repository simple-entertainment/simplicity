/*
 * Copyright © Simple Entertainment Limited 2011
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
#include <GL/glut.h>

#include <boost/function.hpp>
#include <boost/math/constants/constants.hpp>

#include <simplicity/vector/SimpleTranslationVector4.h>

#include "OpenGLDemoRunner.h"

using namespace std;
using namespace boost::math::constants;

namespace simplicity
{
	/**
	 * <p>
	 * The {@link simplicity::OpenGLDemoRunner OpenGLDemoRunner} that will respond to the GLUT events.
	 * </p>
	 */
	OpenGLDemoRunner* runner;

	/**
	 * <p>
	 * A proxy for keyboard events that can be used as a GLUT callback.
	 * </p>
	 *
	 * @param key The key that was pressed.
	 * @param x ?
	 * @param y ?
	 */
	void keyboard(const unsigned char key, const int x, const int y)
	{
		runner->keyboard(key, x, y);
	}

	/**
	 * <p>
	 * A proxy for motion events that can be used as a GLUT callback.
	 * </p>
	 *
	 * @param x The distance the mouse was moved on the x axis.
	 * @param y The distance the mouse was moved on the y axis.
	 */
	void onMouseMotion(const int x, const int y)
	{
		runner->onMouseMotion(x, y);
	}

	/**
	 * <p>
	 * A proxy for mouse events that can be used as a GLUT callback.
	 * </p>
	 *
	 * @param button The GLUT mouse button that was used.
	 * @param state The new state of the mouse button.
	 * @param x The position on the x axis where the mouse was used.
	 * @param y The position on the y axis where the mouse was used.
	 */
	void onMouseButton(const int button, const int state, const int x, const int y)
	{
		runner->onMouseButton(button, state, x, y);
	}

	/**
	 * <p>
	 * A proxy for render events that can be used as a GLUT callback.
	 * </p>
	 */
	void render()
	{
		runner->render();
	}

	/**
	 * <p>
	 * Initialises the standalone proxy methods for use with GLUT.
	 * </p>
	 *
	 * @param runner The {@link simplicity::OpenGLDemoRunner OpenGLDemoRunner} that will respond to the GLUT events.
	 */
	void initStandalone(OpenGLDemoRunner* runner)
	{
		simplicity::runner = runner;

		glutDisplayFunc(render);
		glutIdleFunc(render);
		glutKeyboardFunc(keyboard);
		glutMouseFunc(onMouseButton);
		glutMotionFunc(onMouseMotion);
	}

	OpenGLDemoRunner::OpenGLDemoRunner(string title) :
		demoIndex(-1), title(title)
	{
	}

	OpenGLDemoRunner::~OpenGLDemoRunner()
	{
	}

	void OpenGLDemoRunner::addDemo(boost::shared_ptr<Demo> demo)
	{
		demos.push_back(demo);
	}

	void OpenGLDemoRunner::dispose()
	{
		demos.at(demoIndex)->dispose();
	}

	void OpenGLDemoRunner::init(int argc, char **argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
		glutInitWindowSize(800, 600);
		glutCreateWindow("Where's my title???");

		initStandalone(this);

		nextDemo();
	}

	void OpenGLDemoRunner::keyboard(const unsigned char key, const int x, const int y)
	{
		if (key == ' ')
		{
			nextDemo();
		}
		else if (key == 8) // backspace
		{
			previousDemo();
		}
	}

	void OpenGLDemoRunner::onMouseButton(const int button, const int state, const int x, const int y)
	{
		demos.at(demoIndex)->onMouseButton(button, state, x, y);
	}

	void OpenGLDemoRunner::onMouseMotion(const int x, const int y)
	{
		demos.at(demoIndex)->onMouseMotion(x, y);
	}

	void OpenGLDemoRunner::nextDemo()
	{
		int signedDemoCount = demos.size();
		if (demoIndex < signedDemoCount - 1)
		{
			if (demoIndex >= 0)
			{
				demos.at(demoIndex)->dispose();
			}

			demoIndex++;
			demos.at(demoIndex)->init();
		}
	}

	void OpenGLDemoRunner::previousDemo()
	{
		if (demoIndex > 0)
		{
			demos.at(demoIndex)->dispose();

			demoIndex--;
			demos.at(demoIndex)->init();
		}
	}

	void OpenGLDemoRunner::render()
	{
		demos.at(demoIndex)->advance();

		shared_ptr<Camera> camera = demos.at(demoIndex)->getCamera();
		float frameWidth = camera->getFrameWidth();
		float frameHeight = camera->getFrameHeight();

		if (camera->getProjectionMode() == Camera::PERSPECTIVE)
		{
			frameWidth *= 10.0f;
			frameHeight *= 10.0f;
		}

		text(GLUT_BITMAP_HELVETICA_18, demos.at(demoIndex)->getTitle(), frameWidth * -0.49f, frameHeight * 0.45f);
		text(GLUT_BITMAP_HELVETICA_12, demos.at(demoIndex)->getDescription(), frameWidth * -0.49f, frameHeight * 0.4f);
		text(GLUT_BITMAP_HELVETICA_18, "<< Previous [backspace]", frameWidth * -0.49f, frameHeight * -0.45f);
		text(GLUT_BITMAP_HELVETICA_18, "[space] Next >>", frameWidth * 0.33f, frameHeight * -0.45f);

		glutSwapBuffers();
	}

	void OpenGLDemoRunner::run()
	{
		glutMainLoop();
	}

	void OpenGLDemoRunner::text(void* font, const string text, const float x, const float y)
	{
		float currentY = y;

		glDisable(GL_LIGHTING);
		glColor3f(0.05f, 0.05f, 0.05f);
		glRasterPos3f(x, currentY, -1.0f);
		for (unsigned int index = 0; index < text.length(); index++)
		{
			if (text.at(index) == '\n')
			{
				currentY -= 0.025f;
				glRasterPos3f(x, currentY, -1.0f);
			}
			else
			{
				glutBitmapCharacter(font, text.at(index));
			}
		}
		glEnable(GL_LIGHTING);
	}
}
