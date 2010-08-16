package com.se.simplicity.picking.event;

import java.util.EventListener;

/**
 * <p>
 * A listener for {@link com.se.simplicity.picking.event.PickEvent PickEvent} events.
 * </p>
 * 
 * @author simple
 */
public interface PickListener extends EventListener
{
	/**
	 * <p>
	 * Processes a fired {@link com.se.simplicity.picking.event.PickEvent PickEvent}.
	 * </p>
	 * 
	 * @param event The {@link com.se.simplicity.picking.event.PickEvent PickEvent} to process.
	 */
	void scenePicked(PickEvent event);
}
