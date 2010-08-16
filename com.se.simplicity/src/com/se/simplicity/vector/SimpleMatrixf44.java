package com.se.simplicity.vector;

import com.se.simplicity.SEInvalidOperationException;

/**
 * <p>
 * A 4x4 dimensional matrix that stores its data in a <code>float</code> array.
 * </p>
 * 
 * <p>
 * Copyright (c) 2007, simple entertainment
 * </p>
 * 
 * @author simple
 */
public class SimpleMatrixf44 extends ArrayBackedObjectf implements Matrixf
{
	/**
	 * The version of this class.
	 */
	private static final long serialVersionUID = 1L;

	/**
	 * <p>
	 * Creates an instance of <code>SimpleMatrixf44</code>.
	 * </p>
	 * 
	 * <p>
	 * The <code>SimpleMatrixf44</code> is initialised as an identity matrix.
	 * </p>
	 */
	public SimpleMatrixf44()
	{
		setArray(new float[16]);

		setIdentity();
	}

	/**
	 * <p>
	 * Creates an instance of <code>SimpleMatrixf44</code>.
	 * </p>
	 * 
	 * <p>
	 * The <code>SimpleMatrixf44</code> is initialised to the contents of the array given.
	 * </p>
	 * 
	 * @param array An array containing the initial elements for this <code>SimpleMatrixf44</code>.
	 */
	public SimpleMatrixf44(final float[] array)
	{
		setArray(array);
	}

	@Override
	public float getDeterminant()
	{
		float[] array = getArray();

		float determinant = array[0]
				* ((array[5] * array[10] * array[15] + array[6] * array[11] * array[13] + array[7] * array[9] * array[14])
						- array[7] * array[10] * array[13] - array[5] * array[11] * array[14] - array[6] * array[9] * array[15]);

		determinant -= array[1]
				* ((array[4] * array[10] * array[15] + array[6] * array[11] * array[12] + array[7] * array[8] * array[14])
						- array[7] * array[10] * array[12] - array[4] * array[11] * array[14] - array[6] * array[8] * array[15]);

		determinant += array[2]
				* ((array[4] * array[9] * array[15] + array[5] * array[11] * array[12] + array[7] * array[8] * array[13])
						- array[7] * array[9] * array[12] - array[4] * array[11] * array[13] - array[5] * array[8] * array[15]);

		determinant -= array[3]
				* ((array[4] * array[9] * array[14] + array[5] * array[10] * array[12] + array[6] * array[8] * array[13])
						- array[6] * array[9] * array[12] - array[4] * array[10] * array[13] - array[5] * array[8] * array[14]);

		return (determinant);
	}

	/**
	 * <p>
	 * Retrieves the determinant of a 3x3 column-major matrix. The matrix is formatted as follows:
	 * </p>
	 * 
	 * <pre>
	 * -------------------
	 * | f00 | f10 | f20 |
	 * -------------------
	 * | f01 | f11 | f21 |
	 * -------------------
	 * | f02 | f12 | f22 |
	 * -------------------
	 * </pre>
	 * 
	 * @param f00 An element of the 3x3 matrix.
	 * @param f10 An element of the 3x3 matrix.
	 * @param f20 An element of the 3x3 matrix.
	 * @param f01 An element of the 3x3 matrix.
	 * @param f11 An element of the 3x3 matrix.
	 * @param f21 An element of the 3x3 matrix.
	 * @param f02 An element of the 3x3 matrix.
	 * @param f12 An element of the 3x3 matrix.
	 * @param f22 An element of the 3x3 matrix.
	 * 
	 * @return The determinant of a 3x3 column-major matrix.
	 */
	protected float getDeterminant33(final float f00, final float f10, final float f20, final float f01, final float f11,
			final float f21, final float f02, final float f12, final float f22)
	{
		return (f00 * (f11 * f22 - f12 * f21) - f10 * (f01 * f22 - f02 * f21) + f20 * (f01 * f12 - f02 * f11));
	}

