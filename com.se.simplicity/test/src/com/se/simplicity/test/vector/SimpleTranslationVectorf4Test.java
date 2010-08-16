package com.se.simplicity.test.vector;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.vector.SimpleTranslationVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.vector.SimpleTranslationVectorf4 SimpleTranslationVectorf4}.
 * </p>
 * 
 * @author simple
 */
public class SimpleTranslationVectorf4Test
{
	/**
	 * An instance of the class being unit tested.
	 */
	private SimpleTranslationVectorf4 testObject;

	/**
	 * <p>
	 * Setup to perform before each unit test.
	 * </p>
	 */
	@Before
	public void before()
	{
		testObject = new SimpleTranslationVectorf4();
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTranslationVectorf4.translateX translateX()}.
	 * </p>
	 */
	@Test
	public void translateX()
	{
		testObject.setX(1.0f);
		testObject.translateX(1.0f);
		
		assertEquals(2.0f, testObject.getX(), 0.0f);
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTranslationVectorf4.translateY translateY()}.
	 * </p>
	 */
	@Test
	public void translateY()
	{
		testObject.setY(1.0f);
		testObject.translateY(1.0f);
		
		assertEquals(2.0f, testObject.getY(), 0.0f);
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.SimpleTranslationVectorf4.translateZ translateZ()}.
	 * </p>
	 */
	@Test
	public void translateZ()
	{
		testObject.setZ(1.0f);
		testObject.translateZ(1.0f);
		
		assertEquals(2.0f, testObject.getZ(), 0.0f);
	}
}
