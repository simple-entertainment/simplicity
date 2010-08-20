/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.engine;

/**
 * <p>
 * A system that repeats a cycle of functionality. The cycles of functionality are atomic in the context of the <code>Engine</code>.
 * </p>
 * 
 * @author Gary Buyn
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
