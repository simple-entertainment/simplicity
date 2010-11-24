/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.picking.engine;

import java.awt.Dimension;
import java.util.List;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scene.Scene;

/**
 * <p>
 * Manages the picking of a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. Each advance processes the outstanding
 * {@link com.se.simplicity.picking.Pick Pick}s, the results are fired to any {@link com.se.simplicity.picking.event.PickListener PickListener}s in
 * the form of a {@link com.se.simplicity.picking.event.PickEvent PickEvent}.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface PickingEngine extends Engine
{
    /**
     * <p>
     * Adds a {@link com.se.simplicity.picking.event.PickListener PickListener} to be invoked when a {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph} is picked.
     * </p>
     * 
     * @param listener A <code>PickListener</code> to be invoked when a <code>SceneGraph</code> is picked.
     */
    void addPickListener(PickListener listener);

    /**
     * <p>
     * Performs the outstanding picks against a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     */
    void advance();

    /**
     * <p>
     * Fires a {@link com.se.simplicity.picking.event.PickEvent PickEvent} to all {@link com.se.simplicity.picking.event.PickListener PickListener}s
     * for processing.
     * </p>
     * 
     * @param event The <code>PickEvent</code> to be fired to all <code>PickListener</code>s.
     */
    void firePickEvent(PickEvent event);

    /**
     * <p>
     * Retrieves the viewpoint that will be adapted to create the picking viewpoint.
     * </p>
     * 
     * @return The viewpoint that will be adapted to create the picking viewpoint.
     */
    Camera getCamera();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.picking.Picker Picker} that picks the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} for
     * this <code>PickingEngine</code>.
     * </p>
     * 
     * @return The <code>Picker</code> that picks the <code>SceneGraph</code> for this <code>PickingEngine</code>.
     */
    Picker getPicker();

    /**
     * <p>
     * Retrieves the outstanding picks to be performed against this <code>PickingEngine</code>'s {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph}.
     * </p>
     * 
     * @return The outstanding picks to be performed against this <code>PickingEngine</code>'s <code>SceneGraph</code>.
     */
    List<Pick> getPicks();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scene.Scene Scene} to be picked.
     * </p>
     * 
     * @return The <code>Scene</code> to be picked.
     */
    Scene getScene();

    /**
     * <p>
     * Registers a pick at the given location and area relative to this <code>PickingEngine</code>'s {@link com.se.simplicity.rendering.Camera Camera}
     * in {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} coordinates.
     * </p>
     * 
     * @param x The position on the <code>x</code> axis to pick.
     * @param y The position on the <code>y</code> axis to pick.
     * @param width The width of the area to pick.
     * @param height The height of the area to pick.
     */
    void pick(float x, float y, float width, float height);

    /**
     * <p>
     * Registers a pick at the given location and area relative to this <code>PickingEngine</code>'s {@link com.se.simplicity.rendering.Camera Camera}
     * in {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} coordinates.
     * </p>
     * 
     * @param pick The position and area to pick.
     */
    void pick(Pick pick);

    /**
     * <p>
     * Registers a pick at the given location of a viewport with the given dimensions.
     * </p>
     * 
     * @param viewportSize The size of the viewport.
     * @param x The position on the <code>x</code> axis of the viewport to pick.
     * @param y The position on the <code>y</code> axis of the viewport to pick.
     * @param width The width of the area on the viewport to pick.
     * @param height The height of the area on the viewport to pick.
     */
    void pickViewport(Dimension viewportSize, int x, int y, int width, int height);

    /**
     * <p>
     * Registers a pick at the given location and area of a viewport.
     * </p>
     * 
     * @param viewportSize The size of the viewport.
     * @param pick The position and area of the viewport to pick.
     */
    void pickViewport(Dimension viewportSize, Pick pick);

    /**
     * <p>
     * Removes a {@link com.se.simplicity.picking.event.PickListener PickListener} from those to be invoked when a
     * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
     * </p>
     * 
     * @param listener A <code>PickListener</code> that was to be invoked when a <code>SceneGraph</code> is picked.
     */
    void removePickListener(PickListener listener);

    /**
     * <p>
     * Sets the viewpoint that will be adapted to create the picking viewpoint.
     * </p>
     * 
     * @param camera The viewpoint that will be adapted to create the picking viewpoint. The {@link com.se.simplicity.rendering.Camera Camera}
     * given will not be modified when creating the picking viewpoint.
     */
    void setCamera(Camera camera);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.picking.Picker Picker} that picks the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} for this
     * <code>PickingEngine</code>.
     * </p>
     * 
     * @param picker The {@link com.se.simplicity.picking.Picker Picker} that picks the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}
     * for this <code>PickingEngine</code>.
     */
    void setPicker(Picker picker);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scene.Scene Scene} to be picked.
     * </p>
     * 
     * @param scene The <code>Scene</code> to be picked.
     */
    void setScene(Scene scene);
}
