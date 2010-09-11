/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.rendering;

import javax.media.opengl.GL;

import com.se.simplicity.editor.internal.SelectionWidget;
import com.se.simplicity.editor.internal.Widget;
import com.se.simplicity.jogl.rendering.AdaptingJOGLRenderer;
import com.se.simplicity.jogl.rendering.BlendingJOGLRenderer;
import com.se.simplicity.jogl.rendering.DepthClearingJOGLRenderer;
import com.se.simplicity.jogl.rendering.OutlineJOGLRenderer;
import com.se.simplicity.jogl.rendering.StencilClearingJOGLRenderer;
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.vector.ArrayBackedObjectf;

/**
 * <p>
 * Renders the {@link com.se.simplicity.editor.internal.Widget Widget} in a JOGL environment using internally configured
 * {@link com.se.simplicity.rendering.Renderer Renderer}s. If the <code>Widget</code> to be rendered is a
 * {@link com.se.simplicity.editor.internal.SelectionWidget SelectionWidget}, the modelview matrix is manipulated to ensure only the transformation
 * from the root {@link com.se.simplicity.scenegraph.Node Node} of the <code>Widget</code> is applied (after the
 * {@link com.se.simplicity.rendering.Camera Camera} is applied) and the <code>SelectionWidget</code> is rendered with an outline. The depth buffer is
 * cleared and blending is enabled before rendering all <code>Widgets</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetJOGLRenderer extends AdaptingJOGLRenderer
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
    private OutlineJOGLRenderer fOutlineWidgetRenderer;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Renderer Renderer} that is executed for all {@link com.se.simplicity.editor.internal.Widget Widget}s
     * except the {@link com.se.simplicity.editor.internal.SelectionWidget SelectionWidget}.
     * </p>
     */
    private BlendingJOGLRenderer fStandardWidgetRenderer;

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
    public WidgetJOGLRenderer(final Renderer renderer)
    {
        super(renderer);

        fWidget = null;

        fStandardWidgetRenderer = new BlendingJOGLRenderer(new DepthClearingJOGLRenderer(renderer));
        fOutlineWidgetRenderer = new OutlineJOGLRenderer(new StencilClearingJOGLRenderer(fStandardWidgetRenderer));
    }

    @Override
    public void dispose()
    {
        if (fWidget != null)
        {
            if (fWidget instanceof SelectionWidget)
            {
                fOutlineWidgetRenderer.dispose();
            }
            else
            {
                fStandardWidgetRenderer.dispose();
            }
        }
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
        if (fWidget != null)
        {
            if (fWidget instanceof SelectionWidget)
            {
                fOutlineWidgetRenderer.init();
            }
            else
            {
                fStandardWidgetRenderer.init();
            }
        }
    }

    @Override
    public void renderModel(final Model model)
    {
        if (fWidget != null)
        {
            fWidget.updateView(fCamera);

            if (fWidget instanceof SelectionWidget)
            {
                GL gl = getGL();

                gl.glPushMatrix();
                gl.glLoadIdentity();
                fCamera.apply();
                gl.glMultMatrixf(((ArrayBackedObjectf) fWidget.getRootNode().getTransformation()).getArray(), 0);

                fOutlineWidgetRenderer.renderModel(((ModelNode) fWidget.getRootNode()).getModel());

                gl.glPopMatrix();
            }
            else
            {
                fStandardWidgetRenderer.renderModel(model);
            }
        }
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

        fOutlineWidgetRenderer.setGL(gl);
        fStandardWidgetRenderer.setGL(gl);
    }

    @Override
    public void setRenderer(final Renderer renderer)
    {
        super.setRenderer(renderer);

        ((AdaptingJOGLRenderer) fStandardWidgetRenderer.getRenderer()).setRenderer(renderer);
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
