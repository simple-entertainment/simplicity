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
#ifndef WINDOWENGINE_H_
#define WINDOWENGINE_H_

#include "../engine/Engine.h"

namespace simplicity
{
	/**
	 * <p>
	 * An engine that provides the window in which the game will run.
	 * </p>
	 */
	class SIMPLE_API WindowEngine : public Engine
	{
		public:
			/**
			 * <p>
			 * Retrieves the height of the window.
			 * </p>
			 *
			 * @return The height of the window.
			 */
			virtual int getHeight() const = 0;

			/**
			 * <p>
			 * Retrieves the width of the window.
			 * </p>
			 *
			 * @return The width of the window.
			 */
			virtual int getWidth() const = 0;

			/**
			 * <p>
			 * Determines if the window is in fullscreen mode.
			 * </p>
			 *
			 * @return True if the window is in fullscreen mode, false otherwise.
			 */
			virtual bool isFullscreen() const = 0;

			/**
			 * <p>
			 * Sets the fullscreen mode of the window.
			 * </p>
			 *
			 * @param fullscreen Fullscreen?
			 */
			virtual void setFullscreen(bool fullscreen) = 0;

			/**
			 * <p>
			 * Sets the height of the window.
			 * </p>
			 *
			 * @param height The height of the window.
			 */
			virtual void setHeight(int height) = 0;

			/**
			 * <p>
			 * Sets the width of the window.
			 * </p>
			 *
			 * @param width The width of the window.
			 */
			virtual void setWidth(int width) = 0;
	};
}

#endif /* WINDOWENGINE_H_ */
