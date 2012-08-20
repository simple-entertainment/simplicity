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
#include <GL/glut.h>

#include <simplicity/Events.h>
#include <simplicity/graph/NodeFactory.h>
#include <simplicity/input/MouseButtonEvent.h>
#include <simplicity/Messages.h>

#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include "SimplePathFinderDemo.h"

using namespace simplicity::opengl;
using namespace std;

namespace simplicity
{
	SimplePathFinderDemo::SimplePathFinderDemo() :
		pathDisplayed(false), pathFinder(), renderingEngine()
	{
	}

	void SimplePathFinderDemo::dispose()
	{
		renderingEngine->destroy();
		removeAllEntities();

		Messages::deregisterRecipient(MOUSE_BUTTON_EVENT, bind(&SimplePathFinderDemo::onMouse, this, placeholders::_1));
	}

	string SimplePathFinderDemo::getDescription() const
	{
		return "Click the mouse to advance the simple pathfinding algorithm.\n"
			"When a path is found, it will be displayed as green dots.";
	}

	shared_ptr<Engine> SimplePathFinderDemo::getEngine() const
	{
		return renderingEngine;
	}

	string SimplePathFinderDemo::getTitle() const
	{
		return "SimplePathFinderDemo";
	}

	void SimplePathFinderDemo::init()
	{
		pathDisplayed = false;
		renderingEngine.reset(new SimpleOpenGLRenderingEngine);

		renderingEngine->setPreferredFrequency(100);
		renderingEngine->setViewportWidth(800);
		renderingEngine->setViewportHeight(800);

		initScene();

		shared_ptr<Camera> camera = addCamera();
		renderingEngine->setCamera(camera);

		addLight();
		addBackground();

		addTitle();
		addDescription();

		createNavigationMesh();
		vector<pair<unsigned int, unsigned int> > obstacleLocations = getRandomObstacleLocations();
		removeLocationsFromNavigationMesh(obstacleLocations);
		addObstacles(obstacleLocations);

		shared_ptr<Renderer> renderer(new SimpleOpenGLRenderer);
		renderingEngine->addRenderer(renderer);
		renderingEngine->init();

		pathFinder.reset(new SimplePathFinder(getNavigationMesh().get(4), getNavigationMesh().get(95)));

		Messages::registerRecipient(MOUSE_BUTTON_EVENT, bind(&SimplePathFinderDemo::onMouse, this, placeholders::_1));
	}

	void SimplePathFinderDemo::onMouse(const boost::any message)
	{
		const MouseButtonEvent& event = boost::any_cast<MouseButtonEvent>(message);

		if (event.button != Mouse::Button::LEFT || event.buttonState != Button::State::UP)
		{
			return;
		}

		bool pathFound = pathFinder->stepForward();

		displayOpenNodes(pathFinder->getOpenNodes());

		if (pathFound && !pathDisplayed)
		{
			displayPath(pathFinder->findShortestPath());
			pathDisplayed = true;
		}
	}
}
