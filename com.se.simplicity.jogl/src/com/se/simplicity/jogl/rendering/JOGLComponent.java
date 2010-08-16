package com.se.simplicity.jogl.rendering;

// JOGL imports.
import javax.media.opengl.GL;

/**
 * <p>
 * A component that uses the JOGL rendering environment.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public interface JOGLComponent
{
	/**
	 * <p>
	 * Retrieves the JOGL rendering environment.
	 * </p>
	 * 
	 * @return The JOGL rendering environment.
	 */
	GL getGL();

	/**
	 * <p>
	 * Sets the JOGL rendering environment.
	 * </p>
	 * 
	 * @param gl The JOGL rendering environment.
	 */
	void setGL(GL gl);
}
