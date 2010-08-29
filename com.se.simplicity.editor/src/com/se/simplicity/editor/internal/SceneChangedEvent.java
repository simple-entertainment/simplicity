/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal;

import com.se.simplicity.scene.Scene;

/**
 * <p>
 * An event raised when a <code>Scene</code> is changed. Provides contextual information to a
 * {@link com.se.simplicity.editor.internal.SceneChangedListener SceneChangedListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneChangedEvent
{
    /**
     * <p>
     * The <code>Scene</code> that has changed.
     * </p>
     */
    private Scene scene;

    /**
     * <p>
     * The type of change that has been made to the <code>Scene</code>.
     * </p>
     */
    private SceneChangedEventType type;

    /**
     * <p>
     * The component that has changed (if the event is component specific).
     * </p>
     */
    private Object sceneComponent;

    /**
     * <p>
     * Creates an instance of <code>SceneChangedEvent</code>.
     * </p>
     * 
     * @param newScene The <code>Scene</code> that has changed.
     * @param newSceneComponent The component that has changed (if the event is component specific).
     * @param newType The type of change that has been made to the <code>Scene</code>.
     */
    public SceneChangedEvent(final Scene newScene, final Object newSceneComponent, final SceneChangedEventType newType)
    {
        sceneComponent = newSceneComponent;
        scene = newScene;
        type = newType;
    }

    /**
     * <p>
     * Retrieves the <code>Scene</code> that has changed.
     * </p>
     * 
     * @return The <code>Scene</code> that has changed.
     */
    public Scene getScene()
    {
        return (scene);
    }

    /**
     * <p>
     * Retrieves the component that has changed (if the event is component specific).
     * </p>
     * 
     * @return The component that has changed, or null if the event is not component specific.
     */
    public Object getSceneComponent()
    {
        return (sceneComponent);
    }

    /**
     * <p>
     * Retrieves the type of change that has been made to the <code>Scene</code>.
     * </p>
     * 
     * @return The type of change that has been made to the <code>Scene</code>.
     */
    public SceneChangedEventType getType()
    {
        return (type);
    }
}
