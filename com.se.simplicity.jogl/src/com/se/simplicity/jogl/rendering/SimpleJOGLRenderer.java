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

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.model.ArrayVG;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * Renders a {@link com.se.simplicity.model.VertexGroup VertexGroup} in a JOGL environment. This implementation uses only simple rendering techniques
 * and properties.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLRenderer implements Renderer, JOGLComponent
{
    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL gl;

    @Override
    public GL getGL()
    {
        return (gl);
    }

    /**
     * <p>
     * Retrieves the JOGL drawing mode used to render the <code>VertexGroup</code>.
     * </p>
     * 
     * @param drawingMode The <code>DrawingMode</code> to retrieve the JOGL drawing mode for.
     * 
     * @return The JOGL drawing mode used to render the <code>VertexGroup</code>.
     */
    protected int getJOGLDrawingMode(final DrawingMode drawingMode)
    {
        int joglDrawingMode = -1;

        if (drawingMode == DrawingMode.VERTICES)
        {
            gl.glPointSize(2.0f);
            joglDrawingMode = GL.GL_POINTS;
        }
        else if (drawingMode == DrawingMode.EDGES)
        {
            joglDrawingMode = GL.GL_LINE_LOOP;
        }
        else if (drawingMode == DrawingMode.FACES)
        {
            joglDrawingMode = GL.GL_TRIANGLES;
        }

        return (joglDrawingMode);
    }

    @Override
    public void init()
    {
        // Initialise the JOGL state.
        gl.glEnable(GL.GL_CULL_FACE);
        gl.glDepthFunc(GL.GL_LEQUAL);
        gl.glEnable(GL.GL_DEPTH_TEST);
        gl.glFrontFace(GL.GL_CCW);

        // Enable model data arrays.
        gl.glEnableClientState(GL.GL_VERTEX_ARRAY);
    }

    /**
     * <p>
     * Renders an <code>ArrayVG</code>.
     * </p>
     * 
     * @param vertexGroup The <code>ArrayVG</code> to render.
     * @param drawingMode The <code>DrawingMode</code> used to render the <code>ArrayVG</code>.
     */
    protected void renderArrayVG(final ArrayVG vertexGroup, final DrawingMode drawingMode)
    {
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();

        for (int faceIndex = 0; faceIndex < vertices.length / CNV_ITEMS_IN_FACE; faceIndex++)
        {
            gl.glBegin(getJOGLDrawingMode(drawingMode));
            {
                for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
                {
                    int vertex = faceIndex * CNV_ITEMS_IN_FACE + vertexIndex;

                    gl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
                    gl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
                    gl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
                }
            }
            gl.glEnd();
        }
    }

    /**
     * <p>
     * Renders an <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @param vertexGroup The <code>IndexedArrayVG</code> to render.
     * @param drawingMode The <code>DrawingMode</code> used to render the <code>IndexedArrayVG</code>.
     */
    protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup, final DrawingMode drawingMode)
    {
        int[] indices = vertexGroup.getIndices();
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();
        int vertex;

        for (int faceIndex = 0; faceIndex < indices.length / VERTICES_IN_A_FACE; faceIndex++)
        {
            gl.glBegin(getJOGLDrawingMode(drawingMode));
            {
                for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
                {
                    vertex = indices[faceIndex * VERTICES_IN_A_FACE] * ITEMS_IN_CNV + vertexIndex;

                    gl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
                    gl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
                    gl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
                }
            }
            gl.glEnd();
        }
    }

    /**
     * <p>
     * Renders a <code>VertexGroup</code>.
     * </p>
     * 
     * @param vertexGroup The <code>VertexGroup</code> to render.
     * @param drawingMode The <code>DrawingMode</code> to render the <code>VertexGroup</code> with.
     */
    public void renderVertexGroup(final VertexGroup vertexGroup, final DrawingMode drawingMode)
    {
        if (vertexGroup instanceof ArrayVG)
        {
            renderArrayVG((ArrayVG) vertexGroup, drawingMode);
        }
        else if (vertexGroup instanceof IndexedArrayVG)
        {
            renderIndexedArrayVG((IndexedArrayVG) vertexGroup, drawingMode);
        }
    }

    @Override
    public void setGL(final GL newGl)
    {
        gl = newGl;
    }
}
