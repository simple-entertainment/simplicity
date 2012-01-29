/*
 * Copyright © 2011 Simple Entertainment Limited
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
#include <simplicity/opengl/OpenGLDemoRunner.h>

#include "ai/pathfinding/SimplePathFinderDemo.h"
#include "ai/pathfinding/BezierPathInterpreterDemo.h"

using namespace simplicity;

int main(int argc, char** argv)
{
	OpenGLDemoRunner runner("Simplicity Demo");

	runner.addDemo(shared_ptr<Demo> (new SimplePathFinderDemo));
	runner.addDemo(shared_ptr<Demo> (new BezierPathInterpreterDemo));

	runner.init(argc, argv);
	runner.run();
	runner.dispose();

	return (0);
}
