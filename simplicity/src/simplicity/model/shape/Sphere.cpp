/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../../vector/SimpleRGBColourVectorf4.h"
#include "../../vector/SimpleTranslationVectorf4.h"
#include "Sphere.h"

namespace simplicity
{
    Sphere::Sphere() :
        fColour(new SimpleRGBColourVectorf4(1.0f, 1.0f, 1.0f, 1.0f)), fRadius(1.0f)
    {
    }

    Sphere::~Sphere()
    {
        delete fColour;
    }

    TranslationVectorf*
    Sphere::getCenter()
    {
        return (new SimpleTranslationVectorf4());
    }

    RGBColourVectorf*
    Sphere::getColour()
    {
        return (fColour);
    }

    float
    Sphere::getRadius()
    {
        return (fRadius);
    }

    void
    Sphere::setColour(RGBColourVectorf* const colour)
    {
        fColour = colour;
    }

    void
    Sphere::setRadius(const float radius)
    {
        fRadius = radius;
    }
}
