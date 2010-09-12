/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal;

import org.eclipse.jface.viewers.ISelection;

/**
 * <p>
 * A selection within a {@link com.se.simplicity.scene.Scene Scene} made as the result of a picking event.
 * </p>
 * 
 * @author Gary Buyn
 */
public class PickSelection implements ISelection
{
    /**
     * <p>
     * Signifies that the source of the selection was a pick of the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    public static final int SCENE_PICK = 1;

    /**
     * <p>
     * Signifies that the source of the selection was a pick of a {@link com.se.simplicity.editor.internal.Widget Widget}.
     * </p>
     */
    public static final int WIDGET_PICK = 0;

    /**
     * <p>
     * The selected scene component.
     * </p>
     */
    private Object fSceneComponent;

    /**
     * <p>
     * The source of the selection.
     * </p>
     */
    private int fSource;

    /**
     * <p>
     * Creates an instance of <code>PickSelection</code>.
     * </p>
     * 
     * @param sceneComponent The selected scene component.
     * @param source The source of the selection.
     */
    public PickSelection(final Object sceneComponent, final int source)
    {
        fSceneComponent = sceneComponent;
        fSource = source;
    }

    /**
     * <p>
     * Retrieves the selected scene component.
     * </p>
     * 
     * @return The selected scene component.
     */
    public Object getSceneComponent()
    {
        return (fSceneComponent);
    }

    /**
     * <p>
     * Retrieves the source of the selection.
     * </p>
     * 
     * @return The source of the selection.
     */
    public int getSource()
    {
        return (fSource);
    }

    @Override
    public boolean isEmpty()
    {
        return (fSceneComponent == null);
    }
}
