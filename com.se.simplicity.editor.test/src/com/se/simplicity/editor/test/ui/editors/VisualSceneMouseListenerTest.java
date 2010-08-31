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
import static org.easymock.classextension.EasyMock.verify;
import static org.junit.Assert.assertEquals;

import java.awt.Dimension;

import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Event;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.VisualSceneMouseListener;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.TranslationVectorf;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.VisualSceneMouseListener VisualSceneMouseListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneMouseListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private VisualSceneMouseListener testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneMouseListener#mouseUp(MouseEvent) mouseUp(MouseEvent)}.
     * </p>
     */
    @Test
    public void mouseUp()
    {
        // Create dependencies.
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        PickingEngine mockPickingEngine = createMock(PickingEngine.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);

        Dimension dimension = new Dimension();
        dimension.width = 200;
        dimension.height = 200;

        Event event = new Event();
        event.widget = mockCanvas;
        MouseEvent mouseEvent = new MouseEvent(event);
        mouseEvent.button = 1;
        mouseEvent.x = 100;
        mouseEvent.y = 100;

        // Dictate correct behaviour.
        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        mockPickingEngine.pickViewport(dimension, 100, 100, 5, 5);
        replay(mockCanvas, mockPickingEngine);

        // Initialise test environment.
        testObject = new VisualSceneMouseListener(mockPickingEngine, null);

        // Perform test.
        testObject.mouseUp(mouseEvent);

        // Verify test results.
        verify(mockPickingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneMouseListener#mouseUp(MouseEvent) mouseUp(MouseEvent)}.
     * </p>
     */
    @Test
    public void mouseScrolled()
    {
        // Create dependencies.
        Camera mockCamera = createMock(Camera.class);
        Node mockNode = createMock(Node.class);
        SimpleTransformationMatrixf44 matrix = new SimpleTransformationMatrixf44();

        Event event = new Event();
        event.widget = createMock(GLCanvas.class);
        MouseEvent mouseEvent = new MouseEvent(event);
        mouseEvent.count = 1;

        // Dictate correct behaviour.
        expect(mockCamera.getNode()).andStubReturn(mockNode);
        expect(mockNode.getTransformation()).andStubReturn(matrix);
        replay(mockCamera, mockNode);

        // Initialise test environment.
        testObject = new VisualSceneMouseListener(null, mockCamera);

        // Perform test 1.
        testObject.mouseScrolled(mouseEvent);

        // Verify test 1 results.
        TranslationVectorf vector = matrix.getTranslation();

        assertEquals(0.0f, vector.getX(), 0.0f);
        assertEquals(0.0f, vector.getY(), 0.0f);
        assertEquals(-1.0f, vector.getZ(), 0.0f);

        // Modify dependencies.
        mouseEvent.count = -1;

        // Perform test 2.
        testObject.mouseScrolled(mouseEvent);

        // Verify test 2 results.
        vector = matrix.getTranslation();

        assertEquals(0.0f, vector.getX(), 0.0f);
        assertEquals(0.0f, vector.getY(), 0.0f);
        assertEquals(0.0f, vector.getZ(), 0.0f);
    }
}
