package com.se.simplicity.rendering;

import com.se.simplicity.picking.Picker;

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
 * <p>
 * Copyright (c) 2007, simple entertainment
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
	 * Retrieves the {@link com.se.simplicity.picking.Picker Picker} with which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * 
	 * @return The {@link com.se.simplicity.picking.Picker Picker} with which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * </p>
	 */
	Picker getPicker();

	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.rendering.Renderer Renderer} that renders to this <code>Viewport</code>.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.Renderer Renderer} that renders to this <code>Viewport</code>.
	 */
	Renderer getRenderer();
	
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
	 * @param The height of this <code>Viewport</code>.
	 */
	void setHeight(int height);

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.picking.Picker Picker} with which the {@link com.se.simplicity.scenegraph.SceneGraph
	 * SceneGraph} is picked.
	 * 
	 * @param picker The {@link com.se.simplicity.picking.Picker Picker} with which the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * </p>
	 */
	void setPicker(Picker picker);

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.rendering.Renderer Renderer} that renders to this <code>Viewport</code>.
	 * </p>
	 * 
	 * @param renderer The {@link com.se.simplicity.rendering.Renderer Renderer} that renders to this <code>Viewport</code>.
	 */
	void setRenderer(Renderer renderer);
	
	/**
	 * <p>
	 * Sets the width of this <code>Viewport</code>.
	 * </p>
	 * 
	 * @param The width of this <code>Viewport</code>.
	 */
	void setWidth(int width);
}
