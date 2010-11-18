/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <math.h>

#include "SimpleTransformationMatrixf44.h"
#include "SimpleTranslationVectorf4.h"

namespace simplicity
{
    SimpleTransformationMatrixf44::SimpleTransformationMatrixf44() :
        SimpleMatrixf44()
    {
    }

    SimpleTransformationMatrixf44::SimpleTransformationMatrixf44(float* const array) :
        SimpleMatrixf44(array)
    {
    }

    SimpleTransformationMatrixf44::~SimpleTransformationMatrixf44()
    {
    }

    TranslationVectorf*
    SimpleTransformationMatrixf44::getTranslation()
    {
        float* array = getArray();

        return (new SimpleTranslationVectorf4(array[12], array[13], array[14], array[15]));
    }

    float
    SimpleTransformationMatrixf44::getXAxisTranslation()
    {
        return (getArray()[12]);
    }

    float
    SimpleTransformationMatrixf44::getYAxisTranslation()
    {
        return (getArray()[13]);
    }

    float
    SimpleTransformationMatrixf44::getZAxisTranslation()
    {
        return (getArray()[14]);
    }

    void
    SimpleTransformationMatrixf44::rotate(const float angle, Vectorf* const axis)
    {
        float* array = getArray();
        float* axisArray = dynamic_cast<SimpleVectorf4*>(axis)->getArray();

        // Initialise trigonometric information.
        float cosine = cos(angle);
        float sine = sin(angle);
        float oneMinusCosine = 1.0f - cosine;

        float sineX = sine * axisArray[0];
        float sineY = sine * axisArray[1];
        float sineZ = sine * axisArray[2];

        float xy = axisArray[0] * axisArray[1];
        float xz = axisArray[0] * axisArray[2];
        float yz = axisArray[1] * axisArray[2];

        // Setup rotation matrix.
        // X axis component.
        float f00 = axisArray[0] * axisArray[0] * oneMinusCosine + cosine;
        float f01 = xy * oneMinusCosine + sineZ;
        float f02 = xz * oneMinusCosine - sineY;

        // Y axis component.
        float f10 = xy * oneMinusCosine - sineZ;
        float f11 = axisArray[1] * axisArray[1] * oneMinusCosine + cosine;
        float f12 = yz * oneMinusCosine + sineX;

        // Z axis component.
        float f20 = xz * oneMinusCosine + sineY;
        float f21 = yz * oneMinusCosine - sineX;
        float f22 = axisArray[2] * axisArray[2] * oneMinusCosine + cosine;

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

    void
    SimpleTransformationMatrixf44::setTranslation(TranslationVectorf* const translation)
    {
        float* array = getArray();
        float* transArray = ((SimpleVectorf4*) translation)->getArray();

        array[12] = transArray[0];
        array[13] = transArray[1];
        array[14] = transArray[2];
        array[15] = transArray[3];
    }

    void
    SimpleTransformationMatrixf44::setXAxisTranslation(const float distance)
    {
        getArray()[12] = distance;
    }

    void
    SimpleTransformationMatrixf44::setYAxisTranslation(const float distance)
    {
        getArray()[13] = distance;
    }

    void
    SimpleTransformationMatrixf44::setZAxisTranslation(const float distance)
    {
        getArray()[14] = distance;
    }

    void
    SimpleTransformationMatrixf44::translate(TranslationVectorf* const translation)
    {
        float* array = getArray();
        float* transArray = ((SimpleVectorf4*) translation)->getArray();

        array[12] += array[0] * transArray[0] + array[4] * transArray[1] + array[8] * transArray[2];
        array[13] += array[1] * transArray[0] + array[5] * transArray[1] + array[9] * transArray[2];
        array[14] += array[2] * transArray[0] + array[6] * transArray[1] + array[10] * transArray[2];
        array[15] += array[3] * transArray[0] + array[7] * transArray[1] + array[11] * transArray[2];
    }
}