	/**
	 * <p>
	 * NOTE: This method uses Cramer's Rule to compute the inverse (computes many determinants). Gaussian Elimination could be a
	 * more efficient means of computing the inverse.
	 * </p>
	 */
	@Override
	public void invert() throws SEInvalidOperationException
	{
		float[] array = getArray();
		float determinant = getDeterminant();

		if (determinant == 0.0f)
		{
			throw new SEInvalidOperationException("Cannot invert a Matrix with a determinant of 0.");
		}

		float invDeterminant = 1.0f / determinant;

		// Calculate determinants for each value in this matrix.
		float f00 = getDeterminant33(array[5], array[6], array[7], array[9], array[10], array[11], array[13], array[14],
				array[15]);
		float f01 = -getDeterminant33(array[4], array[6], array[7], array[8], array[10], array[11], array[12], array[14],
				array[15]);
		float f02 = getDeterminant33(array[4], array[5], array[7], array[8], array[9], array[11], array[12], array[13], array[15]);
		float f03 = -getDeterminant33(array[4], array[5], array[6], array[8], array[9], array[10], array[12], array[13],
				array[14]);

		float f10 = -getDeterminant33(array[1], array[2], array[3], array[9], array[10], array[11], array[13], array[14],
				array[15]);
		float f11 = getDeterminant33(array[0], array[2], array[3], array[8], array[10], array[11], array[12], array[14],
				array[15]);
		float f12 = -getDeterminant33(array[0], array[1], array[3], array[8], array[9], array[11], array[12], array[13],
				array[15]);
		float f13 = getDeterminant33(array[0], array[1], array[2], array[8], array[9], array[10], array[12], array[13], array[14]);

		float f20 = getDeterminant33(array[1], array[2], array[3], array[5], array[6], array[7], array[13], array[14], array[15]);
		float f21 = -getDeterminant33(array[0], array[2], array[3], array[4], array[6], array[7], array[12], array[14], array[15]);
		float f22 = getDeterminant33(array[0], array[1], array[3], array[4], array[5], array[7], array[12], array[13], array[15]);
		float f23 = -getDeterminant33(array[0], array[1], array[2], array[4], array[5], array[6], array[12], array[13], array[14]);

		float f30 = -getDeterminant33(array[1], array[2], array[3], array[5], array[6], array[7], array[9], array[10], array[11]);
		float f31 = getDeterminant33(array[0], array[2], array[3], array[4], array[6], array[7], array[8], array[10], array[11]);
		float f32 = -getDeterminant33(array[0], array[1], array[3], array[4], array[5], array[7], array[8], array[9], array[11]);
		float f33 = getDeterminant33(array[0], array[1], array[2], array[4], array[5], array[6], array[8], array[9], array[10]);

		// Transpose and divide by the determinant.
		array[0] = f00 * invDeterminant;
		array[1] = f10 * invDeterminant;
		array[2] = f20 * invDeterminant;
		array[3] = f30 * invDeterminant;
		array[4] = f01 * invDeterminant;
		array[5] = f11 * invDeterminant;
		array[6] = f21 * invDeterminant;
		array[7] = f31 * invDeterminant;
		array[8] = f02 * invDeterminant;
		array[9] = f12 * invDeterminant;
		array[10] = f22 * invDeterminant;
		array[11] = f32 * invDeterminant;
		array[12] = f03 * invDeterminant;
		array[13] = f13 * invDeterminant;
		array[14] = f23 * invDeterminant;
		array[15] = f33 * invDeterminant;
	}

