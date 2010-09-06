/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.model.shapes;

import com.se.simplicity.model.Model;
import com.se.simplicity.vector.RGBColourVectorf;
import com.se.simplicity.vector.SimpleRGBColourVectorf4;

/**
 * <p>
 * A torus-shaped {@link com.se.simplicity.model.Model Model}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class Torus implements Model
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
     * The inner radius.
     * </p>
     */
    private float fInnerRadius;

    /**
     * <p>
     * The outer radius.
     * </p>
     */
    private float fOuterRadius;

    /**
     * <p>
     * Creates an instance of <code>Torus</code>.
     * </p>
     */
    public Torus()
    {
        fColour = new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 1.0f);
        fInnerRadius = 1.0f;
        fOuterRadius = 2.0f;
    }

    /**
     * <p>
     * Retrieves the colour to render this <code>Torus</code> as. The default is white.
     * </p>
     * 
     * @return The colour to render this <code>Torus</code> as.
     */
    public RGBColourVectorf getColour()
    {
        return (fColour);
    }

    /**
     * <p>
     * Retrieves the inner radius. The default is 0.5.
     * </p>
     * 
     * @return The inner radius.
     */
    public float getInnerRadius()
    {
        return (fInnerRadius);
    }

    /**
     * <p>
     * Retrieves the outer radius. The default is 0.5.
     * </p>
     * 
     * @return The outer radius.
     */
    public float getOuterRadius()
    {
        return (fOuterRadius);
    }

    /**
     * <p>
     * Sets the colour to render this <code>Torus</code> as. The default is white.
     * </p>
     * 
     * @param colour The colour to render this <code>Torus</code> as.
     */
    public void setColour(final RGBColourVectorf colour)
    {
        fColour = colour;
    }

    /**
     * <p>
     * Sets the inner radius. The default is 0.5.
     * </p>
     * 
     * @param innerRadius The inner radius.
     */
    public void setInnerRadius(final float innerRadius)
    {
        fInnerRadius = innerRadius;
    }

    /**
     * <p>
     * Sets the outer radius. The default is 0.5.
     * </p>
     * 
     * @param outerRadius The outer radius.
     */
    public void setOuterRadius(final float outerRadius)
    {
        fOuterRadius = outerRadius;
    }
}
