package com.se.simplicity.test.vector;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

import com.se.simplicity.vector.ArrayBackedObjectf;
import com.se.simplicity.vector.SimpleVectorf4;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.vector.ArrayBackedObjectf ArrayBackedObjectf}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class ArrayBackedObjectfTest
{
	/**
	 * An instance of the class being unit tested.
	 */
	private ArrayBackedObjectf testObject;
	
	/**
	 * <p>
	 * Setup to perform before each unit test.
	 * </p>
	 */
	@Before
	public void before()
	{
		testObject = new SimpleVectorf4();
	}
	
	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.vector.ArrayBackedObjectf.getArrayCopy getArrayCopy()}.
	 * </p>
	 */
	@Test
	public void getArrayCopy()
	{
		assertNotNull(testObject.getArrayCopy());
		assertNotSame(testObject.getArray(), testObject.getArrayCopy());
		assertNotSame(testObject.getArrayCopy(), testObject.getArrayCopy());
		
		float[] arrayCopy1 = testObject.getArrayCopy();
		float[] arrayCopy2 = testObject.getArrayCopy();
		
		for (int index = 0; index < arrayCopy1.length; index++)
		{
			assertEquals(arrayCopy1[index], arrayCopy2[index], 0.0f);
		}
	}
}
