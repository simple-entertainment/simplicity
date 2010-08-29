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
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Widget;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scene.Scene;
import com.se.simplicity.util.metadata.rendering.MetaDataLight;

/**
 * <p>
 * Listens for events that signify a change in the value held by a widget and saves that property change to the model (i.e. <code>Light</code>).
 * </p>
 * 
 * @author Gary Buyn
 */
public class LightViewListener implements ModifyListener
{
    /**
     * <p>
     * Determines if this <code>LightViewListener</code> should respond to events.
     * </p>
     */
    private boolean enabled;

    /**
     * <p>
     * Maps the <code>Widget</code>s displaying the properties of a <code>Light</code> to names so that they may be easily retrieved and their
     * contents saved to the model.
     * </p>
     */
    private Map<Widget, String> widgetBindings;

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
        widgetBindings = newWidgetBindings;

        enabled = true;
    }

    /**
     * <p>
     * Stops this <code>LightViewListener</code> from responding to events.
     * </p>
     */
    public void disable()
    {
        enabled = false;
    }

    /**
     * <p>
     * Ensures this <code>LightViewListener</code> is responding to events.
     * </p>
     */
    public void enable()
    {
        enabled = true;
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
        return (enabled);
    }

    @Override
    public void modifyText(final ModifyEvent e)
    {
        if (!enabled)
        {
            return;
        }

        Scene activeScene = SceneManager.getSceneManager().getActiveScene();
        Light activeLight = SceneManager.getSceneManager().getActiveLight();
        String value = ((Text) e.widget).getText();

        if (widgetBindings.get(e.widget).equals("name"))
        {
            if (activeLight instanceof MetaDataLight)
            {
                ((MetaDataLight) activeLight).setAttribute("name", value);
            }
        }
        else if (widgetBindings.get(e.widget).equals("node"))
        {
            activeLight.setNode(activeScene.getSceneGraph().getNode(Integer.parseInt(value)));
        }

        SceneManager.getSceneManager().notifyLightModified(activeLight);
    }
}
