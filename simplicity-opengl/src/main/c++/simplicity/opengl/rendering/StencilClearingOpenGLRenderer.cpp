/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <GL/glew.h>

#include "StencilClearingOpenGLRenderer.h"

using namespace boost;

namespace simplicity
{
  namespace opengl
  {
    StencilClearingOpenGLRenderer::StencilClearingOpenGLRenderer(shared_ptr<Renderer> renderer) :
	  RendererDecorator(renderer)
    {
    }

    StencilClearingOpenGLRenderer::~StencilClearingOpenGLRenderer()
    {
    }

    void
    StencilClearingOpenGLRenderer::onDispose()
    {
    }

    void
    StencilClearingOpenGLRenderer::onInit()
    {
      glClear(GL_STENCIL_BUFFER_BIT);
    }
  }
}
