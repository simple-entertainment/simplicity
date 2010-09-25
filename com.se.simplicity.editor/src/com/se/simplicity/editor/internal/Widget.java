package com.se.simplicity.editor.internal;

import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * A widget that exists in the virtual universe.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Widget
{
    /**
     * <p>
     * Determines if this <code>Widget</code> should always be rendered facing the {@link com.se.simplicity.rendering.Camera Camera}.
     * </p>
     * 
     * @return True if this <code>Widget</code> should always be rendered facing the <code>Camera</code>, false otherwise.
     */
    boolean alwaysFacesCamera();

    /**
     * <p>
     * Determines whether this <code>Widget</code> should only be rendered at the selected scene component / primitive.
     * </p>
     * 
     * @return True if this <code>Widget</code> should only be rendered at the selected scene component / primitive, false otherwise.
     */
    boolean atSelectionOnly();

    /**
     * <p>
     * Executes this <code>Widget</code> given a movement in viewport coordinates.
     * </p>
     * 
     * @param x The distance of the movement on the x axis in viewport coordinates.
     * @param y The distance of the movement on the y axis in viewport coordinates.
     */
    void executeMove(int x, int y);

    /**
     * <p>
     * Retrieves the root {@link com.se.simplicity.scenegraph.Node Node} of this <code>Widget</code>.
     * </p>
     * 
     * @return The root {@link com.se.simplicity.scenegraph.Node Node} of this <code>Widget</code>.
     */
    Node getRootNode();

    /**
     * <p>
     * Retrieves the currently selected {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} of this <code>Widget</code>.
     * </p>
     * 
     * @return The currently selected {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} of this <code>Widget</code>.
     */
    ModelNode getSelectedWidgetNode();

    /**
     * <p>
     * Retrieves the selected scene component and primitive.
     * </p>
     * 
     * @return The selected scene component and primitive.
     */
    SceneSelection getSelection();

    /**
     * <p>
     * Ensures that this <code>Widget</code> is correctly scaled, positioned and orientated etc.
     * </p>
     * 
     * @param camera The {@link com.se.simplicity.rendering.Camera Camera} through which this <code>Widget</code> is being viewed.
     * @param isSelection Determines if the <code>Widget</code> is being rendered for the selected scene component / primitive.
     */
    void init(Camera camera, boolean isSelection);

    /**
     * <p>
     * Determines if the {@link com.se.simplicity.picking.Picker Picker} used to pick this <code>Widget</code> should create the hit from this
     * <code>Widget</code>'s select buffer contents or the {@link com.se.simplicity.scene.Scene}s select buffer contents.
     * </p>
     * 
     * @return True if the <code>Picker</code> used to pick this <code>Widget</code> should create the hit from this <code>Widget</code>'s select
     * buffer contents, false otherwise.
     */
    boolean isHittable();

    /**
     * <p>
     * Determines whether this <code>Widget</code> should bee rendered with an outline.
     * </p>
     * 
     * @return True if this <code>Widget</code> should bee rendered with an outline, false otherwise.
     */
    boolean isOutlined();

    /**
     * <p>
     * Sets the currently selected {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} of this <code>Widget</code>.
     * </p>
     * 
     * @param selectedWidgetNode The currently selected {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} of this <code>Widget</code>.
     */
    void setSelectedWidgetNode(ModelNode selectedWidgetNode);

    /**
     * <p>
     * Sets the selected scene component and primitive.
     * </p>
     * 
     * @param selection The selected scene component and primitive.
     */
    void setSelection(SceneSelection selection);
}
