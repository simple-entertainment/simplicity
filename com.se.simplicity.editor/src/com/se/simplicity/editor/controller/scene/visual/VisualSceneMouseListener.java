/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.controller.scene.visual;

import org.eclipse.swt.events.MouseAdapter;
import org.eclipse.swt.events.MouseEvent;

import com.se.simplicity.editor.view.scene.visual.VisualSceneView;
import com.se.simplicity.viewport.Viewport;

public class VisualSceneMouseListener extends MouseAdapter
{
    private Viewport model;

    private VisualSceneView view;

    public VisualSceneMouseListener(Viewport model, VisualSceneView view)
    {
        this.model = model;
        this.view = view;
    }
    
    public void mouseClicked(final MouseEvent event)
    {
        if (event.button == 1 && model.getPickingEngine() != null)
        {
            model.getPickingEngine().pickViewport(model, event.x, event.y, view.getBounds().width, view.getBounds().height);
        }
    }
}
