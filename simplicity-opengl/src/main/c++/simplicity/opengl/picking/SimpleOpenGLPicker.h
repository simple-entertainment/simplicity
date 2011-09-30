/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIMPLEOPENGLPICKER_H_
#define SIMPLEOPENGLPICKER_H_

#include <simplicity/model/VertexGroup.h>
#include <simplicity/picking/Picker.h>
#include <simplicity/rendering/engine/RenderingEngine.h>

namespace simplicity
{
  namespace opengl
  {
    /**
     * <p>
     * Picks from a JOGL rendering environment. This implementation uses only simple picking techniques and properties.
     * </p>
     *
     * <p>
     * {@link simplicity::RenderingEngine RenderingEngine}s and {@link simplicity::Renderer Renderer}s used in conjunction with a
     * <code>SimpleJOGLPicker</code> must name rendered scene components using the following convention for picking to function correctly:
     * </p>
     *
     * <ul>
     * <li>{@link simplicity::Model Model}s must be named after the ID of the {@link simplicity::ModelNode ModelNode} they are contained in.</li>
     * <li>Primitives within the <code>Model</code>s can optionally be named after the index of the primitive within the <code>Model</code>. If they
     * are not named the resulting {@link simplicity::Hit Hit} will contain the <code>ModelNode</code> ONLY and not the primitive.</li>
     * </ul>
     *
     * @author Gary Buyn
     */
    class SimpleOpenGLPicker : public Picker
    {
      public:
        friend class SimpleOpenGLPickerTest;

        /**
         * <p>
         * Creates an instance of <code>SimpleOpenGLPicker</code>.
         * </p>
         */
        SimpleOpenGLPicker();

        /**
         * <p>
         * Disposes of an instance of <code>SimpleOpenGLPicker</code>.
         * </p>
         */
        virtual
        ~SimpleOpenGLPicker();

        void
        dispose();

        Renderer::DrawingMode
        getDrawingMode() const;

        /**
         * <p>
         * Retrieves the <code>RenderingEngine</code> that renders the <code>Scene</code> to determine which components will be picked.
         * </p>
         *
         * @return The <code>RenderingEngine</code> that renders the <code>Scene</code> to determine which components will be picked.
         */
        boost::shared_ptr<RenderingEngine>
        getRenderingEngine() const;

        /**
         * <p>
         * Retrieves the select buffer used by the JOGL rendering environment.
         * </p>
         *
         * <p>
         * NOTE: This method should only be used to examine the select buffer, not to modify it.
         * </p>
         *
         * @return The select buffer used by the JOGL rendering environment.
         */
        unsigned int*
        getSelectBuffer() const;

        /**
         * <p>
         * Retrieves the capacity of the select buffer used by the JOGL rendering environment.
         * </p>
         *
         * @return The capacity of the select buffer used by the JOGL rendering environment.
         */
        int
        getSelectBufferCapacity() const;

        void
        init();

        PickEvent
        pickScene(Scene& scene, const Camera& camera, const Pick pick);

        void
        setDrawingMode(const Renderer::DrawingMode mode);

        /**
         * <p>
         * Sets the <code>RenderingEngine</code> that renders the <code>Scene</code> to determine which components will be picked.
         * </p>
         *
         * @param renderingEngine The <code>RenderingEngine</code> that renders the <code>Scene</code> to determine which components will be picked.
         */
        void
        setRenderingEngine(boost::shared_ptr<RenderingEngine> renderingEngine);

        /**
         * <p>
         * Sets the capacity of the select buffer used by the OpenGL rendering environment.
         * </p>
         *
         * @param selectBufferCapacity The capacity of the select buffer used by the OpenGL rendering environment.
         */
        void
        setSelectBufferCapacity(const int selectBufferCapacity);

      private:

        /**
         * <p>
         * The default select buffer capacity.
         * </p>
         */
        static const int DEFAULT_SELECT_BUFFER_CAPACITY = 2048;

        /**
         * <p>
         * The {@link simplicity::DrawingMode DrawingMode} used to create {@link simplicity::PickEvent PickEvent}s from the
         * {@link simplicity::Scene Scene}.
         * </p>
         */
        Renderer::DrawingMode fDrawingMode;

        /**
         * <p>
         * The <code>RenderingEngine</code> that renders the <code>Scene</code> to determine which components will be picked.
         * </p>
         */
        boost::shared_ptr<RenderingEngine> fRenderingEngine;

        /**
         * <p>
         * The select buffer used by the JOGL rendering environment. Holds details of picked <code>SceneGraph</code> components.
         * </p>
         */
        unsigned int* fSelectBuffer;

        /**
         * <p>
         * The capacity of the select buffer used by the JOGL rendering environment. This capacity determines how much hit data can be retrieved when
         * picking a <code>Scene</code>.
         * </p>
         */
        int fSelectBufferCapacity;

        /**
         * <p>
         * Creates a <code>PickEvent</code> for the given select buffer.
         * </p>
         *
         * <p>
         * It is assumed that names 1..n-1 in the select buffer correspond to the unique identifiers of <code>ModelNode</code>s containing the picked
         * components of the <code>SceneGraph</code> and that name n in the select buffer corresponds to the subset (face/edge/vertex) of the
         * component that was actually picked.
         * </p>
         *
         * @param scene The <code>Scene</code> that was picked.
         * @param numberOfHits The number of hits returned during the last <code>GL_SELECTION</code> rendering pass.
         *
         * @return A <code>PickEvent</code> for the given select buffer.
         */
        PickEvent
        createPickEvent(const Scene& scene, const int numberOfHits) const;

        /**
         * <p>
         * Retrieves a subset vertex group containing the rendered primitive at the given index of the given <code>VertexGroup</code>.
         * </p>
         *
         * @param vertexGroup The <code>VertexGroup</code> to create the subset from.
         * @param index The index of the rendered primitive to contain in the subset.
         *
         * @return A subset vertex group containing the rendered primitive at the given index of the given <code>VertexGroup</code>.
         */
        boost::shared_ptr<VertexGroup>
        getSubsetVG(VertexGroup& vertexGroup, const int index) const;
    };
  }
}

#endif /* SIMPLEOPENGLPICKER_H_ */
