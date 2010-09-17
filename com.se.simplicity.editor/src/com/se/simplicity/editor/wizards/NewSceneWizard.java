/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.wizards;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.InvocationTargetException;

import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IFile;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.IWorkspaceRoot;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Path;
import org.eclipse.core.runtime.Status;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.operation.IRunnableWithProgress;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.wizard.Wizard;
import org.eclipse.ui.INewWizard;
import org.eclipse.ui.IWorkbench;
import org.eclipse.ui.IWorkbenchPage;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.ide.IDE;

/**
 * <p>
 * A wizard that creates a file containing the serialised source representation of an empty {@link com.se.simplicity.scene.Scene Scene}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NewSceneWizard extends Wizard implements INewWizard
{
    /**
     * <p>
     * The main page of the wizard.
     * </p>
     */
    private NewSceneWizardPage fPage;

    /**
     * <p>
     * The selected resource (where the new {@link com.se.simplicity.scene.Scene Scene} will be created by default).
     * </p>
     */
    private ISelection fSelection;

    /**
     * <p>
     * Creates an instance of <code>NewSceneWizard</code>.
     * </p>
     */
    public NewSceneWizard()
    {
        super();
        setNeedsProgressMonitor(true);
    }

    @Override
    public void addPages()
    {
        fPage = new NewSceneWizardPage(fSelection);
        addPage(fPage);
    }

    /**
     * The worker method. It will find the container, create the file if missing or just replace its contents, and open the editor on the newly
     * created file.
     * 
     * @param containerName The name of the container.
     * @param fileName The name of the file.
     * @param monitor A progress monitor.
     * 
     * @throws CoreException Thrown if the given container does not exist.
     */
    private void doFinish(final String containerName, final String fileName, final IProgressMonitor monitor) throws CoreException
    {
        // create a sample file
        monitor.beginTask("Creating " + fileName, 2);
        IWorkspaceRoot root = ResourcesPlugin.getWorkspace().getRoot();
        IResource resource = root.findMember(new Path(containerName));
        if (!resource.exists() || !(resource instanceof IContainer))
        {
            throwCoreException("Container \"" + containerName + "\" does not exist.");
        }
        IContainer container = (IContainer) resource;
        final IFile file = container.getFile(new Path(fileName));
        try
        {
            InputStream stream = getEmptySceneSource();
            if (file.exists())
            {
                file.setContents(stream, true, true, monitor);
            }
            else
            {
                file.create(stream, true, monitor);
            }
            stream.close();
        }
        catch (IOException e)
        {}
        monitor.worked(1);
        monitor.setTaskName("Opening file for editing...");
        getShell().getDisplay().asyncExec(new Runnable()
        {
            public void run()
            {
                IWorkbenchPage page = PlatformUI.getWorkbench().getActiveWorkbenchWindow().getActivePage();
                try
                {
                    IDE.openEditor(page, file, true);
                }
                catch (PartInitException e)
                {}
            }
        });
        monitor.worked(1);
    }

    /**
     * <p>
     * Retrieves the serialised source representation an empty {@link com.se.simplicity.scene.Scene Scene}.
     * </p>
     * 
     * @return The serialised source representation an empty {@link com.se.simplicity.scene.Scene Scene}.
     */
    private InputStream getEmptySceneSource()
    {
        String contents = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n" + "<simplicity>\n" + "\t<scene>\n" + "\t\t<sceneGraph>\n"
                + "\t\t\t<node name=\"Internally Managed Node(s)\">\n" + "\t\t\t</node>\n" + "\t\t</sceneGraph>\n" + "\t</scene>\n"
                + "</simplicity>\n";
        return new ByteArrayInputStream(contents.getBytes());
    }

    @Override
    public void init(final IWorkbench workbench, final IStructuredSelection selection)
    {
        this.fSelection = selection;
    }

    @Override
    public boolean performFinish()
    {
        final String containerName = fPage.getContainerName();
        final String fileName = fPage.getFileName();
        IRunnableWithProgress op = new IRunnableWithProgress()
        {
            public void run(final IProgressMonitor monitor) throws InvocationTargetException
            {
                try
                {
                    doFinish(containerName, fileName, monitor);
                }
                catch (CoreException e)
                {
                    throw new InvocationTargetException(e);
                }
                finally
                {
                    monitor.done();
                }
            }
        };
        try
        {
            getContainer().run(true, false, op);
        }
        catch (InterruptedException e)
        {
            return false;
        }
        catch (InvocationTargetException e)
        {
            Throwable realException = e.getTargetException();
            MessageDialog.openError(getShell(), "Error", realException.getMessage());
            return false;
        }
        return true;
    }

    /**
     * <p>
     * Throws a {@link org.eclipse.core.runtime.CoreException CoreException} with a relevant status.
     * </p>
     * 
     * @param message The message to include in the status.
     * 
     * @throws CoreException A <code>CoreException</code> with a relevant status..
     */
    private void throwCoreException(final String message) throws CoreException
    {
        IStatus status = new Status(IStatus.ERROR, "com.se.simplicity.editor", IStatus.OK, message, null);
        throw new CoreException(status);
    }
}
