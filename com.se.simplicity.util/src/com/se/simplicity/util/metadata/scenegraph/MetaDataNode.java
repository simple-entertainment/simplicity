/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.metadata.scenegraph;

import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.List;

import com.se.simplicity.model.BoundingVolume;
import com.se.simplicity.model.Model;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.scenegraph.Traversal;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.util.metadata.MetaData;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * Wraps another <code>Node</code> implementation (including <code>ModelNode</code> support) and provides the ability to add meta data attributes.
 * </p>
 * 
 * <p>
 * This <code>MetaDataNode</code> will behave exactly as if you were acting on the <code>Node</code> it is wrapping except for the following methods
 * which are copied from <code>SimpleNode</code>: {@link com.se.simplicity.util.metadata.scenegraph.MetaDataNode#addChild addChild()},
 * {@link com.se.simplicity.util.metadata.scenegraph.MetaDataNode#hasChildren hasChildren()},
 * {@link com.se.simplicity.util.metadata.scenegraph.MetaDataNode#isAncestor isAncestor()},
 * {@link com.se.simplicity.util.metadata.scenegraph.MetaDataNode#isSuccessor isSuccessor()},
 * {@link com.se.simplicity.util.metadata.scenegraph.MetaDataNode#getParent getParent()},
 * {@link com.se.simplicity.util.metadata.scenegraph.MetaDataNode#removeChild removeChild()} and
 * {@link com.se.simplicity.util.metadata.scenegraph.MetaDataNode#setParent setParent()}.
 * </p>
 * 
 * <p>
 * As a result of these methods being copied, any hierarchies made with <code>MetaDataNode</code>s will relate the <code>MetaDataNode</code>s as
 * parent and child ONLY. The wrapped <code>Node</code>s will NOT be related as parent and child.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MetaDataNode implements ModelNode, MetaData
{
    /**
     * The version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * The meta data attributes.
     * </p>
     */
    private Hashtable<String, Object> attributes;

    /**
     * <p>
     * The <code>MetaDataNode</code>s directly below this <code>MetaDataNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     */
    private List<Node> children;

    /**
     * <p>
     * The <code>Node</code> that is wrapped by this <code>MetaDataNode</code>.
     * </p>
     */
    private Node node;

    /**
     * <p>
     * The <code>MetaDataNode</code> directly above this <code>MetaDataNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} .
     * </p>
     */
    private Node parent;

    /**
     * <p>
     * Creates an instance of <code>MetaDataNode</code>.
     * </p>
     * 
     * @param newNode The <code>Node</code> that is wrapped by this <code>MetaDataCamera</code>.
     */
    public MetaDataNode(final Node newNode)
    {
        node = newNode;

        attributes = new Hashtable<String, Object>();
        children = new ArrayList<Node>();
        parent = null;
    }

    @Override
    public void addChild(final Node child)
    {
        children.add(child);
        child.setParent(this);
    }

    /**
     * <p>
     * Adds an attribute called 'name' to this <code>MetaDataNode</code> with a basic name chosen depending on the class of its wrapped
     * <code>Node</code>.
     * </p>
     */
    public void addDefaultNameAttribute()
    {
        String name = null;

        if (node instanceof ModelNode)
        {
            name = "Vertex Group (" + getID() + ")";
        }
        else
        {
            name = "Node (" + getID() + ")";
        }

        setAttribute("name", name);
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
    public BoundingVolume getBounds()
    {
        return (node.getBounds());
    }

    @Override
    public List<Node> getChildren()
    {
        return (children);
    }

    @Override
    public int getID()
    {
        return (node.getID());
    }

    @Override
    public Model getModel()
    {
        if (node instanceof ModelNode)
        {
            return (((ModelNode) node).getModel());
        }
        else
        {
            return (null);
        }
    }

    @Override
    public Node getParent()
    {
        return (parent);
    }

    @Override
    public TransformationMatrixf getTransformation()
    {
        return (node.getTransformation());
    }

    @Override
    public VertexGroup getVertexGroup()
    {
        if (node instanceof ModelNode)
        {
            return (((ModelNode) node).getVertexGroup());
        }
        else
        {
            return (null);
        }
    }

    /**
     * <p>
     * Retrieves the <code>Node</code> that is wrapped by this <code>MetaDataNode</code>.
     * </p>
     * 
     * @return The <code>Node</code> that is wrapped by this <code>MetaDataNode</code>.
     */
    public Node getWrappedNode()
    {
        return (node);
    }

    @Override
    public boolean hasChildren()
    {
        if (children.size() == 0)
        {
            return (false);
        }

        return (true);
    }

    @Override
    public boolean isAncestor(final Node ancestor)
    {
        Node currentParent = parent;

        while (currentParent != null)
        {
            if (currentParent == ancestor)
            {
                return (true);
            }

            currentParent = currentParent.getParent();
        }

        return (false);
    }

    @Override
    public boolean isCollidable()
    {
        return (node.isCollidable());
    }

    @Override
    public boolean isModifiable()
    {
        return (node.isModifiable());
    }

    @Override
    public boolean isSuccessor(final Node successor)
    {
        Traversal traversal = new SimpleTraversal(this);

        while (traversal.hasMoreNodes())
        {
            if (traversal.getNextNode() == successor && successor != this)
            {
                return (true);
            }
        }

        return (false);
    }

    @Override
    public boolean isVisible()
    {
        return (node.isVisible());
    }

    @Override
    public void removeChild(final Node child)
    {
        children.remove(child);
        child.setParent(null);
    }

    @Override
    public void setAttribute(final String name, final Object value)
    {
        attributes.put(name, value);
    }

    @Override
    public void setBounds(final BoundingVolume newBounds)
    {
        node.setBounds(newBounds);
    }

    @Override
    public void setCollidable(final boolean newCollidable)
    {
        node.setCollidable(newCollidable);
    }

    @Override
    public void setID(final int newId)
    {
        node.setID(newId);
    }

    @Override
    public void setModel(final Model newModel)
    {
        if (node instanceof ModelNode)
        {
            ((ModelNode) node).setModel(newModel);
        }
    }

    @Override
    public void setModifiable(final boolean newModifiable)
    {
        node.setModifiable(newModifiable);
    }

    @Override
    public void setParent(final Node newParent)
    {
        parent = newParent;
    }

    @Override
    public void setTransformation(final TransformationMatrixf newTransformation)
    {
        node.setTransformation(newTransformation);
    }

    @Override
    public void setVertexGroup(final VertexGroup newVertexGroup)
    {
        if (node instanceof ModelNode)
        {
            ((ModelNode) node).setVertexGroup(newVertexGroup);
        }
    }

    @Override
    public void setVisible(final boolean newVisible)
    {
        node.setVisible(newVisible);
    }
}
