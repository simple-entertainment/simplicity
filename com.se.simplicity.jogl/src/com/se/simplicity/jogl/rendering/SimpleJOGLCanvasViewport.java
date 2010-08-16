package com.se.simplicity.jogl.rendering;

// JOGL imports.
import javax.media.opengl.GLCanvas;

// simplicity imports.
import com.se.simplicity.jogl.picking.JOGLPicker;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.Renderer;
import com.se.simplicity.rendering.Viewport;

/**
 * <p>
 * A viewport on which a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} rendered by a JOGL rendering environment can
 * be displayed. This <code>SimpleJOGLCanvasViewport</code> extends the {@link javax.media.opengl.GLCanvas GLCanvas} class in
 * order to integrate it with the JOGL rendering environment.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLCanvasViewport extends GLCanvas implements Viewport
{
	/**
	 * <p>
	 * The version of this class.
	 * <p>
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * <p>
	 * The <code>Camera</code> through which the <code>SceneGraph</code> is viewed.
	 * </p>
	 */
	private Camera camera;

	/**
	 * <p>
	 * The <code>Picker</code> with which the <code>SceneGraph</code> is picked.
	 * </p>
	 */
	private Picker picker;

	/**
	 * <p>
	 * The <code>Renderer</code> that renders to this <code>SimpleJOGLCanvasViewport</code>.
	 * </p>
	 */
	private Renderer renderer;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleJOGLCanvasViewport</code>.
	 * </p>
	 */
	public SimpleJOGLCanvasViewport()
	{
		super();

		this.camera = null;
		this.renderer = null;
	}

	@Override
	public void displaySceneGraph()
	{
		// Ensures the correct camera will be used to draw the scene graph to this Viewport. This enables the easy use of multiple
		// Viewports viewing a single scene graph using a single Renderer.
		if (renderer.getCamera() != camera)
		{
			renderer.setCamera(camera);
		}

		display();
	}

	@Override
	public Camera getCamera()
	{
		return (camera);
	}

	@Override
	public Picker getPicker()
	{
		return (picker);
	}

	@Override
	public Renderer getRenderer()
	{
		return (renderer);
	}

	@Override
	public void setCamera(final Camera camera)
	{
		this.camera = camera;
	}

	@Override
	public void setPicker(final Picker picker)
	{
		if (this.picker != null)
		{
			removeGLEventListener((JOGLPicker) this.picker);
		}

		this.picker = picker;

		addGLEventListener((JOGLPicker) picker);
	}

	@Override
	public void setRenderer(final Renderer renderer)
	{
		if (this.renderer != null)
		{
			removeGLEventListener((JOGLRenderer) this.renderer);
		}

		this.renderer = renderer;

		addGLEventListener((JOGLRenderer) renderer);
	}
}
