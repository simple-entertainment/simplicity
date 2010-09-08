/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.handlers;

import java.util.List;

import org.apache.log4j.Logger;
import org.eclipse.core.commands.AbstractHandler;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.expressions.IEvaluationContext;
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.ISources;

import com.se.simplicity.editor.ui.editors.SceneEditor;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * Changes the {@link com.se.simplicity.rendering.DrawingMode DrawingMode} of the {@link com.se.simplicity.scene.Scene Scene} in the active editor to
 * <code>EDGES</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public class EdgesHandler extends AbstractHandler
{
    /**
     * Creates an instance of <code>EdgesHandler</code>.
     */
    public EdgesHandler()
    {}

    /**
     * <p>
     * Changes the {@link com.se.simplicity.rendering.DrawingMode DrawingMode} of the {@link com.se.simplicity.scene.Scene Scene} in the active editor
     * to <code>EDGES</code>.
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
        // This could be done more easily using: HandlerUtil.getActiveEditor(event); but that does not facilitate TDD...
        IEditorPart editor = (IEditorPart) ((IEvaluationContext) event.getApplicationContext()).getVariable(ISources.ACTIVE_EDITOR_NAME);
        if (!(editor instanceof SceneEditor))
        {
            Logger.getLogger(getClass()).error("This handler can only be executed when a Scene Editor is active.");
            throw new ExecutionException("This handler can only be executed when a Scene Editor is active.");
        }

        List<Renderer> renderers = ((SceneEditor) editor).getContentProvider().getRenderingEngine().getRenderers();

        renderers.get(0).setDrawingMode(DrawingMode.EDGES);
        renderers.get(1).setDrawingMode(DrawingMode.EDGES);

        return (null);
    }
}
