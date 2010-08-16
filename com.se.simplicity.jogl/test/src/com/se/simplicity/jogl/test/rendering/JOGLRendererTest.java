package com.se.simplicity.jogl.test.rendering;

import static org.easymock.EasyMock.*;
import static org.easymock.classextension.EasyMock.*;

import javax.media.opengl.GL;

import org.junit.Test;

import com.se.simplicity.jogl.rendering.JOGLRenderer;
import com.se.simplicity.jogl.rendering.SimpleJOGLCamera;
import com.se.simplicity.jogl.rendering.SimpleJOGLLight;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.JOGLRenderer JOGLRenderer}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
 */
public abstract class JOGLRendererTest
{
	/**
	 * An instance of the class being unit tested.
	 */
	private JOGLRenderer testObject;
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.JOGLRenderer.init init()}.
	 * </p>
	 */
	@Test
	public void init()
	{
		GL mockGL = createMock(GL.class);
		
		SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);
		mockCamera.setGL(mockGL);
		
		SimpleJOGLLight mockLight1 = createMock(SimpleJOGLLight.class);
		mockLight1.setGL(mockGL);
		SimpleJOGLLight mockLight2 = createMock(SimpleJOGLLight.class);
		mockLight2.setGL(mockGL);
		
		testObject.setGL(mockGL);
		testObject.setCamera(mockCamera);
		testObject.addLight(mockLight1);
		testObject.addLight(mockLight2);
		
		replay();
		
		testObject.init();
		
		verify();
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.JOGLRenderer.setCamera setCamera()}.
	 * </p>
	 */
	@Test
	public void setCamera()
	{
		SimpleJOGLCamera mockCamera = createMock(SimpleJOGLCamera.class);
		mockCamera.setGL(null);
		
		replay();
		
		testObject.setCamera(mockCamera);
		
		verify();
	}
	
	/**
	 * <p>
	 * Sets the instance of the class being unit tested.
	 * </p>
	 * 
	 * @param testObject The instance of the class being unit tested.
	 */
	public void setJOGLRenderer(final JOGLRenderer testObject)
	{
		this.testObject = testObject;
	}
}
