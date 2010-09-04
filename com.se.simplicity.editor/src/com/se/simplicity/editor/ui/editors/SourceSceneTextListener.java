package com.se.simplicity.editor.ui.editors;

import java.io.ByteArrayInputStream;

import org.apache.log4j.Logger;
import org.eclipse.jface.text.ITextListener;
import org.eclipse.jface.text.TextEvent;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.wst.sse.core.internal.text.JobSafeStructuredDocument;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.util.scene.SceneFactory;

/**
 * <p>
 * Listens for changes made to the text in a {@link com.se.simplicity.editor.ui.editors.SourceSceneEditor SourceSceneEditor} and updates the active
 * <code>Scene</code> to match them.
 * </p>
 * 
 * @author Gary Buyn
 */
@SuppressWarnings("restriction")
public class SourceSceneTextListener implements ITextListener
{
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
    public SourceSceneTextListener(final SourceSceneEditor sourceSceneEditor)
    {
        fSourceSceneEditor = sourceSceneEditor;
    }

    @Override
    public void textChanged(final TextEvent event)
    {
        IFileEditorInput input = (IFileEditorInput) fSourceSceneEditor.getEditorInput();
        JobSafeStructuredDocument document = (JobSafeStructuredDocument) fSourceSceneEditor.getTextViewer().getDocument();

        try
        {
            SceneFactory.updateFromSource(SceneManager.getSceneManager().getActiveScene(), new ByteArrayInputStream(document.getText().getBytes()));
            SceneManager.getSceneManager().notifySceneModified(input.getFile().getFullPath().toString());
        }
        catch (Exception e)
        {
            Logger.getLogger(getClass()).debug("Failed to update Scene from Source.", e);
        }
    }
}
