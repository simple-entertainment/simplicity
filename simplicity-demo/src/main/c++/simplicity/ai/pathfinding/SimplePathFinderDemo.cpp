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

#include <simplicity/scene/SceneFactory.h>
#include <simplicity/Simplicity.h>

#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include <simplicity/freeglut/FreeglutEvents.h>
#include <simplicity/freeglut/input/FreeglutInputEvent.h>

#include "SimplePathFinderDemo.h"

using namespace simplicity::freeglut;
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

		Simplicity::deregisterObserver(FREEGLUT_MOUSE_EVENT,
			bind(&SimplePathFinderDemo::onMouse, this, placeholders::_1));
	}

	string SimplePathFinderDemo::getDescription()
	{
		return "Click the mouse to advance the simple pathfinding algorithm.\n"
			"When a path is found, it will be displayed as green dots.";
	}

	shared_ptr<Engine> SimplePathFinderDemo::getEngine()
	{
		return renderingEngine;
	}

	string SimplePathFinderDemo::getTitle()
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

		populateNavigationMesh();

		for (shared_ptr<Entity> obstacle : createObstacles())
		{
			renderingEngine->addEntity(obstacle);
		}

		renderingEngine->addEntity(createTitle());
		for (shared_ptr<Entity> descriptionLine : createDescription()) {
			renderingEngine->addEntity(descriptionLine);
		}

		renderingEngine->addRenderer(shared_ptr < Renderer > (new SimpleOpenGLRenderer));
		renderingEngine->init();

		pathFinder.reset(new SimplePathFinder(*getNavigationMesh().at(4), *getNavigationMesh().at(95)));

		Simplicity::registerObserver(FREEGLUT_MOUSE_EVENT,
			bind(&SimplePathFinderDemo::onMouse, this, placeholders::_1));
	}

	void SimplePathFinderDemo::onMouse(const boost::any data)
	{
		const FreeglutInputEvent& event(boost::any_cast < FreeglutInputEvent > (data));

		if (event.button != GLUT_LEFT_BUTTON || event.state != GLUT_UP)
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
