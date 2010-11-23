/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.vector;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.vector.SimpleMatrixf44;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.vector.SimpleVectorf4 SimpleVectorf4}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleVectorf4Test
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleVectorf4 fTestObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.add add()}.
     * </p>
     */
    @Test
    public void add()
    {
        fTestObject.add(new SimpleVectorf4(4.0f, 2.0f, 7.5f, 3.9f));

        float[] array = fTestObject.getArray();

        assertEquals(5.0f, array[0], 0.0f);
        assertEquals(4.0f, array[1], 0.0f);
        assertEquals(10.5f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        fTestObject = new SimpleVectorf4();

        float[] array = fTestObject.getArray();

        array[0] = 1.0f;
        array[1] = 2.0f;
        array[2] = 3.0f;
        array[3] = 1.0f;
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.crossProduct crossProduct()}.
     * </p>
     */
    @Test
    public void crossProduct()
    {
        fTestObject.crossProductRight(new SimpleVectorf4(3.0f, 2.0f, 1.0f, 0.0f));

        float[] array = fTestObject.getArray();

        assertEquals(-4.0f, array[0], 0.0f);
        assertEquals(8.0f, array[1], 0.0f);
        assertEquals(-4.0f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.dotProduct dotProduct()}.
     * </p>
     */
    @Test
    public void dotProduct()
    {
        assertEquals(30.5f, fTestObject.dotProduct(new SimpleVectorf4(4.0f, 2.0f, 7.5f, 3.9f)), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.getLength getLength()}.
     * </p>
     */
    @Test
    public void getLength()
    {
        assertEquals(3.741657387f, fTestObject.getLength(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.getLengthSquared getLengthSquared()}.
     * </p>
     */
    @Test
    public void getLengthSquared()
    {
        assertEquals(14.0f, fTestObject.getLengthSquared(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.homogenize homogenize()}.
     * </p>
     */
    @Test
    public void homogenize()
    {
        float[] array = fTestObject.getArray();

        array[0] = 2.0f;
        array[1] = 4.0f;
        array[2] = 6.0f;
        array[3] = 2.0f;

        fTestObject.homogenize();

        assertEquals(1.0f, array[0], 0.0f);
        assertEquals(2.0f, array[1], 0.0f);
        assertEquals(3.0f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.homogenize homogenize()} for the special condition where this
     * {@link com.se.simplicity.vector.SimpleVectorf4 SimpleVectorf4} is already homogenized.
     * </p>
     */
    @Test
    public void homogenizeNotRequired()
    {
        fTestObject.homogenize();

        float[] array = fTestObject.getArray();

        assertEquals(1.0f, array[0], 0.0f);
        assertEquals(2.0f, array[1], 0.0f);
        assertEquals(3.0f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.multiplyMatrixLeft multiplyMatrixLeft()}.
     * </p>
     */
    @Test
    public void multiplyMatrixLeft()
    {
        SimpleMatrixf44 matrix = new SimpleMatrixf44();
        float[] matrixArray = matrix.getArray();

        matrixArray[0] = 1.0f;
        matrixArray[4] = 2.0f;
        matrixArray[8] = 3.0f;
        matrixArray[12] = 4.0f;
        matrixArray[1] = 2.0f;
        matrixArray[5] = 1.0f;
        matrixArray[9] = 4.0f;
        matrixArray[13] = 3.0f;
        matrixArray[2] = 3.0f;
        matrixArray[6] = 4.0f;
        matrixArray[10] = 1.0f;
        matrixArray[14] = 2.0f;
        matrixArray[3] = 0.0f;
        matrixArray[7] = 0.0f;
        matrixArray[11] = 0.0f;
        matrixArray[15] = 1.0f;

        fTestObject.multiplyLeft(matrix);

        float[] array = fTestObject.getArray();

        assertEquals(18.0f, array[0], 0.0f);
        assertEquals(19.0f, array[1], 0.0f);
        assertEquals(16.0f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.multiplyMatrixRight multiplyMatrixRight()}.
     * </p>
     */
    @Test
    public void multiplyMatrixRight()
    {
        SimpleMatrixf44 matrix = new SimpleMatrixf44();
        float[] matrixArray = matrix.getArray();

        matrixArray[0] = 1.0f;
        matrixArray[4] = 2.0f;
        matrixArray[8] = 3.0f;
        matrixArray[12] = 4.0f;
        matrixArray[1] = 2.0f;
        matrixArray[5] = 1.0f;
        matrixArray[9] = 4.0f;
        matrixArray[13] = 3.0f;
        matrixArray[2] = 3.0f;
        matrixArray[6] = 4.0f;
        matrixArray[10] = 1.0f;
        matrixArray[14] = 2.0f;
        matrixArray[3] = 0.0f;
        matrixArray[7] = 0.0f;
        matrixArray[11] = 0.0f;
        matrixArray[15] = 1.0f;

        fTestObject.multiplyRight(matrix);

        float[] array = fTestObject.getArray();

        assertEquals(14.0f, array[0], 0.0f);
        assertEquals(16.0f, array[1], 0.0f);
        assertEquals(14.0f, array[2], 0.0f);
        assertEquals(17.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.multiplyVectorRight multiplyVectorRight()}.
     * </p>
     */
    @Test
    public void multiplyVectorRight()
    {
        SimpleVectorf4 otherVector = new SimpleVectorf4();
        float[] otherArray = otherVector.getArray();

        otherArray[0] = 4.0f;
        otherArray[1] = 5.0f;
        otherArray[2] = 6.0f;
        otherArray[3] = 1.0f;

        fTestObject.multiplyRight(otherVector);

        float[] array = fTestObject.getArray();

        assertEquals(4.0f, array[0], 0.0f);
        assertEquals(10.0f, array[1], 0.0f);
        assertEquals(18.0f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.negate negate()}.
     * </p>
     */
    @Test
    public void negate()
    {
        fTestObject.negate();

        float[] array = fTestObject.getArray();

        assertEquals(-1.0f, array[0], 0.0f);
        assertEquals(-2.0f, array[1], 0.0f);
        assertEquals(-3.0f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.normalize normalize()}.
     * </p>
     */
    @Test
    public void normalize()
    {
        float[] array = fTestObject.getArray();

        array[0] = 0.0f;
        array[1] = 0.0f;
        array[2] = 3.0f;
        array[3] = 1.0f;

        fTestObject.normalize();

        array = fTestObject.getArray();

        assertEquals(0.0f, array[0], 0.0f);
        assertEquals(0.0f, array[1], 0.0f);
        assertEquals(1.0f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleVectorf4.subtract subtract()}.
     * </p>
     */
    @Test
    public void subtract()
    {
        fTestObject.subtractRight(new SimpleVectorf4(4.0f, 2.0f, 7.5f, 3.9f));

        float[] array = fTestObject.getArray();

        assertEquals(-3.0f, array[0], 0.0f);
        assertEquals(0.0f, array[1], 0.0f);
        assertEquals(-4.5f, array[2], 0.0f);
        assertEquals(1.0f, array[3], 0.0f);
    }
}
