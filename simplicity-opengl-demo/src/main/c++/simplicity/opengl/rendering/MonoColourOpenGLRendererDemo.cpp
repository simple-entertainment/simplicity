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

#include <simplicity/math/SimpleRGBAColourVector4.h>
#include <simplicity/scene/SimpleNode.h>
#include <simplicity/scene/SimpleScene.h>

#include <simplicity/opengl/rendering/MonoColourOpenGLRenderer.h>

#include "MonoColourOpenGLRendererDemo.h"

using namespace boost;
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
			fRenderingEngine.advance(shared_ptr<EngineInput>());
		}

		void MonoColourOpenGLRendererDemo::dispose()
		{
			fRenderingEngine.destroy();
		}

		shared_ptr<Camera> MonoColourOpenGLRendererDemo::getCamera()
		{
			return (fRenderingEngine.getCamera());
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
			fRenderingEngine.setClearingColour(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.95f, 0.95f, 0.95f, 1.0f)));

			shared_ptr<SimpleScene> scene(new SimpleScene);
			shared_ptr<SimpleNode> sceneRoot(new SimpleNode);
			fRenderingEngine.setScene(scene);

			shared_ptr<Camera> camera = addStandardCamera(sceneRoot);
			scene->addCamera(camera);
			fRenderingEngine.setCamera(camera);

			shared_ptr<Light> light = addStandardLight(sceneRoot);
			scene->addLight(light);

			addStandardCapsule(sceneRoot);
			addStandardCylinder(sceneRoot);
			addStandardSphere(sceneRoot);
			addStandardTorus(sceneRoot);
			scene->addNode(sceneRoot);

			shared_ptr<MonoColourOpenGLRenderer> renderer(new MonoColourOpenGLRenderer);
			renderer->setColour(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.0f, 0.5f, 0.5f, 1.0f)));
			fRenderingEngine.addRenderer(renderer);

			fRenderingEngine.init();
		}
	}
}
