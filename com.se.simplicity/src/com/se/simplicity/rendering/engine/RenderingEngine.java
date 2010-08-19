package com.se.simplicity.rendering.engine;

import java.util.List;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Manages the renderng of a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. Each advance re-renders the
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} in its current state.
 * </p>
 * 
 * @author simple
 */
public interface RenderingEngine extends Engine
{
	/**
	 * <p>
	 * Adds a {@link com.se.simplicity.rendering.Light Light} to this <code>RenderingEngine</code>.
	 * </p>
	 * 
	 * @param light The {@link com.se.simplicity.rendering.Light Light} to add to this <code>RenderingEngine</code>.
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
	 * Renders the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 * 
	 * <p>
	 * This method should be called by {@link com.se.simplicity.viewport.Viewport Viewport}s in order to display an updated
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 */
	@Override
	void advance();

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
	 * Retreives the {@link com.se.simplicity.rendering.Light Light}s in this <code>RenderingEngine</code>.
	 * <p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.Light Light}s in this <code>RenderingEngine</code>.
	 */
	List<Light> getLights();

	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.rendering.Renderer Renderer} that renders
	 * {@link com.se.simplicity.model.VertexGroup VertexGroup}s for this <code>RenderingEngine</code>.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.Renderer Renderer} that renders
	 * {@link com.se.simplicity.model.VertexGroup VertexGroup}s for this <code>RenderingEngine</code>.
	 */
	Renderer getRenderer();

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
	 * Renders the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 * 
	 * <p>
	 * Preparation of the rendering environment including camera transformation should not be performed from within this method.
	 * Instead this should be performed in the {@link com.se.simplicity.rendering.engine.RenderingEngine#advance() advance()}
	 * method.
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
     * Sets the {@link com.se.simplicity.rendering.Light Light}s in this <code>RenderingEngine</code>.
     * <p>
     * 
     * @param lights The {@link com.se.simplicity.rendering.Light Light}s in this <code>RenderingEngine</code>.
     */
    void setLights(List<Light> lights);
	
	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.rendering.Renderer Renderer} that renders
	 * {@link com.se.simplicity.model.VertexGroup VertexGroup}s for this <code>RenderingEngine</code>.
	 * </p>
	 * 
	 * @param renderer The {@link com.se.simplicity.rendering.Renderer Renderer} that renders
	 * {@link com.se.simplicity.model.VertexGroup VertexGroup}s for this <code>RenderingEngine</code>.
	 */
	void setRenderer(Renderer renderer);

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to be rendered.
	 * </p>
	 * 
	 * @param sceneGraph The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to be rendered.
	 */
	void setSceneGraph(final SceneGraph sceneGraph);
}
