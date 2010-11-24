/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.scenegraph;

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
public class SimpleNode implements Node
{
    /**
     * The version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * A volume containing all the {@link com.se.simplicity.model.Model Model}s within the subgraph of which this <code>SimpleNode</code>
     * is the root.
     * </p>
     */
    private BoundingVolume fBounds;

    /**
     * <p>
     * The <code>SimpleNode</code>s directly below this <code>SimpleNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     */
    private List<Node> fChildren;

    /**
     * <p>
     * The collision mode. Determines if this <code>SimpleNode</code> can collide with other <code>SimpleNode</code>s in the
     * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} (determines if it should be included in collision detection).
     * </p>
     */
    private boolean fCollidable;

    /**
     * <p>
     * This <code>SimpleNode</code>'s unique identifier. This unique identifier is managed by the {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph}.
     * </p>
     */
    private int fId;

    /**
     * <p>
     * The modification mode. Determines if this <code>SimpleNode</code> can be modified.
     * </p>
     */
    private boolean fModifiable;

    /**
     * <p>
     * The <code>SimpleNode</code> directly above this <code>SimpleNode</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} .
     * </p>
     */
    private Node fParent;

    /**
     * <p>
     * This <code>SimpleNode</code>'s relative position and orientation.
     * </p>
     */
    private TransformationMatrixf fTransformation;

    /**
     * <p>
     * The visibility mode. Determines if this <code>SimpleNode</code> is visible (determines if it should be rendered).
     * </p>
     */
    private boolean fVisible;

    /**
     * <p>
     * Creates an instance of <code>SimpleNode</code>.
     * </p>
     */
    public SimpleNode()
    {
        fBounds = null;
        fChildren = new ArrayList<Node>();
        fCollidable = true;
        fId = 0;
        fModifiable = true;
        fParent = null;
        fTransformation = new SimpleTransformationMatrixf44();
        fVisible = true;
    }

    @Override
    public void addChild(final Node child)
    {
        fChildren.add(child);
        child.setParent(this);
    }

    @Override
    public TransformationMatrixf getAbsoluteTransformation()
    {
        TransformationMatrixf transformation = new SimpleTransformationMatrixf44();
        Node currentNode = this;

        while (currentNode != null)
        {
            transformation.multiplyLeft(currentNode.getTransformation());

            currentNode = currentNode.getParent();
        }

        return (transformation);
    }

    @Override
    public BoundingVolume getBounds()
    {
        return (fBounds);
    }

    @Override
    public List<Node> getChildren()
    {
        return (fChildren);
    }

    @Override
    public int getID()
    {
        return (fId);
    }

    @Override
    public Node getParent()
    {
        return (fParent);
    }

    @Override
    public TransformationMatrixf getTransformation()
    {
        return (fTransformation);
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
        return (fCollidable);
    }

    @Override
    public boolean isModifiable()
    {
        return (fModifiable);
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
        return (fVisible);
    }

    @Override
    public void removeChild(final Node child)
    {
        fChildren.remove(child);
        child.setParent(null);
    }

    @Override
    public void setBounds(final BoundingVolume bounds)
    {
        fBounds = bounds;
    }

    @Override
    public void setCollidable(final boolean collidable)
    {
        fCollidable = collidable;
    }

    @Override
    public void setID(final int newId)
    {
        fId = newId;
    }

    @Override
    public void setModifiable(final boolean modifiable)
    {
        fModifiable = modifiable;
    }

    @Override
    public void setParent(final Node parent)
    {
        fParent = parent;
    }

    @Override
    public void setTransformation(final TransformationMatrixf transformation)
    {
        fTransformation = transformation;
    }

    @Override
    public void setVisible(final boolean visible)
    {
        fVisible = visible;
    }
}
