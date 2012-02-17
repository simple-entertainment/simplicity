/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "../../math/SimpleRGBAColourVector4.h"
#include "../../math/SimpleTranslationVector4.h"
#include "Capsule.h"

namespace simplicity
{
  Capsule::Capsule() :
    fCenter(new SimpleTranslationVector4<> ), fColour(new SimpleRGBAColourVector4<> (1.0f, 1.0f, 1.0f, 1.0f)),
        fLength(1.0f), fRadius(1.0f)
  {
  }

  Capsule::~Capsule()
  {
  }

  const TranslationVector<>&
  Capsule::getCenter() const
  {
    return (*fCenter);
  }

  RGBAColourVector<>&
  Capsule::getColour() const
  {
    return (*fColour);
  }

  float
  Capsule::getLength() const
  {
    return (fLength);
  }

  float
  Capsule::getRadius() const
  {
    return (fRadius);
  }

  void
  Capsule::setColour(std::shared_ptr<RGBAColourVector<> > colour)
  {
    fColour = colour;
  }

  void
  Capsule::setLength(const float length)
  {
    fLength = length;
  }

  void
  Capsule::setRadius(const float radius)
  {
    fRadius = radius;
  }
}