package com.se.simplicity.vector;

import com.se.simplicity.SEInvalidOperationException;

/**
 * <p>
 * A matrix that stores its data in a <code>float</code> array.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public interface Matrixf
{
	/**
	 * <p>
	 * Retrieves the determinant of this <code>Matrixf</code>.
	 * </p>
	 * 
	 * @return The determinant of this <code>Matrixf</code>.
	 */
	float getDeterminant();

	/**
	 * <p>
	 * Attempts to set this <code>Matrixf</code> to the inverse of this <code>Matrixf</code>.
	 * </p>
	 * 
	 * @throws SEInvalidOperationException If this <code>SimpleMatrixf44</code> has a determinant of 0.
	 */
	void invert() throws SEInvalidOperationException;

	/**
	 * <p>
	 * Multiplies this <code>Matrixf</code> with the <code>Matrixf</code> given. The <code>Matrixf</code> given is placed on the
	 * left hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * This <code>Matrixf</code> becomes the result of the multiplication.
	 * </p>
	 * 
	 * @param leftMatrix The <code>Matrixf</code> to be placed on the left hand side of the multiplication with this
	 * <code>Matrixf</code>.
	 */
	void multiplyLeft(Matrixf leftMatrix);

	/**
	 * <p>
	 * Multiplies this <code>Matrixf</code> with the <code>Matrixf</code> given. The <code>Matrixf</code> given is placed on the
	 * left hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * A new <code>Matrixf</code> is created as the result of the multiplication.
	 * </p>
	 * 
	 * @param leftMatrix The <code>Matrixf</code> to be placed on the left hand side of the multiplication with this
	 * <code>Matrixf</code>.
	 * 
	 * @return The result of the multiplication.
	 */
	Matrixf multiplyLeftCopy(Matrixf leftMatrix);

	/**
	 * <p>
	 * Multiplies this <code>Matrixf</code> with the <code>Matrixf</code> given. The <code>Matrixf</code> given is placed on the
	 * right hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * This <code>Matrixf</code> becomes the result of the multiplication.
	 * </p>
	 * 
	 * @param rightMatrix The <code>Matrixf</code> to be placed on the right hand side of the multiplication with this
	 * <code>Matrixf</code>.
	 */
	void multiplyRight(Matrixf rightMatrix);

	/**
	 * <p>
	 * Multiplies this <code>Matrixf</code> with the <code>Matrixf</code> given. The <code>Matrixf</code> given is placed on the
	 * right hand side of the equation.
	 * </p>
	 * 
	 * <p>
	 * A new <code>Matrixf</code> is created as the result of the multiplication.
	 * </p>
	 * 
	 * @param rightMatrix The <code>Matrixf</code> to be placed on the right hand side of the multiplication with this
	 * <code>Matrixf</code>.
	 * 
	 * @return The result of the multiplication.
	 */
	Matrixf multiplyRightCopy(Matrixf rightMatrix);

	/**
	 * <p>
	 * Sets this <code>Matrixf</code> to the identity matrix.
	 * </p>
	 */
	void setIdentity();

	/**
	 * <p>
	 * Sets this <code>Matrixf</code> to the transpose of this <code>Matrixf</code>.
	 * </p>
	 */
	void transpose();
}
