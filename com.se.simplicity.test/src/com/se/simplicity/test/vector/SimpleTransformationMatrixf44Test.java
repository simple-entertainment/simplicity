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

import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.SimpleTranslationVectorf4;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.vector.SimpleTransformationMatrixf44 SimpleTransformationMatrixf44}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleTransformationMatrixf44Test
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleTransformationMatrixf44 fTestObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        fTestObject = new SimpleTransformationMatrixf44();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.rotate rotate()}.
     * </p>
     */
    @Test
    public void rotate()
    {
        float[] array = fTestObject.getArray();

        fTestObject.rotate((float) Math.PI / 2.0f, new SimpleVectorf4(0.0f, 1.0f, 0.0f, 1.0f));

        assertEquals(0.0f, array[0], 0.0000001f);
        assertEquals(0.0f, array[1], 0.0000001f);
        assertEquals(-1.0f, array[2], 0.0000001f);
        assertEquals(0.0f, array[4], 0.0000001f);
        assertEquals(1.0f, array[5], 0.0000001f);
        assertEquals(0.0f, array[6], 0.0000001f);
        assertEquals(1.0f, array[8], 0.0000001f);
        assertEquals(0.0f, array[9], 0.0000001f);
        assertEquals(0.0f, array[10], 0.0000001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.translate translate()}.
     * </p>
     */
    @Test
    public void translate()
    {
        float[] array = fTestObject.getArray();

        array[12] = 1.0f;
        array[13] = 2.0f;
        array[14] = 3.0f;

        fTestObject.translate(new SimpleTranslationVectorf4(1.0f, 2.0f, 3.0f, 1.0f));

        assertEquals(2.0f, array[12], 0.0f);
        assertEquals(4.0f, array[13], 0.0f);
        assertEquals(6.0f, array[14], 0.0f);
    }
}
