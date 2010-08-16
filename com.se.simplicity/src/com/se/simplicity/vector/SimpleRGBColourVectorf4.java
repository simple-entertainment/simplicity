package com.se.simplicity.vector;

/**
 * <p>
 * A 4 dimensional colour vector that stores its data in a <code>float</code> array.
 * </p>
 * 
 * @author simple
 */
public class SimpleRGBColourVectorf4 extends SimpleVectorf4 implements RGBColourVectorf
{
	/**
	 * The version of this class.
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * <p>
	 * Creates an instance of <code>SimpleRGBColourVectorf4</code>.
	 * </p>
	 */
	public SimpleRGBColourVectorf4()
	{
		super();
	}
	
	/**
	 * <p>
	 * Creates an instance of <code>SimpleRGBColourVectorf4</code>.
	 * </p>
	 * 
	 * @param f0 The red element of this <code>SimpleRGBColourVectorf4</code>.
	 * @param f1 The green element of this <code>SimpleRGBColourVectorf4</code>.
	 * @param f2 The blue element of this <code>SimpleRGBColourVectorf4</code>.
	 * @param f3 The alpha element of this <code>SimpleRGBColourVectorf4</code>.
	 */
	public SimpleRGBColourVectorf4(final float f0, final float f1, final float f2, final float f3)
	{
		super(f0, f1, f2, f3);
	}
	
	/**
	 * <p>
	 * Creates an instance of <code>SimpleRGBColourVectorf4</code>.
	 * </p>
	 * 
	 * @param array An array containing the initial elements of this <code>SimpleRGBColourVectorf4</code>.
	 */
	public SimpleRGBColourVectorf4(final float[] array)
	{
		super(array);
	}
	
	@Override
	public float getBlue()
	{
		return (getArray()[2]);
	}

	@Override
	public float getGreen()
	{
		return (getArray()[1]);
	}

	@Override
	public float getRed()
	{
		return (getArray()[0]);
	}

	@Override
	public void setBlue(final float blue)
	{
		getArray()[2] = blue;
	}

	@Override
	public void setGreen(final float green)
	{
		getArray()[1] = green;
	}

	@Override
	public void setRed(final float red)
	{
		getArray()[0] = red;
	}
}
