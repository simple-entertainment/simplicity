/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef STENCILCLEARINGOPENGLRENDERERDEMO_H_
#define STENCILCLEARINGOPENGLRENDERERDEMO_H_

#include <simplicity/opengl/rendering/engine/SimpleOpenGLRenderingEngine.h>

#include "../OpenGLDemo.h"

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * A small demonstration of the {@link simplicity::opengl::StencilClearingOpenGLRenderer StencilClearingOpenGLRenderer}.
     * </p>
     */
    class StencilClearingOpenGLRendererDemo : public OpenGLDemo
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>StencilClearingOpenGLRendererDemo</code>.
         * </p>
         */
      StencilClearingOpenGLRendererDemo();

        /**
         * <p>
         * Disposes of an instance of <code>StencilClearingOpenGLRendererDemo</code>.
         * </p>
         */
        virtual
        ~StencilClearingOpenGLRendererDemo();

        void
        advance();

        void
        dispose();

        boost::shared_ptr<Node>
        getCameraRootNode();

        std::string
        getDescription();

        std::string
        getTitle();

        void
        init();

      private:
        /**
         * <p>
         * The rendering engine for the demo.
         * </p>
         */
        SimpleOpenGLRenderingEngine fRenderingEngine;
    };
  }
}

#endif /* STENCILCLEARINGOPENGLRENDERERDEMO_H_ */
