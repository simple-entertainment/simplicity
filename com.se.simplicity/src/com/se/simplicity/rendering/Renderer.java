/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.rendering;

import com.se.simplicity.model.VertexGroup;

/**
 * <p>
 * Renders {@link com.se.simplicity.rendering.VertexGroup VertexGroup}s.
 * </p>
 * 
 * @author Gary Buyn
 */
public interface Renderer
{
    /**
     * <p>
     * Renders the given {@link com.se.simplicity.rendering.VertexGroup VertexGroup} with the given {@link com.se.simplicity.rendering.DrawingMode
     * DrawingMode}.
     * </p>
     * 
     * @param vertexGroup The {@link com.se.simplicity.rendering.VertexGroup VertexGroup} to render.
     * @param drawingMode The {@link com.se.simplicity.rendering.DrawingMode DrawingMode} to render the
     * {@link com.se.simplicity.rendering.VertexGroup VertexGroup} with.
     */
    void renderVertexGroup(VertexGroup vertexGroup, DrawingMode drawingMode);
}
