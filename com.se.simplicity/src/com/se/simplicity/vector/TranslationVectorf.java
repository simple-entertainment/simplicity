package com.se.simplicity.vector;

/**
 * <p>
 * A translation vector that stores its data in a <code>float</code> array.
 * </p>
 * 
 * <p>
 * Copyright (c) 2009, simple entertainment
 * </p>
 * 
 * @author simple
 */
public interface TranslationVectorf extends Vectorf
{
	/**
	 * <p>
	 * Retrieves the w component of this <code>TranslationVectorf</code>.
	 * </p>
	 * 
	 * @return The w component of this <code>TranslationVectorf</code>.
	 */
	float getW();
	
	/**
	 * <p>
	 * Retrieves the x axis component of this <code>TranslationVectorf</code>.
	 * </p>
	 * 
	 * @return The x axis component of this <code>TranslationVectorf</code>.
	 */
	float getX();
	
	/**
	 * <p>
	 * Retrieves the y axis component of this <code>TranslationVectorf</code>.
	 * </p>
	 * 
	 * @return The y axis component of this <code>TranslationVectorf</code>.
	 */
	float getY();
	
	/**
	 * <p>
	 * Retrieves the z axis component of this <code>TranslationVectorf</code>.
	 * </p>
	 * 
	 * @return The z axis component of this <code>TranslationVectorf</code>.
	 */
	float getZ();
	
	/**
	 * <p>
	 * Sets the x axis component of this <code>TranslationVectorf</code>.
	 * </p>
	 * 
	 * @param x The x axis component of this <code>TranslationVectorf</code>.
	 */
	void setX(float x);
	
	/**
	 * <p>
	 * Sets the y axis component of this <code>TranslationVectorf</code>.
	 * </p>
	 * 
	 * @param y The y axis component of this <code>TranslationVectorf</code>.
	 */
	void setY(float y);
	
	/**
	 * <p>
	 * Sets the z axis component of this <code>TranslationVectorf</code>.
	 * </p>
	 * 
	 * @param z The z axis component of this <code>TranslationVectorf</code>.
	 */
	void setZ(float z);
	
	/**
	 * <p>
	 * Translates this <code>TranslationVectorf</code> by the given distance on the x axis.
	 * </p>
	 * 
	 * @param x The distance to translate this <code>TranslationVectorf</code> on the x axis.
	 */
	void translateX(float x);
	
	/**
	 * <p>
	 * Translates this <code>TranslationVectorf</code> by the given distance on the y axis.
	 * </p>
	 * 
	 * @param y The distance to translate this <code>TranslationVectorf</code> on the y axis.
	 */
	void translateY(float y);
	
	/**
	 * <p>
	 * Translates this <code>TranslationVectorf</code> by the given distance on the z axis.
	 * </p>
	 * 
	 * @param z The distance to translate this <code>TranslationVectorf</code> on the z axis.
	 */
	void translateZ(float z);
}
