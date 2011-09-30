/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import org.eclipse.swt.events.ControlAdapter;
import org.eclipse.swt.events.ControlEvent;
import org.eclipse.swt.widgets.Control;

/**
 * <p>
 * Listens for resize events on a 3D canvas and updates the {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor VisualSceneEditor} to reflect
 * the change in size.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ResizeControlListener extends ControlAdapter
{
    /**
     * <p>
     * The {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor VisualSceneEditor} to update.
     * </p>
     */
    private SceneEditor fSceneEditor;

    /**
     * <p>
     * Creates an instance of <code>ResizeControlListener</code>.
     * </p>
     * 
     * @param sceneEditor The {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor VisualSceneEditor} to update.
     */
    public ResizeControlListener(final SceneEditor sceneEditor)
    {
        fSceneEditor = sceneEditor;
    }

    @Override
    public void controlResized(final ControlEvent event)
    {
        fSceneEditor.setCanvasSize(((Control) event.widget).getBounds());
    }
}
