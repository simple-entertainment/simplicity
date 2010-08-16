package com.se.simplicity.jogl.test.picking;

import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.jogl.picking.SimpleJOGLPicker;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.jogl.rendering.SimpleJOGLPicker SimpleJOGLPicker}.
 * </p>
 * 
 * @author simple
 */
public class SimpleJOGLPickerTest
{
	/**
	 * An instance of the class being unit tested.
	 */
	private SimpleJOGLPicker testObject;

	/**
	 * <p>
	 * Setup to perform before each unit test.
	 * </p>
	 */
	@Before
	public void before()
	{
		testObject = new SimpleJOGLPicker();
	}

	/**
	 * Unit test the method {@link com.se.simplicity.jogl.picking.SimpleJOGLPicker.pickSceneGraph pickSceneGraph()}.
	 */
	@Test
	@Ignore("Need to know about the select buffer contents")
	public void pickSceneGraph()
	{}
}
