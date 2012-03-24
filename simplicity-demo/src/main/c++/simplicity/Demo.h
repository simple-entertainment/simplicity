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
#ifndef DEMO_H_
#define DEMO_H_

#include <string>

#include <simplicity/engine/Engine.h>

namespace simplicity
{
	/**
	 * <p>
	 * A small demonstration of a function.
	 * </p>
	 */
	class Demo
	{
		public:
			virtual ~Demo()
			{
			}

			/**
			 * <p>
			 * Restores the state of the demo environment for use by other demos.
			 * </p>
			 */
			virtual void dispose() = 0;

			/**
			 * <p>
			 * Retrieves a description of the demo.
			 * </p>
			 *
			 * @return A description of the demo.
			 */
			virtual std::string getDescription() = 0;

			/**
			 * <p>
			 * Retrieves the engine that runs the demo.
			 * </p>
			 *
			 * @return The engine that runs the demo.
			 */
			virtual std::shared_ptr<Engine> getEngine() = 0;

			/**
			 * <p>
			 * Retrieves the title of the demo.
			 * </p>
			 *
			 * @return The title of the demo.
			 */
			virtual std::string getTitle() = 0;

			/**
			 * <p>
			 * Initialises the state of the demo environment for use with this demo.
			 * </p>
			 */
			virtual void init() = 0;
	};
}

#endif /* DEMO_H_ */
