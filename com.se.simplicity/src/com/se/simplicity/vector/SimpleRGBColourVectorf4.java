/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.vector;

/**
 * <p>
 * A 4 dimensional colour vector that stores its data in a <code>float</code> array.
 * </p>
 * 
 * @author Gary Buyn
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
