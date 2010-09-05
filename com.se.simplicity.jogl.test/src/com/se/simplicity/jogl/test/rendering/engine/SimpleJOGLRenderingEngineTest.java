/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.test.rendering.engine;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import java.awt.Dimension;
import java.util.ArrayList;

import javax.media.opengl.GL;

import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.scene.SimpleJOGLScene;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.test.mocks.NodeHierarchy;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine SimpleJOGLRenderingEngine}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLRenderingEngineTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleJOGLRenderingEngine testObject;

    /**
     * <p>
     * Unit test the methods {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine#addRenderer(Renderer) addRenderer(Renderer)} and
     * {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine#removeRenderer(Renderer) removeRenderer(Renderer)}.
     * </p>
     */
    @Test
    public void addRemoveRenderer()
    {
        // Create dependencies.
        MockGL mockGL = new MockGL();

        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        SimpleJOGLRenderer renderer = new SimpleJOGLRenderer();

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        mockScene.setGL(mockGL);
        replay(mockScene, mockSceneGraph);

        // Setup test environment.
        testObject.setGL(mockGL);
        testObject.setScene(mockScene);

        // Perform test 1.
        testObject.addRenderer(renderer);

        // Verify test 1 results.
        assertTrue(testObject.getRenderers().contains(renderer));
        assertEquals(mockGL, renderer.getGL());
        assertEquals(nodes.node1, testObject.getRendererRoot(renderer));

        // Perform test 2.
        testObject.removeRenderer(renderer);

        // Verify test 2 results.
        assertFalse(testObject.getRenderers().contains(renderer));
        assertNull(testObject.getRendererRoot(renderer));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine#addRenderer(int, Renderer) addRenderer(int,
     * Renderer)}.
     * </p>
     */
    @Test
    public void addRendererAtIndex()
    {
        // Create dependencies.
        MockGL mockGL = new MockGL();

        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        SimpleJOGLRenderer mockRenderer1 = createMock(SimpleJOGLRenderer.class);
        SimpleJOGLRenderer mockRenderer2 = createMock(SimpleJOGLRenderer.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        mockScene.setGL(mockGL);
        replay(mockScene, mockSceneGraph);

        // Setup test environment.
        testObject.setGL(mockGL);
        testObject.setScene(mockScene);
        testObject.addRenderer(mockRenderer1);

        // Perform test.
        testObject.addRenderer(0, mockRenderer2);

        // Verify test results.
        assertEquals(mockRenderer2, testObject.getRenderers().get(0));
        assertEquals(mockRenderer1, testObject.getRenderers().get(1));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.advance advance()}, specifically clearing before
     * rendering.
     * </p>
     */
    @Test
    public void advanceClearing()
    {
        // Create dependencies.
        MockGL mockGL = new MockGL();
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        // Dictate correct behaviour.
        mockGL.reset();
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        mockScene.setGL(mockGL);
        replay(mockScene, mockSceneGraph);

        // Setup test environment.
        testObject.setGL(mockGL);
        testObject.addRenderer(createMock(SimpleJOGLRenderer.class));
        testObject.setCamera(createMock(SimpleJOGLCamera.class));
        testObject.setScene(mockScene);

        // Perform test 1 (clearing enabled).
        testObject.advance();

        // Verify test 1 results.
        assertEquals(1, mockGL.getMethodCallCountIgnoreParams("glClear"), 0);

        // Setup test 2 environment.
        testObject.setClearsBeforeRender(false);

        // Dictate test 2 correct behaviour.
        mockGL.reset();

        // Perform test 2 (clearing disabled).
        testObject.advance();

        // Verify test 2 results.
        assertEquals(0, mockGL.getMethodCallCountIgnoreParams("glClear"), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.advance advance()} with the special condition
     * that the {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine SimpleJOGLRenderingEngine} being tested does not have a
     * {@link com.se.simplicity.rendering.Camera Camera} to view the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} through.
     * </p>
     */
    @Test(expected = IllegalStateException.class)
    public void advanceNoCamera()
    {
        testObject.advance();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.advance advance()} with the special condition
     * that the {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine SimpleJOGLRenderingEngine} being tested does not have a
     * {@link com.se.simplicity.scene.Scene Scene} to render.
     * </p>
     */
    @Test(expected = IllegalStateException.class)
    public void advanceNoScene()
    {
        testObject.setCamera(createMock(SimpleJOGLCamera.class));

        testObject.advance();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.advance advance()}, specifically the number of
     * calls to <code>glPushMatrix</code>, <code>glPopMatrix</code> and <code>glMultMatrix</code>.
     * </p>
     */
    @Test
    public void advancePopPushMatrixMult()
    {
        // Create dependencies.
        MockGL mockGL = new MockGL();
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        // Dictate correct behaviour.
        mockGL.reset();
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        mockScene.setGL(mockGL);
        replay(mockScene, mockSceneGraph);

        // Setup test environment.
        testObject.setGL(mockGL);
        testObject.addRenderer(createMock(SimpleJOGLRenderer.class));
        testObject.setCamera(createMock(SimpleJOGLCamera.class));
        testObject.setScene(mockScene);

        // PPerform test.
        testObject.advance();

        // Verify test results.
        assertEquals(8, mockGL.getMethodCallCountIgnoreParams("glPushMatrix"), 0);
        assertEquals(8, mockGL.getMethodCallCountIgnoreParams("glPopMatrix"), 0);
        assertEquals(7, mockGL.getMethodCallCountIgnoreParams("glMultMatrixf"), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.advance advance()}, specifically the
     * initialisation and disposing of dependencies.
     * </p>
     */
    @Test
    public void advanceRendererCameraLight()
    {
        // Create dependencies.
        MockGL mockGL = new MockGL();
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        SimpleJOGLRenderer mockRenderer = createMock(SimpleJOGLRenderer.class);
        SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);
        SimpleJOGLLight mockLight = createMock(SimpleJOGLLight.class);
        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockLight);

        // Dictate correct behaviour.
        mockGL.reset();
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        mockScene.setGL(mockGL);
        mockRenderer.setGL(mockGL);
        mockRenderer.init();
        mockRenderer.renderModel(((ModelNode) nodes.node3).getModel());
        mockRenderer.dispose();
        mockCamera.init();
        mockCamera.apply();
        mockLight.apply();
        replay(mockScene, mockSceneGraph, mockRenderer, mockCamera, mockLight);

        // Setup test environment.
        testObject.setGL(mockGL);
        testObject.addRenderer(mockRenderer);
        testObject.setCamera(mockCamera);
        testObject.setScene(mockScene);

        // Perform test.
        testObject.advance();

        // Verify test results.
        verify(mockRenderer, mockCamera, mockLight);
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SimpleJOGLRenderingEngine();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.init init()}.
     * </p>
     */
    @Test
    public void init()
    {
        // Create dependencies.
        MockGL mockGl = new MockGL();
        Dimension dimension = new Dimension(200, 200);

        // Initialise test environment.
        testObject.setGL(mockGl);
        testObject.setViewportSize(dimension);

        // Perform test.
        testObject.init();

        // Verify test results.
        assertEquals(1, mockGl.getMethodCallCount("glViewport", new Object[] {0, 0, 200, 200}), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.init init()} with the special condition that
     * there is no viewport size.
     * </p>
     */
    @Test
    public void initNoViewportSize()
    {
        // Create dependencies.
        MockGL mockGl = new MockGL();

        // Initialise test environment.
        testObject.setGL(mockGl);

        // Perform test.
        testObject.init();

        // Verify test results.
        assertEquals(0, mockGl.getMethodCallCountIgnoreParams("glViewport"), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.renderSceneGraph renderSceneGraph()}.
     * </p>
     */
    @Test
    public void renderSceneGraph()
    {
        MockGL mockGL = new MockGL();
        SimpleJOGLRenderer mockRenderer = createMock(SimpleJOGLRenderer.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setGL(mockGL);

        mockGL.reset();
        reset(mockRenderer);
        mockRenderer.renderModel(((ModelNode) nodes.node3).getModel());
        replay(mockRenderer);

        testObject.renderSceneGraph(mockRenderer, nodes.node1);

        verify(mockRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.renderSceneGraph renderSceneGraph()} with the
     * special condition that the {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine} being tested uses a
     * {@link com.se.simplicity.jogl.rendering.NamedJOGLRenderer}.
     * </p>
     */
    @Test
    public void renderSceneGraphNamed()
    {
        MockGL mockGL = new MockGL();
        NamedJOGLRenderer mockRenderer = createMock(NamedJOGLRenderer.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setGL(mockGL);

        mockGL.reset();
        reset(mockRenderer);
        mockRenderer.renderModel(((ModelNode) nodes.node3).getModel(), 2);
        replay(mockRenderer);

        testObject.renderSceneGraph(mockRenderer, nodes.node1);

        verify(mockRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.run run()}.
     * </p>
     */
    @Test
    @Ignore("May need to use aspect to test")
    public void run()
    {}

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine#setGL(GL) setGL(GL)}.
     * </p>
     */
    @Test
    public void setGL()
    {
        // Create dependencies.
        MockGL mockGL = new MockGL();

        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        SimpleJOGLRenderer mockRenderer1 = createMock(SimpleJOGLRenderer.class);
        SimpleJOGLRenderer mockRenderer2 = createMock(SimpleJOGLRenderer.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        mockScene.setGL(null);
        mockRenderer1.setGL(null);
        mockRenderer2.setGL(null);
        mockScene.setGL(mockGL);
        mockRenderer1.setGL(mockGL);
        mockRenderer2.setGL(mockGL);
        replay(mockScene, mockSceneGraph, mockRenderer1, mockRenderer2);

        // Setup test environment.
        testObject.setScene(mockScene);
        testObject.addRenderer(mockRenderer1);
        testObject.addRenderer(mockRenderer2);

        // Perform test.
        testObject.setGL(mockGL);

        // Verify test results.
        verify(mockScene, mockRenderer1, mockRenderer2);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine#setScene(Scene) setScene(Scene)}.
     * </p>
     */
    @Test
    public void setScene()
    {
        // Create dependencies.
        MockGL mockGL = new MockGL();

        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        SimpleJOGLRenderer mockRenderer1 = createMock(SimpleJOGLRenderer.class);
        SimpleJOGLRenderer mockRenderer2 = createMock(SimpleJOGLRenderer.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        mockScene.setGL(mockGL);
        mockRenderer1.setGL(mockGL);
        mockRenderer2.setGL(mockGL);
        replay(mockScene, mockSceneGraph, mockRenderer1, mockRenderer2);

        // Setup test environment.
        testObject.setGL(mockGL);
        testObject.addRenderer(mockRenderer1);
        testObject.addRenderer(mockRenderer2);

        // Perform test.
        testObject.setScene(mockScene);

        // Verify test results.
        verify(mockScene);

        assertEquals(nodes.node1, testObject.getRendererRoot(mockRenderer1));
        assertEquals(nodes.node1, testObject.getRendererRoot(mockRenderer2));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine#setScene(Scene) setScene(Scene)}.
     * </p>
     */
    @Test
    public void setSceneSceneGraphNull()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(null);
        replay(mockScene);

        // Perform test.
        try
        {
            testObject.setScene(mockScene);
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Scene: Must contain Scene Graph.", e.getMessage());
        }
    }
}
