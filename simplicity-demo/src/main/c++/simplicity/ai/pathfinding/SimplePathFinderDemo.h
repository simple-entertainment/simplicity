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
#ifndef SIMPLEPATHFINDERDEMO_H_
#define SIMPLEPATHFINDERDEMO_H_

#include <simplicity/ai/pathfinding/SimplePathFinder.h>

#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>

#include "PathFindingDemo.h"

namespace simplicity
{
	/**
	 * <p>
	 * A small demonstration of the {@link simplicity::SimplePathFinder SimplePathFinder}.
	 * </p>
	 *
	 * @author Gary Buyn
	 */
	class SimplePathFinderDemo : public PathFindingDemo
	{
		public:
			/**
			 * <p>
			 * Creates an instance of <code>SimplePathFinderDemo</code>.
			 * </p>
			 */
			SimplePathFinderDemo();

			/**
			 * <p>
			 * Disposes of an instance of <code>SimplePathFinderDemo</code>.
			 * </p>
			 */
			virtual ~SimplePathFinderDemo();

			void advance();

			void dispose();

			std::shared_ptr<Camera> getCamera();

			std::string getDescription();

			std::string getTitle();

			void init();

			void onMouseButton(const int button, const int state, const int x, const int y);

			void onMouseMotion(const int x, const int y);

		private:
			/**
			 * <p>
			 * The path finder for the demo.
			 * </p>
			 */
			std::shared_ptr<PathFinder> pathFinder;

			/**
			 * <p>
			 * The rendering engine for the demo.
			 * </p>
			 */
			simplicity::opengl::SimpleOpenGLRenderingEngine renderingEngine;
	};
}

#endif /* SIMPLEPATHFINDERDEMO_H_ */
