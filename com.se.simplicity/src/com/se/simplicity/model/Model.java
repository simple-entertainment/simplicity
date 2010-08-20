/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.model;

import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * A container for the internal model structure compatible with {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}s. The internal model
 * structure is composed of a graph of {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode}s which becomes a subset of a scene's
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. Each {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode} in the
 * <code>Model</code>'s graph contains a {@link com.se.simplicity.model.VertexGroup VertexGroup} which represents a portion of (or possibly the
 * entire) <code>Model</code>'s vertices. The <code>Model</code> can be split into multiple {@link com.se.simplicity.model.VertexGroup VertexGroup}s
 * to provide structures optimised for animation and/or enhanced rendering performance.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Model
{
    /**
     * <p>
     * Retrieves the node at the root of this <code>Model</code>'s graph.
     * </p>
     * 
     * @return The node at the root of this <code>Model</code>'s graph.
     */
    ModelNode getRoot();

    /**
     * <p>
     * Sets the node at the root of this <code>Model</code>'s graph.
     * </p>
     * 
     * @param root The node at the root of this <code>Model</code>'s graph.
     */
    void setRoot(ModelNode root);
}
