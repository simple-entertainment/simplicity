/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.controller.outline;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import java.util.ArrayList;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Tree;
import org.eclipse.swt.widgets.TreeItem;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.controller.outline.OutlineController;
import com.se.simplicity.editor.model.scene.MetaDataCamera;
import com.se.simplicity.editor.model.scene.MetaDataLight;
import com.se.simplicity.editor.model.scene.MetaDataSceneGraph;
import com.se.simplicity.editor.view.outline.OutlineViewFactory;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.test.mocks.NodeHierarchy;

public class OutlineControllerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private OutlineController testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new OutlineController();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.controller.outline.OutlineController.init init()}.
     * </p>
     */
    @Test
    public void init()
    {
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Composite mockComposite = createMock(Composite.class);
        Tree mockTree = createMock(Tree.class);

        testObject.setModel(mockRenderingEngine);
        testObject.setView(mockTree);

        reset(mockTree, mockRenderingEngine);
        expect(mockTree.setParent(mockComposite)).andReturn(true);
        mockTree.removeAll(); // Confirms that update() was called
        expect(mockRenderingEngine.getScene()).andReturn(null);
        replay(mockTree, mockRenderingEngine);

        testObject.init(mockComposite);

        verify(mockTree);
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
        Tree tree = new OutlineViewFactory().getOutlineView();
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Scene mockScene = createMock(Scene.class);

        ArrayList<Camera> cameras = new ArrayList<Camera>();
        MetaDataCamera mockCamera0 = createMock(MetaDataCamera.class);
        MetaDataCamera mockCamera1 = createMock(MetaDataCamera.class);
        cameras.add(mockCamera0);
        cameras.add(mockCamera1);

        testObject.setModel(mockRenderingEngine);
        testObject.setView(tree);

        expect(mockRenderingEngine.getScene()).andStubReturn(mockScene);
        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockCamera0.getAttribute("name")).andReturn("Camera0");
        expect(mockCamera1.getAttribute("name")).andReturn("Camera1");
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(null);
        replay(mockRenderingEngine, mockScene, mockCamera0, mockCamera1);

        testObject.update();

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
        Tree tree = new OutlineViewFactory().getOutlineView();
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Scene mockScene = createMock(Scene.class);

        ArrayList<Light> lights = new ArrayList<Light>();
        MetaDataLight mockLight0 = createMock(MetaDataLight.class);
        MetaDataLight mockLight1 = createMock(MetaDataLight.class);
        lights.add(mockLight0);
        lights.add(mockLight1);

        testObject.setModel(mockRenderingEngine);
        testObject.setView(tree);

        expect(mockRenderingEngine.getScene()).andStubReturn(mockScene);
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockLight0.getAttribute("name")).andReturn("Light0");
        expect(mockLight1.getAttribute("name")).andReturn("Light1");
        expect(mockScene.getSceneGraph()).andStubReturn(null);
        replay(mockRenderingEngine, mockScene, mockLight0, mockLight1);

        testObject.update();

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
        Tree tree = new OutlineViewFactory().getOutlineView();
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Scene mockScene = createMock(Scene.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.setModel(mockRenderingEngine);
        testObject.setView(tree);

        expect(mockRenderingEngine.getScene()).andStubReturn(mockScene);
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockRenderingEngine, mockScene, mockSceneGraph);

        testObject.update();

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
        Tree tree = new OutlineViewFactory().getOutlineView();
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
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

        testObject.setModel(mockRenderingEngine);
        testObject.setView(tree);

        expect(mockRenderingEngine.getScene()).andStubReturn(mockScene);
        expect(mockScene.getCameras()).andStubReturn(new ArrayList<Camera>());
        expect(mockScene.getLights()).andStubReturn(new ArrayList<Light>());
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(nodes.node1);
        replay(mockRenderingEngine, mockScene, mockSceneGraph);

        testObject.update();

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
