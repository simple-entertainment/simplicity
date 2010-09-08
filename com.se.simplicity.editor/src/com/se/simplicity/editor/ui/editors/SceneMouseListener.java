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
import org.eclipse.swt.widgets.Control;

import com.se.simplicity.picking.engine.PickingEngine;

/**
 * <p>
 * Listens for mouse events on a 3D canvas and picks the <code>Scene</code> displayed on it.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneMouseListener implements MouseListener
{
    /**
     * <p>
     * The <code>PickingEngine</code> to register picks with.
     * </p>
     */
    private PickingEngine fPickingEngine;

    /**
     * <p>
     * Creates an instance of <code>SceneMouseListener</code>.
     * </p>
     * 
     * @param pickingEngine The <code>PickingEngine</code> to register picks with.
     */
    public SceneMouseListener(final PickingEngine pickingEngine)
    {
        fPickingEngine = pickingEngine;
    }

    @Override
    public void mouseDoubleClick(final MouseEvent event)
    {}

    @Override
    public void mouseDown(final MouseEvent event)
    {}

    @Override
    public void mouseUp(final MouseEvent event)
    {
        if (event.button == 3)
        {
            Dimension viewportSize = new Dimension();
            viewportSize.width = ((Control) event.widget).getBounds().width;
            viewportSize.height = ((Control) event.widget).getBounds().height;

            fPickingEngine.pickViewport(viewportSize, event.x, event.y, 2, 2);
        }
    }
}
