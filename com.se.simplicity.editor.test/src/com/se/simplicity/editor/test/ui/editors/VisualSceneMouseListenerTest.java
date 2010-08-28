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

import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Event;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.VisualSceneMouseListener;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.viewport.Viewport;

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
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneMouseListener#mouseClicked(MouseEvent) mouseClicked(MouseEvent)}.
     * </p>
     */
    @Test
    public void mouseClicked()
    {
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Viewport mockViewport = createMock(Viewport.class);
        PickingEngine mockPickingEngine = createMock(PickingEngine.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);

        expect(mockViewport.getPickingEngine()).andStubReturn(mockPickingEngine);
        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        mockPickingEngine.pickViewport(mockViewport, 100, 100, 200, 200);
        replay(mockCanvas, mockViewport, mockPickingEngine);

        testObject = new VisualSceneMouseListener(mockViewport, mockCanvas);

        Event event = new Event();
        event.widget = mockCanvas;
        MouseEvent mouseEvent = new MouseEvent(event);
        mouseEvent.button = 1;
        mouseEvent.x = 100;
        mouseEvent.y = 100;
        testObject.mouseClicked(mouseEvent);

        verify(mockPickingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneMouseListener#mouseClicked(MouseEvent) mouseClicked(MouseEvent)}.
     * </p>
     */
    @Test
    public void mouseClickedNoPickingEngine()
    {
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Viewport mockViewport = createMock(Viewport.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);

        expect(mockViewport.getPickingEngine()).andStubReturn(null);
        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        replay(mockCanvas, mockViewport);

        testObject = new VisualSceneMouseListener(mockViewport, mockCanvas);

        Event event = new Event();
        event.widget = mockCanvas;
        MouseEvent mouseEvent = new MouseEvent(event);
        mouseEvent.button = 1;
        mouseEvent.x = 100;
        mouseEvent.y = 100;
        testObject.mouseClicked(mouseEvent);
    }
}
