/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include "AlwaysStencilOpenGLRenderer.h"

using namespace std;

namespace simplicity
{
  namespace opengl
  {
    AlwaysStencilOpenGLRenderer::AlwaysStencilOpenGLRenderer(shared_ptr<Renderer> renderer) :
      RendererDecorator(renderer), fStencilValue(1)
    {
    }

    AlwaysStencilOpenGLRenderer::~AlwaysStencilOpenGLRenderer()
    {
    }

    void
    AlwaysStencilOpenGLRenderer::onDispose()
    {
      // Disable stencil buffer.
      glDisable(GL_STENCIL_TEST);

      // Revert stencil buffer settings.
      glStencilFunc(GL_ALWAYS, 0, STENCIL_BUFFER_MASK);
      glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    }

    int
    AlwaysStencilOpenGLRenderer::getStencilValue() const
    {
      return (fStencilValue);
    }

    void
    AlwaysStencilOpenGLRenderer::onInit()
    {
      // Enable stencil buffer.
      glEnable(GL_STENCIL_TEST);

      // Set the stencil buffer value for every pixel drawn.
      glStencilFunc(GL_ALWAYS, fStencilValue, STENCIL_BUFFER_MASK);
      glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
    }

    void
    AlwaysStencilOpenGLRenderer::setStencilValue(const int stencilValue)
    {
      fStencilValue = stencilValue;
    }
  }
}
