/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import javax.media.opengl.GLContext;

import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Display;

import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * Continually renders a <code>Viewport</code> to a 3D canvas using the JOGL rendering environment. Renders are executed as asynchronous display calls
 * ( {@link org.eclipse.swt.widgets.Display#asyncExec(Runnable) Display.asyncExec(Runnable)}) until the canvas is disposed.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneDisplayer implements Runnable
{
    /**
     * <p>
     * The 3D canvas to render the <code>Viewport</code> to.
     * </p>
     */
    private GLCanvas canvas;

    /**
     * <p>
     * The display to request asynchronous calls against.
     * </p>
     */
    private Display display;

    /**
     * <p>
     * The <code>GLContext</code> to use when rendering the <code>Viewport</code>.
     * </p>
     */
    private GLContext glContext;

    /**
     * <p>
     * The <code>Viewport</code> to render.
     * </p>
     */
    private Viewport viewport;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneDisplayer</code>.
     * </p>
     * 
     * @param newDisplay The display to request asynchronous calls against.
     * @param newViewport The <code>Viewport</code> to render.
     * @param newCanvas The 3D canvas to render the <code>Viewport</code> to.
     * @param newGlContext The <code>GLContext</code> to use when rendering the <code>Viewport</code>.
     */
    public VisualSceneDisplayer(final Display newDisplay, final Viewport newViewport, final GLCanvas newCanvas, final GLContext newGlContext)
    {
        canvas = newCanvas;
        display = newDisplay;
        glContext = newGlContext;
        viewport = newViewport;
    }

    /**
     * <p>
     * Continually renders a <code>Viewport</code> to a 3D canvas using the JOGL rendering environment. Renders are executed as asynchronous display
     * calls ( {@link org.eclipse.swt.widgets.Display#asyncExec(Runnable) Display.asyncExec(Runnable)}) until the canvas is disposed.
     * </p>
     */
    public void run()
    {
        try
        {
            if (!canvas.isDisposed())
            {
                canvas.setCurrent();
                glContext.makeCurrent();

                viewport.displayScene();

                canvas.swapBuffers();
                glContext.release();

                display.asyncExec(this);
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}
