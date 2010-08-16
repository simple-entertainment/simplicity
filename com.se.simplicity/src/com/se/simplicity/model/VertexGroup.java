package com.se.simplicity.model;

import com.se.simplicity.SEInvalidOperationException;

/**
 * <p>
 * A portion of (or possibly an entire) {@link com.se.simplicity.model.Model Model}'s vertices.
 * </p>
 * 
 * @author simple
 */
public interface VertexGroup
{
	/**
	 * <p>
	 * Creates a subset <code>VertexGroup</code> that contains only the edge at the given index within this
	 * <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @param index The index of the edge to create a subset <code>VertexGroup</code> for.
	 * 
	 * @return A subset <code>VertexGroup</code> that contains only the edge at the given index within this
	 * <code>VertexGroup</code>.
	 */
	VertexGroup createEdgeSubsetVG(int index);

	/**
	 * <p>
	 * Creates a subset <code>VertexGroup</code> that contains only the face at the given index within this
	 * <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @param index The index of the face to create a subset <code>VertexGroup</code> for.
	 * 
	 * @return A subset <code>VertexGroup</code> that contains only the face at the given index within this
	 * <code>VertexGroup</code>.
	 */
	VertexGroup createFaceSubsetVG(int index);

	/**
	 * <p>
	 * Creates a subset <code>VertexGroup</code> that contains only the vertex at the given index within this
	 * <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @param index The index of the vertex to create a subset <code>VertexGroup</code> for.
	 * 
	 * @return A subset <code>VertexGroup</code> that contains only the vertex at the given index within this
	 * <code>VertexGroup</code>.
	 */
	VertexGroup createVertexSubsetVG(int index);

	/**
	 * <p>
	 * Creates a subset <code>VertexGroup</code> that contains the given length of consecutive vertices starting at the given
	 * index within this <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @param index The index of the first vertex to include in the subset <code>VertexGroup</code>.
	 * @param length The number of consecutive vertices to include in the subset <code>VertexGroup</code>.
	 * 
	 * @return A subset <code>VertexGroup</code> that contains the given length of consecutive vertices starting at the given
	 * index within this <code>VertexGroup</code>.
	 */
	VertexGroup createSubsetVG(int index, int length);

	/**
	 * <p>
	 * Retrieves the parent of this <code>VertexGroup</code>. The parent should be set to <code>null</code> unless this
	 * <code>VertexGroup</code> is a subset.
	 * </p>
	 * 
	 * @return The parent of this <code>VertexGroup</code>.
	 */
	VertexGroup getParent();

	/**
	 * <p>
	 * Determines if this <code>VertexGroup</code> is a subgroup of a parent <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @return True if this <code>VertexGroup</code> is a subgroup of a parent <code>VertexGroup</code>, false otherwise.
	 */
	boolean isSubset();

	/**
	 * <p>
	 * Copies the changes made to this <code>VertexGroup</code> to it's parent <code>VertexGroup</code>.
	 * </p>
	 * 
	 * @throws SEInvalidOperationException If this Vertex Group is not a subset.
	 */
	void mergeWithParent() throws SEInvalidOperationException;
}
