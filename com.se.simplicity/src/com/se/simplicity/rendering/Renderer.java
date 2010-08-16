package com.se.simplicity.rendering;

// simplicity imports.
import java.util.List;

import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Renders a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} from the viewpoint of a
 * {@link com.se.simplicity.rendering.Camera Camera}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public interface Renderer
{
	/**
	 * <p>
	 * Adds a {@link com.se.simplicity.rendering.Camera Camera} to this <code>Renderer</code>.
	 * </p>
	 * 
	 * @param camera The {@link com.se.simplicity.rendering.Camera Camera} to add to this <code>Renderer</code>.
	 */
	void addCamera(Camera camera);

	/**
	 * <p>
	 * Adds a {@link com.se.simplicity.rendering.Light Light} to this <code>Renderer</code>.
	 * </p>
	 * 
	 * @param light The {@link com.se.simplicity.rendering.Light Light} to add to this <code>Renderer</code>.
	 */
	void addLight(Light light);
	
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
	 * Displays the rendered {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 * 
	 * <p>
	 * This method should be called by {@link com.se.simplicity.rendering.Viewport Viewport}s in order to display the rendered
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 */
	void display();
	
	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.rendering.Camera Camera} through which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be rendered.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.Camera Camera} through which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be rendered.
	 */
	Camera getCamera();

	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.rendering.Camera Camera}s in this <code>Renderer</code>.
	 * <p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.Camera Camera}s in this <code>Renderer</code>.
	 */
	List<Camera> getCameras();

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
	 * Retreives the {@link com.se.simplicity.rendering.Light Light}s in this <code>Renderer</code>.
	 * <p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.Light Light}s in this <code>Renderer</code>.
	 */
	List<Light> getLights();

	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to be rendered.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to be rendered.
	 */
	SceneGraph getSceneGraph();

	/**
	 * <p>
	 * Initialises this <code>Renderer</code>.
	 * </p>
	 */
	void init();

	/**
	 * <p>
	 * Renders the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 * 
	 * <p>
	 * Preparation of the rendering environment including camera transformation should not be performed from within this method.
	 * Instead this should be performed in the {@link com.se.simplicity.rendering.Renderer#display() display()} method.
	 * </p>
	 */
	void renderSceneGraph();

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.rendering.Camera Camera} through which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be rendered.
	 * </p>
	 * 
	 * @param camera The {@link com.se.simplicity.rendering.Camera Camera} through which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} will be rendered.
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
	 * Sets the drawing mode used to render the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 * 
	 * @param drawingMode The drawing mode used to render the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 */
	void setDrawingMode(DrawingMode drawingMode);

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to be rendered.
	 * </p>
	 * 
	 * @param sceneGraph The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to be rendered.
	 */
	void setSceneGraph(final SceneGraph sceneGraph);
}
