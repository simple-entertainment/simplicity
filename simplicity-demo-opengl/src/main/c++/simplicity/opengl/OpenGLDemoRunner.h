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
#ifndef OPENGLDEMORUNNER_H_
#define OPENGLDEMORUNNER_H_

#include <string>
#include <vector>

#include <simplicity/DemoRunner.h>

namespace simplicity
{
	/**
	 * <p>
	 * Provides an OpenGL environment in which {@link simplicity::Demo Demo}s can be run.
	 * </p>
	 */
	class OpenGLDemoRunner
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>OpenGLDemoRunner</code>.
			 * </p>
			 */
			OpenGLDemoRunner(std::string title);

			/**
			 * <p>
			 * Disposes of an instance of <code>OpenGLDemoRunner</code>.
			 * </p>
			 */
			virtual ~OpenGLDemoRunner();

			void addDemo(std::shared_ptr<Demo> demo);

			void dispose();

			void init(int argc, char** argv);

			/**
			 * <p>
			 * Processes keyboard events.
			 * </p>
			 *
			 * @param key The key that was pressed.
			 * @param x ?
			 * @param y ?
			 */
			void keyboard(const unsigned char key, const int x, const int y);

			/**
			 * <p>
			 * Processes mouse button events.
			 * </p>
			 *
			 * @param button The GLUT mouse button that was used.
			 * @param state The new state of the mouse button.
			 * @param x The position on the x axis where the mouse was used.
			 * @param y The position on the y axis where the mouse was used.
			 */
			void onMouseButton(const int button, const int state, const int x, const int y);

			/**
			 * <p>
			 * Processes mouse motion events.
			 * </p>
			 *
			 * @param x The distance the mouse was moved on the x axis.
			 * @param y The distance the mouse was moved on the y axis.
			 */
			void onMouseMotion(const int x, const int y);

			/**
			 * <p>
			 * The render method called during each iteration of the main loop.
			 * </p>
			 */
			void render();

			void run();

		private:
			/**
			 * <p>
			 * The index of the currently running {@link simplicity::Demo Demo}.
			 * </p>
			 */
			int demoIndex;

			/**
			 * <p>
			 * The list of {@link simplicity::Demo Demo}s to be run.
			 * </p>
			 */
			std::vector<std::shared_ptr<Demo> > demos;

			/**
			 * <p>
			 * The title to display on the program window.
			 * </p>
			 */
			std::string title;

			/**
			 * <p>
			 * The position on the z axis at which text is rendered.
			 * </p>
			 */
			float textZ;

			/**
			 * <p>
			 * Moves to the next {@link simplicity::Demo Demo}.
			 * </p>
			 */
			void nextDemo();

			/**
			 * <p>
			 * Moves to the previous {@link simplicity::Demo Demo}.
			 * </p>
			 */
			void previousDemo();

			/**
			 * <p>
			 * Renders text.
			 * </p>
			 *
			 * @param font The GLUT font to render the text in.
			 * @param text The test to render.
			 * @param x The position on the x axis to render the text (relative to the center of the camera frame).
			 * @param y The position on the y axis to render the text (relative to the center of the camera frame).
			 */
			void text(void* font, const std::string text, const float x, const float y);
	};
}

#endif /* OPENGLDEMORUNNER_H_ */
