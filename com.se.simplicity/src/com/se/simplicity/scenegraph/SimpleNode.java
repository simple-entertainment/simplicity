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
import java.util.ArrayList;
import java.util.List;

import com.se.simplicity.model.BoundingVolume;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A component of a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleNode implements Node, Serializable
{
    /**
     * The version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * A volume containing all the {@link com.se.simplicity.model.VertexGroup VertexGroup}s within the subgraph of which this <code>SimpleNode</code>
     * is the root.
     * </p>
     */
    private BoundingVolume bounds;

    /**
     * <p>
     * The <code>SimpleNode</code>s directly below this <code>SimpleNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     */
    private List<Node> children;

    /**
     * <p>
     * The collision mode. Determines if this <code>SimpleNode</code> can collide with other <code>SimpleNode</code>s in the
     * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} (determines if it should be included in collision detection).
     * </p>
     */
    private boolean collidable;

    /**
     * <p>
     * This <code>SimpleNode</code>'s unique identifier. This unique identifier is managed by the {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph}.
     * </p>
     */
    private int id;

    /**
     * <p>
     * The modification mode. Determines if this <code>SimpleNode</code> can be modified.
     * </p>
     */
    private boolean modifiable;

    /**
     * <p>
     * The <code>SimpleNode</code> directly above this <code>SimpleNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} .
     * </p>
     */
    private Node parent;

    /**
     * <p>
     * This <code>SimpleNode</code>'s relative position and orientation.
     * </p>
     */
    private TransformationMatrixf transformation;

    /**
     * <p>
     * The visibility mode. Determines if this <code>SimpleNode</code> is visible (determines if it should be rendered).
     * </p>
     */
    private boolean visible;

    /**
     * <p>
     * Creates an instance of <code>SimpleNode</code>.
     * </p>
     */
    public SimpleNode()
    {
        children = new ArrayList<Node>();
        collidable = true;
        id = 0;
        modifiable = true;
        parent = null;
        transformation = new SimpleTransformationMatrixf44();
        visible = true;
    }

    @Override
    public void addChild(final Node child)
    {
        children.add(child);
        child.setParent(this);
    }

    @Override
    public BoundingVolume getBounds()
    {
        return (bounds);
    }

    @Override
    public List<Node> getChildren()
    {
        return (children);
    }

    @Override
    public int getID()
    {
        return (id);
    }

    @Override
    public Node getParent()
    {
        return (parent);
    }

    @Override
    public TransformationMatrixf getTransformation()
    {
        return (transformation);
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
        return (collidable);
    }

    @Override
    public boolean isModifiable()
    {
        return (modifiable);
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
        return (visible);
    }

    @Override
    public void removeChild(final Node child)
    {
        children.remove(child);
        child.setParent(null);
    }

    @Override
    public void setBounds(final BoundingVolume newBounds)
    {
        bounds = newBounds;
    }

    @Override
    public void setCollidable(final boolean newCollidable)
    {
        collidable = newCollidable;
    }

    @Override
    public void setID(final int newId)
    {
        id = newId;
    }

    @Override
    public void setModifiable(final boolean newModifiable)
    {
        modifiable = newModifiable;
    }

    @Override
    public void setParent(final Node newParent)
    {
        parent = newParent;
    }

    @Override
    public void setTransformation(final TransformationMatrixf newTransformation)
    {
        transformation = newTransformation;
    }

    @Override
    public void setVisible(final boolean newVisible)
    {
        visible = newVisible;
    }
}
