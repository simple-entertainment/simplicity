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
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import javax.media.opengl.GL;
import javax.media.opengl.GLContext;

import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Display;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.ContentProvider;
import com.se.simplicity.editor.internal.EditMode;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.event.SceneChangedListener;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.jogl.picking.SimpleJOGLPicker;
import com.se.simplicity.jogl.scene.SimpleJOGLScene;
import com.se.simplicity.jogl.test.mocks.MockGL;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.ContentProvider ContentProvider}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ContentProviderTest
{
    /**
     * An instance of the class being unit tested.
     */
    private ContentProvider testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new ContentProvider();

        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#displayContent(GLCanvas, GLContent) displayContent(GLCanvas,
     * GLContent)}.
     * </p>
     */
    @Test
    public void displayContent()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        MockGL mockGl = new MockGL();

        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Display mockDisplay = createMock(Display.class);
        GLContext mockGlContext = createMock(GLContext.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        mockScene.setGL(mockGl);
        expect(mockSceneGraph.getRoot()).andStubReturn(createMock(Node.class));
        expect(mockCanvas.getDisplay()).andStubReturn(mockDisplay);
        replay(mockScene, mockSceneGraph, mockCanvas);

        // Dictate expected results.
        mockDisplay.asyncExec((Runnable) anyObject());
        replay(mockDisplay);

        // Initialise test environment.
        testObject = new ContentProvider(mockScene);
        testObject.init();
        testObject.setGL(mockGl);

        // Perform test.
        testObject.displayContent(mockCanvas, mockGlContext);

        // Verify test results.
        verify(mockDisplay);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#init() init()}.
     * </p>
     */
    @Test
    public void init()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        expect(mockSceneGraph.getRoot()).andStubReturn(createMock(Node.class));
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new ContentProvider(mockScene);

        // Perform test.
        testObject.init();

        // Verify test results.
        assertNotNull(testObject.getRenderingEngine());
        assertNotNull(testObject.getScenePickingEngine());
        assertNotNull(testObject.getWidgetPickingEngine());

        assertNotNull(testObject.getViewingCamera());

        assertEquals(testObject.getViewingCamera(), testObject.getRenderingEngine().getCamera());
        assertEquals(testObject.getViewingCamera(), testObject.getScenePickingEngine().getCamera());
        assertEquals(testObject.getViewingCamera(), testObject.getWidgetPickingEngine().getCamera());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#setCanvasSize(Rectangle) setCanvasSize(Rectangle)}.
     * </p>
     */
    @Test
    public void setCanvasSize()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        Rectangle rectangle = new Rectangle(0, 0, 200, 200); // Would create an aspect ratio of 1.0

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        expect(mockSceneGraph.getRoot()).andStubReturn(createMock(Node.class));
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new ContentProvider(mockScene);
        testObject.init();

        // Perform test.
        testObject.setCanvasSize(rectangle);

        // Verify test results.
        assertEquals(rectangle.width, testObject.getRenderingEngine().getViewportSize().width, 0);
        assertEquals(rectangle.height, testObject.getRenderingEngine().getViewportSize().height, 0);

        SimpleJOGLPicker scenePicker = (SimpleJOGLPicker) testObject.getScenePickingEngine().getPicker();
        assertEquals(rectangle.width, scenePicker.getRenderingEngine().getViewportSize().width, 0);
        assertEquals(rectangle.height, scenePicker.getRenderingEngine().getViewportSize().height, 0);

        SimpleJOGLPicker widgetPicker = (SimpleJOGLPicker) testObject.getWidgetPickingEngine().getPicker();
        assertEquals(rectangle.width, widgetPicker.getRenderingEngine().getViewportSize().width, 0);
        assertEquals(rectangle.height, widgetPicker.getRenderingEngine().getViewportSize().height, 0);

        assertEquals(1.0f, testObject.getViewingCamera().getFrameAspectRatio(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#setCanvasSize(Rectangle) setCanvasSize(Rectangle)} with the
     * special condition that the {@link com.se.simplicity.editor.internal.ContentProvider ContentProvider} does not synchronise the viewing
     * {@link com.se.simplicity.rendering.Camera Camera}'s aspect ratio with the canvas's aspect ratio.
     * </p>
     */
    @Test
    public void setCanvasSizeCameraNotSynchronised()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        Rectangle rectangle = new Rectangle(0, 0, 200, 200); // Would create an aspect ratio of 1.0

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        expect(mockSceneGraph.getRoot()).andStubReturn(createMock(Node.class));
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new ContentProvider(mockScene);
        testObject.init();
        testObject.setSynchronisesCameraAspectRatio(false);

        // Perform test.
        testObject.setCanvasSize(rectangle);

        // Verify test results.
        assertEquals(0.75f, testObject.getViewingCamera().getFrameAspectRatio(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#setGL(GL) setGL(GL)}.
     * </p>
     */
    @Test
    public void setGL()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        MockGL mockGl = new MockGL();

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        mockScene.setGL(mockGl);
        expect(mockSceneGraph.getRoot()).andStubReturn(createMock(Node.class));
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new ContentProvider(mockScene);
        testObject.init();

        // Perform test.
        testObject.setGL(mockGl);

        assertNotNull(((JOGLComponent) testObject.getRenderingEngine()).getGL());

        SimpleJOGLPicker scenePicker = (SimpleJOGLPicker) testObject.getScenePickingEngine().getPicker();
        assertNotNull(((JOGLComponent) testObject.getScenePickingEngine()).getGL());
        assertNotNull(((JOGLComponent) scenePicker.getRenderingEngine()).getGL());

        SimpleJOGLPicker widgetPicker = (SimpleJOGLPicker) testObject.getWidgetPickingEngine().getPicker();
        assertNotNull(((JOGLComponent) testObject.getWidgetPickingEngine()).getGL());
        assertNotNull(((JOGLComponent) widgetPicker.getRenderingEngine()).getGL());

        assertNotNull(((JOGLComponent) testObject.getViewingCamera()).getGL());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#setSelectedSceneComponent(Object)
     * setSelectedSceneComponent(Object)} with the special condition that the scene component is a {@link com.se.simplicity.scenegraph.Node Node}.
     * </p>
     */
    @Test
    public void setSelectedSceneComponentNode()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        SceneManager.getSceneManager().addScene(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene(mockScene);
        testObject = new ContentProvider(mockScene);
        testObject.init();

        // Perform test.
        testObject.setSelectedSceneComponent(mockNode);

        // Verify test results.
        assertEquals(mockNode, testObject.getRenderingEngine().getRendererRoot(testObject.getRenderingEngine().getRenderers().get(1)));
        assertEquals(mockNode, SceneManager.getSceneManager().getActiveNode());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#setSelectedSceneComponent(Object)
     * setSelectedSceneComponent(Object)} with the special condition that the scene component is null.
     * </p>
     */
    @Test
    public void setSelectedSceneComponentNull()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        SceneManager.getSceneManager().addScene(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene(mockScene);
        testObject = new ContentProvider(mockScene);
        testObject.init();
        testObject.setSelectedSceneComponent(mockNode);

        // Perform test.
        testObject.setSelectedSceneComponent(null);

        // Verify test results.
        assertNull(testObject.getRenderingEngine().getRendererRoot(testObject.getRenderingEngine().getRenderers().get(1)));
        assertNull(SceneManager.getSceneManager().getActiveNode());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#setSelectedSceneComponent(Object)
     * setSelectedSceneComponent(Object)} with the special condition that the scene component is the same as the already selected scene component.
     * </p>
     */
    @Test
    public void setSelectedSceneComponentSame()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        SceneManager.getSceneManager().addScene(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene(mockScene);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);
        testObject = new ContentProvider(mockScene);
        testObject.init();
        testObject.setSelectedSceneComponent(mockNode);

        // Dictate expected results.
        reset(mockListener);
        replay(mockListener); // Expect that an event is not fired.

        // Perform test.
        testObject.setSelectedSceneComponent(mockNode);

        // Verify test results.
        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#setEditMode(EditMode) setEditMode(EditMode)}.
     * </p>
     */
    @Test
    public void setEditMode()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        expect(mockSceneGraph.getRoot()).andStubReturn(createMock(Node.class));
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new ContentProvider(mockScene);
        testObject.init();

        // Perform test.
        testObject.setEditMode(EditMode.ROTATION);

        // Verify test results.
        assertNotNull(testObject.getRenderingEngine().getRendererRoot(testObject.getRenderingEngine().getRenderers().get(2)));
        assertEquals(1, testObject.getWidgetPickingEngine().getScene().getSceneGraph().getSubgraphRoots().size(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.ContentProvider#setEditMode(EditMode) setEditMode(EditMode)} with the special
     * condition that the current edit mode is 'SELECTION'.
     * </p>
     */
    @Test
    public void setEditModeNull()
    {
        // Create dependencies.
        SimpleJOGLScene mockScene = createMock(SimpleJOGLScene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        mockScene.setGL(null);
        expect(mockSceneGraph.getRoot()).andStubReturn(createMock(Node.class));
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject = new ContentProvider(mockScene);
        testObject.init();
        testObject.setEditMode(EditMode.ROTATION);

        // Perform test.
        testObject.setEditMode(EditMode.SELECTION);

        // Verify test results.
        assertNull(testObject.getRenderingEngine().getRendererRoot(testObject.getRenderingEngine().getRenderers().get(2)));
        assertEquals(0, testObject.getWidgetPickingEngine().getScene().getSceneGraph().getSubgraphRoots().size(), 0);
    }
}
