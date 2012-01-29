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
#include <simplicity/scene/SimpleNode.h>
#include <simplicity/scene/SimpleScene.h>

#include <simplicity/opengl/rendering/AlwaysStencilOpenGLRenderer.h>
#include <simplicity/opengl/rendering/NotEqualStencilOpenGLRenderer.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>
#include <simplicity/opengl/rendering/StencilClearingOpenGLRenderer.h>

#include "StencilClearingOpenGLRendererDemo.h"

namespace simplicity
{
	namespace opengl
	{
		StencilClearingOpenGLRendererDemo::StencilClearingOpenGLRendererDemo()
		{
		}

		StencilClearingOpenGLRendererDemo::~StencilClearingOpenGLRendererDemo()
		{
		}

		void StencilClearingOpenGLRendererDemo::advance()
		{
			fRenderingEngine.advance(shared_ptr<EngineInput>());
		}

		void StencilClearingOpenGLRendererDemo::dispose()
		{
			fRenderingEngine.destroy();
		}

		shared_ptr<Camera> StencilClearingOpenGLRendererDemo::getCamera()
		{
			return (fRenderingEngine.getCamera());
		}

		string StencilClearingOpenGLRendererDemo::getDescription()
		{
			return ("Pass #1 Renders the sphere, cylinder and capsule and assigns a value to the stencil buffer.\n"
				"Before Pass #2 Clears the stencil buffer.\n"
				"Pass #2 Renders the torus only where the stencil buffer has not been assigned a value.\n"
				"The result of this is that the torus can be rendered over the other shapes.");
		}

		string StencilClearingOpenGLRendererDemo::getTitle()
		{
			return ("StencilClearingOpenGLRenderer");
		}

		void StencilClearingOpenGLRendererDemo::init()
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
			scene->addNode(sceneRoot);

			shared_ptr<SimpleNode> renderingPass1Root(new SimpleNode);
			addStandardCapsule(renderingPass1Root);
			addStandardCylinder(renderingPass1Root);
			addStandardSphere(renderingPass1Root);
			scene->addNode(renderingPass1Root);

			shared_ptr<SimpleNode> renderingPass2Root(new SimpleNode);
			addStandardTorus(renderingPass2Root);
			scene->addNode(renderingPass2Root);

			shared_ptr<SimpleOpenGLRenderer> wrappedRenderer(new SimpleOpenGLRenderer);

			shared_ptr<AlwaysStencilOpenGLRenderer> firstRenderer(new AlwaysStencilOpenGLRenderer(wrappedRenderer));
			fRenderingEngine.addRenderer(firstRenderer);
			fRenderingEngine.setRendererRoot(*firstRenderer, renderingPass1Root);

			shared_ptr<StencilClearingOpenGLRenderer> secondRenderer(
				new StencilClearingOpenGLRenderer(
					shared_ptr < NotEqualStencilOpenGLRenderer > (new NotEqualStencilOpenGLRenderer(wrappedRenderer))));
			fRenderingEngine.addRenderer(secondRenderer);
			fRenderingEngine.setRendererRoot(*secondRenderer, renderingPass2Root);

			fRenderingEngine.init();
		}
	}
}
