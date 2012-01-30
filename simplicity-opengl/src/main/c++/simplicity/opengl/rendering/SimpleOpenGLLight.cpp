/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include <simplicity/math/SimpleRGBAColourVector4.h>
#include <simplicity/math/SimpleTransformationMatrix44.h>
#include <simplicity/math/SimpleTranslationVector4.h>

#include "SimpleOpenGLLight.h"

using namespace std;

namespace simplicity
{
  namespace opengl
  {
    log4cpp::Category& SimpleOpenGLLight::fLogger = log4cpp::Category::getInstance("simplicity_opengl::SimpleOpenGLLight");

    SimpleOpenGLLight::SimpleOpenGLLight() :
      fAmbientLight(new SimpleRGBAColourVector4<> ), fDiffuseLight(new SimpleRGBAColourVector4<> ),
          fInitialised(false), fLightingMode(Light::SCENE), fSpecularLight(new SimpleRGBAColourVector4<> )
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
        SimpleTranslationVector4<> origin;
        glLightfv(GL_LIGHT0, GL_POSITION, origin.getData().data());
      }
      else if (fLightingMode == Light::SCENE)
      {
        glLightfv(GL_LIGHT0, GL_POSITION, getTransformation().getTranslation()->getData().data());
        glLightfv(GL_LIGHT0, GL_AMBIENT, fAmbientLight->getData().data());
        glLightfv(GL_LIGHT0, GL_DIFFUSE, fDiffuseLight->getData().data());
        glLightfv(GL_LIGHT0, GL_SPECULAR, fSpecularLight->getData().data());
      }
    }

    RGBAColourVector<>&
    SimpleOpenGLLight::getAmbientLight() const
    {
      return (*fAmbientLight);
    }

    RGBAColourVector<>&
    SimpleOpenGLLight::getDiffuseLight() const
    {
      return (*fDiffuseLight);
    }

    Light::LightingMode
    SimpleOpenGLLight::getLightingMode() const
    {
      return (fLightingMode);
    }

    std::shared_ptr<Node>
    SimpleOpenGLLight::getNode() const
    {
      return (fNode);
    }

    RGBAColourVector<>&
    SimpleOpenGLLight::getSpecularLight() const
    {
      return (*fSpecularLight);
    }

    const TransformationMatrix<>&
    SimpleOpenGLLight::getTransformation() const
    {
      if (!fNode)
      {
        fTransformation.reset(new SimpleTransformationMatrix44<> );
        return (*fTransformation);
      }

      fTransformation.reset(new SimpleTransformationMatrix44<> (fNode->getAbsoluteTransformation()->getData()));

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

        SimpleRGBAColourVector4<> colour;
        colour.setRed(0.5f);
        colour.setGreen(0.5f);
        colour.setBlue(0.5f);
        glLightfv(GL_LIGHT0, GL_AMBIENT, colour.getData().data());
        glLightfv(GL_LIGHT0, GL_DIFFUSE, colour.getData().data());
        glLightfv(GL_LIGHT0, GL_SPECULAR, colour.getData().data());

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
    SimpleOpenGLLight::setAmbientLight(std::unique_ptr<RGBAColourVector<> > ambientLight)
    {
      fAmbientLight = move(ambientLight);
    }

    void
    SimpleOpenGLLight::setDiffuseLight(std::unique_ptr<RGBAColourVector<> > diffuseLight)
    {
      fDiffuseLight = move(diffuseLight);
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
    SimpleOpenGLLight::setNode(std::shared_ptr<Node> newNode)
    {
      fNode = newNode;
    }

    void
    SimpleOpenGLLight::setSpecularLight(std::unique_ptr<RGBAColourVector<> > specularLight)
    {
      fSpecularLight = move(specularLight);
    }
  }
}
