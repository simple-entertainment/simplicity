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

import com.se.simplicity.editor.internal.properties.LightPropertySource;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.properties.LightPropertySource LightPropertySource}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class LightPropertySourceTest
{
    /**
     * An instance of the class being unit tested.
     */
    private LightPropertySource testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.LightPropertySource#getPropertyDescriptors() getPropertyDescriptors()}
     * .
     * </p>
     */
    @Test
    public void getPropertyDescriptors()
    {
        // Initialise test environment.
        testObject = new LightPropertySource(createMock(Light.class));

        // Perform test.
        IPropertyDescriptor[] propertyDescriptors = testObject.getPropertyDescriptors();

        // Verify test results.
        assertEquals(13, propertyDescriptors.length, 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.LightPropertySource#getPropertyValue(Object) getPropertyValue(Object)}
     * .
     * </p>
     */
    @Test
    public void getPropertyValue()
    {
        // Create dependencies.
        Light mockLight = createMock(Light.class);
        Node mockNode = createMock(Node.class);

        // Initialise test environment.
        testObject = new LightPropertySource(mockLight);

        // Dictate correct behaviour.
        expect(mockLight.getAmbientLight()).andStubReturn(new float[] {0.1f, 0.2f, 0.3f, 1.0f});
        expect(mockLight.getDiffuseLight()).andStubReturn(new float[] {0.1f, 0.2f, 0.3f, 1.0f});
        expect(mockLight.getNode()).andStubReturn(mockNode);
        expect(mockLight.getLightingMode()).andStubReturn(LightingMode.SCENE);
        expect(mockLight.getSpecularLight()).andStubReturn(new float[] {0.1f, 0.2f, 0.3f, 1.0f});
        expect(mockNode.getID()).andStubReturn(0);
        replay(mockLight, mockNode);

        // Perform test - Verify test results.
        assertEquals(0.1f, testObject.getPropertyValue("ambientRed"));
        assertEquals(0.2f, testObject.getPropertyValue("ambientGreen"));
        assertEquals(0.3f, testObject.getPropertyValue("ambientBlue"));
        assertEquals(0.1f, testObject.getPropertyValue("diffuseRed"));
        assertEquals(0.2f, testObject.getPropertyValue("diffuseGreen"));
        assertEquals(0.3f, testObject.getPropertyValue("diffuseBlue"));
        assertEquals(0, testObject.getPropertyValue("node"));
        assertEquals(0, testObject.getPropertyValue("lightingMode"));
        assertEquals(0.1f, testObject.getPropertyValue("specularRed"));
        assertEquals(0.2f, testObject.getPropertyValue("specularGreen"));
        assertEquals(0.3f, testObject.getPropertyValue("specularBlue"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.LightPropertySource#getPropertyValue(Object) getPropertyValue(Object)}
     * , specifically the functionality dependent on the type of the Light.
     * </p>
     */
    @Test
    public void getPropertyValueType()
    {
        // Create dependencies.
        SimpleJOGLLight camera = new SimpleJOGLLight();
        MetaDataLight metaDataLight = new MetaDataLight(camera);
        metaDataLight.setAttribute("name", "test");

        // Initialise test environment.
        testObject = new LightPropertySource(camera);

        // Perform test 1 - Verify test 1 results.
        assertEquals("?LightX?", testObject.getPropertyValue("name"));
        assertEquals("com.se.simplicity.jogl.rendering.SimpleJOGLLight", testObject.getPropertyValue("type"));

        // Initialise test environment.
        testObject = new LightPropertySource(metaDataLight);

        // Perform test 2 - Verify test 2 results.
        assertEquals("test", testObject.getPropertyValue("name"));
        assertEquals("com.se.simplicity.jogl.rendering.SimpleJOGLLight", testObject.getPropertyValue("type"));
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.LightPropertySource#setPropertyValue(Object, Object)
     * setPropertyValue(Object, Object)}.
     * </p>
     */
    @Test
    public void setPropertyValue()
    {
        // Create dependencies.
        Light mockLight = createMock(Light.class);
        float[] ambientLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};
        float[] diffuseLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};
        float[] specularLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};

        // Initialise test environment.
        testObject = new LightPropertySource(mockLight);

        // Dictate expected results.
        expect(mockLight.getAmbientLight()).andStubReturn(ambientLight);
        expect(mockLight.getDiffuseLight()).andStubReturn(diffuseLight);
        mockLight.setLightingMode(LightingMode.SCENE);
        expect(mockLight.getSpecularLight()).andStubReturn(specularLight);
        replay(mockLight);

        // Perform test
        testObject.setPropertyValue("ambientRed", "0.1");
        testObject.setPropertyValue("ambientGreen", "0.2");
        testObject.setPropertyValue("ambientBlue", "0.3");
        testObject.setPropertyValue("diffuseRed", "0.1");
        testObject.setPropertyValue("diffuseGreen", "0.2");
        testObject.setPropertyValue("diffuseBlue", "0.3");
        testObject.setPropertyValue("lightingMode", 0);
        testObject.setPropertyValue("specularRed", "0.1");
        testObject.setPropertyValue("specularGreen", "0.2");
        testObject.setPropertyValue("specularBlue", "0.3");

        // Verify test results.
        verify(mockLight);

        assertEquals(0.1f, ambientLight[0], 0.0f);
        assertEquals(0.2f, ambientLight[1], 0.0f);
        assertEquals(0.3f, ambientLight[2], 0.0f);
        assertEquals(0.1f, diffuseLight[0], 0.0f);
        assertEquals(0.2f, diffuseLight[1], 0.0f);
        assertEquals(0.3f, diffuseLight[2], 0.0f);
        assertEquals(0.1f, specularLight[0], 0.0f);
        assertEquals(0.2f, specularLight[1], 0.0f);
        assertEquals(0.3f, specularLight[2], 0.0f);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.properties.LightPropertySource#setPropertyValue(Object, Object)
     * setPropertyValue(Object, Object)} with the special condition that the Light is a MetaDataLight.
     * </p>
     */
    @Test
    public void setPropertyValueMetaDataLight()
    {
        // Create dependencies.
        MetaDataLight mockLight = createMock(MetaDataLight.class);
        float[] ambientLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};
        float[] diffuseLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};
        float[] specularLight = new float[] {0.0f, 0.0f, 0.0f, 1.0f};

        // Initialise test environment.
        testObject = new LightPropertySource(mockLight);

        // Dictate expected results.
        expect(mockLight.getAmbientLight()).andStubReturn(ambientLight);
        expect(mockLight.getDiffuseLight()).andStubReturn(diffuseLight);
        mockLight.setAttribute("name", "test");
        mockLight.setLightingMode(LightingMode.SCENE);
        expect(mockLight.getSpecularLight()).andStubReturn(specularLight);
        replay(mockLight);

        // Perform test
        testObject.setPropertyValue("ambientRed", "0.1");
        testObject.setPropertyValue("ambientGreen", "0.2");
        testObject.setPropertyValue("ambientBlue", "0.3");
        testObject.setPropertyValue("diffuseRed", "0.1");
        testObject.setPropertyValue("diffuseGreen", "0.2");
        testObject.setPropertyValue("diffuseBlue", "0.3");
        testObject.setPropertyValue("name", "test");
        testObject.setPropertyValue("lightingMode", 0);
        testObject.setPropertyValue("specularRed", "0.1");
        testObject.setPropertyValue("specularGreen", "0.2");
        testObject.setPropertyValue("specularBlue", "0.3");

        // Verify test results.
        verify(mockLight);

        assertEquals(0.1f, ambientLight[0], 0.0f);
        assertEquals(0.2f, ambientLight[1], 0.0f);
        assertEquals(0.3f, ambientLight[2], 0.0f);
        assertEquals(0.1f, diffuseLight[0], 0.0f);
        assertEquals(0.2f, diffuseLight[1], 0.0f);
        assertEquals(0.3f, diffuseLight[2], 0.0f);
        assertEquals(0.1f, specularLight[0], 0.0f);
        assertEquals(0.2f, specularLight[1], 0.0f);
        assertEquals(0.3f, specularLight[2], 0.0f);
    }
}
