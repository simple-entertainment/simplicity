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
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.handlers.HandlerUtil;
import org.eclipse.ui.handlers.RegistryToggleState;

import com.se.simplicity.editor.ui.editors.SceneEditor;

/**
 * <p>
 * Toggles the 'Cull Face' mode in the active editor.
 * </p>
 * 
 * @author Gary Buyn
 */
public class CullFaceModeHandler extends AbstractHandler
{
    /**
     * Creates an instance of <code>CullFaceHandler</code>.
     */
    public CullFaceModeHandler()
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

        // Change the Cull Face Mode in the model.
        ((SceneEditor) editor).setCullFaceMode(!(Boolean) event.getCommand().getState(RegistryToggleState.STATE_ID).getValue());

        // Update UI elements to reflect the change in Cull Face Mode.
        HandlerUtil.toggleCommandState(event.getCommand());

        return (null);
    }
}
