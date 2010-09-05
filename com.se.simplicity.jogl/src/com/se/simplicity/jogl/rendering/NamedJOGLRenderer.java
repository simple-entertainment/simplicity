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
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.NamedRenderer;

/**
 * <p>
 * This implementation names the <code>Model</code>s rendered as well as the primitives rendered (faces, edges or vertices).
 * <code>Model</code>s are named using their hash codes unless a specific name is given. The naming of the primitives is specific to the
 * <code>Model</code> implementation.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NamedJOGLRenderer extends SimpleJOGLRenderer implements NamedRenderer
{
    @Override
    protected void renderArrayVG(final ArrayVG vertexGroup)
    {
        if (getDrawingMode() == DrawingMode.EDGES)
        {
            renderArrayVGEdges(vertexGroup);
        }
        else if (getDrawingMode() == DrawingMode.FACES)
        {
            renderArrayVGFaces(vertexGroup);
        }
        else if (getDrawingMode() == DrawingMode.VERTICES)
        {
            renderArrayVGVertices(vertexGroup);
        }
    }

    /**
     * <p>
     * Renders the given <code>ArrayVG</code> naming the edges with consecutive integers beginning with zero. This means that the section of the
     * <code>ArrayVG</code>'s arrays containing data for a particular edge can be found as follows:
     * </p>
     * 
     * <p>
     * <code>int firstIndexOfEdgeSection = egdeName * 3;</code>
     * </p>
     * 
     * <p>
     * The section containing a particular edge consists of six consecutive items of data beginning at <code>firstIndexOfEdgeSection</code> in each
     * array.
     * </p>
     * 
     * @param vertexGroup The <code>ArrayVG</code> to render.
     */
    protected void renderArrayVGEdges(final ArrayVG vertexGroup)
    {
        GL gl = getGL();

        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();

        for (int edgeIndex = 0; edgeIndex < vertices.length / ITEMS_IN_CNV - 1; edgeIndex++)
        {
            gl.glPushName(edgeIndex);
            gl.glBegin(GL.GL_LINE_LOOP);
            {
                gl.glColor3f(colours[edgeIndex * ITEMS_IN_CNV], colours[edgeIndex * ITEMS_IN_CNV + 1], colours[edgeIndex * ITEMS_IN_CNV + 2]);
                gl.glNormal3f(normals[edgeIndex * ITEMS_IN_CNV], normals[edgeIndex * ITEMS_IN_CNV + 1], normals[edgeIndex * ITEMS_IN_CNV + 2]);
                gl.glVertex3f(vertices[edgeIndex * ITEMS_IN_CNV], vertices[edgeIndex * ITEMS_IN_CNV + 1], vertices[edgeIndex * ITEMS_IN_CNV + 2]);

                gl.glColor3f(colours[(edgeIndex + 1) * ITEMS_IN_CNV], colours[(edgeIndex + 1) * ITEMS_IN_CNV + 1], colours[(edgeIndex + 1)
                        * ITEMS_IN_CNV + 2]);
                gl.glNormal3f(normals[(edgeIndex + 1) * ITEMS_IN_CNV], normals[(edgeIndex + 1) * ITEMS_IN_CNV + 1], normals[(edgeIndex + 1)
                        * ITEMS_IN_CNV + 2]);
                gl.glVertex3f(vertices[(edgeIndex + 1) * ITEMS_IN_CNV], vertices[(edgeIndex + 1) * ITEMS_IN_CNV + 1], vertices[(edgeIndex + 1)
                        * ITEMS_IN_CNV + 2]);
            }
            gl.glEnd();
            gl.glPopName();
        }
    }

    /**
     * <p>
     * Renders the given <code>ArrayVG</code> naming the faces with consecutive integers beginning with zero. This means that the section of the
     * <code>ArrayVG</code>'s arrays containing data for a particular face can be found as follows:
     * </p>
     * 
     * <p>
     * <code>int firstIndexOfFaceSection = faceName * 9;</code>
     * </p>
     * 
     * <p>
     * The section containing a particular face consists of nine consecutive items of data beginning at <code>firstIndexOfFaceSection</code> in each
     * array.
     * </p>
     * 
     * @param vertexGroup The <code>ArrayVG</code> to render.
     */
    protected void renderArrayVGFaces(final ArrayVG vertexGroup)
    {
        GL gl = getGL();

        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();

        for (int faceIndex = 0; faceIndex < vertices.length / CNV_ITEMS_IN_FACE; faceIndex++)
        {
            gl.glPushName(faceIndex);
            gl.glBegin(GL.GL_TRIANGLES);
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
            gl.glPopName();
        }
    }

    /**
     * <p>
     * Renders the given <code>ArrayVG</code> naming the vertices with consecutive integers beginning with zero. This means that the section of the
     * <code>ArrayVG</code>'s arrays containing data for a particular vertex can be found as follows:
     * </p>
     * 
     * <p>
     * <code>int firstIndexOfVertexSection = vertexName * 3;</code>
     * </p>
     * 
     * <p>
     * The section containing a particular vertex consists of three consecutive items of data beginning at <code>firstIndexOfVertexSection</code> in
     * each array.
     * </p>
     * 
     * @param vertexGroup The <code>ArrayVG</code> to render.
     */
    protected void renderArrayVGVertices(final ArrayVG vertexGroup)
    {
        GL gl = getGL();

        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();

        for (int vertexIndex = 0; vertexIndex < vertices.length / ITEMS_IN_CNV; vertexIndex++)
        {
            gl.glPushName(vertexIndex);
            gl.glBegin(GL.GL_POINTS);
            {
                gl.glColor3f(colours[vertexIndex * ITEMS_IN_CNV], colours[vertexIndex * ITEMS_IN_CNV + 1], colours[vertexIndex * ITEMS_IN_CNV + 2]);
                gl.glNormal3f(normals[vertexIndex * ITEMS_IN_CNV], normals[vertexIndex * ITEMS_IN_CNV + 1], normals[vertexIndex * ITEMS_IN_CNV + 2]);
                gl.glVertex3f(vertices[vertexIndex * ITEMS_IN_CNV], vertices[vertexIndex * ITEMS_IN_CNV + 1],
                        vertices[vertexIndex * ITEMS_IN_CNV + 2]);
            }
            gl.glEnd();
            gl.glPopName();
        }
    }

    @Override
    protected void renderIndexedArrayVG(final IndexedArrayVG vertexGroup)
    {
        if (getDrawingMode() == DrawingMode.EDGES)
        {
            renderIndexedArrayVGEdges(vertexGroup);
        }
        else if (getDrawingMode() == DrawingMode.FACES)
        {
            renderIndexedArrayVGFaces(vertexGroup);
        }
        else if (getDrawingMode() == DrawingMode.VERTICES)
        {
            renderIndexedArrayVGVertices(vertexGroup);
        }
    }

    /**
     * <p>
     * Renders the given <code>IndexedArrayVG</code> naming the edges with consecutive integers beginning with zero. This means that the section of
     * the <code>ArrayVG</code>'s index array containing references to data for a particular edge can be found as follows:
     * </p>
     * 
     * <p>
     * <code>int firstIndexOfEdgeSection = edgeName;</code>
     * </p>
     * 
     * <p>
     * The section containing a particular vertex consists of two indices beginning at <code>firstIndexOfEdgeSection</code> in the index array.
     * </p>
     * 
     * @param vertexGroup The <code>IndexedArrayVG</code> to render.
     */
    protected void renderIndexedArrayVGEdges(final IndexedArrayVG vertexGroup)
    {
        GL gl = getGL();

        int[] indices = vertexGroup.getIndices();
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();
        int vertex;

        for (int edgeIndex = 0; edgeIndex < indices.length - 1; edgeIndex++)
        {
            vertex = indices[edgeIndex];

            gl.glPushName(vertex);
            gl.glBegin(GL.GL_LINE_LOOP);
            {
                gl.glColor3f(colours[vertex * ITEMS_IN_CNV], colours[vertex * ITEMS_IN_CNV + 1], colours[vertex * ITEMS_IN_CNV + 2]);
                gl.glNormal3f(normals[vertex * ITEMS_IN_CNV], normals[vertex * ITEMS_IN_CNV + 1], normals[vertex * ITEMS_IN_CNV + 2]);
                gl.glVertex3f(vertices[vertex * ITEMS_IN_CNV], vertices[vertex * ITEMS_IN_CNV + 1], vertices[vertex * ITEMS_IN_CNV + 2]);

                gl
                        .glColor3f(colours[(vertex + 1) * ITEMS_IN_CNV], colours[(vertex + 1) * ITEMS_IN_CNV + 1], colours[(vertex + 1)
                                * ITEMS_IN_CNV + 2]);
                gl.glNormal3f(normals[(vertex + 1) * ITEMS_IN_CNV], normals[(vertex + 1) * ITEMS_IN_CNV + 1],
                        normals[(vertex + 1) * ITEMS_IN_CNV + 2]);
                gl.glVertex3f(vertices[(vertex + 1) * ITEMS_IN_CNV], vertices[(vertex + 1) * ITEMS_IN_CNV + 1], vertices[(vertex + 1) * ITEMS_IN_CNV
                        + 2]);
            }
            gl.glEnd();
            gl.glPopName();
        }
    }

    /**
     * <p>
     * Renders the given <code>IndexedArrayVG</code> naming the faces with consecutive integers beginning with zero. This means that the section of
     * the <code>ArrayVG</code>'s index array containing references to data for a particular face can be found as follows:
     * </p>
     * 
     * <p>
     * <code>int firstIndexOfFaceSection = faceName * 3;</code>
     * </p>
     * 
     * <p>
     * The section containing a particular face consists of three consecutive indexes beginning at <code>firstIndexOfFaceSection</code> in the index
     * array.
     * </p>
     * 
     * @param vertexGroup The <code>IndexedArrayVG</code> to render.
     */
    protected void renderIndexedArrayVGFaces(final IndexedArrayVG vertexGroup)
    {
        GL gl = getGL();

        int[] indices = vertexGroup.getIndices();
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();
        int vertex;

        for (int faceIndex = 0; faceIndex < indices.length / VERTICES_IN_A_FACE; faceIndex++)
        {
            gl.glPushName(faceIndex);
            gl.glBegin(GL.GL_TRIANGLES);
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
            gl.glPopName();
        }
    }

    /**
     * <p>
     * Renders the given <code>IndexedArrayVG</code> naming the vertices with consecutive integers beginning with zero. This means that the section of
     * the <code>ArrayVG</code>'s index array containing references to data for a particular vertex can be found as follows:
     * </p>
     * 
     * <p>
     * <code>int firstIndexOfVertexSection = vertexName;</code>
     * </p>
     * 
     * <p>
     * The section containing a particular vertex consists of one index beginning at <code>firstIndexOfVertexSection</code> in the index array.
     * </p>
     * 
     * @param vertexGroup The <code>IndexedArrayVG</code> to render.
     */
    protected void renderIndexedArrayVGVertices(final IndexedArrayVG vertexGroup)
    {
        GL gl = getGL();

        int[] indices = vertexGroup.getIndices();
        float[] colours = vertexGroup.getColours();
        float[] normals = vertexGroup.getNormals();
        float[] vertices = vertexGroup.getVertices();
        int vertex;

        for (int vertexIndex = 0; vertexIndex < indices.length; vertexIndex++)
        {
            vertex = indices[vertexIndex];

            gl.glPushName(vertex);
            gl.glBegin(GL.GL_POINTS);
            {
                gl.glColor3f(colours[vertex * ITEMS_IN_CNV], colours[vertex * ITEMS_IN_CNV + 1], colours[vertex * ITEMS_IN_CNV + 2]);
                gl.glNormal3f(normals[vertex * ITEMS_IN_CNV], normals[vertex * ITEMS_IN_CNV + 1], normals[vertex * ITEMS_IN_CNV + 2]);
                gl.glVertex3f(vertices[vertex * ITEMS_IN_CNV], vertices[vertex * ITEMS_IN_CNV + 1], vertices[vertex * ITEMS_IN_CNV + 2]);
            }
            gl.glEnd();
            gl.glPopName();
        }
    }

    /**
     * <p>
     * Assigns the hash code of the <code>VertexGroup</code> being rendered as its name.
     * </p>
     * 
     * @param vertexGroup The <code>VertexGroup</code> to render.
     */
    @Override
    public void renderModel(final Model vertexGroup)
    {
        GL gl = getGL();

        gl.glPushName(vertexGroup.hashCode());

        super.renderModel(vertexGroup);

        gl.glPopName();
    }

    @Override
    public void renderModel(final Model model, final int name)
    {
        GL gl = getGL();

        gl.glPushName(name);

        super.renderModel(model);

        gl.glPopName();
    }
}
