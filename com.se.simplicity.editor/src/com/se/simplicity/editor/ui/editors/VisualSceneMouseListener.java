/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import org.eclipse.swt.events.MouseAdapter;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.opengl.GLCanvas;

import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * Listens for mouse events on a 3D canvas and registers picks against the <code>Viewport</code> (if a <code>PickingEngine</code> exists).
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneMouseListener extends MouseAdapter
{
    /**
     * <p>
     * The <code>Viewport</code> this to register picks against.
     * </p>
     */
    private Viewport viewport;

    /**
     * <p>
     * The 3D canvas to listen for mouse events from.
     * </p>
     */
    private GLCanvas canvas;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneMouseListener</code>.
     * </p>
     * 
     * 
     * @param newViewport The <code>Viewport</code> this to register picks again
     * @param newCanvas The 3D canvas to listen for mouse events from.
     */
    public VisualSceneMouseListener(final Viewport newViewport, final GLCanvas newCanvas)
    {
        viewport = newViewport;
        canvas = newCanvas;
    }

    /**
     * <p>
     * Responds to a button 1 mouse event by registering a pick against the <code>Viewport</code> (if a <code>PickingEngine</code> exists).
     * </p>
     * 
     * @param event The event to respond to.
     */
    public void mouseClicked(final MouseEvent event)
    {
        if (event.button == 1 && viewport.getPickingEngine() != null)
        {
            viewport.getPickingEngine().pickViewport(viewport, event.x, event.y, canvas.getBounds().width, canvas.getBounds().height);
        }
    }
}
