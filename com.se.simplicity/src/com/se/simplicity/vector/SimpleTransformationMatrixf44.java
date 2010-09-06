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
 * A 4x4 transformation matrix that stores its data in a <code>float</code> array.
 * </p>
 * 
 * <p>
 * This <code>SimpleTransformationMatrixf44</code> uses a 3D homogeneous coordinate system. It is of the following format:
 * </p>
 * 
 * <pre>
 * --------------------
 *  xx | yx | zx | tx |
 * --------------------
 *  xy | yy | zy | ty |
 * --------------------
 *  xz | yz | zz | tz |
 * --------------------
 *  xw | yw | zw | tw |
 * --------------------
 * </pre>
 * 
 * <p>
 * Where the first column is the x axis rotation, the second column is the y axis rotation, the third column is the z axis rotation and the fourth
 * column is the translation.
 * </p>
 * 
 * <p>
 * It is stored in column-major format. This means the first four indices of the array represent the first column of the
 * <code>SimpleTransformationMatrixf44</code>, the second four represent the second column etc.
 * </p>
 * 
 * @author Gary Buyn
 */
public class SimpleTransformationMatrixf44 extends SimpleMatrixf44 implements TransformationMatrixf
{
    /**
     * The version of this class.
     */
    private static final long serialVersionUID = 1L;

    /**
     * <p>
     * Creates an instance of <code>SimpleTransformationMatrixf44</code>.
     * </p>
     */
    public SimpleTransformationMatrixf44()
    {
        super();
    }

    /**
     * <p>
     * Creates an instance of <code>SimpleTransformationMatrixf44</code>.
     * </p>
     * 
     * @param array An array containing the initial elements for this <code>SimpleMatrixf44</code>.
     */
    public SimpleTransformationMatrixf44(final float[] array)
    {
        super(array);
    }

    @Override
    public TranslationVectorf getTranslation()
    {
        float[] array = getArray();

        return (new SimpleTranslationVectorf4(array[12], array[13], array[14], array[15]));
    }

    @Override
    public float getXAxisRotation()
    {
        return ((float) Math.atan2(getArray()[6], getArray()[10]));
    }

    @Override
    public float getXAxisTranslation()
    {
        return (getArray()[12]);
    }

    @Override
    public float getYAxisRotation()
    {
        return ((float) -Math.asin(getArray()[2]));
    }

    @Override
    public float getYAxisTranslation()
    {
        return (getArray()[13]);
    }

    @Override
    public float getZAxisRotation()
    {
        return ((float) Math.atan2(getArray()[1], getArray()[0]));
    }

    @Override
    public float getZAxisTranslation()
    {
        return (getArray()[14]);
    }

    @Override
    public void rotate(final float angle, final Vectorf axis)
    {
        float[] array = getArray();
        float[] axisArray = ((SimpleVectorf4) axis).getArray();

        // Initialise trigonometric information.
        float cos = (float) Math.cos(angle);
        float sin = (float) Math.sin(angle);
        float oneMinusCos = 1.0f - cos;

        float sinX = sin * axisArray[0];
        float sinY = sin * axisArray[1];
        float sinZ = sin * axisArray[2];

        float xy = axisArray[0] * axisArray[1];
        float xz = axisArray[0] * axisArray[2];
        float yz = axisArray[1] * axisArray[2];

        // Setup rotation matrix.
        // X axis component.
        float f00 = axisArray[0] * axisArray[0] * oneMinusCos + cos;
        float f01 = xy * oneMinusCos + sinZ;
        float f02 = xz * oneMinusCos - sinY;

        // Y axis component.
        float f10 = xy * oneMinusCos - sinZ;
        float f11 = axisArray[1] * axisArray[1] * oneMinusCos + cos;
        float f12 = yz * oneMinusCos + sinX;

        // Z axis component.
        float f20 = xz * oneMinusCos + sinY;
        float f21 = yz * oneMinusCos - sinX;
        float f22 = axisArray[2] * axisArray[2] * oneMinusCos + cos;

        float temp00 = array[0] * f00 + array[4] * f01 + array[8] * f02;
        float temp01 = array[1] * f00 + array[5] * f01 + array[9] * f02;
        float temp02 = array[2] * f00 + array[6] * f01 + array[10] * f02;
        float temp03 = array[3] * f00 + array[7] * f01 + array[11] * f02;
        float temp10 = array[0] * f10 + array[4] * f11 + array[8] * f12;
        float temp11 = array[1] * f10 + array[5] * f11 + array[9] * f12;
        float temp12 = array[2] * f10 + array[6] * f11 + array[10] * f12;
        float temp13 = array[3] * f10 + array[7] * f11 + array[11] * f12;
        array[8] = array[0] * f20 + array[4] * f21 + array[8] * f22;
        array[9] = array[1] * f20 + array[5] * f21 + array[9] * f22;
        array[10] = array[2] * f20 + array[6] * f21 + array[10] * f22;
        array[11] = array[3] * f20 + array[7] * f21 + array[11] * f22;
        array[0] = temp00;
        array[1] = temp01;
        array[2] = temp02;
        array[3] = temp03;
        array[4] = temp10;
        array[5] = temp11;
        array[6] = temp12;
        array[7] = temp13;
    }

    @Override
    public void setTranslation(final TranslationVectorf translation)
    {
        float[] array = getArray();
        float[] transArray = ((SimpleVectorf4) translation).getArray();

        array[12] = transArray[0];
        array[13] = transArray[1];
        array[14] = transArray[2];
        array[15] = transArray[3];
    }

    @Override
    public void setXAxisRotation(final float angle)
    {
        rotate(angle - getXAxisRotation(), new SimpleVectorf4(1.0f, 0.0f, 0.0f, 1.0f));
    }

    @Override
    public void setXAxisTranslation(final float distance)
    {
        getArray()[12] = distance;
    }

    @Override
    public void setYAxisRotation(final float angle)
    {
        rotate(angle - getYAxisRotation(), new SimpleVectorf4(0.0f, 1.0f, 0.0f, 1.0f));
    }

    @Override
    public void setYAxisTranslation(final float distance)
    {
        getArray()[13] = distance;
    }

    @Override
    public void setZAxisRotation(final float angle)
    {
        rotate(angle - getZAxisRotation(), new SimpleVectorf4(0.0f, 0.0f, 1.0f, 1.0f));
    }

    @Override
    public void setZAxisTranslation(final float distance)
    {
        getArray()[14] = distance;
    }

    @Override
    public void translate(final TranslationVectorf translation)
    {
        float[] array = getArray();
        float[] transArray = ((SimpleVectorf4) translation).getArray();

        array[12] += array[0] * transArray[0] + array[4] * transArray[1] + array[8] * transArray[2];
        array[13] += array[1] * transArray[0] + array[5] * transArray[1] + array[9] * transArray[2];
        array[14] += array[2] * transArray[0] + array[6] * transArray[1] + array[10] * transArray[2];
        array[15] += array[3] * transArray[0] + array[7] * transArray[1] + array[11] * transArray[2];
    }
}
