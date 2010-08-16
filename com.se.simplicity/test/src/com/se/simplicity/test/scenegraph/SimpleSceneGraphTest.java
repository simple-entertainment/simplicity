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
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
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
}
