/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.picking;

/**
 * <p>
 * The position and area for a {@link com.se.simplicity.picking.Picker Picker} to pick. A <code>Pick</code> generally represents a subset of a
 * {@link com.se.simplicity.rendering.Camera Camera}'s frame.
 * </p>
 * 
 * @author Gary Buyn
 */
public class Pick
{
    /**
     * <p>
     * The height of the area being picked.
     * </p>
     */
    private float fHeight;

    /**
     * <p>
     * The width of the area being picked.
     * </p>
     */
    private float fWidth;

    /**
     * <p>
     * The position on the <code>x</code> axis being picked.
     * </p>
     */
    private float fX;

    /**
     * <p>
     * The position on the <code>y</code> axis being picked.
     * </p>
     */
    private float fY;

    /**
     * <p>
     * Creates an instance of <code>Pick</code>.
     * </p>
     */
    public Pick()
    {
        fHeight = 0.0f;
        fWidth = 0.0f;
        fX = 0.0f;
        fY = 0.0f;
    }

    /**
     * <p>
     * Retrieves the height of the area being picked.
     * </p>
     * 
     * @return The height of the area being picked.
     */
    public float getHeight()
    {
        return (fHeight);
    }

    /**
     * <p>
     * Retrieves the width of the area being picked.
     * </p>
     * 
     * @return The width of the area being picked.
     */
    public float getWidth()
    {
        return (fWidth);
    }

    /**
     * <p>
     * Retrieves the position on the <code>x</code> axis being picked.
     * </p>
     * 
     * @return The position on the <code>x</code> axis being picked.
     */
    public float getX()
    {
        return (fX);
    }

    /**
     * <p>
     * Retrieves the position on the <code>y</code> axis being picked.
     * </p>
     * 
     * @return The position on the <code>y</code> axis being picked.
     */
    public float getY()
    {
        return (fY);
    }

    /**
     * <p>
     * Sets the height of the area being picked.
     * </p>
     * 
     * @param height The height of the area being picked.
     */
    public void setHeight(final float height)
    {
        fHeight = height;
    }

    /**
     * <p>
     * Sets the width of the area being picked.
     * </p>
     * 
     * @param width The height of the area being picked.
     */
    public void setWidth(final float width)
    {
        fWidth = width;
    }

    /**
     * <p>
     * Sets the position on the <code>x</code> axis being picked.
     * </p>
     * 
     * @param x The position on the <code>x</code> axis being picked.
     */
    public void setX(final float x)
    {
        fX = x;
    }

    /**
     * <p>
     * Sets the position on the <code>y</code> axis being picked.
     * </p>
     * 
     * @param y The position on the <code>y</code> axis being picked.
     */
    public void setY(final float y)
    {
        fY = y;
    }
}
