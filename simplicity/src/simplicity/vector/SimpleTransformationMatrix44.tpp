/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <math.h>

#include "SimpleTransformationMatrix44.h"
#include "SimpleTranslationVector4.h"

namespace simplicity
{
  template<class Data>
    SimpleTransformationMatrix44<Data>::SimpleTransformationMatrix44() :
      SimpleMatrix44<Data> ()
    {
    }

  template<class Data>
    SimpleTransformationMatrix44<Data>::SimpleTransformationMatrix44(array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX> data) :
      SimpleMatrix44<Data> (data)
    {
    }

  template<class Data>
    shared_ptr<TranslationVector<Data> >
    SimpleTransformationMatrix44<Data>::getTranslation() const
    {
      const array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX> data(SimpleMatrix44<Data>::getData());

      return (shared_ptr<TranslationVector<Data> > (new SimpleTranslationVector4<Data> (data.at(12), data.at(13), data.at(14), data.at(15))));
    }

  template<class Data>
    Data
    SimpleTransformationMatrix44<Data>::getXAxisTranslation() const
    {
      return (SimpleMatrix44<Data>::getData().at(12));
    }

  template<class Data>
    Data
    SimpleTransformationMatrix44<Data>::getYAxisTranslation() const
    {
      return (SimpleMatrix44<Data>::getData().at(13));
    }

  template<class Data>
    Data
    SimpleTransformationMatrix44<Data>::getZAxisTranslation() const
    {
      return (SimpleMatrix44<Data>::getData().at(14));
    }

  template<class Data>
    void
    SimpleTransformationMatrix44<Data>::rotate(const Data angle, const Vector<Data>& axis)
    {
      array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX>& data = SimpleMatrix44<Data>::getData();
      const array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR> axisData = dynamic_cast<const SimpleVector4<Data>& > (axis).getData();

      // Initialise trigonometric information.
      Data cosine = cos(angle);
      Data sine = sin(angle);
      Data oneMinusCosine = 1 - cosine;

      Data sineX = sine * axisData.at(0);
      Data sineY = sine * axisData.at(1);
      Data sineZ = sine * axisData.at(2);

      Data xy = axisData.at(0) * axisData.at(1);
      Data xz = axisData.at(0) * axisData.at(2);
      Data yz = axisData.at(1) * axisData.at(2);

      // Setup rotation matrix.
      // X axis component.
      Data d00 = axisData.at(0) * axisData.at(0) * oneMinusCosine + cosine;
      Data d01 = xy * oneMinusCosine + sineZ;
      Data d02 = xz * oneMinusCosine - sineY;

      // Y axis component.
      Data d10 = xy * oneMinusCosine - sineZ;
      Data d11 = axisData.at(1) * axisData.at(1) * oneMinusCosine + cosine;
      Data d12 = yz * oneMinusCosine + sineX;

      // Z axis component.
      Data d20 = xz * oneMinusCosine + sineY;
      Data d21 = yz * oneMinusCosine - sineX;
      Data d22 = axisData.at(2) * axisData.at(2) * oneMinusCosine + cosine;

      Data temp00 = data.at(0) * d00 + data.at(4) * d01 + data.at(8) * d02;
      Data temp01 = data.at(1) * d00 + data.at(5) * d01 + data.at(9) * d02;
      Data temp02 = data.at(2) * d00 + data.at(6) * d01 + data.at(10) * d02;
      Data temp03 = data.at(3) * d00 + data.at(7) * d01 + data.at(11) * d02;
      Data temp10 = data.at(0) * d10 + data.at(4) * d11 + data.at(8) * d12;
      Data temp11 = data.at(1) * d10 + data.at(5) * d11 + data.at(9) * d12;
      Data temp12 = data.at(2) * d10 + data.at(6) * d11 + data.at(10) * d12;
      Data temp13 = data.at(3) * d10 + data.at(7) * d11 + data.at(11) * d12;
      data.at(8) = data.at(0) * d20 + data.at(4) * d21 + data.at(8) * d22;
      data.at(9) = data.at(1) * d20 + data.at(5) * d21 + data.at(9) * d22;
      data.at(10) = data.at(2) * d20 + data.at(6) * d21 + data.at(10) * d22;
      data.at(11) = data.at(3) * d20 + data.at(7) * d21 + data.at(11) * d22;
      data.at(0) = temp00;
      data.at(1) = temp01;
      data.at(2) = temp02;
      data.at(3) = temp03;
      data.at(4) = temp10;
      data.at(5) = temp11;
      data.at(6) = temp12;
      data.at(7) = temp13;
    }

  template<class Data>
    void
    SimpleTransformationMatrix44<Data>::setTranslation(shared_ptr<TranslationVector<Data> > translation)
    {
      array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX>& data = SimpleMatrix44<Data>::getData();
      const array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR> transData = dynamic_cast<const SimpleVector4<Data>& > (*translation).getData();

      data.at(12) = transData.at(0);
      data.at(13) = transData.at(1);
      data.at(14) = transData.at(2);
      data.at(15) = transData.at(3);
    }

  template<class Data>
    void
    SimpleTransformationMatrix44<Data>::setXAxisTranslation(Data const distance)
    {
      SimpleMatrix44<Data>::getData().at(12) = distance;
    }

  template<class Data>
    void
    SimpleTransformationMatrix44<Data>::setYAxisTranslation(Data const distance)
    {
      SimpleMatrix44<Data>::getData().at(13) = distance;
    }

  template<class Data>
    void
    SimpleTransformationMatrix44<Data>::setZAxisTranslation(Data const distance)
    {
      SimpleMatrix44<Data>::getData().at(14) = distance;
    }

  template<class Data>
    void
    SimpleTransformationMatrix44<Data>::translate(const TranslationVector<Data>& translation)
    {
      array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX>& data = SimpleMatrix44<Data>::getData();
      const array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR> transData = dynamic_cast<const SimpleVector4<Data>& > (translation).getData();

      data.at(12) += data.at(0) * transData.at(0) + data.at(4) * transData.at(1) + data.at(8) * transData.at(2);
      data.at(13) += data.at(1) * transData.at(0) + data.at(5) * transData.at(1) + data.at(9) * transData.at(2);
      data.at(14) += data.at(2) * transData.at(0) + data.at(6) * transData.at(1) + data.at(10) * transData.at(2);
      data.at(15) += data.at(3) * transData.at(0) + data.at(7) * transData.at(1) + data.at(11) * transData.at(2);
    }
}
