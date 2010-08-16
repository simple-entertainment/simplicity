package com.se.simplicity.jogl.rendering;

// JOGL imports.
import javax.media.opengl.GL;

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.rendering.Camera;
import com.se.simplicity.rendering.ProjectionMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A viewpoint within a <code>SceneGraph</code> rendered by a JOGL rendering environment. This implementation uses only simple
 * camera techniques and properties.
 * </p>
 * 
 * <p>
 * NEED A DIAGRAM TO EXPLAIN FRUSTUM AND THE RELATIONSHIP TO COMPONENTS IN THE CAMERA.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLCamera implements Camera, JOGLComponent
{
	/**
	 * <p>
	 * The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
	 * </p>
	 */
	private float farClippingDistance;

	/**
	 * <p>
	 * The aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75).
	 * </p>
	 */
	private float frameAspectRatio;

	/**
	 * <p>
	 * The width of the frame.
	 * </p>
	 */
	private float frameWidth;

	/**
	 * <p>
	 * The location of the frame on the <code>x</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 * </p>
	 */
	private float frameX;

	/**
	 * <p>
	 * The location of the frame on the <code>y</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 * </p>
	 */
	private float frameY;

	/**
	 * <p>
	 * The JOGL rendering environment.
	 * </p>
	 */
	protected GL gl;

	/**
	 * The initialisation status. Determines if this <code>SimpleJOGLCamera</code> is initialised.
	 */
	private boolean isInitialised;

	/**
	 * <p>
	 * The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
	 * </p>
	 */
	private float nearClippingDistance;

	/**
	 * <p>
	 * The <code>Node</code> that represents this <code>SimpleJOGLCamera</code>'s location and orientation.
	 * </p>
	 */
	private Node node;

	/**
	 * <p>
	 * The projection mode used to render a <code>SceneGraph</code>.
	 * </p>
	 */
	private ProjectionMode projectionMode;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleJOGLCamera</code>.
	 * </p>
	 */
	public SimpleJOGLCamera()
	{
		frameAspectRatio = 0.75f; // 3:4
		farClippingDistance = 1000.0f;
		frameWidth = 0.1f;
		frameX = 0.0f;
		frameY = 0.0f;
		isInitialised = false;
		nearClippingDistance = 0.1f;
		node = null;
		projectionMode = ProjectionMode.PERSPECTIVE;
	}

	@Override
	public void apply()
	{
		if (!isInitialised)
		{
			init();
		}

		gl.glMultMatrixf(((SimpleTransformationMatrixf44) getTransformation()).getArray(), 0);
	}

	/**
	 * <p>
	 * Retrieves the distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
	 * </p>
	 * 
	 * @return The distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
	 */
	public float getFarClippingDistance()
	{
		return (farClippingDistance);
	}

	/**
	 * <p>
	 * Retrieves the aspect ratio of the frame.
	 * </p>
	 * 
	 * @return The aspect ratio of the frame.
	 */
	public float getFrameAspectRatio()
	{
		return (frameAspectRatio);
	}

	/**
	 * <p>
	 * Retrieves the width of the frame.
	 * </p>
	 * 
	 * @return The width of the frame.
	 */
	public float getFrameWidth()
	{
		return (frameWidth);
	}

	/**
	 * <p>
	 * Retrieves the location of the frame on the <code>x</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 * </p>
	 * 
	 * @return The location of the frame on the <code>x</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 */
	public float getFrameX()
	{
		return (frameX);
	}

	/**
	 * <p>
	 * Retrieves the location of the frame on the <code>y</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 * </p>
	 * 
	 * @return The location of the frame on the <code>y</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 */
	public float getFrameY()
	{
		return (frameY);
	}

	@Override
	public final GL getGL()
	{
		return (gl);
	}

	/**
	 * <p>
	 * Retrieves the distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
	 * </p>
	 * 
	 * @return The distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
	 */
	public float getNearClippingDistance()
	{
		return (nearClippingDistance);
	}

	@Override
	public final Node getNode()
	{
		return (node);
	}

	/**
	 * <p>
	 * Retrieves the projection mode used to render a <code>SceneGraph</code>.
	 * </p>
	 * 
	 * @return The projection mode used to render a <code>SceneGraph</code>.
	 */
	public final ProjectionMode getProjectionMode()
	{
		return (projectionMode);
	}

	@Override
	public final TransformationMatrixf getTransformation()
	{
		if (node == null)
		{
			return (null);
		}

		TransformationMatrixf transformation = new SimpleTransformationMatrixf44();
		Node currentNode = node;

		while (currentNode != null)
		{
			transformation.multiplyRight(currentNode.getTransformation());

			currentNode = currentNode.getParent();
		}

		try
		{
			transformation.invert();
		}
		catch (SEInvalidOperationException ex)
		{
			// TODO Implement log4j
			// TODO Search for all System.out.println and printStackTrace instances and replace with log4j

			ex.printStackTrace();
		}

		return (transformation);
	}

	@Override
	public void init()
	{
		if (projectionMode == null)
		{
			throw new IllegalStateException("This Camera must have a projection mode to be initialised.");
		}

		gl.glMatrixMode(GL.GL_PROJECTION);

		gl.glLoadIdentity();
		gl.glFrustum(-frameWidth / 2 + frameX, frameWidth / 2 + frameX, -frameWidth * frameAspectRatio / 2 + frameY, frameWidth
				* frameAspectRatio / 2 + frameY, nearClippingDistance, farClippingDistance);

		gl.glMatrixMode(GL.GL_MODELVIEW);

		isInitialised = true;
	}

	@Override
	public final boolean isInitialised()
	{
		return (isInitialised);
	}

	/**
	 * <p>
	 * Sets the distance from the eye past which components of the <code>SceneGraph</code> will be clipped (not drawn).
	 * </p>
	 * 
	 * @param farClippingDistance The distance from the eye past which components of the <code>SceneGraph</code> will be clipped
	 * (not drawn).
	 */
	public void setFarClippingDistance(final float farClippingDistance)
	{
		this.farClippingDistance = farClippingDistance;

		isInitialised = false;
	}

	/**
	 * <p>
	 * Sets the aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75).
	 * </p>
	 * 
	 * @param frameAspectRatio The aspect ratio of the frame. An aspect ratio of 3:4 is stored as 3 / 4 (0.75).
	 */
	public void setFrameAspectRatio(final float frameAspectRatio)
	{
		this.frameAspectRatio = frameAspectRatio;

		isInitialised = false;
	}

	/**
	 * <p>
	 * Sets the width of the frame.
	 * </p>
	 * 
	 * @param frameWidth The width of the frame.
	 */
	public void setFrameWidth(final float frameWidth)
	{
		this.frameWidth = frameWidth;

		isInitialised = false;
	}

	/**
	 * <p>
	 * Sets the location of the frame on the <code>x</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 * </p>
	 * 
	 * @param frameX The location of the frame on the <code>x</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 */
	public void setFrameX(final float frameX)
	{
		this.frameX = frameX;

		isInitialised = false;
	}

	/**
	 * <p>
	 * Sets the location of the frame on the <code>y</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 * </p>
	 * 
	 * @param frameY The location of the frame on the <code>y</code> axis relative to the location and orientation of this
	 * <code>SimpleJOGLCamera</code>.
	 */
	public void setFrameY(final float frameY)
	{
		this.frameY = frameY;

		isInitialised = false;
	}

	@Override
	public final void setGL(final GL gl)
	{
		this.gl = gl;

		isInitialised = false;
	}

	@Override
	public final void setInitialised(final boolean isInitialised)
	{
		this.isInitialised = isInitialised;
	}

	/**
	 * <p>
	 * Sets the distance from the eye before which components of the <code>SceneGraph</code> will be clipped (not drawn).
	 * </p>
	 * 
	 * @param nearClippingDistance The distance from the eye before which components of the <code>SceneGraph</code> will be
	 * clipped (not drawn).
	 */
	public void setNearClippingDistance(final float nearClippingDistance)
	{
		this.nearClippingDistance = nearClippingDistance;

		isInitialised = false;
	}

	@Override
	public final void setNode(final Node node)
	{
		this.node = node;
	}

	/**
	 * <p>
	 * Sets the projection mode used to render a <code>SceneGraph</code>.
	 * </p>
	 * 
	 * @param projectionMode The projection mode used to render a <code>SceneGraph</code>.
	 */
	public final void setProjectionMode(final ProjectionMode projectionMode)
	{
		this.projectionMode = projectionMode;
	}
}
