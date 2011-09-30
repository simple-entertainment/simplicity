/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.internal;

import com.se.simplicity.editor.internal.selection.PickSelection;
import com.se.simplicity.editor.internal.selection.PickSelectionSource;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.editor.ui.editors.SceneEditor;
import com.se.simplicity.model.Model;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;

/**
 * <p>
 * Listens for pick events on a 3D canvas and selects the picked scene component.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ScenePickListener implements PickListener
{
    /**
     * <p>
     * The {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor} to select the scene component for.
     * </p>
     */
    private SceneEditor fSceneEditor;

    /**
     * <p>
     * Creates an instance of <code>ScenePickListener</code>.
     * </p>
     * 
     * @param sceneEditor The {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor} to select the scene component for.
     */
    public ScenePickListener(final SceneEditor sceneEditor)
    {
        fSceneEditor = sceneEditor;
    }

    @Override
    public void scenePicked(final PickEvent event)
    {
        Object sceneComponent = null;
        Model primitive = null;
        if (event.getHitCount() > 0)
        {
            sceneComponent = event.getCloseHit().getNode();
            primitive = event.getCloseHit().getPrimitive();
        }

        // Only allow a selection that is not for the already selected scene component if the EditingMode is 'SELECTION' and the SelectionMode is
        // 'MODEL'.
        if (sceneComponent == ((SceneSelection) fSceneEditor.getSelection()).getSceneComponent()
                || (fSceneEditor.getEditingMode() == EditingMode.SELECTION && fSceneEditor.getSelectionMode() == SelectionMode.MODEL))
        {
            fSceneEditor.setSelection(new PickSelection(sceneComponent, primitive, PickSelectionSource.SCENE_PICK));
        }
    }
}
