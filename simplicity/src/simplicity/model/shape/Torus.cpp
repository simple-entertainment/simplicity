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
#include "Torus.h"

namespace simplicity
{
  Torus::Torus() :
    fColour(new SimpleRGBColourVector4<float> (1.0f, 1.0f, 1.0f, 1.0f)), fInnerRadius(1.0f), fOuterRadius(2.0f)
  {
  }

  Torus::~Torus()
  {
    delete fColour;
  }

  TranslationVector<float> *
  Torus::getCenter() const
  {
    return (new SimpleTranslationVector4<float> ());
  }

  RGBColourVector<float> *
  Torus::getColour() const
  {
    return (fColour);
  }

  float
  Torus::getInnerRadius() const
  {
    return (fInnerRadius);
  }

  float
  Torus::getOuterRadius() const
  {
    return (fOuterRadius);
  }

  void
  Torus::setColour(RGBColourVector<float> * const colour)
  {
    fColour = colour;
  }

  void
  Torus::setInnerRadius(float const innerRadius)
  {
    fInnerRadius = innerRadius;
  }

  void
  Torus::setOuterRadius(float const outerRadius)
  {
    fOuterRadius = outerRadius;
  }
}
