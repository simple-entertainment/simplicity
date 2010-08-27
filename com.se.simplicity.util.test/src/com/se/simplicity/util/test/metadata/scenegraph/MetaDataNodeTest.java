/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.util.test.metadata.scenegraph;

import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.replay;
import static org.easymock.classextension.EasyMock.createMock;
import static org.junit.Assert.assertEquals;

import org.junit.Test;

import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.model.ModelNode;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.util.scenegraph.MetaDataNode MetaDataNode}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class MetaDataNodeTest
{
    /**
     * An instance of the class being unit tested.
     */
    private MetaDataNode testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scenegraph.MetaDataNode.addDefaultNameAttribute addDefaultNameAttribute()}.
     * </p>
     */
    @Test
    public void addDefaultNameAttribute()
    {
        Node mockNode = createMock(Node.class);

        testObject = new MetaDataNode(mockNode);

        expect(mockNode.getID()).andStubReturn(0);
        replay(mockNode);

        testObject.addDefaultNameAttribute();

        assertEquals("Node (0)", testObject.getAttribute("name"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.util.scenegraph.MetaDataNode.addDefaultNameAttribute addDefaultNameAttribute()} with the
     * special condition that the wrapped <code>Node</code> is a <code>ModelNode</code>.
     * </p>
     */
    @Test
    public void addDefaultNameAttributeModelNode()
    {
        Node mockNode = createMock(ModelNode.class);

        testObject = new MetaDataNode(mockNode);

        expect(mockNode.getID()).andStubReturn(0);
        replay(mockNode);

        testObject.addDefaultNameAttribute();

        assertEquals("Vertex Group (0)", testObject.getAttribute("name"));
    }
}
