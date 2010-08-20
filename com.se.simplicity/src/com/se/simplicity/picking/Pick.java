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
    private float height;

    /**
     * <p>
     * The width of the area being picked.
     * </p>
     */
    private float width;

    /**
     * <p>
     * The position on the <code>x</code> axis being picked.
     * </p>
     */
    private float x;

    /**
     * <p>
     * The position on the <code>y</code> axis being picked.
     * </p>
     */
    private float y;

    /**
     * <p>
     * Retrieves the height of the area being picked.
     * </p>
     * 
     * @return The height of the area being picked.
     */
    public float getHeight()
    {
        return height;
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
        return width;
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
        return x;
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
        return y;
    }

    /**
     * <p>
     * Sets the height of the area being picked.
     * </p>
     * 
     * @param newHeight The height of the area being picked.
     */
    public void setHeight(final float newHeight)
    {
        height = newHeight;
    }

    /**
     * <p>
     * Sets the width of the area being picked.
     * </p>
     * 
     * @param newWidth The height of the area being picked.
     */
    public void setWidth(final float newWidth)
    {
        width = newWidth;
    }

    /**
     * <p>
     * Sets the position on the <code>x</code> axis being picked.
     * </p>
     * 
     * @param newX The position on the <code>x</code> axis being picked.
     */
    public void setX(final float newX)
    {
        x = newX;
    }

    /**
     * <p>
     * Sets the position on the <code>y</code> axis being picked.
     * </p>
     * 
     * @param newY The position on the <code>y</code> axis being picked.
     */
    public void setY(final float newY)
    {
        y = newY;
    }
}
