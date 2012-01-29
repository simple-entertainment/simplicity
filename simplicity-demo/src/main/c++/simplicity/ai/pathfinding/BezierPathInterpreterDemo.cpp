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

#include <simplicity/ai/pathfinding/BezierPathInterpolator.h>
#include <simplicity/ai/pathfinding/NoPathException.h>
#include <simplicity/ai/pathfinding/SimplePathFinder.h>
#include <simplicity/scene/SimpleNode.h>
#include <simplicity/scene/SimpleScene.h>

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

	BezierPathInterpreterDemo::~BezierPathInterpreterDemo()
	{
	}

	void BezierPathInterpreterDemo::advance()
	{
		renderingEngine.advance(shared_ptr<EngineInput>());
	}

	void BezierPathInterpreterDemo::dispose()
	{
		renderingEngine.destroy();
	}

	shared_ptr<Camera> BezierPathInterpreterDemo::getCamera()
	{
		return (renderingEngine.getCamera());
	}

	string BezierPathInterpreterDemo::getDescription()
	{
		return ("");
	}

	string BezierPathInterpreterDemo::getTitle()
	{
		return ("BezierPathInterpreterDemo");
	}

	void BezierPathInterpreterDemo::init()
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

		renderingEngine.addRenderer(shared_ptr<Renderer> (new SimpleOpenGLRenderer));
		renderingEngine.init();

		do
		{
			populateNavigationMesh();
			vector<shared_ptr<Entity> > obstacles = createObstacles();

			try
			{
				SimplePathFinder pathFinder = SimplePathFinder(*getNavigationMesh().at(4), *getNavigationMesh().at(95));
				shortestPath = pathFinder.findShortestPath();

				renderingEngine.addEntities(obstacles);
			}
			catch (NoPathException& e)
			{
			}
		}
		while (shortestPath.empty());
	}

	void BezierPathInterpreterDemo::onMouseButton(const int button, const int state, const int x, const int y)
	{
		if (button == GLUT_LEFT_BUTTON || state == GLUT_UP)
		{
			BezierPathInterpolator pathInterpolator(shortestPath);
			vector<shared_ptr<const Node> > path;

			for (unsigned int index = 0; index <= interpolationCount; index++)
			{
				shared_ptr<Node> pathNode(new SimpleNode);
				pathNode->getTransformation().setTranslation(*pathInterpolator.interpolate(index / interpolationCount));

				path.push_back(pathNode);
			}

			displayPath(renderingEngine, path);

			interpolationCount *= 2;
		}
	}

	void BezierPathInterpreterDemo::onMouseMotion(const int x, const int y)
	{
	}
}
