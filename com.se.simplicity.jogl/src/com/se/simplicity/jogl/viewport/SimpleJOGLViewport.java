/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.viewport;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * A viewport on which a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} rendered by a JOGL rendering environment can be displayed.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleJOGLViewport implements Viewport, JOGLComponent
{
    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL gl;

    /**
     * <p>
     * The height of this <code>SimpleJOGLViewport</code> in screen coordinates.
     * </p>
     */
    private int height;

    /**
     * <p>
     * The <code>PickingEngine</code> used to pick fomr this <code>SimpleJOGLViewport</code>.
     * TODO Should this be here???
     * </p>
     */
    private PickingEngine pickingEngine;

    /**
     * <p>
     * The <code>RenderingEngine</code> used to render this <code>SimpleJOGLViewport</code>.
     * </p>
     */
    private RenderingEngine renderingEngine;

    /**
     * <p>
     * The width of this <code>SimpleJOGLViewport</code> in screen coordinates.
     * </p>
     */
    private int width;

    /**
     * <p>
     * Creates an instance of <code>SimpleJOGLViewport</code>.
     * </p>
     */
    public SimpleJOGLViewport()
    {
        gl = null;
        height = -1;
        width = -1;
    }

    @Override
    public void displaySceneGraph()
    {
        if (pickingEngine != null)
        {
            pickingEngine.advance();
        }

        try
        {
            renderingEngine.advance();
        }
        catch (NullPointerException e)
        {
            throw new IllegalStateException("This Viewport must have a Rendering Engine before it can displlay the Scene Graph", e);
        }
    }

    @Override
    public GL getGL()
    {
        return (gl);
    }

    @Override
    public int getHeight()
    {
        return (height);
    }

    @Override
    public PickingEngine getPickingEngine()
    {
        return (pickingEngine);
    }

    @Override
    public RenderingEngine getRenderingEngine()
    {
        return (renderingEngine);
    }

    @Override
    public int getWidth()
    {
        return (width);
    }

    @Override
    public void setGL(final GL newGl)
    {
        gl = newGl;

        if (pickingEngine != null)
        {
            ((JOGLComponent) pickingEngine).setGL(newGl);
        }

        if (renderingEngine != null)
        {
            ((JOGLComponent) renderingEngine).setGL(newGl);
        }
    }

    @Override
    public void setPickingEngine(final PickingEngine newPickingEngine)
    {
        ((JOGLComponent) newPickingEngine).setGL(gl);

        pickingEngine = newPickingEngine;
    }

    @Override
    public void setRenderingEngine(final RenderingEngine newRenderingEngine)
    {
        ((JOGLComponent) newRenderingEngine).setGL(gl);

        renderingEngine = newRenderingEngine;
    }

    @Override
    public void setSize(final int newWidth, final int newHeight)
    {
        width = newWidth;
        height = newHeight;

        gl.glViewport(0, 0, newWidth, newHeight);
    }
}
