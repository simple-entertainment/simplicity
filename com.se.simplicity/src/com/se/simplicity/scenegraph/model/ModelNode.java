package com.se.simplicity.scenegraph.model;

import com.se.simplicity.model.Model;
import com.se.simplicity.model.VertexGroup;
import com.se.simplicity.scenegraph.Node;

/**
 * <p>
 * A {@link com.se.simplicity.scenegraph.Node Node} that contains a {@link com.se.simplicity.model.VertexGroup VertexGroup}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public interface ModelNode extends Node
{
	/**
	 * <p>
	 * Retrieves the {@link com.se.simplicity.model.Model Model} this <code>ModelNode</code> is the root of.
	 * </p>
	 * 
	 * @return The {@link com.se.simplicity.model.Model Model} this <code>ModelNode</code> is the root of or <code>null</code> if
	 * this <code>ModelNode</code> is not the root of a {@link com.se.simplicity.model.Model Model}.
	 */
	Model getModel();

	/**
	 * <p>
	 * Retrieves the portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>ModelNode</code> contains.
	 * </p>
	 * 
	 * @return The portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>ModelNode</code> contains.
	 */
	VertexGroup getVertexGroup();

	/**
	 * <p>
	 * Sets the {@link com.se.simplicity.model.Model Model} this <code>ModelNode</code> is the root of.
	 * </p>
	 * 
	 * @param model The {@link com.se.simplicity.model.Model Model} this <code>ModelNode</code> is the root of.
	 */
	void setModel(Model model);

	/**
	 * <p>
	 * Sets the portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>ModelNode</code> contains.
	 * </p>
	 * 
	 * @param vertexGroup The portion of a {@link com.se.simplicity.model.Model Model}'s vertices this <code>ModelNode</code>
	 * contains.
	 */
	void setVertexGroup(VertexGroup vertexGroup);
}
