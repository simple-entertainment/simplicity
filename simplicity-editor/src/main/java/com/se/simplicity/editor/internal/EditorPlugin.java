/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal;

import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.Logger;
import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.jface.resource.ImageRegistry;
import org.eclipse.jface.util.IPropertyChangeListener;
import org.eclipse.jface.util.PropertyChangeEvent;

/**
 * <p>
 * Provides resources required by different elements of the editor.
 * </p>
 * 
 * @author Gary Buyn
 */
public final class EditorPlugin
{
    /**
     * <p>
     * The singleton instance of <code>SceneManager</code>.
     * </p>
     */
    private static EditorPlugin fEditorResources = new EditorPlugin();

    /**
     * <p>
     * Returns the singleton instance of <code>SceneManager</code>.
     * </p>
     * 
     * @return The singleton instance of <code>SceneManager</code>.
     */
    public static EditorPlugin getInstance()
    {
        return (fEditorResources);
    }

    /**
     * <p>
     * The image registry.
     * </p>
     */
    private ImageRegistry fImageRegistry;

    /**
     * <p>
     * Logs messages associated with this class.
     * </p>
     */
    private Logger fLogger;

    private List<IPropertyChangeListener> fPropertyChangeListeners;

    /**
     * <p>
     * Creates an instance of <code>SceneManager</code>. Hidden because only one instance of the <code>SceneManager</code> should exist.
     * </p>
     */
    private EditorPlugin()
    {
        fLogger = Logger.getLogger(getClass().getName());
        fPropertyChangeListeners = new ArrayList<IPropertyChangeListener>();

        try
        {
            fImageRegistry = new ImageRegistry();
            fImageRegistry.put("sceneComponentEmpty", ImageDescriptor.createFromURL(new URL(
                    "file:///home/simple/workspace/com.se.simplicity.editor/images/simple_eddy.gif")));
        }
        catch (Exception e)
        {
            fLogger.error("Failed to load image(s).", e);
        }
    }

    /**
     * <p>
     * Retrieves the image registry.
     * </p>
     * 
     * @return The image registry.
     */
    public ImageRegistry getImageRegistry()
    {
        return (fImageRegistry);
    }

    /**
     * <p>
     * Registers a {@link org.eclipse.jface.util.IPropertyChangeListener IPropertyChangeListener} with this <code>EditorPlugin</code>.
     * <code>IPropertyChangeListener</code>s registered here are notified of modifications to scene components.
     * </p>
     * 
     * @param listener The <code>IPropertyChangeListener</code> to register.
     */
    public void addPropertyChangeListener(final IPropertyChangeListener listener)
    {
        fPropertyChangeListeners.add(listener);
    }

    /**
     * <p>
     * Unregisters a {@link org.eclipse.jface.util.IPropertyChangeListener IPropertyChangeListener} with this <code>EditorPlugin</code>.
     * <code>IPropertyChangeListener</code>s registered here are notified of modifications to scene components.
     * </p>
     * 
     * @param listener The <code>IPropertyChangeListener</code> to register.
     */
    public void removePropertyChangeListener(final IPropertyChangeListener listener)
    {
        fPropertyChangeListeners.remove(listener);
    }

    /**
     * <p>
     * Notifies all {@link org.eclipse.jface.util.IPropertyChangeListener IPropertyChangeListener}s registered with this <code>EditorPlugin</code> of
     * a change in a scene component (including the addition and removal of the scene component).
     * </p>
     * 
     * <p>
     * {@link org.eclipse.jface.util.PropertyChangeEvent PropertyChangeEvent}s passed to this method should be constructed as follows:
     * </p>
     * 
     * <ul>
     * <li>source: The Object calling this method.</li>
     * <li>property: The name of the property. Valid values include: 'scene', 'camera', 'light' and 'node'. Other values can be used to identify
     * properties within a scene component.</li>
     * <li>oldValue: The previous value of the property (not required).</li>
     * <li>newValue: The new value of the property. If this value is null it signifies that the scene component has been remooved.</li>
     * </ul>
     * 
     * @param event An event representing a change in a scene component.
     */
    public void propertyChanged(final PropertyChangeEvent event)
    {
        for (IPropertyChangeListener listener : fPropertyChangeListeners)
        {
            listener.propertyChange(event);
        }
    }
}
