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
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.ProjectionMode;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;

/**
 * <p>
 * Provides properties for a {@link com.se.simplicity.rendering.Camera Camera}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class CameraPropertySource implements IPropertySource
{
    /**
     * <p>
     * The {@link com.se.simplicity.rendering.Camera Camera} to provide properties for.
     * </p>
     */
    private Camera fCamera;

    /**
     * <p>
     * Descriptors of the {@link com.se.simplicity.rendering.Camera Camera}'s exposed properties.
     * </p>
     */
    private IPropertyDescriptor[] fPropertyDescriptors;

    /**
     * <p>
     * Creates an instance of <code>CameraPropertySource</code>.
     * </p>
     * 
     * @param camera The {@link com.se.simplicity.rendering.Camera Camera} to provide properties for.
     */
    public CameraPropertySource(final Camera camera)
    {
        fCamera = camera;

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

            TextPropertyDescriptor nearClippingDistance = new TextPropertyDescriptor("nearClippingDistance", "Near Clipping Distance");
            nearClippingDistance.setCategory("Clipping");
            propertyDescriptors.add(nearClippingDistance);
            TextPropertyDescriptor farClippingDistance = new TextPropertyDescriptor("farClippingDistance", "Far Clipping Distance");
            farClippingDistance.setCategory("Clipping");
            propertyDescriptors.add(farClippingDistance);

            TextPropertyDescriptor frameAspectRatio = new TextPropertyDescriptor("frameAspectRatio", "Aspect Ratio");
            frameAspectRatio.setCategory("Frame");
            propertyDescriptors.add(frameAspectRatio);
            TextPropertyDescriptor frameX = new TextPropertyDescriptor("frameX", "X");
            frameX.setCategory("Frame");
            propertyDescriptors.add(frameX);
            TextPropertyDescriptor frameY = new TextPropertyDescriptor("frameY", "Y");
            frameY.setCategory("Frame");
            propertyDescriptors.add(frameY);
            TextPropertyDescriptor frameWidth = new TextPropertyDescriptor("frameWidth", "Width");
            frameWidth.setCategory("Frame");
            propertyDescriptors.add(frameWidth);
            TextPropertyDescriptor frameHeight = new TextPropertyDescriptor("frameHeight", "Height");
            frameHeight.setCategory("Frame");
            propertyDescriptors.add(frameHeight);

            PropertyDescriptor node = new PropertyDescriptor("node", "Node");
            node.setCategory("General");
            propertyDescriptors.add(node);
            ComboBoxPropertyDescriptor projectionMode = new ComboBoxPropertyDescriptor("projectionMode", "Projection Mode", new String[] {
                    "ORTHOGONAL", "PERSPECTIVE"});
            projectionMode.setCategory("General");
            propertyDescriptors.add(projectionMode);

            TextPropertyDescriptor name = new TextPropertyDescriptor("name", "Name");
            name.setCategory("Identification");
            propertyDescriptors.add(name);

            PropertyDescriptor type = new PropertyDescriptor("type", "Type");
            type.setCategory("Reflection");
            propertyDescriptors.add(type);

            fPropertyDescriptors = propertyDescriptors.toArray(new PropertyDescriptor[0]);
        }

        return (fPropertyDescriptors);
    }

    @Override
    public Object getPropertyValue(final Object id)
    {
        Object propertyValue = null;

        // Clipping
        if (id.equals("nearClippingDistance"))
        {
            propertyValue = fCamera.getNearClippingDistance();
        }
        else if (id.equals("farClippingDistance"))
        {
            propertyValue = fCamera.getFarClippingDistance();
        }

        // Frame
        else if (id.equals("frameAspectRatio"))
        {
            propertyValue = fCamera.getFrameAspectRatio();
        }
        else if (id.equals("frameX"))
        {
            propertyValue = fCamera.getFrameX();
        }
        else if (id.equals("frameY"))
        {
            propertyValue = fCamera.getFrameY();
        }
        else if (id.equals("frameWidth"))
        {
            propertyValue = fCamera.getFrameWidth();
        }
        else if (id.equals("frameHeight"))
        {
            propertyValue = fCamera.getFrameHeight();
        }

        // General
        else if (id.equals("node"))
        {
            propertyValue = fCamera.getNode().getID();
        }
        else if (id.equals("projectionMode"))
        {
            if (fCamera.getProjectionMode() == ProjectionMode.ORTHOGONAL)
            {
                propertyValue = 0;
            }
            else if (fCamera.getProjectionMode() == ProjectionMode.PERSPECTIVE)
            {
                propertyValue = 1;
            }
        }

        // Identification
        else if (id.equals("name"))
        {
            if (fCamera instanceof MetaDataCamera)
            {
                propertyValue = ((MetaDataCamera) fCamera).getAttribute("name");
            }
            else
            {
                propertyValue = "?CameraX?";
            }
        }

        // Reflection
        else if (id.equals("type"))
        {
            if (fCamera instanceof MetaDataCamera)
            {
                propertyValue = ((MetaDataCamera) fCamera).getWrappedCamera().getClass().getName();
            }
            else
            {
                propertyValue = fCamera.getClass().getName();
            }
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

        // Clipping
        if (id.equals("nearClippingDistance"))
        {
            oldValue = fCamera.getNearClippingDistance();
            fCamera.setNearClippingDistance(Float.valueOf((String) value));
        }
        else if (id.equals("farClippingDistance"))
        {
            oldValue = fCamera.getFarClippingDistance();
            fCamera.setFarClippingDistance(Float.valueOf((String) value));
        }

        // Frame
        else if (id.equals("frameAspectRatio"))
        {
            oldValue = fCamera.getFrameAspectRatio();
            fCamera.setFrameAspectRatio(Float.valueOf((String) value));
        }
        else if (id.equals("frameX"))
        {
            oldValue = fCamera.getFrameX();
            fCamera.setFrameX(Float.valueOf((String) value));
        }
        else if (id.equals("frameY"))
        {
            oldValue = fCamera.getFrameY();
            fCamera.setFrameY(Float.valueOf((String) value));
        }
        else if (id.equals("frameWidth"))
        {
            oldValue = fCamera.getFrameWidth();
            fCamera.setFrameWidth(Float.valueOf((String) value));
        }
        else if (id.equals("frameHeight"))
        {
            oldValue = fCamera.getFrameHeight();
            fCamera.setFrameHeight(Float.valueOf((String) value));
        }

        // General
        if (id.equals("projectionMode"))
        {
            oldValue = fCamera.getProjectionMode();
            if ((Integer) value == 0)
            {
                fCamera.setProjectionMode(ProjectionMode.ORTHOGONAL);
            }
            else if ((Integer) value == 1)
            {
                fCamera.setProjectionMode(ProjectionMode.PERSPECTIVE);
            }
        }

        // Identification
        else if (id.equals("name"))
        {
            if (fCamera instanceof MetaDataCamera)
            {
                oldValue = ((MetaDataCamera) fCamera).getAttribute("name");
                ((MetaDataCamera) fCamera).setAttribute("name", value);
            }
        }

        EditorPlugin.getInstance().propertyChanged(new PropertyChangeEvent(this, (String) id, oldValue, value));
    }
}
