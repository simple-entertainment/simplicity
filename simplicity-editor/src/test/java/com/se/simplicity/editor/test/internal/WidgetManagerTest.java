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
import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.eq;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import java.awt.Dimension;

import org.junit.Test;

import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.internal.SelectionMode;
import com.se.simplicity.editor.internal.WidgetManager;
import com.se.simplicity.editor.internal.rendering.WidgetJOGLRenderer;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
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
        testObject = new WidgetManager(mockScene, mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setCamera(mockCamera);

        // Verify test results.
        assertEquals(mockCamera, testObject.getPickingEngine().getCamera());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setEditingMode(EditingMode) setEditingMode(EditMode)}.
     * </p>
     */
    @Test
    public void setEditingMode()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        // Initialise test environment.
        testObject = new WidgetManager(mockScene, mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setEditingMode(EditingMode.ROTATION);

        // Verify test results.
        assertNull(testObject.getWidget().getSelectedWidgetNode());
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
        testObject = new WidgetManager(mockScene, mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setGL(mockGl);

        SimpleJOGLPicker scenePicker = (SimpleJOGLPicker) testObject.getPickingEngine().getPicker();
        assertNotNull(((JOGLComponent) testObject.getPickingEngine()).getGL());
        assertNotNull(((JOGLComponent) scenePicker.getRenderingEngine()).getGL());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.WidgetManager#setSelection(SceneSelection) setSelection(SceneSelection)} with the
     * special condition that the selection mode is 'MODEL'.
     * </p>
     */
    @Test
    public void setSelectionSelectionModeModel()
    {
        // Create dependencies.
        SceneSelection mockSelection = createMock(SceneSelection.class);
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate expected results.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        replay(mockSelection, mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new WidgetManager(mockScene, mockRenderingEngine);
        testObject.init();

        // Dictate expected results.
        reset(mockRenderingEngine);
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), eq(mockNode));
        replay(mockRenderingEngine);

        // Perform test.
        testObject.setSelection(mockSelection);

        // Verify results.
        verify(mockRenderingEngine);

        testObject.setEditingMode(EditingMode.ROTATION);
        assertEquals(mockSelection, testObject.getWidget().getSelection());

        testObject.setEditingMode(EditingMode.SELECTION);
        assertEquals(mockSelection, testObject.getWidget().getSelection());

        testObject.setEditingMode(EditingMode.TRANSLATION);
        assertEquals(mockSelection, testObject.getWidget().getSelection());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.WidgetManager#setSelection(SceneSelection) setSelection(SceneSelection)}.
     * </p>
     */
    @Test
    public void setSelection()
    {
        // Create dependencies.
        SceneSelection mockSelection = createMock(SceneSelection.class);
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode0 = createMock(Node.class);
        Node mockNode1 = createMock(Node.class);

        // Dictate expected results.
        expect(mockSelection.getNode()).andStubReturn(mockNode0);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode1);
        replay(mockSelection, mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new WidgetManager(mockScene, mockRenderingEngine);
        testObject.init();
        testObject.setSelectionMode(SelectionMode.FACES);

        // Dictate expected results.
        reset(mockRenderingEngine);
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), eq(mockNode0));
        replay(mockRenderingEngine);

        // Perform test.
        testObject.setSelection(mockSelection);

        // Verify results.
        verify(mockRenderingEngine);

        testObject.setEditingMode(EditingMode.ROTATION);
        assertEquals(mockSelection, testObject.getWidget().getSelection());

        testObject.setEditingMode(EditingMode.SELECTION);
        assertEquals(mockSelection, testObject.getWidget().getSelection());

        testObject.setEditingMode(EditingMode.TRANSLATION);
        assertEquals(mockSelection, testObject.getWidget().getSelection());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.WidgetManager#setSelectionMode(SelectionMode) setSelectionMode(SelectionMode)}.
     * </p>
     */
    @Test
    public void setSelectionMode()
    {
        // Create dependencies.
        SceneSelection mockSelection = createMock(SceneSelection.class);
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate expected results.
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        replay(mockSelection, mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new WidgetManager(mockScene, mockRenderingEngine);
        testObject.init();
        testObject.setEditingMode(EditingMode.SELECTION);

        // Perform test 1.
        testObject.setSelectionMode(SelectionMode.EDGES);

        // Verify test 1 results.
        SimpleJOGLPicker picker = (SimpleJOGLPicker) testObject.getPickingEngine().getPicker();
        assertEquals(SelectionMode.EDGES, ((WidgetJOGLRenderer) picker.getRenderingEngine().getRenderers().get(0)).getSelectionMode());
        assertEquals(DrawingMode.EDGES, picker.getDrawingMode());

        // Perform test 2.
        testObject.setSelectionMode(SelectionMode.FACES);

        // Verify test 2 results.
        assertEquals(SelectionMode.FACES, ((WidgetJOGLRenderer) picker.getRenderingEngine().getRenderers().get(0)).getSelectionMode());
        assertEquals(DrawingMode.FACES, picker.getDrawingMode());

        // Perform test 3.
        testObject.setSelectionMode(SelectionMode.MODEL);

        // Verify test 3 results.
        assertEquals(SelectionMode.MODEL, ((WidgetJOGLRenderer) picker.getRenderingEngine().getRenderers().get(0)).getSelectionMode());
        assertEquals(DrawingMode.FACES, picker.getDrawingMode());

        // Perform test 4.
        testObject.setSelectionMode(SelectionMode.VERTICES);

        // Verify test 4 results.
        assertEquals(SelectionMode.VERTICES, ((WidgetJOGLRenderer) picker.getRenderingEngine().getRenderers().get(0)).getSelectionMode());
        assertEquals(DrawingMode.VERTICES, picker.getDrawingMode());
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
        testObject = new WidgetManager(mockScene, mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setViewportSize(mockDimension);

        // Verify test results.
        assertEquals(mockDimension, ((SimpleJOGLPicker) testObject.getPickingEngine().getPicker()).getRenderingEngine().getViewportSize());
    }
}
