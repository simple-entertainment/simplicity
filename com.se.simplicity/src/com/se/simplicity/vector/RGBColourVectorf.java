package com.se.simplicity.vector;

/**
 * <p>
 * A colour vector that stores its data in a <code>float</code> array.
 * </p>
 * 
 * @author simple
 */
public interface RGBColourVectorf extends Vectorf
{
	/**
	 * <p>
	 * Retrieves the blue component of this <code>RGBColourVectorf</code>.
	 * </p>
	 * 
	 * @return The blue component of this <code>RGBColourVectorf</code>.
	 */
	float getBlue();

	/**
	 * <p>
	 * Retrieves the green component of this <code>RGBColourVectorf</code>.
	 * </p>
	 * 
	 * @return The green component of this <code>RGBColourVectorf</code>.
	 */
	float getGreen();

	/**
	 * <p>
	 * Retrieves the red component of this <code>RGBColourVectorf</code>.
	 * </p>
	 * 
	 * @return The red component of this <code>RGBColourVectorf</code>.
	 */
	float getRed();

	/**
	 * <p>
	 * Sets the blue component of this <code>RGBColourVectorf</code>.
	 * </p>
	 * 
	 * @param blue The blue component of this <code>RGBColourVectorf</code>.
	 */
	void setBlue(float blue);

	/**
	 * <p>
	 * Sets the green component of this <code>RGBColourVectorf</code>.
	 * </p>
	 * 
	 * @param green The green component of this <code>RGBColourVectorf</code>.
	 */
	void setGreen(float green);

	/**
	 * <p>
	 * Sets the red component of this <code>RGBColourVectorf</code>.
	 * </p>
	 * 
	 * @param red The red component of this <code>RGBColourVectorf</code>.
	 */
	void setRed(float red);
}
