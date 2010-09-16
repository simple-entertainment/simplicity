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
import org.eclipse.jface.util.IPropertyChangeListener;
import org.eclipse.jface.util.PropertyChangeEvent;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.wst.sse.core.internal.text.BasicStructuredDocument;
import org.eclipse.wst.sse.ui.StructuredTextEditor;
import org.eclipse.wst.sse.ui.internal.actions.StructuredTextEditorActionConstants;

import com.se.simplicity.editor.internal.EditorPlugin;
import com.se.simplicity.editor.internal.util.SceneDocumentSynchroniser;
import com.se.simplicity.scene.Scene;

/**
 * <p>
 * An XML editor that synchronises itself with a {@link com.se.simplicity.scene.Scene Scene}. There are three parts to this synchronisation:
 * </p>
 * 
 * <p>
 * Firstly, it listens for {@link org.eclipse.jface.util.PropertyChangeEvent PropertyChangeEvent}s and updates its text to match the
 * <code>Scene</code> when they occur.
 * </p>
 * 
 * <p>
 * Secondly, it updates the <code>Scene</code> in response to changes made in its text.
 * </p>
 * 
 * <p>
 * Thirdly, it notifies any {@link org.eclipse.jface.util.IPropertyChangeListener IPropertyChangeListener}s registered with the
 * {@link com.se.simplicity.editor.internal.EditorPlugin EditorPlugin} in response to changes made in its text.
 * </p>
 * 
 * @author Gary Buyn
 */
@SuppressWarnings("restriction")
public class SourceSceneEditor extends StructuredTextEditor implements IPropertyChangeListener, ITextListener
{
    /**
     * <p>
     * The {@link com.se.simplicity.scene.Scene Scene} this <code>SourceSceneEditor</code> is synchronised with.
     * </p>
     */
    private Scene fScene;

    /**
     * <p>
     * Creates an instance of <code>SourceSceneEditor</code>.
     * </p>
     */
    public SourceSceneEditor()
    {
        super();

        fScene = null;
    }

    @Override
    public void createPartControl(final Composite parent)
    {
        super.createPartControl(parent);

        EditorPlugin.getInstance().addPropertyChangeListener(this);
        getTextViewer().addTextListener(this);
    }

    @Override
    public void dispose()
    {
        EditorPlugin.getInstance().removePropertyChangeListener(this);
        getTextViewer().removeTextListener(this);

        super.dispose();
    }

    @Override
    public void propertyChange(final PropertyChangeEvent event)
    {
        if (!(event.getSource() instanceof SourceSceneEditor))
        {
            updateDocument();
        }
    }

    /**
     * <p>
     * Retrieves the {@link com.se.simplicity.scene.Scene Scene} this <code>SourceSceneEditor</code> is synchronised with.
     * </p>
     * 
     * @param scene The <code>Scene</code> this <code>SourceSceneEditor</code> is synchronised with.
     */
    public void setScene(final Scene scene)
    {
        fScene = scene;
    }

    @Override
    public void textChanged(final TextEvent event)
    {
        updateScene();
    }

    /**
     * <p>
     * Updates the text in this <code>SourceSceneEditor</code> to match the {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     */
    public void updateDocument()
    {
        getTextViewer().removeTextListener(this);

        SceneDocumentSynchroniser synchroniser = new SceneDocumentSynchroniser();
        synchroniser.synchroniseToDocument(fScene, (BasicStructuredDocument) getTextViewer().getDocument());

        getTextViewer().addTextListener(this);

        getAction(StructuredTextEditorActionConstants.ACTION_NAME_FORMAT_DOCUMENT).run();
    }

    /**
     * <p>
     * Updates the {@link com.se.simplicity.scene.Scene Scene} to match the text in this <code>SourceSceneEditor</code>.
     * </p>
     */
    public void updateScene()
    {
        try
        {
            SceneDocumentSynchroniser synchroniser = new SceneDocumentSynchroniser();
            synchroniser.synchroniseToScene((BasicStructuredDocument) getTextViewer().getDocument(), fScene);

            EditorPlugin.getInstance().propertyChanged(new PropertyChangeEvent(this, "scene", null, fScene));
        }
        catch (Exception e)
        {
            Logger.getLogger(getClass()).debug("Failed to update Scene from Source.", e);
        }
    }
}
