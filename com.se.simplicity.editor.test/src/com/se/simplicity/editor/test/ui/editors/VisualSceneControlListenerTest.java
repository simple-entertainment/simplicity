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

import org.eclipse.swt.events.ControlEvent;
import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.VisualSceneControlListener;
import com.se.simplicity.jogl.rendering.engine.SimpleJOGLRenderingEngine;
import com.se.simplicity.rendering.Camera;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.VisualSceneControlListener VisualSceneControlListener}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneControlListenerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private VisualSceneControlListener testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneControlListener#controlResized(ControlEvent)
     * controlResized(ControlEvent)}.
     * </p>
     */
    @Test
    public void controlResized()
    {
        // Create dependencies.
        SimpleJOGLRenderingEngine renderingEngine = new SimpleJOGLRenderingEngine();
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);

        // Dictate correct behaviour.
        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        replay(mockCanvas);

        // Initialise test environment.
        testObject = new VisualSceneControlListener(mockCanvas);
        testObject.addRenderingEngine(renderingEngine);

        // Perform test.
        testObject.controlResized(null);

        // Verify test results.
        Dimension dimension = renderingEngine.getViewportSize();

        assertEquals(200, dimension.width, 0);
        assertEquals(200, dimension.height, 0);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneControlListener#controlResized(ControlEvent)
     * controlResized(ControlEvent)} with the special condition that the current <code>Camera</code>'s aspect ratio should be synchronised with the
     * <code>RenderingEngine</code>'s aspect ratio.
     * </p>
     */
    @Test
    public void controlResizedCameraAspectRatioSynchronised()
    {
        // Create dependencies.
        SimpleJOGLRenderingEngine renderingEngine = new SimpleJOGLRenderingEngine();
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);
        Camera mockCamera = createMock(Camera.class);
        renderingEngine.setCamera(mockCamera);

        // Dictate correct behaviour.
        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        mockCamera.setFrameAspectRatio(1.0f);
        replay(mockCanvas, mockCamera);

        // Initialise test environment.
        testObject = new VisualSceneControlListener(mockCanvas);
        testObject.setCameraAspectRatioSyncronised(true);
        testObject.addRenderingEngine(renderingEngine);

        // Perform test.
        testObject.controlResized(null);

        // Verify test results.
        verify(mockCamera);

        Dimension dimension = renderingEngine.getViewportSize();

        assertEquals(200, dimension.width, 0);
        assertEquals(200, dimension.height, 0);
    }
}
