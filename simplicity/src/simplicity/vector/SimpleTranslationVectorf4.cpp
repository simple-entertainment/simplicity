/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleTranslationVectorf4.h"

namespace simplicity
{
    SimpleTranslationVectorf4::SimpleTranslationVectorf4() :
        SimpleVectorf4()
    {
    }

    SimpleTranslationVectorf4::SimpleTranslationVectorf4(const float f0, const float f1, const float f2, const float f3) :
        SimpleVectorf4(f0, f1, f2, f3)
    {
    }

    SimpleTranslationVectorf4::SimpleTranslationVectorf4(float* const array) :
        SimpleVectorf4(array)
    {
    }

    SimpleTranslationVectorf4::~SimpleTranslationVectorf4()
    {
    }

    float
    SimpleTranslationVectorf4::getW()
    {
        return (getArray()[3]);
    }

    float
    SimpleTranslationVectorf4::getX()
    {
        return (getArray()[0]);
    }

    float
    SimpleTranslationVectorf4::getY()
    {
        return (getArray()[1]);
    }

    float
    SimpleTranslationVectorf4::getZ()
    {
        return (getArray()[2]);
    }

    void
    SimpleTranslationVectorf4::setX(const float x)
    {
        getArray()[0] = x;
    }

    void
    SimpleTranslationVectorf4::setY(const float y)
    {
        getArray()[1] = y;
    }

    void
    SimpleTranslationVectorf4::setZ(const float z)
    {
        getArray()[2] = z;
    }

    void
    SimpleTranslationVectorf4::translateX(const float x)
    {
        getArray()[0] += x;
    }

    void
    SimpleTranslationVectorf4::translateY(const float y)
    {
        getArray()[1] += y;
    }

    void
    SimpleTranslationVectorf4::translateZ(const float z)
    {
        getArray()[2] += z;
    }
}
