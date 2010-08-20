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
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * A {@link com.se.simplicity.scenegraph.Node Node} that contains a {@link com.se.simplicity.model.VertexGroup VertexGroup}.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface ModelNode extends Node
{
    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.model.Model Model} this <code>ModelNode</code> is the root of.
     * </p>
     * 
     * @return The {@link com.se.simplicity.model.Model Model} this <code>ModelNode</code> is the root of or <code>null</code> if this
     * <code>ModelNode</code> is not the root of a {@link com.se.simplicity.model.Model Model}.
     */
    Model getModel();

    /**
     * <p>
     * Retrieves the portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>ModelNode</code> contains.
     * </p>
     * 
     * @return The portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>ModelNode</code> contains.
     */
    VertexGroup getVertexGroup();

    /**
     * <p>
     * Sets the {@link com.se.simplicity.model.Model Model} this <code>ModelNode</code> is the root of.
     * </p>
     * 
     * @param model The {@link com.se.simplicity.model.Model Model} this <code>ModelNode</code> is the root of.
     */
    void setModel(Model model);

    /**
     * <p>
     * Sets the portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>ModelNode</code> contains.
     * </p>
     * 
     * @param vertexGroup The portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>ModelNode</code> contains.
     */
    void setVertexGroup(VertexGroup vertexGroup);
}
