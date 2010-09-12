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

import com.se.simplicity.model.Model;

/**
 * <p>
 * A selection within a {@link com.se.simplicity.scene.Scene Scene}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneSelection implements ISelection
{
    /**
     * <p>
     * The selected primitive.
     * </p>
     */
    private Model fPrimitive;

    /**
     * <p>
     * The selected scene component.
     * </p>
     */
    private Object fSceneComponent;

    /**
     * <p>
     * Creates an instance of <code>SceneSelection</code>.
     * </p>
     * 
     * @param sceneComponent The selected scene component (if one is selected).
     * @param primitive The selected primitive (if one is selected).
     */
    public SceneSelection(final Object sceneComponent, final Model primitive)
    {
        fPrimitive = primitive;
        fSceneComponent = sceneComponent;
    }

    /**
     * <p>
     * Retrieves the selected primitive (if one is selected).
     * </p>
     * 
     * @return The selected primitive, or null if there is no selected primitive.
     */
    public Model getPrimitive()
    {
        return (fPrimitive);
    }

    /**
     * <p>
     * Retrieves the selected scene component (if one is selected).
     * </p>
     * 
     * @return The selected scene component, or null if there is no selected primitive.
     */
    public Object getSceneComponent()
    {
        return (fSceneComponent);
    }

    @Override
    public boolean isEmpty()
    {
        return (fPrimitive == null && fSceneComponent == null);
    }
}
