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

import com.se.simplicity.SENotSupportedException;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * Renders the outline of a {@link com.se.simplicity.model.VertexGroup VertexGroup} in a JOGL environment. Achieves this using the stencil buffer
 * technique.
 * </p>
 * 
 * @author Gary Buyn
 */
public class OutlineJOGLRenderer implements Renderer, JOGLComponent
{
    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL fGl;
    private AlwaysStencilJOGLRenderer fAlwaysStencil;
    private MonoColourJOGLRenderer fMonoColour;
    private NotEqualStencilJOGLRenderer fNotEqualStencil;

    public OutlineJOGLRenderer(final Renderer renderer)
    {
        fAlwaysStencil = new AlwaysStencilJOGLRenderer(renderer);
        fMonoColour = new MonoColourJOGLRenderer();
        fNotEqualStencil = new NotEqualStencilJOGLRenderer(fMonoColour);
    }

    @Override
    public void dispose()
    {
        // Revert drawing settings.
        fGl.glLineWidth(1.0f);
    }

    @Override
    public DrawingMode getDrawingMode()
    {
        throw new SENotSupportedException("This implementation manages the Drawing Mode internally");
    }

    @Override
    public GL getGL()
    {
        return (fGl);
    }

    @Override
    public void init()
    {
        // Set outline width.
        fGl.glLineWidth(3.0f);
    }

    @Override
    public void renderVertexGroup(final VertexGroup vertexGroup)
    {
        fAlwaysStencil.init();
        fAlwaysStencil.renderVertexGroup(vertexGroup);
        fAlwaysStencil.dispose();

        fGl.glPolygonMode(GL.GL_FRONT_AND_BACK, GL.GL_LINE);

        fNotEqualStencil.init();
        fNotEqualStencil.renderVertexGroup(vertexGroup);
        fNotEqualStencil.dispose();

        fGl.glPolygonMode(GL.GL_FRONT_AND_BACK, GL.GL_FILL);
    }

    @Override
    public void setDrawingMode(final DrawingMode mode)
    {
        throw new SENotSupportedException("This implementation manages the Drawing Mode internally");
    }

    @Override
    public void setGL(final GL gl)
    {
        fGl = gl;

        fAlwaysStencil.setGL(gl);
        fMonoColour.setGL(gl);
        fNotEqualStencil.setGL(gl);
    }
}
