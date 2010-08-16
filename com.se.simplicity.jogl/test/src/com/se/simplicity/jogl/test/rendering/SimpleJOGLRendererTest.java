package com.se.simplicity.jogl.test.rendering;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.jogl.rendering.SimpleJOGLRenderer;

/**
 * TODO Complete set of tests
 * 
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderer SimpleJOGLRenderer}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLRendererTest
{
	/**
	 * An instance of the class being unit tested.
	 */
	private SimpleJOGLRenderer testObject;

	/**
	 * <p>
	 * Setup to perform before each unit test.
	 * </p>
	 */
	@Before
	public final void before()
	{
		testObject = new SimpleJOGLRenderer();
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderer.init init()}.
	 * </p>
	 */
	@Test
	public void init()
	{
		// TODO include SimpleJOGLRenderer testing
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderer.setCamera setCamera()}.
	 * </p>
	 */
	@Test
	public void setCamera()
	{
		// TODO include SimpleJOGLRenderer testing
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderer.display display()} with the special
	 * condition that the {@link com.se.simplicity.jogl.rendering.SimpleJOGLRenderer SimpleJOGLRenderer} being tested does not
	 * have a {@link com.se.simplicity.rendering.Camera Camera} to view through.
	 * </p>
	 */
	@Test(expected = IllegalStateException.class)
	public void displayNoCamera()
	{
		//testObject.;
	}
}
