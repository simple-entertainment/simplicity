/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.model;

import static com.se.simplicity.model.ModelConstants.ITEMS_IN_CNV;
import static com.se.simplicity.model.ModelConstants.VERTICES_IN_A_FACE;

import java.io.Serializable;

import com.se.simplicity.SEInvalidOperationException;

/**
 * <p>
 * A vertex group based on an indexed array of vertices.
 * </p>
 * 
 * <p>
 * Three separate arrays are actually used to store the information for the vertices. One for the coordinates, one for the colours and one for the
 * surface normals. A fourth array contains indexes. This array makes it possible to create a sequence of vertices from the other three arrays without
 * the need to repeat vertices in those arrays.
 * </p>
 * 
 * <p>
 * This kind of vertex group can have a smaller memory footprint and/or faster processing than the standard array of vertices (as used by the
 * <code>ArrayVG</code>) in some situations.
 * </p>
 * 
 * <p>
 * Each vertex is stored as three consecutive values in each array as follows:
 * </p>
 * 
 * <pre>
 * coordinates = {x1, y1, z1, x2, y2, z2, x3, y3, z3,..}
 * colours = {r1, g1, b1, r2, g2, b2, r3, g3, b3,..}
 * surface normals = {x1, y1, z1, x2, y2, z2, x3, y3, z3,..}
 * </pre>
 * 
 * <p>
 * For all the arrays the numbers show which vertex the value relates to. For coordinates, the letters x, y and z show which axis the value relates
 * to. For colours the letters r, g and b show which component of the RGB colour model the value relates to. For surface normals the letters x, y and
 * z show which axis the value relates to.
 * </p>
 * 
 * @author Gary Buyn
 */
public class IndexedArrayVG implements VertexGroup, Serializable
{
    /**
     * The serialisation version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * The colours of all the vertices in this <code>IndexedArrayVG</code>.
     */
    private float[] colours;

    /**
     * <p>
     * The index of the vertex in the parent <code>IndexedArrayVG</code> from which the data in this <code>IndexedArrayVG</code> was copied.
     * </p>
     */
    private int indexWithinParent;

    /**
     * <p>
     * The subset status. Determines if this <code>IndexedArrayVG</code> is a subgroup of a parent <code>IndexedArrayVG</code>. Subset
     * <code>IndexedArrayVG</code>s contain a copy of a subset of the parent <code>IndexedArrayVG</code>s data.
     * </p>
     */
    private boolean isSubset;

    /**
     * The indices of all the vertices in this <code>IndexedArrayVG</code>.
     */
    private int[] indices;

    /**
     * The surface normals of all the vertices in this <code>IndexedArrayVG</code>.
     */
    private float[] normals;

    /**
     * <p>
     * The parent of this <code>IndexedArrayVG</code>. The parent should be set to <code>null</code> unless this <code>IndexedArrayVG</code> is a
     * subset.
     * </p>
     */
    private VertexGroup parent;

    /**
     * The coordinates of all the vertices in this <code>IndexedArrayVG</code>.
     */
    private float[] vertices;

    /**
     * <p>
     * Creates an instance of <code>IndexedArrayVG</code>.
     * </p>
     */
    public IndexedArrayVG()
    {
        indexWithinParent = -1;
        isSubset = false;
        parent = null;
    }

    /**
     * <p>
     * Creates an instance of <code>IndexedArrayVG</code>. This constructer should be used when creating subset <code>VertexGroup</code>s.
     * </p>
     * 
     * @param newParent The parent of this <code>VertexGroup</code>.
     */
    protected IndexedArrayVG(final VertexGroup newParent)
    {
        parent = newParent;

        indexWithinParent = -1;
        isSubset = true;
    }

    /**
     * <p>
     * Retrieves the colours of all the vertices in this <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @return The colours of all the vertices in this <code>IndexedArrayVG</code>.
     */
    public float[] getColours()
    {
        return (colours);
    }

    /**
     * <p>
     * Retrieves the index of the vertex in the parent <code>ArrayVG</code> from which the data in this <code>ArrayVG</code> was copied.
     * </p>
     * 
     * @return The index of the vertex in the parent <code>ArrayVG</code> from which the data in this <code>ArrayVG</code> was copied.
     */
    public int getIndexWithinParent()
    {
        return (indexWithinParent);
    }

    /**
     * <p>
     * Retrieves the indices of all the vertices in this <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @return The indices of all the vertices in this <code>IndexedArrayVG</code>.
     */
    public int[] getIndices()
    {
        return (indices);
    }

    /**
     * <p>
     * Retrieves the surface normals of all the vertices in this <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @return The surface normals of all the vertices in this <code>IndexedArrayVG</code>.
     */
    public float[] getNormals()
    {
        return (normals);
    }

    /**
     * <p>
     * Retrieves the coordinates of all the vertices in this <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @return The coordinates of all the vertices in this <code>IndexedArrayVG</code>.
     */
    public float[] getVertices()
    {
        return (vertices);
    }

