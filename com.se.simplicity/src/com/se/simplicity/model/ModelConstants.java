/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.model;

/**
 * <p>
 * Constants often used by objects that manipulate {@link com.se.simplicity.model.Model Model}s and {@link com.se.simplicity.model.VertexGroup
 * VertexGroup}s.
 * </p>
 * 
 * @author Gary Buyn
 */
public final class ModelConstants
{
    /**
     * <p>
     * Constructs an instance of <code>ModelConstants</code> (hidden).
     * </p>
     */
    private ModelConstants()
    {}

    /**
     * <p>
     * The number of data items in a colour, normal or vertex array required to represent one vertex.
     * </p>
     */
    public static final int ITEMS_IN_CNV = 3;

    /**
     * <p>
     * The number of vertices in a face.
     * </p>
     */
    public static final int VERTICES_IN_A_FACE = 3;

    /**
     * <p>
     * The number of data items in a colour, normal or vertex array required to represent one face.
     * </p>
     */
    public static final int CNV_ITEMS_IN_FACE = VERTICES_IN_A_FACE * ITEMS_IN_CNV;
}
