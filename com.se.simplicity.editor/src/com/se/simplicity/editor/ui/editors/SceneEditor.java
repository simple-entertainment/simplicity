/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.jface.dialogs.ErrorDialog;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.editors.text.TextEditor;
import org.eclipse.ui.part.MultiPageEditorPart;

/**
 * A multi-page eclipse editor that displays a <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment on the first page and
 * the serialised source representation in an XML editor on the second page.
 * 
 * @author Gary Buyn
 */
public class SceneEditor extends MultiPageEditorPart
{
    /**
     * <p>
     * The XML editor that displays the serialised source representation of the <code>Scene</code>.
     * </p>
     */
    private TextEditor sourceEditor;

    /**
     * <p>
     * The editor that displays the <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment.
     * </p>
     */
    private VisualSceneEditor visualEditor;

    @Override
    protected void createPages()
    {
        createVisualPage();
        createSourcePage();
    }

    /**
     * <p>
     * Adds the source editor to the next available page within this multi-page editor.
     * </p>
     */
    public void createSourcePage()
    {
        try
        {
            sourceEditor = new TextEditor();
            int index = addPage(sourceEditor, getEditorInput());
            setPageText(index, "Source");
        }
        catch (PartInitException e)
        {
            ErrorDialog.openError(getSite().getShell(), "Error creating nested source editor", null, e.getStatus());
        }
    }

    /**
     * <p>
     * Adds the visual editor to the next available page within this multi-page editor.
     * </p>
     */
    public void createVisualPage()
    {
        try
        {
            visualEditor = new VisualSceneEditor();
            int index = addPage(visualEditor, getEditorInput());
            setPageText(index, "Visual");
        }
        catch (PartInitException e)
        {
            ErrorDialog.openError(getSite().getShell(), "Error creating nested visual editor", null, e.getStatus());
        }
    }

    @Override
    public void doSave(final IProgressMonitor monitor)
    {
        getEditor(0).doSave(monitor);
    }

    @Override
    public void doSaveAs()
    {
        IEditorPart editor = getEditor(0);
        editor.doSaveAs();
        setPageText(0, editor.getTitle());
        setInput(editor.getEditorInput());
    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input) throws PartInitException
    {
        if (!(input instanceof IFileEditorInput))
        {
            throw new PartInitException("Invalid Input: Must be IFileEditorInput");
        }

        super.init(site, input);

        setPartName(input.getName());
    }

    @Override
    public boolean isSaveAsAllowed()
    {
        return (false);
    }

    @Override
    protected void pageChange(final int newPageIndex)
    {
//        if (isDirtySinceLastPageChange)
//        {
//            if (newPageIndex == 0)
//            {
//                SceneFactory.updateFromSource(SceneManager.getSceneManager().getScene(id), ((IFileEditorInput) getEditorInput()).getFile()
//                        .getContents());
//            }
//
//            SceneManager.getSceneManager().notifySceneModified(id);
//
//            isDirtySinceLastPageChange = false;
//        }
    }
}
