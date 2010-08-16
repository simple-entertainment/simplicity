package com.se.simplicity.model;

/**
 * <p>
 * A simple geometric shape that contains the geometry of a subgraph of a
 * {@link com.se.simplicity.scenegraph.SceneGraph SceneGraph}. <code>BoundingVolume</code>s can be used in many processes to
 * enhance performance and reduce un-needed calculations.
 * </p>
 * 
 * <p>
 * An example where <code>BoundingVolume</code>s are used is collision deteection. Collision of the two
 * <code>BoundingVolume</code>s can be tested before collision of the actual geometry contained in them. If the
 * <code>BoundingVolume</code>s do not collide the (possibly very complex) calculations required to test for collisions between
 * the actual geometry is avoided.
 * </p>
 * 
 * @author simple
 */
public interface BoundingVolume
{
	/**
	 * <p>
	 * Determines if this <code>BoundingVolume</code> intersects with the given <code>BoundingVolume</code>.
	 * </p>
	 * 
	 * @param otherBoundingVolume The <code>BoundingVolume</code> to test for intersection with this <code>BoundingVolume</code>.
	 * 
	 * @return True if the this <code>BoundingVolume</code> intersects with the given <code>BoundingVolume</code>, false
	 * otherwise.
	 */
	boolean intersectsWith(BoundingVolume otherBoundingVolume);

	/**
	 * <p>
	 * Updates this <code>BoundingVolume</code> to ensure it includes the entire subgraph's geometry.
	 * </p>
	 */
	void update();
}
