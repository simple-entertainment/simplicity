/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.test.scenegraph;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.scenegraph.SimpleNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.scenegraph.SimpleNode SimpleNode}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleNodeTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SimpleNode testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.scenegraph.SimpleNode.addChild addChild()}.
     * </p>
     */
    @Test
    public void addChild()
    {
        SimpleNode child = new SimpleNode();

        testObject.addChild(child);

        assertTrue(testObject.getChildren().contains(child));
        assertEquals(testObject, child.getParent());
    }

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SimpleNode();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.scenegraph.SimpleNode.hasChildren hasChildren()}.
     * </p>
     */
    @Test
    public void hasChildren()
    {
        SimpleNode child = new SimpleNode();

        assertFalse(testObject.hasChildren());

        testObject.addChild(child);

        assertTrue(testObject.hasChildren());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.scenegraph.SimpleNode.isAncestor isAncestor()}.
     * </p>
     */
    @Test
    public void isAncestor()
    {
        SimpleNode child = new SimpleNode();
        testObject.addChild(child);

        SimpleNode grandChild = new SimpleNode();
        child.addChild(grandChild);

        assertTrue(child.isAncestor(testObject));
        assertTrue(grandChild.isAncestor(testObject));

        assertFalse(child.isAncestor(child));
        assertFalse(child.isAncestor(grandChild));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.scenegraph.SimpleNode.isSuccessor isSuccessor()}.
     * </p>
     */
    @Test
    public void isSuccessor()
    {
        SimpleNode child = new SimpleNode();
        testObject.addChild(child);

        SimpleNode grandChild = new SimpleNode();
        child.addChild(grandChild);

        assertTrue(child.isSuccessor(grandChild));
        assertTrue(testObject.isSuccessor(grandChild));

        assertFalse(child.isSuccessor(child));
        assertFalse(child.isSuccessor(testObject));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.scenegraph.SimpleNode.removeChild removeChild()}.
     * </p>
     */
    @Test
    public void removeChild()
    {
        SimpleNode child = new SimpleNode();

        testObject.addChild(child);
        testObject.removeChild(child);

        assertFalse(testObject.getChildren().contains(child));
        assertNull(child.getParent());
    }
}
