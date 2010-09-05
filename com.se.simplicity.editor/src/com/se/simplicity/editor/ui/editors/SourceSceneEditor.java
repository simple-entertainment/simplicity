/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.wst.sse.core.internal.text.BasicStructuredDocument;
import org.eclipse.wst.sse.ui.StructuredTextEditor;
import org.eclipse.wst.sse.ui.internal.actions.StructuredTextEditorActionConstants;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser;

/**
 * <p>
 * An XML editor that dynamically updates its text to match changes to the active <code>Scene</code> made externally of this editor. Also updates the
 * active <code>Scene</code> in response to changes made internally.
 * </p>
 * 
 * @author Gary Buyn
 */
@SuppressWarnings("restriction")
public class SourceSceneEditor extends StructuredTextEditor implements SceneChangedListener
{
    /**
     * <p>
     * Listens for changes in the text of this <code>SourceSceneEditor</code>.
     * </p>
     */
    private SourceSceneTextListener fSourceSceneTextListener;

    /**
     * <p>
     * Creates an instance of <code>SourceSceneEditor</code>.
     * </p>
     */
    public SourceSceneEditor()
    {
        super();

        fSourceSceneTextListener = new SourceSceneTextListener(this);

        SceneManager.getSceneManager().addSceneChangedListener(this);
    }

    @Override
    public void createPartControl(final Composite parent)
    {
        super.createPartControl(parent);

        getTextViewer().addTextListener(fSourceSceneTextListener);
    }

    @Override
    public void dispose()
    {
        SceneManager.getSceneManager().removeSceneChangedListener(this);
        getTextViewer().removeTextListener(fSourceSceneTextListener);

        super.dispose();
    }

    @Override
    public void sceneChanged(final SceneChangedEvent event)
    {
        // If any scene components were modified.
        if (event.getType() == SceneChangedEventType.CAMERA_MODIFIED || event.getType() == SceneChangedEventType.LIGHT_MODIFIED
                || event.getType() == SceneChangedEventType.NODE_MODIFIED)
        {
            fSourceSceneTextListener.disable();

            SceneDocumentSynchroniser synchroniser = new SceneDocumentSynchroniser();
            synchroniser.synchroniseToDocument(SceneManager.getSceneManager().getActiveScene(), (BasicStructuredDocument) getTextViewer()
                    .getDocument());

            fSourceSceneTextListener.enable();

            getAction(StructuredTextEditorActionConstants.ACTION_NAME_FORMAT_DOCUMENT).run();
        }
    }
}
