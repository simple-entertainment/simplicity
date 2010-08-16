package com.se.simplicity.vector;

/**
 * <p>
 * A transformation matrix that stores its data in a <code>float</code> array.
 * </p>
 * 
 * @author simple
 */
public interface TransformationMatrixf extends Matrixf
{
	/**
	 * <p>
	 * Retrieves the translation portion of this <code>TransformationMatrixf</code>.
	 * </p>
	 * 
	 * @return The translation portion of this <code>TransformationMatrixf</code>.
	 */
	TranslationVectorf getTranslation();

	/**
	 *<p>
	 *Retrieves the x axis rotation of this <code>TransformationMatrixf</code>.
	 *</p>
	 * 
	 * @return The x axis rotation of this <code>TransformationMatrixf</code>.
	 */
	float getXAxisRotation();
	
	/**
	 *<p>
	 *Retrieves the y axis rotation of this <code>TransformationMatrixf</code>.
	 *</p>
	 * 
	 * @return The y axis rotation of this <code>TransformationMatrixf</code>.
	 */
	float getYAxisRotation();
	
	/**
	 *<p>
	 *Retrieves the z axis rotation of this <code>TransformationMatrixf</code>.
	 *</p>
	 * 
	 * @return The z axis rotation of this <code>TransformationMatrixf</code>.
	 */
	float getZAxisRotation();

	/**
	 * <p>
	 * Rotates this <code>TransformationMatrixf</code> by the angle given about the axis given.
	 * </p>
	 * 
	 * @param angle The angle to rotate this <code>TransformationMatrixf</code>.
	 * @param axis The axis to rotate this <code>TransformationMatrixf</code> about.
	 */
	void rotate(float angle, Vectorf axis);
	
	/**
	 * <p>
	 * Sets the translation portion of this <code>TransformationMatrixf</code>.
	 * </p>
	 * 
	 * @param translation The translation portion of this <code>TransformationMatrixf</code>.
	 */
	void setTranslation(TranslationVectorf translation);
	
	/**
	 * Sets the x axis rotation of this <code>TransformationMatrixf</code>.
	 * 
	 * @param angle The x axis rotation of this <code>TransformationMatrixf</code>.
	 */
	void setXAxisRotation(float angle);
	
	/**
	 * Sets the y axis rotation of this <code>TransformationMatrixf</code>.
	 * 
	 * @param angle The y axis rotation of this <code>TransformationMatrixf</code>.
	 */
	void setYAxisRotation(float angle);
	
	/**
	 * Sets the z axis rotation of this <code>TransformationMatrixf</code>.
	 * 
	 * @param angle The z axis rotation of this <code>TransformationMatrixf</code>.
	 */
	void setZAxisRotation(float angle);

	/**
	 * <p>
	 * Translates this <code>TransformationMatrixf</code> by the translation given.
	 * </p>
	 * 
	 * @param translation The translation to translate this <code>TransformationMatrixf</code> by.
	 */
	void translate(TranslationVectorf translation);
}
