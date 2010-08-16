package com.se.simplicity.scenegraph.model;

import com.se.simplicity.model.Model;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.scenegraph.SimpleNode;

/**
 * <p>
 * A simple implementation of a {@link com.se.simplicity.scenegraph.model.ModelNode ModelNode}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleModelNode extends SimpleNode implements ModelNode
{
	/**
	 * The version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * <p>
	 * The {@link com.se.simplicity.model.Model Model} this <code>SimpleModelNode</code> is the root of, if this
	 * <code>SimpleModelNode</code> is the root of a {@link com.se.simplicity.model.Model Model}.
	 * </p>
	 */
	private Model model = null;

	/**
	 * <p>
	 * The portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>SimpleModelNode</code> contains.
	 * </p>
	 */
	private VertexGroup vertexGroup = null;

	@Override
	public Model getModel()
	{
		return (model);
	}

	@Override
	public VertexGroup getVertexGroup()
	{
		return (vertexGroup);
	}

	@Override
	public void setModel(final Model model)
	{
		this.model = model;
	}

	@Override
	public void setVertexGroup(final VertexGroup vertexGroup)
	{
		this.vertexGroup = vertexGroup;
	}
}
