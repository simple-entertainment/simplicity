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
#include <simplicity/scene/SceneFactory.h>

#include <simplicity/opengl/rendering/CullFaceOpenGLRenderer.h>
#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>

#include "CullFaceOpenGLRendererDemo.h"

namespace simplicity
{
	namespace opengl
	{
		CullFaceOpenGLRendererDemo::CullFaceOpenGLRendererDemo() :
			renderingEngine()
		{
		}

		string CullFaceOpenGLRendererDemo::getDescription()
		{
			return "Renders the front side of each face green and the back side of each face red.";
		}

		shared_ptr<Engine> CullFaceOpenGLRendererDemo::getEngine()
		{
			return renderingEngine;
		}

		string CullFaceOpenGLRendererDemo::getTitle()
		{
			return "CullFaceOpenGLRenderer";
		}

		void CullFaceOpenGLRendererDemo::onDispose()
		{
			renderingEngine->destroy();
		}

		void CullFaceOpenGLRendererDemo::onInit()
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

			sceneRoot->addChild(createTitle()->getNode());
			for (shared_ptr<Model> descriptionLine : createDescription()) {
				sceneRoot->addChild(descriptionLine->getNode());
			}

			sceneRoot->addChild(getModelsRoot());
			shared_ptr<Model> capsule(createStandardCapsule());
			getModelsRoot()->addChild(capsule->getNode());
			shared_ptr<Model> cylinder(createStandardCylinder());
			getModelsRoot()->addChild(cylinder->getNode());
			shared_ptr<Model> sphere(createStandardSphere());
			getModelsRoot()->addChild(sphere->getNode());
			shared_ptr<Model> torus(createStandardTorus());
			getModelsRoot()->addChild(torus->getNode());

			shared_ptr<CullFaceOpenGLRenderer> renderer(new CullFaceOpenGLRenderer);
			renderingEngine->addRenderer(renderer);

			renderingEngine->init();
		}
	}
}
