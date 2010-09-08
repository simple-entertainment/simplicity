/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import java.awt.Dimension;

import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.MouseListener;
import org.eclipse.swt.events.MouseMoveListener;
import org.eclipse.swt.graphics.Point;
import org.eclipse.swt.widgets.Control;

import com.se.simplicity.editor.internal.ContentProvider;

/**
 * <p>
 * Listens for mouse events on a 3D canvas and picks the 3D widgets displayed on it as well as manipulating the position and orientation of the
 * selected {@link com.se.simplicity.model.Model Model} depending on the widget element that was picked.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetMouseListener implements MouseListener, MouseMoveListener
{
    /**
     * <p>
     * Determines if mouse button 1 is currently down.
     * </p>
     */
    private boolean fMouseButton1Down;

    /**
     * <p>
     * The last position the mouse was at (only updated while mouse button 1 is down).
     * </p>
     */
    private Point fMouseButton1DownPoint;

    /**
     * <p>
     * The {@link com.se.simplicity.rendering.editor.internal.ContentProvider ContentProvider} to set the currently selected widget component for.
     * </p>
     */
    private ContentProvider fContentProvider;

    /**
     * <p>
     * Creates an instance of <code>WidgetMouseListener</code>.
     * </p>
     * 
     * @param contentProvider The <code>PickingEngine</code> to register picks with.
     */
    public WidgetMouseListener(final ContentProvider contentProvider)
    {
        fContentProvider = contentProvider;
    }

    @Override
    public void mouseDoubleClick(final MouseEvent event)
    {}

    @Override
    public void mouseDown(final MouseEvent event)
    {
        if (event.button == 1)
        {
            fMouseButton1DownPoint = null;
            fMouseButton1Down = true;

            Dimension viewportSize = new Dimension();
            viewportSize.width = ((Control) event.widget).getBounds().width;
            viewportSize.height = ((Control) event.widget).getBounds().height;

            fContentProvider.getWidgetPickingEngine().pickViewport(viewportSize, event.x, event.y, 2, 2);
        }
    }

    @Override
    public void mouseMove(final MouseEvent event)
    {
        if (fMouseButton1Down)
        {
            if (fMouseButton1DownPoint != null)
            {
                fContentProvider.executeEdit(event.x - fMouseButton1DownPoint.x, event.y - fMouseButton1DownPoint.y);
            }

            fMouseButton1DownPoint = new Point(event.x, event.y);
        }
    }

    @Override
    public void mouseUp(final MouseEvent event)
    {
        if (event.button == 1)
        {
            fMouseButton1Down = false;

            fContentProvider.setSelectedWidgetComponent(null);
        }
    }
}
