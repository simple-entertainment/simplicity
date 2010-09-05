/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.picking.event;

import java.util.ArrayList;

import com.se.simplicity.picking.Hit;

/**
 * <p>
 * An event that indicates a {@link com.se.simplicity.picking.Picker Picker} has been invoked against a
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} (a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} has been picked) and
 * contains the hits made as a result of this pick.
 * </p>
 * 
 * @author Gary Buyn
 */
public class PickEvent
{
    /**
     * <p>
     * The hits made as a result of the pick.
     * </p>
     */
    private ArrayList<Hit> fHits;

    /**
     * <p>
     * Creates an instance of <code>PickEvent</code>.
     * </p>
     */
    public PickEvent()
    {
        fHits = new ArrayList<Hit>();
    }

    /**
     * <p>
     * Adds a hit made as a result of the pick.
     * </p>
     * 
     * @param hit A hit made as a result of the pick.
     */
    public void addHit(final Hit hit)
    {
        fHits.add(hit);
    }

    /**
     * <p>
     * Retrieves the closest hit made as a result of the pick.
     * </p>
     * 
     * @return The closest hit made as a result of the pick.
     */
    public Hit getCloseHit()
    {
        Hit closeHit = null;
        for (Hit hit : fHits)
        {
            if (closeHit == null || hit.getMinimumDistance() < closeHit.getMinimumDistance())
            {
                closeHit = hit;
            }
        }

        return (closeHit);
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
    public Hit getHit(final int index)
    {
        return (fHits.get(index));
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
        return (fHits.size());
    }
}
