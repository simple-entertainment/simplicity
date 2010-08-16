package com.se.simplicity.model;

import java.io.Serializable;

import com.se.simplicity.scenegraph.model.ModelNode;

/**
 * <p>
 * A simple implementation of a {@link com.se.simplicity.model.Model Model}.
 * </p>
 * 
 * @author simple
 */
public class SimpleModel implements Model, Serializable
{
	/**
	 * The serialisation version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * <p>
	 * The node at the root of this <code>SimpleModel</code>'s graph.
	 * </p>
	 */
	private ModelNode root;

	@Override
	public ModelNode getRoot()
	{
		return (root);
	}

	@Override
	public void setRoot(final ModelNode root)
	{
		this.root = root;
	}
}
