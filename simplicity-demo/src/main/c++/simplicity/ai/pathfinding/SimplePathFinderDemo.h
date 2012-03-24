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
#ifndef SIMPLEPATHFINDERDEMO_H_
#define SIMPLEPATHFINDERDEMO_H_

#include <boost/any.hpp>

#include <simplicity/ai/pathfinding/SimplePathFinder.h>
#include <simplicity/rendering/engine/RenderingEngine.h>

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
			SimplePathFinderDemo();

			void dispose();

			std::string getDescription();

			std::shared_ptr<Engine> getEngine();

			std::string getTitle();

			void init();

		private:
			bool pathDisplayed;

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
			std::shared_ptr<simplicity::RenderingEngine> renderingEngine;

			/**
			 * <p>
			 * Responds to mouse events.
			 * </p>
			 */
			void onMouse(const boost::any data);
	};
}

#endif /* SIMPLEPATHFINDERDEMO_H_ */
