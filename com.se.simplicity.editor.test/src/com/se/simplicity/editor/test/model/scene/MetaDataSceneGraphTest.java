/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.model.scene;

import static org.easymock.EasyMock.createMock;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;

import org.junit.Test;

import com.se.simplicity.editor.model.scene.MetaDataNode;
import com.se.simplicity.editor.model.scene.MetaDataSceneGraph;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.test.mocks.NodeHierarchy;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.model.scene.MetaDataSceneGraph MetaDataSceneGraph}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MetaDataSceneGraphTest
{
    /**
     * An instance of the class being unit tested.
     */
    private MetaDataSceneGraph testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.model.scene.MetaDataSceneGraph.wrapNodes wrapNodes()}.
     * </p>
     */
    @Test
    public void wrapNodes()
    {
        SceneGraph mockSceneGraph = createMock(SceneGraph.class);
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject = new MetaDataSceneGraph(mockSceneGraph);

        MetaDataNode node0 = testObject.wrapNodes(nodes.node1);

        assertEquals("Node (0)", node0.getAttribute("name"));
        assertNull(node0.getParent());
        assertNull(node0.getWrappedNode().getParent());
        assertEquals(3, node0.getChildren().size(), 0);
        assertEquals(0, node0.getWrappedNode().getChildren().size(), 0);

        MetaDataNode node1 = (MetaDataNode) node0.getChildren().get(0);
        assertEquals("Node (1)", node1.getAttribute("name"));
        assertEquals(node0, node1.getParent());
        assertNull(node1.getWrappedNode().getParent());
        assertEquals(1, node1.getChildren().size(), 0);
        assertEquals(0, node1.getWrappedNode().getChildren().size(), 0);

        MetaDataNode node2 = (MetaDataNode) node1.getChildren().get(0);
        assertEquals("Vertex Group (2)", node2.getAttribute("name"));
        assertEquals(node1, node2.getParent());
        assertNull(node1.getWrappedNode().getParent());
        assertEquals(0, node2.getChildren().size(), 0);
        assertEquals(0, node2.getWrappedNode().getChildren().size(), 0);

        MetaDataNode node3 = (MetaDataNode) node0.getChildren().get(1);
        assertEquals("Node (3)", node3.getAttribute("name"));
        assertEquals(node0, node3.getParent());
        assertNull(node3.getWrappedNode().getParent());
        assertEquals(2, node3.getChildren().size(), 0);
        assertEquals(0, node3.getWrappedNode().getChildren().size(), 0);

        MetaDataNode node4 = (MetaDataNode) node3.getChildren().get(0);
        assertEquals("Node (4)", node4.getAttribute("name"));
        assertEquals(node3, node4.getParent());
        assertNull(node4.getWrappedNode().getParent());
        assertEquals(0, node4.getChildren().size(), 0);
        assertEquals(0, node4.getWrappedNode().getChildren().size(), 0);

        MetaDataNode node5 = (MetaDataNode) node3.getChildren().get(1);
        assertEquals("Node (5)", node5.getAttribute("name"));
        assertEquals(node3, node5.getParent());
        assertNull(node4.getWrappedNode().getParent());
        assertEquals(0, node5.getChildren().size(), 0);
        assertEquals(0, node5.getWrappedNode().getChildren().size(), 0);

        MetaDataNode node6 = (MetaDataNode) node0.getChildren().get(2);
        assertEquals("Node (6)", node6.getAttribute("name"));
        assertEquals(node0, node6.getParent());
        assertNull(node6.getWrappedNode().getParent());
        assertEquals(0, node6.getChildren().size(), 0);
        assertEquals(0, node6.getWrappedNode().getChildren().size(), 0);
    }
}
