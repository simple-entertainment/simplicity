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
import com.se.simplicity.scenegraph.SimpleNode;

/**
 * <p>
 * A simple implementation of a {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleModelNode extends SimpleNode implements ModelNode
{
    /**
     * The version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * The {@link com.se.simplicity.model.Model Model} this <code>SimpleModelNode</code> is the root of, if this <code>SimpleModelNode</code> is the
     * root of a {@link com.se.simplicity.model.Model Model}.
     * </p>
     */
    private Model model = null;

    /**
     * <p>
     * The portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>SimpleModelNode</code> contains.
     * </p>
     */
    private VertexGroup vertexGroup = null;

    @Override
    public Model getModel()
    {
        return (model);
    }

    @Override
    public VertexGroup getVertexGroup()
    {
        return (vertexGroup);
    }

    @Override
    public void setModel(final Model newModel)
    {
        model = newModel;
    }

    @Override
    public void setVertexGroup(final VertexGroup newVertexGroup)
    {
        vertexGroup = newVertexGroup;
    }
}
