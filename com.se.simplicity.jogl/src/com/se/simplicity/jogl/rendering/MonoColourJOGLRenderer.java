/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.rendering;

import static com.se.simplicity.model.ModelConstants.ITEMS_IN_CNV;

import javax.media.opengl.GL;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.vector.RGBColourVectorf;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;

/**
 * <p>
 * Renders a {@link com.se.simplicity.model.Model Model} using only one colour in a JOGL environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MonoColourJOGLRenderer extends SimpleJOGLRenderer
{
    /**
     * <p>
     * The colour to render the {@link com.se.simplicity.model.Model Model} in.
     * </p>
     */
    private RGBColourVectorf fRenderColour;

    /**
     * <p>
     * Retrieves the colour to render the {@link com.se.simplicity.model.Model Model} in.
     * </p>
     * 
     * @return The colour to render the {@link com.se.simplicity.model.Model Model} in.
     */
    public RGBColourVectorf getRenderColour()
    {
        return (fRenderColour);
    }

    /**
     * <p>
     * Creates an instance of <code>MonoColourJOGLRenderer</code>.
     * </p>
     */
    public MonoColourJOGLRenderer()
    {
        fRenderColour = new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 1.0f);
    }

    @Override
    public void init()
    {
        GL gl = getGL();

        gl.glColor3f(fRenderColour.getRed(), fRenderColour.getGreen(), fRenderColour.getBlue());
    }

    @Override
    protected void renderArrayVG(final ArrayVG vertexGroup)
    {
        GL gl = getGL();

        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();

        gl.glBegin(getJOGLDrawingMode(getDrawingMode()));
        {
            for (int index = 0; index < vertices.length; index += ITEMS_IN_CNV)
            {
                gl.glNormal3f(normals[index], normals[index + 1], normals[index + 2]);
                gl.glVertex3f(vertices[index], vertices[index + 1], vertices[index + 2]);
            }
        }
        gl.glEnd();
    }

    @Override
    protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup)
    {
        GL gl = getGL();

        int[] indices = vertexGroup.getIndices();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();

        gl.glBegin(getJOGLDrawingMode(getDrawingMode()));
        {
            for (int indicesIndex = 0; indicesIndex < indices.length; indicesIndex++)
            {
                int vertexIndex = indices[indicesIndex] * ITEMS_IN_CNV;

                gl.glNormal3f(normals[vertexIndex], normals[vertexIndex + 1], normals[vertexIndex + 2]);
                gl.glVertex3f(vertices[vertexIndex], vertices[vertexIndex + 1], vertices[vertexIndex + 2]);
            }
        }
        gl.glEnd();
    }

    /**
     * <p>
     * Sets the colour to render the {@link com.se.simplicity.model.Model Model} in.
     * </p>
     * 
     * @param renderColour The colour to render the {@link com.se.simplicity.model.Model Model} in.
     */
    public void setRenderColour(final RGBColourVectorf renderColour)
    {
        fRenderColour = renderColour;
    }
}
