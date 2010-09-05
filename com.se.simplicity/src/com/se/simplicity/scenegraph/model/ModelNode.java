/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.scenegraph.model;

import com.se.simplicity.model.Model;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * A {@link com.se.simplicity.scenegraph.Node Node} that contains a {@link com.se.simplicity.model.Model Model}.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface ModelNode extends Node
{
    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.model.Model Model} at this <code>ModelNode</code>'s position and orientation.
     * </p>
     * 
     * @return The {@link com.se.simplicity.model.Model Model} at this <code>ModelNode</code>'s position and orientation.
     */
    Model getModel();

    /**
     * <p>
     * Sets the {@link com.se.simplicity.model.Model Model} at this <code>ModelNode</code>'s position and orientation.
     * </p>
     * 
     * @param model The {@link com.se.simplicity.model.Model Model} at this <code>ModelNode</code>'s position and orientation.
     */
    void setModel(Model model);
}
