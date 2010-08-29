/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.editors;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.internal.SceneManager;
import com.se.simplicity.editor.ui.editors.VisualSceneEditor;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor VisualSceneEditor}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneEditorTest
{
    /**
     * An instance of the class being unit tested.
     */
    private VisualSceneEditor testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new VisualSceneEditor();

        SceneManager.getSceneManager().reset();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#createPartControl(Composite) createPartControl(Composite)}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void createPartControl() throws FileNotFoundException, CoreException
    {
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/internal/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        testObject.init(mockSite, mockInput);

        testObject.createPartControl(new Composite(new Shell(), SWT.NONE));

        assertNotNull(testObject.getViewport().getGL());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#init(IEditorSite, IEditorInput) init(IEditorSite,
     * IEditorInput)}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void init() throws FileNotFoundException, CoreException
    {
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/internal/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        testObject.init(mockSite, mockInput);

        assertNotNull(testObject.getViewport());
        assertNotNull(SceneManager.getSceneManager().getActiveScene());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#init(IEditorSite, IEditorInput) init(IEditorSite,
     * IEditorInput)} with the special condition that the source file is invalid.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void initInvalidFile() throws FileNotFoundException, CoreException
    {
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/internal/triangleMalformed.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        try
        {
            testObject.init(mockSite, mockInput);
        }
        catch (PartInitException e)
        {
            assertEquals("Failed to load scene from file 'EasyMock for interface org.eclipse.core.runtime.IPath'.", e.getMessage());
        }
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#setFocus() setFocus()}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void setFocus() throws FileNotFoundException, CoreException
    {
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/internal/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        testObject.init(mockSite, mockInput);

        testObject.setFocus();

        assertNotNull(SceneManager.getSceneManager().getActiveScene());
    }
}
