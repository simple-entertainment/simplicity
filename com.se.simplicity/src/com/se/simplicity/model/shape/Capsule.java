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
import com.se.simplicity.vector.SimpleTranslationVectorf4;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * A capsule-shaped {@link com.se.simplicity.model.Model Model}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class Capsule implements Shape
{
    /**
     * <p>
     * The serialisation version of this class.
     * </p>
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * The colour to render this <code>Capsule</code> as.
     * </p>
     */
    private RGBColourVectorf fColour;

    /**
     * <p>
     * The length.
     * </p>
     */
    private float fLength;

    /**
     * <p>
     * The radius.
     * </p>
     */
    private float fRadius;

    /**
     * <p>
     * Creates an instance of <code>Capsule</code>.
     * </p>
     */
    public Capsule()
    {
        fColour = new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 1.0f);
        fLength = 1.0f;
        fRadius = 1.0f;
    }

    @Override
    public TranslationVectorf getCenter()
    {
        return (new SimpleTranslationVectorf4());
    }

    @Override
    public RGBColourVectorf getColour()
    {
        return (fColour);
    }

    /**
     * <p>
     * Retrieves the length. The default is 1.0.
     * </p>
     * 
     * @return The length.
     */
    public float getLength()
    {
        return (fLength);
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
     * Sets the length. The default is 1.0.
     * </p>
     * 
     * @param length The length.
     */
    public void setLength(final float length)
    {
        fLength = length;
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
