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

import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * Clears the stencil buffer before executing the wrapped {@link com.se.simplicity.rendering.engine.Renderer Renderer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class StencilClearingJOGLRenderer extends AdaptingJOGLRenderer
{
    /**
     * <p>
     * Creates an instance of <code>StencilClearingJOGLRenderer</code>.
     * </p>
     * 
     * @param renderer The wrapped {@link com.se.simplicity.rendering.Renderer Renderer} that will execute after the stencil buffer is cleared.
     */
    public StencilClearingJOGLRenderer(final Renderer renderer)
    {
        super(renderer);
    }

    @Override
    public void init()
    {
        getGL().glClear(GL.GL_STENCIL_BUFFER_BIT);

        super.init();
    }
}
