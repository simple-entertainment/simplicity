/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.viewport;

import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.engine.RenderingEngine;

/**
 * <p>
 * A viewport on which a rendered {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} can be displayed.
 * </p>
 * 
 * <p>
 * Implementors of this interface should be GUI objects that are able to display the rendered {@link com.se.simplicity.scenegraph.SceneGraph
 * SceneGraph}.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Viewport
{
    /**
     * <p>
     * Displays the rendered {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} on this <code>Viewport</code>.
     * </p>
     */
    void displaySceneGraph();

    /**
     * <p>
     * Retrieves the height of this <code>Viewport</code>.
     * </p>
     * 
     * @return The height of this <code>Viewport</code>.
     */
    int getHeight();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} with which the
     * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
     * 
     * @return The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} with which the {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph} is picked.
     * </p>
     */
    PickingEngine getPickingEngine();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that is used to render this <code>Viewport</code>.
     * </p>
     * 
     * @return The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that is used to render this <code>Viewport</code>.
     */
    RenderingEngine getRenderingEngine();

    /**
     * <p>
     * Retrieves the width of this <code>Viewport</code>.
     * </p>
     * 
     * @return The width of this <code>Viewport</code>.
     */
    int getWidth();

    /**
     * <p>
     * Sets the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} with which the {@link com.se.simplicity.scenegraph.SceneGraph
     * SceneGraph} is picked.
     * 
     * @param pickingEngine The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} with which the
     * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
     * </p>
     */
    void setPickingEngine(PickingEngine pickingEngine);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that is used to render this <code>Viewport</code>.
     * </p>
     * 
     * @param renderingEngine The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that is used to render this
     * <code>Viewport</code>.
     */
    void setRenderingEngine(RenderingEngine renderingEngine);

    /**
     * <p>
     * Sets the size of this <code>Viewport</code>.
     * </p>
     * 
     * @param width The width of this <code>Viewport</code>.
     * @param height The height of this <code>Viewport</code>.
     */
    void setSize(int width, int height);
}
