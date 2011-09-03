/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <simplicity/SEInvalidOperationException.h>

#include "NamePassingOpenGLRenderer.h"

using namespace boost;

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Holds a name that it passes to the named renderer it adapts.
     * </p>
     */
    class MiddleManRenderer : public AdaptingRenderer
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>MiddleManRenderer</code>.
         * </p>
         */
        MiddleManRenderer(shared_ptr<Renderer> renderer) :
            AdaptingRenderer(renderer)
        {
          fName = -1;
        }

        /**
         * <p>
         * Disposes of an instance of <code>MiddleManRenderer</code>.
         * </p>
         */
        ~MiddleManRenderer()
        {
        }

        void
        onDispose()
        {
        }

        void
        onInit()
        {
        }

        void
        renderModel(const Model& model)
        {
          if (fName != -1)
          {
            dynamic_pointer_cast<NamedRenderer>(getRenderer())->renderModel(model, fName);
          }

          fName = -1;
        }

        /**
         * <p>
         * Sets the name to be passed to the adapted named renderer.
         * </p>
         *
         * @param name The name to be passed to the adapted named renderer.
         */
        void
        setName(const int name)
        {
          fName = name;
        }

      private:
        /**
         * <p>
         * The name to be passed to the adapted named renderer.
         * </p>
         */
        int fName;
    };

    NamePassingOpenGLRenderer::NamePassingOpenGLRenderer(shared_ptr<Renderer> renderer) :
        AdaptingRenderer(renderer)
    {
      if (!dynamic_pointer_cast<AdaptingRenderer>(renderer))
      {
        throw SEInvalidOperationException();
      }

      // Retrieve the AdaptingRenderer that is wrapping the NamedRenderer the name is to be passed to.
      shared_ptr<AdaptingRenderer> wrappedRenderer(dynamic_pointer_cast<AdaptingRenderer>(renderer));
      while (!dynamic_pointer_cast<NamedRenderer>(wrappedRenderer->getRenderer()))
      {
        wrappedRenderer = dynamic_pointer_cast<AdaptingRenderer>(wrappedRenderer->getRenderer());
      }

      // Put the middle man between the AdaptingRenderer and the NamedRenderer.
      shared_ptr<Renderer> namedRenderer(wrappedRenderer->getRenderer());
      fMiddleMan = shared_ptr<Renderer>(new MiddleManRenderer(namedRenderer));
      wrappedRenderer->setRenderer(fMiddleMan);
    }

    NamePassingOpenGLRenderer::~NamePassingOpenGLRenderer()
    {
    }

    void
    NamePassingOpenGLRenderer::onDispose()
    {
    }

    void
    NamePassingOpenGLRenderer::onInit()
    {
    }

    void
    NamePassingOpenGLRenderer::renderModel(const Model& model, const int name)
    {
      dynamic_pointer_cast<MiddleManRenderer>(fMiddleMan)->setName(name);

      AdaptingRenderer::renderModel(model);
    }
  }
}

