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
#include <GL/glew.h>
#include <GL/glut.h>

#include <boost/math/constants/constants.hpp>

#include <simplicity/math/SimpleRGBAColourVector4.h>
#include <simplicity/math/SimpleTranslationVector4.h>
#include <simplicity/scene/model/SimpleModelNode.h>
#include <simplicity/scene/SimpleNode.h>

#include <simplicity/opengl/model/shape/GLUCapsule.h>
#include <simplicity/opengl/model/shape/GLUCylinder.h>
#include <simplicity/opengl/model/shape/GLUSphere.h>
#include <simplicity/opengl/model/shape/GLUTorus.h>
#include <simplicity/opengl/rendering/SimpleOpenGLCamera.h>
#include <simplicity/opengl/rendering/SimpleOpenGLLight.h>

#include "OpenGLDemo.h"

using namespace boost::math::constants;

namespace simplicity
{
	namespace opengl
	{
		shared_ptr<Camera> OpenGLDemo::addStandardCamera(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleOpenGLCamera> camera(new SimpleOpenGLCamera);
			shared_ptr<SimpleNode> cameraNode(new SimpleNode);
			cameraRootNode.reset(new SimpleNode);
			cameraNode->getTransformation().translate(SimpleTranslationVector4<float>(0.0f, 0.0f, -20.0f, 1.0f));
			cameraNode->getTransformation().rotate(pi<float>(),
				SimpleTranslationVector4<float>(0.0f, 1.0f, 0.0f, 1.0f));
			camera->setNode(cameraNode);
			cameraRootNode->getTransformation().rotate(pi<float>() / 8.0f,
				SimpleTranslationVector4<float>(-0.5f, -0.5f, 0.0f, 1.0f));
			cameraRootNode->addChild(cameraNode);
			parentNode->addChild(cameraRootNode);

			return (camera);
		}

		void OpenGLDemo::addStandardCapsule(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleModelNode> capsuleNode(new SimpleModelNode);
			capsuleNode->getTransformation().translate(SimpleTranslationVector4<float>(-3.0f, 3.0f, 0.0f, 1.0f));
			shared_ptr<GLUCapsule> capsule(new GLUCapsule);
			capsule->setColour(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.75f, 0.0f, 0.0f, 1.0f)));
			capsuleNode->setModel(capsule);
			parentNode->addChild(capsuleNode);
		}

		void OpenGLDemo::addStandardCylinder(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleModelNode> cylinderNode(new SimpleModelNode);
			cylinderNode->getTransformation().translate(SimpleTranslationVector4<float>(0.0f, 3.0f, 0.0f, 1.0f));
			shared_ptr<GLUCylinder> cylinder(new GLUCylinder);
			cylinder->setColour(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.0f, 0.75f, 0.0f, 1.0f)));
			cylinderNode->setModel(cylinder);
			parentNode->addChild(cylinderNode);
		}

		shared_ptr<Light> OpenGLDemo::addStandardLight(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleOpenGLLight> light(new SimpleOpenGLLight);
			light->setAmbientLight(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.25f, 0.25f, 0.25f, 1.0f)));
			light->setDiffuseLight(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.25f, 0.25f, 0.25f, 1.0f)));
			light->setSpecularLight(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.1f, 0.1f, 0.1f, 1.0f)));
			shared_ptr<SimpleNode> lightNode(new SimpleNode);
			lightNode->getTransformation().translate(SimpleTranslationVector4<float>(0.0f, 0.0f, 20.0f, 1.0f));
			light->setNode(lightNode);
			parentNode->addChild(lightNode);

			return (light);
		}

		void OpenGLDemo::addStandardSphere(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleModelNode> sphereNode(new SimpleModelNode);
			sphereNode->getTransformation().translate(SimpleTranslationVector4<float>(3.0f, 3.0f, 0.0f, 1.0f));
			shared_ptr<GLUSphere> sphere(new GLUSphere);
			sphere->setColour(
				shared_ptr < SimpleRGBAColourVector4<float>
					> (new SimpleRGBAColourVector4<float>(0.0f, 0.0f, 0.75f, 1.0f)));
			sphereNode->setModel(sphere);
			parentNode->addChild(sphereNode);
		}

		void OpenGLDemo::addStandardTorus(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleModelNode> torusNode(new SimpleModelNode);
			torusNode->getTransformation().translate(SimpleTranslationVector4<float>(0.0f, -2.0f, 0.0f, 1.0f));
			shared_ptr<GLUTorus> torus(new GLUTorus);
			torusNode->setModel(torus);
			parentNode->addChild(torusNode);
		}

		void OpenGLDemo::onMouseButton(const int button, const int state, const int x, const int y)
		{
		}

		void OpenGLDemo::onMouseMotion(const int x, const int y)
		{
			float angleX = (mouseX - x) / 10.0f;
			float angleY = (y - mouseY) / 10.0f;
			mouseX = x;
			mouseY = y;

			if (cameraRootNode.get())
			{
				cameraRootNode->getTransformation().rotate(angleX / pi<float>(),
					SimpleTranslationVector4<float>(0.0f, 1.0f, 0.0f, 1.0f));
				cameraRootNode->getTransformation().rotate(angleY / pi<float>(),
					SimpleTranslationVector4<float>(1.0f, 0.0f, 0.0f, 1.0f));
			}
		}
	}
}

