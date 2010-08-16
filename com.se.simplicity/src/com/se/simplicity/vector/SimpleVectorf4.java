package com.se.simplicity.vector;

import java.io.Serializable;

/**
 * <p>
 * A 4 dimensional vector that stores its data in a <code>float</code> array.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleVectorf4 extends ArrayBackedObjectf implements Vectorf, Serializable
{
	/**
	 * The version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleVectorf4</code>.
	 * </p>
	 * 
	 * <p>
	 * The <code>SimpleVectorf4</code> is initialised to <code>(0.0f, 0.0f, 0.0f, 1.0f)</code>.
	 * </p>
	 */
	public SimpleVectorf4()
	{
		float[] array = new float[4];

		array[0] = 0.0f;
		array[1] = 0.0f;
		array[2] = 0.0f;
		array[3] = 0.1f;

		setArray(array);
	}

	/**
	 * <p>
	 * Creates an instance of <code>SimpleVectorf4</code>.
	 * </p>
	 * 
	 * <p>
	 * The <code>SimpleVectorf4</code> is initialised to the components given.
	 * </p>
	 * 
	 * @param f0 The first element of this <code>SimpleVectorf4</code>.
	 * @param f1 The second element of this <code>SimpleVectorf4</code>.
	 * @param f2 The third element of this <code>SimpleVectorf4</code>.
	 * @param f3 The fourth element of this <code>SimpleVectorf4</code>.
	 */
	public SimpleVectorf4(final float f0, final float f1, final float f2, final float f3)
	{
		float[] array = new float[4];

		array[0] = f0;
		array[1] = f1;
		array[2] = f2;
		array[3] = f3;

		setArray(array);
	}

	/**
	 * <p>
	 * Creates an instance of <code>SimpleVectorf4</code>.
	 * </p>
	 * 
	 * <p>
	 * The <code>SimpleVectorf4</code> is initialised to the contents of the array given.
	 * </p>
	 * 
	 * @param array An array containing the initial elements of this <code>SimpleVectorf4</code>.
	 */
	public SimpleVectorf4(final float[] array)
	{
		setArray(array);
	}

	/**
	 * <p>
	 * Adds the <code>SimpleVectorf</code> given to this <code>SimpleVectorf</code>.
	 * <p>
	 * 
	 * <p>
	 * This method assumes both <code>SimpleVectorf</code>s to be homogenised.
	 * </p>
	 * 
	 * @param vector The <code>SimpleVectorf</code> to add this <code>SimpleVectorf</code> to.
	 * 
	 * @return An array that contains the result of the addition.
	 */
	protected float[] add(final SimpleVectorf4 vector)
	{
		float[] leftArray = getArray();
		float[] rightArray = vector.getArray();
		float[] addArray = new float[4];

		addArray[0] = leftArray[0] + rightArray[0];
		addArray[1] = leftArray[1] + rightArray[1];
		addArray[2] = leftArray[2] + rightArray[2];
		addArray[3] = 1.0f;

		return (addArray);
	}

	@Override
	public void add(final Vectorf vector)
	{
		setArray(add((SimpleVectorf4) vector));
	}

	@Override
	public Vectorf addCopy(final Vectorf vector)
	{
		return (new SimpleVectorf4(add((SimpleVectorf4) vector)));
	}

	/**
	 * <p>
	 * Performs a cross product of the <code>SimpleVectorf4</code>s given.
	 * </p>
	 * 
	 * <p>
	 * This method assumes both <code>SimpleVectorf4</code>s to be homogenised.
	 * </p>
	 * 
	 * @param leftVector The <code>SimpleVectorf4</code> to be placed on the left hand side of the equation.
	 * @param rightVector The <code>SimpleVectorf4</code> to be placed on the right hand side of the equation.
	 * 
	 * @return An array that contains the result of the cross product.
	 */
	protected float[] crossProduct(final SimpleVectorf4 leftVector, final SimpleVectorf4 rightVector)
	{
		float[] leftArray = leftVector.getArray();
		float[] rightArray = rightVector.getArray();
		float[] crossArray = new float[4];

		crossArray[0] = leftArray[1] * rightArray[2] - leftArray[2] * rightArray[1];
		crossArray[1] = leftArray[2] * rightArray[0] - leftArray[0] * rightArray[2];
		crossArray[2] = leftArray[0] * rightArray[1] - leftArray[1] * rightArray[0];
		crossArray[3] = 1.0f;

		return (crossArray);
	}

	@Override
	public void crossProductRight(final Vectorf vector)
	{
		setArray(crossProduct(this, (SimpleVectorf4) vector));
	}

	@Override
	public Vectorf crossProductRightCopy(final Vectorf vector)
	{
		return (new SimpleVectorf4(crossProduct(this, (SimpleVectorf4) vector)));
	}

	@Override
	public float dotProduct(final Vectorf vector)
	{
		float[] firstArray = getArray();
		float[] secondArray = ((SimpleVectorf4) vector).getArray();
		float dot = 0.0f;

		for (int index = 0; index < 3; index++)
		{
			dot += firstArray[index] * secondArray[index];
		}

		return (dot);
	}

	@Override
	public float getLength()
	{
		return ((float) Math.sqrt((double) getLengthSquared()));
	}

	@Override
	public float getLengthSquared()
	{
		float[] array = getArray();

		return (array[0] * array[0] + array[1] * array[1] + array[2] * array[2]);
	}

	@Override
	public void homogenize()
	{
		float[] array = getArray();

		if (array[3] == 1.0f)
		{
			return;
		}

		array[0] = array[0] / array[3];
		array[1] = array[1] / array[3];
		array[2] = array[2] / array[3];
		array[3] = 1.0f;
	}

	/**
	 * <p>
	 * Multiplies the <code>SimpleVectorf4</code>s given.
	 * </p>
	 * 
	 * <p>
	 * This method assumes both <code>SimpleVectorf4</code>s to be homogenised.
	 * </p>
	 * 
	 * @param leftVector The <code>SimpleVectorf4</code> to be placed on the left hand side of the equation.
	 * @param rightVector The <code>SimpleVectorf4</code> to be placed on the right hand side of the equation.
	 * 
	 * @return An array that contains the result of the multiplication.
	 */
	protected float[] multiply(final SimpleVectorf4 leftVector, final SimpleVectorf4 rightVector)
	{
		float[] leftArray = leftVector.getArray();
		float[] rightArray = rightVector.getArray();
		float[] multArray = new float[4];

		multArray[0] = leftArray[0] * rightArray[0];
		multArray[1] = leftArray[1] * rightArray[1];
		multArray[2] = leftArray[2] * rightArray[2];
		multArray[3] = 1.0f;

		return (multArray);
	}

	@Override
	public void multiplyLeft(final Matrixf matrix)
	{
		setArray(multiplyLeft((SimpleMatrixf44) matrix));
	}

	/**
	 * <p>
	 * Multiplies this <code>Vectorf</code> with the {@link com.se.simplicity.vector.Matrixf Matrixf} given. This
	 * <code>Vectorf</code> is treated as a column vector and multiplied as follows:
	 * </p>
	 * 
	 * <pre>
	 *   -----------------     -----
	 *   | x | x | x | x |  *  | x |
	 *   -----------------     -----
	 *   | x | x | x | x |     | x |
	 *   -----------------     -----
	 *   | x | x | x | x |     | x |
	 *   -----------------     -----
	 *   | x | x | x | x |     | x |
	 *   -----------------     -----
	 * </pre>
	 * 
	 * @param matrix The <code>SimpleMatrixf44</code> to be multiplied.
	 * 
	 * @return An array that contains the result of the multiplication.
	 */
	protected float[] multiplyLeft(final SimpleMatrixf44 matrix)
	{
		float[] mArray = matrix.getArray();
		float[] vArray = getArray();
		float[] multArray = new float[4];

		float sum = 0.0f;

		// For every row in the matrix.
		for (int row = 0; row < 4; row++)
		{
			// For every element in the vector and every element in the current
			// row of the matrix.
			for (int element = 0; element < 4; element++)
			{
				// Add the product of the two to the value for the new vector.
				sum += mArray[row + (element * 4)] * vArray[element];
			}

			multArray[row] = sum;
			sum = 0.0f;
		}

		return (multArray);
	}

	@Override
	public Vectorf multiplyLeftCopy(final Matrixf matrix)
	{
		return (new SimpleVectorf4(multiplyLeft((SimpleMatrixf44) matrix)));
	}

	@Override
	public void multiplyRight(final Matrixf matrix)
	{
		setArray(multiplyRight((SimpleMatrixf44) matrix));
	}

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
	 * @param matrix The <code>SimpleMatrixf44</code> to be multiplied.
	 * 
	 * @return An array that contains the result of the multiplication.
	 */
	protected float[] multiplyRight(final SimpleMatrixf44 matrix)
	{
		float[] vArray = getArray();
		float[] mArray = matrix.getArray();
		float[] multArray = new float[4];

		float sum = 0.0f;

		// For every column in the matrix.
		for (int column = 0; column < 4; column++)
		{
			// For every element in the vector and every element in the current
			// column of the matrix.
			for (int element = 0; element < 4; element++)
			{
				// Add the product of the two to the value for the new vector.
				sum += vArray[element] * mArray[(column * 4) + element];
			}

			multArray[column] = sum;
			sum = 0.0f;
		}

		return (multArray);
	}

	@Override
	public void multiplyRight(final Vectorf vector)
	{
		setArray(multiply(this, (SimpleVectorf4) vector));
	}

	@Override
	public Vectorf multiplyRightCopy(final Matrixf matrix)
	{
		return (new SimpleVectorf4(multiplyRight((SimpleMatrixf44) matrix)));
	}

	@Override
	public Vectorf multiplyRightCopy(final Vectorf vector)
	{
		return (new SimpleVectorf4(multiply(this, (SimpleVectorf4) vector)));
	}

	@Override
	public void negate()
	{
		scale(-1.0f);
	}

	@Override
	public void normalize()
	{
		float[] array = getArray();

		float sum = array[0] + array[1] + array[2];

		scale(1.0f / sum);
	}

	@Override
	public void scale(final float scalar)
	{
		float[] array = getArray();

		array[0] = array[0] * scalar;
		array[1] = array[1] * scalar;
		array[2] = array[2] * scalar;
	}

	/**
	 * <p>
	 * Performs a subtraction of the <code>SimpleVectorf</code>s given from this <code>Vectorf</code>.
	 * </p>
	 * 
	 * @param leftVector The <code>SimpleVectorf4</code> to be placed on the left hand side of the equation.
	 * @param rightVector The <code>SimpleVectorf4</code> to be placed on the right hand side of the equation.
	 * 
	 * @return An array that contains the result of the subtraction.
	 */
	protected float[] subtract(final SimpleVectorf4 leftVector, final SimpleVectorf4 rightVector)
	{
		float[] leftArray = leftVector.getArray();
		float[] rightArray = rightVector.getArray();
		float[] subArray = new float[4];

		subArray[0] = leftArray[0] - rightArray[0];
		subArray[1] = leftArray[1] - rightArray[1];
		subArray[2] = leftArray[2] - rightArray[2];
		subArray[3] = 1.0f;

		return (subArray);
	}

	@Override
	public void subtractRight(final Vectorf vector)
	{
		setArray(subtract(this, (SimpleVectorf4) vector));
	}

	@Override
	public Vectorf subtractRightCopy(final Vectorf vector)
	{
		return (new SimpleVectorf4(subtract(this, (SimpleVectorf4) vector)));
	}

	/**
	 * <p>
	 * Retrieves a textual representation of this <code>SimpleVectorf4</code> in the following format.
	 * </p>
	 * 
	 * <pre>
	 * ----------------
	 *  x | y | z | w |
	 * ----------------
	 * </pre>
	 * 
	 * @return A textual representation of this <code>SimpleVectorf4</code>.
	 */
	public String toString()
	{
		float[] array = getArray();
		String string = "";

		string += "-------------------------\n";
		string += "| " + array[0] + " | " + array[1] + " | " + array[2] + " | " + array[3] + " |\n";
		string += "-------------------------\n";

		return (string);
	}
}
