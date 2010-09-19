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
import static org.easymock.EasyMock.isNull;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

import java.awt.Dimension;

import javax.media.opengl.GL;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.SelectionMode;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.rendering.NamedJOGLRenderer;
import com.se.simplicity.jogl.rendering.OutlineJOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.scene.MetaDataScene;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.SceneManager SceneManager}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneManagerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneManager testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SceneManager();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#init() init()}.
     * </p>
     */
    @Test
    public void init()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);

        // Dictate expected results.
        mockRenderingEngine.addRenderer(isA(SimpleJOGLRenderer.class));
        mockRenderingEngine.addRenderer(isA(OutlineJOGLRenderer.class));
        mockRenderingEngine.setRendererRoot(isA(OutlineJOGLRenderer.class), (Node) anyObject());
        replay(mockRenderingEngine);

        // Perform test.
        testObject.init();

        // Verify test results.
        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#init() init()} with the special condition that the Scene is a
     * MetaDataScene with a preferred Renderer.
     * </p>
     */
    @Test
    public void initMetaDataScene()
    {
        // Create dependencies.
        MetaDataScene mockScene = createMock(MetaDataScene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        // Dictate correct behaviour.
        expect(mockScene.getAttribute("preferredRenderer")).andStubReturn("com.se.simplicity.jogl.rendering.NamedJOGLRenderer");
        replay(mockScene);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);

        // Dictate expected results.
        mockRenderingEngine.addRenderer(isA(NamedJOGLRenderer.class));
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), (Node) anyObject());
        replay(mockRenderingEngine);

        // Perform test.
        testObject.init();

        // Verify test results.
        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#init() init()} with the special condition that the Scene is a
     * MetaDataScene with an invalid preferred Renderer.
     * </p>
     */
    @Test
    public void initMetaDataSceneInvalidRenderer()
    {
        // Create dependencies.
        MetaDataScene mockScene = createMock(MetaDataScene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        // Dictate correct behaviour.
        expect(mockScene.getAttribute("preferredRenderer")).andStubReturn("com.se.simplicity.jogl.rendering.StupidJOGLRenderer");
        replay(mockScene);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);

        // Dictate expected results.
        mockRenderingEngine.addRenderer(isA(SimpleJOGLRenderer.class));
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), (Node) anyObject());
        replay(mockRenderingEngine);

        // Perform test.
        testObject.init();

        // Verify test results.
        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setCamera(Camera) setCamera(Camera)}.
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
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setDrawingMode(DrawingMode) setDrawingMode(DrawingMode)}.
     * </p>
     */
    @Test
    public void setDrawingMode()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Perform test.
        testObject.setDrawingMode(DrawingMode.VERTICES);

        // Verify test results.
        assertEquals(DrawingMode.VERTICES, ((SimpleJOGLPicker) testObject.getPickingEngine().getPicker()).getRenderingEngine().getRenderers().get(0)
                .getDrawingMode());

    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setGL(GL) setGL(GL)}.
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
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setSelectedSceneComponent(Object) with the special condition that no
     * scene component is selected.
     * </p>
     */
    @Test
    public void setSelectionEmpty()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        SceneSelection mockSelection = createMock(SceneSelection.class);

        // Dictate correct behaviour.
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), (Node) anyObject());
        expect(mockSelection.getSceneComponent()).andStubReturn(null);
        expect(mockSelection.getPrimitive()).andStubReturn(null);
        replay(mockRenderingEngine, mockSelection);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Dictate expected results.
        reset(mockRenderingEngine);
        mockRenderingEngine.setRendererRoot(isA(OutlineJOGLRenderer.class), (Node) isNull());
        replay(mockRenderingEngine);

        // Perform test.
        testObject.setSelection(mockSelection);

        // Verify test results.
        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setSelection(SceneSelection) with the special condition that the
     * selected scene component is a Node.
     * </p>
     */
    @Test
    public void setSelectionNode()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        SceneSelection mockSelection = createMock(SceneSelection.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), (Node) anyObject());
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        expect(mockSelection.getPrimitive()).andStubReturn(null);
        replay(mockRenderingEngine, mockSelection);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.init();

        // Dictate expected results.
        reset(mockRenderingEngine);
        mockRenderingEngine.setRendererRoot(isA(OutlineJOGLRenderer.class), eq(mockNode));
        replay(mockRenderingEngine);

        // Perform test.
        testObject.setSelection(mockSelection);

        // Verify test results.
        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setSelection(SceneSelection) with the special condition that the
     * selected scene component is a Node and the selection mode is NOT 'MODEL'.
     * </p>
     */
    @Test
    public void setSelectionPrimitive()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);

        SceneSelection mockSelection = createMock(SceneSelection.class);
        Node mockNode = createMock(Node.class);
        Model mockPrimitive = createMock(Model.class);

        // Dictate correct behaviour.
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.addRenderer((Renderer) anyObject());
        mockRenderingEngine.setRendererRoot((Renderer) anyObject(), (Node) anyObject());
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        expect(mockSelection.getPrimitive()).andStubReturn(mockPrimitive);
        replay(mockRenderingEngine, mockSelection);

        // Initialise test environment.
        testObject.setScene(mockScene);
        testObject.setRenderingEngine(mockRenderingEngine);
        testObject.setSelectionMode(SelectionMode.FACES);
        testObject.init();

        // Dictate expected results.
        reset(mockRenderingEngine);
        mockRenderingEngine.setRendererRoot(isA(OutlineJOGLRenderer.class), (Node) anyObject());
        replay(mockRenderingEngine);

        // Perform test.
        testObject.setSelection(mockSelection);

        // Verify test results.
        verify(mockRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setViewportSize(Dimension) setViewportSize(Dimension)}.
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
