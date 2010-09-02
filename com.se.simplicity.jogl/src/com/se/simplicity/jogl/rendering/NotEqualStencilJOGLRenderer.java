/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.rendering;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * Renders a {@link com.se.simplicity.model.VertexGroup VertexGroup} in a JOGL environment using a wrapped
 * {@link com.se.simplicity.rendering.Renderer Renderer} but only renders on pixels where the stencil buffer does not contain a certain value (1 by
 * default).
 * </p>
 * 
 * @author Gary Buyn
 */
public class NotEqualStencilJOGLRenderer implements Renderer, JOGLComponent
{
    /**
     * <p>
     * The mask to be anded with during stencil tests.
     * </p>
     */
    private static final int STENCIL_BUFFER_MASK = 255; // binary: 1111

    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL fGl;

    /**
     * <p>
     * The wrapped {@link com.se.simplicity.rendering.Renderer Renderer} that will actually render the {@link com.se.simplicity.model.VertexGroup
     * VertexGroup}.
     * </p>
     */
    private Renderer fRenderer;

    /**
     * <p>
     * The value in the stencil buffer that will result in the pixel not being drawn.
     * </p>
     */
    private int fStencilValue;

    /**
     * <p>
     * Creates an instance of <code>NotEqualStencilJOGLRenderer</code>.
     * </p>
     * 
     * @param renderer The wrapped {@link com.se.simplicity.rendering.Renderer Renderer} that will actually render the
     * {@link com.se.simplicity.model.VertexGroup VertexGroup}.
     */
    public NotEqualStencilJOGLRenderer(final Renderer renderer)
    {
        fRenderer = renderer;

        fGl = null;
        fStencilValue = 1;
    }

    @Override
    public void dispose()
    {
        // Disable stencil buffer.
        fGl.glDisable(GL.GL_STENCIL_TEST);

        // Revert stencil buffer settings.
        fGl.glStencilFunc(GL.GL_ALWAYS, 0, STENCIL_BUFFER_MASK);

        fRenderer.dispose();
    }

    @Override
    public DrawingMode getDrawingMode()
    {
        return (fRenderer.getDrawingMode());
    }

    @Override
    public GL getGL()
    {
        return (fGl);
    }

    /**
     * <p>
     * Retrieves the value in the stencil buffer that will result in the pixel not being drawn. 1 is the default.
     * </p>
     * 
     * @return The value in the stencil buffer that will result in the pixel not being drawn.
     */
    public int getStencilValue()
    {
        return (fStencilValue);
    }

    @Override
    public void init()
    {
        fRenderer.init();

        // Enable stencil buffer.
        fGl.glEnable(GL.GL_STENCIL_TEST);

        // Only draw if the stencil buffer does not contain the value.
        fGl.glStencilFunc(GL.GL_NOTEQUAL, fStencilValue, STENCIL_BUFFER_MASK);
    }

    @Override
    public void renderVertexGroup(final VertexGroup vertexGroup)
    {
        fRenderer.renderVertexGroup(vertexGroup);
    }

    @Override
    public void setDrawingMode(final DrawingMode mode)
    {
        fRenderer.setDrawingMode(mode);
    }

    @Override
    public void setGL(final GL gl)
    {
        fGl = gl;

        ((JOGLComponent) fRenderer).setGL(gl);
    }

    /**
     * <p>
     * Sets the value in the stencil buffer that will result in the pixel not being drawn. 1 is the default.
     * </p>
     * 
     * @param stencilValue The value in the stencil buffer that will result in the pixel not being drawn.
     */
    public void setStencilValue(final int stencilValue)
    {
        fStencilValue = stencilValue;
    }
}
