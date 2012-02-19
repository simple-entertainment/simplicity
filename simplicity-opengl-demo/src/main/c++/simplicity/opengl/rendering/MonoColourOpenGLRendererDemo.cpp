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
#include <boost/math/constants/constants.hpp>

#include <simplicity/math/MathFactory.h>
#include <simplicity/scene/SimpleNode.h>
#include <simplicity/scene/SimpleScene.h>

#include <simplicity/opengl/rendering/MonoColourOpenGLRenderer.h>

#include "MonoColourOpenGLRendererDemo.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		MonoColourOpenGLRendererDemo::MonoColourOpenGLRendererDemo()
		{
		}

		MonoColourOpenGLRendererDemo::~MonoColourOpenGLRendererDemo()
		{
		}

		void MonoColourOpenGLRendererDemo::advance()
		{
			renderingEngine.advance(shared_ptr<EngineInput>());
		}

		void MonoColourOpenGLRendererDemo::dispose()
		{
			renderingEngine.destroy();
		}

		shared_ptr<Camera> MonoColourOpenGLRendererDemo::getCamera()
		{
			return (renderingEngine.getCamera());
		}

		string MonoColourOpenGLRendererDemo::getDescription()
		{
			return ("You'll just have to trust me on this one (unless you check the code). All the shapes are"
				"different colours but the renderer overrides that.");
		}

		string MonoColourOpenGLRendererDemo::getTitle()
		{
			return ("MonoColourOpenGLRenderer");
		}

		void MonoColourOpenGLRendererDemo::init()
		{
			unique_ptr<RGBAColourVector<> > clearingColour(MathFactory::getInstance().createRGBAColourVector());
			clearingColour->setRed(0.95f);
			clearingColour->setGreen(0.95f);
			clearingColour->setBlue(0.95f);
			renderingEngine.setClearingColour(move(clearingColour));

			shared_ptr<SimpleScene> scene(new SimpleScene);
			shared_ptr<SimpleNode> sceneRoot(new SimpleNode);
			renderingEngine.setScene(scene);

			shared_ptr<Camera> camera = addStandardCamera(sceneRoot);
			scene->addCamera(camera);
			renderingEngine.setCamera(camera);

			shared_ptr<Light> light = addStandardLight(sceneRoot);
			scene->addLight(light);

			addStandardCapsule(sceneRoot);
			addStandardCylinder(sceneRoot);
			addStandardSphere(sceneRoot);
			addStandardTorus(sceneRoot);
			scene->addNode(sceneRoot);

			shared_ptr<MonoColourOpenGLRenderer> renderer(new MonoColourOpenGLRenderer);

			unique_ptr<RGBAColourVector<> > renderColour(MathFactory::getInstance().createRGBAColourVector());
			renderColour->setGreen(0.5f);
			renderColour->setBlue(0.5f);
			renderer->setColour(move(renderColour));

			renderingEngine.addRenderer(renderer);

			renderingEngine.init();
		}
	}
}
