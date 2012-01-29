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

#include "CullFaceOpenGLRenderer.h"

namespace simplicity
{
  namespace opengl
  {
    CullFaceOpenGLRenderer::CullFaceOpenGLRenderer() :
      fBackFaceColour(new SimpleRGBAColourVector4<> (1.0f, 0.0f, 0.0f, 1.0f)),
          fFrontFaceColour(new SimpleRGBAColourVector4<> (0.0f, 1.0f, 0.0f, 1.0f))
    {
    }

    CullFaceOpenGLRenderer::~CullFaceOpenGLRenderer()
    {
    }

    void
    CullFaceOpenGLRenderer::dispose()
    {
      if (!fCullFace)
      {
        glDisable(GL_CULL_FACE);
      }

      if (fFrontFace == GL_CW)
      {
        glFrontFace(GL_CW);
      }
      else
      {
        glFrontFace(GL_CCW);
      }
    }

    std::shared_ptr<RGBAColourVector<> >
    CullFaceOpenGLRenderer::getBackFaceColour()
    {
      return (fBackFaceColour);
    }

    Renderer::DrawingMode
    CullFaceOpenGLRenderer::getDrawingMode() const
    {
      return (fDrawingMode);
    }

    std::shared_ptr<RGBAColourVector<> >
    CullFaceOpenGLRenderer::getFrontFaceColour()
    {
      return (fFrontFaceColour);
    }

    void
    CullFaceOpenGLRenderer::init()
    {
      glGetBooleanv(GL_CULL_FACE, &fCullFace);
      glEnable(GL_CULL_FACE);

      glGetIntegerv(GL_FRONT_FACE, &fFrontFace);
    }

    void
    CullFaceOpenGLRenderer::renderModel(const Model& model)
    {
      // Prepare for rendering of the back sides.
      if (fFrontFace == GL_CW)
      {
        glFrontFace(GL_CCW);
      }
      else
      {
        glFrontFace(GL_CW);
      }
      fRenderer.setColour(fBackFaceColour);

      fRenderer.init();
      fRenderer.renderModel(model);

      // Prepare for rendering of the front sides.
      if (fFrontFace == GL_CW)
      {
        glFrontFace(GL_CW);
      }
      else
      {
        glFrontFace(GL_CCW);
      }
      fRenderer.setColour(fFrontFaceColour);

      fRenderer.init();
      fRenderer.renderModel(model);
    }

    void
    CullFaceOpenGLRenderer::setBackFaceColour(std::shared_ptr<RGBAColourVector<> > backFaceColour)
    {
      fBackFaceColour = backFaceColour;
    }

    void
    CullFaceOpenGLRenderer::setDrawingMode(const DrawingMode mode)
    {
      fDrawingMode = mode;
    }

    void
    CullFaceOpenGLRenderer::setFrontFaceColour(std::shared_ptr<RGBAColourVector<> > frontFaceColour)
    {
      fFrontFaceColour = frontFaceColour;
    }
  }
}
