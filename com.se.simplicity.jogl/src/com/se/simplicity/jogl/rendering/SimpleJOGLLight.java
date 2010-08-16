package com.se.simplicity.jogl.rendering;

import javax.media.opengl.GL;

import org.apache.log4j.Logger;

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.jogl.JOGLComponent;
import com.se.simplicity.rendering.Light;
import com.se.simplicity.rendering.LightingMode;
import com.se.simplicity.scenegraph.Node;
import com.se.simplicity.vector.ArrayBackedObjectf;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A light within a <code>SceneGraph</code> rendered by a JOGL rendering environment. This implementation uses only simple
 * lighting techniques and properties.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLLight implements Light, JOGLComponent
{
	/**
	 * <p>
	 * The ambient component of this <code>Light</code>.
	 * </p>
	 */
	private float[] ambientLight;

	/**
	 * <p>
	 * The diffuse component of this <code>Light</code>.
	 * </p>
	 */
	private float[] diffuseLight;
	
	/**
	 * <p>
	 * The JOGL rendering environment.
	 * </p>
	 */
	protected GL gl;

	/**
	 * <p>
	 * The initialisation status. Determines if this <code>Light</code> is initialised.
	 * </p>
	 */
	private boolean isInitialised;

	/**
	 * <p>
	 * The lighting mode used to render the {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 */
	private LightingMode lightingMode;
	
	/**
	 * <p>
	 * Logs messages associated with this class.
	 * </p>
	 */
	private Logger logger;

	/**
	 * <p>
	 * The node that represents this <code>Light</code>'s location and orientation of this light.
	 * </p>
	 */
	private Node node;

	/**
	 * <p>
	 * The specular component of this <code>Light</code>.
	 * </p>
	 */
	private float[] specularLight;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleJOGLLight</code>.
	 * </p>
	 */
	public SimpleJOGLLight()
	{
		ambientLight = null;
		diffuseLight = null;
		isInitialised = false;
		lightingMode = LightingMode.SCENE;
		logger = Logger.getLogger(getClass().getName());
		node = null;
		specularLight = null;
	}

	@Override
	public void apply()
	{
		if (!isInitialised)
		{
			init();
		}

		gl.glLightfv(GL.GL_LIGHT0, GL.GL_POSITION, ((ArrayBackedObjectf) getTransformation()).getArray(), 0);
		gl.glLightfv(GL.GL_LIGHT0, GL.GL_AMBIENT, ambientLight, 0);
		gl.glLightfv(GL.GL_LIGHT0, GL.GL_DIFFUSE, diffuseLight, 0);
		gl.glLightfv(GL.GL_LIGHT0, GL.GL_SPECULAR, specularLight, 0);
	}

	@Override
	public float[] getAmbientLight()
	{
		return (ambientLight);
	}

	@Override
	public float[] getDiffuseLight()
	{
		return (diffuseLight);
	}

	@Override
	public GL getGL()
	{
		return (gl);
	}

	@Override
	public LightingMode getLightingMode()
	{
		return (lightingMode);
	}

	@Override
	public Node getNode()
	{
		return (node);
	}

	@Override
	public float[] getSpecularLight()
	{
		return (specularLight);
	}

	@Override
	public TransformationMatrixf getTransformation()
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
		catch (SEInvalidOperationException e)
		{
			logger.error("Failed to invert the transformation.", e);
		}

		return (transformation);
	}

	@Override
	public void init()
	{		
		if (lightingMode == LightingMode.SOLID)
		{
			gl.glDisable(GL.GL_LIGHTING);
			gl.glDisable(GL.GL_COLOR_MATERIAL);
			gl.glDisable(GL.GL_LIGHT0);
		}

		if (lightingMode == LightingMode.SHADED)
		{
			gl.glEnable(GL.GL_LIGHTING);
			gl.glEnable(GL.GL_COLOR_MATERIAL);
			gl.glColorMaterial(GL.GL_FRONT_AND_BACK, GL.GL_AMBIENT_AND_DIFFUSE);
			gl.glLightfv(GL.GL_LIGHT0, GL.GL_AMBIENT, new float[] {0.1f, 0.1f, 0.1f}, 0);
			gl.glLightfv(GL.GL_LIGHT0, GL.GL_DIFFUSE, new float[] {0.1f, 0.1f, 0.1f}, 0);
			gl.glLightfv(GL.GL_LIGHT0, GL.GL_SPECULAR, new float[] {0.1f, 0.1f, 0.1f}, 0);
			gl.glEnable(GL.GL_LIGHT0);
		}

		if (lightingMode == LightingMode.SCENE)
		{
			gl.glEnable(GL.GL_LIGHTING);
			gl.glEnable(GL.GL_COLOR_MATERIAL);
			gl.glColorMaterial(GL.GL_FRONT_AND_BACK, GL.GL_AMBIENT_AND_DIFFUSE);
			gl.glEnable(GL.GL_LIGHT0);
		}
	}

	@Override
	public boolean isInitialised()
	{
		return (isInitialised);
	}

	@Override
	public void setAmbientLight(final float[] ambientLight)
	{
		this.ambientLight = ambientLight;
	}

	@Override
	public void setDiffuseLight(final float[] diffuseLight)
	{
		this.diffuseLight = diffuseLight;
	}

	@Override
	public void setGL(GL gl)
	{
		this.gl = gl;		
	}

	@Override
	public void setInitialised(final boolean isInitialised)
	{
		this.isInitialised = isInitialised;
	}

	@Override
	public void setLightingMode(final LightingMode lightingMode)
	{
		this.lightingMode = lightingMode;

		isInitialised = false;
	}

	@Override
	public void setNode(final Node node)
	{
		this.node = node;
	}

	@Override
	public void setSpecularLight(final float[] specularLight)
	{
		this.specularLight = specularLight;
	}
}
