/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal.selection;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.eclipse.jface.viewers.IStructuredSelection;

import com.se.simplicity.editor.internal.properties.CameraPropertySource;
import com.se.simplicity.editor.internal.properties.LightPropertySource;
import com.se.simplicity.editor.internal.properties.NodePropertySource;
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * A selection within a {@link com.se.simplicity.scene.Scene Scene}.
 * </p>
 * 
 * <p>
 * NOTE: The methods inherited from {@link org.eclipse.jface.viewers.IStructuredSelection IStructuredSelection} return
 * {@link org.eclipse.ui.views.properties.IPropertySource IPropertySource} objects instead of the actual selection contents. These methods are only
 * intended to be used by an {@link org.eclipse.ui.views.properties.IPropertySheetPage IPropertySheetPage}. All <code>IpropertySource</code> objects
 * returned do, however, provide getters to the actual selection object they provide properties for.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneSelection implements IStructuredSelection
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

    @Override
    public Object getFirstElement()
    {
        Object firstElement = null;

        if (!toList().isEmpty())
        {
            firstElement = toList().get(0);
        }

        return (firstElement);
    }

    @SuppressWarnings("unchecked")
    @Override
    public Iterator iterator()
    {
        return (toList().iterator());
    }

    @Override
    public int size()
    {
        return (toList().size());
    }

    @Override
    public Object[] toArray()
    {
        return (toList().toArray());
    }

    @SuppressWarnings("unchecked")
    @Override
    public List toList()
    {
        ArrayList<Object> list = new ArrayList<Object>();

        if (fSceneComponent instanceof Node)
        {
            list.add(new NodePropertySource((Node) fSceneComponent));
        }
        else if (fSceneComponent instanceof Camera)
        {
            list.add(new CameraPropertySource((Camera) fSceneComponent));
        }
        else if (fSceneComponent instanceof Light)
        {
            list.add(new LightPropertySource((Light) fSceneComponent));
        }

        if (fPrimitive != null)
        {
            list.add(fPrimitive);
        }

        return (list);
    }
}
