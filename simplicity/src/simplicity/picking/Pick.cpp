/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "Pick.h"

namespace simplicity
{
  Pick::Pick() :
    fHeight(0.0f), fWidth(0.0f), fX(0.0f), fY(0.0f)
  {
  }

  Pick::~Pick()
  {
  }

  float
  Pick::getHeight() const
  {
    return (fHeight);
  }

  float
  Pick::getWidth() const
  {
    return (fWidth);
  }

  float
  Pick::getX() const
  {
    return (fX);
  }

  float
  Pick::getY() const
  {
    return (fY);
  }

  void
  Pick::setHeight(float const height)
  {
    fHeight = height;
  }

  void
  Pick::setWidth(float const width)
  {
    fWidth = width;
  }

  void
  Pick::setX(float const x)
  {
    fX = x;
  }

  void
  Pick::setY(float const y)
  {
    fY = y;
  }
}
