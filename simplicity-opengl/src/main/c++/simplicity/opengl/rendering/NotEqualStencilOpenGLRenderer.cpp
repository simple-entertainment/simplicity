/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include "NotEqualStencilOpenGLRenderer.h"

namespace simplicity
{
  namespace opengl
  {
    NotEqualStencilOpenGLRenderer::NotEqualStencilOpenGLRenderer(boost::shared_ptr<Renderer> renderer) :
      AdaptingRenderer(renderer), fStencilValue(1)
    {
    }

    NotEqualStencilOpenGLRenderer::~NotEqualStencilOpenGLRenderer()
    {
    }

    /**
     * <p>
     * Retrieves the value in the stencil buffer that will result in the pixel not being drawn. 1 is the default.
     * </p>
     *
     * @return The value in the stencil buffer that will result in the pixel not being drawn.
     */
    int
    NotEqualStencilOpenGLRenderer::getStencilValue() const
    {
      return (fStencilValue);
    }

    void
    NotEqualStencilOpenGLRenderer::onDispose()
    {
      // Disable stencil buffer.
      glDisable(GL_STENCIL_TEST);

      // Revert stencil buffer settings.
      glStencilFunc(GL_ALWAYS, 0, STENCIL_BUFFER_MASK);
    }

    void
    NotEqualStencilOpenGLRenderer::onInit()
    {
      // Enable stencil buffer.
      glEnable(GL_STENCIL_TEST);

      // Only draw if the stencil buffer does not contain the value.
      glStencilFunc(GL_NOTEQUAL, fStencilValue, STENCIL_BUFFER_MASK);
    }

    /**
     * <p>
     * Sets the value in the stencil buffer that will result in the pixel not being drawn. 1 is the default.
     * </p>
     *
     * @param stencilValue The value in the stencil buffer that will result in the pixel not being drawn.
     */
    void
    NotEqualStencilOpenGLRenderer::setStencilValue(const int stencilValue)
    {
      fStencilValue = stencilValue;
    }
  }
}
