/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.rendering;

import com.se.simplicity.model.Model;
import com.se.simplicity.rendering.NamedRenderer;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * Provides blending capabilities to the wrapped {@link com.se.simplicity.rendering.engine.Renderer Renderer}.
 * </p>
 * 
 * @author Gary Buyn
 */
public class NamePassingJOGLRenderer extends AdaptingJOGLRenderer implements NamedRenderer
{
    private class MiddleManJOGLRenderer extends AdaptingJOGLRenderer
    {
        private int fName;

        public MiddleManJOGLRenderer(Renderer renderer)
        {
            super(renderer);

            fName = -1;
        }

        @Override
        public void renderModel(final Model model)
        {
            if (fName != -1)
            {
                ((NamedRenderer) getRenderer()).renderModel(model, fName);
            }

            fName = -1;
        }

        public void setName(final int name)
        {
            fName = name;
        }
    }

    private MiddleManJOGLRenderer fMiddleMan;

    /**
     * <p>
     * Creates an instance of <code>BlendingJOGLRenderer</code>.
     * </p>
     * 
     * @param renderer The wrapped {@link com.se.simplicity.rendering.Renderer Renderer} that will execute with blending capabilities enabled.
     */
    public NamePassingJOGLRenderer(final Renderer renderer)
    {
        super(renderer);

        if (!(renderer instanceof AdaptingJOGLRenderer))
        {
            throw new IllegalStateException("This Renderer must wrap an AdaptingJOGLRenderer.");
        }

        // Retrieve the AdaptingJOGLRenderer that is wrapping the NamedRenderer the name is to be passed to.
        AdaptingJOGLRenderer wrappedRenderer = (AdaptingJOGLRenderer) renderer;
        while (!(wrappedRenderer.getRenderer() instanceof NamedRenderer))
        {
            wrappedRenderer = (AdaptingJOGLRenderer) wrappedRenderer.getRenderer();
        }

        // Put the middle man between the AdaptingJOGLRenderer and the NamedRenderer.
        Renderer namedRenderer = wrappedRenderer.getRenderer();
        fMiddleMan = new MiddleManJOGLRenderer(namedRenderer);
        wrappedRenderer.setRenderer(fMiddleMan);
    }

    @Override
    public void renderModel(final Model model, final int name)
    {
        fMiddleMan.setName(name);

        super.renderModel(model);
    }
}