    /**
     * <p>
     * Sets the colours of all the vertices in this <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @param newColours The colours of all the vertices in this <code>IndexedArrayVG</code>.
     */
    public void setColours(final float[] newColours)
    {
        colours = newColours;
    }

    /**
     * <p>
     * Sets the index of the vertex in the parent <code>IndexedArrayVG</code> from which the data in this <code>IndexedArrayVG</code> was copied.
     * </p>
     * 
     * @param newIndexWithinParent The index of the vertex in the parent <code>IndexedArrayVG</code> from which the data in this
     * <code>IndexedArrayVG</code> was copied.
     */
    public void setIndexWithinParent(final int newIndexWithinParent)
    {
        indexWithinParent = newIndexWithinParent;
    }

    /**
     * <p>
     * Sets the indices of all the vertices in this <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @param newIndices The indices of all the vertices in this <code>IndexedArrayVG</code>.
     */
    public void setIndices(final int[] newIndices)
    {
        indices = newIndices;
    }

    /**
     * <p>
     * Sets the surface normals of all the vertices in this <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @param newNormals The surface normals of all the vertices in this <code>IndexedArrayVG</code>.
     */
    public void setNormals(final float[] newNormals)
    {
        normals = newNormals;
    }

    /**
     * <p>
     * Sets the coordinates of all the vertices in this <code>IndexedArrayVG</code>.
     * </p>
     * 
     * @param newVertices The coordinates of all the vertices in this <code>IndexedArrayVG</code>.
     */
    public void setVertices(final float[] newVertices)
    {
        vertices = newVertices;
    }

    @Override
    public VertexGroup createSubsetVG(final int index, final int length)
    {
        int[] subsetIndices = new int[length];
        float[] subsetColours = new float[length * ITEMS_IN_CNV];
        float[] subsetNormals = new float[length * ITEMS_IN_CNV];
        float[] subsetVertices = new float[length * ITEMS_IN_CNV];

        System.arraycopy(indices, index, subsetIndices, 0, subsetIndices.length);

        for (int currentIndex = 0; currentIndex < subsetIndices.length; currentIndex++)
        {
            System.arraycopy(colours, subsetIndices[currentIndex] * ITEMS_IN_CNV, subsetColours, currentIndex * ITEMS_IN_CNV, ITEMS_IN_CNV);
            System.arraycopy(normals, subsetIndices[currentIndex] * ITEMS_IN_CNV, subsetNormals, currentIndex * ITEMS_IN_CNV, ITEMS_IN_CNV);
            System.arraycopy(vertices, subsetIndices[currentIndex] * ITEMS_IN_CNV, subsetVertices, currentIndex * ITEMS_IN_CNV, ITEMS_IN_CNV);
        }

        IndexedArrayVG subsetVertexGroup = new IndexedArrayVG(this);
        subsetVertexGroup.setIndexWithinParent(index);
        subsetVertexGroup.setIndices(subsetIndices);
        subsetVertexGroup.setColours(subsetColours);
        subsetVertexGroup.setNormals(subsetNormals);
        subsetVertexGroup.setVertices(subsetVertices);

        return subsetVertexGroup;
    }

    @Override
    public VertexGroup createEdgeSubsetVG(final int index)
    {
        return createSubsetVG(index, 2);
    }

    @Override
    public VertexGroup createFaceSubsetVG(final int index)
    {
        return createSubsetVG(index * VERTICES_IN_A_FACE, VERTICES_IN_A_FACE);
    }

    @Override
    public VertexGroup createVertexSubsetVG(final int index)
    {
        return createSubsetVG(index, 1);
    }

    @Override
    public VertexGroup getParent()
    {
        return (parent);
    }

    @Override
    public boolean isSubset()
    {
        return (isSubset);
    }

    @Override
    public void mergeWithParent() throws SEInvalidOperationException
    {
        if (!isSubset)
        {
            throw new SEInvalidOperationException("Cannot merge this Vertex Group because it is not a subset.");
        }

        for (int currentIndex = 0; currentIndex < indices.length; currentIndex++)
        {
            int parentCopyIndex = ((IndexedArrayVG) parent).getIndices()[indexWithinParent + currentIndex];

            System.arraycopy(colours, indices[currentIndex] * ITEMS_IN_CNV, ((IndexedArrayVG) parent).getColours(), parentCopyIndex * ITEMS_IN_CNV,
                    ITEMS_IN_CNV);
            System.arraycopy(normals, indices[currentIndex] * ITEMS_IN_CNV, ((IndexedArrayVG) parent).getNormals(), parentCopyIndex * ITEMS_IN_CNV,
                    ITEMS_IN_CNV);
            System.arraycopy(vertices, indices[currentIndex] * ITEMS_IN_CNV, ((IndexedArrayVG) parent).getVertices(), parentCopyIndex * ITEMS_IN_CNV,
                    ITEMS_IN_CNV);
        }
    }
}
