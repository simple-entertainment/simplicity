/*
 This file is part of The Simplicity Engine.

 The Simplicity Engine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published
 by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 The Simplicity Engine is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with The Simplicity Engine. If not, see <http://www.gnu.org/licenses/>.
 */
#include <boost/lexical_cast.hpp>

#include "../SEInvalidOperationException.h"
#include "SimpleMatrix44.h"

using namespace boost;
using namespace std;

namespace simplicity
{
  template<class Data>
    SimpleMatrix44<Data>::SimpleMatrix44()
    {
      setIdentity();
    }

  template<class Data>
    SimpleMatrix44<Data>::SimpleMatrix44(array<Data, CELLS_IN_MATRIX> data)
    {
      fData = data;
    }

  template<class Data>
    bool
    SimpleMatrix44<Data>::equals(const Matrix<Data>& otherMatrix) const
    {
      return (fData == dynamic_cast<const SimpleMatrix44<Data>&> (otherMatrix).getDataCopy());
    }

  template<class Data>
    array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX>&
    SimpleMatrix44<Data>::getData()
    {
      return (fData);
    }

  template<class Data>
    array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX>
    SimpleMatrix44<Data>::getDataCopy() const
    {
      return (fData);
    }

  template<class Data>
    Data
    SimpleMatrix44<Data>::getDeterminant() const
    {
      Data determinant = fData.at(0) * ((fData.at(5) * fData.at(10) * fData.at(15) + fData.at(6) * fData.at(11) * fData.at(13)
          + fData.at(7) * fData.at(9) * fData.at(14)) - fData.at(7) * fData.at(10) * fData.at(13) - fData.at(5) * fData.at(11)
          * fData.at(14) - fData.at(6) * fData.at(9) * fData.at(15));

      determinant -= fData.at(1) * ((fData.at(4) * fData.at(10) * fData.at(15) + fData.at(6) * fData.at(11) * fData.at(12)
          + fData.at(7) * fData.at(8) * fData.at(14)) - fData.at(7) * fData.at(10) * fData.at(12) - fData.at(4) * fData.at(11)
          * fData.at(14) - fData.at(6) * fData.at(8) * fData.at(15));

      determinant += fData.at(2) * ((fData.at(4) * fData.at(9) * fData.at(15) + fData.at(5) * fData.at(11) * fData.at(12)
          + fData.at(7) * fData.at(8) * fData.at(13)) - fData.at(7) * fData.at(9) * fData.at(12) - fData.at(4) * fData.at(11)
          * fData.at(13) - fData.at(5) * fData.at(8) * fData.at(15));

      determinant -= fData.at(3) * ((fData.at(4) * fData.at(9) * fData.at(14) + fData.at(5) * fData.at(10) * fData.at(12)
          + fData.at(6) * fData.at(8) * fData.at(13)) - fData.at(6) * fData.at(9) * fData.at(12) - fData.at(4) * fData.at(10)
          * fData.at(13) - fData.at(5) * fData.at(8) * fData.at(14));

      return (determinant);
    }

  template<class Data>
    Data
    SimpleMatrix44<Data>::getDeterminant33(const Data d00, const Data d10, const Data d20, const Data d01, const Data d11,
        const Data d21, const Data d02, const Data d12, const Data d22) const
    {
      return (d00 * (d11 * d22 - d12 * d21) - d10 * (d01 * d22 - d02 * d21) + d20 * (d01 * d12 - d02 * d11));
    }

  template<class Data>
    const Data* const
    SimpleMatrix44<Data>::getRawData() const
    {
      return (fData.data());
    }

