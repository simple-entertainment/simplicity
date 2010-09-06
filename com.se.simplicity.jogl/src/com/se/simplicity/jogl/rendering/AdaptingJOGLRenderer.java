/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.rendering;

import javax.media.opengl.GL;

import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.DrawingMode;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * A {@link com.se.simplicity.rendering.Renderer Renderer} that wraps another <code>Renderer</code> and adapts the JOGL rendering environment before
 * allowing the wrapped <code>Renderer</code> to execute.
 * </p>
 * 
 * <p>
 * Subclasses should only override the methods {@link com.se.simplicity.jogl.rendering.AdaptingJOGLRenderer#init() init()} and
 * {@link com.se.simplicity.jogl.rendering.AdaptingJOGLRenderer#dispose() dispose()} making sure to call <code>super.init()</code> at the end of the
 * <code>init()</code> method and <code>super.dispose()</code> at the start of the <code>dispose()</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public abstract class AdaptingJOGLRenderer implements Renderer, JOGLComponent
{
    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL fGl;

    /**
     * <p>
     * The wrapped {@link com.se.simplicity.rendering.Renderer Renderer}.
     * </p>
     */
    private Renderer fRenderer;

    /**
     * <p>
     * Creates an instance of <code>AlwaysStencilJOGLRenderer</code>.
     * </p>
     * 
     * @param renderer The wrapped {@link com.se.simplicity.rendering.Renderer Renderer}.
     */
    public AdaptingJOGLRenderer(final Renderer renderer)
    {
        fRenderer = renderer;

        fGl = null;
    }

    @Override
    public void dispose()
    {
        fRenderer.dispose();
    }

    @Override
    public void init()
    {
        fRenderer.init();
    }

    @Override
    public DrawingMode getDrawingMode()
    {
        return (fRenderer.getDrawingMode());
    }

    @Override
    public GL getGL()
    {
        return (fGl);
    }

    @Override
    public void renderModel(final Model model)
    {
        fRenderer.renderModel(model);
    }

    @Override
    public void setDrawingMode(final DrawingMode mode)
    {
        fRenderer.setDrawingMode(mode);
    }

    @Override
    public void setGL(final GL gl)
    {
        fGl = gl;

        ((JOGLComponent) fRenderer).setGL(gl);
    }
}
