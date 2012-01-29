/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef CULLFACEOPENGLRENDERER_H_
#define CULLFACEOPENGLRENDERER_H_

#include <simplicity/rendering/Renderer.h>

#include "MonoColourOpenGLRenderer.h"

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Renders the front and back sides of polygons with different colours so that faces that are being erroneously culled can be corrected.
     * </p>
     *
     * @author Gary Buyn
     */
    class CullFaceOpenGLRenderer : public Renderer
    {
      public:
        /**
         * <p>
         * Creates an instance of <code>CullFaceOpenGLRenderer</code>.
         * </p>
         */
        CullFaceOpenGLRenderer();

        /**
         * <p>
         * Disposes of an instance of <code>CullFaceOpenGLRenderer</code>.
         * </p>
         */
        virtual
        ~CullFaceOpenGLRenderer();

        void
        dispose();

        /**
         * <p>
         * Retrieves the colour to render the back side of the faces with. The default is green.
         * </p>
         *
         * @return The colour to render the back side of the faces with.
         */
        std::shared_ptr<RGBAColourVector<> >
        getBackFaceColour();

        DrawingMode
        getDrawingMode() const;

        /**
         * <p>
         * Retrieves the colour to render the front side of the faces with. The default is green.
         * </p>
         *
         * @return The colour to render the front side of the faces with.
         */
        std::shared_ptr<RGBAColourVector<> >
        getFrontFaceColour();

        void
        init();

        void
        renderModel(const Model& model);

        /**
         * <p>
         * Sets the colour to render the back side of the faces with. The default is green.
         * </p>
         *
         * @param backFaceColour The colour to render the back side of the faces with.
         */
        void
        setBackFaceColour(std::shared_ptr<RGBAColourVector<> > backFaceColour);

        void
        setDrawingMode(const DrawingMode mode);

        /**
         * <p>
         * Sets the colour to render the front side of the faces with. The default is green.
         * </p>
         *
         * @param frontFaceColour The colour to render the front side of the faces with.
         */
        void
        setFrontFaceColour(std::shared_ptr<RGBAColourVector<> > frontFaceColour);

      private:
        /**
         * <p>
         * The colour to render the back side of the faces with.
         * </p>
         */
        std::shared_ptr<RGBAColourVector<> > fBackFaceColour;

        /**
         * <p>
         * The cull face status before this <code>CullFaceOpenGLRenderer</code> is executed.
         * </p>
         */
        unsigned char fCullFace;

        /**
         * <p>
         * The drawing mode used to render the {@link com.se.simplicity.model.Model Model}s.
         * </p>
         */
        DrawingMode fDrawingMode;

        /**
         * <p>
         * The front face before this <code>CullFaceOpenGLRenderer</code> is executed.
         * </p>
         */
        int fFrontFace;

        /**
         * <p>
         * The colour to render the front side of the faces with.
         * </p>
         */
        std::shared_ptr<RGBAColourVector<> > fFrontFaceColour;

        /**
         * <p>
         * The renderer that is delegated to to perform the actual rendering.
         * </p>
         */
        MonoColourOpenGLRenderer fRenderer;
    };
  }
}

#endif /* CULLFACEOPENGLRENDERER_H_ */
