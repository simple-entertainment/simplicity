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

import com.se.simplicity.editor.internal.properties.CameraPropertySource;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.ProjectionMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.properties.CameraPropertySource CameraPropertySource}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class CameraPropertySourceTest
{
    /**
     * An instance of the class being unit tested.
     */
    private CameraPropertySource testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.CameraPropertySource#getPropertyDescriptors()
     * getPropertyDescriptors()}.
     * </p>
     */
    @Test
    public void getPropertyDescriptors()
    {
        // Initialise test environment.
        testObject = new CameraPropertySource(createMock(Camera.class));

        // Perform test.
        IPropertyDescriptor[] propertyDescriptors = testObject.getPropertyDescriptors();

        // Verify test results.
        assertEquals(11, propertyDescriptors.length, 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.CameraPropertySource#getPropertyValue(Object)
     * getPropertyValue(Object)}.
     * </p>
     */
    @Test
    public void getPropertyValue()
    {
        // Create dependencies.
        Camera mockCamera = createMock(Camera.class);
        Node mockNode = createMock(Node.class);

        // Initialise test environment.
        testObject = new CameraPropertySource(mockCamera);

        // Dictate correct behaviour.
        expect(mockCamera.getNearClippingDistance()).andStubReturn(1000.0f);
        expect(mockCamera.getFarClippingDistance()).andStubReturn(0.1f);
        expect(mockCamera.getFrameAspectRatio()).andStubReturn(0.75f);
        expect(mockCamera.getFrameX()).andStubReturn(0.0f);
        expect(mockCamera.getFrameY()).andStubReturn(0.0f);
        expect(mockCamera.getFrameWidth()).andStubReturn(0.1f);
        expect(mockCamera.getFrameHeight()).andStubReturn(0.075f);
        expect(mockCamera.getNode()).andStubReturn(mockNode);
        expect(mockCamera.getProjectionMode()).andStubReturn(ProjectionMode.PERSPECTIVE);
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockCamera, mockNode);

        // Perform test - Verify test results.
        assertEquals(1000.0f, testObject.getPropertyValue("nearClippingDistance"));
        assertEquals(0.1f, testObject.getPropertyValue("farClippingDistance"));
        assertEquals(0.75f, testObject.getPropertyValue("frameAspectRatio"));
        assertEquals(0.0f, testObject.getPropertyValue("frameX"));
        assertEquals(0.0f, testObject.getPropertyValue("frameY"));
        assertEquals(0.1f, testObject.getPropertyValue("frameWidth"));
        assertEquals(0.075f, testObject.getPropertyValue("frameHeight"));
        assertEquals(0, testObject.getPropertyValue("node"));
        assertEquals(1, testObject.getPropertyValue("projectionMode"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.CameraPropertySource#getPropertyValue(Object)
     * getPropertyValue(Object)}, specifically the functionality dependent on the type of the Camera.
     * </p>
     */
    @Test
    public void getPropertyValueType()
    {
        // Create dependencies.
        SimpleJOGLCamera camera = new SimpleJOGLCamera();
        MetaDataCamera metaDataCamera = new MetaDataCamera(camera);
        metaDataCamera.setAttribute("name", "test");

        // Initialise test environment.
        testObject = new CameraPropertySource(camera);

        // Perform test 1 - Verify test 1 results.
        assertEquals("?CameraX?", testObject.getPropertyValue("name"));
        assertEquals("com.se.simplicity.jogl.rendering.SimpleJOGLCamera", testObject.getPropertyValue("type"));

        // Initialise test environment.
        testObject = new CameraPropertySource(metaDataCamera);

        // Perform test 2 - Verify test 2 results.
        assertEquals("test", testObject.getPropertyValue("name"));
        assertEquals("com.se.simplicity.jogl.rendering.SimpleJOGLCamera", testObject.getPropertyValue("type"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.CameraPropertySource#setPropertyValue(Object, Object)
     * setPropertyValue(Object, Object)}.
     * </p>
     */
    @Test
    public void setPropertyValue()
    {
        // Create dependencies.
        Camera mockCamera = createMock(Camera.class);

        // Initialise test environment.
        testObject = new CameraPropertySource(mockCamera);

        // Dictate expected results.
        mockCamera.setNearClippingDistance(1000.0f);
        mockCamera.setFarClippingDistance(0.1f);
        mockCamera.setFrameAspectRatio(0.75f);
        mockCamera.setFrameX(0.0f);
        mockCamera.setFrameY(0.0f);
        mockCamera.setFrameWidth(0.1f);
        mockCamera.setFrameHeight(0.075f);
        mockCamera.setProjectionMode(ProjectionMode.PERSPECTIVE);
        replay(mockCamera);

        // Perform test
        testObject.setPropertyValue("nearClippingDistance", "1000.0");
        testObject.setPropertyValue("farClippingDistance", "0.1");
        testObject.setPropertyValue("frameAspectRatio", "0.75");
        testObject.setPropertyValue("frameX", "0.0");
        testObject.setPropertyValue("frameY", "0.0");
        testObject.setPropertyValue("frameWidth", "0.1");
        testObject.setPropertyValue("frameHeight", "0.075");
        testObject.setPropertyValue("projectionMode", 1);

        // Verify test results.
        verify(mockCamera);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.CameraPropertySource#setPropertyValue(Object, Object)
     * setPropertyValue(Object, Object)} with the special condition that the Camera is a MetaDataCamera.
     * </p>
     */
    @Test
    public void setPropertyValueMetaDataCamera()
    {
        // Create dependencies.
        MetaDataCamera mockCamera = createMock(MetaDataCamera.class);

        // Initialise test environment.
        testObject = new CameraPropertySource(mockCamera);

        // Dictate correct behaviour.
        mockCamera.setNearClippingDistance(1000.0f);
        mockCamera.setFarClippingDistance(0.1f);
        mockCamera.setFrameAspectRatio(0.75f);
        mockCamera.setFrameX(0.0f);
        mockCamera.setFrameY(0.0f);
        mockCamera.setFrameWidth(0.1f);
        mockCamera.setFrameHeight(0.075f);
        mockCamera.setProjectionMode(ProjectionMode.PERSPECTIVE);
        mockCamera.setAttribute("name", "test");
        replay(mockCamera);

        // Perform test
        testObject.setPropertyValue("nearClippingDistance", "1000.0");
        testObject.setPropertyValue("farClippingDistance", "0.1");
        testObject.setPropertyValue("frameAspectRatio", "0.75");
        testObject.setPropertyValue("frameX", "0.0");
        testObject.setPropertyValue("frameY", "0.0");
        testObject.setPropertyValue("frameWidth", "0.1");
        testObject.setPropertyValue("frameHeight", "0.075");
        testObject.setPropertyValue("projectionMode", 1);
        testObject.setPropertyValue("name", "test");

        // Verify test results.
        verify(mockCamera);
    }
}
