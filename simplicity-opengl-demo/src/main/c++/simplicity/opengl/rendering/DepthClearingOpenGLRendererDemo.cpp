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
#include <boost/math/constants/constants.hpp>

#include <simplicity/scene/SimpleScene.h>
#include <simplicity/scenegraph/SimpleNode.h>
#include <simplicity/scenegraph/SimpleSceneGraph.h>
#include <simplicity/vector/SimpleRGBAColourVector4.h>

#include <simplicity/opengl/rendering/DepthClearingOpenGLRenderer.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include "DepthClearingOpenGLRendererDemo.h"

namespace simplicity
{
	namespace opengl
	{
		DepthClearingOpenGLRendererDemo::DepthClearingOpenGLRendererDemo()
		{
		}

		DepthClearingOpenGLRendererDemo::~DepthClearingOpenGLRendererDemo()
		{
		}

		void DepthClearingOpenGLRendererDemo::advance()
		{
			fRenderingEngine.advance(shared_ptr<EngineInput>());
		}

		void DepthClearingOpenGLRendererDemo::dispose()
		{
			fRenderingEngine.destroy();
		}

		shared_ptr<Camera> DepthClearingOpenGLRendererDemo::getCamera()
		{
			return (fRenderingEngine.getCamera());
		}

		string DepthClearingOpenGLRendererDemo::getDescription()
		{
			return ("Pass #1 Renders the sphere, cylinder and capsule normally.\n"
				"Before Pass #2 Clears the depth buffer.\n" "Pass #2 Renders the torus normally.\n"
				"The result of this is that the torus will always be rendered over the other shapes.");
		}

		string DepthClearingOpenGLRendererDemo::getTitle()
		{
			return ("DepthClearingOpenGLRenderer");
		}

		void DepthClearingOpenGLRendererDemo::init()
		{
			fRenderingEngine.setClearingColour(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.95f, 0.95f, 0.95f, 1.0f)));

			shared_ptr<SimpleScene> scene(new SimpleScene);
			shared_ptr<SimpleSceneGraph> sceneGraph(new SimpleSceneGraph);
			shared_ptr<SimpleNode> sceneRoot(new SimpleNode);
			scene->setSceneGraph(sceneGraph);
			fRenderingEngine.setScene(scene);

			shared_ptr<Camera> camera = addStandardCamera(sceneRoot);
			scene->addCamera(camera);
			fRenderingEngine.setCamera(camera);

			shared_ptr<Light> light = addStandardLight(sceneRoot);
			scene->addLight(light);
			sceneGraph->addSubgraph(sceneRoot);

			shared_ptr<SimpleNode> renderingPass1Root(new SimpleNode);
			addStandardCapsule(renderingPass1Root);
			addStandardCylinder(renderingPass1Root);
			addStandardSphere(renderingPass1Root);
			sceneGraph->addSubgraph(renderingPass1Root);

			shared_ptr<SimpleNode> renderingPass2Root(new SimpleNode);
			addStandardTorus(renderingPass2Root);
			sceneGraph->addSubgraph(renderingPass2Root);

			shared_ptr<SimpleOpenGLRenderer> firstRenderer(new SimpleOpenGLRenderer);
			fRenderingEngine.addRenderer(firstRenderer);
			fRenderingEngine.setRendererRoot(*firstRenderer, renderingPass1Root);

			shared_ptr<DepthClearingOpenGLRenderer> secondRenderer(new DepthClearingOpenGLRenderer(firstRenderer));
			fRenderingEngine.addRenderer(secondRenderer);
			fRenderingEngine.setRendererRoot(*secondRenderer, renderingPass2Root);

			fRenderingEngine.init();
		}
	}
}
