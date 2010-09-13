/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.editors;

import static org.easymock.EasyMock.anyObject;
import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import java.awt.Dimension;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import org.eclipse.core.resources.IFile;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.IPath;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.ISelectionChangedListener;
import org.eclipse.jface.viewers.SelectionChangedEvent;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.IWorkbenchPart;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.views.contentoutline.IContentOutlinePage;
import org.junit.Before;
import org.junit.Test;

import sun.org.mozilla.javascript.Node;

import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.internal.selection.PickSelection;
import com.se.simplicity.editor.internal.selection.PickSelectionSource;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.editor.ui.editors.VisualSceneEditor;
import com.se.simplicity.editor.ui.editors.outline.SceneOutlinePage;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;

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
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#getAdapter(Class) getAdapter(Class)}.
     * </p>
     * 
     * @throws PartInitException Thrown if the initialisation fails.
     */
    @Test
    public void getAdapter() throws PartInitException
    {
        // Perform test.
        Object adapterInstance = testObject.getAdapter(IContentOutlinePage.class);

        // Verify test results.
        assertTrue(adapterInstance instanceof SceneOutlinePage);
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
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        // Perform test.
        testObject.init(mockSite, mockInput);

        // Verify results.
        assertEquals("triangle.xml", testObject.getPartName());

        assertTrue(testObject.getSceneManager().getRenderingEngine() instanceof SimpleJOGLRenderingEngine);

        assertEquals(EditingMode.SELECTION, testObject.getEditingMode());
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
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangleMalformed.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangleMalformed.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        // Initialise test environment.
        testObject = new VisualSceneEditor();

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

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#init(IEditorSite, IEditorInput) init(IEditorSite,
     * IEditorInput)} with the special condition that the preferred RenderingEngine is invalid.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void initInvalidRenderingEngine() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(
                new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangleInvalidRenderingEngine.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        // Perform test.
        testObject.init(mockSite, mockInput);

        // Verify results.
        assertTrue(testObject.getSceneManager().getRenderingEngine() instanceof SimpleJOGLRenderingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#pickForSelection(Dimension, int, int, int, int)
     * pickForSelection(Dimension, int, int, int, int)}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void pickForSelection() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        // Initialise test environment.
        testObject.init(mockSite, mockInput);

        // Perform test.
        testObject.pickForSelection(createMock(Dimension.class), 100, 100, 2, 2);

        // Verify results.
        assertEquals(1, testObject.getSceneManager().getPickingEngine().getPicks().size(), 0);
        assertEquals(1, testObject.getWidgetManager().getPickingEngine().getPicks().size(), 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#selectionChanged(IWorkbenchPart, ISelection)
     * selectionChanged(IWorkbenchPart, ISelection)}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void selectionChanged() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        ISelectionChangedListener mockListener = createMock(ISelectionChangedListener.class);
        SceneSelection mockSelection = createMock(SceneSelection.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        expect(mockSelection.getPrimitive()).andStubReturn(null);
        replay(mockInput, mockFile, mockPath, mockSelection);

        // Initialise test environment.
        testObject.init(mockSite, mockInput);
        testObject.addSelectionChangedListener(mockListener);

        // Dictate expected results.
        replay(mockListener); // This listener should not be notified.

        // Perform test.
        testObject.selectionChanged(null, mockSelection);

        // Verify results.
        verify(mockListener);

        assertEquals(mockSelection, testObject.getSelection());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#setCanvasSize(Rectangle) setCanvasSize(Rectangle)}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void setCanvasSize() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        Dimension dimension = new Dimension(200, 200);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        // Initialise test environment.
        testObject.init(mockSite, mockInput);

        // Perform test.
        testObject.setCanvasSize(rectangle);

        // Verify results.
        assertEquals(dimension, testObject.getSceneManager().getRenderingEngine().getViewportSize());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#setEditingMode(EditingMode) setEditingMode(EditingMode)}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void setEditingMode() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        replay(mockInput, mockFile, mockPath);

        // Initialise test environment.
        testObject.init(mockSite, mockInput);

        // Perform test.
        testObject.setEditingMode(EditingMode.TRANSLATION);

        // Verify results.
        assertEquals(EditingMode.TRANSLATION, testObject.getWidgetManager().getEditingMode());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#setSelection(ISelection) setSelection(ISelection)}.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void setSelection() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        ISelectionChangedListener mockListener = createMock(ISelectionChangedListener.class);
        SceneSelection mockSelection = createMock(SceneSelection.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        expect(mockSelection.getPrimitive()).andStubReturn(null);
        replay(mockInput, mockFile, mockPath, mockSelection);

        // Initialise test environment.
        testObject.init(mockSite, mockInput);
        testObject.addSelectionChangedListener(mockListener);

        // Dictate expected results.
        mockListener.selectionChanged((SelectionChangedEvent) anyObject());
        replay(mockListener);

        // Perform test.
        testObject.setSelection(mockSelection);

        // Verify results.
        verify(mockListener);

        assertEquals(mockSelection, testObject.getSelection());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#setSelection(ISelection) setSelection(ISelection)} with the
     * special condition that the selection is a PickSelection.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void setSelectionPickSelection() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        ISelectionChangedListener mockListener = createMock(ISelectionChangedListener.class);
        PickSelection mockSelection = createMock(PickSelection.class);
        Node mockNode = createMock(Node.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        expect(mockSelection.getSource()).andStubReturn(PickSelectionSource.WIDGET_PICK);
        expect(mockSelection.isEmpty()).andReturn(false);
        expect(mockSelection.getSceneComponent()).andStubReturn(mockNode);
        replay(mockInput, mockFile, mockPath, mockSelection);

        // Initialise test environment.
        testObject.init(mockSite, mockInput);
        testObject.addSelectionChangedListener(mockListener);

        // Dictate expected results.
        mockListener.selectionChanged((SelectionChangedEvent) anyObject());
        replay(mockListener);

        // Perform test.
        testObject.setSelection(mockSelection);

        // Verify results.
        verify(mockListener);

        assertEquals(mockNode, ((SceneSelection) testObject.getSelection()).getSceneComponent());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneEditor#setSelection(ISelection) setSelection(ISelection)} with the
     * special condition that the selection is an empty PickSelection sourced from a Widget pick.
     * </p>
     * 
     * @throws CoreException Thrown if the contents of the source file fail to be retrieved.
     * @throws FileNotFoundException Thrown if the source file cannot be found.
     */
    @Test
    public void setSelectionPickSelectionWidgetEmpty() throws FileNotFoundException, CoreException
    {
        // Create dependencies.
        IEditorSite mockSite = createMock(IEditorSite.class);
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);
        IFile mockFile = createMock(IFile.class);
        IPath mockPath = createMock(IPath.class);

        ISelectionChangedListener mockListener = createMock(ISelectionChangedListener.class);
        PickSelection mockSelection = createMock(PickSelection.class);

        // Dictate correct behaviour.
        expect(mockInput.getName()).andStubReturn("triangle.xml");
        expect(mockInput.getFile()).andStubReturn(mockFile);
        expect(mockFile.getContents()).andStubReturn(new FileInputStream("src/com/se/simplicity/editor/test/ui/editors/triangle.xml"));
        expect(mockFile.getFullPath()).andStubReturn(mockPath);
        mockPath.toString();
        expect(mockSelection.getSource()).andStubReturn(PickSelectionSource.WIDGET_PICK);
        expect(mockSelection.isEmpty()).andReturn(true);
        replay(mockInput, mockFile, mockPath, mockSelection);

        // Initialise test environment.
        testObject.init(mockSite, mockInput);
        testObject.addSelectionChangedListener(mockListener);
        ISelection beforeSelection = testObject.getSelection();

        // Dictate expected results.
        replay(mockListener); // This listener should not be notified.

        // Perform test.
        testObject.setSelection(mockSelection);

        // Verify results.
        verify(mockListener);

        assertEquals(beforeSelection, testObject.getSelection());
    }
}
