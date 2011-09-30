/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.editors.outline;

import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.outline.SceneLabelProvider;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.scenegraph.SimpleNode;
import com.se.simplicity.util.metadata.MetaData;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.outline.SceneLabelProvider SceneLabelProvider}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneLabelProviderTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneLabelProvider testObject;

    /**
     * <p>
     * Setup to perform before each unit test.
     * </p>
     */
    @Before
    public void before()
    {
        testObject = new SceneLabelProvider();
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneLabelProvider#getText(Object) getText(Object)}.
     * </p>
     */
    @Test
    public void getText()
    {
        // Create dependencies.
        SimpleJOGLCamera camera = new SimpleJOGLCamera();

        // Perform test.
        String text = testObject.getText(camera);

        // Verify results.
        assertEquals("SimpleJOGLCamera", text);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneLabelProvider#getText(Object) getText(Object)} with the special
     * condition that the element has MetaData.
     * </p>
     */
    @Test
    public void getTextMetaData()
    {
        // Create dependencies.
        MetaData mockMetaData = createMock(MetaData.class);

        // Dictate correct behaviour.
        expect(mockMetaData.getAttribute("name")).andStubReturn("test");
        replay(mockMetaData);

        // Perform test.
        String text = testObject.getText(mockMetaData);

        // Verify results.
        assertEquals("test", text);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.outline.SceneLabelProvider#getText(Object) getText(Object)} with the special
     * condition that the element is a Node.
     * </p>
     */
    @Test
    public void getTextNode()
    {
        // Create dependencies.
        SimpleNode node = new SimpleNode();
        node.setID(1);

        // Perform test.
        String text = testObject.getText(node);

        // Verify results.
        assertEquals("SimpleNode1", text);
    }
}
