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
#include <GL/glew.h>
#include <GL/glut.h>

#include <boost/math/constants/constants.hpp>

#include <simplicity/math/MathFactory.h>
#include <simplicity/model/ModelFactory.h>
#include <simplicity/scene/SceneFactory.h>
#include <simplicity/Simplicity.h>

#include <simplicity/opengl/model/OpenGLText.h>
#include <simplicity/opengl/rendering/SimpleOpenGLCamera.h>
#include <simplicity/opengl/rendering/SimpleOpenGLLight.h>

#include <simplicity/freeglut/FreeglutEvents.h>
#include <simplicity/freeglut/input/FreeglutInputEvent.h>

#include "OpenGLDemo.h"

using namespace boost::math::constants;
using namespace simplicity::freeglut;
using namespace std;

namespace simplicity
{
	namespace opengl
	{
		OpenGLDemo::OpenGLDemo() :
			modelsRoot(SceneFactory::getInstance().createNode())
		{
		}

		shared_ptr<Camera> OpenGLDemo::addStandardCamera(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleOpenGLCamera> camera(new SimpleOpenGLCamera);

			shared_ptr<Node> node(SceneFactory::getInstance().createNode());
			camera->setNode(node);

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setZ(15.0f);
			node->getTransformation().translate(*location);

			parentNode->addChild(node);

			return camera;
		}

		shared_ptr<Light> OpenGLDemo::addStandardLight(shared_ptr<Node> parentNode)
		{
			shared_ptr<SimpleOpenGLLight> light(new SimpleOpenGLLight);

			shared_ptr<Node> node(SceneFactory::getInstance().createNode());
			light->setNode(node);

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setZ(15.0f);
			node->getTransformation().translate(*location);

			unique_ptr<ColourVector<> > ambientLight(MathFactory::getInstance().createColourVector());
			ambientLight->setRed(0.25f);
			ambientLight->setGreen(0.25f);
			ambientLight->setBlue(0.25f);
			light->setAmbientLight(move(ambientLight));

			unique_ptr<ColourVector<> > diffuseLight(MathFactory::getInstance().createColourVector());
			diffuseLight->setRed(0.5f);
			diffuseLight->setGreen(0.5f);
			diffuseLight->setBlue(0.5f);
			light->setDiffuseLight(move(diffuseLight));

			unique_ptr<ColourVector<> > specularLight(MathFactory::getInstance().createColourVector());
			specularLight->setRed(0.5f);
			specularLight->setGreen(0.5f);
			specularLight->setBlue(0.5f);
			light->setSpecularLight(move(specularLight));

			parentNode->addChild(node);

			return light;
		}

		vector<shared_ptr<Model> > OpenGLDemo::createDescription()
		{
			vector <shared_ptr<Model> > description;
			string text(getDescription());

			unsigned int lineNum = 0;
			while (text.find('\n') != string::npos)
			{
				description.push_back(createDescriptionLine(text.substr(0, text.find('\n')), lineNum));
				text = text.substr(text.find('\n') + 1);
				lineNum++;
			}
			description.push_back(createDescriptionLine(text, lineNum));

			return description;
		}

		shared_ptr<Model> OpenGLDemo::createDescriptionLine(const string& line, const unsigned int lineNum)
		{
			shared_ptr<Text> descriptionLine(ModelFactory::getInstance().createText());

			unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
			colour->setRed(1.0f);
			colour->setGreen(1.0f);
			colour->setBlue(1.0f);
			descriptionLine->setColour(move(colour));

			descriptionLine->setText(line);

			shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
			descriptionLine->setNode(node);
			node->setModel(descriptionLine);

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setX(-3.6f);
			location->setY(2.4f - (lineNum / 10.0f));
			node->getTransformation().setTranslation(*location);

			return descriptionLine;
		}

		shared_ptr<Model> OpenGLDemo::createStandardCapsule()
		{
			shared_ptr<Capsule> capsule(ModelFactory::getInstance().createCapsule());

			unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
			colour->setRed(0.75f);
			capsule->setColour(move(colour));

			shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
			capsule->setNode(node);
			node->setModel(capsule);

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setX(-3.0f);
			location->setY(3.0f);
			node->getTransformation().translate(*location);

			return capsule;
		}

		shared_ptr<Model> OpenGLDemo::createStandardCylinder()
		{
			shared_ptr<Cylinder> cylinder(ModelFactory::getInstance().createCylinder());

			unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
			colour->setGreen(0.75f);
			cylinder->setColour(move(colour));

			shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
			cylinder->setNode(node);
			node->setModel(cylinder);

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setY(3.0f);
			node->getTransformation().translate(*location);

			return cylinder;
		}

		shared_ptr<Model> OpenGLDemo::createStandardSphere()
		{
			shared_ptr<Sphere> sphere(ModelFactory::getInstance().createSphere());

			unique_ptr<ColourVector<> > colour(MathFactory::getInstance().createColourVector());
			colour->setBlue(0.75f);
			sphere->setColour(move(colour));

			shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
			sphere->setNode(node);
			node->setModel(sphere);

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setX(3.0f);
			location->setY(3.0f);
			node->getTransformation().translate(*location);

			return sphere;
		}

		shared_ptr<Torus> OpenGLDemo::createStandardTorus()
		{
			shared_ptr<Torus> torus(ModelFactory::getInstance().createTorus());

			shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
			torus->setNode(node);
			node->setModel(torus);

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setY(-2.0f);
			node->getTransformation().translate(*location);

			return torus;
		}

		shared_ptr<Model> OpenGLDemo::createTitle()
		{
			shared_ptr<Text> title(ModelFactory::getInstance().createText());

			dynamic_cast<OpenGLText*>(title.get())->setFont(GLUT_BITMAP_HELVETICA_18);
			title->setText(getTitle());

			shared_ptr<ModelNode> node(SceneFactory::getInstance().createModelNode());
			title->setNode(node);
			node->setModel(title);

			unique_ptr<TranslationVector<> > location(MathFactory::getInstance().createTranslationVector());
			location->setX(-3.6f);
			location->setY(2.6f);
			node->getTransformation().setTranslation(*location);

			return title;
		}

		void OpenGLDemo::dispose()
		{
			Simplicity::deregisterObserver(FREEGLUT_MOTION_EVENT, bind(&OpenGLDemo::onMotion, this, placeholders::_1));

			onDispose();
		}

		shared_ptr<Node> OpenGLDemo::getModelsRoot()
		{
			return modelsRoot;
		}

		void OpenGLDemo::init()
		{
			Simplicity::registerObserver(FREEGLUT_MOTION_EVENT, bind(&OpenGLDemo::onMotion, this, placeholders::_1));

			onInit();
		}

		void OpenGLDemo::onMotion(const boost::any data)
		{
			const FreeglutInputEvent& event(boost::any_cast < FreeglutInputEvent > (data));

			float angleX = (mouseX - event.x) / 10.0f;
			float angleY = (event.y - mouseY) / 10.0f;
			mouseX = event.x;
			mouseY = event.y;

			if (modelsRoot.get() != NULL)
			{
				unique_ptr<TranslationVector<> > yAxis(MathFactory::getInstance().createTranslationVector());
				yAxis->setY(1.0f);
				modelsRoot->getTransformation().rotate(angleX / pi<float>(), *yAxis);

				unique_ptr<TranslationVector<> > xAxis(MathFactory::getInstance().createTranslationVector());
				xAxis->setX(1.0f);
				modelsRoot->getTransformation().rotate(angleY / pi<float>(), *xAxis);
			}
		}
	}
}

