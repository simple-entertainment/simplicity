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
import java.util.List;

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
    private int fLastNodeID;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.Node Node}s within this <code>SimpleSceneGraph</code>.
     * </p>
     */
    private Hashtable<Integer, Node> fNodes;

    /**
     * <p>
     * The root {@link com.se.simplicity.scenegraph.Node Node} of this <code>SimpleSceneGraph</code>.
     * </p>
     */
    private Node fRoot;

    /**
     * <p>
     * Creates an instance of <code>SimpleSceneGraph</code>.
     * </p>
     */
    public SimpleSceneGraph()
    {
        fLastNodeID = 0;
        fNodes = new Hashtable<Integer, Node>();
        fRoot = new SimpleNode();
        fRoot.setID(getNextNodeID());
        fNodes.put(fRoot.getID(), fRoot);
    }

    @Override
    public void addSubgraph(final Node subgraphRoot)
    {
        addSubgraph(subgraphRoot, fRoot);
    }

    @Override
    public void addSubgraph(final Node subgraphRoot, final Node parent)
    {
        SimpleTraversal traversal = new SimpleTraversal(subgraphRoot);

        while (traversal.hasMoreNodes())
        {
            Node node = traversal.getNextNode();

            node.setID(getNextNodeID());
            fNodes.put(node.getID(), node);
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
    private int getNextNodeID()
    {
        return (fLastNodeID++);
    }

    @Override
    public Node getNode(final int id)
    {
        return (fNodes.get(id));
    }

    @Override
    public Node getRoot()
    {
        return (fRoot);
    }

    @Override
    public List<Node> getSubgraphRoots()
    {
        return fRoot.getChildren();
    }

    @Override
    public void removeSubgraph(final Node subgraphRoot)
    {
        SimpleTraversal traversal = new SimpleTraversal(subgraphRoot);

        while (traversal.hasMoreNodes())
        {
            fNodes.remove(traversal.getNextNode());
        }

        subgraphRoot.getParent().removeChild(subgraphRoot);
    }

    @Override
    public void resetIDs()
    {
        fLastNodeID = 0;
        fNodes.clear();

        SimpleTraversal traversal = new SimpleTraversal(fRoot);

        while (traversal.hasMoreNodes())
        {
            Node node = traversal.getNextNode();

            node.setID(getNextNodeID());
            fNodes.put(node.getID(), node);
        }
    }
}
