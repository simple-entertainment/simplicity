/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.rendering;

import static com.se.simplicity.model.ModelConstants.ITEMS_IN_CNV;

import javax.media.opengl.GL;

import com.se.simplicity.editor.internal.Widget;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.rendering.AdaptingJOGLRenderer;
import com.se.simplicity.jogl.rendering.OutlineJOGLRenderer;
import com.se.simplicity.jogl.rendering.StencilClearingJOGLRenderer;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.ArrayBackedObjectf;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.SimpleTranslationVectorf4;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * Renders a selection {@link com.se.simplicity.editor.internal.Widget Widget} in a JOGL environment. The modelview matrix is manipulated to ensure
 * only the transformation from the root {@link com.se.simplicity.scenegraph.Node Node} of the <code>Widget</code> is applied (after the
 * {@link com.se.simplicity.rendering.Camera Camera} is applied) and the <code>Widget</code> is rendered with an outline.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SelectionWidgetJOGLRenderer extends AdaptingJOGLRenderer
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed through.
     * </p>
     */
    private Camera fCamera;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Renderer Renderer} that is executed for the {@link com.se.simplicity.editor.internal.SelectionWidget
     * SelectionWidget}.
     * </p>
     */
    private Renderer fOutlineRenderer;

    /**
     * <p>
     * The {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     * </p>
     */
    private Widget fWidget;

    /**
     * <p>
     * Creates an instance of <code>WidgetJOGLRenderer</code>.
     * </p>
     * 
     * @param renderer The wrapped {@link com.se.simplicity.rendering.Renderer Renderer} that will render the
     * {@link com.se.simplicity.editor.internal.Widget Widget}.
     */
    public SelectionWidgetJOGLRenderer(final Renderer renderer)
    {
        super(renderer);

        fWidget = null;
        fOutlineRenderer = new StencilClearingJOGLRenderer(new OutlineJOGLRenderer());
    }

    @Override
    public void dispose()
    {
        super.dispose();

        fOutlineRenderer.dispose();
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed
     * through.
     * </p>
     * 
     * @return The {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed
     * through.
     */
    public Camera getCamera()
    {
        return (fCamera);
    }

    protected TranslationVectorf getPrimitiveTranslation(final Model primitive)
    {
        SimpleTranslationVectorf4 translation = new SimpleTranslationVectorf4();
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        if (primitive instanceof ArrayVG)
        {
            float[] vertices = ((ArrayVG) primitive).getVertices();
            int vertexCount = vertices.length / ITEMS_IN_CNV;
            for (int vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++)
            {
                x += vertices[vertexIndex];
                y += vertices[vertexIndex] + 1;
                z += vertices[vertexIndex] + 2;
            }

            x /= vertexCount;
            y /= vertexCount;
            z /= vertexCount;
        }

        translation.setX(x);
        translation.setY(y);
        translation.setZ(z);

        return (translation);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     * </p>
     * 
     * @return The {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     */
    public Widget getWidget()
    {
        return (fWidget);
    }

    @Override
    public void init()
    {
        fOutlineRenderer.init();

        super.init();
    }

    @Override
    public void renderModel(final Model model)
    {
        // Retrieve the current MODELVIEW matrix and remove the influence of the Camera.
        SimpleTransformationMatrixf44 modelViewMatrix = new SimpleTransformationMatrixf44();
        getGL().glGetFloatv(GL.GL_MODELVIEW_MATRIX, modelViewMatrix.getArray(), 0);
        modelViewMatrix.multiplyLeft(fCamera.getNode().getAbsoluteTransformation());

        fWidget.updateView(fCamera, modelViewMatrix, model);

        GL gl = getGL();

        gl.glPushMatrix();
        {
            gl.glLoadIdentity();
            fCamera.apply();
            gl.glMultMatrixf(((ArrayBackedObjectf) fWidget.getRootNode().getTransformation()).getArray(), 0);

            Model widgetModel = ((ModelNode) fWidget.getRootNode()).getModel();
            super.renderModel(widgetModel);
            fOutlineRenderer.renderModel(widgetModel);
        }
        gl.glPopMatrix();
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed through.
     * </p>
     * 
     * @param camera The {@link com.se.simplicity.rendering.Camera Camera} the {@link com.se.simplicity.editor.internal.Widget Widget} is being viewed
     * through.
     */
    public void setCamera(final Camera camera)
    {
        fCamera = camera;
    }

    @Override
    public void setGL(final GL gl)
    {
        super.setGL(gl);

        ((JOGLComponent) fOutlineRenderer).setGL(gl);
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     * </p>
     * 
     * @param widget The {@link com.se.simplicity.editor.internal.Widget Widget} that will be rendered.
     */
    public void setWidget(final Widget widget)
    {
        fWidget = widget;
    }
}
