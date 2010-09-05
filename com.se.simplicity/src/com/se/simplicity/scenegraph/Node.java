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
import java.util.List;

import com.se.simplicity.model.BoundingVolume;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A component of a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Node extends Serializable
{
    /**
     * <p>
     * Adds a child to this <code>Node</code>.
     * </p>
     * 
     * @param child The <code>Node</code> to add to this <code>Node</code>'s children.
     */
    void addChild(Node child);

    /**
     * <p>
     * Retrieves this <code>Node</code>'s absolute position and orientation.
     * </p>
     * 
     * @return This <code>Node</code>'s absolute position and orientation.
     */
    TransformationMatrixf getAbsoluteTransformation();

    /**
     * <p>
     * Retrieves a volume containing all the {@link com.se.simplicity.model.Model Model}s within the subgraph of which this <code>Node</code> is the
     * root.
     * </p>
     * 
     * @return A volume containing all the {@link com.se.simplicity.model.Model Model}s within the subgraph of which this <code>Node</code> is the
     * root.
     */
    BoundingVolume getBounds();

    /**
     * <p>
     * Retrieves the <code>Node</code>s directly below this <code>Node</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     * 
     * @return The <code>Node</code>s directly below this <code>Node</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     */
    List<Node> getChildren();

    /**
     * <p>
     * Retrieves this <code>Node</code>'s unique identifier.
     * </p>
     * 
     * @return This <code>Node</code>'s unique identifier.
     */
    int getID();

    /**
     * <p>
     * Retrieves the <code>Node</code> directly above this <code>Node</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     * 
     * @return The <code>Node</code> directly above this <code>Node</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     */
    Node getParent();

    /**
     * <p>
     * Retrieves this <code>Node</code>'s relative position and orientation.
     * </p>
     * 
     * @return This <code>Node</code>'s relative position and orientation.
     */
    TransformationMatrixf getTransformation();

    /**
     * <p>
     * Determines if children exist for this <code>Node</code>.
     * </p>
     * 
     * @return True if children exist for this <code>Node</code>, false otherwise.
     */
    boolean hasChildren();

    /**
     * <p>
     * Determines if the given <code>Node</code> is an ancestor of this <code>Node</code>.
     * </p>
     * 
     * @param ancestor The <code>Node</code> to check.
     * @return True if the given <code>Node</code> is an ancestor of this <code>Node</code>, false otherwise.
     */
    boolean isAncestor(Node ancestor);

    /**
     * <p>
     * Determines if this <code>Node</code> can collide with other <code>Node</code>s in the {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph} (determines if it should be included in collision detection).
     * </p>
     * 
     * @return True if this <code>Node</code> can collide with other <code>Node</code>s in the {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph}, false otherwise.
     */
    boolean isCollidable();

    /**
     * <p>
     * Determines if this <code>Node</code> can be modified.
     * </p>
     * 
     * @return True if this <code>Node</code> can be modified, false otherwise.
     */
    boolean isModifiable();

    /**
     * <p>
     * Determines if the given <code>Node</code> is a successor of this <code>Node</code>.
     * </p>
     * 
     * @param successor The <code>Node</code> to check.
     * @return True if the given <code>Node</code> is a successor of this <code>Node</code>, false otherwise.
     */
    boolean isSuccessor(Node successor);

    /**
     * <p>
     * Determines if this <code>Node</code> is visible (determines if it should be rendered).
     * </p>
     * 
     * @return True if this <code>Node</code> is visible, false otherwise.
     */
    boolean isVisible();

    /**
     * <p>
     * Removes a child from this <code>Node</code>.
     * </p>
     * 
     * @param child The child to be removed.
     */
    void removeChild(final Node child);

    /**
     * <p>
     * Retrieves a volume containing all the {@link com.se.simplicity.model.Model Model}s within the subgraph of which this <code>Node</code> is the
     * root.
     * </p>
     * 
     * @param bounds A volume containing all the {@link com.se.simplicity.model.Model Model}s within the subgraph of which this <code>Node</code> is
     * the root.
     */
    void setBounds(final BoundingVolume bounds);

    /**
     * <p>
     * Sets the collision mode.
     * </p>
     * 
     * @param collidable Determines if this <code>Node</code> can collide with other <code>Node</code>s in the
     * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} (determines if it should be included in collision detection).
     */
    void setCollidable(boolean collidable);

    /**
     * <p>
     * Sets this <code>Node</code>'s unique identifier. This identifier should be managed by the {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph}.
     * </p>
     * 
     * @param id This <code>Node</code>'s unique identifier.
     */
    void setID(int id);

    /**
     * <p>
     * Sets the modification mode.
     * </p>
     * 
     * @param modifiable Determines if this <code>Node</code> can be modified.
     */
    void setModifiable(boolean modifiable);

    /**
     * <p>
     * Sets the <code>Node</code> directly above this <code>Node</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     * 
     * @param parent The <code>Node</code> directly above this <code>Node</code> in a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     */
    void setParent(Node parent);

    /**
     * <p>
     * Sets this <code>Node</code>'s relative position and orientation.
     * </p>
     * 
     * @param transformation This <code>Node</code>'s relative position and orientation.
     */
    void setTransformation(TransformationMatrixf transformation);

    /**
     * <p>
     * The visibility mode.
     * </p>
     * 
     * @param visible Determines if this <code>Node</code> is visible (determines if it should be rendered).
     */
    void setVisible(boolean visible);
}
