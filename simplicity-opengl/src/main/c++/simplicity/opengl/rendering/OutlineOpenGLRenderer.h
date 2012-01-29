/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef OUTLINEOPENGLRENDERER_H_
#define OUTLINEOPENGLRENDERER_H_

#include <simplicity/math/RGBAColourVector.h>
#include <simplicity/rendering/Renderer.h>

#include "AlwaysStencilOpenGLRenderer.h"
#include "MonoColourOpenGLRenderer.h"
#include "NotEqualStencilOpenGLRenderer.h"

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Renders the {@link simplicity::Model Model} in a JOGL environment and adds an outline. Achieves this using the
     * stencil buffer technique.
     * </p>
     *
     * @author Gary Buyn
     */
    class OutlineOpenGLRenderer : public Renderer
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>OutlineOpenGLRenderer</code>.
         * </p>
         */
        OutlineOpenGLRenderer();

        /**
         * <p>
         * Disposes of an instance of <code>OutlineOpenGLRenderer</code>.
         * </p>
         */
        virtual
        ~OutlineOpenGLRenderer();

        void
        dispose();

        DrawingMode
        getDrawingMode() const;

        /**
         * <p>
         * Retrieves the colour of the outline. White is the default.
         * </p>
         *
         * @return The colour of the outline.
         */
        std::shared_ptr<RGBAColourVector<> >
        getOutlineColour() const;

        /**
         * <p>
         * Retrieves the width of the outline. This is actually the width of the line used to draw the outline, only half of which will actually be
         * visible. 3 is the default.
         * </p>
         *
         * @return The width of the outline.
         */
        float
        getOutlineWidth() const;

        void
        init();

        void
        renderModel(const Model& model);

        void
        setDrawingMode(const DrawingMode mode);

        /**
         * <p>
         * Sets the colour of the outline. White is the default.
         * </p>
         *
         * @param outlineColour The colour of the outline.
         */
        void
        setOutlineColour(std::shared_ptr<RGBAColourVector<> > outlineColour);

        /**
         * <p>
         * Sets the width of the outline. This is actually the width of the line used to draw the outline, only half of which will actually be visible. 3
         * is the default.
         * </p>
         *
         * @param outlineWidth The width of the outline.
         */
        void
        setOutlineWidth(const float outlineWidth);

      private:
        /**
         * <p>
         * The default width of the outline.
         * </p>
         */
        static const float DEFAULT_OUTLINE_WIDTH;

        /**
         * <p>
         * The {@link simplicity::Renderer Renderer} used to perform the first rendering pass (the normal object).
         * </p>
         */
        std::unique_ptr<AlwaysStencilOpenGLRenderer> fAlwaysStencil;

        /**
         * <p>
         * The {@link simplicity::Renderer Renderer} used in the second rendering pass to ensure the colours in the object are ignored when drawing
         * the outline.
         * </p>
         */
        std::shared_ptr<MonoColourOpenGLRenderer> fMonoColour;

        /**
         * <p>
         * The {@link simplicity::Renderer Renderer} used to perform the second rendering pass (the outline).
         * </p>
         */
        std::unique_ptr<NotEqualStencilOpenGLRenderer> fNotEqualStencil;

        /**
         * <p>
         * The width of the outline.
         * </p>
         */
        float fOutlineWidth;
    };
  }
}

#endif /* OUTLINEOPENGLRENDERER_H_ */
