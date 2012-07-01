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
#include <simplicity/input/InputEvent.h>
#include <simplicity/scene/SceneFactory.h>
#include <simplicity/SimpleEvents.h>
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

		Simplicity::deregisterObserver(INPUT_EVENT, bind(&BezierPathInterpreterDemo::onMouse, this, placeholders::_1));
	}

	string BezierPathInterpreterDemo::getDescription()
	{
		return "Click the mouse to interpolate points on the path.";
	}

	shared_ptr<Engine> BezierPathInterpreterDemo::getEngine()
	{
		return renderingEngine;
	}

	string BezierPathInterpreterDemo::getTitle()
	{
		return "BezierPathInterpreterDemo";
	}

	void BezierPathInterpreterDemo::init()
	{
		renderingEngine.reset(new SimpleOpenGLRenderingEngine);
		renderingEngine->setPreferredFrequency(100);
		renderingEngine->setViewportWidth(800);
		renderingEngine->setViewportHeight(800);

		shared_ptr<Scene> scene(SceneFactory::getInstance().createScene());
		renderingEngine->setScene(scene);

		shared_ptr<Node> sceneRoot(SceneFactory::getInstance().createNode());
		scene->addNode(sceneRoot);

		shared_ptr<Camera> camera = addCamera(sceneRoot);
		scene->addCamera(camera);
		renderingEngine->setCamera(camera);

		shared_ptr<Light> light = addLight(sceneRoot);
		scene->addLight(light);

		addBackground(sceneRoot);

		renderingEngine->addEntity(createTitle());
		for (shared_ptr<Entity> descriptionLine : createDescription()) {
			renderingEngine->addEntity(descriptionLine);
		}

		renderingEngine->addRenderer(shared_ptr < Renderer > (new SimpleOpenGLRenderer));
		renderingEngine->init();

		do
		{
			populateNavigationMesh();
			vector < shared_ptr<Entity> > obstacles = createObstacles();

			try
			{
				SimplePathFinder pathFinder = SimplePathFinder(*getNavigationMesh().at(4), *getNavigationMesh().at(95));
				shortestPath = pathFinder.findShortestPath();

				for (shared_ptr<Entity> obstacle : obstacles)
				{
					renderingEngine->addEntity(obstacle);
				}
			}
			catch (NoPathException& e)
			{
			}
		}
		while (shortestPath.empty());

		interpolationCount = 2;

		Simplicity::registerObserver(INPUT_EVENT, bind(&BezierPathInterpreterDemo::onMouse, this, placeholders::_1));
	}

	void BezierPathInterpreterDemo::onMouse(const boost::any data)
	{
		const InputEvent& event = boost::any_cast<InputEvent>(data);

		if (event.type != InputEvent::Type::MOUSE_BUTTON || event.mouseButton != InputEvent::MouseButton::LEFT
			|| event.buttonState != InputEvent::ButtonState::UP)
		{
			return;
		}

		BezierPathInterpolator pathInterpolator(shortestPath);
		vector < shared_ptr<const Node> > path;

		for (unsigned int index = 0; index <= interpolationCount; index++)
		{
			shared_ptr<Node> pathNode(SceneFactory::getInstance().createNode());
			pathNode->getTransformation().setTranslation(*pathInterpolator.interpolate(index / interpolationCount));

			path.push_back(pathNode);
		}

		displayPath(path);

		interpolationCount *= 2;
	}
}
