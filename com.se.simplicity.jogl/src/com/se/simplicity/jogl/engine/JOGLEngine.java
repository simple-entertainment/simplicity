package com.se.simplicity.jogl.engine;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLEventListener;

import com.se.simplicity.engine.Engine;
import com.se.simplicity.jogl.JOGLComponent;

/**
 * <p>
 * An engine that supports the inversion of control provided by the JOGL framework. A <code>JOGLEngine</code> can subscribe to a
 * publisher of <code>GLEvent</code>s and thereby rely on the JOGL framework to advance the <code>JOGLEngine</code>.
 * </p>
 * 
 * @author simple
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
	 * It is not required to call this method when subscribed to a publisher of <code>GLEvent</code>s. The JOGL framework will
	 * advance the <code>JOGLEngine</code>.
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
	public void setGL(final GL gl)
	{
		this.gl = gl;
	}
}
