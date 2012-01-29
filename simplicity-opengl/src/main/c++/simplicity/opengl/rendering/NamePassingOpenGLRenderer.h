/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef NAMEPASSINGOPENGLRENDERER_H_
#define NAMEPASSINGOPENGLRENDERER_H_

#include <simplicity/rendering/RendererDecorator.h>
#include <simplicity/rendering/NamedRenderer.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Passes the name down the chain or renderer decorators to the first
     * {@link simplicity::NamedRenderer NamedRenderer}.
     * </p>
     *
     * @author Gary Buyn
     */
    class NamePassingOpenGLRenderer : public RendererDecorator, public NamedRenderer
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>NamePassingOpenGLRenderer</code>.
         * </p>
         */
        NamePassingOpenGLRenderer(std::shared_ptr<Renderer> renderer);

        /**
         * <p>
         * Disposes of an instance of <code>NamePassingOpenGLRenderer</code>.
         * </p>
         */
        virtual
        ~NamePassingOpenGLRenderer();

        void
        onDispose();

        void
        onInit();

        void
        renderModel(const Model& model, const int name);

      private:
        /**
         * <p>
         * The middle-man used to pass the name from this renderer to the first {@link simplicity::NamedRenderer NamedRenderer} down the chain.
         * </p>
         */
        std::shared_ptr<Renderer> fMiddleMan;
    };
  }
}

#endif /* NAMEPASSINGOPENGLRENDERER_H_ */
