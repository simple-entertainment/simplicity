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
#include <simplicity/Events.h>
#include <simplicity/input/KeyboardButtonEvent.h>
#include <simplicity/Messages.h>
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
shared_ptr<CompositeEngine> engine(new SimpleCompositeEngine);

void nextDemo()
{
	if (demoIndex < demos.size() - 1)
	{
		engine->removeEngine(demos.at(demoIndex)->getEngine());
		demos.at(demoIndex)->dispose();

		demoIndex++;

		demos.at(demoIndex)->init();
		engine->addEngine(demos.at(demoIndex)->getEngine());
	}
}

void previousDemo()
{
	if (demoIndex > 0)
	{
		engine->removeEngine(demos.at(demoIndex)->getEngine());
		demos.at(demoIndex)->dispose();

		demoIndex--;

		demos.at(demoIndex)->init();
		engine->addEngine(demos.at(demoIndex)->getEngine());
	}
}

void changeDemo(const boost::any message)
{
	const KeyboardButtonEvent& event = boost::any_cast<KeyboardButtonEvent>(message);

	if (event.buttonState != Button::State::DOWN)
	{
		return;
	}

	if (event.button == Keyboard::Button::SPACE)
	{
		nextDemo();
	}
	else if (event.button == Keyboard::Button::BACKSPACE)
	{
		previousDemo();
	}
}

int main(int argc, char** argv)
{
	shared_ptr<Engine> freeglutEngine(new FreeglutEngine);
	freeglutEngine->setPreferredFrequency(100);
	engine->addEngine(freeglutEngine);

	Simplicity::setEngine(engine);

	Messages::registerRecipient(KEYBOARD_BUTTON_EVENT, changeDemo);

	unique_ptr<ModelFactory> modelFactory(new OpenGLModelFactory);
	ModelFactory::setInstance(move(modelFactory));

	unique_ptr<Demo> simplePathFinderDemo(new SimplePathFinderDemo);
	demos.push_back(move(simplePathFinderDemo));
	unique_ptr<Demo> bezierPathInterpreterDemo(new BezierPathInterpreterDemo);
	demos.push_back(move(bezierPathInterpreterDemo));

	demos.at(demoIndex)->init();
	engine->addEngine(demos.at(demoIndex)->getEngine());

	Simplicity::start();

	return 0;
}
