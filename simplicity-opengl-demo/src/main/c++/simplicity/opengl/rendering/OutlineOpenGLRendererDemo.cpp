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
			renderingEngine.advance(shared_ptr<EngineInput>());
		}

		void OutlineOpenGLRendererDemo::dispose()
		{
			renderingEngine.destroy();
		}

		shared_ptr<Camera> OutlineOpenGLRendererDemo::getCamera()
		{
			return (renderingEngine.getCamera());
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

			shared_ptr<OutlineOpenGLRenderer> renderer(new OutlineOpenGLRenderer);
			renderingEngine.addRenderer(renderer);

			renderingEngine.init();
		}
	}
}
