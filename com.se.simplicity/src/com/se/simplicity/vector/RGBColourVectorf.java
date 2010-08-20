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
 * A colour vector that stores its data in a <code>float</code> array.
 * </p>
 * 
 * @author Gary Buyn
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
