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
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleTraversal;
import com.se.simplicity.scenegraph.Traversal;
import com.se.simplicity.util.metadata.MetaData;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * Wraps another <code>Node</code> implementation and provides the ability to add meta data attributes.
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
public class MetaDataNode implements Node, MetaData
{
    /**
     * The version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * Retrieves the default name for the given {@link com.se.simplicity.scenegraph.Node Node}.
     * </p>
     * 
     * @param node The <code>Node</code> to retrieve the default name for.
     * 
     * @return The default name for the given {@link com.se.simplicity.scenegraph.Node Node}.
     */
    public static String getDefaultName(final Node node)
    {
        String className = null;
        if (node instanceof MetaDataNode)
        {
            className = ((MetaDataNode) node).getWrappedNode().getClass().getSimpleName();
        }
        else
        {
            className = node.getClass().getSimpleName();
        }

        return (className + node.getID());
    }

    /**
     * <p>
     * The meta data attributes.
     * </p>
     */
    private Hashtable<String, Object> fAttributes;

    /**
     * <p>
     * The <code>MetaDataNode</code>s directly below this <code>MetaDataNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     */
    private List<Node> fChildren;

    /**
     * <p>
     * The <code>Node</code> that is wrapped by this <code>MetaDataNode</code>.
     * </p>
     */
    private Node fNode;

    /**
     * <p>
     * The <code>MetaDataNode</code> directly above this <code>MetaDataNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} .
     * </p>
     */
    private Node fParent;

    /**
     * <p>
     * Creates an instance of <code>MetaDataNode</code>.
     * </p>
     * 
     * @param node The <code>Node</code> that is wrapped by this <code>MetaDataNode</code>.
     */
    public MetaDataNode(final Node node)
    {
        fNode = node;

        fAttributes = new Hashtable<String, Object>();
        fChildren = new ArrayList<Node>();
        fParent = null;
    }

    @Override
    public void addChild(final Node child)
    {
        fChildren.add(child);
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
        setAttribute("name", MetaDataNode.getDefaultName(this));
    }

    @Override
    public TransformationMatrixf getAbsoluteTransformation()
    {
        return (fNode.getAbsoluteTransformation());
    }

    @Override
    public Object getAttribute(final String name)
    {
        return (fAttributes.get(name));
    }

    @Override
    public Enumeration<String> getAttributeNames()
    {
        return (fAttributes.keys());
    }

    @Override
    public Enumeration<Object> getAttributes()
    {
        return (fAttributes.elements());
    }

    @Override
    public BoundingVolume getBounds()
    {
        return (fNode.getBounds());
    }

    @Override
    public List<Node> getChildren()
    {
        return (fChildren);
    }

    @Override
    public int getID()
    {
        return (fNode.getID());
    }

    @Override
    public Node getParent()
    {
        return (fParent);
    }

    @Override
    public TransformationMatrixf getTransformation()
    {
        return (fNode.getTransformation());
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
        return (fNode);
    }

    @Override
    public boolean hasChildren()
    {
        if (fChildren.size() == 0)
        {
            return (false);
        }

        return (true);
    }

    @Override
    public boolean isAncestor(final Node ancestor)
    {
        Node currentParent = fParent;

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
        return (fNode.isCollidable());
    }

    @Override
    public boolean isModifiable()
    {
        return (fNode.isModifiable());
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
        return (fNode.isVisible());
    }

    @Override
    public void removeChild(final Node child)
    {
        fChildren.remove(child);
        child.setParent(null);
    }

    @Override
    public void setAttribute(final String name, final Object value)
    {
        fAttributes.put(name, value);
    }

    @Override
    public void setBounds(final BoundingVolume bounds)
    {
        fNode.setBounds(bounds);
    }

    @Override
    public void setCollidable(final boolean collidable)
    {
        fNode.setCollidable(collidable);
    }

    @Override
    public void setID(final int id)
    {
        fNode.setID(id);
    }

    @Override
    public void setModifiable(final boolean modifiable)
    {
        fNode.setModifiable(modifiable);
    }

    @Override
    public void setParent(final Node parent)
    {
        fParent = parent;
    }

    @Override
    public void setTransformation(final TransformationMatrixf transformation)
    {
        fNode.setTransformation(transformation);
    }

    @Override
    public void setVisible(final boolean visible)
    {
        fNode.setVisible(visible);
    }
}
