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

#include <simplicity/math/SimpleRGBAColourVector4.h>
#include <simplicity/scene/SimpleScene.h>
#include <simplicity/scenegraph/SimpleNode.h>
#include <simplicity/scenegraph/SimpleSceneGraph.h>

#include <simplicity/opengl/rendering/AlwaysStencilOpenGLRenderer.h>
#include <simplicity/opengl/rendering/NotEqualStencilOpenGLRenderer.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include "AlwaysAndNotEqualStencilOpenGLRenderersDemo.h"

using namespace boost;

namespace simplicity
{
	namespace opengl
	{
		AlwaysAndNotEqualStencilOpenGLRenderersDemo::AlwaysAndNotEqualStencilOpenGLRenderersDemo()
		{
		}

		AlwaysAndNotEqualStencilOpenGLRenderersDemo::~AlwaysAndNotEqualStencilOpenGLRenderersDemo()
		{
		}

		void AlwaysAndNotEqualStencilOpenGLRenderersDemo::advance()
		{
			fRenderingEngine.advance(shared_ptr<EngineInput>());
		}

		void AlwaysAndNotEqualStencilOpenGLRenderersDemo::dispose()
		{
			fRenderingEngine.destroy();
		}

		shared_ptr<Camera> AlwaysAndNotEqualStencilOpenGLRenderersDemo::getCamera()
		{
			return (fRenderingEngine.getCamera());
		}

		string AlwaysAndNotEqualStencilOpenGLRenderersDemo::getDescription()
		{
			return ("Pass #1 Renders the sphere, cylinder and capsule and assigns a value to the stencil buffer.\n"
				"Pass #2 Renders the torus only where the stencil buffer has not been assigned a value.\n"
				"The result of this is that the torus will never be rendered over the other shapes.");
		}

		string AlwaysAndNotEqualStencilOpenGLRenderersDemo::getTitle()
		{
			return ("AlwaysStencilOpenGLRenderer and NotEqualStencilOpenGLRenderer");
		}

		void AlwaysAndNotEqualStencilOpenGLRenderersDemo::init()
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

			shared_ptr<SimpleOpenGLRenderer> wrappedRenderer(new SimpleOpenGLRenderer);

			shared_ptr<AlwaysStencilOpenGLRenderer> firstRenderer(new AlwaysStencilOpenGLRenderer(wrappedRenderer));
			fRenderingEngine.addRenderer(firstRenderer);
			fRenderingEngine.setRendererRoot(*firstRenderer, renderingPass1Root);

			shared_ptr<NotEqualStencilOpenGLRenderer> secondRenderer(
				new NotEqualStencilOpenGLRenderer(wrappedRenderer));
			fRenderingEngine.addRenderer(secondRenderer);
			fRenderingEngine.setRendererRoot(*secondRenderer, renderingPass2Root);

			fRenderingEngine.init();
		}
	}
}
