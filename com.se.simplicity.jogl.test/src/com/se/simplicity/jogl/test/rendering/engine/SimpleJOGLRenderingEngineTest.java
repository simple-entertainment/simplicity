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

import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.scene.SimpleJOGLScene;
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
     * Unit test the method {@link com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine.advance advance()}, specifically clearing before
     * rendering.
     * </p>
     */
    @Test
    public void advanceClearing()
    {
        MockGL mockGL = new MockGL();
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        testObject.setGL(mockGL);
        testObject.setRenderer(createMock(SimpleJOGLRenderer.class));
        testObject.setCamera(createMock(SimpleJOGLCamera.class));
        testObject.setScene(mockScene);

        // Test with clearing enabled.
        mockGL.reset();
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockScene, mockSceneGraph);

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
        MockGL mockGL = new MockGL();
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setGL(mockGL);
        testObject.setRenderer(createMock(SimpleJOGLRenderer.class));
        testObject.setCamera(createMock(SimpleJOGLCamera.class));
        testObject.setScene(mockScene);

        mockGL.reset();
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockScene, mockSceneGraph);

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
        // TODO implement test
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
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setGL(mockGL);
        testObject.setRenderer(mockRenderer);
        testObject.setScene(mockScene);

        mockGL.reset();
        reset(mockRenderer);
        mockRenderer.renderVertexGroup(((ModelNode) nodes.node3).getVertexGroup(), DrawingMode.FACES);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockRenderer, mockScene, mockSceneGraph);

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
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setGL(mockGL);
        testObject.setRenderer(mockRenderer);
        testObject.setScene(mockScene);

        mockGL.reset();
        reset(mockRenderer);
        mockRenderer.renderVertexGroup(((ModelNode) nodes.node3).getVertexGroup(), DrawingMode.FACES, 2);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockRenderer, mockScene, mockSceneGraph);

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
}
