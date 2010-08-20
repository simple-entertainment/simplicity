/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.test.picking;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.test.mocks.MockGL;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLPicker SimpleJOGLPicker}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLPickerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleJOGLPicker testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SimpleJOGLPicker();
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.pickSceneGraph pickSceneGraph()}.
     */
    @Test
    @Ignore("Need to know about the select buffer contents")
    public void pickSceneGraph()
    {
    // TODO implement SimpleJOGLPicker tests
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.setGL setGL()}.
     */
    @Test
    public void setGL()
    {
        MockGL mockGl = new MockGL();

        testObject.setGL(mockGl);

        assertEquals(1, mockGl.getMethodCallCountIgnoreParams("glSelectBuffer"), 0);
    }

    /**
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.setSelectBufferCapacity setSelectBufferCapacity()} with the special
     * condition that a GL has already been set.
     */
    @Test
    public void setSelectBufferCapacityGL()
    {
        MockGL mockGl = new MockGL();

        testObject.setGL(mockGl);

        mockGl.reset();

        testObject.setSelectBufferCapacity(10);

        assertEquals(1, mockGl.getMethodCallCountIgnoreParams("glSelectBuffer"), 0);
    }
}
