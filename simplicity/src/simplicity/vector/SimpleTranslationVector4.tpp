/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include "SimpleTranslationVector4.h"

using namespace boost;

namespace simplicity
{
  template<class Data>
    SimpleTranslationVector4<Data>::SimpleTranslationVector4() :
      SimpleVector4<Data> ()
    {
    }

  template<class Data>
    SimpleTranslationVector4<Data>::SimpleTranslationVector4(const Data x, const Data y, const Data z, const Data w) :
      SimpleVector4<Data> (x, y, z, w)
    {
    }

  template<class Data>
    SimpleTranslationVector4<Data>::SimpleTranslationVector4(array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR> data) :
      SimpleVector4<Data> (data)
    {
    }

  template<class Data>
    Data
    SimpleTranslationVector4<Data>::getW() const
    {
      return (SimpleVector4<Data>::getData().at(3));
    }

  template<class Data>
    Data
    SimpleTranslationVector4<Data>::getX() const
    {
      return (SimpleVector4<Data>::getData().at(0));
    }

  template<class Data>
    Data
    SimpleTranslationVector4<Data>::getY() const
    {
      return (SimpleVector4<Data>::getData().at(1));
    }

  template<class Data>
    Data
    SimpleTranslationVector4<Data>::getZ() const
    {
      return (SimpleVector4<Data>::getData().at(2));
    }

  template<class Data>
    void
    SimpleTranslationVector4<Data>::setX(const Data x)
    {
      SimpleVector4<Data>::getData().at(0) = x;
    }

  template<class Data>
    void
    SimpleTranslationVector4<Data>::setY(const Data y)
    {
      SimpleVector4<Data>::getData().at(1) = y;
    }

  template<class Data>
    void
    SimpleTranslationVector4<Data>::setZ(const Data z)
    {
      SimpleVector4<Data>::getData().at(2) = z;
    }

  template<class Data>
    void
    SimpleTranslationVector4<Data>::translateX(const Data x)
    {
      SimpleVector4<Data>::getData().at(0) += x;
    }

  template<class Data>
    void
    SimpleTranslationVector4<Data>::translateY(const Data y)
    {
      SimpleVector4<Data>::getData().at(1) += y;
    }

  template<class Data>
    void
    SimpleTranslationVector4<Data>::translateZ(const Data z)
    {
      SimpleVector4<Data>::getData().at(2) += z;
    }
}
