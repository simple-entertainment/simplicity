package com.se.simplicity.test.model;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import com.se.simplicity.SEInvalidOperationException;
import com.se.simplicity.model.ArrayVG;

/**
 * <p>
 * Unit tests for the class {@link com.se.simplicity.model.ArrayVG ArrayVG}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class ArrayVGTest
{
	/**
	 * An instance of the class being unit tested.
	 */
	private ArrayVG testObject;

	/**
	 * <p>
	 * Setup to perform before each unit test.
	 * </p>
	 */
	@Before
	public void before()
	{
		testObject = new ArrayVG();

		testObject.setColours(new float[] {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f});
		testObject.setNormals(new float[] {-0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f});
		testObject.setVertices(new float[] {-1.0f, -1.0f, 0.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f});
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.model.ArrayVG.createEdgeSubsetVG createEdgeSubsetVG()}.
	 * </p>
	 */
	@Test
	@Ignore("Not implemented")
	public void createEdgeSubsetVG()
	{ }

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.model.ArrayVG.createFaceSubsetVG createFaceSubsetVG()}.
	 * </p>
	 */
	@Test
	public void createFaceSubsetVG()
	{
		ArrayVG subsetVG = (ArrayVG) testObject.createFaceSubsetVG(0);

		float[] subsetColours = subsetVG.getColours();

		assertEquals(9, subsetColours.length, 0);
		assertEquals(1.0f, subsetColours[0], 0.0f);
		assertEquals(0.0f, subsetColours[1], 0.0f);
		assertEquals(0.0f, subsetColours[2], 0.0f);
		assertEquals(0.0f, subsetColours[3], 0.0f);
		assertEquals(1.0f, subsetColours[4], 0.0f);
		assertEquals(0.0f, subsetColours[5], 0.0f);
		assertEquals(0.0f, subsetColours[6], 0.0f);
		assertEquals(0.0f, subsetColours[7], 0.0f);
		assertEquals(1.0f, subsetColours[8], 0.0f);

		float[] subsetNormals = subsetVG.getNormals();

		assertEquals(9, subsetNormals.length, 0);
		assertEquals(-0.5f, subsetNormals[0], 0.0f);
		assertEquals(-0.5f, subsetNormals[1], 0.0f);
		assertEquals(0.0f, subsetNormals[2], 0.0f);
		assertEquals(-0.5f, subsetNormals[3], 0.0f);
		assertEquals(0.5f, subsetNormals[4], 0.0f);
		assertEquals(0.0f, subsetNormals[5], 0.0f);
		assertEquals(0.5f, subsetNormals[6], 0.0f);
		assertEquals(0.5f, subsetNormals[7], 0.0f);
		assertEquals(0.0f, subsetNormals[8], 0.0f);

		float[] subsetVertices = subsetVG.getVertices();

		assertEquals(9, subsetVertices.length, 0);
		assertEquals(-1.0f, subsetVertices[0], 0.0f);
		assertEquals(-1.0f, subsetVertices[1], 0.0f);
		assertEquals(0.0f, subsetVertices[2], 0.0f);
		assertEquals(-1.0f, subsetVertices[3], 0.0f);
		assertEquals(1.0f, subsetVertices[4], 0.0f);
		assertEquals(0.0f, subsetVertices[5], 0.0f);
		assertEquals(1.0f, subsetVertices[6], 0.0f);
		assertEquals(1.0f, subsetVertices[7], 0.0f);
		assertEquals(0.0f, subsetVertices[8], 0.0f);
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.model.ArrayVG.createVertexSubsetVG createVertexSubsetVG()}.
	 * </p>
	 */
	@Test
	public void createVertexSubsetVG()
	{
		ArrayVG subsetVG = (ArrayVG) testObject.createVertexSubsetVG(0);

		float[] subsetColours = subsetVG.getColours();

		assertEquals(3, subsetColours.length, 0);
		assertEquals(1.0f, subsetColours[0], 0.0f);
		assertEquals(0.0f, subsetColours[1], 0.0f);
		assertEquals(0.0f, subsetColours[2], 0.0f);

		float[] subsetNormals = subsetVG.getNormals();

		assertEquals(3, subsetNormals.length, 0);
		assertEquals(-0.5f, subsetNormals[0], 0.0f);
		assertEquals(-0.5f, subsetNormals[1], 0.0f);
		assertEquals(0.0f, subsetNormals[2], 0.0f);

		float[] subsetVertices = subsetVG.getVertices();

		assertEquals(3, subsetVertices.length, 0);
		assertEquals(-1.0f, subsetVertices[0], 0.0f);
		assertEquals(-1.0f, subsetVertices[1], 0.0f);
		assertEquals(0.0f, subsetVertices[2], 0.0f);
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.model.ArrayVG.mergeWithParent mergeWithParent()}.
	 * </p>
	 * 
	 * @throws SEInvalidOperationException Thrown by the method being unit tested.
	 */
	@Test
	public void mergeWithParent() throws SEInvalidOperationException
	{
		ArrayVG subsetVG = (ArrayVG) testObject.createFaceSubsetVG(0);

		subsetVG.setColours(new float[] {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f});
		subsetVG.setNormals(new float[] {0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f});
		subsetVG.setVertices(new float[] {-2.0f, -2.0f, 0.0f, -2.0f, 2.0f, 0.0f, 2.0f, 2.0f, 0.0f});

		subsetVG.mergeWithParent();

		float[] colours = testObject.getColours();

		assertEquals(12, colours.length, 0);
		assertEquals(0.0f, colours[0], 0.0f);
		assertEquals(0.0f, colours[1], 0.0f);
		assertEquals(1.0f, colours[2], 0.0f);
		assertEquals(0.0f, colours[3], 0.0f);
		assertEquals(1.0f, colours[4], 0.0f);
		assertEquals(0.0f, colours[5], 0.0f);
		assertEquals(1.0f, colours[6], 0.0f);
		assertEquals(0.0f, colours[7], 0.0f);
		assertEquals(0.0f, colours[8], 0.0f);
		assertEquals(1.0f, colours[9], 0.0f);
		assertEquals(1.0f, colours[10], 0.0f);
		assertEquals(1.0f, colours[11], 0.0f);

		float[] normals = testObject.getNormals();

		assertEquals(12, normals.length, 0);
		assertEquals(0.5f, normals[0], 0.0f);
		assertEquals(0.5f, normals[1], 0.0f);
		assertEquals(0.0f, normals[2], 0.0f);
		assertEquals(0.5f, normals[3], 0.0f);
		assertEquals(-0.5f, normals[4], 0.0f);
		assertEquals(0.0f, normals[5], 0.0f);
		assertEquals(-0.5f, normals[6], 0.0f);
		assertEquals(-0.5f, normals[7], 0.0f);
		assertEquals(0.0f, normals[8], 0.0f);
		assertEquals(0.5f, normals[9], 0.0f);
		assertEquals(-0.5f, normals[10], 0.0f);
		assertEquals(0.0f, normals[11], 0.0f);

		float[] vertices = testObject.getVertices();

		assertEquals(12, vertices.length, 0);
		assertEquals(-2.0f, vertices[0], 0.0f);
		assertEquals(-2.0f, vertices[1], 0.0f);
		assertEquals(0.0f, vertices[2], 0.0f);
		assertEquals(-2.0f, vertices[3], 0.0f);
		assertEquals(2.0f, vertices[4], 0.0f);
		assertEquals(0.0f, vertices[5], 0.0f);
		assertEquals(2.0f, vertices[6], 0.0f);
		assertEquals(2.0f, vertices[7], 0.0f);
		assertEquals(0.0f, vertices[8], 0.0f);
		assertEquals(1.0f, vertices[9], 0.0f);
		assertEquals(-1.0f, vertices[10], 0.0f);
		assertEquals(0.0f, vertices[11], 0.0f);
	}

	/**
	 * <p>
	 * Unit test the method {@link com.se.simplicity.model.ArrayVG.mergeWithParent mergeWithParent()} for the special condition
	 * where the {@link com.se.simplicity.model.ArrayVG ArrayVG} being tested is not a subset.
	 * </p>
	 * 
	 * @throws SEInvalidOperationException Thrown by the method being unit tested.
	 */
	@Test(expected = SEInvalidOperationException.class)
	public void mergeWithParentNotSubset() throws SEInvalidOperationException
	{
		testObject.mergeWithParent();
	}
}
