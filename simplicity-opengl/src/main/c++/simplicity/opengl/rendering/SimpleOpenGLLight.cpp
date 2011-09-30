/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/smart_ptr.hpp>

#include <GL/glew.h>

#include <simplicity/vector/SimpleRGBAColourVector4.h>
#include <simplicity/vector/SimpleTransformationMatrix44.h>
#include <simplicity/vector/SimpleTranslationVector4.h>

#include "SimpleOpenGLLight.h"

using namespace boost;

namespace simplicity
{
  namespace opengl
  {
    log4cpp::Category& SimpleOpenGLLight::fLogger = log4cpp::Category::getInstance("simplicity_opengl::SimpleOpenGLLight");

    SimpleOpenGLLight::SimpleOpenGLLight() :
      fAmbientLight(new SimpleRGBAColourVector4<float> ), fDiffuseLight(new SimpleRGBAColourVector4<float> ),
          fInitialised(false), fLightingMode(Light::SCENE), fSpecularLight(new SimpleRGBAColourVector4<float> )
    {
    }

    SimpleOpenGLLight::~SimpleOpenGLLight()
    {
    }

    void
    SimpleOpenGLLight::apply()
    {
      if (!fInitialised)
      {
        init();
      }

      if (fLightingMode == Light::SHADED)
      {
        SimpleTranslationVector4<float> origin;
        glLightfv(GL_LIGHT0, GL_POSITION, origin.getRawData());
      }
      else if (fLightingMode == Light::SCENE)
      {
        glLightfv(GL_LIGHT0, GL_POSITION, getTransformation().getTranslation()->getRawData());
        glLightfv(GL_LIGHT0, GL_AMBIENT, fAmbientLight->getRawData());
        glLightfv(GL_LIGHT0, GL_DIFFUSE, fDiffuseLight->getRawData());
        glLightfv(GL_LIGHT0, GL_SPECULAR, fSpecularLight->getRawData());
      }
    }

    RGBAColourVector<float>&
    SimpleOpenGLLight::getAmbientLight() const
    {
      return (*fAmbientLight);
    }

    RGBAColourVector<float>&
    SimpleOpenGLLight::getDiffuseLight() const
    {
      return (*fDiffuseLight);
    }

    Light::LightingMode
    SimpleOpenGLLight::getLightingMode() const
    {
      return (fLightingMode);
    }

    shared_ptr<Node>
    SimpleOpenGLLight::getNode() const
    {
      return (fNode);
    }

    RGBAColourVector<float>&
    SimpleOpenGLLight::getSpecularLight() const
    {
      return (*fSpecularLight);
    }

    const TransformationMatrix<float>&
    SimpleOpenGLLight::getTransformation() const
    {
      if (!fNode)
      {
        fTransformation.reset(new SimpleTransformationMatrix44<float> );
        return (*fTransformation);
      }

      fTransformation.reset(
          new SimpleTransformationMatrix44<float> (
              dynamic_cast<const SimpleMatrix44<float>&> (fNode->getAbsoluteTransformation()).getData()));

      try
      {
        fTransformation->invert();
      }
      catch (SEInvalidOperationException& e)
      {
        fLogger.error("Failed to invert the transformation: s%", e.what());
      }

      return (*fTransformation);
    }

    void
    SimpleOpenGLLight::init()
    {
      if (fLightingMode == Light::SOLID)
      {
        glDisable(GL_LIGHTING);
        glDisable(GL_COLOR_MATERIAL);
        glDisable(GL_LIGHT0);
      }
      else if (fLightingMode == Light::SHADED)
      {
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

        SimpleRGBAColourVector4<float> colour;
        colour.setRed(0.5f);
        colour.setGreen(0.5f);
        colour.setBlue(0.5f);
        glLightfv(GL_LIGHT0, GL_AMBIENT, colour.getRawData());
        glLightfv(GL_LIGHT0, GL_DIFFUSE, colour.getRawData());
        glLightfv(GL_LIGHT0, GL_SPECULAR, colour.getRawData());

        glEnable(GL_LIGHT0);
      }
      else if (fLightingMode == Light::SCENE)
      {
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glEnable(GL_LIGHT0);
      }

      fInitialised = true;
    }

    bool
    SimpleOpenGLLight::isInitialised() const
    {
      return (fInitialised);
    }

    void
    SimpleOpenGLLight::setAmbientLight(shared_ptr<RGBAColourVector<float> > ambientLight)
    {
      fAmbientLight = ambientLight;
    }

    void
    SimpleOpenGLLight::setDiffuseLight(shared_ptr<RGBAColourVector<float> > diffuseLight)
    {
      fDiffuseLight = diffuseLight;
    }

    void
    SimpleOpenGLLight::setInitialised(const bool isInitialised)
    {
      fInitialised = isInitialised;
    }

    void
    SimpleOpenGLLight::setLightingMode(const LightingMode lightingMode)
    {
      fLightingMode = lightingMode;

      fInitialised = false;
    }

    void
    SimpleOpenGLLight::setNode(shared_ptr<Node> newNode)
    {
      fNode = newNode;
    }

    void
    SimpleOpenGLLight::setSpecularLight(shared_ptr<RGBAColourVector<float> > specularLight)
    {
      fSpecularLight = specularLight;
    }
  }
}
