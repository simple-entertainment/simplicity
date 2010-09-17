/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.wizards;

import org.eclipse.core.resources.IFile;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.IImportWizard;
import org.eclipse.ui.IWorkbench;

/**
 * <p>
 * A wizard that imports {@link com.se.simplicity.model.Model Model}s from various standard model file formats.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ModelImportWizard extends Wizard implements IImportWizard
{
    /**
     * <p>
     * The main page of the wizard.
     * </p>
     */
    private ModelImportWizardPage mainPage;

    /**
     * <p>
     * Creates an instance of <code>ModelImportWizard</code>.
     * </p>
     */
    public ModelImportWizard()
    {
        super();
    }

    @Override
    public void addPages()
    {
        super.addPages();
        addPage(mainPage);
    }

    @Override
    public void init(final IWorkbench workbench, final IStructuredSelection selection)
    {
        setWindowTitle("Model Import Wizard");
        setNeedsProgressMonitor(true);
        mainPage = new ModelImportWizardPage("Import Model", selection);
    }

    @Override
    public boolean performFinish()
    {
        IFile file = mainPage.createNewFile();
        if (file == null)
        {
            return false;
        }

        return true;
    }
}
