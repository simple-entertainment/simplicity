/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.rendering.engine;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Manages the renderng of a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. Each advance re-renders the
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} in its current state.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface RenderingEngine extends Engine
{
    /**
     * <p>
     * Determines if the screen buffer is cleared before rendering.
     * </p>
     * 
     * @return True if the screen buffer is cleared before rendering.
     */
    boolean clearsBeforeRender();

    /**
     * <p>
     * Renders the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * <p>
     * This method should be called by {@link com.se.simplicity.viewport.Viewport Viewport}s in order to display an updated <code>Scene</code>.
     * </p>
     */
    @Override
    void advance();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Camera Camera} through which the {@link com.se.simplicity.scene.Scene Scene} will be rendered.
     * </p>
     * 
     * @return The <code>Camera</code> through which the <code>Scene</code> will be rendered.
     */
    Camera getCamera();

    /**
     * <p>
     * Retrieves the colour to clear the screen buffer with before rendering.
     * </p>
     * 
     * @return The colour to clear the screen buffer with before rendering.
     */
    SimpleVectorf4 getClearingColour();

    /**
     * <p>
     * Receives the drawing mode used to render the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     * 
     * @return mode The drawing mode used to render the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     */
    DrawingMode getDrawingMode();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.rendering.Renderer Renderer} that renders {@link com.se.simplicity.model.VertexGroup VertexGroup}s for
     * this <code>RenderingEngine</code>.
     * </p>
     * 
     * @return The {@link com.se.simplicity.rendering.Renderer Renderer} that renders {@link com.se.simplicity.model.VertexGroup VertexGroup}s for
     * this <code>RenderingEngine</code>.
     */
    Renderer getRenderer();

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scene.Scene Scene} to be rendered.
     * </p>
     * 
     * @return The {@link com.se.simplicity.scene.Scene Scene} to be rendered.
     */
    Scene getScene();

    /**
     * <p>
     * Renders the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * <p>
     * Preparation of the rendering environment including camera transformation should not be performed from within this method. Instead this should
     * be performed in the {@link com.se.simplicity.rendering.engine.RenderingEngine#advance() advance()} method.
     * </p>
     */
    void renderSceneGraph();

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera} through which the {@link com.se.simplicity.scene.Scene Scene} will be rendered.
     * </p>
     * 
     * @param newCamera The <code>Camera</code> through which the <code>Scene</code> will be rendered.
     */
    void setCamera(Camera newCamera);

    /**
     * <p>
     * Sets the colour to clear the buffer with before rendering.
     * </p>
     * 
     * @param newClearingColour The colour to clear the buffer with before rendering.
     */
    void setClearingColour(SimpleVectorf4 newClearingColour);

    /**
     * <p>
     * Sets the clearing mode. Determines if the screen buffer is cleared before rendering.
     * </p>
     * 
     * @param newClearsBeforeRender Determines if the screen buffer is cleared before rendering.
     */
    void setClearsBeforeRender(boolean newClearsBeforeRender);

    /**
     * <p>
     * Sets the drawing mode used to render the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     * </p>
     * 
     * @param newDrawingMode The drawing mode used to render the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
     */
    void setDrawingMode(DrawingMode newDrawingMode);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Renderer Renderer} that renders {@link com.se.simplicity.model.VertexGroup VertexGroup}s for this
     * <code>RenderingEngine</code>.
     * </p>
     * 
     * @param newRenderer The {@link com.se.simplicity.rendering.Renderer Renderer} that renders {@link com.se.simplicity.model.VertexGroup
     * VertexGroup}s for this <code>RenderingEngine</code>.
     */
    void setRenderer(Renderer newRenderer);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scene.Scene Scene} to be rendered.
     * </p>
     * 
     * @param newScene The {@link com.se.simplicity.scene.Scene Scene} to be rendered.
     */
    void setScene(Scene newScene);
}
