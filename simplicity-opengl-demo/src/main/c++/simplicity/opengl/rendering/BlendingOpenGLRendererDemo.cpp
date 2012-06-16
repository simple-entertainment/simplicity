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
#include <simplicity/model/ModelFactory.h>
#include <simplicity/scene/SceneFactory.h>

#include <simplicity/opengl/rendering/BlendingOpenGLRenderer.h>
#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include "BlendingOpenGLRendererDemo.h"

namespace simplicity
{
	namespace opengl
	{
		BlendingOpenGLRendererDemo::BlendingOpenGLRendererDemo() :
			renderingEngine()
		{
		}

		string BlendingOpenGLRendererDemo::getDescription()
		{
			return "Pass #1 Renders the sphere, cylinder and capsule normally.\n"
				"Pass #2 Renders the torus with 50% opacity and blends it.";
		}

		shared_ptr<Engine> BlendingOpenGLRendererDemo::getEngine()
		{
			return renderingEngine;
		}

		string BlendingOpenGLRendererDemo::getTitle()
		{
			return "BlendingOpenGLRenderer";
		}

		void BlendingOpenGLRendererDemo::onDispose()
		{
			renderingEngine->destroy();
		}

		void BlendingOpenGLRendererDemo::onInit()
		{
			renderingEngine.reset(new SimpleOpenGLRenderingEngine);

			renderingEngine->setPreferredFrequency(100);
			renderingEngine->setViewportWidth(800);
			renderingEngine->setViewportHeight(800);

			unique_ptr<ColourVector<> > clearingColour(MathFactory::getInstance().createColourVector());
			clearingColour->setRed(0.95f);
			clearingColour->setGreen(0.95f);
			clearingColour->setBlue(0.95f);
			renderingEngine->setClearingColour(move(clearingColour));

			shared_ptr<Scene> scene(SceneFactory::getInstance().createScene());
			renderingEngine->setScene(scene);

			shared_ptr<Node> sceneRoot(SceneFactory::getInstance().createNode());
			scene->addNode(sceneRoot);

			shared_ptr<Camera> camera = addStandardCamera(sceneRoot);
			scene->addCamera(camera);
			renderingEngine->setCamera(camera);

			shared_ptr<Light> light = addStandardLight(sceneRoot);
			scene->addLight(light);

			shared_ptr<Node> textRoot(SceneFactory::getInstance().createNode());
			sceneRoot->addChild(textRoot);

			textRoot->addChild(createTitle()->getNode());
			for (shared_ptr<Model> descriptionLine : createDescription()) {
				textRoot->addChild(descriptionLine->getNode());
			}

			sceneRoot->addChild(getModelsRoot());

			shared_ptr<Node> renderingPass1Root(SceneFactory::getInstance().createNode());
			getModelsRoot()->addChild(renderingPass1Root);

			shared_ptr<Model> capsule(createStandardCapsule());
			renderingPass1Root->addChild(capsule->getNode());
			shared_ptr<Model> cylinder(createStandardCylinder());
			renderingPass1Root->addChild(cylinder->getNode());
			shared_ptr<Model> sphere(createStandardSphere());
			renderingPass1Root->addChild(sphere->getNode());

			shared_ptr<Node> renderingPass2Root(SceneFactory::getInstance().createNode());
			getModelsRoot()->addChild(renderingPass2Root);

			shared_ptr<Torus> torus(createStandardTorus());
			renderingPass2Root->addChild(torus->getNode());

			unique_ptr<ColourVector<> > torusColour(MathFactory::getInstance().createColourVector());
			torusColour->setRed(1.0f);
			torusColour->setGreen(1.0f);
			torusColour->setBlue(1.0f);
			torusColour->setAlpha(0.5f);
			torus->setColour(move(torusColour));

			shared_ptr<SimpleOpenGLRenderer> textRenderer(new SimpleOpenGLRenderer);
			renderingEngine->addRenderer(textRenderer);
			renderingEngine->setRendererRoot(*textRenderer, textRoot);

			shared_ptr<SimpleOpenGLRenderer> firstRenderer(new SimpleOpenGLRenderer);
			renderingEngine->addRenderer(firstRenderer);
			renderingEngine->setRendererRoot(*firstRenderer, renderingPass1Root);

			shared_ptr<BlendingOpenGLRenderer> secondRenderer(new BlendingOpenGLRenderer(firstRenderer));
			renderingEngine->addRenderer(secondRenderer);
			renderingEngine->setRendererRoot(*secondRenderer, renderingPass2Root);

			renderingEngine->init();
		}
	}
}
