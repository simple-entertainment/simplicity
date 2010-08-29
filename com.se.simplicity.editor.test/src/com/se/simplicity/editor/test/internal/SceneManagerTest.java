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
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.ui.IFileEditorInput;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.jogl.scene.SimpleJOGLScene;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;
import com.se.simplicity.util.metadata.scene.MetaDataScene;
import com.se.simplicity.viewport.Viewport;

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
    private SceneManager testObject = SceneManager.getSceneManager();

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject.reset();
    }

    /**
     * <p>
     * Unit test the methods {@link com.se.simplicity.editor.internal.SceneManager#addSceneChangedListener(SceneChangedListener)
     * addSceneChangedListener(SceneChangedListener)} and
     * {@link com.se.simplicity.editor.internal.SceneManager#removeSceneChangedListener(SceneChangedListener)
     * removeSceneChangedListener(SceneChangedListener)}.
     * </p>
     */
    @Test
    public void addRemoveSceneChangedListener()
    {
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        testObject.addSceneChangedListener(mockListener);

        assertTrue(testObject.getSceneChangedListeners().contains(mockListener));

        testObject.removeSceneChangedListener(mockListener);

        assertTrue(!testObject.getSceneChangedListeners().contains(mockListener));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#addSceneDefinition(IFileEditorInput)
     * addSceneDefinition(IFileEditorInput)}.
     * </p>
     * 
     * @throws CoreException Thrown if the <code>IFileEditorInput</code> fails to retrieve the contents of the file.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void addSceneDefinitionIFileEditorInput() throws CoreException, FileNotFoundException
    {
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/internal/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        replay(mockInput, mockFile);

        testObject.addSceneDefinition(mockInput);

        assertNotNull(testObject.getScene(mockPath.toString()));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#addSceneDefinition(InputStream, String)
     * addSceneDefinition(InputStream, String)}.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void addSceneDefinitionInputStream() throws FileNotFoundException
    {
        testObject.addSceneDefinition(new FileInputStream("src/com/se/simplicity/editor/test/internal/triangle.xml"), "test");

        assertNotNull(testObject.getScene("test"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#addSceneDefinition(Scene, String) addSceneDefinition(Scene, String)}
     * .
     * </p>
     */
    @Test
    public void addSceneDefinitionScene()
    {
        testObject.addSceneDefinition(createMock(Scene.class), "test");

        assertNotNull(testObject.getScene("test"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#getViewportToScene(String) getViewportToScene(String)}.
     * </p>
     */
    @Test
    public void getViewportToScene()
    {
        SimpleJOGLScene scene = new SimpleJOGLScene();
        MetaDataCamera mockCamera = createMock(MetaDataCamera.class);
        scene.addCamera(mockCamera);

        testObject.addSceneDefinition(scene, "test");

        expect(mockCamera.getAttribute("default")).andStubReturn("true");
        replay(mockCamera);

        Viewport viewport = testObject.getViewportToScene("test");

        assertEquals(scene, viewport.getRenderingEngine().getScene());
        assertNotNull(viewport.getRenderingEngine().getRenderer());
        assertEquals(scene.getCameras().get(0), viewport.getRenderingEngine().getCamera());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#getViewportToScene(String) getViewportToScene(String)} with the
     * special condition that the <code>Scene</code> is a <code>MetaDataScene</code> with the 'preferredRenderingEngine' and 'preferredRenderer'
     * attributes set.
     * </p>
     */
    @Test
    public void getViewportToSceneMetaDataScene()
    {
        MetaDataScene scene = new MetaDataScene(new SimpleJOGLScene());
        MetaDataCamera mockCamera = createMock(MetaDataCamera.class);
        scene.addCamera(mockCamera);

        scene.setAttribute("preferredRenderingEngine", "com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine");
        scene.setAttribute("preferredRenderer", "com.se.simplicity.jogl.rendering.SimpleJOGLRenderer");
        testObject.addSceneDefinition(scene, "test");

        expect(mockCamera.getAttribute("default")).andStubReturn("true");
        replay(mockCamera);

        Viewport viewport = testObject.getViewportToScene("test");

        assertTrue(viewport.getRenderingEngine() instanceof SimpleJOGLRenderingEngine);
        assertTrue(viewport.getRenderingEngine().getRenderer() instanceof SimpleJOGLRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#getViewportToScene(String) getViewportToScene(String)} with the
     * special condition that the <code>Scene</code> is a <code>MetaDataScene</code> with the 'preferredRenderingEngine' and 'preferredRenderer'
     * attributes set but the 'preferredRenderingEngine' attribute is set to an invalid value.
     * </p>
     */
    @Test
    public void getViewportToSceneMetaDataSceneInvalidRenderingEngine()
    {
        MetaDataScene scene = new MetaDataScene(new SimpleJOGLScene());
        MetaDataCamera mockCamera = createMock(MetaDataCamera.class);
        scene.addCamera(mockCamera);

        scene.setAttribute("preferredRenderingEngine", "stupid.dumb.RenderingEngine");
        scene.setAttribute("preferredRenderer", "com.se.simplicity.jogl.rendering.SimpleJOGLRenderer");
        testObject.addSceneDefinition(scene, "test");

        expect(mockCamera.getAttribute("default")).andStubReturn("true");
        replay(mockCamera);

        Viewport viewport = testObject.getViewportToScene("test");

        assertTrue(viewport.getRenderingEngine() instanceof SimpleJOGLRenderingEngine);
        assertTrue(viewport.getRenderingEngine().getRenderer() instanceof SimpleJOGLRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#getViewportToScene(String) getViewportToScene(String)} with the
     * special condition that the <code>Scene</code> is a <code>MetaDataScene</code> with the 'preferredRenderingEngine' and 'preferredRenderer'
     * attributes set but the 'preferredRenderer' attribute is set to an invalid value.
     * </p>
     */
    @Test
    public void getViewportToSceneMetaDataSceneInvalidRenderer()
    {
        MetaDataScene scene = new MetaDataScene(new SimpleJOGLScene());
        MetaDataCamera mockCamera = createMock(MetaDataCamera.class);
        scene.addCamera(mockCamera);

        scene.setAttribute("preferredRenderingEngine", "com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine");
        scene.setAttribute("preferredRenderer", "stupid.dumb.Renderer");
        testObject.addSceneDefinition(scene, "test");

        expect(mockCamera.getAttribute("default")).andStubReturn("true");
        replay(mockCamera);

        Viewport viewport = testObject.getViewportToScene("test");

        assertTrue(viewport.getRenderingEngine() instanceof SimpleJOGLRenderingEngine);
        assertTrue(viewport.getRenderingEngine().getRenderer() instanceof SimpleJOGLRenderer);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#getViewportToScene(String) getViewportToScene(String)} with the
     * special condition that the <code>Scene</code> does not have any <code>Camera</code>s.
     * </p>
     */
    @Test
    public void getViewportToSceneNoCameras()
    {
        SimpleJOGLScene scene = new SimpleJOGLScene();
        scene.setSceneGraph(createMock(SceneGraph.class));

        testObject.addSceneDefinition(scene, "test");

        Viewport viewport = testObject.getViewportToScene("test");

        assertNotNull(viewport.getRenderingEngine().getCamera());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#getViewportToScene(String) getViewportToScene(String)} with the
     * special condition that the <code>Scene</code> does not have any <code>MetaDataCamera</code>s with the 'default' attribute set to true.
     * </p>
     */
    @Test
    public void getViewportToSceneNoDefaultCameras()
    {
        SimpleJOGLScene scene = new SimpleJOGLScene();
        scene.addCamera(createMock(MetaDataCamera.class));
        scene.setSceneGraph(createMock(SceneGraph.class));

        testObject.addSceneDefinition(scene, "test");

        Viewport viewport = testObject.getViewportToScene("test");

        assertEquals(scene.getCameras().get(0), viewport.getRenderingEngine().getCamera());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#getViewportToScene(String) getViewportToScene(String)} with the
     * special condition that the <code>Scene</code> does not have any <code>MetaDataCamera</code>s.
     * </p>
     */
    @Test
    public void getViewportToSceneNoMetaDataCameras()
    {
        SimpleJOGLScene scene = new SimpleJOGLScene();
        scene.addCamera(createMock(SimpleJOGLCamera.class));
        scene.setSceneGraph(createMock(SceneGraph.class));

        testObject.addSceneDefinition(scene, "test");

        Viewport viewport = testObject.getViewportToScene("test");

        assertEquals(scene.getCameras().get(0), viewport.getRenderingEngine().getCamera());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#notifyNodeModified(int) notifyNodeModified(int)}.
     * </p>
     */
    @Test
    public void notifyNodeModified()
    {
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        testObject.addSceneDefinition(mockScene, "test");
        testObject.setActiveScene("test");
        testObject.addSceneChangedListener(mockListener);

        org.easymock.classextension.EasyMock.reset(mockListener);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockListener);

        testObject.notifyNodeModified(0);

        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#notifySceneModified(String) notifySceneModified(String)}.
     * </p>
     */
    @Test
    public void notifySceneModified()
    {
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        testObject.addSceneDefinition(createMock(Scene.class), "test");
        testObject.addSceneChangedListener(mockListener);

        org.easymock.classextension.EasyMock.reset(mockListener);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockListener);

        testObject.notifySceneModified("test");

        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#reset() reset()}.
     * </p>
     */
    @Test
    public void reset()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);

        ArrayList<Camera> cameras = new ArrayList<Camera>();
        Camera mockCamera = createMock(Camera.class);
        cameras.add(mockCamera);

        ArrayList<Light> lights = new ArrayList<Light>();
        Light mockLight = createMock(Light.class);
        lights.add(mockLight);

        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        // Initialise test environment.
        testObject.addSceneChangedListener(createMock(SceneChangedListener.class));
        testObject.addSceneDefinition(mockScene, "test");
        testObject.setActiveScene("test");
        testObject.setActiveCamera(mockCamera);
        testObject.setActiveLight(mockLight);
        testObject.setActiveNode(mockNode);

        // Verify test environment.
        assertEquals(1, testObject.getSceneChangedListeners().size(), 0);
        assertNotNull(testObject.getScene("test"));
        assertNotNull(testObject.getActiveScene());
        assertNotNull(testObject.getActiveCamera());
        assertNotNull(testObject.getActiveLight());
        assertNotNull(testObject.getActiveNode());

        // Perform test.
        testObject.reset();

        // Verify results.
        assertEquals(0, testObject.getSceneChangedListeners().size(), 0);
        assertNull(testObject.getScene("test"));
        assertNull(testObject.getActiveScene());
        assertNull(testObject.getActiveCamera());
        assertNull(testObject.getActiveLight());
        assertNull(testObject.getActiveNode());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setActiveCamera(Camera) setActiveCamera(Camera)}.
     * </p>
     */
    @Test
    public void setActiveCamera()
    {
        Scene mockScene = createMock(Scene.class);
        ArrayList<Camera> cameras = new ArrayList<Camera>();
        Camera mockCamera = createMock(Camera.class);
        cameras.add(mockCamera);
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        expect(mockScene.getCameras()).andStubReturn(cameras);
        replay(mockScene);

        testObject.addSceneDefinition(mockScene, "test");
        testObject.setActiveScene("test");
        testObject.addSceneChangedListener(mockListener);

        org.easymock.classextension.EasyMock.reset(mockListener);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockListener);

        testObject.setActiveCamera(mockCamera);

        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setActiveCamera(Camera) setActiveCamera(Camera)} with the special
     * condition that the <code>Camera</code> is not in the active <code>Scene</code>.
     * </p>
     */
    @Test
    public void setActiveCameraNotInScene()
    {
        Scene mockScene = createMock(Scene.class);
        Camera mockCamera = createMock(Camera.class);

        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        replay(mockScene);

        testObject.addSceneDefinition(mockScene, "test");
        testObject.setActiveScene("test");

        try
        {
            testObject.setActiveCamera(mockCamera);
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Camera: The Camera must be in the active Scene.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setActiveLight(Light) setActiveLight(Light)}.
     * </p>
     */
    @Test
    public void setActiveLight()
    {
        Scene mockScene = createMock(Scene.class);
        ArrayList<Light> lights = new ArrayList<Light>();
        Light mockLight = createMock(Light.class);
        lights.add(mockLight);
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        expect(mockScene.getLights()).andStubReturn(lights);
        replay(mockScene);

        testObject.addSceneDefinition(mockScene, "test");
        testObject.setActiveScene("test");
        testObject.addSceneChangedListener(mockListener);

        org.easymock.classextension.EasyMock.reset(mockListener);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockListener);

        testObject.setActiveLight(mockLight);

        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setActiveCamera(Camera) setActiveCamera(Camera)} with the special
     * condition that the <code>Light</code> is not in the active <code>Scene</code>.
     * </p>
     */
    @Test
    public void setActiveLightNotInScene()
    {
        Scene mockScene = createMock(Scene.class);
        Light mockLight = createMock(Light.class);

        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        replay(mockScene);

        testObject.addSceneDefinition(mockScene, "test");
        testObject.setActiveScene("test");

        try
        {
            testObject.setActiveLight(mockLight);
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Light: The Light must be in the active Scene.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setActiveNode(Node) setActiveNode(Node)}.
     * </p>
     */
    @Test
    public void setActiveNode()
    {
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        testObject.addSceneDefinition(mockScene, "test");
        testObject.setActiveScene("test");
        testObject.addSceneChangedListener(mockListener);

        org.easymock.classextension.EasyMock.reset(mockListener);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockListener);

        testObject.setActiveNode(mockNode);

        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setActiveNode(Node) setActiveNode(Node)} with the special condition
     * that the <code>Node</code> is not in the active <code>Scene</code>.
     * </p>
     */
    @Test
    public void setActiveNodeNotInScene()
    {
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        testObject.addSceneDefinition(mockScene, "test");
        testObject.setActiveScene("test");

        try
        {
            testObject.setActiveNode(mockNode);
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Node: The Node must be in the active Scene.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setActiveScene(String) setActiveScene(String)}.
     * </p>
     */
    @Test
    public void setActiveScene()
    {
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        testObject.addSceneDefinition(createMock(Scene.class), "test");
        testObject.addSceneChangedListener(mockListener);

        org.easymock.classextension.EasyMock.reset(mockListener);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockListener);

        testObject.setActiveScene("test");

        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.SceneManager#setActiveScene(String) setActiveScene(String)} with the special
     * condition that the <code>Scene</code> is not managed by the <code>SceneManager</code>.
     * </p>
     */
    @Test
    public void setActiveSceneNotManaged()
    {
        try
        {
            testObject.setActiveScene("test");
        }
        catch (IllegalArgumentException e)
        {
            assertEquals("Invalid Scene: The Scene must already be managed by this Scene Manager.", e.getMessage());
        }
    }
}
