package com.se.simplicity.viewport;

import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;

/**
 * <p>
 * A viewport on which a rendered {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} can be displayed.
 * </p>
 * 
 * <p>
 * Implementors of this interface should be GUI objects that are able to display the rendered
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
 * </p>
 * 
 * @author simple
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
	 * Retrieves the {@link com.se.simplicity.rendering.Camera Camera} through which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is viewed.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.Camera Camera} through which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is viewed.
	 */
	Camera getCamera();

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
	 * @return The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} with which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * </p>
	 */
	PickingEngine getPickingEngine();

	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that is used to render this
	 * <code>Viewport</code>.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that is used to render this
	 * <code>Viewport</code>.
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
	 * Sets the {@link com.se.simplicity.rendering.Camera Camera} through which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is viewed.
	 * </p>
	 * 
	 * @param camera The {@link com.se.simplicity.rendering.Camera Camera} through which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is viewed.
	 */
	void setCamera(Camera camera);

	/**
	 * <p>
	 * Sets the height of this <code>Viewport</code>.
	 * </p>
	 * 
	 * @param height The height of this <code>Viewport</code>.
	 */
	void setHeight(int height);

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} with which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * 
	 * @param pickingEngine The {@link com.se.simplicity.picking.engine.PickingEngine PickingEngine} with which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * </p>
	 */
	void setPickingEngine(PickingEngine pickingEngine);

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that is used to render this
	 * <code>Viewport</code>.
	 * </p>
	 * 
	 * @param renderingEngine The {@link com.se.simplicity.rendering.engine.RenderingEngine RenderingEngine} that is used to
	 * render this <code>Viewport</code>.
	 */
	void setRenderingEngine(RenderingEngine renderingEngine);

	/**
	 * <p>
	 * Sets the width of this <code>Viewport</code>.
	 * </p>
	 * 
	 * @param width The width of this <code>Viewport</code>.
	 */
	void setWidth(int width);
}
