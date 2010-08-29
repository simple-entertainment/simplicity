/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.views;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.io.FileNotFoundException;
import java.util.ArrayList;

import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.TreeItem;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.ui.views.SceneOutlineView;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.test.mocks.NodeHierarchy;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;
import com.se.simplicity.util.metadata.scenegraph.MetaDataSceneGraph;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.views.SceneOutlineView SceneOutlineView}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneOutlineViewTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneOutlineView testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SceneOutlineView();

        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the constructor {@link com.se.simplicity.editor.ui.views.SceneOutlineView#SceneOutlineView() SceneOutlineView()}.
     * </p>
     */
    @Test
    public void sceneOutlineView()
    {
        testObject = new SceneOutlineView();

        assertTrue(SceneManager.getSceneManager().getSceneChangedListeners().contains(testObject));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineView#createPartControl(Composite) createPartControl(Composite)}.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void createPartControl() throws FileNotFoundException
    {
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");

        reset(mockScene);
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        expect(mockNode.hasChildren()).andStubReturn(false);
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockScene, mockSceneGraph, mockNode);

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        Tree tree = testObject.getTree();

        assertEquals(1, tree.getItemCount(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineView#createPartControl(Composite) createPartControl(Composite)} with
     * the special condition that no active scene exists.
     * </p>
     * 
     * @throws FileNotFoundException Thrown if source file is not found.
     */
    @Test
    public void createPartControlNoActiveScene() throws FileNotFoundException
    {
        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        Tree tree = testObject.getTree();

        assertEquals(0, tree.getItemCount(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineView#dispose() dispose()}.
     * </p>
     */
    @Test
    public void dispose()
    {
        testObject.dispose();

        assertTrue(!SceneManager.getSceneManager().getSceneChangedListeners().contains(testObject));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineView#sceneChanged(SceneChangedEvent) sceneChanged(SceneChangedEvent)}
     * with the special condition that the event is of type 'NODE_MODIFIED'.
     * </p>
     */
    @Test
    public void sceneChangedNodeModified()
    {
        // Create dependencies.
        SceneChangedEvent mockEvent = createMock(SceneChangedEvent.class);
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        MetaDataNode mockNode = createMock(MetaDataNode.class);

        // Dictate correct behaviour.
        expect(mockEvent.getScene()).andStubReturn(mockScene);
        expect(mockEvent.getSceneComponent()).andStubReturn(mockNode);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.NODE_MODIFIED);
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        expect(mockNode.hasChildren()).andStubReturn(false);
        expect(mockNode.getID()).andStubReturn(0);
        expect(mockNode.getAttribute("name")).andReturn("Node0");
        expect(mockNode.getAttribute("name")).andReturn("Test");
        replay(mockEvent, mockScene, mockSceneGraph, mockNode);

        // Initialise test environment.
        SceneManager.getSceneManager().addSceneDefinition(mockScene, "test");
        SceneManager.getSceneManager().setActiveScene("test");
        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        // Verify test environment.
        Tree tree = testObject.getTree();

        assertEquals("Node0", tree.getItem(0).getText());

        // Perform test.
        testObject.sceneChanged(mockEvent);

        // Verify results.
        assertEquals("Test", tree.getItem(0).getText());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineView#sceneChanged(SceneChangedEvent) sceneChanged(SceneChangedEvent)}
     * with the special condition that the event is of type 'SCENE_ACTIVATED'.
     * </p>
     */
    @Test
    public void sceneChangedSceneActivated()
    {
        SceneChangedEvent mockEvent = createMock(SceneChangedEvent.class);
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        expect(mockEvent.getScene()).andStubReturn(mockScene);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.SCENE_ACTIVATED);
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        expect(mockNode.hasChildren()).andStubReturn(false);
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockEvent, mockScene, mockSceneGraph, mockNode);

        testObject.sceneChanged(mockEvent);

        Tree tree = testObject.getTree();

        assertEquals(1, tree.getItemCount(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineView#sceneChanged(SceneChangedEvent) sceneChanged(SceneChangedEvent)}
     * with the special condition that the event is of type 'SCENE_MODIFIED'.
     * </p>
     */
    @Test
    public void sceneChangedSceneModified()
    {
        SceneChangedEvent mockEvent = createMock(SceneChangedEvent.class);
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        expect(mockEvent.getScene()).andStubReturn(mockScene);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.SCENE_MODIFIED);
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        expect(mockNode.hasChildren()).andStubReturn(false);
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockEvent, mockScene, mockSceneGraph, mockNode);

        testObject.sceneChanged(mockEvent);

        Tree tree = testObject.getTree();

        assertEquals(1, tree.getItemCount(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.views.SceneOutlineView#sceneChanged(SceneChangedEvent) sceneChanged(SceneChangedEvent)}
     * with the special condition that the events are of type 'SCENE_MODIFIED' followed by type 'SCENE_ACTIVATED'.
     * </p>
     */
    @Test
    public void sceneChangedSceneModifiedActivated()
    {
        SceneChangedEvent mockEvent = createMock(SceneChangedEvent.class);
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        expect(mockEvent.getScene()).andStubReturn(mockScene);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.SCENE_MODIFIED);
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        expect(mockNode.hasChildren()).andStubReturn(false);
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockEvent, mockScene, mockSceneGraph, mockNode);

        testObject.sceneChanged(mockEvent);

        reset(mockEvent);
        expect(mockEvent.getScene()).andStubReturn(mockScene);
        expect(mockEvent.getType()).andStubReturn(SceneChangedEventType.SCENE_ACTIVATED);
        replay(mockEvent);

        testObject.sceneChanged(mockEvent);

        Tree tree = testObject.getTree();

        assertEquals(1, tree.getItemCount(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.controller.outline.OutlineController.update update()}, specifically the updating of the
     * camera tree items.
     * </p>
     */
    @Test
    public void updateCameras()
    {
        Scene mockScene = createMock(Scene.class);

        ArrayList<Camera> cameras = new ArrayList<Camera>();
        MetaDataCamera mockCamera0 = createMock(MetaDataCamera.class);
        MetaDataCamera mockCamera1 = createMock(MetaDataCamera.class);
        cameras.add(mockCamera0);
        cameras.add(mockCamera1);

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockCamera0.getAttribute("name")).andReturn("Camera0");
        expect(mockCamera1.getAttribute("name")).andReturn("Camera1");
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(null);
        replay(mockScene, mockCamera0, mockCamera1);

        testObject.update(mockScene);

        Tree tree = testObject.getTree();

        assertEquals(2, tree.getItemCount(), 0);
        TreeItem item0 = tree.getItem(0);
        assertEquals("Camera0", item0.getText());
        TreeItem item1 = tree.getItem(1);
        assertEquals("Camera1", item1.getText());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.controller.outline.OutlineController.update update()}, specifically the updating of the
     * light tree items.
     * </p>
     */
    @Test
    public void updateLights()
    {
        Scene mockScene = createMock(Scene.class);

        ArrayList<Light> lights = new ArrayList<Light>();
        MetaDataLight mockLight0 = createMock(MetaDataLight.class);
        MetaDataLight mockLight1 = createMock(MetaDataLight.class);
        lights.add(mockLight0);
        lights.add(mockLight1);

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockLight0.getAttribute("name")).andReturn("Light0");
        expect(mockLight1.getAttribute("name")).andReturn("Light1");
        expect(mockScene.getSceneGraph()).andStubReturn(null);
        replay(mockScene, mockLight0, mockLight1);

        testObject.update(mockScene);

        Tree tree = testObject.getTree();

        assertEquals(2, tree.getItemCount(), 0);
        TreeItem item0 = tree.getItem(0);
        assertEquals("Light0", item0.getText());
        TreeItem item1 = tree.getItem(1);
        assertEquals("Light1", item1.getText());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.controller.outline.OutlineController.update update()}, specifically the updating of the
     * scene graph tree items.
     * </p>
     */
    @Test
    public void updateSceneGraph()
    {
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockScene, mockSceneGraph);

        testObject.update(mockScene);

        Tree tree = testObject.getTree();

        assertEquals(1, tree.getItemCount(), 0);
        TreeItem item0 = tree.getItem(0);
        assertEquals("Node0", item0.getText());

        assertEquals(3, item0.getItemCount(), 0);
        TreeItem item1 = item0.getItem(0);
        assertEquals("Node1", item1.getText());
        TreeItem item3 = item0.getItem(1);
        assertEquals("Node3", item3.getText());
        TreeItem item6 = item0.getItem(2);
        assertEquals("Node6", item6.getText());

        assertEquals(1, item1.getItemCount(), 0);
        TreeItem item2 = item1.getItem(0);
        assertEquals("Node2", item2.getText());

        assertEquals(2, item3.getItemCount(), 0);
        TreeItem item4 = item3.getItem(0);
        assertEquals("Node4", item4.getText());
        TreeItem item5 = item3.getItem(1);
        assertEquals("Node5", item5.getText());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.controller.outline.OutlineController.update update()}, specifically the updating of the
     * scene graph tree items with the special condition that the <code>Node</code>s in the <code>SceneGraph</code> are <code>MetaDataNode</code>s.
     * </p>
     */
    @Test
    public void updateSceneGraphMetaDataNodes()
    {
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        SimpleTraversal traversal = new SimpleTraversal(MetaDataSceneGraph.wrapNodes(nodes.node1));
        nodes.node1 = traversal.getNextNode();
        nodes.node2 = traversal.getNextNode();
        nodes.node3 = traversal.getNextNode();
        nodes.node4 = traversal.getNextNode();
        nodes.node5 = traversal.getNextNode();
        nodes.node6 = traversal.getNextNode();
        nodes.node7 = traversal.getNextNode();

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockScene, mockSceneGraph);

        testObject.update(mockScene);

        Tree tree = testObject.getTree();

        assertEquals(1, tree.getItemCount(), 0);
        TreeItem item0 = tree.getItem(0);
        assertEquals("Node (0)", item0.getText());

        assertEquals(3, item0.getItemCount(), 0);
        TreeItem item1 = item0.getItem(0);
        assertEquals("Node (1)", item1.getText());
        TreeItem item3 = item0.getItem(1);
        assertEquals("Node (3)", item3.getText());
        TreeItem item6 = item0.getItem(2);
        assertEquals("Node (6)", item6.getText());

        assertEquals(1, item1.getItemCount(), 0);
        TreeItem item2 = item1.getItem(0);
        assertEquals("Vertex Group (2)", item2.getText());

        assertEquals(2, item3.getItemCount(), 0);
        TreeItem item4 = item3.getItem(0);
        assertEquals("Node (4)", item4.getText());
        TreeItem item5 = item3.getItem(1);
        assertEquals("Node (5)", item5.getText());
    }
}
