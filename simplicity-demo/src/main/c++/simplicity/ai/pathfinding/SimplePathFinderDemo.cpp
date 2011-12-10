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
#include <GL/glew.h>
#include <GL/glut.h>

#include <simplicity/scene/SimpleNode.h>
#include <simplicity/scene/SimpleScene.h>

#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include "SimplePathFinderDemo.h"

using namespace boost;
using namespace simplicity::opengl;
using namespace std;

namespace simplicity
{
	SimplePathFinderDemo::SimplePathFinderDemo()
	{
	}

	SimplePathFinderDemo::~SimplePathFinderDemo()
	{
	}

	void SimplePathFinderDemo::advance()
	{
		renderingEngine.advance(shared_ptr<EngineInput>());
	}

	void SimplePathFinderDemo::dispose()
	{
		renderingEngine.destroy();
	}

	shared_ptr<Camera> SimplePathFinderDemo::getCamera()
	{
		return (renderingEngine.getCamera());
	}

	string SimplePathFinderDemo::getDescription()
	{
		return ("");
	}

	string SimplePathFinderDemo::getTitle()
	{
		return ("SimplePathFinderDemo");
	}

	void SimplePathFinderDemo::init()
	{
		renderingEngine.setViewportWidth(800);
		renderingEngine.setViewportHeight(800);

		shared_ptr<Scene> scene(new SimpleScene);
		renderingEngine.setScene(scene);

		shared_ptr<Node> sceneRoot(new SimpleNode);

		shared_ptr<Camera> camera = addCamera(sceneRoot);
		scene->addCamera(camera);
		renderingEngine.setCamera(camera);

		shared_ptr<Light> light = addLight(sceneRoot);
		scene->addLight(light);

		addBackground(sceneRoot);
		scene->addNode(sceneRoot);

		populateNavigationMesh();

		renderingEngine.addRenderer(shared_ptr<Renderer> (new SimpleOpenGLRenderer));
		renderingEngine.addEntities(createObstacles());

		pathFinder = shared_ptr<SimplePathFinder> (new SimplePathFinder(*getNavigationMesh().at(4),
			*getNavigationMesh().at(95)));

		renderingEngine.init();
	}

	void SimplePathFinderDemo::onMouseButton(const int button, const int state, const int x, const int y)
	{
		if (button != GLUT_LEFT_BUTTON || state != GLUT_UP)
		{
			return;
		}

		bool pathFound = pathFinder->stepForward();

		displayOpenNodes(renderingEngine, pathFinder->getOpenNodes());

		if (pathFound)
		{
			displayPath(renderingEngine, pathFinder->findShortestPath());
		}
	}

	void SimplePathFinderDemo::onMouseMotion(const int x, const int y)
	{
	}
}
