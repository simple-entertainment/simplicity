/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.scenegraph;

import java.util.List;

/**
 * <p>
 * A simple traversal that traverses {@link com.se.simplicity.scenegraph.Node Node}s in a prefix order.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleTraversal implements Traversal
{
    /**
     * <p>
     * The number of backtracks required to get to the next {@link com.se.simplicity.scenegraph.Node Node}.
     * </p>
     */
    private int fBacktracksToNextNode;

    /**
     * <p>
     * The next {@link com.se.simplicity.scenegraph.Node Node} to retrieve from this traversal.
     * </p>
     */
    private Node fNextNode;

    /**
     * <p>
     * The root {@link com.se.simplicity.scenegraph.Node Node} of the graph to traverse.
     * </p>
     */
    private Node fRoot;

    /**
     * <p>
     * Creates an instance of <code>SimpleTraversal</code>.
     * </p>
     * 
     * @param root The root {@link com.se.simplicity.scenegraph.Node Node} of the graph to traverse.
     */
    public SimpleTraversal(final Node root)
    {
        fRoot = root;

        fBacktracksToNextNode = 0;
        fNextNode = null;

        reset();
    }

    /**
     * <p>
     * Finds the next {@link com.se.simplicity.scenegraph.Node Node} in this traversal, updating the state variables appropriately.
     * </p>
     * 
     * @return The next <code>Node</code> in this traversal,
     */
    private Node findNextNode()
    {
        fBacktracksToNextNode = 0;

        // If the only node in the traversal is the root, end the traversal.
        if (fNextNode == fRoot && !fNextNode.hasChildren())
        {
            fBacktracksToNextNode++;

            return (null);
        }

        // If the current node has children, move to it's first child.
        if (fNextNode.hasChildren())
        {
            return (fNextNode.getChildren().get(0));
        }

        // If the current node has no children, backtrack to the next sibling.
        List<Node> siblings = fNextNode.getParent().getChildren();

        // While the current node has no more siblings, move to it's parent.
        while (siblings.indexOf(fNextNode) + 1 == siblings.size())
        {
            fBacktracksToNextNode++;

            fNextNode = fNextNode.getParent();

            // If the next node is the root, end the traversal.
            if (fNextNode == fRoot)
            {
                fBacktracksToNextNode++;

                return (null);
            }

            siblings = fNextNode.getParent().getChildren();
        }

        // If the next node has more siblings, move to it's next sibling.
        fBacktracksToNextNode++;

        return (siblings.get(siblings.indexOf(fNextNode) + 1));
    }

    /**
     * <p>
     * Retrieves the number of backtracks required to get to the next {@link com.se.simplicity.scenegraph.Node Node}.
     * </p>
     * 
     * <p>
     * A backtrack is an upward movement in the graph being traversed. An additional backtrack is performed at the end of a traversal to move above
     * back to the root. This ensures that the number of backtracks performed is equal to the number of downward movements performed including the
     * initial downward movement to the root when <code>getNextNode()</code> is first called.
     * </p>
     * 
     * @return The number of backtracks required to get to the next <code>Node</code>.
     */
    public int getBacktracksToNextNode()
    {
        return (fBacktracksToNextNode);
    }

    @Override
    public Node getNextNode()
    {
        // If the traversal has ended.
        if (fNextNode == null)
        {
            return (null);
        }

        Node currentNode = fNextNode;
        fNextNode = findNextNode();

        return (currentNode);
    }

    @Override
    public boolean hasMoreNodes()
    {
        return (fNextNode != null);
    }

    @Override
    public void reset()
    {
        fBacktracksToNextNode = 0;
        fNextNode = fRoot;
    }
}
