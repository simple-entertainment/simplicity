package com.se.simplicity.vector;

/**
 * <p>
 * A vector that stores its data in a <code>float</code> array.
 * </p>
 * 
 * @author simple
 */
public interface Vectorf
{
	/**
	 * <p>
	 * Adds the <code>Vectorf</code> given to this <code>Vectorf</code>.
	 * <p>
	 * 
	 * <p>
	 * This <code>Vectorf</code> becomes the result of the addition.
	 * </p>
	 * 
	 * <p>
	 * This method assumes both <code>Vectorf</code>s to be homogenised.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to add this <code>Vectorf</code> to.
	 */
	void add(Vectorf vector);

	/**
	 * <p>
	 * Adds the <code>Vectorf</code> given to this <code>Vectorf</code>.
	 * <p>
	 * 
	 * <p>
	 * A new <code>Vectorf</code> is created as the result of the addition.
	 * </p>
	 * 
	 * <p>
	 * This method assumes both <code>Vectorf</code>s to be homogenised.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to add this <code>Vectorf</code> to.
	 * 
	 * @return A new <code>Vectorf</code> that is the result of sum of this <code>Vectorf</code> and the <code>Vectorf</code>
	 * given.
	 */
	Vectorf addCopy(Vectorf vector);

	/**
	 * <p>
	 * Performs a cross product of this <code>Vectorf</code> and the <code>Vectorf</code> given. The <code>Vectorf</code> given is
	 * placed on the right hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * This <code>Vectorf</code> becomes the result of the cross product.
	 * </p>
	 * 
	 * <p>
	 * This method assumes both <code>Vectorf</code>s to be homogenised.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
	 */
	void crossProductRight(Vectorf vector);

	/**
	 * <p>
	 * Performs a cross product of this <code>Vectorf</code> and the <code>Vectorf</code> given. The <code>Vectorf</code> given is
	 * placed on the right hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * A new <code>Vectorf</code> is created as the result of the cross product.
	 * </p>
	 * 
	 * <p>
	 * This method assumes both <code>Vectorf</code>s to be homogenised.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
	 * 
	 * @return A new <code>Vectorf</code> that is the result of the cross product of this <code>Vectorf</code> and the
	 * <code>Vectorf</code> given.
	 */
	Vectorf crossProductRightCopy(Vectorf vector);

	/**
	 * <p>
	 * Performs a dot product of this <code>Vectorf</code> and the <code>Vectorf</code> given
	 * </p>
	 * 
	 * <p>
	 * This method assumes both <code>Vectorf</code>s to be homogenised.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to perform the dot product with.
	 * 
	 * @return The dot product of this <code>Vectorf</code> and the <code>Vectorf</code> given.
	 */
	float dotProduct(Vectorf vector);

	/**
	 * <p>
	 * Retrieves the length of this <code>Vectorf</code>.
	 * </p>
	 * 
	 * @return The length of this <code>Vectorf</code>.
	 */
	float getLength();

	/**
	 * <p>
	 * Retrieves the length of this <code>Vectorf</code> squared.
	 * </p>
	 * 
	 * @return The length of this <code>Vectorf</code> squared.
	 */
	float getLengthSquared();

	/**
	 * <p>
	 * Homogenises this <code>Vectorf</code>.
	 * </p>
	 * 
	 * <p>
	 * Scales all values equally so that the <code>w</code> value of this <code>Vectorf</code> is <code>1.0f</code>.
	 * </p>
	 */
	void homogenize();

	/**
	 * <p>
	 * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This
	 * <code>Vectorf</code> is treated as a column vector and multiplied as follows:
	 * </p>
	 * 
	 * <pre>
	 * ----------------     -----
	 *  x | x | x | x |  *  | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 * </pre>
	 * 
	 * <p>
	 * This <code>Vectorf</code> becomes the result of the multiplication.
	 * </p>
	 * 
	 * @param matrix The {@link com.se.simplicity.vector.Matrixf Matrixf} to be placed on the left hand side of the equation.
	 */
	void multiplyLeft(Matrixf matrix);

