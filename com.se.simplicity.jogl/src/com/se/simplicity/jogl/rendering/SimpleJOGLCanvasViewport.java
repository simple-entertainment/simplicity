package com.se.simplicity.jogl.rendering;

// JOGL imports.
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;

import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.viewport.Viewport;

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
	 * The <code>PickingEngine</code> with which the <code>SceneGraph</code> is picked.
	 * </p>
	 */
	private PickingEngine pickingEngine;

	/**
	 * <p>
	 * The <code>RenderingEngine</code> that renders to this <code>SimpleJOGLCanvasViewport</code>.
	 * </p>
	 */
	private RenderingEngine renderingEngine;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleJOGLCanvasViewport</code>.
	 * </p>
	 */
	public SimpleJOGLCanvasViewport()
	{
		super();

		camera = null;
		pickingEngine = null;
		renderingEngine = null;
	}

	@Override
	public void displaySceneGraph()
	{
		// Ensures the correct camera will be used to draw the scene graph to this Viewport. This enables the easy use of multiple
		// Viewports viewing a single scene graph using a single Renderer.
		if (renderingEngine.getCamera() != camera)
		{
			renderingEngine.setCamera(camera);
		}

		display();
	}

	@Override
	public Camera getCamera()
	{
		return (camera);
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
	public void setCamera(final Camera camera)
	{
		this.camera = camera;
	}

	@Override
	public void setPickingEngine(final PickingEngine pickingEngine)
	{
		if (this.pickingEngine != null)
		{
			removeGLEventListener((GLEventListener) this.pickingEngine);
		}

		this.pickingEngine = pickingEngine;

		addGLEventListener((GLEventListener) pickingEngine);
	}

	@Override
	public void setRenderingEngine(final RenderingEngine renderingEngine)
	{
		if (this.renderingEngine != null)
		{
			removeGLEventListener((GLEventListener) this.renderingEngine);
		}

		this.renderingEngine = renderingEngine;

		addGLEventListener((GLEventListener) renderingEngine);
	}

	@Override
	public void setHeight(int height)
	{ }

	@Override
	public void setWidth(int width)
	{ }
}
