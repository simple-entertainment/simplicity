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

import java.awt.Dimension;

import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Event;
import org.junit.Test;

import com.se.simplicity.editor.internal.EditingMode;
import com.se.simplicity.editor.internal.Widget;
import com.se.simplicity.editor.internal.WidgetManager;
import com.se.simplicity.editor.ui.editors.WidgetMouseListener;
import com.se.simplicity.picking.engine.PickingEngine;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.WidgetMouseListener WidgetMouseListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class WidgetMouseListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private WidgetMouseListener testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.WidgetMouseListener#mouseDown(MouseEvent) mouseDown(MouseEvent)} with the
     * special condition that it was mouse button 1 that raised the event.
     * </p>
     */
    @Test
    public void mouseDownButton1()
    {
        // Create dependencies.
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        WidgetManager mockWidgetManager = createMock(WidgetManager.class);
        Widget mockWidget = createMock(Widget.class);
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
        expect(mockWidgetManager.getWidget()).andStubReturn(mockWidget);
        expect(mockWidgetManager.getEditingMode()).andStubReturn(EditingMode.ROTATION);
        expect(mockWidgetManager.getPickingEngine()).andStubReturn(mockPickingEngine);
        replay(mockCanvas, mockWidgetManager);

        // Initialise test environment.
        testObject = new WidgetMouseListener(mockWidgetManager);

        // Dictate expected results.
        mockPickingEngine.pickViewport(dimension, 100, 100, 2, 2);
        replay(mockPickingEngine);

        // Perform test.
        testObject.mouseDown(mouseEvent);

        // Verify test results.
        verify(mockPickingEngine);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.WidgetMouseListener#mouseUp(MouseEvent) mouseUp(MouseEvent)} with the special
     * condition that it was mouse button 1 that raised the event.
     * </p>
     */
    @Test
    public void mouseMove()
    {
        // Create dependencies.
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        WidgetManager mockWidgetManager = createMock(WidgetManager.class);
        Widget mockWidget = createMock(Widget.class);
        PickingEngine mockPickingEngine = createMock(PickingEngine.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);

        Event event = new Event();
        event.widget = mockCanvas;
        MouseEvent mouseEvent = new MouseEvent(event);
        mouseEvent.button = 1;
        mouseEvent.x = 100;
        mouseEvent.y = 100;

        // Dictate correct behaviour.
        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        expect(mockWidgetManager.getWidget()).andStubReturn(mockWidget);
        expect(mockWidgetManager.getEditingMode()).andStubReturn(EditingMode.ROTATION);
        expect(mockWidgetManager.getPickingEngine()).andStubReturn(mockPickingEngine);
        replay(mockCanvas, mockWidgetManager);

        // Initialise test environment.
        testObject = new WidgetMouseListener(mockWidgetManager);
        testObject.mouseDown(mouseEvent);

        // Dictate expected results.
        mockWidget.executeMove(10, 10);
        replay(mockWidget);

        // Perform test.
        testObject.mouseMove(mouseEvent);
        mouseEvent.x = 110;
        mouseEvent.y = 110;
        testObject.mouseMove(mouseEvent);

        // Verify test results.
        verify(mockWidget);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.WidgetMouseListener#mouseUp(MouseEvent) mouseUp(MouseEvent)} with the special
     * condition that it was mouse button 1 that raised the event.
     * </p>
     */
    @Test
    public void mouseUpButton1()
    {
        // Create dependencies.
        WidgetManager mockWidgetManager = createMock(WidgetManager.class);
        Widget mockWidget = createMock(Widget.class);

        Event event = new Event();
        event.widget = createMock(GLCanvas.class);
        MouseEvent mouseEvent = new MouseEvent(event);
        mouseEvent.button = 1;

        // Dictate correct behaviour.
        expect(mockWidgetManager.getWidget()).andStubReturn(mockWidget);
        expect(mockWidgetManager.getEditingMode()).andStubReturn(EditingMode.ROTATION);
        replay(mockWidgetManager);

        // Initialise test environment.
        testObject = new WidgetMouseListener(mockWidgetManager);

        // Dictate expected results.
        mockWidget.setSelectedWidgetNode(null);
        replay(mockWidget);

        // Perform test.
        testObject.mouseUp(mouseEvent);

        // Verify test results.
        verify(mockWidget);
    }
}
