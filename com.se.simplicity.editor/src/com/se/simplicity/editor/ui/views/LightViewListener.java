/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.views;

import java.util.Map;

import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.widgets.Combo;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;

/**
 * <p>
 * Listens for events that signify a change in the value held by a widget and saves that property change to the model (i.e. <code>Light</code>).
 * </p>
 * 
 * @author Gary Buyn
 */
public class LightViewListener implements ModifyListener, SelectionListener
{
    /**
     * <p>
     * Determines if this <code>LightViewListener</code> should respond to events.
     * </p>
     */
    private boolean fEnabled;

    /**
     * <p>
     * Maps the <code>Widget</code>s displaying the properties of a <code>Light</code> to names so that they may be easily retrieved and their
     * contents saved to the model.
     * </p>
     */
    private Map<Widget, String> fWidgetBindings;

    /**
     * <p>
     * Creates an instance of <code>LightViewListener</code>.
     * </p>
     * 
     * @param newWidgetBindings Maps the <code>Widget</code>s displaying the properties of a <code>Light</code> to names so that they may be easily
     * retrieved and their contents saved to the model.
     */
    public LightViewListener(final Map<Widget, String> newWidgetBindings)
    {
        fWidgetBindings = newWidgetBindings;

        fEnabled = true;
    }

    /**
     * <p>
     * Stops this <code>LightViewListener</code> from responding to events.
     * </p>
     */
    public void disable()
    {
        fEnabled = false;
    }

    /**
     * <p>
     * Ensures this <code>LightViewListener</code> is responding to events.
     * </p>
     */
    public void enable()
    {
        fEnabled = true;
    }

    /**
     * <p>
     * Determines whether this <code>LightViewListener</code> is responding to events.
     * </p>
     * 
     * @return True if this <code>LightViewListener</code> is responding to events, false otherwise.
     */
    public boolean isEnabled()
    {
        return (fEnabled);
    }

    @Override
    public void modifyText(final ModifyEvent event)
    {
        if (!fEnabled)
        {
            return;
        }

        Scene activeScene = SceneManager.getSceneManager().getActiveScene();
        Light activeLight = SceneManager.getSceneManager().getActiveLight();
        String value = ((Text) event.widget).getText();

        try
        {
            if (fWidgetBindings.get(event.widget).equals("name"))
            {
                if (activeLight instanceof MetaDataLight)
                {
                    ((MetaDataLight) activeLight).setAttribute("name", value);
                }
            }
            else if (fWidgetBindings.get(event.widget).equals("node"))
            {
                activeLight.setNode(activeScene.getSceneGraph().getNode(Integer.parseInt(value)));
            }
            else if (fWidgetBindings.get(event.widget).equals("ambientR"))
            {
                activeLight.getAmbientLight()[0] = Float.parseFloat(value);
            }
            else if (fWidgetBindings.get(event.widget).equals("ambientG"))
            {
                activeLight.getAmbientLight()[1] = Float.parseFloat(value);
            }
            else if (fWidgetBindings.get(event.widget).equals("ambientB"))
            {
                activeLight.getAmbientLight()[2] = Float.parseFloat(value);
            }
            else if (fWidgetBindings.get(event.widget).equals("diffuseR"))
            {
                activeLight.getDiffuseLight()[0] = Float.parseFloat(value);
            }
            else if (fWidgetBindings.get(event.widget).equals("diffuseG"))
            {
                activeLight.getDiffuseLight()[1] = Float.parseFloat(value);
            }
            else if (fWidgetBindings.get(event.widget).equals("diffuseB"))
            {
                activeLight.getDiffuseLight()[2] = Float.parseFloat(value);
            }
            else if (fWidgetBindings.get(event.widget).equals("specularR"))
            {
                activeLight.getSpecularLight()[0] = Float.parseFloat(value);
            }
            else if (fWidgetBindings.get(event.widget).equals("specularG"))
            {
                activeLight.getSpecularLight()[1] = Float.parseFloat(value);
            }
            else if (fWidgetBindings.get(event.widget).equals("specularB"))
            {
                activeLight.getSpecularLight()[2] = Float.parseFloat(value);
            }

            SceneManager.getSceneManager().notifyLightModified(activeLight);
        }
        catch (NumberFormatException e)
        {
            if (!value.isEmpty())
            {
                SceneManager.getSceneManager().setActiveLight(activeLight);
            }
        }
    }

    /**
     * <p>
     * Sets the lighting mode property of a <code>Light</code> in response to a change in the value held by a <code>Widget</code>.
     * </p>
     * 
     * @param widget The <code>Widget</code> whose value has changed.
     */
    protected void setLightingMode(final Widget widget)
    {
        Light activeLight = SceneManager.getSceneManager().getActiveLight();
        String value = ((Combo) widget).getText();

        if (value.equals("SCENE"))
        {
            activeLight.setLightingMode(LightingMode.SCENE);
        }
        else if (value.equals("SHADED"))
        {
            activeLight.setLightingMode(LightingMode.SHADED);
        }
        else if (value.equals("SOLID"))
        {
            activeLight.setLightingMode(LightingMode.SOLID);
        }

        SceneManager.getSceneManager().notifyLightModified(activeLight);
    }

    @Override
    public void widgetDefaultSelected(final SelectionEvent event)
    {
        setLightingMode(event.widget);
    }

    @Override
    public void widgetSelected(final SelectionEvent event)
    {
        setLightingMode(event.widget);
    }
}
