/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.scenegraph;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.scenegraph.SimpleSceneGraph;
import com.se.simplicity.test.mocks.NodeHierarchy;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.scenegraph.SimpleSceneGraph SimpleSceneGraph}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleSceneGraphTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleSceneGraph testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.scenegraph.SimpleSceneGraph.addSubgraph addSubgraph()}.
     * </p>
     */
    @Test
    public void addSubgraph()
    {
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.addSubgraph(nodes.node1);

        assertTrue(testObject.getRoot().getChildren().contains(nodes.node1));
        assertEquals(testObject.getRoot(), nodes.node1.getParent());

        assertEquals(1, nodes.node1.getID(), 0);
        assertEquals(testObject.getNode(1), nodes.node1);
        assertEquals(2, nodes.node2.getID(), 0);
        assertEquals(testObject.getNode(2), nodes.node2);
        assertEquals(3, nodes.node3.getID(), 0);
        assertEquals(testObject.getNode(3), nodes.node3);
        assertEquals(4, nodes.node4.getID(), 0);
        assertEquals(testObject.getNode(4), nodes.node4);
        assertEquals(5, nodes.node5.getID(), 0);
        assertEquals(testObject.getNode(5), nodes.node5);
        assertEquals(6, nodes.node6.getID(), 0);
        assertEquals(testObject.getNode(6), nodes.node6);
        assertEquals(7, nodes.node7.getID(), 0);
        assertEquals(testObject.getNode(7), nodes.node7);
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SimpleSceneGraph();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.scenegraph.SimpleSceneGraph.removeSubgraph removeSubgraph()}.
     * </p>
     */
    @Test
    public void removeSubgraph()
    {
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.addSubgraph(nodes.node1);
        testObject.removeSubgraph(nodes.node4);

        assertTrue(testObject.getRoot().getChildren().contains(nodes.node1));
        assertEquals(testObject.getRoot(), nodes.node1.getParent());

        assertTrue(nodes.node1.getChildren().contains(nodes.node2));
        assertEquals(nodes.node1, nodes.node2.getParent());

        assertFalse(nodes.node1.getChildren().contains(nodes.node4));
        assertNull(nodes.node4.getParent());

        assertTrue(nodes.node1.getChildren().contains(nodes.node7));
        assertEquals(nodes.node1, nodes.node7.getParent());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.scenegraph.SimpleSceneGraph#resetIDs() resetIDs()}.
     * </p>
     */
    @Test
    public void resetIDs()
    {
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject.addSubgraph(nodes.node1);
        testObject.removeSubgraph(nodes.node4);
        
        testObject.resetIDs();

        assertEquals(nodes.node1, testObject.getNode(1));
        assertEquals(nodes.node2, testObject.getNode(2));
        assertEquals(nodes.node3, testObject.getNode(3));
        assertEquals(nodes.node7, testObject.getNode(4));
    }
}
