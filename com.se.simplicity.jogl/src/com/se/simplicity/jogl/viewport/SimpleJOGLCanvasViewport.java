package com.se.simplicity.jogl.viewport;

import java.awt.Component;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.media.opengl.GLCanvas;

import com.se.simplicity.jogl.engine.JOGLEngine;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * A viewport on which a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} rendered by a JOGL rendering environment can
 * be displayed.
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

		this.camera = null;
		this.pickingEngine = null;
		this.renderingEngine = null;
	}
	
	/**
	 * TODO refactor
	 */
	public void applyMousePicking(PickingEngine pickingEngine)
	{
//		if (this.viewport != viewport)
//		{
//			this.viewport = viewport;
//
//			((Component) viewport).addMouseListener(new MouseAdapter()
//			{
//				public void mouseClicked(final MouseEvent event)
//				{
//					if (event.getButton() == MouseEvent.BUTTON1)
//					{
//						pickingEngine.pick(event.getX(), event.getY(), 2, 2);
//					}
//				}
//			});
//		}
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
	public void setHeight(final int height)
	{
		setSize(getWidth(), height);
	}

	@Override
	public void setPickingEngine(final PickingEngine pickingEngine)
	{
		if (this.pickingEngine != null)
		{
			removeGLEventListener((JOGLEngine) this.pickingEngine);
		}

		this.pickingEngine = pickingEngine;

		addGLEventListener((JOGLEngine) pickingEngine);
	}

	@Override
	public void setRenderingEngine(final RenderingEngine renderingEngine)
	{
		if (this.renderingEngine != null)
		{
			removeGLEventListener((JOGLEngine) this.renderingEngine);
		}

		this.renderingEngine = renderingEngine;

		addGLEventListener((JOGLEngine) renderingEngine);
	}

	@Override
	public void setWidth(final int width)
	{
		setSize(width, getHeight());
	}
}
