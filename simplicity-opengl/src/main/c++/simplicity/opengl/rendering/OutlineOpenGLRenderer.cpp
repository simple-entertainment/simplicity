/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include "OutlineOpenGLRenderer.h"

namespace simplicity
{
  namespace opengl
  {
	  const float OutlineOpenGLRenderer::DEFAULT_OUTLINE_WIDTH = 3.0f;

    OutlineOpenGLRenderer::OutlineOpenGLRenderer() :
      fMonoColour(new MonoColourOpenGLRenderer), fOutlineWidth(DEFAULT_OUTLINE_WIDTH)
    {
      fAlwaysStencil.reset(new AlwaysStencilOpenGLRenderer(fMonoColour));
      fNotEqualStencil.reset(new NotEqualStencilOpenGLRenderer(fMonoColour));
    }

    OutlineOpenGLRenderer::~OutlineOpenGLRenderer()
    {
    }

    void
    OutlineOpenGLRenderer::dispose()
    {
    }

    Renderer::DrawingMode
    OutlineOpenGLRenderer::getDrawingMode() const
    {
      return (fMonoColour->getDrawingMode());
    }

    std::shared_ptr<RGBAColourVector<> >
    OutlineOpenGLRenderer::getOutlineColour() const
    {
      return (fMonoColour->getColour());
    }

    float
    OutlineOpenGLRenderer::getOutlineWidth() const
    {
      return (fOutlineWidth);
    }

    void
    OutlineOpenGLRenderer::init()
    {
    }

    void
    OutlineOpenGLRenderer::renderModel(const Model& model)
    {
      unsigned char lightingEnabledParams;
      glGetBooleanv(GL_LIGHTING, &lightingEnabledParams);
      unsigned char cullFaceEnabledParams;
      glGetBooleanv(GL_CULL_FACE, &cullFaceEnabledParams);

      // Prepare for setting the stencil.
      glDrawBuffer(GL_NONE);
      if (cullFaceEnabledParams)
      {
        glDisable(GL_CULL_FACE);
      }

      fAlwaysStencil->init();
      fAlwaysStencil->renderModel(model);
      fAlwaysStencil->dispose();

      // Restore rendering environment settings.
      glDrawBuffer(GL_BACK);

      // Prepare for rendering the outline.

      if (lightingEnabledParams)
      {
        glDisable(GL_LIGHTING);
      }

      // If outlines need to be drawn for the edges or faces, draw them.
      if (getDrawingMode() != VERTICES)
      {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(fOutlineWidth);

        fNotEqualStencil->init();
        fNotEqualStencil->renderModel(model);
        fNotEqualStencil->dispose();

        glLineWidth(1.0f);
      }

      // Draw outlines for the vertices (if edges or faces are being drawn this just gives nice rounded corners).
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
      glPointSize(fOutlineWidth);

      fNotEqualStencil->init();
      fNotEqualStencil->renderModel(model);
      fNotEqualStencil->dispose();

      glPointSize(1.0f);

      // Restore rendering environment settings.
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      if (lightingEnabledParams)
      {
        glEnable(GL_LIGHTING);
      }
      if (cullFaceEnabledParams)
      {
        glEnable(GL_CULL_FACE);
      }
    }

    void
    OutlineOpenGLRenderer::setDrawingMode(const DrawingMode mode)
    {
      fMonoColour->setDrawingMode(mode);
    }

    void
    OutlineOpenGLRenderer::setOutlineColour(std::shared_ptr<RGBAColourVector<> > outlineColour)
    {
      fMonoColour->setColour(outlineColour);
    }

    void
    OutlineOpenGLRenderer::setOutlineWidth(const float outlineWidth)
    {
      fOutlineWidth = outlineWidth;
    }
  }
}
