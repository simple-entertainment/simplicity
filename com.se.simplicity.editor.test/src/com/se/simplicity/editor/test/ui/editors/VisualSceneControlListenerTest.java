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

import org.eclipse.swt.graphics.Rectangle;
import org.eclipse.swt.opengl.GLCanvas;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.VisualSceneControlListener;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.util.metadata.rendering.MetaDataCamera;
import com.se.simplicity.viewport.Viewport;

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
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Viewport mockViewport = createMock(Viewport.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);

        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        mockViewport.setSize(200, 200);
        replay(mockCanvas, mockViewport);

        testObject = new VisualSceneControlListener(mockViewport, mockCanvas);
        testObject.controlResized(null);

        verify(mockViewport);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneControlListener#controlResized(ControlEvent)
     * controlResized(ControlEvent)} with the special condition that the current <code>Camera</code>'s aspect ratio should be synchronised with the
     * <code>Viewport</code>'s aspect ratio.
     * </p>
     */
    @Test
    public void controlResizedCameraAspectRatioSynchronised()
    {
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Viewport mockViewport = createMock(Viewport.class);
        Rectangle rectangle = new Rectangle(0, 0, 200, 200);
        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        MetaDataCamera mockMetaDataCamera = createMock(MetaDataCamera.class);
        SimpleJOGLCamera mockWrappedCamera = createMock(SimpleJOGLCamera.class);

        expect(mockCanvas.getBounds()).andStubReturn(rectangle);
        mockViewport.setSize(200, 200);
        expect(mockViewport.getRenderingEngine()).andStubReturn(mockRenderingEngine);
        expect(mockRenderingEngine.getCamera()).andStubReturn(mockMetaDataCamera);
        expect(mockMetaDataCamera.getWrappedCamera()).andStubReturn(mockWrappedCamera);
        mockWrappedCamera.setFrameAspectRatio(1.0f);
        replay(mockCanvas, mockViewport, mockRenderingEngine, mockMetaDataCamera, mockWrappedCamera);

        testObject = new VisualSceneControlListener(mockViewport, mockCanvas);
        testObject.setCameraAspectRatioSyncronised(true);
        testObject.controlResized(null);

        verify(mockViewport, mockWrappedCamera);
    }
}
