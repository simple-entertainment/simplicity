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

import java.util.ArrayList;
import java.util.HashMap;

import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.TreeItem;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.ui.views.SceneOutlineSelectionListener;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.views.SceneOutlineSelectionListener SceneOutlineSelectionListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneOutlineSelectionListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneOutlineSelectionListener testObject;

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
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineSelectionListener#widgetSelected(SelectionEvent)
     * widgetSelected(SelectionEvent)} with the special condition that the widget selected maps to a <code>Camera</code>.
     * </p>
     */
    @Test
    public void widgetSelectedCamera()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);
        TreeItem mockTreeItem = createMock(TreeItem.class);

        Scene mockScene = createMock(Scene.class);
        Camera mockCamera = createMock(Camera.class);
        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(mockCamera);

        HashMap<TreeItem, Object> map = new HashMap<TreeItem, Object>();
        map.put(mockTreeItem, mockCamera);

        Event event = new Event();
        event.widget = createMock(Tree.class);
        event.item = mockTreeItem;
        SelectionEvent selectionEvent = new SelectionEvent(event);

        // Initialise test environment.
        testObject = new SceneOutlineSelectionListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(cameras);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockListener);

        // Perform test.
        testObject.widgetSelected(selectionEvent);

        // Verify results.
        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineSelectionListener#widgetSelected(SelectionEvent)
     * widgetSelected(SelectionEvent)} with the special condition that the widget selected maps to a <code>Light</code>.
     * </p>
     */
    @Test
    public void widgetSelectedLight()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);
        TreeItem mockTreeItem = createMock(TreeItem.class);

        Scene mockScene = createMock(Scene.class);
        Light mockLight = createMock(Light.class);
        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockLight);

        HashMap<TreeItem, Object> map = new HashMap<TreeItem, Object>();
        map.put(mockTreeItem, mockLight);

        Event event = new Event();
        event.widget = createMock(Tree.class);
        event.item = mockTreeItem;
        SelectionEvent selectionEvent = new SelectionEvent(event);

        // Initialise test environment.
        testObject = new SceneOutlineSelectionListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Dictate correct behaviour.
        expect(mockScene.getLights()).andStubReturn(lights);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockListener);

        // Perform test.
        testObject.widgetSelected(selectionEvent);

        // Verify results.
        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineSelectionListener#widgetSelected(SelectionEvent)
     * widgetSelected(SelectionEvent)} with the special condition that the widget selected maps to a <code>Node</code>.
     * </p>
     */
    @Test
    public void widgetSelectedNode()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);
        TreeItem mockTreeItem = createMock(TreeItem.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        HashMap<TreeItem, Object> map = new HashMap<TreeItem, Object>();
        map.put(mockTreeItem, mockNode);

        Event event = new Event();
        event.widget = createMock(Tree.class);
        event.item = mockTreeItem;
        SelectionEvent selectionEvent = new SelectionEvent(event);

        // Initialise test environment.
        testObject = new SceneOutlineSelectionListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(mockNode);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockSceneGraph, mockListener);

        // Perform test.
        testObject.widgetSelected(selectionEvent);

        // Verify results.
        verify(mockListener);
    }
}
