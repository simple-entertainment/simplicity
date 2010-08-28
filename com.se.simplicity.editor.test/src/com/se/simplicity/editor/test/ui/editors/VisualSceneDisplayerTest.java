/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.ui.editors;

import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.expect;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;

import javax.media.opengl.GLContext;

import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Display;
import org.junit.Test;

import com.se.simplicity.editor.ui.editors.VisualSceneDisplayer;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.ui.editors.VisualSceneDisplayer VisualSceneDisplayer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneDisplayerTest
{
    /**
     * An instance of the class being unit tested.
     */
    private VisualSceneDisplayer testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.ui.editors.VisualSceneDisplayer#run() run()}.
     * </p>
     */
    @Test
    public void run()
    {
        Display mockDisplay = createMock(Display.class);
        Viewport mockViewport = createMock(Viewport.class);
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        GLContext mockGlContext = createMock(GLContext.class);

        testObject = new VisualSceneDisplayer(mockDisplay, mockViewport, mockCanvas, mockGlContext);

        reset(mockDisplay, mockViewport, mockCanvas, mockGlContext);
        expect(mockCanvas.isDisposed()).andReturn(false);
        mockCanvas.setCurrent();
        expect(mockGlContext.makeCurrent()).andReturn(0);
        mockViewport.displayScene();
        mockCanvas.swapBuffers();
        mockGlContext.release();
        mockDisplay.asyncExec(testObject);
        replay(mockDisplay, mockViewport, mockCanvas, mockGlContext);

        testObject.run();

        verify(mockDisplay, mockViewport);
    }
}
