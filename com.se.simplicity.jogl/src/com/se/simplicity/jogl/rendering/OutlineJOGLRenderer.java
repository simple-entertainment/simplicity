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
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.vector.RGBColourVectorf;

/**
 * <p>
 * Renders the {@link com.se.simplicity.model.Model Model} in a JOGL environment using a wrapped {@link com.se.simplicity.rendering.Renderer Renderer}
 * and adds an outline. Achieves this using the stencil buffer technique.
 * </p>
 * 
 * @author Gary Buyn
 */
public class OutlineJOGLRenderer implements Renderer, JOGLComponent
{
    /**
     * <p>
     * The default width of the outline.
     * </p>
     */
    private static final float DEFAULT_OUTLINE_WIDTH = 3.0f;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Renderer Renderer} used to perform the first rendering pass (the normal object).
     * </p>
     */
    private AlwaysStencilJOGLRenderer fAlwaysStencil;

    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL fGl;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Renderer Renderer} used in the second rendering pass to ensure the colours in the object are ignored
     * when drawing the outline.
     * </p>
     */
    private MonoColourJOGLRenderer fMonoColour;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Renderer Renderer} used to perform the second rendering pass (the outline).
     * </p>
     */
    private NotEqualStencilJOGLRenderer fNotEqualStencil;

    /**
     * <p>
     * The width of the outline.
     * </p>
     */
    private float fOutlineWidth;

    /**
     * <p>
     * Creates an instance of <code>OutlineJOGLRenderer</code>.
     * </p>
     */
    public OutlineJOGLRenderer()
    {
        fMonoColour = new MonoColourJOGLRenderer();
        fAlwaysStencil = new AlwaysStencilJOGLRenderer(fMonoColour);
        fNotEqualStencil = new NotEqualStencilJOGLRenderer(fMonoColour);
        fOutlineWidth = DEFAULT_OUTLINE_WIDTH;
    }

    @Override
    public void dispose()
    {}

    @Override
    public DrawingMode getDrawingMode()
    {
        return (fMonoColour.getDrawingMode());
    }

    @Override
    public GL getGL()
    {
        return (fGl);
    }

    /**
     * <p>
     * Retrieves the colour of the outline. White is the default.
     * </p>
     * 
     * @return The colour of the outline.
     */
    public RGBColourVectorf getOutlineColour()
    {
        return (fMonoColour.getRenderColour());
    }

    /**
     * <p>
     * Retrieves the width of the outline. This is actually the width of the line used to draw the outline, only half of which will actually be
     * visible. 3 is the default.
     * </p>
     * 
     * @return The width of the outline.
     */
    public float getOutlineWidth()
    {
        return (fOutlineWidth);
    }

    @Override
    public void init()
    {}

    @Override
    public void renderModel(final Model model)
    {
        byte[] lightingEnabledParams = new byte[1];
        fGl.glGetBooleanv(GL.GL_LIGHTING, lightingEnabledParams, 0);
        byte[] cullFaceEnabledParams = new byte[1];
        fGl.glGetBooleanv(GL.GL_CULL_FACE, cullFaceEnabledParams, 0);

        // Prepare for setting the stencil.
        fGl.glDrawBuffer(GL.GL_NONE);
        if (cullFaceEnabledParams[0] == 1)
        {
            fGl.glDisable(GL.GL_CULL_FACE);
        }

        fAlwaysStencil.init();
        fAlwaysStencil.renderModel(model);
        fAlwaysStencil.dispose();

        // Restore rendering environment settings.
        fGl.glDrawBuffer(GL.GL_BACK);

        // Prepare for rendering the outline.

        if (lightingEnabledParams[0] == 1)
        {
            fGl.glDisable(GL.GL_LIGHTING);
        }

        // If outlines need to be drawn for the edges or faces, draw them.
        if (getDrawingMode() != DrawingMode.VERTICES)
        {
            fGl.glPolygonMode(GL.GL_FRONT_AND_BACK, GL.GL_LINE);
            fGl.glLineWidth(fOutlineWidth);

            fNotEqualStencil.init();
            fNotEqualStencil.renderModel(model);
            fNotEqualStencil.dispose();

            fGl.glLineWidth(1.0f);
        }

        // Draw outlines for the vertices (if edges or faces are being drawn this just gives nice rounded corners).
        fGl.glPolygonMode(GL.GL_FRONT_AND_BACK, GL.GL_POINT);
        fGl.glPointSize(fOutlineWidth);

        fNotEqualStencil.init();
        fNotEqualStencil.renderModel(model);
        fNotEqualStencil.dispose();

        fGl.glPointSize(1.0f);

        // Restore rendering environment settings.
        fGl.glPolygonMode(GL.GL_FRONT_AND_BACK, GL.GL_FILL);
        if (lightingEnabledParams[0] == 1)
        {
            fGl.glEnable(GL.GL_LIGHTING);
        }
        if (cullFaceEnabledParams[0] == 1)
        {
            fGl.glEnable(GL.GL_CULL_FACE);
        }
    }

    @Override
    public void setDrawingMode(final DrawingMode mode)
    {
        fMonoColour.setDrawingMode(mode);
    }

    @Override
    public void setGL(final GL gl)
    {
        fGl = gl;

        fAlwaysStencil.setGL(gl);
        fMonoColour.setGL(gl);
        fNotEqualStencil.setGL(gl);
    }

    /**
     * <p>
     * Sets the colour of the outline. White is the default.
     * </p>
     * 
     * @param outlineColour The colour of the outline.
     */
    public void setOutlineColour(final RGBColourVectorf outlineColour)
    {
        fMonoColour.setRenderColour(outlineColour);
    }

    /**
     * <p>
     * Sets the width of the outline. This is actually the width of the line used to draw the outline, only half of which will actually be visible. 3
     * is the default.
     * </p>
     * 
     * @param outlineWidth The width of the outline.
     */
    public void setOutlineWidth(final float outlineWidth)
    {
        fOutlineWidth = outlineWidth;
    }
}
