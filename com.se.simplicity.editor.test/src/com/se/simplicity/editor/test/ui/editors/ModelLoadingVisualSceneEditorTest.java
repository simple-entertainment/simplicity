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
import static org.junit.Assert.assertTrue;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.ModelLoadingVisualSceneEditor;
import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.ModelLoadingVisualSceneEditor ModelLoadingVisualSceneEditor}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ModelLoadingVisualSceneEditorTest
{
    /**
     * An instance of the class being unit tested.
     */
    private ModelLoadingVisualSceneEditor testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new ModelLoadingVisualSceneEditor();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.SceneLoadingVisualSceneEditor#loadScene(IEditorInput) loadScene(IEditorInput)}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void loadScene() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangleModelOnly.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangleModelOnly.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        // Perform test.
        testObject.init(mockSite, mockInput);

        // Verify test results.
        assertEquals(0, testObject.getScene().getCameras().size(), 0);
        assertEquals(0, testObject.getScene().getLights().size(), 0);
        assertEquals(1, testObject.getScene().getSceneGraph().getSubgraphRoots().size(), 0);
        assertTrue(testObject.getScene().getSceneGraph().getSubgraphRoots().get(0) instanceof ModelNode);
        assertNotNull(((ModelNode) testObject.getScene().getSceneGraph().getSubgraphRoots().get(0)).getModel());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.SceneLoadingVisualSceneEditor#loadScene(IEditorInput) loadScene(IEditorInput)}
     * with the special condition that the source file is invalid.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void loadSceneInvalidFile() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangleModelOnlyMalformed.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(
                new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangleModelOnlyMalformed.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        try
        {
            // Perform test.
            testObject.init(mockSite, mockInput);
        }
        catch (PartInitException e)
        {
            // Verify test results.
            assertEquals("Failed to load Scene from file 'EasyMock for interface org.eclipse.core.runtime.IPath'.", e.getMessage());
        }
    }
}