	/**
	 * <p>
	 * Multiplies the <code>SimpleMatrixf44</code>s given.
	 * </p>
	 * 
	 * @param leftMatrix The <code>SimpleMatrixf44</code> to be placed on the left hand side of the equation.
	 * @param rightMatrix The <code>SimpleMatrixf44</code> to be placed on the right hand side of the equation.
	 * 
	 * @return An array that contains the result of the multiplication.
	 */
	protected float[] multiply(final SimpleMatrixf44 leftMatrix, final SimpleMatrixf44 rightMatrix)
	{
		float[] leftArray = leftMatrix.getArray();
		float[] rightArray = rightMatrix.getArray();
		float[] multArray = new float[16];

		float sum = 0.0f;

		// For every row in the left hand matrix.
		for (int row = 0; row < 4; row++)
		{
			// For every column in the right hand matrix.
			for (int column = 0; column < 4; column++)
			{
				// For every element in the current row of the left hand matrix and
				// every element in the current column of the right hand matrix.
				for (int element = 0; element < 4; element++)
				{
					// Add the product of the two to the value for the new
					// matrix.
					sum += leftArray[row + (element * 4)] * rightArray[(column * 4) + element];
				}

				multArray[(column * 4) + row] = sum;
				sum = 0.0f;
			}
		}

		return (multArray);
	}

	@Override
	public void multiplyLeft(final Matrixf leftMatrix)
	{
		setArray(multiply((SimpleMatrixf44) leftMatrix, this));
	}

	@Override
	public Matrixf multiplyLeftCopy(final Matrixf leftMatrix)
	{
		return (new SimpleMatrixf44(multiply((SimpleMatrixf44) leftMatrix, this)));
	}

	@Override
	public void multiplyRight(final Matrixf rightMatrix)
	{
		setArray(multiply(this, (SimpleMatrixf44) rightMatrix));
	}

	@Override
	public Matrixf multiplyRightCopy(final Matrixf rightMatrix)
	{
		return (new SimpleMatrixf44(multiply(this, (SimpleMatrixf44) rightMatrix)));
	}

	@Override
	public void setIdentity()
	{
		float[] array = getArray();

		array[0] = 1.0f;
		array[1] = 0.0f;
		array[2] = 0.0f;
		array[3] = 0.0f;

		array[4] = 0.0f;
		array[5] = 1.0f;
		array[6] = 0.0f;
		array[7] = 0.0f;

		array[8] = 0.0f;
		array[9] = 0.0f;
		array[10] = 1.0f;
		array[11] = 0.0f;

		array[12] = 0.0f;
		array[13] = 0.0f;
		array[14] = 0.0f;
		array[15] = 1.0f;
	}

	/**
	 * <p>
	 * Retrieves a textual representation of this <code>SimpleMatrixf44</code> in the following format.
	 * </p>
	 * 
	 * <pre>
	 * ----------------
	 *  x | x | x | x |
	 * ----------------
	 *  x | x | x | x |
	 * ----------------
	 *  x | x | x | x |
	 * ----------------
	 *  x | x | x | x |
	 * ----------------
	 * </pre>
	 * 
	 * @return A textual representation of this <code>SimpleMatrixf44</code>.
	 */
	public String toString()
	{
		float[] array = getArray();
		String string = "";

		string += "-------------------------\n";
		string += "| " + array[0] + " | " + array[4] + " | " + array[8] + " | " + array[12] + " |\n";
		string += "-------------------------\n";
		string += "| " + array[1] + " | " + array[5] + " | " + array[9] + " | " + array[13] + " |\n";
		string += "-------------------------\n";
		string += "| " + array[2] + " | " + array[6] + " | " + array[10] + " | " + array[14] + " |\n";
		string += "-------------------------\n";
		string += "| " + array[3] + " | " + array[7] + " | " + array[11] + " | " + array[15] + " |\n";
		string += "-------------------------\n";

		return (string);
	}

	@Override
	public void transpose()
	{
		float[] array = getArray();
		float temp = -1;

		temp = array[1];
		array[1] = array[4];
		array[4] = temp;

		temp = array[2];
		array[2] = array[8];
		array[8] = temp;

		temp = array[3];
		array[3] = array[12];
		array[12] = temp;

		temp = array[6];
		array[6] = array[9];
		array[9] = temp;

		temp = array[7];
		array[7] = array[13];
		array[13] = temp;

		temp = array[11];
		array[11] = array[14];
		array[14] = temp;
	}
}
