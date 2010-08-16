package com.se.simplicity.rendering;

/**
 * <p>
 * The drawing mode used to render a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. The modes are as follows:
 * </p>
 * 
 * @author simple
 */
public enum DrawingMode
{
	/**
	 * <p>
	 * Renders only the edges of the models.
	 * </p>
	 */
	EDGES,
	
	/**
	 * <p>
	 * Renders only the faces of the models.
	 * </p>
	 */
	FACES,
	
	/**
	 * <p>
	 * Renders only the vertices of the models.
	 * </p>
	 */
	VERTICES
}
