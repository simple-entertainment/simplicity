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

import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.vector.SimpleTranslationVectorf4 SimpleTranslationVectorf4}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleTranslationVectorf4Test
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleTranslationVectorf4 testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SimpleTranslationVectorf4();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleTranslationVectorf4.translateX translateX()}.
     * </p>
     */
    @Test
    public void translateX()
    {
        testObject.setX(1.0f);
        testObject.translateX(1.0f);

        assertEquals(2.0f, testObject.getX(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleTranslationVectorf4.translateY translateY()}.
     * </p>
     */
    @Test
    public void translateY()
    {
        testObject.setY(1.0f);
        testObject.translateY(1.0f);

        assertEquals(2.0f, testObject.getY(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.vector.SimpleTranslationVectorf4.translateZ translateZ()}.
     * </p>
     */
    @Test
    public void translateZ()
    {
        testObject.setZ(1.0f);
        testObject.translateZ(1.0f);

        assertEquals(2.0f, testObject.getZ(), 0.0f);
    }
}
