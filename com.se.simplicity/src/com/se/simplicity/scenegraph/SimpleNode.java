package com.se.simplicity.scenegraph;

// J2SE imports.
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

// simplicity imports.
import com.se.simplicity.SENotSupportedException;
import com.se.simplicity.vector.SimpleTransformationMatrixf44;
import com.se.simplicity.vector.TransformationMatrixf;

/**
 * <p>
 * A component of a {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleNode implements Node, Serializable
{
	/**
	 * The version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * TODO Create type for bounding volumes.
	 * 
	 * <p>
	 * A volume containing all the {@link com.se.simplicity.model.VertexGroup VertexGroup}s within the subgraph of which this
	 * <code>SimpleNode</code> is the root.
	 * </p>
	 */
	private Object bounds;

	/**
	 * <p>
	 * The <code>SimpleNode</code>s directly below this <code>SimpleNode</code> in a
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 */
	private List<Node> children;

	/**
	 * <p>
	 * The collision mode. Determines if this <code>SimpleNode</code> can collide with other <code>SimpleNode</code>s in the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} (determines if it should be included in collision detection).
	 * </p>
	 */
	private boolean collidable;

	/**
	 * <p>
	 * This <code>SimpleNode</code>'s unique identifier. This unique identifier is managed by the
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}.
	 * </p>
	 */
	private int id;

	/**
	 * <p>
	 * The modification mode. Determines if this <code>SimpleNode</code> can be modified.
	 * </p>
	 */
	private boolean modifiable;

	/**
	 * <p>
	 * The <code>SimpleNode</code> directly above this <code>SimpleNode</code> in a
	 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph} .
	 * </p>
	 */
	private Node parent;

	/**
	 * <p>
	 * This <code>SimpleNode</code>'s relative position and orientation.
	 * </p>
	 */
	private TransformationMatrixf transformation;

	/**
	 * <p>
	 * The visibility mode. Determines if this <code>SimpleNode</code> is visible (determines if it should be rendered).
	 * </p>
	 */
	private boolean visible;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleNode</code>.
	 * </p>
	 */
	public SimpleNode()
	{
		children = new ArrayList<Node>();
		collidable = true;
		modifiable = true;
		parent = null;
		transformation = new SimpleTransformationMatrixf44();
		visible = true;
	}

	@Override
	public void addChild(final Node child)
	{
		children.add(child);
		child.setParent(this);
	}

	@Override
	public Object getBounds()
	{
		// TODO Implement

		throw new SENotSupportedException("This method has not been implemented yet.");
	}

	@Override
	public List<Node> getChildren()
	{
		return (children);
	}

	@Override
	public int getID()
	{
		return (id);
	}

	@Override
	public Node getParent()
	{
		return (parent);
	}

	@Override
	public TransformationMatrixf getTransformation()
	{
		return (transformation);
	}

	@Override
	public boolean hasChildren()
	{
		if (children.size() == 0)
		{
			return (false);
		}

		return (true);
	}

	@Override
	public boolean isAncestor(final Node ancestor)
	{
		Node currentParent = parent;

		while (currentParent != null)
		{
			if (currentParent == ancestor)
			{
				return (true);
			}

			currentParent = currentParent.getParent();
		}

		return (false);
	}

	@Override
	public boolean isCollidable()
	{
		return (collidable);
	}

	@Override
	public boolean isModifiable()
	{
		return (modifiable);
	}

	@Override
	public boolean isSuccessor(final Node successor)
	{
		Traversal traversal = new SimpleTraversal(this);

		while (traversal.hasMoreNodes())
		{
			if (traversal.getNextNode() == successor && successor != this)
			{
				return (true);
			}
		}

		return (false);
	}

	@Override
	public boolean isVisible()
	{
		return (visible);
	}

	@Override
	public void removeChild(final Node child)
	{
		children.remove(child);
		child.setParent(null);
	}

	@Override
	public void setBounds(Object bounds)
	{
		// TODO Implement

		throw new SENotSupportedException("This method has not been implemented yet.");
	}

	@Override
	public void setCollidable(final boolean collidable)
	{
		this.collidable = collidable;
	}

	@Override
	public void setID(final int id)
	{
		this.id = id;
	}

	@Override
	public void setModifiable(final boolean modifiable)
	{
		this.modifiable = modifiable;
	}

	@Override
	public void setParent(final Node parent)
	{
		this.parent = parent;
	}

	@Override
	public void setTransformation(final TransformationMatrixf transformation)
	{
		this.transformation = transformation;
	}

	@Override
	public void setVisible(final boolean visible)
	{
		this.visible = visible;
	}
}
