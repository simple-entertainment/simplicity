/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.editor.ui.editors;

import java.util.ArrayList;
import java.util.List;

import javax.media.opengl.GLContext;

import org.eclipse.swt.opengl.GLCanvas;
import org.eclipse.swt.widgets.Display;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.rendering.engine.RenderingEngine;

/**
 * <p>
 * Continually advances the contained engines, rendering to a 3D canvas using the JOGL rendering environment. Advances are executed as asynchronous
 * display calls ( {@link org.eclipse.swt.widgets.Display#asyncExec(Runnable) Display.asyncExec(Runnable)}). Advances are halted once the canvas is
 * disposed.
 * </p>
 * 
 * @author Gary Buyn
 */
public class VisualSceneAdvancer implements Runnable
{
    /**
     * <p>
     * The 3D canvas to render to.
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
     * The <code>GLContext</code> to use when rendering.
     * </p>
     */
    private GLContext glContext;

    /**
     * <p>
     * The <code>Engine</code>s to advance.
     * </p>
     */
    private List<Engine> engines;

    /**
     * <p>
     * Creates an instance of <code>VisualSceneDisplayer</code>.
     * </p>
     * 
     * @param newDisplay The display to request asynchronous calls against.
     * @param newCanvas The 3D canvas to render to.
     * @param newGlContext The <code>GLContext</code> to use when rendering.
     */
    public VisualSceneAdvancer(final Display newDisplay, final GLCanvas newCanvas, final GLContext newGlContext)
    {
        canvas = newCanvas;
        display = newDisplay;
        glContext = newGlContext;

        engines = new ArrayList<Engine>();
    }

    /**
     * <p>
     * Adds the given <code>Engine</code> to the <code>Engine</code>s to be advanced.
     * </p>
     * 
     * @param engine The <code>Engine</code> to be advanced.
     */
    public void addEngine(final Engine engine)
    {
        engines.add(engine);
    }

    /**
     * <p>
     * Continually advances the contained engines, rendering to a 3D canvas using the JOGL rendering environment. Advances are executed as
     * asynchronous display calls ( {@link org.eclipse.swt.widgets.Display#asyncExec(Runnable) Display.asyncExec(Runnable)}). Advances are halted once
     * the canvas is disposed.
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

                for (Engine engine : engines)
                {
                    // TODO find a better way to do this
                    if (engine instanceof RenderingEngine)
                    {
                        ((RenderingEngine) engine).getCamera().setInitialised(false);
                    }

                    engine.advance();
                }

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
