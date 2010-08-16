package com.se.simplicity.picking;

import java.util.List;

import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;
import com.se.simplicity.rendering.Viewport;

/**
 * <p>
 * Can be invoked against a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to determine what components of the
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} lie within an area on a {@link com.se.simplicity.rendering.Viewport
 * Viewport}. This process is termed picking.
 * </p>
 * 
 * <p>
 * When the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked, the results are fired to any
 * {@link com.se.simplicity.picking.event.PickListener PickListener}s in the form of a
 * {@link com.se.simplicity.picking.event.PickEvent PickEvent}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public interface Picker
{
	/**
	 * <p>
	 * Adds a {@link com.se.simplicity.picking.event.PickListener PickListener} to be invoked when a
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * </p>
	 * 
	 * @param listener A {@link com.se.simplicity.picking.event.PickListener PickListener} to be invoked when a
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 */
	void addPickListener(PickListener listener);

	/**
	 * <p>
	 * Fires a {@link com.se.simplicity.picking.event.PickEvent PickEvent} to all
	 * {@link com.se.simplicity.picking.event.PickListener PickListener}s for processing.
	 * </p>
	 * 
	 * @param event The {@link com.se.simplicity.picking.event.PickEvent PickEvent} to be fired to all
	 * {@link com.se.simplicity.picking.event.PickListener PickListener}s.
	 */
	void firePickEvent(PickEvent event);

	/**
	 * <p>
	 * Retrieves the outstanding picks to be performed against a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 * 
	 * @return The outstanding picks to be performed against a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 */
	List<Pick> getPicks();

	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.rendering.Viewport Viewport} that picking has been applied to.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.rendering.Viewport Viewport} that picking has been applied to.
	 */
	Viewport getViewport();

	/**
	 * <p>
	 * Registers a pick at the given location of a {@link com.se.simplicity.rendering.Viewport Viewport} with the given
	 * dimensions.
	 * </p>
	 * 
	 * @param x The position on the <code>x</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} to pick.
	 * @param y The position on the <code>y</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} to pick.
	 * @param width The width of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} to pick.
	 * @param height The height of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} to pick.
	 */
	void pick(int x, int y, int width, int height);

	/**
	 * <p>
	 * Registers a pick at the given location and area of a {@link com.se.simplicity.rendering.Viewport Viewport}.
	 * </p>
	 * 
	 * @param pick The position and area of the {@link com.se.simplicity.rendering.Viewport Viewport} to pick.
	 */
	void pick(Pick pick);

	/**
	 * <p>
	 * Performs the outstanding picks against a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 */
	void pickSceneGraph();

	/**
	 * <p>
	 * Removes a {@link com.se.simplicity.picking.event.PickListener PickListener} from those to be invoked when a
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * </p>
	 * 
	 * @param listener A {@link com.se.simplicity.picking.event.PickListener PickListener} that was to be invoked when a
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 */
	void removePickListener(PickListener listener);
	
	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.rendering.Viewport Viewport} that picking has been applied to.
	 * </p>
	 * 
	 * @param viewport The {@link com.se.simplicity.rendering.Viewport Viewport} that picking has been applied to.
	 */
	void setViewport(Viewport viewport);
}
