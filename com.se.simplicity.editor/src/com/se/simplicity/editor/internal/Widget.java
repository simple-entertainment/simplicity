package com.se.simplicity.editor.internal;

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
     * Sets the {@link com.se.simplicity.rendering.Camera Camera} the <code>Widget</code> will be viewing through (used to scale the
     * <code>Widget</code> correctly).
     * </p>
     * 
     * @param camera The {@link com.se.simplicity.rendering.Camera Camera} the <code>Widget</code> will be viewing through.
     */
    void setCamera(Camera camera);

    /**
     * <p>
     * Sets the currently selected scene component.
     * </p>
     * 
     * @param selectedSceneComponent The currently selected scene component.
     */
    void setSelectedSceneComponent(Object selectedSceneComponent);

    /**
     * <p>
     * Sets the currently selected {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} of this <code>Widget</code>.
     * </p>
     * 
     * @param selectedWidgetNode The currently selected {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} of this <code>Widget</code>.
     */
    void setSelectedWidgetNode(ModelNode selectedWidgetNode);
}
