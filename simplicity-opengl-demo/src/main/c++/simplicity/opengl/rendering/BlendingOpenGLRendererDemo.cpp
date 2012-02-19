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
#include <simplicity/scene/model/SimpleModelNode.h>
#include <simplicity/scene/SimpleNode.h>
#include <simplicity/scene/SimpleScene.h>

#include <simplicity/opengl/rendering/BlendingOpenGLRenderer.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include "BlendingOpenGLRendererDemo.h"

namespace simplicity
{
	namespace opengl
	{
		BlendingOpenGLRendererDemo::BlendingOpenGLRendererDemo()
		{
		}

		BlendingOpenGLRendererDemo::~BlendingOpenGLRendererDemo()
		{
		}

		void BlendingOpenGLRendererDemo::advance()
		{
			renderingEngine.advance(shared_ptr<EngineInput>());
		}

		void BlendingOpenGLRendererDemo::dispose()
		{
			renderingEngine.destroy();
		}

		shared_ptr<Camera> BlendingOpenGLRendererDemo::getCamera()
		{
			return (renderingEngine.getCamera());
		}

		string BlendingOpenGLRendererDemo::getDescription()
		{
			return ("Pass #1 Renders the sphere, cylinder and capsule normally.\n"
				"Pass #2 Renders the torus with 50% opacity and blends it.");
		}

		string BlendingOpenGLRendererDemo::getTitle()
		{
			return ("BlendingOpenGLRenderer");
		}

		void BlendingOpenGLRendererDemo::init()
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
			scene->addNode(sceneRoot);

			shared_ptr<SimpleNode> renderingPass1Root(new SimpleNode);
			addStandardCapsule(renderingPass1Root);
			addStandardCylinder(renderingPass1Root);
			addStandardSphere(renderingPass1Root);
			scene->addNode(renderingPass1Root);

			shared_ptr<SimpleNode> renderingPass2Root(new SimpleNode);
			shared_ptr<SimpleModelNode> torusNode(new SimpleModelNode);

			unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
			translation->setY(-2.0f);
			torusNode->getTransformation().translate(*translation);

			shared_ptr<GLUTorus> torus(new GLUTorus);

			unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
			colour->setRed(1.0f);
			colour->setGreen(1.0f);
			colour->setBlue(1.0f);
			colour->setAlpha(0.5f);
			torus->setColour(move(colour));

			torusNode->setModel(torus);
			renderingPass2Root->addChild(torusNode);
			scene->addNode(renderingPass2Root);

			shared_ptr<SimpleOpenGLRenderer> firstRenderer(new SimpleOpenGLRenderer);
			renderingEngine.addRenderer(firstRenderer);
			renderingEngine.setRendererRoot(*firstRenderer, renderingPass1Root);

			shared_ptr<BlendingOpenGLRenderer> secondRenderer(new BlendingOpenGLRenderer(firstRenderer));
			renderingEngine.addRenderer(secondRenderer);
			renderingEngine.setRendererRoot(*secondRenderer, renderingPass2Root);

			renderingEngine.init();
		}
	}
}
