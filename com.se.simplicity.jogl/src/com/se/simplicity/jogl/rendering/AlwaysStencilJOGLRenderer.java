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
 * {@link com.se.simplicity.rendering.Renderer Renderer} and sets a value in the stencil buffer for every pixel drawn (1 by default).
 * </p>
 * 
 * @author Gary Buyn
 */
public class AlwaysStencilJOGLRenderer implements Renderer, JOGLComponent
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
     * The value to set in the stencil buffer for every pixel drawn.
     * </p>
     */
    private int fStencilValue;

    /**
     * <p>
     * Creates an instance of <code>AlwaysStencilJOGLRenderer</code>.
     * </p>
     * 
     * @param renderer The wrapped {@link com.se.simplicity.rendering.Renderer Renderer} that will actually render the
     * {@link com.se.simplicity.model.VertexGroup VertexGroup}.
     */
    public AlwaysStencilJOGLRenderer(final Renderer renderer)
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
        fGl.glStencilOp(GL.GL_KEEP, GL.GL_KEEP, GL.GL_KEEP);

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
     * Retrieves the value to set in the stencil buffer for every pixel drawn. 1 is the default.
     * </p>
     * 
     * @return The value to set in the stencil buffer for every pixel drawn.
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

        // Set the stencil buffer value for every pixel drawn.
        fGl.glStencilFunc(GL.GL_ALWAYS, fStencilValue, STENCIL_BUFFER_MASK);
        fGl.glStencilOp(GL.GL_KEEP, GL.GL_KEEP, GL.GL_REPLACE);
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
     * Sets the value to set in the stencil buffer for every pixel drawn. 1 is the default.
     * </p>
     * 
     * @param stencilValue The value to set in the stencil buffer for every pixel drawn.
     */
    public void setStencilValue(final int stencilValue)
    {
        fStencilValue = stencilValue;
    }
}