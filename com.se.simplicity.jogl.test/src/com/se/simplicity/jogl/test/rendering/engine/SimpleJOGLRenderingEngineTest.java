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
import static org.easymock.classextension.EasyMock.createNiceMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.rendering.DrawingMode;
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
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.addLight addLight()}.
     * </p>
     */
    @Test
    public void addLight()
    {
        SimpleJOGLLight mockLight = createMock(SimpleJOGLLight.class);

        mockLight.setGL(null);
        replay(mockLight);

        testObject.addLight(mockLight);

        assertTrue(testObject.getLights().contains(mockLight));

        verify(mockLight);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.advance advance()}, specifically the application
     * of the <code>Camera</code> and <code>Lights</code>.
     * </p>
     */
    @Test
    public void advanceApplyCameraLights()
    {
        MockGL mockGL = new MockGL();

        SimpleJOGLCamera mockCamera = createNiceMock(SimpleJOGLCamera.class);
        SimpleJOGLLight mockLight = createNiceMock(SimpleJOGLLight.class);

        testObject.setGL(mockGL);
        testObject.setCamera(mockCamera);
        testObject.addLight(mockLight);
        testObject.setSceneGraph(createMock(SceneGraph.class));

        mockGL.reset();
        reset(mockCamera, mockLight);
        mockCamera.apply();
        mockLight.apply();
        replay(mockCamera, mockLight);

        testObject.advance();

        verify(mockCamera, mockLight);
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
        MockGL mockGL = new MockGL();
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        testObject.setGL(mockGL);
        testObject.setRenderer(createMock(SimpleJOGLRenderer.class));
        testObject.setCamera(createMock(SimpleJOGLCamera.class));
        testObject.addLight(createMock(SimpleJOGLLight.class));
        testObject.setSceneGraph(mockSceneGraph);

        // Test with clearing enabled.
        mockGL.reset();
        reset(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockSceneGraph);

        testObject.advance();

        assertEquals(1, mockGL.getMethodCallCountIgnoreParams("glClear"), 0);

        // Test with clearing disabled.
        testObject.setClearsBeforeRender(false);

        mockGL.reset();

        testObject.advance();

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
     * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to render.
     * </p>
     */
    @Test(expected = IllegalStateException.class)
    public void advanceNoSceneGraph()
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
        MockGL mockGL = new MockGL();
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setGL(mockGL);
        testObject.setRenderer(createMock(SimpleJOGLRenderer.class));
        testObject.setCamera(createMock(SimpleJOGLCamera.class));
        testObject.addLight(createMock(SimpleJOGLLight.class));
        testObject.setSceneGraph(mockSceneGraph);

        mockGL.reset();
        reset(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andReturn(nodes.node1);
        replay(mockSceneGraph);

        testObject.advance();

        assertEquals(8, mockGL.getMethodCallCountIgnoreParams("glPushMatrix"), 0);
        assertEquals(8, mockGL.getMethodCallCountIgnoreParams("glPopMatrix"), 0);
        assertEquals(7, mockGL.getMethodCallCountIgnoreParams("glMultMatrixf"), 0);
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
        MockGL mockGL = new MockGL();

        SimpleJOGLRenderer mockRenderer = createMock(SimpleJOGLRenderer.class);
        SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);
        SimpleJOGLLight mockLight1 = createMock(SimpleJOGLLight.class);
        SimpleJOGLLight mockLight2 = createMock(SimpleJOGLLight.class);

        testObject.setGL(mockGL);
        testObject.setRenderer(mockRenderer);
        testObject.setCamera(mockCamera);
        testObject.addLight(mockLight1);
        testObject.addLight(mockLight2);

        reset(mockRenderer, mockCamera, mockLight1, mockLight2);
        mockRenderer.setGL(mockGL);
        mockCamera.setGL(mockGL);
        mockLight1.setGL(mockGL);
        mockLight2.setGL(mockGL);
        replay(mockRenderer, mockCamera, mockLight1, mockLight2);

        testObject.init();

        verify(mockRenderer, mockCamera, mockLight1, mockLight2);
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
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setGL(mockGL);
        testObject.setRenderer(mockRenderer);
        testObject.setSceneGraph(mockSceneGraph);

        mockGL.reset();
        reset(mockRenderer, mockSceneGraph);
        mockRenderer.renderVertexGroup(((ModelNode) nodes.node3).getVertexGroup(), DrawingMode.FACES);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockRenderer, mockSceneGraph);

        testObject.renderSceneGraph();

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
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setGL(mockGL);
        testObject.setRenderer(mockRenderer);
        testObject.setSceneGraph(mockSceneGraph);

        mockGL.reset();
        reset(mockRenderer, mockSceneGraph);
        mockRenderer.renderVertexGroup(((ModelNode) nodes.node3).getVertexGroup(), DrawingMode.FACES, 2);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockRenderer, mockSceneGraph);

        testObject.renderSceneGraph();

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
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.setCamera setCamera()}.
     * </p>
     */
    @Test
    public void setCamera()
    {
        SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);

        mockCamera.setGL(null);
        replay();

        testObject.setCamera(mockCamera);

        verify();
        assertEquals(mockCamera, testObject.getCamera());
    }
}
