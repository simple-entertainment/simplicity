/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BLENDINGOPENGLRENDERER_H_
#define BLENDINGOPENGLRENDERER_H_

#include <simplicity/rendering/RendererDecorator.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Provides blending capabilities to the decorated {@link simplicity::Renderer Renderer}.
     * </p>
     *
     * @author Gary Buyn
     */
    class BlendingOpenGLRenderer : public RendererDecorator
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>BlendingOpenGLRenderer</code>.
         * </p>
         *
         * @param renderer The wrapped {@link simplicity::Renderer Renderer} that will execute with blending capabilities enabled.
         */
        BlendingOpenGLRenderer(boost::shared_ptr<Renderer> renderer);

        /**
         * <p>
         * Disposes of an instance of <code>BlendingOpenGLRenderer</code>.
         * </p>
         */
        virtual
        ~BlendingOpenGLRenderer();

        void
        onDispose();

        void
        onInit();
    };
  }
}

#endif /* BLENDINGOPENGLRENDERER_H_ */
