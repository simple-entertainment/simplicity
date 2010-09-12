/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors.outline;

import org.eclipse.jface.viewers.ITreeContentProvider;
import org.eclipse.jface.viewers.Viewer;

import com.se.simplicity.scene.Scene;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * Provides content based on a {@link com.se.simplicity.scene.Scene Scene} for a {@link org.eclipse.jface.viewers.TreeViewer TreeViewer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneContentProvider implements ITreeContentProvider
{
    @Override
    public void dispose()
    {}

    @Override
    public Object[] getChildren(final Object parentElement)
    {
        Object[] children = null;

        if (parentElement instanceof Node)
        {
            children = ((Node) parentElement).getChildren().toArray();
        }

        return (children);
    }

    @Override
    public Object[] getElements(final Object inputElement)
    {
        Scene scene = (Scene) inputElement;

        int elementIndex = 0;
        int elementCount = scene.getCameras().size() + scene.getLights().size() + 1;

        Object[] elements = new Object[elementCount];

        for (Object element : scene.getCameras())
        {
            elements[elementIndex] = element;
            elementIndex++;
        }
        for (Object element : scene.getLights())
        {
            elements[elementIndex] = element;
            elementIndex++;
        }
        elements[elementIndex] = scene.getSceneGraph().getRoot();

        return (elements);
    }

    @Override
    public Object getParent(final Object element)
    {
        Object parent = null;

        if (element instanceof Node)
        {
            parent = ((Node) element).getParent();
        }

        return (parent);
    }

    @Override
    public boolean hasChildren(final Object element)
    {
        boolean hasChildren = false;

        if (element instanceof Node && ((Node) element).hasChildren())
        {
            hasChildren = true;
        }

        return (hasChildren);
    }

    @Override
    public void inputChanged(final Viewer viewer, final Object oldInput, final Object newInput)
    {}
}