  template<class Data>
    void
    SimpleMatrix44<Data>::invert()
    {
      Data determinant = getDeterminant();

      if (determinant == 0)
      {
        throw SEInvalidOperationException();
      }

      Data invDeterminant = 1 / determinant;

      // Calculate determinants for each value in this matrix.
      Data d00 = getDeterminant33(fData.at(5), fData.at(6), fData.at(7), fData.at(9), fData.at(10), fData.at(11), fData.at(13),
          fData.at(14), fData.at(15));
      Data d01 = -getDeterminant33(fData.at(4), fData.at(6), fData.at(7), fData.at(8), fData.at(10), fData.at(11), fData.at(12),
          fData.at(14), fData.at(15));
      Data d02 = getDeterminant33(fData.at(4), fData.at(5), fData.at(7), fData.at(8), fData.at(9), fData.at(11), fData.at(12),
          fData.at(13), fData.at(15));
      Data d03 = -getDeterminant33(fData.at(4), fData.at(5), fData.at(6), fData.at(8), fData.at(9), fData.at(10), fData.at(12),
          fData.at(13), fData.at(14));

      Data d10 = -getDeterminant33(fData.at(1), fData.at(2), fData.at(3), fData.at(9), fData.at(10), fData.at(11), fData.at(13),
          fData.at(14), fData.at(15));
      Data d11 = getDeterminant33(fData.at(0), fData.at(2), fData.at(3), fData.at(8), fData.at(10), fData.at(11), fData.at(12),
          fData.at(14), fData.at(15));
      Data d12 = -getDeterminant33(fData.at(0), fData.at(1), fData.at(3), fData.at(8), fData.at(9), fData.at(11), fData.at(12),
          fData.at(13), fData.at(15));
      Data d13 = getDeterminant33(fData.at(0), fData.at(1), fData.at(2), fData.at(8), fData.at(9), fData.at(10), fData.at(12),
          fData.at(13), fData.at(14));

      Data d20 = getDeterminant33(fData.at(1), fData.at(2), fData.at(3), fData.at(5), fData.at(6), fData.at(7), fData.at(13),
          fData.at(14), fData.at(15));
      Data d21 = -getDeterminant33(fData.at(0), fData.at(2), fData.at(3), fData.at(4), fData.at(6), fData.at(7), fData.at(12),
          fData.at(14), fData.at(15));
      Data d22 = getDeterminant33(fData.at(0), fData.at(1), fData.at(3), fData.at(4), fData.at(5), fData.at(7), fData.at(12),
          fData.at(13), fData.at(15));
      Data d23 = -getDeterminant33(fData.at(0), fData.at(1), fData.at(2), fData.at(4), fData.at(5), fData.at(6), fData.at(12),
          fData.at(13), fData.at(14));

      Data d30 = -getDeterminant33(fData.at(1), fData.at(2), fData.at(3), fData.at(5), fData.at(6), fData.at(7), fData.at(9),
          fData.at(10), fData.at(11));
      Data d31 = getDeterminant33(fData.at(0), fData.at(2), fData.at(3), fData.at(4), fData.at(6), fData.at(7), fData.at(8),
          fData.at(10), fData.at(11));
      Data d32 = -getDeterminant33(fData.at(0), fData.at(1), fData.at(3), fData.at(4), fData.at(5), fData.at(7), fData.at(8),
          fData.at(9), fData.at(11));
      Data d33 = getDeterminant33(fData.at(0), fData.at(1), fData.at(2), fData.at(4), fData.at(5), fData.at(6), fData.at(8),
          fData.at(9), fData.at(10));

      // Transpose and divide by the determinant.
      fData.at(0) = d00 * invDeterminant;
      fData.at(1) = d10 * invDeterminant;
      fData.at(2) = d20 * invDeterminant;
      fData.at(3) = d30 * invDeterminant;
      fData.at(4) = d01 * invDeterminant;
      fData.at(5) = d11 * invDeterminant;
      fData.at(6) = d21 * invDeterminant;
      fData.at(7) = d31 * invDeterminant;
      fData.at(8) = d02 * invDeterminant;
      fData.at(9) = d12 * invDeterminant;
      fData.at(10) = d22 * invDeterminant;
      fData.at(11) = d32 * invDeterminant;
      fData.at(12) = d03 * invDeterminant;
      fData.at(13) = d13 * invDeterminant;
      fData.at(14) = d23 * invDeterminant;
      fData.at(15) = d33 * invDeterminant;
    }

  template<class Data>
    array<Data, SimpleMatrix44<Data>::CELLS_IN_MATRIX>
    SimpleMatrix44<Data>::multiply(const SimpleMatrix44<Data>& leftMatrix, const SimpleMatrix44<Data>& rightMatrix) const
    {
      array<Data, CELLS_IN_MATRIX> leftData = leftMatrix.getDataCopy();
      array<Data, CELLS_IN_MATRIX> rightData = rightMatrix.getDataCopy();
      array<Data, CELLS_IN_MATRIX> multData;

      // For every row in the left hand matrix.
      for (int row = 0; row < CELLS_IN_COLUMN; row++)
      {
        // For every column in the right hand matrix.
        for (int column = 0; column < CELLS_IN_ROW; column++)
        {
          Data sum = 0;

          // For every element in the current row of the left hand matrix and
          // every element in the current column of the right hand matrix.
          for (int element = 0; element < CELLS_IN_ROW; element++)
          {
            // Add the product of the two to the value for the new
            // matrix.
            sum += leftData.at(row + (element * CELLS_IN_COLUMN)) * rightData.at((column * CELLS_IN_ROW) + element);
          }

          multData.at((column * CELLS_IN_ROW) + row) = sum;
        }
      }

      return (multData);
    }