	/**
	 * <p>
	 * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This
	 * <code>Vectorf</code> is treated as a column vector and multiplied as follows:
	 * </p>
	 * 
	 * <pre>
	 * ----------------     -----
	 *  x | x | x | x |  *  | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 *  x | x | x | x |     | x |
	 * ----------------     -----
	 * </pre>
	 * 
	 * <p>
	 * A new <code>Vectorf</code> is created as the result of the multiplication.
	 * </p>
	 * 
	 * @param matrix The {@link com.se.simplicity.vector.Matrixf Matrixf} to be placed on the left hand side of the equation.
	 * 
	 * @return A new <code>Vectorf</code> that is the result of the multiplication of this <code>Vectorf</code> and the
	 * {@link com.se.simplicity.vector.Matrixf Matrixf} given.
	 */
	Vectorf multiplyLeftCopy(Matrixf matrix);

	/**
	 * <p>
	 * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This
	 * <code>Vectorf</code> is treated as a row vector and multiplied as follows:
	 * </p>
	 * 
	 * <pre>
	 * -----------------     -----------------
	 * | x | x | x | x |  *  | x | x | x | x |
	 * -----------------     -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 * </pre>
	 * 
	 * <p>
	 * This <code>Vectorf</code> becomes the result of the multiplication.
	 * </p>
	 * 
	 * @param matrix The {@link com.se.simplicity.vector.Matrixf Matrixf} to be placed on the right hand side of the equation.
	 */
	void multiplyRight(Matrixf matrix);

	/**
	 * <p>
	 * Multiplies this <code>Vectorf</code> with the <code>Vectorf</code> given. The <code>Vectorf</code> given is placed on the
	 * right hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * This <code>Vectorf</code> becomes the result of the multiplication.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
	 */
	void multiplyRight(Vectorf vector);

	/**
	 * <p>
	 * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This
	 * <code>Vectorf</code> is treated as a row vector and multiplied as follows:
	 * </p>
	 * 
	 * <pre>
	 * -----------------     -----------------
	 * | x | x | x | x |  *  | x | x | x | x |
	 * -----------------     -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 *                       | x | x | x | x |
	 *                       -----------------
	 * </pre>
	 * 
	 * <p>
	 * A new <code>Vectorf</code> is created as the result of the multiplication.
	 * </p>
	 * 
	 * @param matrix The {@link com.se.simplicity.vector.Matrixf Matrixf} to be placed on the right hand side of the equation.
	 * 
	 * @return A new <code>Vectorf</code> that is the result of the multiplication of this <code>Vectorf</code> and the
	 * {@link com.se.simplicity.vector.Matrixf Matrixf} given.
	 */
	Vectorf multiplyRightCopy(Matrixf matrix);

	/**
	 * <p>
	 * Multiplies this <code>Vectorf</code> with the <code>Vectorf</code> given. The <code>Vectorf</code> given is placed on the
	 * right hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * A new <code>Vectorf</code> is created as the result of the multiplication.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
	 * 
	 * @return A new <code>Vectorf</code> that is the result of the multiplication of this <code>Vectorf</code> and the
	 * <code>Vectorf</code> given.
	 */
	Vectorf multiplyRightCopy(Vectorf vector);

	/**
	 * <p>
	 * Negates this <code>Vectorf</code>.
	 * </p>
	 */
	void negate();

	/**
	 * <p>
	 * Scales this <code>Vectorf</code> to a unit length vector.
	 * </p>
	 */
	void normalize();

	/**
	 * <p>
	 * Scales this <code>Vectorf</code> by the scalar given.
	 * </p>
	 * 
	 * @param scalar The factor to scale this <code>Vectorf</code> by.
	 */
	void scale(float scalar);

	/**
	 * <p>
	 * Subtracts the <code>Vectorf</code> given from this <code>Vectorf</code>. The <code>Vectorf</code> given is placed on the
	 * right hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * This <code>Vectorf</code> becomes the result of the subtraction.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
	 */
	void subtractRight(Vectorf vector);

	/**
	 * <p>
	 * Subtracts the <code>Vectorf</code> given from this <code>Vectorf</code>. The <code>Vectorf</code> given is placed on the
	 * right hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * A new <code>Vectorf</code> is created as the result of the subtraction.
	 * </p>
	 * 
	 * @param vector The <code>Vectorf</code> to be placed on the right hand side of the equation.
	 * 
	 * @return A new <code>Vectorf</code> that is the result of the subtraction of the <code>Vectorf</code> given from this
	 * <code>Vectorf</code>.
	 */
	Vectorf subtractRightCopy(Vectorf vector);
}
