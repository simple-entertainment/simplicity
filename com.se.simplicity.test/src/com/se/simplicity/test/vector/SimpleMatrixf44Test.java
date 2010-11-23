/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.vector;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.vector.SimpleMatrixf44;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.vector.SimpleMatrixf44 SimpleMatrixf44}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleMatrixf44Test
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleMatrixf44 fTestObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        fTestObject = new SimpleMatrixf44();

        float[] array = fTestObject.getArray();

        array[0] = 1.0f;
        array[4] = 2.0f;
        array[8] = 3.0f;
        array[12] = 4.0f;
        array[1] = 2.0f;
        array[5] = 1.0f;
        array[9] = 4.0f;
        array[13] = 3.0f;
        array[2] = 3.0f;
        array[6] = 4.0f;
        array[10] = 1.0f;
        array[14] = 2.0f;
        array[3] = 0.0f;
        array[7] = 0.0f;
        array[11] = 0.0f;
        array[15] = 1.0f;
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleMatrixf44.getDeterminant getDeterminant()}.
     * </p>
     */
    @Test
    public void getDeterminant()
    {
        assertEquals(20.0f, fTestObject.getDeterminant(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleMatrixf44.invert invert()}.
     * </p>
     * 
     * @throws SEInvalidOperationException Thrown by the method being unit tested.
     */
    @Test
    public void invert() throws SEInvalidOperationException
    {
        fTestObject.invert();

        float[] array = fTestObject.getArray();

        assertEquals(-0.75f, array[0], 0.0f);
        assertEquals(0.5f, array[1], 0.0f);
        assertEquals(0.25f, array[2], 0.0f);
        assertEquals(0.0f, array[3], 0.0f);
        assertEquals(0.5f, array[4], 0.0f);
        assertEquals(-0.4f, array[5], 0.0f);
        assertEquals(0.1f, array[6], 0.0f);
        assertEquals(0.0f, array[7], 0.0f);
        assertEquals(0.25f, array[8], 0.0f);
        assertEquals(0.1f, array[9], 0.0f);
        assertEquals(-0.15f, array[10], 0.0f);
        assertEquals(0.0f, array[11], 0.0f);
        assertEquals(1.0f, array[12], 0.0f);
        assertEquals(-1.0f, array[13], 0.0f);
        assertEquals(-1.0f, array[14], 0.0f);
        assertEquals(1.0f, array[15], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleMatrixf44.invert invert()} for the special condition where the
     * {@link com.se.simplicity.vector.SimpleMatrixf44 SimpleMatrixf44} being tested has a determinant of 0.
     * </p>
     * 
     * @throws SEInvalidOperationException Thrown by the method being unit tested.
     */
    @Test(expected = SEInvalidOperationException.class)
    public void invertDeterminant0() throws SEInvalidOperationException
    {
        float[] array = fTestObject.getArray();

        array[0] = 0.0f;
        array[4] = 0.0f;
        array[8] = 0.0f;
        array[12] = 0.0f;
        array[1] = 0.0f;
        array[5] = 0.0f;
        array[9] = 0.0f;
        array[13] = 0.0f;
        array[2] = 0.0f;
        array[6] = 0.0f;
        array[10] = 0.0f;
        array[14] = 0.0f;
        array[3] = 0.0f;
        array[7] = 0.0f;
        array[11] = 0.0f;
        array[15] = 0.0f;

        fTestObject.invert();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleMatrixf44.multiply multiply()}.
     * </p>
     */
    @Test
    public void multiply()
    {
        SimpleMatrixf44 otherMatrix = new SimpleMatrixf44();
        float[] otherArray = otherMatrix.getArray();

        otherArray[0] = 1.0f;
        otherArray[4] = 2.0f;
        otherArray[8] = 3.0f;
        otherArray[12] = 4.0f;
        otherArray[1] = 2.0f;
        otherArray[5] = 1.0f;
        otherArray[9] = 4.0f;
        otherArray[13] = 3.0f;
        otherArray[2] = 3.0f;
        otherArray[6] = 4.0f;
        otherArray[10] = 1.0f;
        otherArray[14] = 2.0f;
        otherArray[3] = 0.0f;
        otherArray[7] = 0.0f;
        otherArray[11] = 0.0f;
        otherArray[15] = 1.0f;

        fTestObject.multiplyLeft(otherMatrix);

        float[] array = fTestObject.getArray();

        assertEquals(14.0f, array[0], 0.0f);
        assertEquals(16.0f, array[1], 0.0f);
        assertEquals(14.0f, array[2], 0.0f);
        assertEquals(0.0f, array[3], 0.0f);
        assertEquals(16.0f, array[4], 0.0f);
        assertEquals(21.0f, array[5], 0.0f);
        assertEquals(14.0f, array[6], 0.0f);
        assertEquals(0.0f, array[7], 0.0f);
        assertEquals(14.0f, array[8], 0.0f);
        assertEquals(14.0f, array[9], 0.0f);
        assertEquals(26.0f, array[10], 0.0f);
        assertEquals(0.0f, array[11], 0.0f);
        assertEquals(20.0f, array[12], 0.0f);
        assertEquals(22.0f, array[13], 0.0f);
        assertEquals(28.0f, array[14], 0.0f);
        assertEquals(1.0f, array[15], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleMatrixf44.setIdentity setIdentity()}.
     * </p>
     */
    @Test
    public void setIdentity()
    {
        fTestObject.setIdentity();

        float[] array = fTestObject.getArray();

        assertEquals(1.0f, array[0], 0.0f);
        assertEquals(0.0f, array[1], 0.0f);
        assertEquals(0.0f, array[2], 0.0f);
        assertEquals(0.0f, array[3], 0.0f);
        assertEquals(0.0f, array[4], 0.0f);
        assertEquals(1.0f, array[5], 0.0f);
        assertEquals(0.0f, array[6], 0.0f);
        assertEquals(0.0f, array[7], 0.0f);
        assertEquals(0.0f, array[8], 0.0f);
        assertEquals(0.0f, array[9], 0.0f);
        assertEquals(1.0f, array[10], 0.0f);
        assertEquals(0.0f, array[11], 0.0f);
        assertEquals(0.0f, array[12], 0.0f);
        assertEquals(0.0f, array[13], 0.0f);
        assertEquals(0.0f, array[14], 0.0f);
        assertEquals(1.0f, array[15], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleMatrixf44.transpose transpose()}.
     * </p>
     */
    @Test
    public void transpose()
    {
        fTestObject.transpose();

        float[] array = fTestObject.getArray();

        assertEquals(1.0f, array[0], 0.0f);
        assertEquals(2.0f, array[1], 0.0f);
        assertEquals(3.0f, array[2], 0.0f);
        assertEquals(4.0f, array[3], 0.0f);
        assertEquals(2.0f, array[4], 0.0f);
        assertEquals(1.0f, array[5], 0.0f);
        assertEquals(4.0f, array[6], 0.0f);
        assertEquals(3.0f, array[7], 0.0f);
        assertEquals(3.0f, array[8], 0.0f);
        assertEquals(4.0f, array[9], 0.0f);
        assertEquals(1.0f, array[10], 0.0f);
        assertEquals(2.0f, array[11], 0.0f);
        assertEquals(0.0f, array[12], 0.0f);
        assertEquals(0.0f, array[13], 0.0f);
        assertEquals(0.0f, array[14], 0.0f);
        assertEquals(1.0f, array[15], 0.0f);
    }
}
