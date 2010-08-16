package com.se.simplicity.rendering;

import com.se.simplicity.picking.Pick;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A viewpoint within a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
 * </p>
 * 
 * @author simple
 */
public interface Camera
{
	/**
	 * <p>
	 * Applies this <code>Camera</code> to the rendering environment.
	 * </p>
	 */
	void apply();

	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Camera</code>'s location and
	 * orientation.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Camera</code>'s location and
	 * orientation.
	 */
	Node getNode();

	/**
	 * <p>
	 * Retrieves a picking viewpoint adapted from this <code>Camera</code>'s viewpoint.
	 * </p>
	 * 
	 * @param pick The pick to create the viewpoint for.
	 * 
	 * @return The picking viewpoint.
	 */
	Camera getPickCamera(Pick pick);

	/**
	 * <p>
	 * Retrieves the absolute transformation for the {@link com.se.simplicity.scenegraph.Node Node} of this <code>Camera</code>.
	 * </p>
	 * 
	 * @return The absolute transformation for the {@link com.se.simplicity.scenegraph.Node Node} of this <code>Camera</code>,
	 * or null if the {@link com.se.simplicity.scenegraph.Node Node} does not exist.
	 */
	TransformationMatrixf getTransformation();

	/**
	 * <p>
	 * Initialises this <code>Camera</code>.
	 * </p>
	 */
	void init();

	/**
	 * <p>
	 * Determines if this <code>Camera</code> is initialised.
	 * </p>
	 * 
	 * @return True if this <code>Camera</code> is initialised, false otherwise.
	 */
	boolean isInitialised();

	/**
	 * <p>
	 * Sets the initialisation status.
	 * </p>
	 * 
	 * @param isInitialised Determines if this <code>Camera</code> is initialised.
	 */
	void setInitialised(boolean isInitialised);

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Camera</code>'s location and
	 * orientation.
	 * </p>
	 * 
	 * @param node The {@link com.se.simplicity.scenegraph.Node Node} that represents this <code>Camera</code>'s location and
	 * orientation.
	 */
	void setNode(Node node);
}
