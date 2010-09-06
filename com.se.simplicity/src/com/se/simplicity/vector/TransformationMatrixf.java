/*
    This file is part of The Simplicity Engine.

    The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
package com.se.simplicity.vector;

/**
 * <p>
 * A transformation matrix that stores its data in a <code>float</code> array.
 * </p>
 * 
 * @author Gary Buyn
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
     * Retrieves the x axis rotation of this <code>TransformationMatrixf</code> in radians.
     *</p>
     * 
     * @return The x axis rotation of this <code>TransformationMatrixf</code> in radians.
     */
    float getXAxisRotation();

    /**
     *<p>
     * Retrieves the x axis translation of this <code>TransformationMatrixf</code>.
     *</p>
     * 
     * @return The x axis translation of this <code>TransformationMatrixf</code>.
     */
    float getXAxisTranslation();

    /**
     *<p>
     * Retrieves the y axis rotation of this <code>TransformationMatrixf</code> in radians.
     *</p>
     * 
     * @return The y axis rotation of this <code>TransformationMatrixf</code> in radians.
     */
    float getYAxisRotation();

    /**
     *<p>
     * Retrieves the y axis translation of this <code>TransformationMatrixf</code>.
     *</p>
     * 
     * @return The y axis translation of this <code>TransformationMatrixf</code>.
     */
    float getYAxisTranslation();

    /**
     *<p>
     * Retrieves the z axis rotation of this <code>TransformationMatrixf</code> in radians.
     *</p>
     * 
     * @return The z axis rotation of this <code>TransformationMatrixf</code> in radians.
     */
    float getZAxisRotation();

    /**
     *<p>
     * Retrieves the z axis translation of this <code>TransformationMatrixf</code>.
     *</p>
     * 
     * @return The z axis translation of this <code>TransformationMatrixf</code>.
     */
    float getZAxisTranslation();

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
     * Sets the x axis rotation of this <code>TransformationMatrixf</code> in radians.
     * 
     * @param angle The x axis rotation of this <code>TransformationMatrixf</code> in radians.
     */
    void setXAxisRotation(float angle);

    /**
     *<p>
     * Sets the x axis translation of this <code>TransformationMatrixf</code>.
     *</p>
     * 
     * @param distance The x axis translation of this <code>TransformationMatrixf</code>.
     */
    void setXAxisTranslation(float distance);

    /**
     * Sets the y axis rotation of this <code>TransformationMatrixf</code> in radians.
     * 
     * @param angle The y axis rotation of this <code>TransformationMatrixf</code> in radians.
     */
    void setYAxisRotation(float angle);

    /**
     *<p>
     * Sets the y axis translation of this <code>TransformationMatrixf</code>.
     *</p>
     * 
     * @param distance The y axis translation of this <code>TransformationMatrixf</code>.
     */
    void setYAxisTranslation(float distance);

    /**
     * Sets the z axis rotation of this <code>TransformationMatrixf</code> in radians.
     * 
     * @param angle The z axis rotation of this <code>TransformationMatrixf</code> in radians.
     */
    void setZAxisRotation(float angle);

    /**
     *<p>
     * Sets the z axis translation of this <code>TransformationMatrixf</code>.
     *</p>
     * 
     * @param distance The z axis translation of this <code>TransformationMatrixf</code>.
     */
    void setZAxisTranslation(float distance);

    /**
     * <p>
     * Translates this <code>TransformationMatrixf</code> by the translation given.
     * </p>
     * 
     * @param translation The translation to translate this <code>TransformationMatrixf</code> by.
     */
    void translate(TranslationVectorf translation);
}
