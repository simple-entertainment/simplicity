package com.se.simplicity.model;

import java.io.Serializable;

import com.se.simplicity.SEInvalidOperationException;

/**
 * <p>
 * A vertex group based on an array of vertices.
 * </p>
 * 
 * <p>
 * Three separate arrays are actually used to store the information for the vertices. One for the coordinates, one for the colours
 * and one for the surface normals.
 * </p>
 * 
 * <p>
 * Each vertex is stored as three consecutive values in each array as follows:
 * </p>
 * 
 * <pre>
 * coordinates = {x1, y1, z1, x2, y2, z2, x3, y3, z3,..}
 * colours = {r1, g1, b1, r2, g2, b2, r3, g3, b3,..}
 * surface normals = {x1, y1, z1, x2, y2, z2, x3, y3, z3,..}
 * </pre>
 * 
 * <p>
 * For all the arrays the numbers show which vertex the value relates to. For coordinates, the letters x, y and z show which axis
 * the value relates to. For colours the letters r, g and b show which component of the RGB colour model the value relates to. For
 * surface normals the letters x, y and z show which axis the value relates to.
 * </p>
 * 
 * @author simple
 */
public class ArrayVG implements VertexGroup, Serializable
{
	/**
	 * The serialisation version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * The colours of all the vertices in this <code>ArrayVG</code>.
	 */
	private float[] colours;

	/**
	 * <p>
	 * The index in the parent <code>ArrayVG</code> from which the data in this <code>ArrayVG</code> was copied.
	 * </p>
	 */
	private int indexWithinParent;

	/**
	 * <p>
	 * The subset status. Determines if this <code>ArrayVG</code> is a subgroup of a parent <code>ArrayVG</code>. Subset
	 * <code>ArrayVG</code>s contain a copy of a subset of the parent <code>ArrayVG</code>s data.
	 * </p>
	 */
	private boolean isSubset;

	/**
	 * The surface normals of all the vertices in this <code>ArrayVG</code>.
	 */
	private float[] normals;

	/**
	 * <p>
	 * The parent of this <code>ArrayVG</code>. The parent should be set to <code>null</code> unless this <code>ArrayVG</code> is
	 * a subset.
	 * </p>
	 */
	private VertexGroup parent;

	/**
	 * The coordinates of all the vertices in this <code>ArrayVG</code>.
	 */
	private float[] vertices;

	/**
	 * <p>
	 * Creates an instance of <code>ArrayVG</code>.
	 * </p>
	 */
	public ArrayVG()
	{
		indexWithinParent = -1;
		isSubset = false;
		parent = null;
	}

	/**
	 * <p>
	 * Creates an instance of <code>ArrayVG</code>. This constructor should only be used when creating subset <code>ArrayVG</code>
	 * s.
	 * </p>
	 * 
	 * @param parent The parent of this <code>ArrayVG</code>.
	 */
	protected ArrayVG(final VertexGroup parent)
	{
		this.parent = parent;

		indexWithinParent = -1;
		isSubset = true;
	}

	@Override
	public VertexGroup createEdgeSubsetVG(final int index)
	{
		return createSubsetVG(index, 2);
	}

	@Override
	public VertexGroup createFaceSubsetVG(final int index)
	{
		return createSubsetVG(index * 3, 3);
	}

	@Override
	public VertexGroup createSubsetVG(final int index, final int length)
	{
		float[] subsetColours = new float[length * 3];
		float[] subsetNormals = new float[length * 3];
		float[] subsetVertices = new float[length * 3];

		System.arraycopy(colours, index * 3, subsetColours, 0, subsetColours.length);
		System.arraycopy(normals, index * 3, subsetNormals, 0, subsetNormals.length);
		System.arraycopy(vertices, index * 3, subsetVertices, 0, subsetVertices.length);

		ArrayVG subsetVertexGroup = new ArrayVG(this);
		subsetVertexGroup.setIndexWithinParent(index * 3);
		subsetVertexGroup.setColours(subsetColours);
		subsetVertexGroup.setNormals(subsetNormals);
		subsetVertexGroup.setVertices(subsetVertices);

		return (subsetVertexGroup);
	}

	@Override
	public VertexGroup createVertexSubsetVG(final int index)
	{
		return createSubsetVG(index, 1);
	}

	/**
	 * <p>
	 * Retrieves the colours of all the vertices in this <code>ArrayVG</code>.
	 * </p>
	 * 
	 * @return The colours of all the vertices in this <code>ArrayVG</code>.
	 */
	public float[] getColours()
	{
		return (colours);
	}

	/**
	 * <p>
	 * Retrieves the index in the parent <code>ArrayVG</code> from which the data in this <code>ArrayVG</code> was copied.
	 * </p>
	 * 
	 * @return The index in the parent <code>ArrayVG</code> from which the data in this <code>ArrayVG</code> was copied.
	 */
	public int getIndexWithinParent()
	{
		return (indexWithinParent);
	}

	/**
	 * <p>
	 * Retrieves the surface normals of all the vertices in this <code>ArrayVG</code>.
	 * </p>
	 * 
	 * @return The surface normals of all the vertices in this <code>ArrayVG</code>.
	 */
	public float[] getNormals()
	{
		return (normals);
	}

	@Override
	public VertexGroup getParent()
	{
		return (parent);
	}

	/**
	 * <p>
	 * Retrieves the coordinates of all the vertices in this <code>ArrayVG</code>.
	 * </p>
	 * 
	 * @return The coordinates of all the vertices in this <code>ArrayVG</code>.
	 */
	public float[] getVertices()
	{
		return (vertices);
	}

	@Override
	public boolean isSubset()
	{
		return (isSubset);
	}

	@Override
	public void mergeWithParent() throws SEInvalidOperationException
	{
		if (!isSubset)
		{
			throw new SEInvalidOperationException("Cannot merge this Vertex Group because it is not a subset.");
		}

		System.arraycopy(colours, 0, ((ArrayVG) parent).getColours(), indexWithinParent * 3, colours.length);
		System.arraycopy(normals, 0, ((ArrayVG) parent).getNormals(), indexWithinParent, normals.length);
		System.arraycopy(vertices, 0, ((ArrayVG) parent).getVertices(), indexWithinParent, vertices.length);
	}

	/**
	 * <p>
	 * Sets the colours of all the vertices in this <code>ArrayVG</code>.
	 * </p>
	 * 
	 * @param colours The colours of all the vertices in this <code>ArrayVG</code>.
	 */
	public void setColours(final float[] colours)
	{
		this.colours = colours;
	}

	/**
	 * <p>
	 * Sets the index in the parent <code>ArrayVG</code> from which the data in this <code>ArrayVG</code> was copied.
	 * </p>
	 * 
	 * @param indexWithinParent The index in the parent <code>ArrayVG</code> from which the data in this <code>ArrayVG</code> was
	 * copied.
	 */
	public void setIndexWithinParent(final int indexWithinParent)
	{
		this.indexWithinParent = indexWithinParent;
	}

	/**
	 * <p>
	 * Sets the surface normals of all the vertices in this <code>ArrayVG</code>.
	 * </p>
	 * 
	 * @param normals The surface normals of all the vertices in this <code>ArrayVG</code>.
	 */
	public void setNormals(final float[] normals)
	{
		this.normals = normals;
	}

	/**
	 * <p>
	 * Sets the coordinates of all the vertices in this <code>ArrayVG</code>.
	 * </p>
	 * 
	 * @param vertices The coordinates of all the vertices in this <code>ArrayVG</code>.
	 */
	public void setVertices(final float[] vertices)
	{
		this.vertices = vertices;
	}
}
