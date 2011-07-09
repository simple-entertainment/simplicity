/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <math.h>

#include <boost/lexical_cast.hpp>
using namespace boost;

#include "SimpleVector4.h"

namespace simplicity
{
  template<class Data>
    SimpleVector4<Data>::SimpleVector4()
    {
      fData.at(0) = 0;
      fData.at(1) = 0;
      fData.at(2) = 0;
      fData.at(3) = 1;
    }

  template<class Data>
    SimpleVector4<Data>::SimpleVector4(Data const d0, Data const d1, Data const d2, Data const d3)
    {
      fData.at(0) = d0;
      fData.at(1) = d1;
      fData.at(2) = d2;
      fData.at(3) = d3;
    }

  template<class Data>
    SimpleVector4<Data>::SimpleVector4(array<Data, 4> data)
    {
      fData = data;
    }

  template<class Data>
    array<Data, 4>
    SimpleVector4<Data>::add(SimpleVector4<Data> const & leftVector, SimpleVector4<Data> const & rightVector) const
    {
      array<Data, CELLS_IN_VECTOR> leftData = leftVector.getDataCopy();
      array<Data, CELLS_IN_VECTOR> rightData = rightVector.getDataCopy();
      array<Data, CELLS_IN_VECTOR> addData;

      addData.at(0) = leftData.at(0) + rightData.at(0);
      addData.at(1) = leftData.at(1) + rightData.at(1);
      addData.at(2) = leftData.at(2) + rightData.at(2);
      addData.at(3) = 1;

      return (addData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::add(Vector<Data> const * const otherVector)
    {
      fData = add(*this, *dynamic_cast<SimpleVector4<Data> const * const > (otherVector));
    }

  template<class Data>
    Vector<Data> *
    SimpleVector4<Data>::addCopy(Vector<Data> const * const otherVector) const
    {
      return (new SimpleVector4<Data> (add(*this, *dynamic_cast<SimpleVector4<Data> const * const > (otherVector))));
    }

  template<class Data>
    array<Data, 4>
    SimpleVector4<Data>::crossProduct(SimpleVector4<Data> const & leftVector, SimpleVector4<Data> const & rightVector) const
    {
      array<Data, CELLS_IN_VECTOR> leftData = leftVector.getDataCopy();
      array<Data, CELLS_IN_VECTOR> rightData = rightVector.getDataCopy();
      array<Data, CELLS_IN_VECTOR> crossData;

      crossData.at(0) = leftData.at(1) * rightData.at(2) - leftData.at(2) * rightData.at(1);
      crossData.at(1) = leftData.at(2) * rightData.at(0) - leftData.at(0) * rightData.at(2);
      crossData.at(2) = leftData.at(0) * rightData.at(1) - leftData.at(1) * rightData.at(0);
      crossData.at(3) = 1;

      return (crossData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::crossProductRight(Vector<Data> const * const otherVector)
    {
      fData = crossProduct(*this, *dynamic_cast<SimpleVector4<Data> const * const > (otherVector));
    }

  template<class Data>
    Vector<Data> *
    SimpleVector4<Data>::crossProductRightCopy(Vector<Data> const * const otherVector) const
    {
      return (new SimpleVector4<Data> (crossProduct(*this, *dynamic_cast<SimpleVector4<Data> const * const > (otherVector))));
    }

  template<class Data>
    Data
    SimpleVector4<Data>::dotProduct(Vector<Data> const * const otherVector)
    {
      array<Data, CELLS_IN_VECTOR> otherData = (dynamic_cast<SimpleVector4<Data> const * const > (otherVector))->getDataCopy();
      Data dot = 0;

      for (int index = 0; index < 3; index++)
        {
          dot += fData.at(index) * otherData.at(index);
        }

      return (dot);
    }

  template<class Data>
    array<Data, 4> &
    SimpleVector4<Data>::getData()
    {
      return (fData);
    }

  template<class Data>
    array<Data, 4>
    SimpleVector4<Data>::getDataCopy() const
    {
      return (fData);
    }

  template<class Data>
    Data
    SimpleVector4<Data>::getLength() const
    {
      return (sqrt(getLengthSquared()));
    }

  template<class Data>
    Data
    SimpleVector4<Data>::getLengthSquared() const
    {
      return (fData.at(0) * fData.at(0) + fData.at(1) * fData.at(1) + fData.at(2) * fData.at(2));
    }

  template<class Data>
    void
    SimpleVector4<Data>::homogenize()
    {
      if (fData.at(3) == 1)
        {
          return;
        }

      fData.at(0) = fData.at(0) / fData.at(3);
      fData.at(1) = fData.at(1) / fData.at(3);
      fData.at(2) = fData.at(2) / fData.at(3);
      fData.at(3) = 1;
    }

  template<class Data>
    array<Data, 4>
    SimpleVector4<Data>::multiply(SimpleVector4<Data> const & leftVector, SimpleVector4<Data> const & rightVector) const
    {
      array<Data, CELLS_IN_VECTOR> leftData = leftVector.getDataCopy();
      array<Data, CELLS_IN_VECTOR> rightData = rightVector.getDataCopy();
      array<Data, CELLS_IN_VECTOR> multData;

      multData.at(0) = leftData.at(0) * rightData.at(0);
      multData.at(1) = leftData.at(1) * rightData.at(1);
      multData.at(2) = leftData.at(2) * rightData.at(2);
      multData.at(3) = 1;

      return (multData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::multiplyLeft(Matrix<Data> const * const otherMatrix)
    {
      fData = multiplyLeft(*dynamic_cast<SimpleMatrix44<Data> const * const > (otherMatrix));
    }

  template<class Data>
    array<Data, 4>
    SimpleVector4<Data>::multiplyLeft(SimpleMatrix44<Data> const & otherMatrix) const
    {
      array<Data, 16> mData = otherMatrix.getDataCopy();
      array<Data, CELLS_IN_VECTOR> vData = fData;
      array<Data, CELLS_IN_VECTOR> multData;

      // For every row in the matrix.
      for (int row = 0; row < CELLS_IN_VECTOR; row++)
        {
          Data sum = 0;

          // For every element in the vector and every element in the current
          // row of the matrix.
          for (int element = 0; element < CELLS_IN_VECTOR; element++)
            {
              // Add the product of the two to the value for the new vector.
              sum += mData.at(row + (element * CELLS_IN_VECTOR)) * vData.at(element);
            }

          multData.at(row) = sum;
        }

      return (multData);
    }

  template<class Data>
    Vector<Data> *
    SimpleVector4<Data>::multiplyLeftCopy(Matrix<Data> const * const otherMatrix) const
    {
      return (new SimpleVector4<Data> (multiplyLeft(*dynamic_cast<SimpleMatrix44<Data> const * const > (otherMatrix))));
    }

  template<class Data>
    void
    SimpleVector4<Data>::multiplyRight(Matrix<Data> const * const otherMatrix)
    {
      fData = multiplyRight(*dynamic_cast<SimpleMatrix44<Data> const * const > (otherMatrix));
    }

  template<class Data>
    array<Data, 4>
    SimpleVector4<Data>::multiplyRight(SimpleMatrix44<Data> const & otherMatrix) const
    {
      array<Data, CELLS_IN_VECTOR> vData = fData;
      array<Data, 16> mData = otherMatrix.getDataCopy();
      array<Data, CELLS_IN_VECTOR> multData;

      // For every column in the matrix.
      for (int column = 0; column < CELLS_IN_VECTOR; column++)
        {
          Data sum = 0;

          // For every element in the vector and every element in the current
          // column of the matrix.
          for (int element = 0; element < CELLS_IN_VECTOR; element++)
            {
              // Add the product of the two to the value for the new vector.
              sum += vData.at(element) * mData.at((column * CELLS_IN_VECTOR) + element);
            }

          multData.at(column) = sum;
        }

      return (multData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::multiplyRight(Vector<Data> const * const otherVector)
    {
      fData = multiply(*this, *dynamic_cast<SimpleVector4<Data> const * const > (otherVector));
    }

  template<class Data>
    Vector<Data> *
    SimpleVector4<Data>::multiplyRightCopy(Matrix<Data> const * const otherMatrix) const
    {
      return (new SimpleVector4<Data> (multiplyRight(*dynamic_cast<SimpleMatrix44<Data> const * const > (otherMatrix))));
    }

  template<class Data>
    Vector<Data> *
    SimpleVector4<Data>::multiplyRightCopy(Vector<Data> const * const otherVector) const
    {
      return (new SimpleVector4<Data> (multiply(*this, *dynamic_cast<SimpleVector4<Data> const * const > (otherVector))));
    }

  template<class Data>
    void
    SimpleVector4<Data>::negate()
    {
      scale(-1);
    }

  template<class Data>
    void
    SimpleVector4<Data>::normalize()
    {
      Data sum = fData.at(0) + fData.at(1) + fData.at(2);

      scale(1 / sum);
    }

  template<class Data>
    void
    SimpleVector4<Data>::scale(Data const scalar)
    {
      fData.at(0) = fData.at(0) * scalar;
      fData.at(1) = fData.at(1) * scalar;
      fData.at(2) = fData.at(2) * scalar;
    }

  template<class Data>
    array<Data, 4>
    SimpleVector4<Data>::subtract(SimpleVector4<Data> const & leftVector, SimpleVector4<Data> const & rightVector) const
    {
      array<Data, CELLS_IN_VECTOR> leftData = leftVector.getDataCopy();
      array<Data, CELLS_IN_VECTOR> rightData = rightVector.getDataCopy();
      array<Data, CELLS_IN_VECTOR> subData;

      subData.at(0) = leftData.at(0) - rightData.at(0);
      subData.at(1) = leftData.at(1) - rightData.at(1);
      subData.at(2) = leftData.at(2) - rightData.at(2);
      subData.at(3) = 1;

      return (subData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::subtractRight(Vector<Data> const * const otherVector)
    {
      fData = subtract(*this, *dynamic_cast<SimpleVector4<Data> const * const > (otherVector));
    }

  template<class Data>
    Vector<Data> *
    SimpleVector4<Data>::subtractRightCopy(Vector<Data> const * const otherVector) const
    {
      return (new SimpleVector4(subtract(*this, *dynamic_cast<SimpleVector4<Data> const * const > (otherVector))));
    }

  template<class Data>
    string
    SimpleVector4<Data>::toString() const
    {
      string vectorString = "";

      vectorString += "-------------------------\n";
      vectorString += "| " + lexical_cast<string> (fData.at(0)) + " | " + lexical_cast<string> (fData.at(1)) + " | "
          + lexical_cast<string> (fData.at(2)) + " | " + lexical_cast<string> (fData.at(3)) + " |\n";
      vectorString += "-------------------------\n";

      return (vectorString);
    }
}
