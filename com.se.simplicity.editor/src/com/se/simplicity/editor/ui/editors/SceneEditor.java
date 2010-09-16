/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import java.awt.Dimension;

import org.eclipse.jface.viewers.ISelectionProvider;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.ui.IEditorPart;

import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.WidgetManager;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.ProjectionMode;

/**
 * <p>
 * An editor capable of displaying a {@link com.se.simplicity.scene.Scene Scene} visually.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface SceneEditor extends IEditorPart, ISelectionProvider
{
    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.DrawingMode DrawingMode} used to render the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @return The <code>DrawingMode</code> used to render the <code>Scene</code>.
     */
    DrawingMode getDrawingMode();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.editor.internal.EditingMode EditingMode} used to manipulate the {@link com.se.simplicity.scene.Scene
     * Scene}.
     * </p>
     * 
     * @return The <code>EditingMode</code> used to manipulate the <code>Scene</code>.
     */
    EditingMode getEditingMode();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.ProjectionMode ProjectionMode} the {@link com.se.simplicity.scene.Scene Scene} is displayed
     * with.
     * </p>
     * 
     * @return The <code>ProjectionMode</code> the <code>Scene</code> is displayed with.
     */
    ProjectionMode getProjectionMode();

    /**
     * <p>
     * Retrieves the manager for the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @return The manager for the <code>Scene</code>.
     */
    SceneManager getSceneManager();

    /**
     * <p>
     * Retrieves the manager for the {@link com.se.simplicity.editor.internal.Widget Widget}s used to manipulate the
     * {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @return The manager for the <code>Widget</code>s used to manipulate the <code>Scene</code>.
     */
    WidgetManager getWidgetManager();

    /**
     * <p>
     * Picks the {@link com.se.simplicity.editor.internal.Widget Widget}s and the {@link com.se.simplicity.scene.Scene Scene} to determine the
     * selected scene component (if any). Selection of a <code>Widget</code> takes precedence over selection of a scene component.
     * </p>
     * 
     * @param viewportSize The size of the viewport.
     * @param x The position on the <code>x</code> axis of the viewport to pick.
     * @param y The position on the <code>y</code> axis of the viewport to pick.
     * @param width The width of the area on the viewport to pick.
     * @param height The height of the area on the viewport to pick.
     */
    void pickForSelection(Dimension viewportSize, int x, int y, int width, int height);

    /**
     * <p>
     * Updates this <code>SceneEditor</code> to reflect the size of the 3D canvas.
     * </p>
     * 
     * @param canvasSize The size of the 3D canvas to reflect.
     */
    void setCanvasSize(Rectangle canvasSize);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.DrawingMode DrawingMode} used to render the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @param drawingMode The <code>DrawingMode</code> used to render the <code>Scene</code>.
     */
    void setDrawingMode(DrawingMode drawingMode);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.editor.internal.EditingMode EditingMode} used to manipulate the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @param editingMode The <code>EditingMode</code> used to manipulate the <code>Scene</code>.
     */
    void setEditingMode(EditingMode editingMode);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.ProjectionMode ProjectionMode} the {@link com.se.simplicity.scene.Scene Scene} is displayed with.
     * </p>
     * 
     * @param projectionMode The <code>ProjectionMode</code> the <code>Scene</code> is displayed with.
     */
    void setProjectionMode(ProjectionMode projectionMode);
}
