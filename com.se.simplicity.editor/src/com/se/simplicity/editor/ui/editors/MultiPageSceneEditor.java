/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import java.awt.Dimension;

import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.jface.dialogs.ErrorDialog;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.part.MultiPageEditorPart;

import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.internal.SceneManager2;
import com.se.simplicity.editor.internal.WidgetManager;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.ProjectionMode;
import com.se.simplicity.scenegraph.Node;

/**
 * A multi-page eclipse editor that displays a <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment on the first page and
 * the serialised source representation in an XML editor on the second page.
 * 
 * @author Gary Buyn
 */
public class MultiPageSceneEditor extends MultiPageEditorPart implements SceneEditor
{
    /**
     * <p>
     * The editor that displays serialised source representation of the <code>Scene</code>.
     * </p>
     */
    private SourceSceneEditor fSourceEditor;

    /**
     * <p>
     * The editor that displays the <code>Scene</code> visually on a 3D canvas using the JOGL rendering environment.
     * </p>
     */
    private VisualSceneEditor fVisualEditor;

    /**
     * <p>
     * Creates an instance of <code>SceneEditor</code>.
     * </p>
     */
    public MultiPageSceneEditor()
    {
        fSourceEditor = null;
        fVisualEditor = null;
    }

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
            fSourceEditor = new SourceSceneEditor();
            int index = addPage(fSourceEditor, getEditorInput());
            setPageText(index, "Source");
        }
        catch (PartInitException e)
        {
            ErrorDialog.openError(getSite().getShell(), "Error creating nested visual editor", null, e.getStatus());
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
            fVisualEditor = new VisualSceneEditor();
            int index = addPage(fVisualEditor, getEditorInput());
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
        fSourceEditor.doSave(monitor);
    }

    @Override
    public void doSaveAs()
    {
        fSourceEditor.doSaveAs();
    }

    @Override
    public EditingMode getEditingMode()
    {
        return (fVisualEditor.getEditingMode());
    }

    @Override
    public SceneManager2 getSceneManager()
    {
        return (fVisualEditor.getSceneManager());
    }

    @Override
    public WidgetManager getWidgetManager()
    {
        return (fVisualEditor.getWidgetManager());
    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input) throws PartInitException
    {
        super.init(site, input);

        setPartName(input.getName());
    }

    @Override
    public boolean isSaveAsAllowed()
    {
        return (fSourceEditor.isSaveAsAllowed());
    }

    @Override
    public void pickForSelection(final Dimension viewportSize, final int x, final int y, final int width, final int height)
    {
        fVisualEditor.pickForSelection(viewportSize, x, y, width, height);
    }

    @Override
    public void setCanvasSize(final Rectangle canvasSize)
    {
        fVisualEditor.setCanvasSize(canvasSize);
    }

    @Override
    public void setDrawingMode(final DrawingMode drawingMode)
    {
        fVisualEditor.setDrawingMode(drawingMode);
    }

    @Override
    public void setEditingMode(final EditingMode editingMode)
    {
        fVisualEditor.setEditingMode(editingMode);
    }

    @Override
    public void setProjectionMode(final ProjectionMode projectionMode)
    {
        fVisualEditor.setProjectionMode(projectionMode);
    }

    @Override
    public void setSelectedSceneComponent(final Node selectedSceneComponent)
    {
        fVisualEditor.setSelectedSceneComponent(selectedSceneComponent);
    }
}
