package com.se.simplicity.editor.ui.editors;

import java.io.ByteArrayOutputStream;

import org.apache.log4j.Logger;
import org.eclipse.jface.text.BadLocationException;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.wst.sse.core.internal.provisional.text.IStructuredDocumentRegion;
import org.eclipse.wst.sse.core.internal.text.JobSafeStructuredDocument;
import org.eclipse.wst.sse.ui.StructuredTextEditor;

import com.se.simplicity.editor.internal.SceneChangedEvent;
import com.se.simplicity.editor.internal.SceneChangedEventType;
import com.se.simplicity.editor.internal.SceneChangedListener;
import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.util.scene.SceneFactory;

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
     * Listens for changes in the text in this <code>SourceSceneEditor</code>.
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
            String[] sceneLines = getSceneLines();
            IStructuredDocumentRegion[] sourceRegions = getSourceRegions();

            // For every XML tag in the updated serialised source representation.
            for (int index = 0; index < sceneLines.length; index++)
            {
                // If the corresponding XML tag in the text in this SourceSceneEditor does not match.
                if (!sceneLines[index].replaceAll("\\s", "").equals(sourceRegions[index].getText().replaceAll("\\s", "")))
                {
                    try
                    {
                        // Update the text in this SourceSceneEditor.
                        getTextViewer().getDocument().replace(sourceRegions[index].getStart(), sourceRegions[index].getLength(), sceneLines[index]);
                    }
                    catch (BadLocationException e)
                    {
                        Logger.getLogger(getClass()).error("Failed to update Source.", e);
                    }
                }
            }
        }
    }

    /**
     * <p>
     * Retrieves the XML tags from the updated serialised source representation as <code>String</code>s.
     * </p>
     * 
     * @return The XML tags from the updated serialised source representation as <code>String</code>s.
     */
    protected String[] getSceneLines()
    {
        ByteArrayOutputStream source = new ByteArrayOutputStream();
        SceneFactory.writeToSource(SceneManager.getSceneManager().getActiveScene(), source);

        String[] sceneLines = source.toString().replaceAll(">", ">\n").split("\n");

        return (sceneLines);
    }

    /**
     * <p>
     * Retrieves the regions from the text in this <code>SourceSceneEditor</code> that contain XML tags.
     * </p>
     * 
     * @return The regions from the text in this <code>SourceSceneEditor</code> that contain XML tags.
     */
    protected IStructuredDocumentRegion[] getSourceRegions()
    {
        IStructuredDocumentRegion[] sourceRegions = ((JobSafeStructuredDocument) getTextViewer().getDocument()).getStructuredDocumentRegions();
        IStructuredDocumentRegion[] nonEmptySourceRegions = new IStructuredDocumentRegion[sourceRegions.length / 2 + 1];

        for (int index = 0; index < nonEmptySourceRegions.length; index++)
        {
            nonEmptySourceRegions[index] = sourceRegions[index * 2];
        }

        return (nonEmptySourceRegions);
    }
}
