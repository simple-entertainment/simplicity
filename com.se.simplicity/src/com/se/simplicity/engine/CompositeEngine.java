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
 * An {@link com.se.simplicity.engine.Engine Engine} that is composed of several sub-engines. The <code>CompositeEngine</code> manages how the
 * sub-engines are run.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface CompositeEngine extends Engine
{
    /**
     * <p>
     * Adds an {@link com.se.simplicity.engine.Engine Engine} to the set of engines managed by this <code>CompositeEngine</code>.
     * </p>
     * 
     * @param engine The <code>Engine</code> to add to the set of engines managed by this <code>CompositeEngine</code>.
     */
    void addEngine(Engine engine);

    /**
     * <p>
     * Removes an {@link com.se.simplicity.engine.Engine Engine} from the set of engines managed by this <code>CompositeEngine</code>.
     * </p>
     * 
     * @param engine The <code>Engine</code> to remove from the set of engines managed by this <code>CompositeEngine</code> .
     */
    void removeEngine(Engine engine);
}
