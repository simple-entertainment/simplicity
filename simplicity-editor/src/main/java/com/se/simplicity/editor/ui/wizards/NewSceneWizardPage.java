/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.wizards;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.Path;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.WizardPage;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.ModifyEvent;
import org.eclipse.swt.events.ModifyListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Text;
import org.eclipse.ui.dialogs.ContainerSelectionDialog;

/**
 * <p>
 * The main page of a wizard that creates a file containing the serialised source representation of an empty {@link com.se.simplicity.scene.Scene
 * Scene}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NewSceneWizardPage extends WizardPage
{
    /**
     * <p>
     * A text box for the container the {@link com.se.simplicity.scene.Scene Scene} will be created in.
     * </p>
     */
    private Text fContainerText;

    /**
     * <p>
     * A text box for the file the {@link com.se.simplicity.scene.Scene Scene} will be created in.
     * </p>
     */
    private Text fFileText;

    /**
     * <p>
     * The selected resource (where the new {@link com.se.simplicity.scene.Scene Scene} will be created by default).
     * </p>
     */
    private ISelection fSelection;

    /**
     * Creates an instance of <code>NewSceneWizardPage</code>.
     * 
     * @param selection The selected resource (where the new {@link com.se.simplicity.scene.Scene Scene} will be created by default).
     */
    public NewSceneWizardPage(final ISelection selection)
    {
        super("wizardPage");
        setTitle("Scene");
        setDescription("This wizard creates an empty Scene.");
        this.fSelection = selection;
    }

    @Override
    public void createControl(final Composite parent)
    {
        Composite container = new Composite(parent, SWT.NULL);
        GridLayout layout = new GridLayout();
        container.setLayout(layout);
        layout.numColumns = 3;
        layout.verticalSpacing = 9;
        Label label = new Label(container, SWT.NULL);
        label.setText("&Container:");

        fContainerText = new Text(container, SWT.BORDER | SWT.SINGLE);
        GridData gd = new GridData(GridData.FILL_HORIZONTAL);
        fContainerText.setLayoutData(gd);
        fContainerText.addModifyListener(new ModifyListener()
        {
            public void modifyText(final ModifyEvent e)
            {
                dialogChanged();
            }
        });

        Button button = new Button(container, SWT.PUSH);
        button.setText("Browse...");
        button.addSelectionListener(new SelectionAdapter()
        {
            public void widgetSelected(final SelectionEvent e)
            {
                handleBrowse();
            }
        });
        label = new Label(container, SWT.NULL);
        label.setText("&File name:");

        fFileText = new Text(container, SWT.BORDER | SWT.SINGLE);
        gd = new GridData(GridData.FILL_HORIZONTAL);
        fFileText.setLayoutData(gd);
        fFileText.addModifyListener(new ModifyListener()
        {
            public void modifyText(final ModifyEvent e)
            {
                dialogChanged();
            }
        });
        initialize();
        dialogChanged();
        setControl(container);
    }

    /**
     * Tests if the current workbench selection is a suitable container to use.
     */

    private void initialize()
    {
        if (fSelection != null && !fSelection.isEmpty() && fSelection instanceof IStructuredSelection)
        {
            IStructuredSelection ssel = (IStructuredSelection) fSelection;
            if (ssel.size() > 1)
            {
                return;
            }
            Object obj = ssel.getFirstElement();
            if (obj instanceof IResource)
            {
                IContainer container;
                if (obj instanceof IContainer)
                {
                    container = (IContainer) obj;
                }
                else
                {
                    container = ((IResource) obj).getParent();
                }
                fContainerText.setText(container.getFullPath().toString());
            }
        }
        fFileText.setText("new_scene.sss");
    }

    /**
     * Uses the standard container selection dialog to choose the new value for the container field.
     */

    private void handleBrowse()
    {
        ContainerSelectionDialog dialog = new ContainerSelectionDialog(getShell(), ResourcesPlugin.getWorkspace().getRoot(), false,
                "Select new file container");
        if (dialog.open() == ContainerSelectionDialog.OK)
        {
            Object[] result = dialog.getResult();
            if (result.length == 1)
            {
                fContainerText.setText(((Path) result[0]).toString());
            }
        }
    }

    /**
     * Ensures that both text fields are set.
     */

    private void dialogChanged()
    {
        IResource container = ResourcesPlugin.getWorkspace().getRoot().findMember(new Path(getContainerName()));
        String fileName = getFileName();

        if (getContainerName().length() == 0)
        {
            updateStatus("File container must be specified");
            return;
        }
        if (container == null || (container.getType() & (IResource.PROJECT | IResource.FOLDER)) == 0)
        {
            updateStatus("File container must exist");
            return;
        }
        if (!container.isAccessible())
        {
            updateStatus("Project must be writable");
            return;
        }
        if (fileName.length() == 0)
        {
            updateStatus("File name must be specified");
            return;
        }
        if (fileName.replace('\\', '/').indexOf('/', 1) > 0)
        {
            updateStatus("File name must be valid");
            return;
        }
        int dotLoc = fileName.lastIndexOf('.');
        if (dotLoc != -1)
        {
            String ext = fileName.substring(dotLoc + 1);
            if (!ext.equalsIgnoreCase("sss"))
            {
                updateStatus("File extension must be \"sss\"");
                return;
            }
        }
        updateStatus(null);
    }

    /**
     * <p>
     * Updates the wizard's status with the given message.
     * </p>
     * 
     * @param message The message to update the wizard's status with.
     */
    private void updateStatus(final String message)
    {
        setErrorMessage(message);
        setPageComplete(message == null);
    }

    /**
     * <p>
     * Retrieves the text box for the container the {@link com.se.simplicity.scene.Scene Scene} will be created in.
     * </p>
     * 
     * @return The text box for the container the {@link com.se.simplicity.scene.Scene Scene} will be created in.
     */
    public String getContainerName()
    {
        return fContainerText.getText();
    }

    /**
     * <p>
     * Retrieves the text box for the file the {@link com.se.simplicity.scene.Scene Scene} will be created in.
     * </p>
     * 
     * @return The text box for the file the {@link com.se.simplicity.scene.Scene Scene} will be created in.
     */
    public String getFileName()
    {
        return fFileText.getText();
    }
}
