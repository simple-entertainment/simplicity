package com.se.simplicity.picking;

/**
 * <p>
 * The position and area for a {@link com.se.simplicity.picking.Picker Picker} to pick in a
 * {@link com.se.simplicity.rendering.Viewport Viewport}.
 * </p>
 * 
 * @author simple
 */
public class Pick
{
	/**
	 * <p>
	 * The height of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 */
	private int height;

	/**
	 * <p>
	 * The width of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 */
	private int width;

	/**
	 * <p>
	 * The position on the <code>x</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 */
	private int x;

	/**
	 * <p>
	 * The position on the <code>y</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 */
	private int y;

	/**
	 * <p>
	 * Retrieves the height of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 * 
	 * @return The height of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 */
	public int getHeight()
	{
		return height;
	}

	/**
	 * <p>
	 * Retrieves the width of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 * 
	 * @return The width of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 */
	public int getWidth()
	{
		return width;
	}

	/**
	 * <p>
	 * Retrieves the position on the <code>x</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being
	 * picked.
	 * </p>
	 * 
	 * @return The position on the <code>x</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 */
	public int getX()
	{
		return x;
	}

	/**
	 * <p>
	 * Retrieves the position on the <code>y</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being
	 * picked.
	 * </p>
	 * 
	 * @return The position on the <code>y</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 */
	public int getY()
	{
		return y;
	}

	/**
	 * <p>
	 * Sets the height of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 * 
	 * @param height The height of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 */
	public void setHeight(final int height)
	{
		this.height = height;
	}

	/**
	 * <p>
	 * Sets the width of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 * 
	 * @param width The height of the area on the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 */
	public void setWidth(final int width)
	{
		this.width = width;
	}

	/**
	 * <p>
	 * Sets the position on the <code>x</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 * 
	 * @param x The position on the <code>x</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 */
	public void setX(final int x)
	{
		this.x = x;
	}

	/**
	 * <p>
	 * Sets the position on the <code>y</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 * </p>
	 * 
	 * @param y The position on the <code>y</code> axis of the {@link com.se.simplicity.rendering.Viewport Viewport} being picked.
	 */
	public void setY(final int y)
	{
		this.y = y;
	}
}
