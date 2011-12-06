/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef NOTEQUALSTENCILOPENGLRENDERER_H_
#define NOTEQUALSTENCILOPENGLRENDERER_H_

#include <simplicity/rendering/RendererDecorator.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Renders a {@link simplicity::Model Model} in a JOGL environment using the decorated
     * {@link simplicity::Renderer Renderer} but only renders on pixels where the stencil buffer does not contain a
     * certain value (1 by default).
     * </p>
     *
     * @author Gary Buyn
     */
    class NotEqualStencilOpenGLRenderer : public RendererDecorator
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>NotEqualStencilOpenGLRenderer</code>.
         * </p>
         *
         * @param renderer The wrapped {@link simplicity::Renderer Renderer} that will actually render the {@link simplicity::Model Model}.
         */
        NotEqualStencilOpenGLRenderer(boost::shared_ptr<Renderer> renderer);

        /**
         * <p>
         * Disposes of an instance of <code>NotEqualStencilOpenGLRenderer</code>.
         * </p>
         */
        virtual
        ~NotEqualStencilOpenGLRenderer();

        /**
         * <p>
         * Retrieves the value in the stencil buffer that will result in the pixel not being drawn. 1 is the default.
         * </p>
         *
         * @return The value in the stencil buffer that will result in the pixel not being drawn.
         */
        int
        getStencilValue() const;

        void
        onDispose();

        void
        onInit();

        /**
         * <p>
         * Sets the value in the stencil buffer that will result in the pixel not being drawn. 1 is the default.
         * </p>
         *
         * @param stencilValue The value in the stencil buffer that will result in the pixel not being drawn.
         */
        void
        setStencilValue(const int stencilValue);

      private:
        /**
         * <p>
         * The mask to be anded with during stencil tests.
         * </p>
         */
        static const int STENCIL_BUFFER_MASK = 255; // binary: 1111

        /**
         * <p>
         * The value in the stencil buffer that will result in the pixel not being drawn.
         * </p>
         */
        int fStencilValue;
    };
  }
}

#endif /* NOTEQUALSTENCILOPENGLRENDERER_H_ */
