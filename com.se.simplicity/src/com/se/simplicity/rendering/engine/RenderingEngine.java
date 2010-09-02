/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.rendering.engine;

import java.awt.Dimension;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Manages the renderng of a {@link com.se.simplicity.scene.Scene Scene}. Each advance renders the <code>Scene</code> in its current state.
 * </p>
 * 
 * <p>
 * Any changes to settings made during the {@link com.se.simplicity.rendering.engine.RenderingEngine#init() init()} method should be reverted during
 * the {@link com.se.simplicity.rendering.engine.RenderingEngine#destroy() destroy()} method. It is the responsibility of the
 * <code>RenderingEngine</code> to leave the rendering environment as it was found (except for contents of buffers) so that multiple
 * <code>RenderingEngine</code>s may be used together without effecting each other.
 * </p>
 * 
 * <p>
 * When used within a <code>RenderingEngine</code>, the {@link com.se.simplicity.rendering.engine.Renderer Renderer} acts as a rendering pass. Adding
 * multiple <code>Renderer</code>s to a <code>RenderingEngine</code> effectively creates a multi pass rendering environment.
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
     * Adds a {@link com.se.simplicity.rendering.Renderer Renderer}. During the {@link com.se.simplicity.rendering.engine.RenderingEngine#advance()
     * advance()} method, the <code>Renderer</code>s are executed against the {@link com.se.simplicity.scene.Scene Scene} in the order they were
     * added.
     * </p>
     * 
     * @param renderer The <code>Renderer</code> to be added.
     */
    void addRenderer(Renderer renderer);

    /**
     * <p>
     * Adds a {@link com.se.simplicity.rendering.Renderer Renderer} at the given index. During the
     * {@link com.se.simplicity.rendering.engine.RenderingEngine#advance() advance()} method, the <code>Renderer</code>s are executed against the
     * {@link com.se.simplicity.scene.Scene Scene} in the order they were added. By adding a <code>Renderer</code> at a specific index, it can be
     * executed before others that were added before it.
     * </p>
     * 
     * @param index The index to add the <code>Renderer</code> at.
     * @param renderer The <code>Renderer</code> to be added.
     */
    void addRenderer(int index, Renderer renderer);

    /**
     * <p>
     * Renders the {@link com.se.simplicity.scene.Scene Scene}.
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
     * Retrieves the root {@link com.se.simplicity.scenegraph.Node Node} of the portion of the {@link com.se.simplicity.scene.Scene Scene} that the
     * given {@link com.se.simplicity.rendering.Renderer Renderer} will render when it is executed.
     * </p>
     * 
     * @param renderer The <code>Renderer</code> to set the root <code>Node</code> for.
     * 
     * @return The root <code>Node</code> of the portion of the <code>Scene</code> that will be rendered.
     */
    Node getRendererRoot(Renderer renderer);

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
     * Retrieves the size of the viewport (the area on which the {@link com.se.simplicity.scene.Scene Scene} will be rendered).
     * </p>
     * 
     * @return The size of the viewport.
     */
    Dimension getViewportSize();

    /**
     * <p>
     * Removes a {@link com.se.simplicity.rendering.Renderer Renderer}.
     * </p>
     * 
     * @param renderer The <code>Renderer</code> to be removed.
     */
    void removeRenderer(Renderer renderer);

    /**
     * <p>
     * Renders the portion of the {@link com.se.simplicity.scene.Scene Scene} with the given root {@link com.se.simplicity.scenegraph.Node Node} using
     * the given {@link com.se.simplicity.rendering.Renderer Renderer}.
     * </p>
     * 
     * <p>
     * Preparation of the rendering environment including {@link com.se.simplicity.rendering.Camera Camera} and
     * {@link com.se.simplicity.rendering.Light Light} applications should not be performed from within this method. Instead this should be performed
     * in the {@link com.se.simplicity.rendering.engine.RenderingEngine#advance() advance()} method.
     * </p>
     * 
     * @param renderer The <code>Renderer</code> that will render the portion of the <code>Scene</code>.
     * @param root The root <code>Node</code> of the portion of the <code>Scene</code> that will be rendered.
     */
    void renderSceneGraph(Renderer renderer, Node root);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.rendering.Camera Camera} through which the {@link com.se.simplicity.scene.Scene Scene} will be rendered.
     * </p>
     * 
     * @param camera The <code>Camera</code> through which the <code>Scene</code> will be rendered.
     */
    void setCamera(Camera camera);

    /**
     * <p>
     * Sets the colour to clear the buffer with before rendering.
     * </p>
     * 
     * @param clearingColour The colour to clear the buffer with before rendering.
     */
    void setClearingColour(SimpleVectorf4 clearingColour);

    /**
     * <p>
     * Sets the clearing mode. Determines if the screen buffer is cleared before rendering.
     * </p>
     * 
     * @param clearsBeforeRender Determines if the screen buffer is cleared before rendering.
     */
    void setClearsBeforeRender(boolean clearsBeforeRender);

    /**
     * <p>
     * Sets the root {@link com.se.simplicity.scenegraph.Node Node} of the portion of the {@link com.se.simplicity.scene.Scene Scene} that the given
     * {@link com.se.simplicity.rendering.Renderer Renderer} will render when it is executed. The default is the root <code>Node</code> of the
     * <code>Scene</code>.
     * </p>
     * 
     * @param renderer The <code>Renderer</code> to set the root <code>Node</code> for.
     * @param root The root <code>Node</code> of the portion of the <code>Scene</code> that will be rendered.
     */
    void setRendererRoot(Renderer renderer, Node root);

    /**
     * <p>
     * Sets the {@link com.se.simplicity.scene.Scene Scene} to be rendered.
     * </p>
     * 
     * @param scene The {@link com.se.simplicity.scene.Scene Scene} to be rendered.
     */
    void setScene(Scene scene);

    /**
     * <p>
     * Sets the size of the viewport (the area on which the {@link com.se.simplicity.scene.Scene Scene} will be rendered).
     * </p>
     * 
     * @param viewportSize The size of the viewport.
     */
    void setViewportSize(Dimension viewportSize);
}
