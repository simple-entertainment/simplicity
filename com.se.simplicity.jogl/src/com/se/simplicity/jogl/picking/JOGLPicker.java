package com.se.simplicity.jogl.picking;

// J2SE imports.
import java.awt.Component;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.List;

// JOGL imports.
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLEventListener;

// simplicity imports.
import com.se.simplicity.jogl.rendering.JOGLComponent;
import com.se.simplicity.picking.Picker;
import com.se.simplicity.picking.event.PickEvent;
import com.se.simplicity.picking.event.PickListener;
import com.se.simplicity.rendering.Viewport;

/**
 * <p>
 * A <code>Picker</code> for use with a JOGL rendering environment.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public abstract class JOGLPicker implements Picker, JOGLComponent, GLEventListener
{
	/**
	 * <p>
	 * The JOGL rendering environment.
	 * </p>
	 */
	private GL gl;

	/**
	 * <p>
	 * The {@link com.se.simplicity.picking.event.PickListener PickListener}s to be invoked when a
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} is picked.
	 * </p>
	 */
	private List<PickListener> listeners;

	/**
	 * <p>
	 * The outstanding picks to be performed against a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 */
	private List<Object> picks;

	/**
	 * <p>
	 * The capacity of the select buffer used by the JOGL rendering environment. This capacity determines how much hit data can be
	 * retrieved when picking a <code>SceneGraph</code>.
	 * </p>
	 */
	private int selectBufferCapacity;

	/**
	 * <p>
	 * The <code>Viewport</code> this <code>JOGLPicker</code> has applied picking to.
	 * </p>
	 */
	private Viewport viewport;

	/**
	 * <p>
	 * Creates an instance of <code>JOGLPicker</code>.
	 * </p>
	 */
	public JOGLPicker()
	{
		listeners = new ArrayList<PickListener>();
		picks = new ArrayList<Object>();
		selectBufferCapacity = 2048;
	}

	@Override
	public void addPickListener(final PickListener listener)
	{
		listeners.add(listener);
	}

	@Override
	public void applyMousePicking(final Viewport viewport)
	{
		if (this.viewport != null)
		{
			throw new IllegalStateException("This JOGLPicker is already assigned to a Viewport.");
		}

		if (this.viewport != viewport)
		{
			this.viewport = viewport;

			((Component) viewport).addMouseListener(new MouseAdapter()
			{
				public void mouseClicked(final MouseEvent event)
				{
					if (event.getButton() == MouseEvent.BUTTON1)
					{
						pick(event.getX(), event.getY(), 2, 2);
					}
				}
			});
		}
	}

	@Override
	public void display(final GLAutoDrawable drawable)
	{
		pickSceneGraph();
	}

	@Override
	public void displayChanged(final GLAutoDrawable drawable, final boolean modeChanged, final boolean deviceChanged)
	{}

	@Override
	public void firePickEvent(final PickEvent event)
	{
		for (int index = 0; index < listeners.size(); index++)
		{
			listeners.get(index).scenePicked(event);
		}
	}

	@Override
	public GL getGL()
	{
		return (gl);
	}

	@Override
	public List<Object> getPicks()
	{
		return (picks);
	}
	
	/**
	 * <p>
	 * Retrieves the capacity of the select buffer used by the JOGL rendering environment.
	 * </p>
	 * 
	 * @return The capacity of the select buffer used by the JOGL rendering environment.
	 */
	public int getSelectBufferCapacity()
	{
		return (selectBufferCapacity);
	}
	
	@Override
	public Viewport getViewport()
	{
		return (viewport);
	}

	@Override
	public void init(final GLAutoDrawable drawable)
	{
		gl = drawable.getGL();
	}

	@Override
	public void pick(final int x, final int y, final int width, final int height)
	{
		picks.add(new int[] {x, y, width, height});
	}

	@Override
	public void pickSceneGraph()
	{
		if (picks.isEmpty())
		{
			return;
		}
	}

	@Override
	public void removePickListener(final PickListener listener)
	{
		listeners.remove(listener);
	}

	@Override
	public void reshape(final GLAutoDrawable drawable, final int x, final int y, final int width, final int height)
	{}

	@Override
	public void setGL(final GL gl)
	{
		this.gl = gl;
	}

	/**
	 * <p>
	 * Sets the capacity of the select buffer used by the JOGL rendering environment.
	 * </p>
	 * 
	 * @param selectBufferCapacity The capacity of the select buffer used by the JOGL rendering environment.
	 */
	public void setSelectBufferCapacity(final int selectBufferCapacity)
	{
		this.selectBufferCapacity = selectBufferCapacity;
	}
}
