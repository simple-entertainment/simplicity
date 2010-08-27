package com.se.simplicity.editor.ui.editors;

import org.eclipse.core.resources.IMarker;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.jface.dialogs.ErrorDialog;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorPart;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.editors.text.TextEditor;
import org.eclipse.ui.ide.IDE;
import org.eclipse.ui.part.MultiPageEditorPart;

/**
 * An example showing how to create a multi-page editor. This example has 3 pages:
 * <ul>
 * <li>page 0 contains a nested text editor.
 * <li>page 1 allows you to change the font used in page 2
 * <li>page 2 shows the words in page 0 in sorted order
 * </ul>
 */
public class SceneEditor extends MultiPageEditorPart
{
    private TextEditor sourceEditor;

    private VisualSceneEditor visualEditor;

    /**
     * Creates page 0 of the multi-page editor, which contains a text editor.
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
            ErrorDialog.openError(getSite().getShell(), "Error creating nested text editor", null, e.getStatus());
        }
    }

    /**
     * Creates page 1 of the multi-page editor, which allows you to change the font used in page 2.
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
            ErrorDialog.openError(getSite().getShell(), "Error creating nested text editor", null, e.getStatus());
        }
    }

    /**
     * Creates the pages of the multi-page editor.
     */
    protected void createPages()
    {
        createVisualPage();
        createSourcePage();
    }

    /**
     * Saves the multi-page editor's document.
     */
    public void doSave(IProgressMonitor monitor)
    {
        getEditor(0).doSave(monitor);
    }

    /**
     * Saves the multi-page editor's document as another file. Also updates the text for page 0's tab, and updates this multi-page editor's input to
     * correspond to the nested editor's.
     */
    public void doSaveAs()
    {
        IEditorPart editor = getEditor(0);
        editor.doSaveAs();
        setPageText(0, editor.getTitle());
        setInput(editor.getEditorInput());
    }
    
    public VisualSceneEditor getVisualPage()
    {
        return (visualEditor);
    }

    /*
     * (non-Javadoc) Method declared on IEditorPart
     */
    public void gotoMarker(IMarker marker)
    {
        setActivePage(0);
        IDE.gotoMarker(getEditor(0), marker);
    }

    /**
     * The <code>MultiPageEditorExample</code> implementation of this method checks that the input is an instance of <code>IFileEditorInput</code>.
     */
    public void init(IEditorSite site, IEditorInput input) throws PartInitException
    {
        if (!(input instanceof IFileEditorInput))
            throw new PartInitException("Invalid Input: Must be IFileEditorInput");

        super.init(site, input);
        
        setPartName(input.getName());
    }

    /*
     * (non-Javadoc) Method declared on IEditorPart.
     */
    public boolean isSaveAsAllowed()
    {
        return true;
    }

    /**
     * Calculates the contents of page 2 when the it is activated.
     */
    protected void pageChange(int newPageIndex)
    {
        if (newPageIndex == 0)
        {
            visualEditor.update();
        }
    }
}
