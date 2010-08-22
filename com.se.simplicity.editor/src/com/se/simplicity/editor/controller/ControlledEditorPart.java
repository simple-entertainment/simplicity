/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.controller;

import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.part.EditorPart;

import com.se.simplicity.editor.Editor;

public class ControlledEditorPart extends EditorPart
{
    private EditorPartController controller;

    private String controllerName;

    public ControlledEditorPart(String controllerName)
    {
        this.controllerName = controllerName;
    }

    @Override
    public void createPartControl(Composite parent)
    {
        controller.init(parent);
    }

    @Override
    public void doSave(IProgressMonitor monitor)
    {
    // TODO Auto-generated method stub

    }

    @Override
    public void doSaveAs()
    {
    // TODO Auto-generated method stub

    }

    public EditorPartController getController()
    {
        return (controller);
    }

    @Override
    public void init(final IEditorSite site, final IEditorInput input) throws PartInitException
    {
        setSite(site);
        setInput(input);
                
        controller = (EditorPartController) Editor.editor.getController(controllerName);
        controller.init(site, input);
    }

    @Override
    public boolean isDirty()
    {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public boolean isSaveAsAllowed()
    {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void setFocus()
    {
        controller.setFocus();
    }
}
