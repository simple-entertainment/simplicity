/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef STENCILCLEARINGOPENGLRENDERER_H_
#define STENCILCLEARINGOPENGLRENDERER_H_

#include <simplicity/rendering/AdaptingRenderer.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Clears the stencil buffer before executing the wrapped {@link rendering::Renderer Renderer}.
     * </p>
     *
     * @author Gary Buyn
     */
    class StencilClearingOpenGLRenderer : public AdaptingRenderer
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>StencilClearingOpenGLRenderer</code>.
         * </p>
         *
         * @param renderer The wrapped {@link simplicity::Renderer Renderer} that will actually render the {@link simplicity::Model Model}.
         */
        StencilClearingOpenGLRenderer(boost::shared_ptr<Renderer> renderer);

        /**
         * <p>
         * Disposes of an instance of <code>AlwaysStencilOpenGLRenderer</code>.
         * </p>
         */
        virtual
        ~StencilClearingOpenGLRenderer();

        void
        onDispose();

        void
        onInit();
    };
  }
}

#endif /* STENCILCLEARINGOPENGLRENDERER_H_ */
