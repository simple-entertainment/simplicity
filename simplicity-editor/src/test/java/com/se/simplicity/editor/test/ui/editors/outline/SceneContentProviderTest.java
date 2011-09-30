/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.editors.outline;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.outline.SceneContentProvider;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.outline.SceneContentProvider SceneContentProvider}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneContentProviderTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneContentProvider testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SceneContentProvider();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneContentProvider#getChildren(Object) getChildren(Object)}.
     * </p>
     */
    @Test
    public void getChildren()
    {
        // Create dependencies.
        Node mockNode0 = createMock(Node.class);
        Node mockNode1 = createMock(Node.class);
        Node mockNode2 = createMock(Node.class);
        ArrayList<Node> mockChildren = new ArrayList<Node>();
        mockChildren.add(mockNode1);
        mockChildren.add(mockNode2);

        // Dictate correct behaviour.
        expect(mockNode0.getChildren()).andStubReturn(mockChildren);
        replay(mockNode0);

        // Perform test.
        Object[] children = testObject.getChildren(mockNode0);

        // Verify results.
        assertEquals(mockNode1, children[0]);
        assertEquals(mockNode2, children[1]);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneContentProvider#getChildren(Object) getChildren(Object)} with the
     * special condition that the parent is not a Node.
     * </p>
     */
    @Test
    public void getChildrenNotNode()
    {
        // Perform test.
        Object[] children = testObject.getChildren(createMock(Object.class));

        // Verify results.
        assertNull(children);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneContentProvider#getElements(Object) getElements(Object)}.
     * </p>
     */
    @Test
    public void getElements()
    {
        // Create dependencies.
        Scene mockScene = createMock(Scene.class);
        Camera mockCamera0 = createMock(Camera.class);
        Camera mockCamera1 = createMock(Camera.class);
        Light mockLight0 = createMock(Light.class);
        Light mockLight1 = createMock(Light.class);
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        Node mockNode = createMock(Node.class);
        ArrayList<Camera> cameras = new ArrayList<Camera>();
        cameras.add(mockCamera0);
        cameras.add(mockCamera1);
        ArrayList<Light> lights = new ArrayList<Light>();
        lights.add(mockLight0);
        lights.add(mockLight1);

        // Dictate correct behaviour.
        expect(mockScene.getCameras()).andStubReturn(cameras);
        expect(mockScene.getLights()).andStubReturn(lights);
        expect(mockScene.getSceneGraph()).andStubReturn(mockSceneGraph);
        expect(mockSceneGraph.getRoot()).andStubReturn(mockNode);
        replay(mockScene, mockSceneGraph);

        // Perform test.
        Object[] elements = testObject.getElements(mockScene);

        // Verify results.
        assertEquals(mockCamera0, elements[0]);
        assertEquals(mockCamera1, elements[1]);
        assertEquals(mockLight0, elements[2]);
        assertEquals(mockLight1, elements[3]);
        assertEquals(mockNode, elements[4]);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneContentProvider#getParent(Object) getParent(Object)}.
     * </p>
     */
    @Test
    public void getParent()
    {
        // Create dependencies.
        Node mockNode0 = createMock(Node.class);
        Node mockNode1 = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockNode0.getParent()).andStubReturn(mockNode1);
        replay(mockNode0);

        // Perform test.
        Object parent = testObject.getParent(mockNode0);

        // Verify results.
        assertEquals(mockNode1, parent);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneContentProvider#getParent(Object) getParent(Object)} with the
     * special condition that the element is not a Node.
     * </p>
     */
    @Test
    public void getParentNotNode()
    {
        // Perform test.
        Object parent = testObject.getParent(createMock(Object.class));

        // Verify results.
        assertNull(parent);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneContentProvider#hasChildren(Object) hasChildren(Object)}.
     * </p>
     */
    @Test
    public void hasChildren()
    {
        // Create dependencies.
        Node mockNode0 = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockNode0.hasChildren()).andStubReturn(true);
        replay(mockNode0);

        // Perform test.
        boolean hasChildren = testObject.hasChildren(mockNode0);

        // Verify results.
        assertTrue(hasChildren);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneContentProvider#hasChildren(Object) hasChildren(Object)} with the
     * special condition that the element is not a Node.
     * </p>
     */
    @Test
    public void hasChildrenNotNode()
    {
        // Perform test.
        boolean hasChildren = testObject.hasChildren(createMock(Object.class));

        // Verify results.
        assertFalse(hasChildren);
    }
}
