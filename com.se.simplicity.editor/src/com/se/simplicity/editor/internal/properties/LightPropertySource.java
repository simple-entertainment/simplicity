/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.properties;

import java.util.ArrayList;

import org.eclipse.jface.util.PropertyChangeEvent;
import org.eclipse.ui.views.properties.ComboBoxPropertyDescriptor;
import org.eclipse.ui.views.properties.IPropertyDescriptor;
import org.eclipse.ui.views.properties.IPropertySource;
import org.eclipse.ui.views.properties.PropertyDescriptor;
import org.eclipse.ui.views.properties.TextPropertyDescriptor;

import com.se.simplicity.editor.internal.EditorPlugin;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;

/**
 * <p>
 * Provides properties for a {@link com.se.simplicity.rendering.Light Light}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class LightPropertySource implements IPropertySource
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Light Light} to provide properties for.
     * </p>
     */
    private Light fLight;

    /**
     * <p>
     * Descriptors of the {@link com.se.simplicity.rendering.Light Light}'s exposed properties.
     * </p>
     */
    private IPropertyDescriptor[] fPropertyDescriptors;

    /**
     * <p>
     * Creates an instance of <code>LightPropertySource</code>.
     * </p>
     * 
     * @param light The {@link com.se.simplicity.rendering.Light Light} to provide properties for.
     */
    public LightPropertySource(final Light light)
    {
        fLight = light;

        fPropertyDescriptors = null;
    }

    @Override
    public Object getEditableValue()
    {
        return (null);
    }

    @Override
    public IPropertyDescriptor[] getPropertyDescriptors()
    {
        if (fPropertyDescriptors == null)
        {
            ArrayList<PropertyDescriptor> propertyDescriptors = new ArrayList<PropertyDescriptor>();

            TextPropertyDescriptor ambientRed = new TextPropertyDescriptor("ambientRed", "Red");
            ambientRed.setCategory("Ambient Light");
            propertyDescriptors.add(ambientRed);
            TextPropertyDescriptor ambientGreen = new TextPropertyDescriptor("ambientGreen", "Green");
            ambientGreen.setCategory("Ambient Light");
            propertyDescriptors.add(ambientGreen);
            TextPropertyDescriptor ambientBlue = new TextPropertyDescriptor("ambientBlue", "Blue");
            ambientBlue.setCategory("Ambient Light");
            propertyDescriptors.add(ambientBlue);

            TextPropertyDescriptor diffuseRed = new TextPropertyDescriptor("diffuseRed", "Red");
            diffuseRed.setCategory("Diffuse Light");
            propertyDescriptors.add(diffuseRed);
            TextPropertyDescriptor diffuseGreen = new TextPropertyDescriptor("diffuseGreen", "Green");
            diffuseGreen.setCategory("Diffuse Light");
            propertyDescriptors.add(diffuseGreen);
            TextPropertyDescriptor diffuseBlue = new TextPropertyDescriptor("diffuseBlue", "Blue");
            diffuseBlue.setCategory("Diffuse Light");
            propertyDescriptors.add(diffuseBlue);

            PropertyDescriptor node = new PropertyDescriptor("node", "Node");
            node.setCategory("General");
            propertyDescriptors.add(node);
            ComboBoxPropertyDescriptor lightingMode = new ComboBoxPropertyDescriptor("lightingMode", "Lighting Mode", new String[] {"SCENE",
                    "SHADED", "SOLID"});
            lightingMode.setCategory("General");
            propertyDescriptors.add(lightingMode);

            TextPropertyDescriptor name = new TextPropertyDescriptor("name", "Name");
            name.setCategory("Identification");
            propertyDescriptors.add(name);

            PropertyDescriptor type = new PropertyDescriptor("type", "Type");
            type.setCategory("Reflection");
            propertyDescriptors.add(type);

            TextPropertyDescriptor specularRed = new TextPropertyDescriptor("specularRed", "Red");
            specularRed.setCategory("Specular Light");
            propertyDescriptors.add(specularRed);
            TextPropertyDescriptor specularGreen = new TextPropertyDescriptor("specularGreen", "Green");
            specularGreen.setCategory("Specular Light");
            propertyDescriptors.add(specularGreen);
            TextPropertyDescriptor specularBlue = new TextPropertyDescriptor("specularBlue", "Blue");
            specularBlue.setCategory("Specular Light");
            propertyDescriptors.add(specularBlue);

            fPropertyDescriptors = propertyDescriptors.toArray(new PropertyDescriptor[0]);
        }

        return (fPropertyDescriptors);
    }

    @Override
    public Object getPropertyValue(final Object id)
    {
        Object propertyValue = null;

        // Ambient Light
        if (id.equals("ambientRed"))
        {
            propertyValue = fLight.getAmbientLight()[0];
        }
        else if (id.equals("ambientGreen"))
        {
            propertyValue = fLight.getAmbientLight()[1];
        }
        else if (id.equals("ambientBlue"))
        {
            propertyValue = fLight.getAmbientLight()[2];
        }

        // Diffuse Light
        if (id.equals("diffuseRed"))
        {
            propertyValue = fLight.getDiffuseLight()[0];
        }
        else if (id.equals("diffuseGreen"))
        {
            propertyValue = fLight.getDiffuseLight()[1];
        }
        else if (id.equals("diffuseBlue"))
        {
            propertyValue = fLight.getDiffuseLight()[2];
        }

        // General
        else if (id.equals("node"))
        {
            propertyValue = fLight.getNode().getID();
        }
        else if (id.equals("lightingMode"))
        {
            if (fLight.getLightingMode() == LightingMode.SCENE)
            {
                propertyValue = 0;
            }
            else if (fLight.getLightingMode() == LightingMode.SHADED)
            {
                propertyValue = 1;
            }
            else if (fLight.getLightingMode() == LightingMode.SOLID)
            {
                propertyValue = 2;
            }
        }

        // Identification
        else if (id.equals("name"))
        {
            if (fLight instanceof MetaDataLight)
            {
                propertyValue = ((MetaDataLight) fLight).getAttribute("name");
            }
            else
            {
                propertyValue = "?LightX?";
            }
        }

        // Reflection
        else if (id.equals("type"))
        {
            if (fLight instanceof MetaDataLight)
            {
                propertyValue = ((MetaDataLight) fLight).getWrappedLight().getClass().getName();
            }
            else
            {
                propertyValue = fLight.getClass().getName();
            }
        }

        // Specular Light
        if (id.equals("specularRed"))
        {
            propertyValue = fLight.getSpecularLight()[0];
        }
        else if (id.equals("specularGreen"))
        {
            propertyValue = fLight.getSpecularLight()[1];
        }
        else if (id.equals("specularBlue"))
        {
            propertyValue = fLight.getSpecularLight()[2];
        }

        return (propertyValue);
    }

    @Override
    public boolean isPropertySet(final Object id)
    {
        return (false);
    }

    @Override
    public void resetPropertyValue(final Object id)
    {}

    @Override
    public void setPropertyValue(final Object id, final Object value)
    {
        Object oldValue = null;

        // Ambient Light
        if (id.equals("ambientRed"))
        {
            oldValue = fLight.getAmbientLight()[0];
            fLight.getAmbientLight()[0] = Float.valueOf((String) value);
        }
        else if (id.equals("ambientGreen"))
        {
            oldValue = fLight.getAmbientLight()[1];
            fLight.getAmbientLight()[1] = Float.valueOf((String) value);
        }
        else if (id.equals("ambientBlue"))
        {
            oldValue = fLight.getAmbientLight()[2];
            fLight.getAmbientLight()[2] = Float.valueOf((String) value);
        }

        // Diffuse Light
        if (id.equals("diffuseRed"))
        {
            oldValue = fLight.getDiffuseLight()[0];
            fLight.getDiffuseLight()[0] = Float.valueOf((String) value);
        }
        else if (id.equals("diffuseGreen"))
        {
            oldValue = fLight.getDiffuseLight()[1];
            fLight.getDiffuseLight()[1] = Float.valueOf((String) value);
        }
        else if (id.equals("diffuseBlue"))
        {
            oldValue = fLight.getDiffuseLight()[2];
            fLight.getDiffuseLight()[2] = Float.valueOf((String) value);
        }

        // General
        if (id.equals("lightingMode"))
        {
            oldValue = fLight.getLightingMode();
            if ((Integer) value == 0)
            {
                fLight.setLightingMode(LightingMode.SCENE);
            }
            else if ((Integer) value == 1)
            {
                fLight.setLightingMode(LightingMode.SHADED);
            }
            else if ((Integer) value == 2)
            {
                fLight.setLightingMode(LightingMode.SOLID);
            }
        }

        // Identification
        else if (id.equals("name"))
        {
            if (fLight instanceof MetaDataLight)
            {
                oldValue = ((MetaDataLight) fLight).getAttribute("name");
                ((MetaDataLight) fLight).setAttribute("name", value);
            }
        }

        // Specular Light
        if (id.equals("specularRed"))
        {
            oldValue = fLight.getSpecularLight()[0];
            fLight.getSpecularLight()[0] = Float.valueOf((String) value);
        }
        else if (id.equals("specularGreen"))
        {
            oldValue = fLight.getSpecularLight()[1];
            fLight.getSpecularLight()[1] = Float.valueOf((String) value);
        }
        else if (id.equals("specularBlue"))
        {
            oldValue = fLight.getSpecularLight()[2];
            fLight.getSpecularLight()[2] = Float.valueOf((String) value);
        }

        EditorPlugin.getInstance().propertyChanged(new PropertyChangeEvent(this, (String) id, oldValue, value));
    }
}
