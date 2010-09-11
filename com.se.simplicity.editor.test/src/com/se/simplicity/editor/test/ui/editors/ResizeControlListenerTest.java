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

import org.eclipse.swt.events.ControlEvent;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Event;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.ResizeControlListener;
import com.se.simplicity.editor.ui.editors.SceneEditor;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.ResizeControlListener VisualSceneControlListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class ResizeControlListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private ResizeControlListener testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.ResizeControlListener#controlResized(ControlEvent)
     * controlResized(ControlEvent)}.
     * </p>
     */
    @Test
    public void controlResized()
    {
        // Create dependencies.
        SceneEditor mockSceneEditor = createMock(SceneEditor.class);
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);

        Event event = new Event();
        event.widget = mockCanvas;
        ControlEvent controlEvent = new ControlEvent(event);

        // Dictate correct behaviour.
        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        replay(mockCanvas);

        // Initialise test environment.
        testObject = new ResizeControlListener(mockSceneEditor);

        // Dictate expected results.
        mockSceneEditor.setCanvasSize((Rectangle) anyObject());
        replay(mockSceneEditor);

        // Perform test.
        testObject.controlResized(controlEvent);

        // Verify test results.
        verify(mockSceneEditor);
    }
}
