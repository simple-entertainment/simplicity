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
import org.eclipse.swt.events.MouseWheelListener;
import org.eclipse.swt.widgets.Control;

import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * Listens for mouse events on a 3D canvas and picks the <code>SceneGraph</code> displayed on it.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneMouseListener implements MouseListener, MouseWheelListener
{
    /**
     * <p>
     * The <code>PickingEngine</code> to register picks with.
     * </p>
     */
    private PickingEngine fPickingEngine;

    /**
     * <p>
     * The <code>Camera</code> being used to view the <code>Scene</code>.
     * </p>
     */
    private Camera fViewingCamera;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneMouseListener</code>.
     * </p>
     * 
     * @param newPickingEngine The <code>PickingEngine</code> to register picks with.
     */
    public VisualSceneMouseListener(final PickingEngine newPickingEngine, final Camera viewingCamera)
    {
        fPickingEngine = newPickingEngine;
        fViewingCamera = viewingCamera;
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
        if (event.button == 1)
        {
            Dimension viewportSize = new Dimension();
            viewportSize.width = ((Control) event.widget).getBounds().width;
            viewportSize.height = ((Control) event.widget).getBounds().height;

            fPickingEngine.pickViewport(viewportSize, event.x, event.y, 5, 5);
        }
    }

    @Override
    public void mouseScrolled(final MouseEvent event)
    {
        fViewingCamera.getNode().getTransformation().translate(new SimpleTranslationVectorf4(0.0f, 0.0f, event.count * -1.0f, 1.0f));
    }
}
