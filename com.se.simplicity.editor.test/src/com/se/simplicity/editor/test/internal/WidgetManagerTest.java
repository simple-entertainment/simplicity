/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal;

import static org.easymock.EasyMock.anyObject;
import static org.easymock.EasyMock.eq;
import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.isA;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import java.awt.Dimension;

import javax.media.opengl.GL;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.internal.WidgetManager;
import com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.WidgetManager WidgetManager}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetManagerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private WidgetManager testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new WidgetManager();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.WidgetManager2#setCamera(Camera) setCamera(Camera)}.
     * </p>
     */
    @Test
    public void setCamera()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Camera mockCamera = createMock(Camera.class);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setCamera(mockCamera);

        // Verify test results.
        assertEquals(mockCamera, testObject.getPickingEngine().getCamera());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager2#setEditingMode(EditingMode) setEditingMode(EditMode)}.
     * </p>
     */
    @Test
    public void setEditingMode()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        // Dictate correct behaviour.
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), (Node) anyObject());
        replay(mockRenderingEngine);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Dictate expected results.
        reset(mockRenderingEngine);
        mockRenderingEngine.setRendererRoot(isA(WidgetJOGLRenderer.class), (Node) anyObject());
        replay(mockRenderingEngine);

        // Perform test.
        testObject.setEditingMode(EditingMode.ROTATION);

        // Verify test results.
        verify(mockRenderingEngine);

        assertNull(testObject.getWidget().getSelectedWidgetNode());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager2#setEditingMode(EditingMode) setEditingMode(EditMode)} with the
     * special condition that the current edit mode is 'SELECTION'.
     * </p>
     */
    @Test
    public void setEditingModeSelection()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), (Node) anyObject());
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        replay(mockScene, mockRenderingEngine, mockSceneGraph);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Dictate expected results.
        reset(mockRenderingEngine);
        mockRenderingEngine.setRendererRoot(isA(WidgetJOGLRenderer.class), eq(mockNode));
        replay(mockRenderingEngine);

        // Perform test.
        testObject.setEditingMode(EditingMode.SELECTION);

        // Verify test results.
        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.WidgetManager#setGL(GL) setGL(GL)}.
     * </p>
     */
    @Test
    public void setGL()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        MockGL mockGl = new MockGL();

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setGL(mockGl);

        SimpleJOGLPicker scenePicker = (SimpleJOGLPicker) testObject.getPickingEngine().getPicker();
        assertNotNull(((JOGLComponent) testObject.getPickingEngine()).getGL());
        assertNotNull(((JOGLComponent) scenePicker.getRenderingEngine()).getGL());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.WidgetManager#setRenderingEngine(RenderingEngine)
     * setRenderingEngine(RenderingEngine)}.
     * </p>
     */
    @Test
    public void setRenderingEngine()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        // Initialise test environment.
        testObject.setScene(mockScene);

        // Dictate expected results.
        mockRenderingEngine.addRenderer(isA(WidgetJOGLRenderer.class));
        mockRenderingEngine.setRendererRoot(isA(WidgetJOGLRenderer.class), (Node) anyObject());
        replay(mockRenderingEngine);

        // Perform test.
        testObject.setRenderingEngine(mockRenderingEngine);

        // Verify results.
        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.WidgetManager#setSelectedSceneComponent(Object)
     * setSelectedSceneComponent(Object)}.
     * </p>
     */
    @Test
    public void setSelectedSceneComponent()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate expected results.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setSelectedSceneComponent(mockNode);

        // Verify results.
        testObject.setEditingMode(EditingMode.ROTATION);
        assertEquals(mockNode, testObject.getWidget().getSelectedSceneComponent());

        testObject.setEditingMode(EditingMode.SELECTION);
        assertEquals(mockNode, testObject.getWidget().getSelectedSceneComponent());

        testObject.setEditingMode(EditingMode.TRANSLATION);
        assertEquals(mockNode, testObject.getWidget().getSelectedSceneComponent());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.WidgetManager#setViewportSize(Dimension) setViewportSize(Dimension)}.
     * </p>
     */
    @Test
    public void setViewportSize()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Dimension mockDimension = createMock(Dimension.class);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setViewportSize(mockDimension);

        // Verify test results.
        assertEquals(mockDimension, ((SimpleJOGLPicker) testObject.getPickingEngine().getPicker()).getRenderingEngine().getViewportSize());
    }
}
