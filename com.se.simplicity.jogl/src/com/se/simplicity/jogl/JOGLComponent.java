package com.se.simplicity.jogl;

import javax.media.opengl.GL;

/**
 * <p>
 * A component that uses the JOGL rendering environment.
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
