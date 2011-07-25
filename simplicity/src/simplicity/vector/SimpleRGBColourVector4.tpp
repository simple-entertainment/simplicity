/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleRGBColourVector4.h"

namespace simplicity
{
  template<class Data>
    SimpleRGBColourVector4<Data>::SimpleRGBColourVector4() :
      SimpleVector4<Data> ()
    {
    }

  template<class Data>
    SimpleRGBColourVector4<Data>::SimpleRGBColourVector4(const Data r, const Data g, const Data b, const Data a) :
      SimpleVector4<Data> (r, g, b, a)
    {
    }

  template<class Data>
    SimpleRGBColourVector4<Data>::SimpleRGBColourVector4(array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR> data) :
      SimpleVector4<Data> (data)
    {
    }

  template<class Data>
    Data
    SimpleRGBColourVector4<Data>::getBlue() const
    {
      return (SimpleVector4<Data>::getDataCopy().at(2));
    }

  template<class Data>
    Data
    SimpleRGBColourVector4<Data>::getGreen() const
    {
      return (SimpleVector4<Data>::getDataCopy().at(1));
    }

  template<class Data>
    Data
    SimpleRGBColourVector4<Data>::getRed() const
    {
      return (SimpleVector4<Data>::getDataCopy().at(0));
    }

  template<class Data>
    void
    SimpleRGBColourVector4<Data>::setBlue(const Data blue)
    {
      SimpleVector4<Data>::getData().at(2) = blue;
    }

  template<class Data>
    void
    SimpleRGBColourVector4<Data>::setGreen(const Data green)
    {
      SimpleVector4<Data>::getData().at(1) = green;
    }

  template<class Data>
    void
    SimpleRGBColourVector4<Data>::setRed(const Data red)
    {
      SimpleVector4<Data>::getData().at(0) = red;
    }
}
