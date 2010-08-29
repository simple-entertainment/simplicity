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
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.HashMap;

import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.ui.views.NodeViewListener;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.views.NodeViewListener NodeViewListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NodeViewListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private NodeViewListener testObject;

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
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying the name property of a <code>Node</code>.
     * </p>
     */
    @Test
    public void modifyTextName()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Text mockText = createMock(Text.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        MetaDataNode node = new MetaDataNode(new SimpleNode());

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockText, "name");

        Event event = new Event();
        event.widget = mockText;
        ModifyEvent modifyEvent = new ModifyEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(node);
        expect(mockText.getText()).andStubReturn("Test");
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockSceneGraph, mockText, mockListener);

        // Initialise test environment.
        testObject = new NodeViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveNode(node);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Perform test.
        testObject.modifyText(modifyEvent);

        // Verify results.
        verify(mockListener);

        assertEquals("Test", node.getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying the name property of a <code>Node</code> but the <code>Node</code>is
     * not a <code>MetaDataNode</code>.
     * </p>
     */
    @Test
    public void modifyTextNameNotMetaDataNode()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Text mockText = createMock(Text.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        SimpleNode node = new SimpleNode();

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockText, "name");

        Event event = new Event();
        event.widget = mockText;
        ModifyEvent modifyEvent = new ModifyEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(node);
        expect(mockText.getText()).andStubReturn("Test");
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockSceneGraph, mockText, mockListener);

        // Initialise test environment.
        testObject = new NodeViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveNode(node);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Perform test.
        testObject.modifyText(modifyEvent);

        // Verify results.
        verify(mockListener);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying a rotation property of a <code>Node</code>.
     * </p>
     */
    @Test
    public void modifyTextRotation()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Text mockText = createMock(Text.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        SimpleNode node = new SimpleNode();

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockText, "rotateX");

        Event event = new Event();
        event.widget = mockText;
        ModifyEvent modifyEvent = new ModifyEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(node);
        expect(mockText.getText()).andStubReturn("10.0");
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockSceneGraph, mockText, mockListener);

        // Initialise test environment.
        testObject = new NodeViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveNode(node);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Perform test.
        testObject.modifyText(modifyEvent);

        // Verify results.
        verify(mockListener);

        assertEquals(10.0f * Math.PI / 180.0f, node.getTransformation().getXAxisRotation(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying a translation property of a <code>Node</code>.
     * </p>
     */
    @Test
    public void modifyTextTranslation()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Text mockText = createMock(Text.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        SimpleNode node = new SimpleNode();

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockText, "translateX");

        Event event = new Event();
        event.widget = mockText;
        ModifyEvent modifyEvent = new ModifyEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(node);
        expect(mockText.getText()).andStubReturn("10.0");
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockSceneGraph, mockText, mockListener);

        // Initialise test environment.
        testObject = new NodeViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveNode(node);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Perform test.
        testObject.modifyText(modifyEvent);

        // Verify results.
        verify(mockListener);

        assertEquals(10.0f, node.getTransformation().getTranslation().getX(), 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying the collidable property of a <code>Node</code>.
     * </p>
     */
    @Test
    public void widgetSelectedCollidable()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Button mockButton = createMock(Button.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        SimpleNode node = new SimpleNode();

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockButton, "collidable");

        Event event = new Event();
        event.widget = mockButton;
        SelectionEvent selectionEvent = new SelectionEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(node);
        expect(mockButton.getSelection()).andStubReturn(false);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockSceneGraph, mockButton, mockListener);

        // Initialise test environment.
        testObject = new NodeViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveNode(node);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Verify test environment.
        assertTrue(node.isCollidable());

        // Perform test.
        testObject.widgetSelected(selectionEvent);

        // Verify results.
        verify(mockListener);

        assertFalse(node.isCollidable());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying the modifiable property of a <code>Node</code>.
     * </p>
     */
    @Test
    public void widgetSelectedModifiable()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Button mockButton = createMock(Button.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        SimpleNode node = new SimpleNode();

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockButton, "modifiable");

        Event event = new Event();
        event.widget = mockButton;
        SelectionEvent selectionEvent = new SelectionEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(node);
        expect(mockButton.getSelection()).andStubReturn(false);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockSceneGraph, mockButton, mockListener);

        // Initialise test environment.
        testObject = new NodeViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveNode(node);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Verify test environment.
        assertTrue(node.isModifiable());

        // Perform test.
        testObject.widgetSelected(selectionEvent);

        // Verify results.
        verify(mockListener);

        assertFalse(node.isModifiable());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.NodeViewListener#modifyText(ModifyEvent) modifyText(ModifyEvent)} with the
     * special condition that the widget whose value has changed was displaying the visible property of a <code>Node</code>.
     * </p>
     */
    @Test
    public void widgetSelectedVisible()
    {
        // Create dependencies.
        SceneChangedListener mockListener = createMock(SceneChangedListener.class);

        Button mockButton = createMock(Button.class);

        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        SimpleNode node = new SimpleNode();

        HashMap<Widget, String> map = new HashMap<Widget, String>();
        map.put(mockButton, "visible");

        Event event = new Event();
        event.widget = mockButton;
        SelectionEvent selectionEvent = new SelectionEvent(event);

        // Dictate correct behaviour.
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getNode(0)).andStubReturn(node);
        expect(mockButton.getSelection()).andStubReturn(false);
        mockListener.sceneChanged((SceneChangedEvent) anyObject());
        replay(mockScene, mockSceneGraph, mockButton, mockListener);

        // Initialise test environment.
        testObject = new NodeViewListener(map);
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        SceneManager.getSceneManager().setActiveNode(node);
        SceneManager.getSceneManager().addSceneChangedListener(mockListener);

        // Verify test environment.
        assertTrue(node.isVisible());

        // Perform test.
        testObject.widgetSelected(selectionEvent);

        // Verify results.
        verify(mockListener);

        assertFalse(node.isVisible());
    }
}
