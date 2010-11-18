/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleRGBColourVectorf4.h"

namespace simplicity
{
    SimpleRGBColourVectorf4::SimpleRGBColourVectorf4() :
        SimpleVectorf4()
    {
    }

    SimpleRGBColourVectorf4::SimpleRGBColourVectorf4(const float f0, const float f1, const float f2, const float f3) :
        SimpleVectorf4(f0, f1, f2, f3)
    {
    }

    SimpleRGBColourVectorf4::SimpleRGBColourVectorf4(float* array) :
        SimpleVectorf4(array)
    {
    }

    SimpleRGBColourVectorf4::~SimpleRGBColourVectorf4()
    {
    }

    float
    SimpleRGBColourVectorf4::getBlue()
    {
        return (getArray()[2]);
    }

    float
    SimpleRGBColourVectorf4::getGreen()
    {
        return (getArray()[1]);
    }

    float
    SimpleRGBColourVectorf4::getRed()
    {
        return (getArray()[0]);
    }

    void
    SimpleRGBColourVectorf4::setBlue(const float blue)
    {
        getArray()[2] = blue;
    }

    void
    SimpleRGBColourVectorf4::setGreen(const float green)
    {
        getArray()[1] = green;
    }

    void
    SimpleRGBColourVectorf4::setRed(const float red)
    {
        getArray()[0] = red;
    }
}
