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
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
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
	 * Unit test a reset part way through a traversal of a simple tree of {@link com.se.simplicity.scenegraph.SimpleNode
	 * SimpleNode}s.
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