  template<class Data>
    void
    SimpleMatrix44<Data>::multiplyLeft(const Matrix<Data>& leftMatrix)
    {
      fData = multiply(dynamic_cast<const SimpleMatrix44<Data>&> (leftMatrix), *this);
    }

  template<class Data>
    shared_ptr<Matrix<Data> >
    SimpleMatrix44<Data>::multiplyLeftCopy(const Matrix<Data>& leftMatrix) const
    {
      return (shared_ptr<Matrix<Data> > (
          new SimpleMatrix44<Data> (multiply(dynamic_cast<const SimpleMatrix44<Data>&> (leftMatrix), *this))));
    }

  template<class Data>
    void
    SimpleMatrix44<Data>::multiplyRight(const Matrix<Data>& rightMatrix)
    {
      fData = multiply(*this, dynamic_cast<const SimpleMatrix44<Data>&> (rightMatrix));
    }

  template<class Data>
    shared_ptr<Matrix<Data> >
    SimpleMatrix44<Data>::multiplyRightCopy(const Matrix<Data>& rightMatrix) const
    {
      return (shared_ptr<Matrix<Data> > (
          new SimpleMatrix44<Data> (multiply(*this, dynamic_cast<const SimpleMatrix44<Data>&> (rightMatrix)))));
    }

  template<class Data>
    void
    SimpleMatrix44<Data>::setIdentity()
    {
      fData.at(0) = 1;
      fData.at(1) = 0;
      fData.at(2) = 0;
      fData.at(3) = 0;

      fData.at(4) = 0;
      fData.at(5) = 1;
      fData.at(6) = 0;
      fData.at(7) = 0;

      fData.at(8) = 0;
      fData.at(9) = 0;
      fData.at(10) = 1;
      fData.at(11) = 0;

      fData.at(12) = 0;
      fData.at(13) = 0;
      fData.at(14) = 0;
      fData.at(15) = 1;
    }

  template<class Data>
    string
    SimpleMatrix44<Data>::toString() const
    {
      string matrixString = "";

      matrixString += "-------------------------\n";
      matrixString += "| " + lexical_cast<string> (fData.at(0)) + " | " + lexical_cast<string> (fData.at(4)) + " | "
          + lexical_cast<string> (fData.at(8)) + " | " + lexical_cast<string> (fData.at(12)) + " |\n";
      matrixString += "-------------------------\n";
      matrixString += "| " + lexical_cast<string> (fData.at(1)) + " | " + lexical_cast<string> (fData.at(5)) + " | "
          + lexical_cast<string> (fData.at(9)) + " | " + lexical_cast<string> (fData.at(13)) + " |\n";
      matrixString += "-------------------------\n";
      matrixString += "| " + lexical_cast<string> (fData.at(2)) + " | " + lexical_cast<string> (fData.at(6)) + " | "
          + lexical_cast<string> (fData.at(10)) + " | " + lexical_cast<string> (fData.at(14)) + " |\n";
      matrixString += "-------------------------\n";
      matrixString += "| " + lexical_cast<string> (fData.at(3)) + " | " + lexical_cast<string> (fData.at(7)) + " | "
          + lexical_cast<string> (fData.at(11)) + " | " + lexical_cast<string> (fData.at(15)) + " |\n";
      matrixString += "-------------------------\n";

      return (matrixString);
    }

  template<class Data>
    void
    SimpleMatrix44<Data>::transpose()
    {
      Data temp = -1;

      temp = fData.at(1);
      fData.at(1) = fData.at(4);
      fData.at(4) = temp;

      temp = fData.at(2);
      fData.at(2) = fData.at(8);
      fData.at(8) = temp;

      temp = fData.at(3);
      fData.at(3) = fData.at(12);
      fData.at(12) = temp;

      temp = fData.at(6);
      fData.at(6) = fData.at(9);
      fData.at(9) = temp;

      temp = fData.at(7);
      fData.at(7) = fData.at(13);
      fData.at(13) = temp;

      temp = fData.at(11);
      fData.at(11) = fData.at(14);
      fData.at(14) = temp;
    }
}
