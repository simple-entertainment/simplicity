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

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.vector.SimpleTranslationVectorf4;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * A {@link com.se.simplicity.model.VertexGroup VertexGroup} that contains its vertices in arrays.
 * </p>
 * 
 * <p>
 * Three separate arrays are used to store the information for the vertices. One for the coordinates, one for the colours and one for the surface
 * normals.
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
public class ArrayVG implements VertexGroup
{
    /**
     * <p>
     * The serialisation version of this class.
     * </p>
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * The colours of all the vertices in this <code>ArrayVG</code>.
     * </p>
     */
    private float[] fColours;

    /**
     * <p>
     * The index in the parent <code>ArrayVG</code> from which the data in this <code>ArrayVG</code> was copied.
     * </p>
     */
    private int fIndexWithinParent;

    /**
     * <p>
     * The subset status. Determines if this <code>ArrayVG</code> is a subgroup of a parent <code>ArrayVG</code>. Subset <code>ArrayVG</code>s contain
     * a copy of a subset of the parent <code>ArrayVG</code>s data.
     * </p>
     */
    private boolean fIsSubset;

    /**
     * <p>
     * The surface normals of all the vertices in this <code>ArrayVG</code>.
     * </p>
     */
    private float[] fNormals;

    /**
     * <p>
     * The parent of this <code>ArrayVG</code>. The parent should be set to <code>null</code> unless this <code>ArrayVG</code> is a subset.
     * </p>
     */
    private ArrayVG fParent;

    /**
     * <p>
     * The coordinates of all the vertices in this <code>ArrayVG</code>.
     * </p>
     */
    private float[] fVertices;

    /**
     * <p>
     * Creates an instance of <code>ArrayVG</code>.
     * </p>
     */
    public ArrayVG()
    {
        fIndexWithinParent = -1;
        fIsSubset = false;
        fParent = null;
    }

    /**
     * <p>
     * Creates an instance of <code>ArrayVG</code>. This constructor should only be used when creating subset <code>ArrayVG</code> s.
     * </p>
     * 
     * @param parent The parent of this <code>ArrayVG</code>.
     */
    protected ArrayVG(final ArrayVG parent)
    {
        fParent = parent;

        fIndexWithinParent = -1;
        fIsSubset = true;
    }

    @Override
    public VertexGroup createEdgeSubsetVG(final int index)
    {
        return (createSubsetVG(index, 2));
    }

    @Override
    public VertexGroup createFaceSubsetVG(final int index)
    {
        return (createSubsetVG(index * VERTICES_IN_A_FACE, VERTICES_IN_A_FACE));
    }

    @Override
    public VertexGroup createSubsetVG(final int index, final int length)
    {
        float[] subsetColours = new float[length * ITEMS_IN_CNV];
        float[] subsetNormals = new float[length * ITEMS_IN_CNV];
        float[] subsetVertices = new float[length * ITEMS_IN_CNV];

        System.arraycopy(fColours, index * ITEMS_IN_CNV, subsetColours, 0, subsetColours.length);
        System.arraycopy(fNormals, index * ITEMS_IN_CNV, subsetNormals, 0, subsetNormals.length);
        System.arraycopy(fVertices, index * ITEMS_IN_CNV, subsetVertices, 0, subsetVertices.length);

        ArrayVG subsetVertexGroup = new ArrayVG(this);
        subsetVertexGroup.setIndexWithinParent(index);
        subsetVertexGroup.setColours(subsetColours);
        subsetVertexGroup.setNormals(subsetNormals);
        subsetVertexGroup.setVertices(subsetVertices);

        return (subsetVertexGroup);
    }

    @Override
    public VertexGroup createVertexSubsetVG(final int index)
    {
        return (createSubsetVG(index, 1));
    }

    @Override
    public TranslationVectorf getCenter()
    {
        SimpleTranslationVectorf4 translation = new SimpleTranslationVectorf4();
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        int vertexCount = fVertices.length / ITEMS_IN_CNV;
        for (int vertexIndex = 0; vertexIndex < vertexCount; vertexIndex++)
        {
            x += fVertices[vertexIndex * ITEMS_IN_CNV];
            y += fVertices[vertexIndex * ITEMS_IN_CNV + 1];
            z += fVertices[vertexIndex * ITEMS_IN_CNV + 2];
        }

        x /= vertexCount;
        y /= vertexCount;
        z /= vertexCount;

        translation.setX(x);
        translation.setY(y);
        translation.setZ(z);

        return (translation);
    }

    /**
     * <p>
     * Retrieves the colours of all the vertices in this <code>ArrayVG</code>.
     * </p>
     * 
     * @return The colours of all the vertices in this <code>ArrayVG</code>.
     */
    public float[] getColours()
    {
        return (fColours);
    }

    @Override
    public int getIndexWithinParent()
    {
        return (fIndexWithinParent);
    }

    /**
     * <p>
     * Retrieves the surface normals of all the vertices in this <code>ArrayVG</code>.
     * </p>
     * 
     * @return The surface normals of all the vertices in this <code>ArrayVG</code>.
     */
    public float[] getNormals()
    {
        return (fNormals);
    }

    @Override
    public VertexGroup getParent()
    {
        return (fParent);
    }

    @Override
    public int getVertexCount()
    {
        return (fVertices.length / ITEMS_IN_CNV);
    }

    /**
     * <p>
     * Retrieves the coordinates of all the vertices in this <code>ArrayVG</code>.
     * </p>
     * 
     * @return The coordinates of all the vertices in this <code>ArrayVG</code>.
     */
    public float[] getVertices()
    {
        return (fVertices);
    }

    @Override
    public boolean isSubset()
    {
        return (fIsSubset);
    }

    @Override
    public void mergeWithParent() throws SEInvalidOperationException
    {
        if (!fIsSubset)
        {
            throw new SEInvalidOperationException("Cannot merge this Vertex Group because it is not a subset.");
        }

        System.arraycopy(fColours, 0, ((ArrayVG) fParent).getColours(), fIndexWithinParent * ITEMS_IN_CNV, fColours.length);
        System.arraycopy(fNormals, 0, ((ArrayVG) fParent).getNormals(), fIndexWithinParent * ITEMS_IN_CNV, fNormals.length);
        System.arraycopy(fVertices, 0, ((ArrayVG) fParent).getVertices(), fIndexWithinParent * ITEMS_IN_CNV, fVertices.length);
    }

    /**
     * <p>
     * Sets the colours of all the vertices in this <code>ArrayVG</code>.
     * </p>
     * 
     * @param colours The colours of all the vertices in this <code>ArrayVG</code>.
     */
    public void setColours(final float[] colours)
    {
        fColours = colours;
    }

    @Override
    public void setIndexWithinParent(final int indexWithinParent)
    {
        fIndexWithinParent = indexWithinParent;
    }

    /**
     * <p>
     * Sets the surface normals of all the vertices in this <code>ArrayVG</code>.
     * </p>
     * 
     * @param normals The surface normals of all the vertices in this <code>ArrayVG</code>.
     */
    public void setNormals(final float[] normals)
    {
        fNormals = normals;
    }

    /**
     * <p>
     * Sets the coordinates of all the vertices in this <code>ArrayVG</code>.
     * </p>
     * 
     * @param vertices The coordinates of all the vertices in this <code>ArrayVG</code>.
     */
    public void setVertices(final float[] vertices)
    {
        fVertices = vertices;
    }
}
