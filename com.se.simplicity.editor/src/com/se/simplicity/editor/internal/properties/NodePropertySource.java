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
import org.eclipse.ui.views.properties.IPropertyDescriptor;
import org.eclipse.ui.views.properties.IPropertySource;
import org.eclipse.ui.views.properties.PropertyDescriptor;
import org.eclipse.ui.views.properties.TextPropertyDescriptor;

import com.se.simplicity.editor.internal.EditorPlugin;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;

/**
 * <p>
 * Provides properties for a {@link com.se.simplicity.scenegraph.Node Node}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NodePropertySource implements IPropertySource
{
    /**
     * <p>
     * The {@link com.se.simplicity.scenegraph.Node Node} to provide properties for.
     * </p>
     */
    private Node fNode;

    /**
     * <p>
     * Descriptors of the {@link com.se.simplicity.scenegraph.Node Node}'s exposed properties.
     * </p>
     */
    private IPropertyDescriptor[] fPropertyDescriptors;

    /**
     * <p>
     * Creates an instance of <code>NodePropertySource</code>.
     * </p>
     * 
     * @param node The {@link com.se.simplicity.scenegraph.Node Node} to provide properties for.
     */
    public NodePropertySource(final Node node)
    {
        fNode = node;

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

            PropertyDescriptor id = new PropertyDescriptor("id", "ID");
            id.setCategory("Identification");
            propertyDescriptors.add(id);
            TextPropertyDescriptor name = new TextPropertyDescriptor("name", "Name");
            name.setCategory("Identification");
            propertyDescriptors.add(name);

            CheckBoxPropertyDescriptor collidable = new CheckBoxPropertyDescriptor("collidable", "Collidable");
            collidable.setCategory("General");
            propertyDescriptors.add(collidable);
            CheckBoxPropertyDescriptor modifiable = new CheckBoxPropertyDescriptor("modifiable", "Modifiable");
            modifiable.setCategory("General");
            propertyDescriptors.add(modifiable);
            CheckBoxPropertyDescriptor visible = new CheckBoxPropertyDescriptor("visible", "Visible");
            visible.setCategory("General");
            propertyDescriptors.add(visible);

            PropertyDescriptor type = new PropertyDescriptor("type", "Type");
            type.setCategory("Reflection");
            propertyDescriptors.add(type);

            TextPropertyDescriptor xAxisRotation = new TextPropertyDescriptor("xAxisRotation", "X");
            xAxisRotation.setCategory("Rotation");
            propertyDescriptors.add(xAxisRotation);
            TextPropertyDescriptor yAxisRotation = new TextPropertyDescriptor("yAxisRotation", "Y");
            yAxisRotation.setCategory("Rotation");
            propertyDescriptors.add(yAxisRotation);
            TextPropertyDescriptor zAxisRotation = new TextPropertyDescriptor("zAxisRotation", "Z");
            zAxisRotation.setCategory("Rotation");
            propertyDescriptors.add(zAxisRotation);

            TextPropertyDescriptor xAxisTranslation = new TextPropertyDescriptor("xAxisTranslation", "X");
            xAxisTranslation.setCategory("Translation");
            propertyDescriptors.add(xAxisTranslation);
            TextPropertyDescriptor yAxisTranslation = new TextPropertyDescriptor("yAxisTranslation", "Y");
            yAxisTranslation.setCategory("Translation");
            propertyDescriptors.add(yAxisTranslation);
            TextPropertyDescriptor zAxisTranslation = new TextPropertyDescriptor("zAxisTranslation", "Z");
            zAxisTranslation.setCategory("Translation");
            propertyDescriptors.add(zAxisTranslation);

            fPropertyDescriptors = propertyDescriptors.toArray(new PropertyDescriptor[0]);
        }

        return (fPropertyDescriptors);
    }

    @Override
    public Object getPropertyValue(final Object id)
    {
        Object propertyValue = null;

        // Identification
        if (id.equals("id"))
        {
            propertyValue = fNode.getID();

        }
        else if (id.equals("name"))
        {
            if (fNode instanceof MetaDataNode)
            {
                propertyValue = ((MetaDataNode) fNode).getAttribute("name");
            }
            else
            {
                propertyValue = MetaDataNode.getDefaultName(fNode);
            }
        }

        // General
        else if (id.equals("collidable"))
        {
            propertyValue = fNode.isCollidable();
        }
        else if (id.equals("modifiable"))
        {
            propertyValue = fNode.isModifiable();
        }
        else if (id.equals("visible"))
        {
            propertyValue = fNode.isVisible();
        }

        // Reflection
        else if (id.equals("type"))
        {
            if (fNode instanceof MetaDataNode)
            {
                propertyValue = ((MetaDataNode) fNode).getWrappedNode().getClass().getName();
            }
            else
            {
                propertyValue = fNode.getClass().getName();
            }
        }

        // Rotation
        else if (id.equals("xAxisRotation"))
        {
            propertyValue = fNode.getTransformation().getXAxisRotation();
        }
        else if (id.equals("yAxisRotation"))
        {
            propertyValue = fNode.getTransformation().getYAxisRotation();
        }
        else if (id.equals("zAxisRotation"))
        {
            propertyValue = fNode.getTransformation().getZAxisRotation();
        }

        // Translation
        else if (id.equals("xAxisTranslation"))
        {
            propertyValue = fNode.getTransformation().getXAxisTranslation();
        }
        else if (id.equals("yAxisTranslation"))
        {
            propertyValue = fNode.getTransformation().getYAxisTranslation();
        }
        else if (id.equals("zAxisTranslation"))
        {
            propertyValue = fNode.getTransformation().getZAxisTranslation();
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

        // Identification
        if (id.equals("name"))
        {
            if (fNode instanceof MetaDataNode)
            {
                oldValue = ((MetaDataNode) fNode).getAttribute("name");
                ((MetaDataNode) fNode).setAttribute("name", value);
            }
        }

        // General
        else if (id.equals("collidable"))
        {
            oldValue = fNode.isCollidable();
            fNode.setCollidable((Boolean) value);
        }
        else if (id.equals("modifiable"))
        {
            oldValue = fNode.isModifiable();
            fNode.setModifiable((Boolean) value);
        }
        else if (id.equals("visible"))
        {
            oldValue = fNode.isVisible();
            fNode.setVisible((Boolean) value);
        }

        // Rotation
        else if (id.equals("xAxisRotation"))
        {
            oldValue = fNode.getTransformation().getXAxisRotation();
            fNode.getTransformation().setXAxisRotation(Float.valueOf((String) value));
        }
        else if (id.equals("yAxisRotation"))
        {
            oldValue = fNode.getTransformation().getYAxisRotation();
            fNode.getTransformation().setYAxisRotation(Float.valueOf((String) value));
        }
        else if (id.equals("zAxisRotation"))
        {
            oldValue = fNode.getTransformation().getZAxisRotation();
            fNode.getTransformation().setZAxisRotation(Float.valueOf((String) value));
        }

        // Translation
        else if (id.equals("xAxisTranslation"))
        {
            oldValue = fNode.getTransformation().getXAxisTranslation();
            fNode.getTransformation().setXAxisTranslation(Float.valueOf((String) value));
        }
        else if (id.equals("yAxisTranslation"))
        {
            oldValue = fNode.getTransformation().getYAxisTranslation();
            fNode.getTransformation().setYAxisTranslation(Float.valueOf((String) value));
        }
        else if (id.equals("zAxisTranslation"))
        {
            oldValue = fNode.getTransformation().getZAxisTranslation();
            fNode.getTransformation().setZAxisTranslation(Float.valueOf((String) value));
        }

        EditorPlugin.getInstance().propertyChanged(new PropertyChangeEvent(this, (String) id, oldValue, value));
    }
}
