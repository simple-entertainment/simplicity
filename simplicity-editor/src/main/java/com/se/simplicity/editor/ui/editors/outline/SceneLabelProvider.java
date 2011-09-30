/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors.outline;

import org.eclipse.jface.viewers.ILabelProvider;
import org.eclipse.jface.viewers.ILabelProviderListener;
import org.eclipse.swt.graphics.Image;

import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.util.metadata.MetaData;
import com.se.simplicity.util.metadata.scenegraph.MetaDataNode;

/**
 * <p>
 * Provides labels relevant to a {@link com.se.simplicity.scene.Scene Scene} for a {@link org.eclipse.jface.viewers.TreeViewer TreeViewer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneLabelProvider implements ILabelProvider
{
    @Override
    public Image getImage(final Object element)
    {
        return (null);
    }

    @Override
    public String getText(final Object element)
    {
        String text = null;

        if (element instanceof MetaData)
        {
            text = (String) ((MetaData) element).getAttribute("name");
        }
        else if (element instanceof Node)
        {
            text = MetaDataNode.getDefaultName((Node) element);
        }
        else
        {
            text = element.getClass().getSimpleName();
        }

        return (text);
    }

    @Override
    public void addListener(final ILabelProviderListener listener)
    {}

    @Override
    public void dispose()
    {}

    @Override
    public boolean isLabelProperty(final Object element, final String property)
    {
        return (false);
    }

    @Override
    public void removeListener(final ILabelProviderListener listener)
    {}

}
