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

import com.se.simplicity.model.Model;
import com.se.simplicity.vector.RGBColourVectorf;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;

/**
 * <p>
 * Renders the front and back sides of polygons with different colours so that faces that are being erroneously culled can be corrected.
 * </p>
 * 
 * @author Gary Buyn
 */
public class CullFaceJOGLRenderer extends MonoColourJOGLRenderer
{
    /**
     * <p>
     * The colour to render the back side of the faces with.
     * </p>
     */
    private RGBColourVectorf fBackFaceColour;

    /**
     * <p>
     * The colour to render the front side of the faces with.
     * </p>
     */
    private RGBColourVectorf fFrontFaceColour;

    /**
     * <p>
     * State information about the JOGL rendering environment before this <code>CullFaceJOGLRenderer</code> is executed.
     * </p>
     */
    private byte[] fJoglByteParams;

    /**
     * <p>
     * State information about the JOGL rendering environment before this <code>CullFaceJOGLRenderer</code> is executed.
     * </p>
     */
    private int[] fJoglIntParams;

    /**
     * <p>
     * Creates an instance of <code>CullFaceJOGLRenderer</code>.
     * </p>
     */
    public CullFaceJOGLRenderer()
    {
        fBackFaceColour = new SimpleRGBColourVectorf4(1.0f, 0.0f, 0.0f, 1.0f);
        fFrontFaceColour = new SimpleRGBColourVectorf4(0.0f, 1.0f, 0.0f, 1.0f);
        fJoglByteParams = new byte[1];
        fJoglIntParams = new int[1];
    }

    @Override
    public void dispose()
    {
        GL gl = getGL();

        if (fJoglByteParams[0] == 0)
        {
            gl.glDisable(GL.GL_CULL_FACE);
        }

        if (fJoglIntParams[0] == GL.GL_CW)
        {
            gl.glFrontFace(GL.GL_CW);
        }
        else
        {
            gl.glFrontFace(GL.GL_CCW);
        }

        super.dispose();
    }

    /**
     * <p>
     * Retrieves the colour to render the back side of the faces with. The default is green.
     * </p>
     * 
     * @return The colour to render the back side of the faces with.
     */
    public RGBColourVectorf getBackFaceColour()
    {
        return (fBackFaceColour);
    }

    /**
     * <p>
     * Retrieves the colour to render the front side of the faces with. The default is green.
     * </p>
     * 
     * @return The colour to render the front side of the faces with.
     */
    public RGBColourVectorf getFrontFaceColour()
    {
        return (fFrontFaceColour);
    }

    @Override
    public void init()
    {
        GL gl = getGL();

        gl.glGetBooleanv(GL.GL_CULL_FACE, fJoglByteParams, 0);
        gl.glEnable(GL.GL_CULL_FACE);

        gl.glGetIntegerv(GL.GL_FRONT_FACE, fJoglIntParams, 0);
    }

    @Override
    public void renderModel(final Model model)
    {
        GL gl = getGL();

        // Prepare for rendering of the back sides.
        if (fJoglIntParams[0] == GL.GL_CW)
        {
            gl.glFrontFace(GL.GL_CCW);
        }
        else
        {
            gl.glFrontFace(GL.GL_CW);
        }
        setRenderColour(fBackFaceColour);

        super.init();
        super.renderModel(model);

        // Prepare for rendering of the front sides.
        if (fJoglIntParams[0] == GL.GL_CW)
        {
            gl.glFrontFace(GL.GL_CW);
        }
        else
        {
            gl.glFrontFace(GL.GL_CCW);
        }
        setRenderColour(fFrontFaceColour);

        super.init();
        super.renderModel(model);
    }

    /**
     * <p>
     * Sets the colour to render the back side of the faces with. The default is green.
     * </p>
     * 
     * @param backFaceColour The colour to render the back side of the faces with.
     */
    public void setBackFaceColour(final RGBColourVectorf backFaceColour)
    {
        fBackFaceColour = backFaceColour;
    }

    /**
     * <p>
     * Sets the colour to render the front side of the faces with. The default is green.
     * </p>
     * 
     * @param frontFaceColour The colour to render the front side of the faces with.
     */
    public void setFrontFaceColour(final RGBColourVectorf frontFaceColour)
    {
        fFrontFaceColour = frontFaceColour;
    }

    /**
     * <p>
     * The value of the <code>renderColour</code> is ignored by this implementation. To change the colour the front or back faces are rendered in, use
     * {@link #setFrontFaceColour(RGBColourVectorf)} and {@link #setBackFaceColour(RGBColourVectorf)}.
     * </p>
     * 
     * @param renderColour The colour to render the {@link com.se.simplicity.model.Model Model} in.
     */
    @Override
    public void setRenderColour(final RGBColourVectorf renderColour)
    {
        super.setRenderColour(renderColour);
    }
}
