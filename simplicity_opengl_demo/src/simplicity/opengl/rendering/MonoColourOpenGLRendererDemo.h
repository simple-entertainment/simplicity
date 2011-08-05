/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MONOCOLOUROPENGLRENDERERDEMO_H_
#define MONOCOLOUROPENGLRENDERERDEMO_H_

#include <simplicity/scenegraph/Node.h>

#include "../Demo.h"

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * A small demonstration of the {@link simplicity::opengl::MonoColourOpenGLRenderer MonoColourOpenGLRenderer}.
     * </p>
     */
    class MonoColourOpenGLRendererDemo : public Demo
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>MonoColourOpenGLRendererDemo</code>.
         * </p>
         */
        MonoColourOpenGLRendererDemo();

        /**
         * <p>
         * Disposes of an instance of <code>MonoColourOpenGLRendererDemo</code>.
         * </p>
         */
        virtual
        ~MonoColourOpenGLRendererDemo();

        void
        dispose(RenderingEngine& renderingEngine);

        std::string
        getDescription();

        std::string
        getTitle();

        void
        init(RenderingEngine& renderingEngine);

      private:
        /**
         * <p>
         * The root node of the scene used to demonstrate the {@link simplicity::opengl::MonoColourOpenGLRenderer MonoColourOpenGLRenderer}.
         * </p>
         */
        boost::shared_ptr<Node> fRoot;
    };
  }
}

#endif /* MONOCOLOUROPENGLRENDERERDEMO_H_ */
