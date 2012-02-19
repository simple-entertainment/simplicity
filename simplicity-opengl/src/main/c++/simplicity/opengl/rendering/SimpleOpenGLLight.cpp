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

#include <simplicity/math/MathFactory.h>
#include <simplicity/SEInvalidOperationException.h>

#include "SimpleOpenGLLight.h"

using namespace std;

namespace simplicity
{
	namespace opengl
	{
		log4cpp::Category& SimpleOpenGLLight::logger = log4cpp::Category::getInstance(
			"simplicity_opengl::SimpleOpenGLLight");

		SimpleOpenGLLight::SimpleOpenGLLight() :
			ambientLight(MathFactory::getInstance().createRGBAColourVector()), diffuseLight(
				MathFactory::getInstance().createRGBAColourVector()), initialised(false), lightingMode(Light::SCENE), specularLight(
				MathFactory::getInstance().createRGBAColourVector())
		{
		}

		SimpleOpenGLLight::~SimpleOpenGLLight()
		{
		}

		void SimpleOpenGLLight::apply()
		{
			if (!initialised)
			{
				init();
			}

			if (lightingMode == Light::SHADED)
			{
				unique_ptr<TranslationVector<> > vector(MathFactory::getInstance().createTranslationVector());
				glLightfv(GL_LIGHT0, GL_POSITION, vector->getData().data());
			}
			else if (lightingMode == Light::SCENE)
			{
				glLightfv(GL_LIGHT0, GL_POSITION, getTransformation().getTranslation()->getData().data());
				glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight->getData().data());
				glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight->getData().data());
				glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight->getData().data());
			}
		}

		RGBAColourVector<>& SimpleOpenGLLight::getAmbientLight() const
		{
			return *ambientLight;
		}

		RGBAColourVector<>& SimpleOpenGLLight::getDiffuseLight() const
		{
			return *diffuseLight;
		}

		Light::LightingMode SimpleOpenGLLight::getLightingMode() const
		{
			return lightingMode;
		}

		std::shared_ptr<Node> SimpleOpenGLLight::getNode() const
		{
			return node;
		}

		RGBAColourVector<>& SimpleOpenGLLight::getSpecularLight() const
		{
			return *specularLight;
		}

		const TransformationMatrix<>& SimpleOpenGLLight::getTransformation() const
		{
			transformation = MathFactory::getInstance().createTransformationMatrix();

			if (node.get() == NULL)
			{
				return *transformation;
			}

			transformation->setData(node->getAbsoluteTransformation()->getData());

			try
			{
				transformation->invert();
			}
			catch (SEInvalidOperationException& e)
			{
				logger.error("Failed to invert the transformation: s%", e.what());
			}

			return *transformation;
		}

		void SimpleOpenGLLight::init()
		{
			if (lightingMode == Light::SOLID)
			{
				glDisable(GL_LIGHTING);
				glDisable(GL_COLOR_MATERIAL);
				glDisable(GL_LIGHT0);
			}
			else if (lightingMode == Light::SHADED)
			{
				glEnable(GL_LIGHTING);
				glEnable(GL_COLOR_MATERIAL);
				glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

				unique_ptr<RGBAColourVector<> > colour(MathFactory::getInstance().createRGBAColourVector());
				colour->setRed(0.5f);
				colour->setGreen(0.5f);
				colour->setBlue(0.5f);
				glLightfv(GL_LIGHT0, GL_AMBIENT, colour->getData().data());
				glLightfv(GL_LIGHT0, GL_DIFFUSE, colour->getData().data());
				glLightfv(GL_LIGHT0, GL_SPECULAR, colour->getData().data());

				glEnable(GL_LIGHT0);
			}
			else if (lightingMode == Light::SCENE)
			{
				glEnable(GL_LIGHTING);
				glEnable(GL_COLOR_MATERIAL);
				glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
				glEnable(GL_LIGHT0);
			}

			initialised = true;
		}

		bool SimpleOpenGLLight::isInitialised() const
		{
			return (initialised);
		}

		void SimpleOpenGLLight::setAmbientLight(unique_ptr<RGBAColourVector<> > ambientLight)
		{
			this->ambientLight = move(ambientLight);
		}

		void SimpleOpenGLLight::setDiffuseLight(unique_ptr<RGBAColourVector<> > diffuseLight)
		{
			this->diffuseLight = move(diffuseLight);
		}

		void SimpleOpenGLLight::setInitialised(const bool isInitialised)
		{
			this->initialised = isInitialised;
		}

		void SimpleOpenGLLight::setLightingMode(const LightingMode lightingMode)
		{
			this->lightingMode = lightingMode;

			initialised = false;
		}

		void SimpleOpenGLLight::setNode(std::shared_ptr<Node> newNode)
		{
			this->node = newNode;
		}

		void SimpleOpenGLLight::setSpecularLight(unique_ptr<RGBAColourVector<> > specularLight)
		{
			this->specularLight = move(specularLight);
		}
	}
}
