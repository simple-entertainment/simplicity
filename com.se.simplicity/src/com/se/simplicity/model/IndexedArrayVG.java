package com.se.simplicity.model;

import java.io.Serializable;

import com.se.simplicity.SENotSupportedException;

/**
 * <p>
 * A vertex group based on an indexed array of vertices.
 * </p>
 * 
 * <p>
 * Three separate arrays are actually used to store the information for the vertices. One for the coordinates, one for the colours
 * and one for the surface normals. A fourth array contains indexes. This array makes it possible to create a sequence of vertices
 * from the other three arrays without the need to repeat vertices in those arrays.
 * </p>
 * 
 * <p>
 * This kind of vertex group can have a smaller memory footprint and/or faster processing than the standard array of vertices (as
 * used by the <code>ArrayVG</code>) in some situations.
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
public class IndexedArrayVG implements VertexGroup, Serializable
{

	/**
	 * The serialisation version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * The colours of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	private float[] colours;

	/**
	 * <p>
	 * The index in the parent <code>IndexedArrayVG</code> from which the data in this <code>IndexedArrayVG</code> was copied.
	 * </p>
	 */
	private int indexWithinParent;

	/**
	 * <p>
	 * The subset status. Determines if this <code>IndexedArrayVG</code> is a subgroup of a parent <code>IndexedArrayVG</code>.
	 * Subset <code>IndexedArrayVG</code>s contain a copy of a subset of the parent <code>IndexedArrayVG</code>s data.
	 * </p>
	 */
	private boolean isSubset;

	/**
	 * The indices of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	private int[] indices;

	/**
	 * The surface normals of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	private float[] normals;

	/**
	 * <p>
	 * The parent of this <code>IndexedArrayVG</code>. The parent should be set to <code>null</code> unless this
	 * <code>IndexedArrayVG</code> is a subset.
	 * </p>
	 */
	private VertexGroup parent;

	/**
	 * The coordinates of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	private float[] vertices;

	/**
	 * <p>
	 * Creates an instance of <code>IndexedArrayVG</code>.
	 * </p>
	 */
	public IndexedArrayVG()
	{
		indexWithinParent = -1;
		isSubset = false;
		parent = null;
	}

	/**
	 * <p>
	 * Creates an instance of <code>IndexedArrayVG</code>. This constructer should be used when creating subset
	 * <code>VertexGroup</code>s.
	 * </p>
	 * 
	 * @param parent The parent of this <code>VertexGroup</code>.
	 */
	protected IndexedArrayVG(final VertexGroup parent)
	{
		this.parent = parent;

		indexWithinParent = -1;
		isSubset = true;
	}

	/**
	 * <p>
	 * Retrieves the colours of all the vertices in this <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @return The colours of all the vertices in this <code>IndexedArrayVG</code>.
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
	 * Retrieves the indices of all the vertices in this <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @return The indices of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	public int[] getIndices()
	{
		return (indices);
	}

	/**
	 * <p>
	 * Retrieves the surface normals of all the vertices in this <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @return The surface normals of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	public float[] getNormals()
	{
		return (normals);
	}

	/**
	 * <p>
	 * Retrieves the coordinates of all the vertices in this <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @return The coordinates of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	public float[] getVertices()
	{
		return (vertices);
	}

	/**
	 * <p>
	 * Sets the colours of all the vertices in this <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @param colours The colours of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	public void setColours(final float[] colours)
	{
		this.colours = colours;
	}

	/**
	 * <p>
	 * Sets the indices of all the vertices in this <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @param indices The indices of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	public void setIndices(final int[] indices)
	{
		this.indices = indices;
	}

	/**
	 * <p>
	 * Sets the surface normals of all the vertices in this <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @param normals The surface normals of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	public void setNormals(final float[] normals)
	{
		this.normals = normals;
	}

	/**
	 * <p>
	 * Sets the coordinates of all the vertices in this <code>IndexedArrayVG</code>.
	 * </p>
	 * 
	 * @param vertices The coordinates of all the vertices in this <code>IndexedArrayVG</code>.
	 */
	public void setVertices(final float[] vertices)
	{
		this.vertices = vertices;
	}

	@Override
	public VertexGroup createSubsetVG(final int index, final int length)
	{
		int[] subsetIndices = new int[length];
		float[] subsetColours = new float[length * 3];
		float[] subsetNormals = new float[length * 3];
		float[] subsetVertices = new float[length * 3];

		System.arraycopy(indices, index, subsetIndices, 0, subsetIndices.length);

		for (int currentIndex = 0; currentIndex < subsetIndices.length; currentIndex++)
		{
			System.arraycopy(colours, subsetIndices[currentIndex] * 3, subsetColours, currentIndex * 3, 3);
			System.arraycopy(normals, subsetIndices[currentIndex] * 3, subsetNormals, currentIndex * 3, 3);
			System.arraycopy(vertices, subsetIndices[currentIndex] * 3, subsetVertices, currentIndex * 3, 3);
		}

		IndexedArrayVG subsetVertexGroup = new IndexedArrayVG(this);
		subsetVertexGroup.setIndices(subsetIndices);
		subsetVertexGroup.setColours(subsetColours);
		subsetVertexGroup.setNormals(subsetNormals);
		subsetVertexGroup.setVertices(subsetVertices);

		return subsetVertexGroup;
	}

	@Override
	public VertexGroup createEdgeSubsetVG(final int index)
	{
		// TODO Implement
		
		throw new SENotSupportedException("This method has not been implemented yet.");
	}

	@Override
	public VertexGroup createFaceSubsetVG(final int index)
	{
		return createSubsetVG(index * 3, 3);
	}

	@Override
	public VertexGroup createVertexSubsetVG(final int index)
	{
		return createSubsetVG(index, 1);
	}

	@Override
	public VertexGroup getParent()
	{
		return (parent);
	}

	@Override
	public boolean isSubset()
	{
		return (isSubset);
	}

	@Override
	public void mergeWithParent()
	{
		// TODO Implement
		
		throw new SENotSupportedException("This method has not been implemented yet.");
	}
}
