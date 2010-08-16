package com.se.simplicity.vector;

/**
 * <p>
 * A 4 dimensional translation vector that stores its data in a <code>float</code> array.
 * </p>
 * 
 * <p>
 * This <code>SimpleVectorf4</code> uses a 3D homogeneous coordinate system. It is of the following format:
 * </p>
 * 
 * <pre>
 * ----------------
 *  x | y | z | w |
 * ----------------
 * </pre>
 * 
 * @author simple
 */
public class SimpleTranslationVectorf4 extends SimpleVectorf4 implements TranslationVectorf
{
	/**
	 * The version of this class.
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * <p>
	 * Creates an instance of <code>SimpleTranslationVectorf4</code>.
	 * </p>
	 */
	public SimpleTranslationVectorf4()
	{
		super();
	}
	
	/**
	 * <p>
	 * Creates an instance of <code>SimpleTranslationVectorf4</code>.
	 * </p>
	 * 
	 * @param f0 The x element of this <code>SimpleTranslationVectorf4</code>.
	 * @param f1 The y element of this <code>SimpleTranslationVectorf4</code>.
	 * @param f2 The z element of this <code>SimpleTranslationVectorf4</code>.
	 * @param f3 The w element of this <code>SimpleTranslationVectorf4</code>.
	 */
	public SimpleTranslationVectorf4(final float f0, final float f1, final float f2, final float f3)
	{
		super(f0, f1, f2, f3);
	}
	
	/**
	 * <p>
	 * Creates an instance of <code>SimpleTranslationVectorf4</code>.
	 * </p>
	 * 
	 * @param array An array containing the initial elements of this <code>SimpleTranslationVectorf4</code>.
	 */
	public SimpleTranslationVectorf4(final float[] array)
	{
		super(array);
	}
	
	@Override
	public float getW()
	{
		return (getArray()[3]);
	}

	@Override
	public float getX()
	{
		return (getArray()[0]);
	}

	public float getY()
	{
		return (getArray()[1]);
	}

	@Override
	public float getZ()
	{
		return (getArray()[2]);
	}

	@Override
	public void setX(final float x)
	{
		getArray()[0] = x;
	}

	@Override
	public void setY(final float y)
	{
		getArray()[1] = y;
	}

	@Override
	public void setZ(final float z)
	{
		getArray()[2] = z;
	}

	@Override
	public void translateX(final float x)
	{
		getArray()[0] += x;
	}

	@Override
	public void translateY(final float y)
	{
		getArray()[1] += y;
	}

	@Override
	public void translateZ(final float z)
	{
		getArray()[2] += z;
	}
}
