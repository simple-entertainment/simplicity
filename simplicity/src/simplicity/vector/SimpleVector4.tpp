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

#include "SimpleVector4.h"

using namespace boost;
using namespace std;

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
    SimpleVector4<Data>::SimpleVector4(const Data d0, const Data d1, const Data d2, const Data d3)
    {
      fData.at(0) = d0;
      fData.at(1) = d1;
      fData.at(2) = d2;
      fData.at(3) = d3;
    }

  template<class Data>
    SimpleVector4<Data>::SimpleVector4(array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR> data)
    {
      fData = data;
    }

  template<class Data>
    array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR>
    SimpleVector4<Data>::add(const SimpleVector4<Data>& leftVector, const SimpleVector4<Data>& rightVector) const
    {
      const array<Data, CELLS_IN_VECTOR> leftData = leftVector.getData();
      const array<Data, CELLS_IN_VECTOR> rightData = rightVector.getData();
      array<Data, CELLS_IN_VECTOR> addData;

      addData.at(0) = leftData.at(0) + rightData.at(0);
      addData.at(1) = leftData.at(1) + rightData.at(1);
      addData.at(2) = leftData.at(2) + rightData.at(2);
      addData.at(3) = 1;

      return (addData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::add(const Vector<Data>& otherVector)
    {
      fData = add(*this, dynamic_cast<const SimpleVector4<Data>&> (otherVector));
    }

  template<class Data>
    shared_ptr<Vector<Data> >
    SimpleVector4<Data>::addCopy(const Vector<Data>& otherVector) const
    {
      return (shared_ptr<Vector<Data> > (
          new SimpleVector4<Data> (add(*this, dynamic_cast<const SimpleVector4<Data>&> (otherVector)))));
    }

  template<class Data>
    array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR>
    SimpleVector4<Data>::crossProduct(const SimpleVector4<Data>& leftVector, const SimpleVector4<Data>& rightVector) const
    {
      const array<Data, CELLS_IN_VECTOR> leftData = leftVector.getData();
      const array<Data, CELLS_IN_VECTOR> rightData = rightVector.getData();
      array<Data, CELLS_IN_VECTOR> crossData;

      crossData.at(0) = leftData.at(1) * rightData.at(2) - leftData.at(2) * rightData.at(1);
      crossData.at(1) = leftData.at(2) * rightData.at(0) - leftData.at(0) * rightData.at(2);
      crossData.at(2) = leftData.at(0) * rightData.at(1) - leftData.at(1) * rightData.at(0);
      crossData.at(3) = 1;

      return (crossData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::crossProductRight(const Vector<Data>& otherVector)
    {
      fData = crossProduct(*this, dynamic_cast<const SimpleVector4<Data>&> (otherVector));
    }

  template<class Data>
    shared_ptr<Vector<Data> >
    SimpleVector4<Data>::crossProductRightCopy(const Vector<Data>& otherVector) const
    {
      return (shared_ptr<Vector<Data> > (
          new SimpleVector4<Data> (crossProduct(*this, dynamic_cast<const SimpleVector4<Data>&> (otherVector)))));
    }

  template<class Data>
    Data
    SimpleVector4<Data>::dotProduct(const Vector<Data>& otherVector)
    {
      const array<Data, CELLS_IN_VECTOR> otherData = (dynamic_cast<const SimpleVector4<Data>&> (otherVector)).getData();
      Data dot = 0;

      for (int index = 0; index < 3; index++)
      {
        dot += fData.at(index) * otherData.at(index);
      }

      return (dot);
    }

  template<class Data>
    bool
    SimpleVector4<Data>::equals(const Vector<Data>& otherVector) const
    {
      return (fData == dynamic_cast<const SimpleVector4<Data>&> (otherVector).getData());
    }

  template<class Data>
    array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR>&
    SimpleVector4<Data>::getData()
    {
      return (fData);
    }

  template<class Data>
    const array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR>&
    SimpleVector4<Data>::getData() const
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
    const Data* const
    SimpleVector4<Data>::getRawData() const
    {
      return (fData.data());
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
    array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR>
    SimpleVector4<Data>::multiply(const SimpleVector4<Data>& leftVector, const SimpleVector4<Data>& rightVector) const
    {
      const array<Data, CELLS_IN_VECTOR> leftData = leftVector.getData();
      const array<Data, CELLS_IN_VECTOR> rightData = rightVector.getData();
      array<Data, CELLS_IN_VECTOR> multData;

      multData.at(0) = leftData.at(0) * rightData.at(0);
      multData.at(1) = leftData.at(1) * rightData.at(1);
      multData.at(2) = leftData.at(2) * rightData.at(2);
      multData.at(3) = 1;

      return (multData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::multiplyLeft(const Matrix<Data>& otherMatrix)
    {
      fData = multiplyLeftInternal(dynamic_cast<const SimpleMatrix44<Data>&> (otherMatrix));
    }

  template<class Data>
    array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR>
    SimpleVector4<Data>::multiplyLeftInternal(const SimpleMatrix44<Data>& otherMatrix) const
    {
      const array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX> mData = otherMatrix.getData();
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
    shared_ptr<Vector<Data> >
    SimpleVector4<Data>::multiplyLeftCopy(const Matrix<Data>& otherMatrix) const
    {
      return (shared_ptr<Vector<Data> > (
          new SimpleVector4<Data> (multiplyLeftInternal(dynamic_cast<const SimpleMatrix44<Data>&> (otherMatrix)))));
    }

  template<class Data>
    void
    SimpleVector4<Data>::multiplyRight(const Matrix<Data>& otherMatrix)
    {
      fData = multiplyRightInternal(dynamic_cast<const SimpleMatrix44<Data>&> (otherMatrix));
    }

  template<class Data>
    array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR>
    SimpleVector4<Data>::multiplyRightInternal(const SimpleMatrix44<Data>& otherMatrix) const
    {
      array<Data, CELLS_IN_VECTOR> vData = fData;
      const array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX> mData = otherMatrix.getData();
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
    SimpleVector4<Data>::multiplyRight(const Vector<Data>& otherVector)
    {
      fData = multiply(*this, dynamic_cast<const SimpleVector4<Data>&> (otherVector));
    }

  template<class Data>
    shared_ptr<Vector<Data> >
    SimpleVector4<Data>::multiplyRightCopy(const Matrix<Data>& otherMatrix) const
    {
      return (shared_ptr<Vector<Data> > (
          new SimpleVector4<Data> (multiplyRightInternal(dynamic_cast<const SimpleMatrix44<Data>&> (otherMatrix)))));
    }

  template<class Data>
    shared_ptr<Vector<Data> >
    SimpleVector4<Data>::multiplyRightCopy(const Vector<Data>& otherVector) const
    {
      return (shared_ptr<Vector<Data> > (
          new SimpleVector4<Data> (multiply(*this, dynamic_cast<const SimpleVector4<Data>&> (otherVector)))));
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
    SimpleVector4<Data>::scale(const Data scalar)
    {
      fData.at(0) = fData.at(0) * scalar;
      fData.at(1) = fData.at(1) * scalar;
      fData.at(2) = fData.at(2) * scalar;
    }

  template<class Data>
    array<Data, SimpleVector4<Data>::CELLS_IN_VECTOR>
    SimpleVector4<Data>::subtract(const SimpleVector4<Data>& leftVector, const SimpleVector4<Data>& rightVector) const
    {
      const array<Data, CELLS_IN_VECTOR> leftData = leftVector.getData();
      const array<Data, CELLS_IN_VECTOR> rightData = rightVector.getData();
      array<Data, CELLS_IN_VECTOR> subData;

      subData.at(0) = leftData.at(0) - rightData.at(0);
      subData.at(1) = leftData.at(1) - rightData.at(1);
      subData.at(2) = leftData.at(2) - rightData.at(2);
      subData.at(3) = 1;

      return (subData);
    }

  template<class Data>
    void
    SimpleVector4<Data>::subtractRight(const Vector<Data>& otherVector)
    {
      fData = subtract(*this, dynamic_cast<const SimpleVector4<Data>&> (otherVector));
    }

  template<class Data>
    shared_ptr<Vector<Data> >
    SimpleVector4<Data>::subtractRightCopy(const Vector<Data>& otherVector) const
    {
      return (shared_ptr<Vector<Data> > (
          new SimpleVector4(subtract(*this, dynamic_cast<const SimpleVector4<Data>&> (otherVector)))));
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
