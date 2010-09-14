/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.handlers;

import org.apache.log4j.Logger;
import org.eclipse.core.commands.AbstractHandler;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.handlers.HandlerUtil;
import org.eclipse.ui.handlers.RadioState;

import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.editor.ui.editors.SceneEditor;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * Sets the current {@link com.se.simplicity.editor.internal.SelectionMode SelectionMode} in the active editor.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SelectionModeHandler extends AbstractHandler
{
    /**
     * Creates an instance of <code>SelectionModeHandler</code>.
     */
    public SelectionModeHandler()
    {}

    @Override
    public Object execute(final ExecutionEvent event) throws ExecutionException
    {
        // Check that the correct editor is active.
        IEditorPart editor = HandlerUtil.getActiveEditor(event);
        if (!(editor instanceof SceneEditor))
        {
            Logger.getLogger(getClass()).error("This handler can only be executed when a Scene Editor is active.");
            throw new ExecutionException("This handler can only be executed when a Scene Editor is active.");
        }

        // Check that the Selection Mode has changed.
        if (HandlerUtil.matchesRadioState(event))
        {
            return (null);
        }

        String currentState = event.getParameter(RadioState.PARAMETER_ID);

        // Check that the change in Selection Mode is valid.
        SceneSelection selection = (SceneSelection) ((SceneEditor) editor).getSelection();
        if (!currentState.equals("model") && (selection.isEmpty() || !(selection.getSceneComponent() instanceof ModelNode)))
        {
            MessageDialog.openError(editor.getSite().getShell(), "Cannot change Selection Mode",
                    "A Model must be selected before the Selection Mode can be changed to select sub-components of a Model.");
            return (null);
        }

        // Change the Selection Mode in the model.
//        if (currentState.equals("edges"))
//        {
//            ((SceneEditor) editor).setSelectionMode(SelectionMode.EDGES);
//        }
//        else if (currentState.equals("faces"))
//        {
//            ((SceneEditor) editor).setSelectionMode(SelectionMode.FACES);
//        }
//        else if (currentState.equals("model"))
//        {
//            ((SceneEditor) editor).setSelectionMode(SelectionMode.MODEL);
//        }
//        else if (currentState.equals("vertices"))
//        {
//            ((SceneEditor) editor).setSelectionMode(SelectionMode.VERTICES);
//        }

        // Update UI elements to reflect the change in Selection Mode.
        HandlerUtil.updateRadioState(event.getCommand(), currentState);

        return (null);
    }
}
