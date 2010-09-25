/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.wizards;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Status;
import org.eclipse.jface.preference.FileFieldEditor;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.dialogs.WizardNewFileCreationPage;

import com.se.simplicity.model.Model;
import com.se.simplicity.util.model.ModelFactory;

/**
 * <p>
 * The main page of a wizard that imports {@link com.se.simplicity.model.Model Model}s from various standard model file formats.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ModelImportWizardPage extends WizardNewFileCreationPage
{
    /**
     * <p>
     * The editor used to select the file to import the {@link com.se.simplicity.model.Model Model} from.
     * </p>
     */
    private FileFieldEditor editor;

    /**
     * <p>
     * Creates an instance of <code>ModelImportWizardPage</code>.
     * </p>
     * 
     * @param pageName The name of this page (shown in the title).
     * @param selection The currently selected resource.
     */
    public ModelImportWizardPage(final String pageName, final IStructuredSelection selection)
    {
        super(pageName, selection);
        setTitle(pageName);
        setDescription("Import a Model in an external format.");
    }

    @Override
    protected void createAdvancedControls(final Composite parent)
    {
        Composite fileSelectionArea = new Composite(parent, SWT.NONE);
        GridData fileSelectionData = new GridData(GridData.GRAB_HORIZONTAL | GridData.FILL_HORIZONTAL);
        fileSelectionArea.setLayoutData(fileSelectionData);

        GridLayout fileSelectionLayout = new GridLayout();
        fileSelectionLayout.numColumns = 3;
        fileSelectionLayout.makeColumnsEqualWidth = false;
        fileSelectionLayout.marginWidth = 0;
        fileSelectionLayout.marginHeight = 0;
        fileSelectionArea.setLayout(fileSelectionLayout);

        editor = new FileFieldEditor("fileSelect", "Select File: ", fileSelectionArea);
        editor.getTextControl(fileSelectionArea).addModifyListener(new ModifyListener()
        {
            public void modifyText(final ModifyEvent e)
            {
                IPath path = new Path(ModelImportWizardPage.this.editor.getStringValue());
                setFileName(path.removeFileExtension().lastSegment() + ".sms");
            }
        });
        String[] extensions = new String[] {"*.obj"};
        editor.setFileExtensions(extensions);
        fileSelectionArea.moveAbove(null);

    }

    @Override
    protected void createLinkTarget()
    {}

    @Override
    protected InputStream getInitialContents()
    {
        try
        {
            Model model = ModelFactory.loadFromOBJ(new FileInputStream(editor.getStringValue()));

            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            ModelFactory.writeToSource(model, outputStream);
            ByteArrayInputStream inputStream = new ByteArrayInputStream(outputStream.toByteArray());

            return (inputStream);
        }
        catch (FileNotFoundException e)
        {
            return null;
        }
    }

    @Override
    protected String getNewFileLabel()
    {
        return "New Model Name:";
    }

    @Override
    protected IStatus validateLinkedResource()
    {
        return new Status(IStatus.OK, "com.se.simplicity.editor", IStatus.OK, "", null);
    }
}
