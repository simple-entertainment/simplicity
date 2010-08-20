/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.jogl.engine;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLEventListener;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.jogl.JOGLComponent;

/**
 * <p>
 * An engine that supports the inversion of control provided by the JOGL framework. A <code>JOGLEngine</code> can subscribe to a publisher of
 * <code>GLEvent</code>s and thereby rely on the JOGL framework to advance the <code>JOGLEngine</code>.
 * </p>
 * 
 * @author Gary Buyn
 */
public abstract class JOGLEngine implements Engine, JOGLComponent, GLEventListener
{
    /**
     * <p>
     * The JOGL rendering environment.
     * </p>
     */
    private GL gl;

    /**
     * <p>
     * It is not required to call this method when subscribed to a publisher of <code>GLEvent</code>s. The JOGL framework will advance the
     * <code>JOGLEngine</code>.
     * </p>
     */
    @Override
    public void advance()
    {}

    @Override
    public void display(final GLAutoDrawable drawable)
    {
        advance();
    }

    @Override
    public void displayChanged(final GLAutoDrawable drawable, final boolean modeChanged, final boolean deviceChanged)
    {}

    @Override
    public GL getGL()
    {
        return (gl);
    }

    @Override
    public void init(final GLAutoDrawable drawable)
    {
        gl = drawable.getGL();

        init();
    }

    @Override
    public void reshape(final GLAutoDrawable drawable, final int x, final int y, final int width, final int height)
    {}

    @Override
    public void setGL(final GL newGl)
    {
        gl = newGl;
    }
}
