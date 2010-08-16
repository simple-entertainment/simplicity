package com.se.simplicity.scenegraph;

/**
 * <p>
 * Traverses a tree type graph of {@link com.se.simplicity.scenegraph.Node Node}s. The order in which the
 * {@link com.se.simplicity.scenegraph.Node Node}s are traversed is specific to each implementation.
 * </p>
 * 
 * @author simple
 */
public interface Traversal
{
	/**
	 * <p>
	 * Retrieves the next {@link com.se.simplicity.scenegraph.Node Node} in this traversal.
	 * </p>
	 * 
	 * @return The next {@link com.se.simplicity.scenegraph.Node Node} in this traversal or <code>null</code> if there are no more
	 * {@link com.se.simplicity.scenegraph.Node Node}s to be returned.
	 */
	Node getNextNode();

	/**
	 * <p>
	 * Determines if there are more {@link com.se.simplicity.scenegraph.Node Node}s to be retrieved by this traversal.
	 * </p>
	 * 
	 * @return True if a {@link com.se.simplicity.scenegraph.Node Node} will be retrieved by the next call to
	 * <code>getNextNode()</code>, false otherwise.
	 */
	boolean hasMoreNodes();

	/**
	 * <p>
	 * Resets this traversal so that the next {@link com.se.simplicity.scenegraph.Node Node} retrieved is the root
	 * {@link com.se.simplicity.scenegraph.Node Node} of the graph.
	 * </p>
	 */
	void reset();
}
