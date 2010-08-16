package com.se.simplicity.vector;

import java.io.Serializable;

/**
 * <p>
 * An object which stores its data in a <code>float</code> array.
 * </p>
 *
 * @author simple
 */
public abstract class ArrayBackedObjectf implements Serializable
{
    /**
	 * The version of this class.
	 */
	private static final long serialVersionUID = 1L;
	
	/**
     * <p>
     * The array that contains the data for this object.
     * </p>
     */
    private float[] array = null;

    /**
     * <p>
     * Retrieves the array that contains the data for this object.
     * </p>
     *
     * @return The array that contains the data for this object.
     */
    public float[] getArray()
    {
        return (array);
    }

    /**
     * <p>
     * Retrieves a copy of the array that contains the data for this object.
     * </p>
     *
     * @return A copy of the array that contains the data for this object.
     */
    public float[] getArrayCopy()
    {
        float[] arrayCopy = new float[array.length];
        System.arraycopy(array, 0, arrayCopy, 0, array.length);

        return (arrayCopy);
    }

    /**
     * <p>
     * Sets the array that contains the data for this object.
     * </p>
     *
     * @param array The array that contains the data for this object.
     */
    public void setArray(final float[] array)
    {
        this.array = array;
    }
}
