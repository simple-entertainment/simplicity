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

#include <simplicity/opengl/rendering/OutlineOpenGLRenderer.h>

#include "OutlineOpenGLRendererDemo.h"

namespace simplicity
{
	namespace opengl
	{
		OutlineOpenGLRendererDemo::OutlineOpenGLRendererDemo()
		{
		}

		OutlineOpenGLRendererDemo::~OutlineOpenGLRendererDemo()
		{
		}

		void OutlineOpenGLRendererDemo::advance()
		{
			fRenderingEngine.advance(shared_ptr<EngineInput>());
		}

		void OutlineOpenGLRendererDemo::dispose()
		{
			fRenderingEngine.destroy();
		}

		shared_ptr<Camera> OutlineOpenGLRendererDemo::getCamera()
		{
			return (fRenderingEngine.getCamera());
		}

		string OutlineOpenGLRendererDemo::getDescription()
		{
			return ("Renders only an outline of the shapes. Performs multiple rendering passes internally using "
				"stencilling renderers to achieve this.");
		}

		string OutlineOpenGLRendererDemo::getTitle()
		{
			return ("OutlineOpenGLRenderer");
		}

		void OutlineOpenGLRendererDemo::init()
		{
			fRenderingEngine.setClearingColour(
				shared_ptr < SimpleRGBAColourVector4<>
					> (new SimpleRGBAColourVector4<>(0.95f, 0.95f, 0.95f, 1.0f)));

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

			shared_ptr<OutlineOpenGLRenderer> renderer(new OutlineOpenGLRenderer);
			fRenderingEngine.addRenderer(renderer);

			fRenderingEngine.init();
		}
	}
}