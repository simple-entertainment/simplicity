/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.test.internal.engine;

import static org.easymock.EasyMock.anyObject;
import static org.easymock.EasyMock.expect;
import static org.easymock.classextension.EasyMock.createMock;
import static org.easymock.classextension.EasyMock.replay;
import static org.easymock.classextension.EasyMock.reset;
import static org.easymock.classextension.EasyMock.verify;

import javax.media.opengl.GLContext;

import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Display;
import org.junit.Test;

import com.se.simplicity.editor.internal.engine.DisplayAsyncJOGLCompositeEngine;
import com.se.simplicity.engine.Engine;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.editor.internal.engine.DisplayAsyncJOGLCompositeEngine DisplayAsyncJOGLCompositeEngine}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class DisplayAsyncJOGLCompositeEngineTest
{
    /**
     * An instance of the class being unit tested.
     */
    private DisplayAsyncJOGLCompositeEngine testObject;

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.engine.DisplayAsyncJOGLCompositeEngine#advance() advance()}.
     * </p>
     */
    @Test
    public void advance()
    {
        // Create dependencies.
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        GLContext mockGlContext = createMock(GLContext.class);

        Engine mockEngine0 = createMock(Engine.class);
        Engine mockEngine1 = createMock(Engine.class);

        // Dictate correct behaviour.
        expect(mockCanvas.getDisplay()).andStubReturn(createMock(Display.class));
        replay(mockCanvas);

        // Setup test environment.
        testObject = new DisplayAsyncJOGLCompositeEngine(mockCanvas, mockGlContext);
        testObject.addEngine(mockEngine0);
        testObject.addEngine(mockEngine1);

        // Dictate expected results.
        reset(mockCanvas);
        mockCanvas.setCurrent();
        expect(mockGlContext.makeCurrent()).andReturn(null);
        mockEngine0.advance();
        mockEngine1.advance();
        mockCanvas.swapBuffers();
        mockGlContext.release();
        replay(mockCanvas, mockGlContext, mockEngine0, mockEngine1);

        // Perform test.
        testObject.advance();

        // Verify test results.
        verify(mockCanvas, mockGlContext, mockEngine0, mockEngine1);
    }

    /**
     * <p>
     * Unit test the method {@link com.se.simplicity.editor.internal.engine.DisplayAsyncJOGLCompositeEngine#run() run()}.
     * </p>
     */
    @Test
    public void run()
    {
        // Create dependencies.
        GLCanvas mockCanvas = createMock(GLCanvas.class);
        Display mockDisplay = createMock(Display.class);

        Engine mockEngine0 = createMock(Engine.class);
        Engine mockEngine1 = createMock(Engine.class);

        // Dictate correct behaviour.
        expect(mockCanvas.getDisplay()).andStubReturn(mockDisplay);
        replay(mockCanvas);

        // Setup test environment.
        testObject = new DisplayAsyncJOGLCompositeEngine(mockCanvas, createMock(GLContext.class));
        testObject.addEngine(mockEngine0);
        testObject.addEngine(mockEngine1);

        // Dictate expected results.
        mockEngine0.init();
        mockEngine1.init();
        mockDisplay.asyncExec((Runnable) anyObject());
        mockEngine0.destroy();
        mockEngine1.destroy();
        replay(mockEngine0, mockEngine1, mockDisplay);

        // Perform test.
        testObject.run();

        // Verify test results.
        verify(mockEngine0, mockEngine1, mockDisplay);
    }
}
