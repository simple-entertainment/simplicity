/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal.properties;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import org.eclipse.ui.views.properties.IPropertyDescriptor;
import org.junit.Test;

import com.se.simplicity.editor.internal.properties.NodePropertySource;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.properties.NodePropertySource NodePropertySource}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NodePropertySourceTest
{
    /**
     * An instance of the class being unit tested.
     */
    private NodePropertySource testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.NodePropertySource#getPropertyDescriptors() getPropertyDescriptors()}.
     * </p>
     */
    @Test
    public void getPropertyDescriptors()
    {
        // Initialise test environment.
        testObject = new NodePropertySource(createMock(Node.class));

        // Perform test.
        IPropertyDescriptor[] propertyDescriptors = testObject.getPropertyDescriptors();

        // Verify test results.
        assertEquals(12, propertyDescriptors.length, 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.NodePropertySource#getPropertyValue(Object) getPropertyValue(Object)}.
     * </p>
     */
    @Test
    public void getPropertyValue()
    {
        // Create dependencies.
        Node mockNode = createMock(Node.class);

        TransformationMatrixf mockTransformation = createMock(TransformationMatrixf.class);

        // Dictate correct behaviour.
        expect(mockNode.getID()).andStubReturn(0);
        expect(mockNode.isCollidable()).andStubReturn(true);
        expect(mockNode.isModifiable()).andStubReturn(true);
        expect(mockNode.isVisible()).andStubReturn(true);
        expect(mockNode.getTransformation()).andStubReturn(mockTransformation);
        expect(mockTransformation.getXAxisRotation()).andStubReturn((float) Math.toRadians(90.0));
        expect(mockTransformation.getYAxisRotation()).andStubReturn((float) Math.toRadians(180.0));
        expect(mockTransformation.getZAxisRotation()).andStubReturn((float) Math.toRadians(270.0f));
        expect(mockTransformation.getXAxisTranslation()).andStubReturn(5.0f);
        expect(mockTransformation.getYAxisTranslation()).andStubReturn(10.0f);
        expect(mockTransformation.getZAxisTranslation()).andStubReturn(15.0f);
        replay(mockNode, mockTransformation);

        // Initialise test environment.
        testObject = new NodePropertySource(mockNode);

        // Perform test - Verify test results.
        assertEquals(0, testObject.getPropertyValue("id"));
        assertEquals(true, testObject.getPropertyValue("collidable"));
        assertEquals(true, testObject.getPropertyValue("modifiable"));
        assertEquals(true, testObject.getPropertyValue("visible"));
        assertEquals(Math.toRadians(90.0f), ((Float) testObject.getPropertyValue("xAxisRotation")).floatValue(), 0.0001f);
        assertEquals(Math.toRadians(180.0f), ((Float) testObject.getPropertyValue("yAxisRotation")).floatValue(), 0.0001f);
        assertEquals(Math.toRadians(270.0f), ((Float) testObject.getPropertyValue("zAxisRotation")).floatValue(), 0.0001f);
        assertEquals(5.0f, ((Float) testObject.getPropertyValue("xAxisTranslation")).floatValue(), 0.0001f);
        assertEquals(10.0f, ((Float) testObject.getPropertyValue("yAxisTranslation")).floatValue(), 0.0001f);
        assertEquals(15.0f, ((Float) testObject.getPropertyValue("zAxisTranslation")).floatValue(), 0.0001f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.NodePropertySource#getPropertyValue(Object) getPropertyValue(Object)},
     * specifically the functionality dependent on the type of the Node.
     * </p>
     */
    @Test
    public void getPropertyValueType()
    {
        // Create dependencies.
        SimpleNode node = new SimpleNode();
        MetaDataNode metaDataNode = new MetaDataNode(node);
        metaDataNode.setAttribute("name", "test");

        // Initialise test environment.
        testObject = new NodePropertySource(node);

        // Perform test 1 - Verify test 1 results.
        assertEquals("SimpleNode0", testObject.getPropertyValue("name"));
        assertEquals("com.se.simplicity.scenegraph.SimpleNode", testObject.getPropertyValue("type"));

        // Initialise test environment.
        testObject = new NodePropertySource(metaDataNode);

        // Perform test 2 - Verify test 2 results.
        assertEquals("test", testObject.getPropertyValue("name"));
        assertEquals("com.se.simplicity.scenegraph.SimpleNode", testObject.getPropertyValue("type"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.NodePropertySource#setPropertyValue(Object, Object)
     * setPropertyValue(Object, Object)}.
     * </p>
     */
    @Test
    public void setPropertyValue()
    {
        // Create dependencies.
        Node mockNode = createMock(Node.class);

        TransformationMatrixf mockTransformation = createMock(TransformationMatrixf.class);

        // Initialise test environment.
        testObject = new NodePropertySource(mockNode);

        // Dictate expected results.
        mockNode.setCollidable(true);
        mockNode.setModifiable(true);
        mockNode.setVisible(true);
        expect(mockNode.getTransformation()).andStubReturn(mockTransformation);
        mockTransformation.setXAxisRotation((float) Math.toRadians(90.0));
        mockTransformation.setYAxisRotation((float) Math.toRadians(180.0));
        mockTransformation.setZAxisRotation((float) Math.toRadians(270.0f));
        mockTransformation.setXAxisTranslation(5.0f);
        mockTransformation.setYAxisTranslation(10.0f);
        mockTransformation.setZAxisTranslation(15.0f);
        replay(mockNode, mockTransformation);

        // Perform test
        testObject.setPropertyValue("name", "test");
        testObject.setPropertyValue("collidable", true);
        testObject.setPropertyValue("modifiable", true);
        testObject.setPropertyValue("visible", true);
        testObject.setPropertyValue("xAxisRotation", Double.toString(Math.toRadians(90.0)));
        testObject.setPropertyValue("yAxisRotation", Double.toString(Math.toRadians(180.0)));
        testObject.setPropertyValue("zAxisRotation", Double.toString(Math.toRadians(270.0)));
        testObject.setPropertyValue("xAxisTranslation", "5.0");
        testObject.setPropertyValue("yAxisTranslation", "10.0");
        testObject.setPropertyValue("zAxisTranslation", "15.0");

        // Verify test results.
        verify(mockNode, mockTransformation);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.NodePropertySource#setPropertyValue(Object, Object)
     * setPropertyValue(Object, Object)} with the special condition that the Node is a MetaDataNode.
     * </p>
     */
    @Test
    public void setPropertyValueMetaDataNode()
    {
        // Create dependencies.
        MetaDataNode mockNode = createMock(MetaDataNode.class);

        TransformationMatrixf mockTransformation = createMock(TransformationMatrixf.class);

        // Initialise test environment.
        testObject = new NodePropertySource(mockNode);

        // Dictate expected results.
        mockNode.setAttribute("name", "test");
        mockNode.setCollidable(true);
        mockNode.setModifiable(true);
        mockNode.setVisible(true);
        expect(mockNode.getTransformation()).andStubReturn(mockTransformation);
        mockTransformation.setXAxisRotation((float) Math.toRadians(90.0));
        mockTransformation.setYAxisRotation((float) Math.toRadians(180.0));
        mockTransformation.setZAxisRotation((float) Math.toRadians(270.0f));
        mockTransformation.setXAxisTranslation(5.0f);
        mockTransformation.setYAxisTranslation(10.0f);
        mockTransformation.setZAxisTranslation(15.0f);
        replay(mockNode, mockTransformation);

        // Perform test
        testObject.setPropertyValue("name", "test");
        testObject.setPropertyValue("collidable", true);
        testObject.setPropertyValue("modifiable", true);
        testObject.setPropertyValue("visible", true);
        testObject.setPropertyValue("xAxisRotation", Double.toString(Math.toRadians(90.0)));
        testObject.setPropertyValue("yAxisRotation", Double.toString(Math.toRadians(180.0)));
        testObject.setPropertyValue("zAxisRotation", Double.toString(Math.toRadians(270.0)));
        testObject.setPropertyValue("xAxisTranslation", "5.0");
        testObject.setPropertyValue("yAxisTranslation", "10.0");
        testObject.setPropertyValue("zAxisTranslation", "15.0");

        // Verify test results.
        verify(mockNode, mockTransformation);
    }
}
