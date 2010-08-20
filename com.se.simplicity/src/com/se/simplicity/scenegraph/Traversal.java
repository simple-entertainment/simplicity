/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.scenegraph;

/**
 * <p>
 * Traverses a tree type graph of {@link com.se.simplicity.scenegraph.Node Node}s. The order in which the {@link com.se.simplicity.scenegraph.Node
 * Node}s are traversed is specific to each implementation.
 * </p>
 * 
 * @author Gary Buyn
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
     * @return True if a {@link com.se.simplicity.scenegraph.Node Node} will be retrieved by the next call to <code>getNextNode()</code>, false
     * otherwise.
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
