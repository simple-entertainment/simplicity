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
     * The drawing mode used to render the {@link com.se.simplicity.model.VertexGroup VertexGroup}s.
     * </p>
     */
    private DrawingMode fDrawingMode;
    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL fGl;

    /**
     * <p>
     * Creates an instance of <code>SimpleJOGLRenderer</code>.
     * </p>
     */
    public SimpleJOGLRenderer()
    {
        fDrawingMode = DrawingMode.FACES;
        fGl = null;
    }

    @Override
    public void dispose()
    {
        fGl.glPointSize(1.0f);
    }

    @Override
    public DrawingMode getDrawingMode()
    {
        return (fDrawingMode);
    }

    @Override
    public GL getGL()
    {
        return (fGl);
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
        fGl.glPointSize(2.0f);
    }

    /**
     * <p>
     * Renders an <code>ArrayVG</code>.
     * </p>
     * 
     * @param vertexGroup The <code>ArrayVG</code> to render.
     */
    protected void renderArrayVG(final ArrayVG vertexGroup)
    {
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();

        for (int faceIndex = 0; faceIndex < vertices.length / CNV_ITEMS_IN_FACE; faceIndex++)
        {
            fGl.glBegin(getJOGLDrawingMode(fDrawingMode));
            {
                for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
                {
                    int vertex = faceIndex * CNV_ITEMS_IN_FACE + vertexIndex;

                    fGl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
                    fGl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
                    fGl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
                }
            }
            fGl.glEnd();
        }
    }

    /**
     * <p>
     * Renders an <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @param vertexGroup The <code>IndexedArrayVG</code> to render.
     */
    protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup)
    {
        int[] indices = vertexGroup.getIndices();
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();
        int vertex;

        for (int faceIndex = 0; faceIndex < indices.length / VERTICES_IN_A_FACE; faceIndex++)
        {
            fGl.glBegin(getJOGLDrawingMode(fDrawingMode));
            {
                for (int vertexIndex = 0; vertexIndex < CNV_ITEMS_IN_FACE; vertexIndex += ITEMS_IN_CNV)
                {
                    vertex = indices[faceIndex * VERTICES_IN_A_FACE] * ITEMS_IN_CNV + vertexIndex;

                    fGl.glColor3f(colours[vertex], colours[vertex + 1], colours[vertex + 2]);
                    fGl.glNormal3f(normals[vertex], normals[vertex + 1], normals[vertex + 2]);
                    fGl.glVertex3f(vertices[vertex], vertices[vertex + 1], vertices[vertex + 2]);
                }
            }
            fGl.glEnd();
        }
    }

    @Override
    public void renderVertexGroup(final VertexGroup vertexGroup)
    {
        if (vertexGroup instanceof ArrayVG)
        {
            renderArrayVG((ArrayVG) vertexGroup);
        }
        else if (vertexGroup instanceof IndexedArrayVG)
        {
            renderIndexedArrayVG((IndexedArrayVG) vertexGroup);
        }
    }

    @Override
    public void setDrawingMode(final DrawingMode mode)
    {
        fDrawingMode = mode;
    }

    @Override
    public void setGL(final GL newGl)
    {
        fGl = newGl;
    }
}
