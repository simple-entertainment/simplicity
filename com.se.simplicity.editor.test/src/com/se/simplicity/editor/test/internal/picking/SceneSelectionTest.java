/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal.picking;

import static org.easymock.classextension.EasyMock.createMock;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import com.se.simplicity.editor.internal.properties.CameraPropertySource;
import com.se.simplicity.editor.internal.properties.LightPropertySource;
import com.se.simplicity.editor.internal.properties.NodePropertySource;
import com.se.simplicity.editor.internal.selection.SceneSelection;
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.selection.SceneSelection SceneSelection}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SceneSelectionTest
{
    /**
     * An instance of the class being unit tested.
     */
    private SceneSelection testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.selection.SceneSelection#isEmpty() isEmpty()}.
     * </p>
     */
    @Test
    public void isEmpty()
    {
        // Initialise test environment.
        testObject = new SceneSelection(createMock(Node.class), createMock(Model.class));

        // Perform test 1 - verify test 1 results.
        assertFalse(testObject.isEmpty());

        // Initialise test environment.
        testObject = new SceneSelection(createMock(Node.class), null);

        // Perform test 2 - verify test 2 results.
        assertFalse(testObject.isEmpty());

        // Initialise test environment.
        testObject = new SceneSelection(null, createMock(Model.class));

        // Perform test 3 - verify test 3 results.
        assertFalse(testObject.isEmpty());

        // Initialise test environment.
        testObject = new SceneSelection(null, null);

        // Perform test 4 - verify test 4 results.
        assertTrue(testObject.isEmpty());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.selection.SceneSelection#getFirstElement() getFirstElement()}.
     * </p>
     */
    @Test
    public void getFirstElement()
    {
        // Initialise test environment.
        testObject = new SceneSelection(createMock(Camera.class), null);

        // Perform test 1 - verify test 1 results.
        assertTrue(testObject.getFirstElement() instanceof CameraPropertySource);

        // Initialise test environment.
        testObject = new SceneSelection(createMock(Light.class), null);

        // Perform test 2 - verify test 2 results.
        assertTrue(testObject.getFirstElement() instanceof LightPropertySource);

        // Initialise test environment.
        testObject = new SceneSelection(createMock(Node.class), null);

        // Perform test 3 - verify test 3 results.
        assertTrue(testObject.getFirstElement() instanceof NodePropertySource);

        // Initialise test environment.
        testObject = new SceneSelection(null, null);

        // Perform test 4 - verify test 4 results.
        assertNull(testObject.getFirstElement());
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.selection.SceneSelection#toList() toList()}.
     * </p>
     */
    @Test
    public void toList()
    {
        // Initialise test environment.
        testObject = new SceneSelection(null, null);

        // Perform test 1 - verify test 1 results.
        assertEquals(0, testObject.toList().size(), 0);

        // Initialise test environment.
        testObject = new SceneSelection(createMock(Camera.class), createMock(Model.class));

        // Perform test 2 - verify test 2 results.
        assertEquals(2, testObject.toList().size(), 0);
        assertTrue(testObject.toList().get(0) instanceof CameraPropertySource);
        assertTrue(testObject.toList().get(1) instanceof Model);

        // Initialise test environment.
        testObject = new SceneSelection(createMock(Light.class), createMock(Model.class));

        // Perform test 3 - verify test 3 results.
        assertEquals(2, testObject.toList().size(), 0);
        assertTrue(testObject.toList().get(0) instanceof LightPropertySource);
        assertTrue(testObject.toList().get(1) instanceof Model);

        // Initialise test environment.
        testObject = new SceneSelection(createMock(Node.class), createMock(Model.class));

        // Perform test 4 - verify test 4 results.
        assertEquals(2, testObject.toList().size(), 0);
        assertTrue(testObject.toList().get(0) instanceof NodePropertySource);
        assertTrue(testObject.toList().get(1) instanceof Model);
    }
}
