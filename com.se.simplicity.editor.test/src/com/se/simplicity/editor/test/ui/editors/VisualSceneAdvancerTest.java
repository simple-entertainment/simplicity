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
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;

import javax.media.opengl.GLContext;

import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Display;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.VisualSceneAdvancer;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.VisualSceneAdvancer VisualSceneDisplayer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneAdvancerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private VisualSceneAdvancer testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneAdvancer#run() run()}.
     * </p>
     */
    @Test
    public void run()
    {
        // Create dependencies.
        Display mockDisplay = createMock(Display.class);
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        GLContext mockGlContext = createMock(GLContext.class);

        RenderingEngine mockRenderingEngine = createMock(RenderingEngine.class);
        Camera mockCamera = createMock(Camera.class);
        PickingEngine mockPickingEngine = createMock(PickingEngine.class);

        // Setup test environment.
        testObject = new VisualSceneAdvancer(mockDisplay, mockCanvas, mockGlContext);
        testObject.addEngine(mockRenderingEngine);
        testObject.addEngine(mockPickingEngine);

        // Dictate correct behaviour.
        reset(mockDisplay, mockCanvas, mockGlContext);
        expect(mockCanvas.isDisposed()).andStubReturn(false);
        mockCanvas.setCurrent();
        expect(mockGlContext.makeCurrent()).andStubReturn(0);

        expect(mockRenderingEngine.getCamera()).andReturn(mockCamera);
        mockCamera.setInitialised(false);
        mockRenderingEngine.advance();
        mockPickingEngine.advance();

        mockCanvas.swapBuffers();
        mockGlContext.release();
        mockDisplay.asyncExec(testObject);
        replay(mockDisplay, mockCanvas, mockGlContext, mockRenderingEngine, mockCamera, mockPickingEngine);

        // Perform test.
        testObject.run();

        // Verify test results.
        verify(mockRenderingEngine, mockCamera, mockPickingEngine);
    }
}
