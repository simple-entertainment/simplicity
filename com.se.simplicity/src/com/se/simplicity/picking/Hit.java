package com.se.simplicity.picking;

import com.se.simplicity.model.VertexGroup;
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
     * The primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive sstored in this
     * value is undefined.
     * </p>
     */
    private VertexGroup fPrimitive;

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
     * Retrieves the primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive sstored
     * in this value is undefined.
     * </p>
     * 
     * <p>
     * The primitive is a subset {@link com.se.simplicity.model.VertexGroup VertexGroup}, meaning that any changes can be committed to the overall
     * <code>VertexGroup</code> by calling {@link com.se.simplicity.model.VertexGroup#mergeWithParent() mergeWithParent()} on the
     * <code>VertexGroup</code>.
     * </p>
     * 
     * @return The primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive sstored in
     * this value is undefined.
     */
    public VertexGroup getPrimitive()
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
     * Sets the primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive sstored in
     * this value is undefined.
     * </p>
     * 
     * <p>
     * NOTE: The {@link com.se.simplicity.model.VertexGroup VertexGroup} must be a subset, meaning that any changes can be committed to the overall
     * <code>VertexGroup</code> by calling {@link com.se.simplicity.model.VertexGroup#mergeWithParent() mergeWithParent()} on the
     * <code>VertexGroup</code>.
     * </p>
     * 
     * @param primitive The primitive that intersected the pick. In the case that multiple primitives were drawn with the same name, this primitive
     * sstored in this value is undefined.
     */
    public void setPrimitive(final VertexGroup primitive)
    {
        fPrimitive = primitive;
    }
}
