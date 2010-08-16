package com.se.simplicity.engine;

/**
 * <p>
 * A system that repeats a cycle of functionality. The cycles of functionality are atomic in the context of the
 * <code>Engine</code>.
 * </p>
 * 
 * @author simple
 */
public interface Engine extends Runnable
{
	/**
	 * <p>
	 * Advances this <code>Engine</code> by one cycle.
	 * </p>
	 */
	void advance();

	/**
	 * <p>
	 * Destroys this <code>Engine</code>.
	 * </p>
	 */
	void destroy();

	/**
	 * <p>
	 * Initialises this <code>Engine</code>.
	 * </p>
	 */
	void init();

	/**
	 * <p>
	 * Retrieves the preferred frequency (advancements per second) of this <code>Engine</code>.
	 * </p>
	 * 
	 * @return The preferred frequency (advancements per second) of this <code>Engine</code>.
	 */
	int getPreferredFrequency();

	/**
	 * <p>
	 * Resets this <code>Engine</code> to it's initial properties.
	 * </p>
	 */
	void reset();

	/**
	 * <p>
	 * Sets the preferred frequency (advancements per second) of this <code>Engine</code>.
	 * </p>
	 * 
	 * @param preferredFrequency The preferred frequency (advancements per second) of this <code>Engine</code>.
	 */
	void setPreferredFrequency(int preferredFrequency);
}
