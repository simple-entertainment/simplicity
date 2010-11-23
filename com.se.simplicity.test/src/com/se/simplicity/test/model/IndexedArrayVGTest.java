/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.model;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.model.IndexedArrayVG;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.model.IndexedArrayVG IndexedArrayVG}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class IndexedArrayVGTest
{
    /**
     * An instance of the class being unit tested.
     */
    private IndexedArrayVG fTestObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        fTestObject = new IndexedArrayVG();

        fTestObject.setColours(new float[] {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f});
        fTestObject.setNormals(new float[] {-0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f});
        fTestObject.setVertices(new float[] {-1.0f, -1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f});
        fTestObject.setIndices(new int[] {0, 1, 2, 3});
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.model.IndexedArrayVG#createEdgeSubsetVG(int) createEdgeSubsetVG(int)}.
     * </p>
     */
    @Test
    public void createEdgeSubsetVG()
    {
        IndexedArrayVG subsetVG = (IndexedArrayVG) fTestObject.createEdgeSubsetVG(0);

        int[] subsetIndices = subsetVG.getIndices();

        assertEquals(2, subsetIndices.length, 0);
        assertEquals(0, subsetIndices[0], 0);
        assertEquals(1, subsetIndices[1], 0);

        float[] subsetColours = subsetVG.getColours();

        assertEquals(6, subsetColours.length, 0);
        assertEquals(1.0f, subsetColours[0], 0.0f);
        assertEquals(0.0f, subsetColours[1], 0.0f);
        assertEquals(0.0f, subsetColours[2], 0.0f);
        assertEquals(0.0f, subsetColours[3], 0.0f);
        assertEquals(1.0f, subsetColours[4], 0.0f);
        assertEquals(0.0f, subsetColours[5], 0.0f);

        float[] subsetNormals = subsetVG.getNormals();

        assertEquals(6, subsetNormals.length, 0);
        assertEquals(-0.5f, subsetNormals[0], 0.0f);
        assertEquals(-0.5f, subsetNormals[1], 0.0f);
        assertEquals(0.0f, subsetNormals[2], 0.0f);
        assertEquals(-0.5f, subsetNormals[3], 0.0f);
        assertEquals(0.5f, subsetNormals[4], 0.0f);
        assertEquals(0.0f, subsetNormals[5], 0.0f);

        float[] subsetVertices = subsetVG.getVertices();

        assertEquals(6, subsetVertices.length, 0);
        assertEquals(-1.0f, subsetVertices[0], 0.0f);
        assertEquals(-1.0f, subsetVertices[1], 0.0f);
        assertEquals(0.0f, subsetVertices[2], 0.0f);
        assertEquals(-1.0f, subsetVertices[3], 0.0f);
        assertEquals(1.0f, subsetVertices[4], 0.0f);
        assertEquals(0.0f, subsetVertices[5], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.model.IndexedArrayVG#createFaceSubsetVG(int) createFaceSubsetVG(int)}.
     * </p>
     */
    @Test
    public void createFaceSubsetVG()
    {
        IndexedArrayVG subsetVG = (IndexedArrayVG) fTestObject.createFaceSubsetVG(0);

        int[] subsetIndices = subsetVG.getIndices();

        assertEquals(3, subsetIndices.length, 0);
        assertEquals(0, subsetIndices[0], 0);
        assertEquals(1, subsetIndices[1], 0);
        assertEquals(2, subsetIndices[2], 0);

        float[] subsetColours = subsetVG.getColours();

        assertEquals(9, subsetColours.length, 0);
        assertEquals(1.0f, subsetColours[0], 0.0f);
        assertEquals(0.0f, subsetColours[1], 0.0f);
        assertEquals(0.0f, subsetColours[2], 0.0f);
        assertEquals(0.0f, subsetColours[3], 0.0f);
        assertEquals(1.0f, subsetColours[4], 0.0f);
        assertEquals(0.0f, subsetColours[5], 0.0f);
        assertEquals(0.0f, subsetColours[6], 0.0f);
        assertEquals(0.0f, subsetColours[7], 0.0f);
        assertEquals(1.0f, subsetColours[8], 0.0f);

        float[] subsetNormals = subsetVG.getNormals();

        assertEquals(9, subsetNormals.length, 0);
        assertEquals(-0.5f, subsetNormals[0], 0.0f);
        assertEquals(-0.5f, subsetNormals[1], 0.0f);
        assertEquals(0.0f, subsetNormals[2], 0.0f);
        assertEquals(-0.5f, subsetNormals[3], 0.0f);
        assertEquals(0.5f, subsetNormals[4], 0.0f);
        assertEquals(0.0f, subsetNormals[5], 0.0f);
        assertEquals(0.5f, subsetNormals[6], 0.0f);
        assertEquals(0.5f, subsetNormals[7], 0.0f);
        assertEquals(0.0f, subsetNormals[8], 0.0f);

        float[] subsetVertices = subsetVG.getVertices();

        assertEquals(9, subsetVertices.length, 0);
        assertEquals(-1.0f, subsetVertices[0], 0.0f);
        assertEquals(-1.0f, subsetVertices[1], 0.0f);
        assertEquals(0.0f, subsetVertices[2], 0.0f);
        assertEquals(-1.0f, subsetVertices[3], 0.0f);
        assertEquals(1.0f, subsetVertices[4], 0.0f);
        assertEquals(0.0f, subsetVertices[5], 0.0f);
        assertEquals(1.0f, subsetVertices[6], 0.0f);
        assertEquals(1.0f, subsetVertices[7], 0.0f);
        assertEquals(0.0f, subsetVertices[8], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.model.IndexedArrayVG#createVertexSubsetVG(int) createVertexSubsetVG(int)}.
     * </p>
     */
    @Test
    public void createVertexSubsetVG()
    {
        IndexedArrayVG subsetVG = (IndexedArrayVG) fTestObject.createVertexSubsetVG(0);

        int[] subsetIndices = subsetVG.getIndices();

        assertEquals(1, subsetIndices.length, 0);
        assertEquals(0, subsetIndices[0], 0);

        float[] subsetColours = subsetVG.getColours();

        assertEquals(3, subsetColours.length, 0);
        assertEquals(1.0f, subsetColours[0], 0.0f);
        assertEquals(0.0f, subsetColours[1], 0.0f);
        assertEquals(0.0f, subsetColours[2], 0.0f);

        float[] subsetNormals = subsetVG.getNormals();

        assertEquals(3, subsetNormals.length, 0);
        assertEquals(-0.5f, subsetNormals[0], 0.0f);
        assertEquals(-0.5f, subsetNormals[1], 0.0f);
        assertEquals(0.0f, subsetNormals[2], 0.0f);

        float[] subsetVertices = subsetVG.getVertices();

        assertEquals(3, subsetVertices.length, 0);
        assertEquals(-1.0f, subsetVertices[0], 0.0f);
        assertEquals(-1.0f, subsetVertices[1], 0.0f);
        assertEquals(0.0f, subsetVertices[2], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.model.IndexedArrayVG#getCenter() getCenter()}.
     * </p>
     */
    @Test
    public void getCenter()
    {
        // Perform test.
        TranslationVectorf center = fTestObject.getCenter();

        // Verify test results.
        assertEquals(0.0f, center.getX(), 0.0f);
        assertEquals(0.0f, center.getY(), 0.0f);
        assertEquals(0.0f, center.getZ(), 0.0f);
        assertEquals(1.0f, center.getW(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.model.IndexedArrayVG#getVertexCount() getVertexCount()}.
     * </p>
     */
    @Test
    public void getVertexCount()
    {
        // Perform test / Verify test results.
        assertEquals(4, fTestObject.getVertexCount(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.model.IndexedArrayVG#mergeWithParent() mergeWithParent()}.
     * </p>
     * 
     * @throws SEInvalidOperationException Thrown by the method being unit tested.
     */
    @Test
    public void mergeWithParent() throws SEInvalidOperationException
    {
        IndexedArrayVG subsetVG = (IndexedArrayVG) fTestObject.createFaceSubsetVG(0);

        subsetVG.setColours(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});
        subsetVG.setNormals(new float[] {0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f});
        subsetVG.setVertices(new float[] {-2.0f, -2.0f, 0.0f, -2.0f, 2.0f, 0.0f, 2.0f, 2.0f, 0.0f});

        subsetVG.mergeWithParent();

        int[] indices = fTestObject.getIndices();

        assertEquals(4, indices.length, 0);
        assertEquals(0, indices[0], 0);
        assertEquals(1, indices[1], 0);
        assertEquals(2, indices[2], 0);
        assertEquals(3, indices[3], 0);

        float[] colours = fTestObject.getColours();

        assertEquals(12, colours.length, 0);
        assertEquals(0.0f, colours[0], 0.0f);
        assertEquals(0.0f, colours[1], 0.0f);
        assertEquals(1.0f, colours[2], 0.0f);
        assertEquals(0.0f, colours[3], 0.0f);
        assertEquals(1.0f, colours[4], 0.0f);
        assertEquals(0.0f, colours[5], 0.0f);
        assertEquals(1.0f, colours[6], 0.0f);
        assertEquals(0.0f, colours[7], 0.0f);
        assertEquals(0.0f, colours[8], 0.0f);
        assertEquals(1.0f, colours[9], 0.0f);
        assertEquals(1.0f, colours[10], 0.0f);
        assertEquals(1.0f, colours[11], 0.0f);

        float[] normals = fTestObject.getNormals();

        assertEquals(12, normals.length, 0);
        assertEquals(0.5f, normals[0], 0.0f);
        assertEquals(0.5f, normals[1], 0.0f);
        assertEquals(0.0f, normals[2], 0.0f);
        assertEquals(0.5f, normals[3], 0.0f);
        assertEquals(-0.5f, normals[4], 0.0f);
        assertEquals(0.0f, normals[5], 0.0f);
        assertEquals(-0.5f, normals[6], 0.0f);
        assertEquals(-0.5f, normals[7], 0.0f);
        assertEquals(0.0f, normals[8], 0.0f);
        assertEquals(0.5f, normals[9], 0.0f);
        assertEquals(-0.5f, normals[10], 0.0f);
        assertEquals(0.0f, normals[11], 0.0f);

        float[] vertices = fTestObject.getVertices();

        assertEquals(12, vertices.length, 0);
        assertEquals(-2.0f, vertices[0], 0.0f);
        assertEquals(-2.0f, vertices[1], 0.0f);
        assertEquals(0.0f, vertices[2], 0.0f);
        assertEquals(-2.0f, vertices[3], 0.0f);
        assertEquals(2.0f, vertices[4], 0.0f);
        assertEquals(0.0f, vertices[5], 0.0f);
        assertEquals(2.0f, vertices[6], 0.0f);
        assertEquals(2.0f, vertices[7], 0.0f);
        assertEquals(0.0f, vertices[8], 0.0f);
        assertEquals(1.0f, vertices[9], 0.0f);
        assertEquals(-1.0f, vertices[10], 0.0f);
        assertEquals(0.0f, vertices[11], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.model.IndexedArrayVG#mergeWithParent() mergeWithParent()} for the special condition where the
     * {@link com.se.simplicity.model.IndexedArrayVG IndexedArrayVG} being tested is not a subset.
     * </p>
     * 
     * @throws SEInvalidOperationException Thrown by the method being unit tested.
     */
    @Test(expected = SEInvalidOperationException.class)
    public void mergeWithParentNotSubset() throws SEInvalidOperationException
    {
        fTestObject.mergeWithParent();
    }
}
