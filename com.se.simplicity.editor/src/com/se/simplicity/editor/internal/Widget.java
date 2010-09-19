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
     * Retrieves the selected scene component and primitive.
     * </p>
     * 
     * @return The selected scene component and primitive.
     */
    SceneSelection getSelection();

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
     * Sets the selected scene component and primitive.
     * </p>
     * 
     * @param selection The selected scene component and primitive.
     */
    void setSelection(SceneSelection selection);

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
     * Ensures that this <code>Widget</code> is correctly scaled, positioned and orientated. Can also effect the functionality of this
     * <code>Widget</code>.
     * </p>
     * 
     * @param camera The camera through which this <code>Widget</code> is being viewed.
     */
    void updateView(Camera camera);
}
