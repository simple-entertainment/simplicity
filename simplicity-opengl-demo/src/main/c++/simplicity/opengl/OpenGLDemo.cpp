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

#include <simplicity/math/MathFactory.h>
#include <simplicity/scene/SceneFactory.h>

#include <simplicity/opengl/model/shape/GLUCapsule.h>
#include <simplicity/opengl/model/shape/GLUCylinder.h>
#include <simplicity/opengl/model/shape/GLUSphere.h>
#include <simplicity/opengl/model/shape/GLUTorus.h>
#include <simplicity/opengl/rendering/SimpleOpenGLCamera.h>
#include <simplicity/opengl/rendering/SimpleOpenGLLight.h>

#include "OpenGLDemo.h"

using namespace boost::math::constants;
using namespace std;

namespace simplicity
{
	namespace opengl
	{
		shared_ptr<Camera> OpenGLDemo::addStandardCamera(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleOpenGLCamera> camera(new SimpleOpenGLCamera);
			shared_ptr<Node> cameraNode(SceneFactory::getInstance().createNode());
			cameraRootNode = SceneFactory::getInstance().createNode();

			unique_ptr<TranslationVector<> > cameraTranslation(MathFactory::getInstance().createTranslationVector());
			cameraTranslation->setZ(-20.0f);
			cameraNode->getTransformation().translate(*cameraTranslation);

			unique_ptr<TranslationVector<> > cameraRotationAxis(MathFactory::getInstance().createTranslationVector());
			cameraRotationAxis->setY(1.0f);
			cameraNode->getTransformation().rotate(pi<float>(), *cameraRotationAxis);

			camera->setNode(cameraNode);

			unique_ptr<TranslationVector<> > rootRotationAxis(MathFactory::getInstance().createTranslationVector());
			rootRotationAxis->setX(-0.5f);
			rootRotationAxis->setY(-0.5f);
			cameraRootNode->getTransformation().rotate(pi<float>() / 8.0f, *rootRotationAxis);

			cameraRootNode->addChild(cameraNode);
			parentNode->addChild(cameraRootNode);

			return camera;
		}

		void OpenGLDemo::addStandardCapsule(shared_ptr<Node> parentNode)
		{
			shared_ptr<ModelNode> capsuleNode(SceneFactory::getInstance().createModelNode());

			unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
			translation->setX(-3.0f);
			translation->setY(3.0f);
			capsuleNode->getTransformation().translate(*translation);

			shared_ptr<GLUCapsule> capsule(new GLUCapsule);

			unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
			colour->setRed(0.75f);
			capsule->setColour(move(colour));

			capsuleNode->setModel(capsule);
			parentNode->addChild(capsuleNode);
		}

		void OpenGLDemo::addStandardCylinder(shared_ptr<Node> parentNode)
		{
			shared_ptr<ModelNode> cylinderNode(SceneFactory::getInstance().createModelNode());

			unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
			translation->setY(3.0f);
			cylinderNode->getTransformation().translate(*translation);

			shared_ptr<GLUCylinder> cylinder(new GLUCylinder);

			unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
			colour->setGreen(0.75f);
			cylinder->setColour(move(colour));

			cylinderNode->setModel(cylinder);
			parentNode->addChild(cylinderNode);
		}

		shared_ptr<Light> OpenGLDemo::addStandardLight(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleOpenGLLight> light(new SimpleOpenGLLight);

			unique_ptr<RGBAColourVector<> > ambientLight(MathFactory::getInstance().createRGBAColourVector());
			ambientLight->setRed(0.25f);
			ambientLight->setGreen(0.25f);
			ambientLight->setBlue(0.25f);
			light->setAmbientLight(move(ambientLight));

			unique_ptr<RGBAColourVector<> > diffuseLight(MathFactory::getInstance().createRGBAColourVector());
			diffuseLight->setRed(0.25f);
			diffuseLight->setGreen(0.25f);
			diffuseLight->setBlue(0.25f);
			light->setDiffuseLight(move(diffuseLight));

			unique_ptr<RGBAColourVector<> > specularLight(MathFactory::getInstance().createRGBAColourVector());
			specularLight->setRed(0.1f);
			specularLight->setGreen(0.1f);
			specularLight->setBlue(0.1f);
			light->setSpecularLight(move(specularLight));

			shared_ptr<Node> lightNode(SceneFactory::getInstance().createNode());

			unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
			translation->setZ(20.0f);
			lightNode->getTransformation().translate(*translation);

			light->setNode(lightNode);
			parentNode->addChild(lightNode);

			return light;
		}

		void OpenGLDemo::addStandardSphere(shared_ptr<Node> parentNode)
		{
			shared_ptr<ModelNode> sphereNode(SceneFactory::getInstance().createModelNode());

			unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
			translation->setX(3.0f);
			translation->setY(3.0f);
			sphereNode->getTransformation().translate(*translation);

			shared_ptr<GLUSphere> sphere(new GLUSphere);

			unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
			colour->setBlue(0.75f);
			sphere->setColour(move(colour));

			sphereNode->setModel(sphere);
			parentNode->addChild(sphereNode);
		}

		void OpenGLDemo::addStandardTorus(shared_ptr<Node> parentNode)
		{
			shared_ptr<ModelNode> torusNode(SceneFactory::getInstance().createModelNode());

			unique_ptr<TranslationVector<> > translation(MathFactory::getInstance().createTranslationVector());
			translation->setY(-2.0f);
			torusNode->getTransformation().translate(*translation);

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
				unique_ptr<TranslationVector<> > yAxis(MathFactory::getInstance().createTranslationVector());
				yAxis->setY(1.0f);
				cameraRootNode->getTransformation().rotate(angleX / pi<float>(), *yAxis);

				unique_ptr<TranslationVector<> > xAxis(MathFactory::getInstance().createTranslationVector());
				xAxis->setX(1.0f);
				cameraRootNode->getTransformation().rotate(angleY / pi<float>(), *xAxis);
			}
		}
	}
}

