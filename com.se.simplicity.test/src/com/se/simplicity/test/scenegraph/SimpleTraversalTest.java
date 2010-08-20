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

import org.junit.Test;

import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.test.mocks.NodeHierarchy;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.scenegraph.SimpleTraversal SimpleTraversal}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleTraversalTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleTraversal testObject;

    /**
     * <p>
     * Unit test a full traversal of a simple tree of {@link com.se.simplicity.scenegraph.SimpleNode SimpleNode}s.
     * </p>
     */
    @Test
    public void traversalFull()
    {
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setStandardNodeHierarchy();

        testObject = new SimpleTraversal(nodes.node1);
        SimpleNode nextNode;

        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node1, nextNode);
        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node2, nextNode);
        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node3, nextNode);
        assertEquals(2, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node4, nextNode);
        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node5, nextNode);
        assertEquals(1, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node6, nextNode);
        assertEquals(2, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node7, nextNode);
        assertEquals(2, testObject.getBacktracksToNextNode(), 0);
        assertFalse(testObject.hasMoreNodes());

        assertNull(testObject.getNextNode());
    }

    /**
     * <p>
     * Unit test a reset part way through a traversal of a simple tree of {@link com.se.simplicity.scenegraph.SimpleNode SimpleNode}s.
     * </p>
     */
    @Test
    public void traversalReset()
    {
        NodeHierarchy nodes = new NodeHierarchy();
        nodes.setBasicNodeHierarchy();

        testObject = new SimpleTraversal(nodes.node1);
        SimpleNode nextNode;

        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node1, nextNode);
        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node2, nextNode);
        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        testObject.reset();

        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node1, nextNode);
        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node2, nextNode);
        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(nodes.node3, nextNode);
        assertEquals(3, testObject.getBacktracksToNextNode(), 0);
        assertFalse(testObject.hasMoreNodes());

        assertNull(testObject.getNextNode());
    }

    /**
     * <p>
     * Unit test a traversal of a tree with only one {@link com.se.simplicity.scenegraph.SimpleNode SimpleNode}.
     * </p>
     */
    @Test
    public void traversalRootOnly()
    {
        SimpleNode traversal1 = new SimpleNode();
        testObject = new SimpleTraversal(traversal1);
        SimpleNode nextNode;

        assertEquals(0, testObject.getBacktracksToNextNode(), 0);
        assertTrue(testObject.hasMoreNodes());

        nextNode = (SimpleNode) testObject.getNextNode();

        assertEquals(traversal1, nextNode);
        assertEquals(1, testObject.getBacktracksToNextNode(), 0);
        assertFalse(testObject.hasMoreNodes());

        assertNull(testObject.getNextNode());
    }
}
