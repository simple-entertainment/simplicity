/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import org.apache.log4j.Logger;
import org.eclipse.jface.text.ITextListener;
import org.eclipse.jface.text.TextEvent;
import org.eclipse.wst.sse.core.internal.text.JobSafeStructuredDocument;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser;

/**
 * <p>
 * Listens for changes made to the text in a {@link com.se.simplicity.editor.ui.editors.SourceSceneEditor SourceSceneEditor} and updates the active
 * <code>Scene</code> to match them.
 * </p>
 * 
 * @author Gary Buyn
 */
@SuppressWarnings("restriction")
public class SourceTextListener implements ITextListener
{
    /**
     * <p>
     * Determines if this <code>SourceSceneTextListener</code> should respond to events.
     * </p>
     */
    private boolean fEnabled;

    /**
     * <p>
     * The {@link com.se.simplicity.editor.ui.editors.SourceSceneEditor SourceSceneEditor} to update the active <code>Scene</code> with.
     * </p>
     */
    private SourceSceneEditor fSourceSceneEditor;

    /**
     * <p>
     * Creates an instance of <code>SourceSceneTextListener</code>.
     * </p>
     * 
     * @param sourceSceneEditor The {@link com.se.simplicity.editor.ui.editors.SourceSceneEditor SourceSceneEditor} to update the active
     * <code>Scene</code> with.
     */
    public SourceTextListener(final SourceSceneEditor sourceSceneEditor)
    {
        fSourceSceneEditor = sourceSceneEditor;

        fEnabled = true;
    }

    /**
     * <p>
     * Stops this <code>SourceSceneTextListener</code> from responding to events.
     * </p>
     */
    public void disable()
    {
        fEnabled = false;
    }

    /**
     * <p>
     * Ensures this <code>SourceSceneTextListener</code> is responding to events.
     * </p>
     */
    public void enable()
    {
        fEnabled = true;
    }

    /**
     * <p>
     * Determines whether this <code>SourceSceneTextListener</code> is responding to events.
     * </p>
     * 
     * @return True if this <code>SourceSceneTextListener</code> is responding to events, false otherwise.
     */
    public boolean isEnabled()
    {
        return (fEnabled);
    }

    @Override
    public void textChanged(final TextEvent event)
    {
        try
        {
            SceneManager sceneManager = SceneManager.getSceneManager();
            JobSafeStructuredDocument document = (JobSafeStructuredDocument) fSourceSceneEditor.getTextViewer().getDocument();

            SceneDocumentSynchroniser synchroniser = new SceneDocumentSynchroniser();
            synchroniser.synchroniseToScene(document, sceneManager.getActiveScene());

            sceneManager.notifySceneModified(sceneManager.getActiveScene());
        }
        catch (Exception e)
        {
            Logger.getLogger(getClass()).debug("Failed to update Scene from Source.", e);
        }
    }
}
