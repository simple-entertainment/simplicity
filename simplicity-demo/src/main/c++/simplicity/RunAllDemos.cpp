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
#include <simplicity/engine/SimpleCompositeEngine.h>
#include <simplicity/input/InputEvent.h>
#include <simplicity/SimpleEvents.h>
#include <simplicity/Simplicity.h>

#include <simplicity/opengl/model/OpenGLModelFactory.h>

#include <simplicity/freeglut/engine/FreeglutEngine.h>

#include "ai/pathfinding/SimplePathFinderDemo.h"
#include "ai/pathfinding/BezierPathInterpreterDemo.h"

using namespace simplicity;
using namespace simplicity::freeglut;
using namespace simplicity::opengl;
using namespace std;

unsigned int demoIndex = 0;
vector<unique_ptr<Demo> > demos;
unique_ptr<CompositeEngine> engine(new SimpleCompositeEngine);
// The unique pointer will be given to Simplicity.
CompositeEngine& engineRef = *engine;

void nextDemo()
{
	if (demoIndex < demos.size() - 1)
	{
		engineRef.removeEngine(demos.at(demoIndex)->getEngine());
		demos.at(demoIndex)->dispose();

		demoIndex++;

		demos.at(demoIndex)->init();
		engineRef.addEngine(demos.at(demoIndex)->getEngine());
	}
}

void previousDemo()
{
	if (demoIndex > 0)
	{
		engineRef.removeEngine(demos.at(demoIndex)->getEngine());
		demos.at(demoIndex)->dispose();

		demoIndex--;

		demos.at(demoIndex)->init();
		engineRef.addEngine(demos.at(demoIndex)->getEngine());
	}
}

void changeDemo(const boost::any data)
{
	const InputEvent& event = boost::any_cast<InputEvent>(data);

	if (event.key == ' ')
	{
		nextDemo();
	}
	else if (event.key == 8) // backspace
	{
		previousDemo();
	}
}

int main(int argc, char** argv)
{
	shared_ptr<Engine> freeglutEngine(new FreeglutEngine);
	freeglutEngine->setPreferredFrequency(100);
	engine->addEngine(freeglutEngine);

	Simplicity::init(move(engine));

	Simplicity::registerObserver(INPUT_EVENT, changeDemo);

	unique_ptr<ModelFactory> modelFactory(new OpenGLModelFactory);
	ModelFactory::setInstance(move(modelFactory));

	unique_ptr<Demo> simplePathFinderDemo(new SimplePathFinderDemo);
	demos.push_back(move(simplePathFinderDemo));
	unique_ptr<Demo> bezierPathInterpreterDemo(new BezierPathInterpreterDemo);
	demos.push_back(move(bezierPathInterpreterDemo));

	demos.at(demoIndex)->init();
	engineRef.addEngine(demos.at(demoIndex)->getEngine());

	Simplicity::start();

	return 0;
}
