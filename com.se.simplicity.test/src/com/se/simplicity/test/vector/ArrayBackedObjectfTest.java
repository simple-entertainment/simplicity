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

import com.se.simplicity.vector.ArrayBackedObjectf;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.vector.ArrayBackedObjectf ArrayBackedObjectf}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ArrayBackedObjectfTest
{
    /**
     * An instance of the class being unit tested.
     */
    private ArrayBackedObjectf testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SimpleVectorf4();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.ArrayBackedObjectf.getArrayCopy getArrayCopy()}.
     * </p>
     */
    @Test
    public void getArrayCopy()
    {
        assertNotNull(testObject.getArrayCopy());
        assertNotSame(testObject.getArray(), testObject.getArrayCopy());
        assertNotSame(testObject.getArrayCopy(), testObject.getArrayCopy());

        float[] arrayCopy1 = testObject.getArrayCopy();
        float[] arrayCopy2 = testObject.getArrayCopy();

        for (int index = 0; index < arrayCopy1.length; index++)
        {
            assertEquals(arrayCopy1[index], arrayCopy2[index], 0.0f);
        }
    }
}
