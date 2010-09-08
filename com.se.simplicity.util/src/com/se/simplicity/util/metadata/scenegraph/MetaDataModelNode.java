/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.metadata.scenegraph;

import com.se.simplicity.model.Model;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * A {@link com.se.simplicity.util.metadata.scenegraph.MetaDataNode MetaDataNode} with <code>ModelNode</code> support.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MetaDataModelNode extends MetaDataNode implements ModelNode
{
    /**
     * The version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * Creates an instance of <code>MetaDataModelNode</code>.
     * </p>
     * 
     * @param node The <code>Node</code> that is wrapped by this <code>MetaDataModelNode</code>.
     */
    public MetaDataModelNode(final Node node)
    {
        super(node);
    }

    @Override
    public Model getModel()
    {
        return (((ModelNode) getWrappedNode()).getModel());
    }

    @Override
    public void setModel(final Model model)
    {
        ((ModelNode) getWrappedNode()).setModel(model);
    }
}
