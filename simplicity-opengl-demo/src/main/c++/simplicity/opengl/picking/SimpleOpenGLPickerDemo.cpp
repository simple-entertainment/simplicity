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
#include <stdio.h>

#include <boost/math/constants/constants.hpp>

#include <simplicity/math/MathFactory.h>
#include <simplicity/scene/SimpleNode.h>
#include <simplicity/scene/SimpleScene.h>

#include <simplicity/opengl/picking/engine/SimpleOpenGLPickingEngine.h>
#include <simplicity/opengl/picking/SimpleOpenGLPicker.h>
#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>
#include <simplicity/opengl/rendering/NamedOpenGLRenderer.h>
#include <simplicity/opengl/rendering/OutlineOpenGLRenderer.h>
#include <simplicity/opengl/rendering/SimpleOpenGLRenderer.h>

#include "SimpleOpenGLPickerDemo.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		SimpleOpenGLPickerDemo::SimpleOpenGLPickerDemo() :
			outlineRenderer(shared_ptr < Renderer > (new OutlineOpenGLRenderer)), pickingEngine(
				shared_ptr < PickingEngine > (new SimpleOpenGLPickingEngine)), renderingEngine(
				shared_ptr < RenderingEngine > (new SimpleOpenGLRenderingEngine))
		{
		}

		SimpleOpenGLPickerDemo::~SimpleOpenGLPickerDemo()
		{
		}

		void SimpleOpenGLPickerDemo::advance()
		{
			engine.advance(shared_ptr<EngineInput>());
		}

		void SimpleOpenGLPickerDemo::dispose()
		{
			engine.destroy();
		}

		shared_ptr<Camera> SimpleOpenGLPickerDemo::getCamera()
		{
			return (renderingEngine->getCamera());
		}

		string SimpleOpenGLPickerDemo::getDescription()
		{
			return ("Pass #1 Renders the shapes.\nPass #2 Renders only an outline of the selected shape.\n"
				"Shapes can be selected by 'picking' them (right-clicking on them).");
		}

		string SimpleOpenGLPickerDemo::getTitle()
		{
			return ("SimpleOpenGLPicker");
		}

		void SimpleOpenGLPickerDemo::init()
		{
			unique_ptr<RGBAColourVector<> > clearingColour(MathFactory::getInstance().createRGBAColourVector());
			clearingColour->setRed(0.95f);
			clearingColour->setGreen(0.95f);
			clearingColour->setBlue(0.95f);
			renderingEngine->setClearingColour(move(clearingColour));

			shared_ptr<SimpleScene> scene(new SimpleScene);
			shared_ptr<SimpleNode> sceneRoot(new SimpleNode);
			renderingEngine->setScene(scene);

			shared_ptr<Camera> camera = addStandardCamera(sceneRoot);
			scene->addCamera(camera);
			renderingEngine->setCamera(camera);

			shared_ptr<Light> light = addStandardLight(sceneRoot);
			scene->addLight(light);

			addStandardCapsule(sceneRoot);
			addStandardCylinder(sceneRoot);
			addStandardSphere(sceneRoot);
			addStandardTorus(sceneRoot);
			scene->addNode(sceneRoot);

			shared_ptr<NamedOpenGLRenderer> firstRenderer(new NamedOpenGLRenderer);
			renderingEngine->addRenderer(firstRenderer);

			renderingEngine->addRenderer(outlineRenderer);
			renderingEngine->setRendererRoot(*outlineRenderer, shared_ptr<Node>());

			shared_ptr<SimpleOpenGLPicker> picker(new SimpleOpenGLPicker);
			picker->setRenderingEngine(renderingEngine);
			static_pointer_cast < SimpleOpenGLPickingEngine > (pickingEngine)->setRenderingEngine(renderingEngine);
			pickingEngine->setPicker(picker);

			shared_ptr<SimpleOpenGLPickerDemo> demo(this);
			pickingEngine->addPickListener(demo);

			engine.addEngine(pickingEngine);
			engine.addEngine(renderingEngine);

			engine.init();
		}

		void SimpleOpenGLPickerDemo::mouseClick(const int x, const int y)
		{
			cout << "Mouse clicked at (" + boost::lexical_cast < string > (x) + ", " + boost::lexical_cast < string
				> (y) + ")\n";

			pickingEngine->pickViewport(800, 600, x, y, 2.0f, 2.0f);
		}

		void SimpleOpenGLPickerDemo::operator()(const PickEvent& event) const
		{
			cout << "Event handled by function object!\n";

			if (event.getHitCount() > 0)
			{
				cout << "Selecting shape!\n";

				renderingEngine->setRendererRoot(*outlineRenderer, event.getHit(0).node);
			}
		}
	}
}
