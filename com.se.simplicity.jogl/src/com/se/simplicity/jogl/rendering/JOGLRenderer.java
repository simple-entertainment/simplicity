package com.se.simplicity.jogl.rendering;

// JOGL imports.
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLEventListener;

// simplicity imports.
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;

/**
 * <p>
 * Renders a <code>SceneGraph</code> from the viewpoint of a <code>Camera</code> using the JOGL rendering environment. This
 * <code>JOGLRenderer</code> implements the {@link javax.media.opengl.GLEventListener GLEventListener} interface in order to
 * integrate it with the JOGL rendering environment.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public abstract class JOGLRenderer implements Renderer, JOGLComponent, GLEventListener
{
	/**
	 * <p>
	 * The JOGL rendering environment.
	 * </p>
	 */
	private GL gl;

	/**
	 * <p>
	 * For JOGL implementations this method should not be called directly by the programmer. Instead,
	 * <code>displaySceneGraph()</code> should be called on the <code>Viewport</code>(s) of which this <code>Renderer</code> is a
	 * {@link javax.media.opengl.GLEventListener GLEventListener}.
	 * </p>
	 */
	public void display()
	{ }

	/**
	 * <p>
	 * For JOGL implementations this method should not be called directly by the programmer. Instead, <code>displayScene()</code>
	 * should be called on the <code>JOGLViewport</code>(s) of which this <code>Renderer</code> is a
	 * {@link javax.media.opengl.GLEventListener GLEventListener}.
	 * </p>
	 * 
	 * @param drawable 
	 */
	public void display(final GLAutoDrawable drawable)
	{
		display();
	}

	@Override
	public void displayChanged(final GLAutoDrawable drawable, final boolean modeChanged, final boolean deviceChanged)
	{ }

	@Override
	public GL getGL()
	{
		return (gl);
	}

	@Override
	public void init()
	{
		if (getCamera() != null)
		{
			((JOGLComponent) getCamera()).setGL(gl);
		}

		for (int index = 0; index < getLights().size(); index++)
		{
			((JOGLComponent) getLights().get(index)).setGL(gl);
		}
	}

	@Override
	public void init(final GLAutoDrawable drawable)
	{
		gl = drawable.getGL();

		init();
	}

	@Override
	public void reshape(final GLAutoDrawable drawable, final int x, final int y, final int width, final int height)
	{ }

	@Override
	public void setCamera(final Camera camera)
	{
		((JOGLComponent) camera).setGL(gl);
	}

	@Override
	public void setGL(final GL gl)
	{
		this.gl = gl;
	}
}
