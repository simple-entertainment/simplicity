/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef RENDERER_H_
#define RENDERER_H_

#include "../model/Model.h"

namespace simplicity
{
    /**
     * <p>
     * Renders {@link simplicity::Model Model}s.
     * </p>
     *
     * <p>
     * Any changes to settings made during the {@link simplicity::Renderer#init() init()} or
     * {@link simplicity::Renderer#renderModel(Model) renderModel(Model)} methods should be reverted during the
     * {@link simplicity::Renderer#dispose() dispose()} method. It is the responsibility of the <code>Renderer</code> to leave the
     * rendering environment as it was found (except for contents of buffers) so that multiple <code>Renderer</code>s may be used together without
     * effecting each other.
     * </p>
     *
     * <p>
     * When used within a {@link simplicity::RenderingEngine RenderingEngine}, the <code>Renderer</code> acts as a rendering pass.
     * Adding multiple <code>Renderer</code>s to a <code>RenderingEngine</code> effectively creates a multi pass rendering environment. Since lighting
     * settings may be changed by the <code>RenderingEngine</code>, they should be reverted to the state they were found in, not just the default state.
     * </p>
     *
     * @author Gary Buyn
     */
    class Renderer
    {
        public:
            /**
             * <p>
             * Disposes of an instance of <code>Renderer</code> (included to allow polymorphic deletion).
             * </p>
             */
            virtual
            ~Renderer()
            {
            }

            /**
             * <p>
             * Reverts the rendering environment.
             * </p>
             */
            virtual void
            dispose() = 0;

            /**
             * <p>
             * Receives the {@link simplicity::DrawingMode DrawingMode} used to render the {@link simplicity::Model Model}s.
             * </p>
             *
             * @return The <code>DrawingMode</code> used to render the <code>Model</code>s.
             */
            virtual DrawingMode
            getDrawingMode() = 0;

            /**
             * <p>
             * Initialises the rendering environment.
             * </p>
             */
            virtual void
            init() = 0;

            /**
             * <p>
             * Renders the given {@link simplicity::Model Model}.
             * </p>
             *
             * @param model The <code>Model</code> to render.
             */
            virtual void
            renderModel(Model* const model) = 0;

            /**
             * <p>
             * Sets the {@link simplicity::DrawingMode DrawingMode} used to render the {@link simplicity::Model Model} s.
             * </p>
             *
             * @param mode The <code>DrawingMode</code> used to render the <code>Model</code>s.
             */
            virtual void
            setDrawingMode(DrawingMode mode) = 0;
    };
}

#endif /* RENDERER_H_ */
