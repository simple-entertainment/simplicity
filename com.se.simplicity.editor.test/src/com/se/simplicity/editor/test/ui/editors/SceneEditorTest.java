/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.editors;

import static org.easymock.EasyMock.createMock;
import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.replay;
import static org.junit.Assert.assertEquals;

import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.IFileEditorInput;
import org.eclipse.ui.PartInitException;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.SceneEditor;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.SceneEditor SceneEditor}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneEditorTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneEditor testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SceneEditor();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.SceneEditor#init(IEditorSite, IEditorInput) init(IEditorSite, IEditorInput)}.
     * </p>
     * 
     * @throws PartInitException Thrown if the initialisation fails.
     */
    @Test
    public void init() throws PartInitException
    {
        IFileEditorInput mockInput = createMock(IFileEditorInput.class);

        expect(mockInput.getName()).andStubReturn("test");
        replay(mockInput);

        testObject.init(createMock(IEditorSite.class), mockInput);

        assertEquals("test", testObject.getPartName());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.SceneEditor#init(IEditorSite, IEditorInput) init(IEditorSite, IEditorInput)}
     * with the special condition that the input provided is not of the type <code>IFileEditorInput</code>.
     * </p>
     */
    @Test
    public void initNotIFileEditorInput()
    {
        try
        {
            testObject.init(createMock(IEditorSite.class), createMock(IEditorInput.class));
        }
        catch (PartInitException e)
        {
            assertEquals("Invalid Input: Must be IFileEditorInput", e.getMessage());
        }
    }
}
