package com.se.simplicity.test.vector;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.SimpleTranslationVectorf4;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.vector.SimpleTransformationMatrixf44 SimpleTransformationMatrixf44}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleTransformationMatrixf44Test
{
	/**
	 * An instance of the class being unit tested.
	 */
	private SimpleTransformationMatrixf44 testObject;

	/**
	 * <p>
	 * Setup to perform before each unit test.
	 * </p>
	 */
	@Before
	public void before()
	{
		testObject = new SimpleTransformationMatrixf44();
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.getXAxisRotation getXAxisRotation()}.
	 * </p>
	 */
	@Test
	@Ignore("Not implemented")
	public void getXAxisRotation()
	{ }
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.getYAxisRotation getYAxisRotation()}.
	 * </p>
	 */
	@Test
	@Ignore("Not implemented")
	public void getYAxisRotation()
	{ }
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.getZAxisRotation getZAxisRotation()}.
	 * </p>
	 */
	@Test
	@Ignore("Not implemented")
	public void getZAxisRotation()
	{ }
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.rotate rotate()}.
	 * </p>
	 */
	@Test
	public void rotate()
	{
		float[] array = testObject.getArray();

		testObject.rotate((float) Math.PI / 2.0f, new SimpleVectorf4(0.0f, 1.0f, 0.0f, 1.0f));

		assertEquals(0.0f, array[0], 0.0000001f);
		assertEquals(0.0f, array[1], 0.0000001f);
		assertEquals(-1.0f, array[2], 0.0000001f);
		assertEquals(0.0f, array[4], 0.0000001f);
		assertEquals(1.0f, array[5], 0.0000001f);
		assertEquals(0.0f, array[6], 0.0000001f);
		assertEquals(1.0f, array[8], 0.0000001f);
		assertEquals(0.0f, array[9], 0.0000001f);
		assertEquals(0.0f, array[10], 0.0000001f);
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.setXAxisRotation setXAxisRotation()}.
	 * </p>
	 */
	@Test
	@Ignore("Not implemented")
	public void setXAxisRotation()
	{ }
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.setYAxisRotation setYAxisRotation()}.
	 * </p>
	 */
	@Test
	@Ignore("Not implemented")
	public void setYAxisRotation()
	{ }
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.setZAxisRotation setZAxisRotation()}.
	 * </p>
	 */
	@Test
	@Ignore("Not implemented")
	public void setZAxisRotation()
	{ }

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTransformationMatrixf44.translate translate()}.
	 * </p>
	 */
	@Test
	public void translate()
	{
		float[] array = testObject.getArray();
		
		array[12] = 1.0f;
		array[13] = 2.0f;
		array[14] = 3.0f;

		testObject.translate(new SimpleTranslationVectorf4(1.0f, 2.0f, 3.0f, 1.0f));
		
		assertEquals(2.0f, array[12], 0.0f);
		assertEquals(4.0f, array[13], 0.0f);
		assertEquals(6.0f, array[14], 0.0f);
	}
}
