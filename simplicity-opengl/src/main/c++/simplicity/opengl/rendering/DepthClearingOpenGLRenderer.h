/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DEPTHCLEARINGOPENGLRENDERER_H_
#define DEPTHCLEARINGOPENGLRENDERER_H_

#include <simplicity/rendering/RendererDecorator.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Clears the depth buffer before executing the decorated {@link rendering::Renderer Renderer}.
     * </p>
     *
     * @author Gary Buyn
     */
    class DepthClearingOpenGLRenderer : public RendererDecorator
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>DepthClearingOpenGLRenderer</code>.
         * </p>
         *
         * @param renderer The wrapped {@link simplicity::Renderer Renderer} that will actually render the {@link simplicity::Model Model}.
         */
        DepthClearingOpenGLRenderer(std::shared_ptr<Renderer> renderer);

        /**
         * <p>
         * Disposes of an instance of <code>DepthClearingOpenGLRenderer</code>.
         * </p>
         */
        virtual
        ~DepthClearingOpenGLRenderer();

        void
        onDispose();

        void
        onInit();
    };
  }
}

#endif /* DEPTHCLEARINGOPENGLRENDERER_H_ */
