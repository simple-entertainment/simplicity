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

#include "CullFaceOpenGLRendererDemo.h"

namespace simplicity
{
	namespace opengl
	{
		CullFaceOpenGLRendererDemo::CullFaceOpenGLRendererDemo()
		{
		}

		CullFaceOpenGLRendererDemo::~CullFaceOpenGLRendererDemo()
		{
		}

		void CullFaceOpenGLRendererDemo::advance()
		{
			renderingEngine.advance(shared_ptr<EngineInput>());
		}

		void CullFaceOpenGLRendererDemo::dispose()
		{
			renderingEngine.destroy();
		}

		shared_ptr<Camera> CullFaceOpenGLRendererDemo::getCamera()
		{
			return (renderingEngine.getCamera());
		}

		string CullFaceOpenGLRendererDemo::getDescription()
		{
			return ("Renders the front side of each face green and the back side of each face red.");
		}

		string CullFaceOpenGLRendererDemo::getTitle()
		{
			return ("CullFaceOpenGLRenderer");
		}

		void CullFaceOpenGLRendererDemo::init()
		{
			unique_ptr<RGBAColourVector<> > clearingColour(MathFactory::getInstance().createRGBAColourVector());
			clearingColour->setRed(0.95f);
			clearingColour->setGreen(0.95f);
			clearingColour->setBlue(0.95f);
			renderingEngine.setClearingColour(move(clearingColour));

			shared_ptr<Scene> scene(SceneFactory::getInstance().createScene());
			shared_ptr<Node> sceneRoot(SceneFactory::getInstance().createNode());
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

			shared_ptr<CullFaceOpenGLRenderer> renderer(new CullFaceOpenGLRenderer);
			renderingEngine.addRenderer(renderer);

			renderingEngine.init();
		}
	}
}
