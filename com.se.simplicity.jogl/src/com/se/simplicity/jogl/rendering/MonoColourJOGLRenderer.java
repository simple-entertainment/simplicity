/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.rendering;

import static com.se.simplicity.model.ModelConstants.CNV_ITEMS_IN_FACE;
import static com.se.simplicity.model.ModelConstants.ITEMS_IN_CNV;
import static com.se.simplicity.model.ModelConstants.VERTICES_IN_A_FACE;

import javax.media.opengl.GL;

import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.vector.RGBColourVectorf;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;

/**
 * <p>
 * Renders a {@link com.se.simplicity.model.VertexGroup VertexGroup} using only one colour in a JOGL environment.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MonoColourJOGLRenderer extends SimpleJOGLRenderer
{
    /**
     * <p>
     * The colour to render the {@link com.se.simplicity.model.VertexGroup VertexGroup} in.
     * </p>
     */
    private RGBColourVectorf fRenderColour;

    /**
     * <p>
     * Retrieves the colour to render the {@link com.se.simplicity.model.VertexGroup VertexGroup} in.
     * </p>
     * 
     * @return The colour to render the {@link com.se.simplicity.model.VertexGroup VertexGroup} in.
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

        for (int faceIndex = 0; faceIndex < vertices.length / CNV_ITEMS_IN_FACE; faceIndex++)
        {
            gl.glBegin(getJOGLDrawingMode(getDrawingMode()));
            {
                for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
                {
                    int vertex = faceIndex * CNV_ITEMS_IN_FACE + vertexIndex;

                    gl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
                    gl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
                }
            }
            gl.glEnd();
        }
    }

    @Override
    protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup)
    {
        GL gl = getGL();

        int[] indices = vertexGroup.getIndices();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();
        int vertex;

        for (int faceIndex = 0; faceIndex < indices.length / VERTICES_IN_A_FACE; faceIndex++)
        {
            gl.glBegin(getJOGLDrawingMode(getDrawingMode()));
            {
                for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
                {
                    vertex = indices[faceIndex * VERTICES_IN_A_FACE] * ITEMS_IN_CNV + vertexIndex;

                    gl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
                    gl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
                }
            }
            gl.glEnd();
        }
    }

    /**
     * <p>
     * Sets the colour to render the {@link com.se.simplicity.model.VertexGroup VertexGroup} in.
     * </p>
     * 
     * @param renderColour The colour to render the {@link com.se.simplicity.model.VertexGroup VertexGroup} in.
     */
    public void setRenderColour(final RGBColourVectorf renderColour)
    {
        fRenderColour = renderColour;
    }
}
