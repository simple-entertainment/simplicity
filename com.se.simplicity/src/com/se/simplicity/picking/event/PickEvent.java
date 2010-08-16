package com.se.simplicity.picking.event;

import java.util.ArrayList;

/**
 * <p>
 * An event that indicates a {@link com.se.simplicity.picking.Picker Picker} has been invoked against a
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} (a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} has
 * been picked) and contains the hits made as a result of this pick.
 * </p>
 * 
 * @author simple
 */
public class PickEvent
{
	/**
	 * <p>
	 * The hits made as a result of the pick.
	 * </p>
	 */
	private ArrayList<Object[]> hits;
	
	/**
	 * <p>
	 * Creates an instance of <code>PickEvent</code>.
	 * </p>
	 */
	public PickEvent()
	{
		hits = new ArrayList<Object[]>();
	}

	/**
	 * <p>
	 * Adds a hit made as a result of the pick.
	 * </p>
	 * 
	 * @param hit A hit made as a result of the pick.
	 */
	public void addHit(final Object[] hit)
	{
		hits.add(hit);
	}
	
	/**
	 * <p>
	 * Retrieves a hit made as a result of the pick.
	 * </p>
	 * 
	 * @param index The index of the hit to retrieve.
	 * 
	 * @return A hit made as a result of the pick.
	 */
	public Object[] getHit(final int index)
	{
		return (hits.get(index));
	}

	/**
	 * <p>
	 * Retrieves the number of hits made as a result of the pick.
	 * </p>
	 * 
	 * @return The number of hits made as a result of the pick.
	 */
	public int getHitCount()
	{
		return (hits.size());
	}
}
