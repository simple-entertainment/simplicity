/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.scenegraph;

import java.io.Serializable;
import java.util.Hashtable;

/**
 * <p>
 * This implementation uses only simple scene graph techniques and properties.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleSceneGraph implements SceneGraph, Serializable
{
    /**
     * The version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * The unique identifier that was assigned to the last {@link com.se.simplicity.scenegraph.Node Node} added to the <code>SimpleSceneGraph</code>.
     */
    private int lastNodeID;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.Node Node}s within this <code>SceneGraph</code>.
     * </p>
     */
    private Hashtable<Integer, Node> nodes;

    /**
     * <p>
     * The root {@link com.se.simplicity.scenegraph.Node Node} of this <code>SceneGraph</code>.
     * </p>
     */
    private Node root;

    /**
     * <p>
     * Creates an instance of <code>SimpleSceneGraph</code>.
     * </p>
     */
    public SimpleSceneGraph()
    {
        lastNodeID = 0;
        nodes = new Hashtable<Integer, Node>();
        root = new SimpleNode();
        root.setID(getNextNodeID());
        nodes.put(root.getID(), root);
    }

    @Override
    public void addSubgraph(final Node subgraphRoot)
    {
        addSubgraph(subgraphRoot, root);
    }

    @Override
    public void addSubgraph(final Node subgraphRoot, final Node parent)
    {
        SimpleTraversal traversal = new SimpleTraversal(subgraphRoot);

        while (traversal.hasMoreNodes())
        {
            Node node = traversal.getNextNode();

            node.setID(getNextNodeID());
            nodes.put(node.getID(), node);
        }

        parent.addChild(subgraphRoot);
    }

    /**
     * <p>
     * Retrieves a unique identifier to assign to the next {@link com.se.simplicity.scenegraph.Node Node} added to the <code>SimpleSceneGraph</code>.
     * </p>
     * 
     * @return A unique identifier to assign to the next {@link com.se.simplicity.scenegraph.Node Node} added to the <code>SimpleSceneGraph</code>.
     */
    protected int getNextNodeID()
    {
        return (lastNodeID++);
    }

    @Override
    public Node getNode(final int id)
    {
        return (nodes.get(id));
    }

    @Override
    public Node getRoot()
    {
        return (root);
    }

    @Override
    public void removeSubgraph(final Node subgraphRoot)
    {
        SimpleTraversal traversal = new SimpleTraversal(subgraphRoot);

        while (traversal.hasMoreNodes())
        {
            nodes.remove(traversal.getNextNode());
        }

        subgraphRoot.getParent().removeChild(subgraphRoot);
    }
}
