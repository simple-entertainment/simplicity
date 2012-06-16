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
#include <stdio.h>

#include <boost/math/constants/constants.hpp>

#include <simplicity/engine/SimpleCompositeEngine.h>
#include <simplicity/math/MathFactory.h>
#include <simplicity/scene/SceneFactory.h>
#include <simplicity/SimpleEvents.h>
#include <simplicity/Simplicity.h>

#include <simplicity/opengl/picking/engine/SimpleOpenGLPickingEngine.h>
#include <simplicity/opengl/picking/SimpleOpenGLPicker.h>
#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>
#include <simplicity/opengl/rendering/NamedOpenGLRenderer.h>
#include <simplicity/opengl/rendering/OutlineOpenGLRenderer.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include <simplicity/freeglut/FreeglutEvents.h>
#include <simplicity/freeglut/input/FreeglutInputEvent.h>

#include "SimpleOpenGLPickerDemo.h"

using namespace simplicity::freeglut;
using namespace std;

namespace simplicity
{
	namespace opengl
	{
		SimpleOpenGLPickerDemo::SimpleOpenGLPickerDemo() :
			outlineRenderer(shared_ptr < Renderer > (new OutlineOpenGLRenderer))

		{
		}

		string SimpleOpenGLPickerDemo::getDescription()
		{
			return "Pass #1 Renders the shapes.\nPass #2 Renders only an outline of the selected shape.\n"
				"Shapes can be selected by 'picking' them (right-clicking on them).";
		}

		shared_ptr<Engine> SimpleOpenGLPickerDemo::getEngine()
		{
			return engine;
		}

		string SimpleOpenGLPickerDemo::getTitle()
		{
			return "SimpleOpenGLPicker";
		}

		void SimpleOpenGLPickerDemo::onDispose()
		{
			engine->destroy();

			Simplicity::deregisterObserver(FREEGLUT_MOUSE_EVENT,
				bind(&SimpleOpenGLPickerDemo::onMouse, this, placeholders::_1));
			Simplicity::deregisterObserver(PICK_EVENT, bind(&SimpleOpenGLPickerDemo::onPick, this, placeholders::_1));
		}

		void SimpleOpenGLPickerDemo::onInit()
		{
			engine.reset(new SimpleCompositeEngine);

			renderingEngine.reset(new SimpleOpenGLRenderingEngine);
			engine->addEngine(renderingEngine);

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

			shared_ptr<Model> capsule(createStandardCapsule());
			sceneRoot->addChild(capsule->getNode());
			shared_ptr<Model> cylinder(createStandardCylinder());
			sceneRoot->addChild(cylinder->getNode());
			shared_ptr<Model> sphere(createStandardSphere());
			sceneRoot->addChild(sphere->getNode());
			shared_ptr<Model> torus(createStandardTorus());
			sceneRoot->addChild(torus->getNode());

			shared_ptr<Renderer> renderer(new SimpleOpenGLRenderer);
			renderingEngine->addRenderer(renderer);

			renderingEngine->addRenderer(outlineRenderer);
			renderingEngine->setRendererRoot(*outlineRenderer, shared_ptr<Node>());

			pickingEngine.reset(new SimpleOpenGLPickingEngine);
			engine->addEngine(pickingEngine);

			pickingEngine->setPreferredFrequency(100);

			shared_ptr<RenderingEngine> pickerRenderingEngine(new SimpleOpenGLRenderingEngine);
			pickerRenderingEngine->setScene(scene);
			pickerRenderingEngine->setViewportWidth(800);
			pickerRenderingEngine->setViewportHeight(800);

			clearingColour = MathFactory::getInstance().createColourVector();
			clearingColour->setRed(0.95f);
			clearingColour->setGreen(0.95f);
			clearingColour->setBlue(0.95f);
			pickerRenderingEngine->setClearingColour(move(clearingColour));

			shared_ptr<NamedOpenGLRenderer> namedRenderer(new NamedOpenGLRenderer);
			pickerRenderingEngine->addRenderer(namedRenderer);

			shared_ptr<SimpleOpenGLPicker> picker(new SimpleOpenGLPicker);
			picker->setRenderingEngine(pickerRenderingEngine);
			static_pointer_cast < SimpleOpenGLPickingEngine > (pickingEngine)->setRenderingEngine(renderingEngine);
			pickingEngine->setPicker(picker);

			Simplicity::registerObserver(FREEGLUT_MOUSE_EVENT,
				bind(&SimpleOpenGLPickerDemo::onMouse, this, placeholders::_1));
			Simplicity::registerObserver(PICK_EVENT, bind(&SimpleOpenGLPickerDemo::onPick, this, placeholders::_1));

			engine->init();
		}

		void SimpleOpenGLPickerDemo::onMouse(const boost::any data)
		{
			const FreeglutInputEvent& event(boost::any_cast < FreeglutInputEvent > (data));

			if (event.state == 1)
			{
				pickingEngine->pickViewport(800, 800, event.x, event.y, 2.0f, 2.0f);
			}
		}

		void SimpleOpenGLPickerDemo::onPick(const boost::any data)
		{
			const PickEvent& event(boost::any_cast < PickEvent > (data));

			if (event.getHitCount() > 0)
			{
				renderingEngine->setRendererRoot(*outlineRenderer, event.getHit(0).node);
			}
		}
	}
}
