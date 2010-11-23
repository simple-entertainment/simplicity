/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.vector;

import java.io.Serializable;

/**
 * <p>
 * An object which stores its data in a <code>float</code> array.
 * </p>
 * 
 * @author Gary Buyn
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
    private float[] fArray;

    /**
     * <p>
     * Creates an instance of <code>ArrayBackedObjectf</code>.
     * </p>
     */
    public ArrayBackedObjectf()
    {
        fArray = null;
    }

    /**
     * <p>
     * Returns true if the argument is not null, is of the type <code>ArrayBackedObjectf</code> and has an array the same size with the same contents.
     * </p>
     * 
     * @param other The object to compare this <code>ArrayBackedObjectf</code> to.
     * 
     * @return True if this <code>ArrayBackedObjectf</code> is equal to the object given, false otherwise.
     */
    @Override
    public boolean equals(final Object other)
    {
        if (other == null)
        {
            return (false);
        }

        if (!(other instanceof ArrayBackedObjectf))
        {
            return (false);
        }

        ArrayBackedObjectf otherArrayBackedObjectf = (ArrayBackedObjectf) other;

        if (fArray.length != otherArrayBackedObjectf.getArray().length)
        {
            return (false);
        }

        for (int index = 0; index < fArray.length; index++)
        {
            if (fArray[index] != otherArrayBackedObjectf.getArray()[index])
            {
                return (false);
            }
        }

        return (true);
    }

    /**
     * <p>
     * Retrieves the array that contains the data for this object.
     * </p>
     * 
     * @return The array that contains the data for this object.
     */
    public float[] getArray()
    {
        return (fArray);
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
        float[] arrayCopy = new float[fArray.length];
        System.arraycopy(fArray, 0, arrayCopy, 0, fArray.length);

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
        fArray = array;
    }
}
