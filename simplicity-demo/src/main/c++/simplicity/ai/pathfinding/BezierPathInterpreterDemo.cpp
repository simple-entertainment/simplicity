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

#include <simplicity/ai/pathfinding/BezierPathInterpolator.h>
#include <simplicity/ai/pathfinding/NoPathException.h>
#include <simplicity/ai/pathfinding/SimplePathFinder.h>
#include <simplicity/Events.h>
#include <simplicity/graph/NodeFactory.h>
#include <simplicity/graph/SimpleTree.h>
#include <simplicity/input/MouseButtonEvent.h>
#include <simplicity/Messages.h>
#include <simplicity/scene/SimpleScene.h>
#include <simplicity/Simplicity.h>

#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include "BezierPathInterpreterDemo.h"

using namespace simplicity::opengl;
using namespace std;

namespace simplicity
{
	BezierPathInterpreterDemo::BezierPathInterpreterDemo() :
		interpolationCount(2)
	{
	}

	void BezierPathInterpreterDemo::dispose()
	{
		renderingEngine->destroy();
		removeAllEntities();

		Messages::deregisterRecipient(MOUSE_BUTTON_EVENT,
			bind(&BezierPathInterpreterDemo::onMouse, this, placeholders::_1));
	}

	string BezierPathInterpreterDemo::getDescription() const
	{
		return "Click the mouse to interpolate points on the path.";
	}

	shared_ptr<Engine> BezierPathInterpreterDemo::getEngine() const
	{
		return renderingEngine;
	}

	string BezierPathInterpreterDemo::getTitle() const
	{
		return "BezierPathInterpreterDemo";
	}

	void BezierPathInterpreterDemo::init()
	{
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

		shared_ptr<Renderer> renderer(new SimpleOpenGLRenderer);
		renderingEngine->addRenderer(renderer);
		renderingEngine->init();

		do
		{
			createNavigationMesh();
			vector<pair<unsigned int, unsigned int> > obstacleLocations = getRandomObstacleLocations();
			removeLocationsFromNavigationMesh(obstacleLocations);

			try
			{
				SimplePathFinder pathFinder = SimplePathFinder(getNavigationMesh().get(4), getNavigationMesh().get(95));
				shortestPath = pathFinder.findShortestPath();

				addObstacles(obstacleLocations);
			}
			catch (NoPathException& e)
			{
			}
		}
		while (shortestPath.empty());

		interpolationCount = 2;

		Messages::registerRecipient(MOUSE_BUTTON_EVENT,
			bind(&BezierPathInterpreterDemo::onMouse, this, placeholders::_1));
	}

	void BezierPathInterpreterDemo::onMouse(const boost::any message)
	{
		const MouseButtonEvent& event = boost::any_cast<MouseButtonEvent>(message);

		if (event.button != Mouse::Button::LEFT || event.buttonState != Button::State::UP)
		{
			return;
		}

		BezierPathInterpolator pathInterpolator(shortestPath);
		vector<shared_ptr<const Node> > ownedPath;
		vector<reference_wrapper<const Node> > path;

		for (unsigned int index = 0; index <= interpolationCount; index++)
		{
			shared_ptr<Node> pathNode = NodeFactory::getInstance().createNode();
			pathNode->getTransformation().setTranslation(*pathInterpolator.interpolate(index / interpolationCount));

			ownedPath.push_back(pathNode);
			path.push_back(*pathNode);
		}

		displayPath(path);

		interpolationCount *= 2;
	}
}
