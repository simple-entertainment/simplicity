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
 * @author simple
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
     * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.setSelectBufferCapacity
     * setSelectBufferCapacity()} with the special condition that a GL has already been set.
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
