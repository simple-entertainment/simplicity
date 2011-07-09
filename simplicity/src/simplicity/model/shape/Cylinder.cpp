/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../../vector/SimpleRGBColourVector4.h"
#include "../../vector/SimpleTranslationVector4.h"
#include "Cylinder.h"

namespace simplicity
{
  Cylinder::Cylinder() :
    fColour(new SimpleRGBColourVector4<float> (1.0f, 1.0f, 1.0f, 1.0f)), fLength(1.0f), fRadius(1.0f)
  {
  }

  Cylinder::~Cylinder()
  {
    delete fColour;
  }

  TranslationVector<float> *
  Cylinder::getCenter() const
  {
    return (new SimpleTranslationVector4<float> ());
  }

  RGBColourVector<float> *
  Cylinder::getColour() const
  {
    return (fColour);
  }

  float
  Cylinder::getLength() const
  {
    return (fLength);
  }

  float
  Cylinder::getRadius() const
  {
    return (fRadius);
  }

  void
  Cylinder::setColour(RGBColourVector<float> * const colour)
  {
    fColour = colour;
  }

  void
  Cylinder::setLength(float const length)
  {
    fLength = length;
  }

  void
  Cylinder::setRadius(float const radius)
  {
    fRadius = radius;
  }
}
