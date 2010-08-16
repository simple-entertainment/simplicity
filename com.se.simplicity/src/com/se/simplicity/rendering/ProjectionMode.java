package com.se.simplicity.rendering;

/**
 * <p>
 * The projection mode used to render a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. The modes are as follows:
 * </p>
 * 
 * @author simple
 */
public enum ProjectionMode
{
	/**
	 * <p>
	 * An orthogonal projection (does not employ foreshortening).
	 * </p>
	 */
	ORTHOGONAL,
	
	/**
	 * <p>
	 * A perspective projection (employs foreshortening, this means objects further away appear smaller).
	 * </p>
	 */
	PERSPECTIVE
}
