package com.se.simplicity.picking;

import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.SceneGraph;

/**
 * <p>
 * Picks {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}s. The
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked based on a
 * {@link com.se.simplicity.rendering.Camera Camera} and a {@link com.se.simplicity.picking.Pick Pick} that generally represents a
 * subset of the {@link com.se.simplicity.rendering.Camera Camera}'s frame.
 * </p>
 * 
 * @author simple
 */
public interface Picker
{
	/**
	 * <p>
	 * Picks a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} using the given
	 * {@link com.se.simplicity.picking.Pick Pick} and basing the {@link com.se.simplicity.picking.Pick Pick} on the given
	 * {@link com.se.simplicity.rendering.Camera Camera}.
	 * </p>
	 * 
	 * @param sceneGraph The {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} to pick.
	 * @param camera The {@link com.se.simplicity.rendering.Camera Camera} to base the pick on.
	 * @param pick The {@link com.se.simplicity.picking.Pick Pick} to apply to the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * 
	 * @return An event containing any picked compoonents of the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 */
	PickEvent pickSceneGraph(SceneGraph sceneGraph, Camera camera, Pick pick);
}
