/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.metadata.scenegraph;

import java.util.Enumeration;
import java.util.Hashtable;

import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.util.metadata.MetaData;

/**
 * <p>
 * Wraps another <code>SceneGraph</code> implementation and provides the ability to add meta data attributes.
 * </p>
 * 
 * <p>
 * This <code>MetaDataSceneGraph</code> will behave exactly as if you were acting on the <code>SceneGraph</code> it is wrapping so the caller need not
 * even know that they are calling the <code>MetaDataSceneGraph</code>.
 * </p>
 * 
 * <p>
 * NOTE: All <code>Node</code>s within a <code>MetaDataSceneGraph</code> must be <code>MetaDataNode</code>s (except for the internally managed nodes
 * e.g. the root node). Using the {@link com.se.simplicity.util.metadata.scenegraph.MetaDataSceneGraph#addSubgraph addSubgraph(Node)} and (TODO add other
 * method) methods, it will ensure that all the <code>Node</code>s added are wrapped with <code>MetaDataNode</code>s if necessary.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MetaDataSceneGraph implements SceneGraph, MetaData
{
    /**
     * <p>
     * The meta data attributes.
     * </p>
     */
    private Hashtable<String, Object> attributes;

    /**
     * <p>
     * The <code>SceneGraph</code> that is wrapped by this <code>MetaDataSceneGraph</code>.
     * </p>
     */
    private SceneGraph sceneGraph;

    /**
     * <p>
     * Creates an instance of <code>MetaDataSceneGraph</code>.
     * </p>
     * 
     * @param newSceneGraph The <code>SceneGraph</code> that is wrapped by this <code>MetaDataCamera</code>.
     */
    public MetaDataSceneGraph(final SceneGraph newSceneGraph)
    {
        sceneGraph = newSceneGraph;

        attributes = new Hashtable<String, Object>();
    }

    @Override
    public void addSubgraph(final Node subgraphRoot)
    {
        sceneGraph.addSubgraph(subgraphRoot);

        MetaDataSceneGraph.wrapNodes(subgraphRoot);
    }

    @Override
    public void addSubgraph(final Node subgraphRoot, final Node parent)
    {
        sceneGraph.addSubgraph(subgraphRoot, parent);

        MetaDataSceneGraph.wrapNodes(subgraphRoot);
    }

    @Override
    public Object getAttribute(final String name)
    {
        return (attributes.get(name));
    }

    @Override
    public Enumeration<String> getAttributeNames()
    {
        return (attributes.keys());
    }

    @Override
    public Enumeration<Object> getAttributes()
    {
        return (attributes.elements());
    }

    @Override
    public Node getNode(final int id)
    {
        return (sceneGraph.getNode(id));
    }

    @Override
    public Node getRoot()
    {
        return (sceneGraph.getRoot());
    }

    /**
     * <p>
     * Retrieves the <code>SceneGraph</code> that is wrapped by this <code>MetaDataSceneGraph</code>.
     * </p>
     * 
     * @return The <code>SceneGraph</code> that is wrapped by this <code>MetaDataSceneGraph</code>.
     */
    public SceneGraph getWrappedSceneGraph()
    {
        return (sceneGraph);
    }

    @Override
    public void removeSubgraph(final Node subgraphRoot)
    {
        sceneGraph.removeSubgraph(subgraphRoot);
    }

    @Override
    public void setAttribute(final String name, final Object value)
    {
        attributes.put(name, value);
    }

    /**
     * <p>
     * Wraps any <code>Node</code>s in the subgraph with the given root <code>Node</code> that are not already wrapped with <code>MetaDataNode</code>
     * s. Also moves the parent/child relationship from the wrapped <code>Node</code>s to the <code>MetaDataNode</code>s.
     * </p>
     * 
     * @param subgraphRoot The root <code>Node</code> of the subgraph to be wrapped.
     * 
     * @return The root <code>MetaDataNode</code> of the wrapped subgraph.
     */
    public static MetaDataNode wrapNodes(final Node subgraphRoot)
    {
        MetaDataNode currentNode;
        if (!(subgraphRoot instanceof MetaDataNode))
        {
            Node parentNode = subgraphRoot.getParent();
            currentNode = new MetaDataNode(subgraphRoot);

            if (parentNode != null)
            {
                parentNode.removeChild(subgraphRoot);
                parentNode.addChild(currentNode);
            }

            for (Node childNode : subgraphRoot.getChildren())
            {
                currentNode.addChild((Node) childNode);
            }
            subgraphRoot.getChildren().clear();

            currentNode.addDefaultNameAttribute();
        }
        else
        {
            currentNode = (MetaDataNode) subgraphRoot;
        }

        // Static array retrieved to guard against concurrent modification.
        Object[] children = currentNode.getChildren().toArray();
        for (Object childNode : children)
        {
            wrapNodes((Node) childNode);
        }

        return (currentNode);
    }
}
