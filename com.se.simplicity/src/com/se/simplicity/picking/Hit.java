/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.picking;

import com.se.simplicity.model.Model;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * A hit made as a result of a pick.
 * </p>
 * 
 * @author Gary Buyn
 */
public class Hit
{
    /**
     * <p>
     * The maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the {@link com.se.simplicity.rendering.Camera
     * Camera}.
     * </p>
     */
    private int fMaximumDistance;

    /**
     * <p>
     * The minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the {@link com.se.simplicity.rendering.Camera
     * Camera}.
     * </p>
     */
    private int fMinimumDistance;

    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
     * </p>
     */
    private Node fNode;

    /**
     * <p>
     * The primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive stored in this
     * value is undefined.
     * </p>
     */
    private Model fPrimitive;

    /**
     * <p>
     * Creates an instance of <code>Hit</code>.
     * </p>
     */
    public Hit()
    {
        fMaximumDistance = 0;
        fMinimumDistance = 0;
        fNode = null;
        fPrimitive = null;
    }

    /**
     * <p>
     * Retrieves the maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
     * {@link com.se.simplicity.rendering.Camera Camera}.
     * </p>
     * 
     * @return The maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
     * {@link com.se.simplicity.rendering.Camera Camera}.
     */
    public int getMaximumDistance()
    {
        return (fMaximumDistance);
    }

    /**
     * <p>
     * Retrieves the minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
     * {@link com.se.simplicity.rendering.Camera Camera}.
     * </p>
     * 
     * @return The minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
     * {@link com.se.simplicity.rendering.Camera Camera}.
     */
    public int getMinimumDistance()
    {
        return (fMinimumDistance);
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
     * </p>
     * 
     * @return The {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
     */
    public Node getNode()
    {
        return (fNode);
    }

    /**
     * <p>
     * Retrieves the primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive stored in
     * this value is undefined.
     * </p>
     * 
     * @return The primitive that intersected the pick.
     */
    public Model getPrimitive()
    {
        return (fPrimitive);
    }

    /**
     * <p>
     * Sets the maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
     * {@link com.se.simplicity.rendering.Camera Camera}.
     * </p>
     * 
     * @param maximumDistance The maximum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
     * {@link com.se.simplicity.rendering.Camera Camera}.
     */
    public void setMaximumDistance(final int maximumDistance)
    {
        fMaximumDistance = maximumDistance;
    }

    /**
     * <p>
     * Sets the minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
     * {@link com.se.simplicity.rendering.Camera Camera}.
     * </p>
     * 
     * @param minimumDistance The minimum distance of the primitive(s) that intersected the pick on the Z axis in relation to the
     * {@link com.se.simplicity.rendering.Camera Camera}.
     */
    public void setMinimumDistance(final int minimumDistance)
    {
        fMinimumDistance = minimumDistance;
    }

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
     * </p>
     * 
     * @param node The {@link com.se.simplicity.scenegraph.Node Node} that most directly contains the primitive(s) that intersected the pick.
     */
    public void setNode(final Node node)
    {
        fNode = node;
    }

    /**
     * <p>
     * Sets the primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive stored in this
     * value is undefined.
     * </p>
     * 
     * @param primitive The primitive that intersected the pick.
     */
    public void setPrimitive(final Model primitive)
    {
        fPrimitive = primitive;
    }
}
