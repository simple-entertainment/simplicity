package com.se.simplicity.scenegraph;

/**
 * <p>
 * A tree type graph of {@link com.se.simplicity.scenegraph.Node Node}s that represents a scene in a virtual universe. The
 * <code>SceneGraph</code> manages all the components within it. Methods of the <code>SceneGraph</code> should be called instead
 * of calling methods on its components directly. This ensures that the management of those components is not undermined.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public interface SceneGraph
{
	/**
	 * <p>
	 * Adds a subgraph to the <code>SceneGraph</code>. The subgraph must be a tree type graph. The <code>SceneGraph</code> will
	 * determine where to add the subgraph depending on the internal structure it maintains.
	 * </p>
	 * 
	 * <p>
	 * This method should be called instead of retrieving the root {@link com.se.simplicity.scenegraph.Node Node} of the
	 * <code>SceneGraph</code> and manually adding a subgraph to maintain the integrity of the <code>SceneGraph</code>.
	 * </p>
	 * 
	 * @param subgraphRoot The root {@link com.se.simplicity.scenegraph.Node Node} of the subgraph to add.
	 */
	void addSubgraph(Node subgraphRoot);

	/**
	 * <p>
	 * Adds a subgraph to the <code>SceneGraph</code>. The subgraph must be a tree type graph.
	 * </p>
	 * 
	 * <p>
	 * This method should be called instead of retrieving the root {@link com.se.simplicity.scenegraph.Node Node} of the
	 * <code>SceneGraph</code> and manually adding a subgraph to maintain the integrity of the <code>SceneGraph</code>.
	 * </p>
	 * 
	 * @param subgraphRoot The root {@link com.se.simplicity.scenegraph.Node Node} of the subgraph to add.
	 * @param parent The {@link com.se.simplicity.scenegraph.Node Node} within the <code>SceneGraph</code> to add the subgraph
	 * under.
	 */
	void addSubgraph(Node subgraphRoot, Node parent);
	
	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.scenegraph.Node Node} with the given ID.
	 * </p>
	 * 
	 * @param id The ID of the {@link com.se.simplicity.scenegraph.Node Node} to retrieve.
	 * 
	 * @return The {@link com.se.simplicity.scenegraph.Node Node} with the given ID.
	 */
	Node getNode(int id);

	/**
	 * Retrieves the root {@link com.se.simplicity.scenegraph.Node Node} of this <code>SceneGraph</code>.
	 * 
	 * @return The root {@link com.se.simplicity.scenegraph.Node Node} of this <code>SceneGraph</code>.
	 */
	Node getRoot();
	
	/**
	 * <p>
	 * Removes a subgraph from the <code>SceneGraph</code>.
	 * </p>
	 * 
	 * <p>
	 * This method should be called instead of retrieving the root {@link com.se.simplicity.scenegraph.Node Node} of the
	 * subgraph and manually removing it from its parent to maintain the integrity of the <code>SceneGraph</code>.
	 * </p>
	 * 
	 * @param subgraphRoot The root {@link com.se.simplicity.scenegraph.Node Node} of the subgraph to remove.
	 */
	void removeSubgraph(Node subgraphRoot);
}
