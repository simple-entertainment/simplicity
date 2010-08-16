package com.se.simplicity.scenegraph;

// J2SE imports.
import java.util.List;

/**
 * <p>
 * A simple traversal that traverses {@link com.se.simplicity.scenegraph.Node Node}s in a prefix order.
 * </p>
 * 
 * @author simple
 */
public class SimpleTraversal implements Traversal
{
	/**
	 * <p>
	 * The number of backtracks required to get to the next {@link com.se.simplicity.scenegraph.Node Node}.
	 * </p>
	 */
	private int backtracksToNextNode;

	/**
	 * <p>
	 * The next {@link com.se.simplicity.scenegraph.Node Node} to retrieve from this traversal.
	 * </p>
	 */
	private Node nextNode;

	/**
	 * <p>
	 * The root {@link com.se.simplicity.scenegraph.Node Node} of the graph to traverse.
	 * </p>
	 */
	private Node root;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleTraversal</code>.
	 * </p>
	 * 
	 * @param root The root {@link com.se.simplicity.scenegraph.Node Node} of the graph to traverse.
	 */
	public SimpleTraversal(final Node root)
	{
		this.root = root;

		reset();
	}

	/**
	 * <p>
	 * Finds the next {@link com.se.simplicity.scenegraph.Node Node} in this traversal, updating the state variables
	 * appropriately.
	 * </p>
	 * 
	 * @return The next {@link com.se.simplicity.scenegraph.Node Node} in this traversal,
	 */
	protected Node findNextNode()
	{
		backtracksToNextNode = 0;

		// If the only node in the traversal is the root, end the traversal.
		if (nextNode == root && !nextNode.hasChildren())
		{
			backtracksToNextNode++;

			return (null);
		}

		// If the current node has children, move to it's first child.
		if (nextNode.hasChildren())
		{
			return (nextNode.getChildren().get(0));
		}

		// If the current node has no children, backtrack to the next sibling.
		{
			List<Node> siblings = nextNode.getParent().getChildren();

			// While the current node has no more siblings, move to it's parent.
			while (siblings.indexOf(nextNode) + 1 == siblings.size())
			{
				backtracksToNextNode++;

				nextNode = nextNode.getParent();

				// If the next node is the root, end the traversal.
				if (nextNode == root)
				{
					backtracksToNextNode++;

					return (null);
				}

				siblings = nextNode.getParent().getChildren();
			}

			// If the next node has more siblings, move to it's next sibling.
			backtracksToNextNode++;

			return (siblings.get(siblings.indexOf(nextNode) + 1));
		}
	}

	/**
	 * <p>
	 * Retrieves the number of backtracks required to get to the next {@link com.se.simplicity.scenegraph.Node Node}.
	 * </p>
	 * 
	 * <p>
	 * A backtrack is an upward movement in the graph being traversed. An additional backtrack is performed at the end of a
	 * traversal to move above back to the root. This ensures that the number of backtracks performed is equal to the number of
	 * downward movements performed including the initial downward movement to the root when <code>getNextNode()</code> is first
	 * called.
	 * </p>
	 * 
	 * @return The number of backtracks required to get to the next {@link com.se.simplicity.scenegraph.Node Node}.
	 */
	public int getBacktracksToNextNode()
	{
		return (backtracksToNextNode);
	}

	@Override
	public Node getNextNode()
	{
		// If the traversal has ended.
		if (nextNode == null)
		{
			return (null);
		}

		Node currentNode = nextNode;
		nextNode = findNextNode();

		return (currentNode);
	}

	@Override
	public boolean hasMoreNodes()
	{
		return (nextNode != null);
	}

	@Override
	public void reset()
	{
		backtracksToNextNode = 0;
		nextNode = root;
	}
}
