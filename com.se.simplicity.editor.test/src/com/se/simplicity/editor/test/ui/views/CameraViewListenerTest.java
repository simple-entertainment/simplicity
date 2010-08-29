/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.views;

import static org.easymock.EasyMock.anyObject;
import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import static org.junit.Assert.assertNotNull;

import java.util.ArrayList;
import java.util.HashMap;

import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.ui.views.CameraViewListener;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.views.CameraViewListener CameraViewListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class CameraViewListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private CameraViewListener testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.CameraViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying the name property of a <code>Camera</code>.
     * </p>
     */
    @Test
    public void modifyTextName()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Text mockText = createMock(Text.class);

        Scene mockScene = createMock(Scene.class);
        MetaDataCamera camera = new MetaDataCamera(new SimpleJOGLCamera());
        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(camera);

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockText, "name");

        Event event = new Event();
        event.widget = mockText;
        ModifyEvent modifyEvent = new ModifyEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockText.getText()).andStubReturn("Test");
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockText, mockListener);

        // Initialise test environment.
        testObject = new CameraViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveCamera(camera);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Perform test.
        testObject.modifyText(modifyEvent);

        // Verify results.
        // verify(mockListener);

        assertEquals("Test", camera.getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.CameraViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying the name property of a <code>Camera</code> but the <code>Camera</code>
     * is not a <code>MetaDataCamera</code>.
     * </p>
     */
    @Test
    public void modifyTextNameNotMetaDataNode()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Text mockText = createMock(Text.class);

        Scene mockScene = createMock(Scene.class);
        SimpleJOGLCamera camera = new SimpleJOGLCamera();
        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(camera);

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockText, "name");

        Event event = new Event();
        event.widget = mockText;
        ModifyEvent modifyEvent = new ModifyEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockText.getText()).andStubReturn("Test");
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockText, mockListener);

        // Initialise test environment.
        testObject = new CameraViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveCamera(camera);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Perform test.
        testObject.modifyText(modifyEvent);

        // Verify results.
        // verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.CameraViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying the node property of a <code>Camera</code>.
     * </p>
     */
    @Test
    public void modifyTextNode()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Text mockText = createMock(Text.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node node = createMock(Node.class);
        SimpleJOGLCamera camera = new SimpleJOGLCamera();
        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(camera);

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockText, "node");

        Event event = new Event();
        event.widget = mockText;
        ModifyEvent modifyEvent = new ModifyEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockText.getText()).andStubReturn("0");
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(node);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockText, mockSceneGraph, mockListener);

        // Initialise test environment.
        testObject = new CameraViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveCamera(camera);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Perform test.
        testObject.modifyText(modifyEvent);

        // Verify results.
        // verify(mockListener);

        assertNotNull(camera.getNode());
    }
}
