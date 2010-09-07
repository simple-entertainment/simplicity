/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.model.shape;

import com.se.simplicity.vector.RGBColourVectorf;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;

/**
 * <p>
 * A spherical {@link com.se.simplicity.model.Model Model}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class Sphere implements Shape
{
    /**
     * <p>
     * The serialisation version of this class.
     * </p>
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * The colour to render this <code>Sphere</code> as.
     * </p>
     */
    private RGBColourVectorf fColour;

    /**
     * <p>
     * The radius.
     * </p>
     */
    private float fRadius;

    /**
     * <p>
     * Creates an instance of <code>Sphere</code>.
     * </p>
     */
    public Sphere()
    {
        fColour = new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 1.0f);
        fRadius = 1.0f;
    }

    @Override
    public RGBColourVectorf getColour()
    {
        return (fColour);
    }

    /**
     * <p>
     * Retrieves the radius. The default is 1.0.
     * </p>
     * 
     * @return The radius.
     */
    public float getRadius()
    {
        return (fRadius);
    }

    @Override
    public void setColour(final RGBColourVectorf colour)
    {
        fColour = colour;
    }

    /**
     * <p>
     * Sets the radius. The default is 1.0.
     * </p>
     * 
     * @param radius The radius.
     */
    public void setRadius(final float radius)
    {
        fRadius = radius;
    }
}
