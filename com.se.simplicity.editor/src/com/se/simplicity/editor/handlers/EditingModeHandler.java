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

import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.ui.editors.SceneEditor;

/**
 * <p>
 * Sets the current {@link com.se.simplicity.editor.internal.EditingMode EditingMode} in the active editor.
 * </p>
 * 
 * @author Gary Buyn
 */
public class EditingModeHandler extends AbstractHandler
{
    /**
     * Creates an instance of <code>EditModeHandler</code>.
     */
    public EditingModeHandler()
    {}

    /**
     * <p>
     * Sets the current {@link com.se.simplicity.editor.internal.EditingMode EditingMode} in the active editor.
     * </p>
     * 
     * @param event The event this handler is executing in response to.
     * 
     * @throws ExecutionException Thrown if the execution fails.
     * 
     * @return null.
     */
    public Object execute(final ExecutionEvent event) throws ExecutionException
    {
        // Check that the correct editor is active.
        IEditorPart editor = HandlerUtil.getActiveEditor(event);
        if (!(editor instanceof SceneEditor))
        {
            Logger.getLogger(getClass()).error("This handler can only be executed when a Scene Editor is active.");
            throw new ExecutionException("This handler can only be executed when a Scene Editor is active.");
        }

        // Check that the Editing Mode has changed.
        if (HandlerUtil.matchesRadioState(event))
        {
            return null;
        }

        String currentState = event.getParameter(RadioState.PARAMETER_ID);

        // Check that the change in Editing Mode is valid.
        if (!currentState.equals("SELECTION") && ((SceneEditor) editor).getSelection().isEmpty())
        {
            MessageDialog.openError(editor.getSite().getShell(), "Cannot change Editing Mode",
                    "A Model must be selected before the Editing Mode can be changed to manipulate the Model.");
            return (null);
        }

        // Change the Editing Mode in the model.
        ((SceneEditor) editor).setEditingMode(EditingMode.valueOf(currentState));

        // Update UI elements to reflect the change in Editing Mode.
        HandlerUtil.updateRadioState(event.getCommand(), currentState);

        return (null);
    }
}
