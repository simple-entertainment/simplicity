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

public class VisualSceneDisplayer implements Runnable
{
    private Display display;

    private GLContext glContext;

    private Viewport model;

    private GLCanvas view;

    public VisualSceneDisplayer(Display display, Viewport model, GLCanvas view, GLContext glContext)
    {
        this.display = display;
        this.glContext = glContext;
        this.model = model;
        this.view = view;
    }

    public void run()
    {
        try
        {
            if (!view.isDisposed())
            {
                view.setCurrent();
                glContext.makeCurrent();

                model.displayScene();

                view.swapBuffers();
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
