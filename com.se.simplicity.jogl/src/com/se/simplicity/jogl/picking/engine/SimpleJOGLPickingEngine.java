package com.se.simplicity.jogl.picking.engine;

import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.Logger;

import com.se.simplicity.jogl.engine.JOGLEngine;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.picking.Pick;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.picking.engine.PickingEngine;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.engine.RenderingEngine;
import com.se.simplicity.scenegraph.SceneGraph;
import com.se.simplicity.viewport.Viewport;

/**
 * <p>
 * Manages the picking of a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. This implementation uses only simple
 * picking techniques and properties.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLPickingEngine extends JOGLEngine implements PickingEngine
{
	/**
	 * The viewpoint that will be adapted to create the picking viewpoint.
	 */
	private Camera camera;

	/**
	 * <p>
	 * The <code>PickListener</code>s to be invoked when a <code>SceneGraph</code> is picked.
	 * </p>
	 */
	private List<PickListener> listeners;

	/**
	 * <p>
	 * Logs messages associated with this class.
	 * </p>
	 */
	private Logger logger;

	/**
	 * <p>
	 * The <code>Picker</code> that picks the <code>SceneGraph</code> for this <code>SimpleJOGLPickingEngine</code>.
	 * </p>
	 */
	private Picker picker;

	/**
	 * <p>
	 * The outstanding picks to be performed against a <code>SceneGraph</code>.
	 * </p>
	 */
	private List<Pick> picks;

	/**
	 * <p>
	 * The preferred frequency (advancements per second) of this <code>SimpleJOGLPickingEngine</code>.
	 * </p>
	 */
	private int preferredFrequency;

	/**
	 * <p>
	 * The <code>RenderingEngine</code> whos <code>SceneGraph</code> and <code>Camera</code> are used when picking.
	 * </p>
	 */
	private RenderingEngine renderingEngine;

	/**
	 * <p>
	 * The <code>SceneGraph</code> whose components will be picked.
	 * </p>
	 */
	private SceneGraph sceneGraph;

	/**
	 * <p>
	 * Creates an instance of <code>JOGLPickingEngine</code>.
	 * </p>
	 */
	public SimpleJOGLPickingEngine()
	{
		listeners = new ArrayList<PickListener>();
		logger = Logger.getLogger(getClass().getName());
		picks = new ArrayList<Pick>();
	}

	@Override
	public void addPickListener(final PickListener listener)
	{
		listeners.add(listener);
	}

	@Override
	public void advance()
	{
		if (picks.isEmpty())
		{
			return;
		}

		// Update the Scene Graph and Camera to reflect the Rendering Engine if this Picking Engine is using one.
		if (renderingEngine != null)
		{
			sceneGraph = renderingEngine.getSceneGraph();
			camera = renderingEngine.getCamera();
		}

		// For every pick.
		for (Pick pick : picks)
		{
			firePickEvent(picker.pickSceneGraph(sceneGraph, camera, pick));
		}

		picks.clear();
	}

	/**
	 * <p>
	 * Converts the coordinates of the given <code>Pick</code> from <code>Viewport</code> coordinates to
	 * <code>SceneGraph</code> coordinates.
	 * </p>
	 * 
	 * @param viewport The <code>Viewport</code> from which the original coordinates were retrieved.
	 * @param pick The <code>Pick</code> to convert the coordinates of.
	 * 
	 * @return A <code>Pick</code> with <code>SceneGraph</code> coordinates.
	 */
	public Pick convertPickCoordinatesFromViewportToSceneGraph(final Viewport viewport, final Pick pick)
	{
		SimpleJOGLCamera camera = (SimpleJOGLCamera) this.camera;

		pick.setHeight((float) pick.getHeight() / (float) viewport.getHeight()
				* (camera.getFrameWidth() * camera.getFrameAspectRatio()));
		pick.setWidth((float) pick.getWidth() / (float) viewport.getWidth() * camera.getFrameWidth());
		pick.setX(((float) pick.getX() / (float) viewport.getWidth() * camera.getFrameWidth()));
		pick.setY(((float) pick.getY() / (float) viewport.getHeight() * (camera.getFrameWidth() * camera.getFrameAspectRatio())));

		return (pick);
	}

	@Override
	public void destroy()
	{}

	@Override
	public void firePickEvent(final PickEvent event)
	{
		for (PickListener listener : listeners)
		{
			listener.scenePicked(event);
		}
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
	public List<Pick> getPicks()
	{
		return (picks);
	}

	@Override
	public int getPreferredFrequency()
	{
		return (preferredFrequency);
	}

	/**
	 * <p>
	 * Retrieves the <code>RenderingEngine</code> whos <code>SceneGraph</code> and <code>Camera</code> are used when
	 * picking.
	 * </p>
	 * 
	 * @return The <code>RenderingEngine</code> whos <code>SceneGraph</code> and <code>Camera</code> are used when picking.
	 */
	public RenderingEngine getRenderingEngine()
	{
		return (renderingEngine);
	}

	@Override
	public SceneGraph getSceneGraph()
	{
		return (sceneGraph);
	}

	@Override
	public void init()
	{}

	@Override
	public void pick(final float x, final float y, final float width, final float height)
	{
		Pick pick = new Pick();
		pick.setX(x);
		pick.setY(y);
		pick.setWidth(width);
		pick.setHeight(height);

		picks.add(pick);
	}

	@Override
	public void pick(final Pick pick)
	{
		picks.add(pick);
	}

	@Override
	public void pickViewport(final Viewport viewport, final int x, final int y, final int width, final int height)
	{
		Pick pick = new Pick();
		pick.setX(x);
		pick.setY(y);
		pick.setWidth(width);
		pick.setHeight(height);

		picks.add(convertPickCoordinatesFromViewportToSceneGraph(viewport, pick));
	}

	@Override
	public void pickViewport(final Viewport viewport, final Pick pick)
	{
		picks.add(convertPickCoordinatesFromViewportToSceneGraph(viewport, pick));
	}

	@Override
	public void removePickListener(final PickListener listener)
	{
		listeners.remove(listener);
	}

	@Override
	public void reset()
	{}

	@Override
	public void run()
	{
		init();

		while (!Thread.interrupted())
		{
			sleep();
			advance();
		}

		destroy();
	}

	@Override
	public void setCamera(final Camera camera)
	{
		this.camera = camera;
	}

	@Override
	public void setPicker(Picker picker)
	{
		this.picker = picker;
	}

	@Override
	public void setPreferredFrequency(int preferredFrequency)
	{
		this.preferredFrequency = preferredFrequency;
	}

	/**
	 * <p>
	 * Sets the <code>RenderingEngine</code> whos <code>SceneGraph</code> and <code>Camera</code> are used when picking. The
	 * ability to set a <code>RenderingEngine</code> is a convenience as in most cases picking will be associated with a
	 * particular rendered image. This <code>SimpleJOGLPickingEngine</code> synchronises the <code>SceneGraph</code> and
	 * <code>Camera</code> from the <code>RenderingEngine</code> every time it advances.
	 * </p>
	 * 
	 * @param renderingEngine The <code>RenderingEngine</code> whos <code>SceneGraph</code> and <code>Camera</code> are used
	 * when picking.
	 */
	public void setRenderingEngine(final RenderingEngine renderingEngine)
	{
		this.renderingEngine = renderingEngine;
	}

	@Override
	public void setSceneGraph(final SceneGraph sceneGraph)
	{
		this.sceneGraph = sceneGraph;
	}

	/**
	 * <p>
	 * Causes this <code>SimpleJOGLPickingEngine</code> to sleep for the appropriate amount of time to allow for its preferred
	 * frequency.
	 * </p>
	 */
	protected void sleep()
	{
		try
		{
			Thread.sleep((long) 1000.0 / preferredFrequency);
		}
		catch (InterruptedException e)
		{
			Thread.currentThread().interrupt();

			logger.debug("The engine was interrupted while sleeping.");
		}
	}
}
