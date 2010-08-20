package com.se.simplicity.jogl.test.viewport;

import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.jogl.picking.engine.SimpleJOGLPickingEngine;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.jogl.viewport.SimpleJOGLViewport;

public class SimpleJOGLViewportTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleJOGLViewport testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public final void before()
    {
        testObject = new SimpleJOGLViewport();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport.displaySceneGraph displaySceneGraph()}.
     * </p>
     */
    @Test
    public void displaySceneGraph()
    {
        SimpleJOGLRenderingEngine mockRenderingEngine = createMock(SimpleJOGLRenderingEngine.class);
        SimpleJOGLPickingEngine mockPickingEngine = createMock(SimpleJOGLPickingEngine.class);

        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.setPickingEngine(mockPickingEngine);

        reset(mockRenderingEngine, mockPickingEngine);
        mockRenderingEngine.advance();
        mockPickingEngine.advance();
        replay(mockRenderingEngine, mockPickingEngine);

        testObject.displaySceneGraph();

        verify(mockRenderingEngine, mockPickingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport.displaySceneGraph displaySceneGraph()} with the special
     * condition that the {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport SimpleJOGLViewport} being tested does not have a
     * <code>PickingEngine</code>.
     * </p>
     */
    @Test
    public void displaySceneGraphNoPickingEngine()
    {
        SimpleJOGLRenderingEngine mockRenderingEngine = createMock(SimpleJOGLRenderingEngine.class);

        testObject.setRenderingEngine(mockRenderingEngine);

        reset(mockRenderingEngine);
        mockRenderingEngine.advance();
        replay(mockRenderingEngine);

        testObject.displaySceneGraph();

        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport.displaySceneGraph displaySceneGraph()} with the special
     * condition that the {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport SimpleJOGLViewport} being tested does not have a
     * <code>RenderingEngine</code>.
     * </p>
     */
    @Test(expected = IllegalStateException.class)
    public void displaySceneGraphNoRenderingEngine()
    {
        testObject.displaySceneGraph();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport.setGL setGL()}.
     * </p>
     */
    @Test
    public void setGL()
    {
        MockGL mockGl = new MockGL();
        SimpleJOGLRenderingEngine mockRenderingEngine = createMock(SimpleJOGLRenderingEngine.class);
        SimpleJOGLPickingEngine mockPickingEngine = createMock(SimpleJOGLPickingEngine.class);

        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.setPickingEngine(mockPickingEngine);

        reset(mockRenderingEngine, mockPickingEngine);
        mockRenderingEngine.setGL(mockGl);
        mockPickingEngine.setGL(mockGl);
        replay(mockRenderingEngine, mockPickingEngine);

        testObject.setGL(mockGl);

        verify(mockRenderingEngine, mockPickingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport.setPickingEngine setPickingEngine()}.
     * </p>
     */
    @Test
    public void setPickingEngine()
    {
        MockGL mockGl = new MockGL();
        SimpleJOGLPickingEngine mockPickingEngine = createMock(SimpleJOGLPickingEngine.class);

        testObject.setGL(mockGl);

        reset(mockPickingEngine);
        mockPickingEngine.setGL(mockGl);
        replay(mockPickingEngine);

        testObject.setPickingEngine(mockPickingEngine);

        verify(mockPickingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport.setRenderingEngine setRenderingEngine()}.
     * </p>
     */
    @Test
    public void setRenderingEngine()
    {
        MockGL mockGl = new MockGL();
        SimpleJOGLRenderingEngine mockRenderingEngine = createMock(SimpleJOGLRenderingEngine.class);
        
        testObject.setGL(mockGl);

        reset(mockRenderingEngine);
        mockRenderingEngine.setGL(mockGl);
        replay(mockRenderingEngine);

        testObject.setRenderingEngine(mockRenderingEngine);

        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.viewport.SimpleJOGLViewport.setSize setSize()}.
     * </p>
     */
    @Test
    public void setSize()
    {
        MockGL mockGl = new MockGL();
        
        testObject.setGL(mockGl);
        
        mockGl.reset();
        
        testObject.setSize(200, 200);
        
        assertEquals(1, mockGl.getMethodCallCount("glViewport", new Object[] {0, 0, 200, 200}), 0);
    }
}
