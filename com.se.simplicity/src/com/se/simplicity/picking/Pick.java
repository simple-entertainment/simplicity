package com.se.simplicity.picking;

/**
 * <p>
 * The position and area for a {@link com.se.simplicity.picking.Picker Picker} to pick. A <code>Pick</code> generally represents
 * a subset of a {@link com.se.simplicity.rendering.Camera Camera}'s frame.
 * </p>
 * 
 * @author simple
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
	 * @param height The height of the area being picked.
	 */
	public void setHeight(final float height)
	{
		this.height = height;
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
		this.width = width;
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
		this.x = x;
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
		this.y = y;
	}
}
